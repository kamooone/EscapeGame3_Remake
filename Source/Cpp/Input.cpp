//=============================================================================
//
// 入力処理 [Input.cpp]
//
//=============================================================================
#include "Struct_Input.h"
#include "C_Input.h"


//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
BOOL CALLBACK EnumJoysticksCallback(const DIDEVICEINSTANCE *pdidInstance, VOID *pContext);
BOOL CALLBACK EnumAxesCallback(const DIDEVICEOBJECTINSTANCE *pdidoi, VOID *pContext);


//*****************************************************************************
// グローバル変数
//*****************************************************************************
static LPDIRECTINPUT8 g_PAD;					// DIRECTINPUT8のポインタ
static LPDIRECTINPUTDEVICE8 g_Pad;					// DIRECTINPUTDEVICE8のポインタ
static INPUTSTATE g_InputState;								// キー情報


//*****************************************************************************
// 静的メンバ変数実体化
//*****************************************************************************
LPDIRECTINPUT8       C_Input::g_pDInput;					    // IDirectInput8インターフェースへのポインタ
LPDIRECTINPUTDEVICE8 C_Input::g_pDIDevKeyboard;			        // IDirectInputDevice8インターフェースへのポインタ(キーボード)
LPDIRECTINPUTDEVICE8 C_Input::g_pDIDevMouse;			    	// IDirectInputDevice8インターフェースへのポインタ(マウス)
BYTE                 C_Input::g_keyState[NUM_KEY_MAX];			// キーボードの状態を受け取るワーク
BYTE                 C_Input::g_keyStateTrigger[NUM_KEY_MAX];	// キーボードの状態を受け取るワーク
BYTE                 C_Input::g_keyStateRepeat[NUM_KEY_MAX];	// キーボードの状態を受け取るワーク
BYTE                 C_Input::g_keyStateRelease[NUM_KEY_MAX];	// キーボードの状態を受け取るワーク
int                  C_Input::g_keyStateRepeatCnt[NUM_KEY_MAX];	// キーボードのリピートカウンタ
DIMOUSESTATE2        C_Input::g_mouseState;						// マウスの状態を受け取るワーク
DIMOUSESTATE2        C_Input::g_mouseStateTrigger;				// マウスの状態を受け取るワーク
DIMOUSESTATE2        C_Input::g_mouseStateRelease;				// マウスの状態を受け取るワーク
POINT                C_Input::g_MousePoint;						// マウスの現在座標
HWND                 C_Input::g_hwnd;

DIDEVCAPS C_Input::g_diDevCaps;
BYTE      C_Input::KeyState_Press[256];
BYTE      C_Input::KeyState_Trigger[256];
BYTE      C_Input::KeyState_Release[256];


//=============================================================================
// 入力処理の初期化
//=============================================================================
HRESULT C_Input::InitInput(HINSTANCE hInst, HWND hWnd)
{
	HRESULT hr;

	if(!g_pDInput)
	{
		// DirectInputオブジェクトの作成
		hr = DirectInput8Create(hInst, DIRECTINPUT_VERSION,
									IID_IDirectInput8, (void**)&g_pDInput, NULL);
	}

	// キーボードの初期化
	InitKeyboard(hInst, hWnd);

	// マウスの初期化
	InitMouse(hInst, hWnd);

	//パッドの初期化
	hr = DirectInput8Create(hInst,
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(void**)&g_PAD,
		NULL);
	//if (FAILED(hr))
	//{
	//	MessageBox(hWnd, (char*)"error", (char*)"エラーA", MB_OK);
	//	return false;
	//}

	//インターフェイスの取得
	hr = g_PAD->CreateDevice(GUID_Joystick, &g_Pad, NULL);

	//デバイス機能の設定
	g_PAD->EnumDevices(DI8DEVCLASS_GAMECTRL, EnumJoysticksCallback, NULL, DIEDFL_ATTACHEDONLY);
	

	if (g_Pad != NULL) 
	{	
		// デバイスのフォーマットの設定
		hr = g_Pad->SetDataFormat(&c_dfDIJoystick);

		// 協調モードの設定
		hr = g_Pad->SetCooperativeLevel(hWnd, DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);

		//デバイスの能力設定
		g_Pad->GetCapabilities(&g_diDevCaps);

		//十字キーの範囲設定
		g_Pad->EnumObjects(EnumAxesCallback, (VOID*)hWnd, DIDFT_AXIS);

		// デバイスの取得開始
		g_Pad->Acquire();
		
		if (FAILED(hr))
		{
			MessageBox(hWnd, (char*)"error", (char*)"エラーA", MB_OK);
			return false;
		}
	}

	g_hwnd=hWnd;

	return hr;
}

//=============================================================================
// 入力処理の終了処理
//=============================================================================
void C_Input::UninitInput(void)
{
	// キーボードの終了処理
	UninitKeyboard();

	// マウスの終了処理
	UninitMouse();

	//パッドの終了処理
	if (g_Pad != NULL)
	{
		g_Pad->Unacquire();
	}

	//それぞれのデバイスを開放
	if(g_pDInput)
	{
		g_pDInput->Release();
		g_pDInput = NULL;
	}

	if (g_PAD)
	{
		g_PAD->Release();
		g_PAD = NULL;
	}

	if (g_Pad)
	{
		g_Pad->Release();
		g_Pad = NULL;
	}
}

//=============================================================================
// 入力処理の更新処理
//=============================================================================
void C_Input::UpdateInput(void)
{
	// キーボードの更新
	UpdateKeyboard();

	// マウスの更新
	UpdateMouse();

	if (g_Pad != NULL)
	{//パッドの更新
		KeyUpdate();
	}
}

//=============================================================================
// キーボードの初期化
//=============================================================================
HRESULT C_Input::InitKeyboard(HINSTANCE hInst, HWND hWnd)
{
	HRESULT hr;

	// デバイスオブジェクトを作成
	hr = g_pDInput->CreateDevice(GUID_SysKeyboard, &g_pDIDevKeyboard, NULL);
	if(FAILED(hr) || g_pDIDevKeyboard == NULL)
	{
		MessageBox(hWnd, "キーボードがねぇ！", "警告！", MB_ICONWARNING);
		return hr;
	}

	// データフォーマットを設定
	hr = g_pDIDevKeyboard->SetDataFormat(&c_dfDIKeyboard);
	if(FAILED(hr))
	{
		MessageBox(hWnd, "キーボードのデータフォーマットを設定できませんでした。", "警告！", MB_ICONWARNING);
		return hr;
	}

	// 協調モードを設定（フォアグラウンド＆非排他モード）
	hr = g_pDIDevKeyboard->SetCooperativeLevel(hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE));
	if(FAILED(hr))
	{
		MessageBox(hWnd, "キーボードの協調モードを設定できませんでした。", "警告！", MB_ICONWARNING);
		return hr;
	}

	// キーボードへのアクセス権を獲得(入力制御開始)
	g_pDIDevKeyboard->Acquire();

	return S_OK;
}

//=============================================================================
// キーボードの終了処理
//=============================================================================
void C_Input::UninitKeyboard(void)
{
	if(g_pDIDevKeyboard)
	{
		g_pDIDevKeyboard->Unacquire();

		g_pDIDevKeyboard->Release();
		g_pDIDevKeyboard = NULL;
	}
}

//=============================================================================
// キーボードの更新処理
//=============================================================================
HRESULT C_Input::UpdateKeyboard(void)
{
	HRESULT hr;
	BYTE keyStateOld[NUM_KEY_MAX];

	// 前回のデータを保存
	memcpy(keyStateOld, g_keyState, NUM_KEY_MAX);

	// デバイスからデータを取得
	hr = g_pDIDevKeyboard->GetDeviceState(sizeof(g_keyState), g_keyState);
	if(SUCCEEDED(hr))
	{
		for (int cnt = 0; cnt < NUM_KEY_MAX; cnt++)
		{
			//--------------------------------------------------------------------------------------------
			//トリガー
			if (KEYBOARD_TRIGGER)g_keyStateTrigger[cnt] = 0x80;
			else g_keyStateTrigger[cnt] = 0;

			//リリース
			if (KEYBOARD_RELEASE)g_keyStateRelease[cnt] = 0x80;
			else g_keyStateRelease[cnt] = 0;
			//--------------------------------------------------------------------------------------------


			//--------------------------------------------------------------------------------------------
			// キーが押されているならリピートの判定処理
			if(g_keyState[cnt])
			{
				if(g_keyStateRepeatCnt[cnt] < 30)
				{
					g_keyStateRepeatCnt[cnt]++;
					// 「初回入力」もしくは「ボタンを押してから20フレーム経過」
					// した場合、リピート用配列のデータを有効にする
					if (g_keyStateTrigger[cnt] == 0x80 || g_keyStateRepeatCnt[cnt] >= 30)
					{
						g_keyStateRepeat[cnt] = 0x80;
						g_keyStateRepeatCnt[cnt] = 0;
					}
					// 上記条件以外はリピート用配列のデータを無効にする
					else
					{
						g_keyStateRepeat[cnt] = 0;
					}
				}
			}
			else
			{
				g_keyStateRepeatCnt[cnt] = 0;
				g_keyStateRepeat[cnt] = 0;
			}
		}
	}
	else
	{
		// キーボードへのアクセス権を取得
		hr = g_pDIDevKeyboard->Acquire();
	}

	return hr;
}

//=============================================================================
// キーボードのプレス状態を取得
//=============================================================================
bool C_Input::GetKeyboardPress(int key)
{
 	return ((g_keyState[key] & 0x80) != 0);
}

//=============================================================================
// キーボードのトリガー状態を取得
//=============================================================================
bool C_Input::GetKeyboardTrigger(int key)
{
	return ((g_keyStateTrigger[key] & 0x80) != 0);
}

//=============================================================================
// キーボードのリピート状態を取得
//=============================================================================
bool C_Input::GetKeyboardRepeat(int key)
{
	return ((g_keyStateRepeat[key] & 0x80) != 0);
}

//=============================================================================
// キーボードのリリ－ス状態を取得
//=============================================================================
bool C_Input::GetKeyboardRelease(int key)
{
	return ((g_keyStateRelease[key] & 0x80) != 0);
}

//=============================================================================
// マウスの初期化
//=============================================================================
HRESULT C_Input::InitMouse(HINSTANCE hInst, HWND hWnd)
{
	HRESULT hr;

	// デバイスオブジェクトを作成
	hr = g_pDInput->CreateDevice(GUID_SysMouse, &g_pDIDevMouse, NULL);
	if(FAILED(hr) || g_pDIDevMouse == NULL)
	{
		MessageBox(hWnd, "マウスがねぇ！", "警告！", MB_ICONWARNING);
		return hr;
	}

	// データフォーマットを設定
	hr = g_pDIDevMouse->SetDataFormat(&c_dfDIMouse2);
	if(FAILED(hr))
	{
		MessageBox(hWnd, "マウスのデータフォーマットを設定できませんでした。", "警告！", MB_ICONWARNING);
		return hr;
	}

	// 協調モードを設定（フォアグラウンド＆非排他モード）
	hr = g_pDIDevMouse->SetCooperativeLevel(hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE));
	if(FAILED(hr))
	{
		MessageBox(hWnd, "マウスの協調モードを設定できませんでした。", "警告！", MB_ICONWARNING);
		return hr;
	}

	// デバイスの設定
	{
		DIPROPDWORD dipdw;

		dipdw.diph.dwSize = sizeof(dipdw);
		dipdw.diph.dwHeaderSize = sizeof(dipdw.diph);
		dipdw.diph.dwObj = 0;
		dipdw.diph.dwHow = DIPH_DEVICE;
		dipdw.dwData = DIPROPAXISMODE_REL;

		hr = g_pDIDevMouse->SetProperty(DIPROP_AXISMODE, &dipdw.diph);
	}

	// キーボードへのアクセス権を獲得(入力制御開始)
	g_pDIDevMouse->Acquire();

	return S_OK;
}

//=============================================================================
// マウスの終了処理
//=============================================================================
void C_Input::UninitMouse(void)
{
	if(g_pDIDevMouse)
	{
		g_pDIDevMouse->Unacquire();

		g_pDIDevMouse->Release();
		g_pDIDevMouse = NULL;
	}
}

//=============================================================================
// マウスの更新処理
//=============================================================================
HRESULT C_Input::UpdateMouse(void)
{
	HRESULT hr;
	DIMOUSESTATE2 mouseStateOld;

	// 前回のデータを保存
	mouseStateOld = g_mouseState;
		
	GetCursorPos(&g_MousePoint);
	ScreenToClient(g_hwnd, &g_MousePoint);


	// デバイスからデータを取得
	hr = g_pDIDevMouse->GetDeviceState(sizeof(g_mouseState), &g_mouseState);
	if(SUCCEEDED(hr))
	{
		// トリガーの取得
		//g_mouseStateTrigger.lX = 
		//g_mouseStateTrigger.lY = 
		//g_mouseStateTrigger.lZ = 
		for(int cnt = 0; cnt < 8; cnt++)
		{
			//---------------------------------------------------------------
			//トリガー
			if (MOUSE_TRIGGER)
			{
				g_mouseStateTrigger.rgbButtons[cnt] = 0x80;
				//g_mouseStateTrigger.rgbButtons[cnt] = ((mouseStateOld.rgbButtons[cnt] ^ g_mouseState.rgbButtons[cnt]) & g_mouseState.rgbButtons[cnt]);
			}
  			else g_mouseStateTrigger.rgbButtons[cnt] = 0;
			//---------------------------------------------------------------

			//--------------------------f-------------------------------------
			//リリース
			if (MOUSE_RELEASE)
			{
				g_mouseStateRelease.rgbButtons[cnt] = 0x80;
			}
			else g_mouseStateRelease.rgbButtons[cnt] = 0;
			//---------------------------------------------------------------
		}
	}
	else
	{
		g_pDIDevMouse->Acquire();
	}

	return S_OK;
}

//=============================================================================
// マウスデータ取得(左プレス)
//=============================================================================
bool C_Input::GetMouseLeftPress(void)
{
	return ((g_mouseState.rgbButtons[0] & 0x80) != 0);
}

//=============================================================================
// マウスデータ取得(左トリガー)
//=============================================================================
bool C_Input::GetMouseLeftTrigger(void)
{
	if (((g_mouseStateTrigger.rgbButtons[0] & 0x80) != 0))
	{
		return true;
	}
	else return false;
}

//=============================================================================
// マウスデータ取得(左リリース)
//=============================================================================
bool C_Input::GetMouseLeftRelease(void)
{
	return ((g_mouseStateRelease.rgbButtons[0] & 0x80) != 0);
}

//=============================================================================
// マウスデータ取得(右プレス)
//=============================================================================
bool C_Input::GetMouseRightPress(void)
{
	return ((g_mouseState.rgbButtons[1] & 0x80) != 0);
}

//=============================================================================
// マウスデータ取得(右トリガー)
//=============================================================================
bool C_Input::GetMouseRightTrigger(void)
{
	return ((g_mouseStateTrigger.rgbButtons[1] & 0x80) != 0);
}

//=============================================================================
// マウスデータ取得(右リリース)
//=============================================================================
bool C_Input::GetMouseRightRelease(void)
{
	return ((g_mouseStateRelease.rgbButtons[1] & 0x80) != 0);
}

//=============================================================================
// マウスデータ取得(中央プレス)
//=============================================================================
bool C_Input::GetMouseCenterPress(void)
{
	return ((g_mouseState.rgbButtons[2] & 0x80) != 0);
}

//=============================================================================
// マウスデータ取得(中央トリガー)
//=============================================================================
bool C_Input::GetMouseCenterTrigger(void)
{
	return ((g_mouseState.rgbButtons[2] & 0x80) != 0);
}

//=============================================================================
// マウスデータ取得(中央リリース)
//=============================================================================
bool C_Input::GetMouseCenterRelease(void)
{
	return ((g_mouseStateRelease.rgbButtons[2] & 0x80) != 0);
}

//=============================================================================
// マウスデータ取得(Ｘ軸移動)
//=============================================================================
long C_Input::GetMouseAxisX(void)
{
	return g_mouseState.lX;
}

//=============================================================================
// マウスデータ取得(Ｙ軸移動)
//=============================================================================
long C_Input::GetMouseAxisY(void)
{
	return g_mouseState.lY;
}

//=============================================================================
// マウスデータ取得(Ｚ軸移動)
//=============================================================================
long C_Input::GetMouseAxisZ(void)
{
	return g_mouseState.lZ;
}
//=============================================================================
// マウス座標取得(X)
//=============================================================================
long C_Input::GetMouseX(void)
{
	return g_MousePoint.x;
}

//=============================================================================
// マウス座標取得(Y)
//=============================================================================
long C_Input::GetMouseY(void)
{
	return g_MousePoint.y;
}

//=============================================================================
// パッドのコールバック関数
//=============================================================================
BOOL CALLBACK EnumJoysticksCallback(const DIDEVICEINSTANCE *pdidInstance, VOID *pContext)
{
	HRESULT hr;

	hr = g_PAD->CreateDevice(pdidInstance->guidInstance, &g_Pad, NULL);

	if (FAILED(hr)) return DIENUM_CONTINUE;

	return DIENUM_STOP;
}

BOOL CALLBACK EnumAxesCallback(const DIDEVICEOBJECTINSTANCE *pdidoi, VOID *pContext)
{
	HRESULT     hr;
	DIPROPRANGE diprg;

	diprg.diph.dwSize = sizeof(DIPROPRANGE);
	diprg.diph.dwHeaderSize = sizeof(DIPROPHEADER);
	diprg.diph.dwHow = DIPH_BYID;
	diprg.diph.dwObj = pdidoi->dwType;
	diprg.lMin = 0 - 1000;
	diprg.lMax = 0 + 1000;
	hr = g_Pad->SetProperty(DIPROP_RANGE, &diprg.diph);

	if (FAILED(hr)) return DIENUM_STOP;

	return DIENUM_CONTINUE;
}

//=============================================================================
// パッドの入力更新
//=============================================================================
void C_Input::KeyUpdate()
{
	const int Pushed = 128;

	// キー情報取格納用
	HRESULT hr;
	static BYTE OLDKEY[256];

	DIJOYSTATE js;

	//ゲッター
	g_Pad->Poll();
	hr = g_Pad->GetDeviceState(sizeof(DIJOYSTATE), &js);
	if (SUCCEEDED(hr))
	{
		//キー情報の初期化
		for (int i = 0; i < 256; i++)
		{
			// 1フレーム前のキー情報の確保
			OLDKEY[i] = KeyState_Press[i];
			// キー情報クリア
			KeyState_Press[i] = CLEAR_KEY;
		}

		// 左キー
		if (js.lX < -200 || js.rgdwPOV[0] >18000 && js.rgdwPOV[0] < 36000)
		{
			KeyState_Press[LEFT_KEY] = LEFT_KEY;
		}

		// 右キー
		if (js.lX > 200 || js.rgdwPOV[0] >0 && js.rgdwPOV[0] < 18000)
		{
			KeyState_Press[RIGHT_KEY] = RIGHT_KEY;
		}

		// 上キー
		if (js.lY < -200 ||(js.rgdwPOV[0] >27000 && js.rgdwPOV[0] < 36000) ||(js.rgdwPOV[0] >=0 && js.rgdwPOV[0] < 9000))
		{
			KeyState_Press[UP_KEY] = UP_KEY;
		}

		// 下キー
		if (js.lY > 200 || js.rgdwPOV[0] >9000 && js.rgdwPOV[0] < 27000)
		{
			KeyState_Press[DOWN_KEY] = DOWN_KEY;
		}

		//□ボタン
		if (js.rgbButtons[SQUARE_KEY - 1] == Pushed)
		{
			KeyState_Press[SQUARE_KEY - 1] = SQUARE_KEY;
		}

		//×ボタン
		if (js.rgbButtons[CROSS_KEY - 1] == Pushed)
		{
			KeyState_Press[CROSS_KEY - 1] |= CROSS_KEY;
		}

		//○ボタン
		if (js.rgbButtons[CIRCLE_KEY - 1] == Pushed)
		{
			KeyState_Press[CIRCLE_KEY - 1] |= CIRCLE_KEY;
		}

		//△ボタン
		if (js.rgbButtons[TRIANGLE_KEY - 1] == Pushed)
		{
			KeyState_Press[TRIANGLE_KEY - 1] |= TRIANGLE_KEY;
		}

		//オプションボタン
		if (js.rgbButtons[OPTION_KEY - 1] == Pushed)
		{
			KeyState_Press[OPTION_KEY - 1] |= OPTION_KEY;
		}

		//トリガーとリリースを更新
		for (int i = 0; i < 256; i++)
		{
			KeyState_Trigger[i] = (KeyState_Press[i] & (~OLDKEY[i]));	// トリガー情報取得
			KeyState_Release[i] = (~KeyState_Press[i]) & OLDKEY[i];	// 逆トリガー情報取得
		}
	}

	else if (hr == DIERR_INPUTLOST) 
	{/*デバイスをロストしたらもっかい稼働させる*/
		g_Pad->Acquire();
	}
}

//=============================================================================
// パッドの入力取得(ホールド)
//=============================================================================
bool C_Input::GetKey(DWORD key_code)
{
	if (key_code > 0x00f0)
	{
		return (KeyState_Press[key_code] != 0);
	}
	else
	{
		return KeyState_Press[key_code - 1] & key_code;
	}
	
}

//=============================================================================
// パッドの入力更新（トリガー）
//=============================================================================
bool C_Input::GetKeyDown(DWORD key_code)
{
	if (key_code > 0x00f0)
	{
		return KeyState_Trigger[key_code] & key_code;
	}
	else
	{
		return KeyState_Trigger[key_code - 1] & key_code;
	}

}

//=============================================================================
// パッドの入力更新（リリース）
//=============================================================================
bool C_Input::GetKeyUp(DWORD key_code)
{
	if (key_code > 0x00f0)
	{
		return KeyState_Release[key_code] & key_code;
	}
	else
	{
		return KeyState_Release[key_code - 1] & key_code;
	}

}
