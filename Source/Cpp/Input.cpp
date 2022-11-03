//=============================================================================
//
// ���͏��� [Input.cpp]
//
//=============================================================================
#include "Struct_Input.h"
#include "C_Input.h"


//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
BOOL CALLBACK EnumJoysticksCallback(const DIDEVICEINSTANCE *pdidInstance, VOID *pContext);
BOOL CALLBACK EnumAxesCallback(const DIDEVICEOBJECTINSTANCE *pdidoi, VOID *pContext);


//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
static LPDIRECTINPUT8 g_PAD;					// DIRECTINPUT8�̃|�C���^
static LPDIRECTINPUTDEVICE8 g_Pad;					// DIRECTINPUTDEVICE8�̃|�C���^
static INPUTSTATE g_InputState;								// �L�[���


//*****************************************************************************
// �ÓI�����o�ϐ����̉�
//*****************************************************************************
LPDIRECTINPUT8       C_Input::g_pDInput;					    // IDirectInput8�C���^�[�t�F�[�X�ւ̃|�C���^
LPDIRECTINPUTDEVICE8 C_Input::g_pDIDevKeyboard;			        // IDirectInputDevice8�C���^�[�t�F�[�X�ւ̃|�C���^(�L�[�{�[�h)
LPDIRECTINPUTDEVICE8 C_Input::g_pDIDevMouse;			    	// IDirectInputDevice8�C���^�[�t�F�[�X�ւ̃|�C���^(�}�E�X)
BYTE                 C_Input::g_keyState[NUM_KEY_MAX];			// �L�[�{�[�h�̏�Ԃ��󂯎�郏�[�N
BYTE                 C_Input::g_keyStateTrigger[NUM_KEY_MAX];	// �L�[�{�[�h�̏�Ԃ��󂯎�郏�[�N
BYTE                 C_Input::g_keyStateRepeat[NUM_KEY_MAX];	// �L�[�{�[�h�̏�Ԃ��󂯎�郏�[�N
BYTE                 C_Input::g_keyStateRelease[NUM_KEY_MAX];	// �L�[�{�[�h�̏�Ԃ��󂯎�郏�[�N
int                  C_Input::g_keyStateRepeatCnt[NUM_KEY_MAX];	// �L�[�{�[�h�̃��s�[�g�J�E���^
DIMOUSESTATE2        C_Input::g_mouseState;						// �}�E�X�̏�Ԃ��󂯎�郏�[�N
DIMOUSESTATE2        C_Input::g_mouseStateTrigger;				// �}�E�X�̏�Ԃ��󂯎�郏�[�N
DIMOUSESTATE2        C_Input::g_mouseStateRelease;				// �}�E�X�̏�Ԃ��󂯎�郏�[�N
POINT                C_Input::g_MousePoint;						// �}�E�X�̌��ݍ��W
HWND                 C_Input::g_hwnd;

DIDEVCAPS C_Input::g_diDevCaps;
BYTE      C_Input::KeyState_Press[256];
BYTE      C_Input::KeyState_Trigger[256];
BYTE      C_Input::KeyState_Release[256];


//=============================================================================
// ���͏����̏�����
//=============================================================================
HRESULT C_Input::InitInput(HINSTANCE hInst, HWND hWnd)
{
	HRESULT hr;

	if(!g_pDInput)
	{
		// DirectInput�I�u�W�F�N�g�̍쐬
		hr = DirectInput8Create(hInst, DIRECTINPUT_VERSION,
									IID_IDirectInput8, (void**)&g_pDInput, NULL);
	}

	// �L�[�{�[�h�̏�����
	InitKeyboard(hInst, hWnd);

	// �}�E�X�̏�����
	InitMouse(hInst, hWnd);

	//�p�b�h�̏�����
	hr = DirectInput8Create(hInst,
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(void**)&g_PAD,
		NULL);
	//if (FAILED(hr))
	//{
	//	MessageBox(hWnd, (char*)"error", (char*)"�G���[A", MB_OK);
	//	return false;
	//}

	//�C���^�[�t�F�C�X�̎擾
	hr = g_PAD->CreateDevice(GUID_Joystick, &g_Pad, NULL);

	//�f�o�C�X�@�\�̐ݒ�
	g_PAD->EnumDevices(DI8DEVCLASS_GAMECTRL, EnumJoysticksCallback, NULL, DIEDFL_ATTACHEDONLY);
	

	if (g_Pad != NULL) 
	{	
		// �f�o�C�X�̃t�H�[�}�b�g�̐ݒ�
		hr = g_Pad->SetDataFormat(&c_dfDIJoystick);

		// �������[�h�̐ݒ�
		hr = g_Pad->SetCooperativeLevel(hWnd, DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);

		//�f�o�C�X�̔\�͐ݒ�
		g_Pad->GetCapabilities(&g_diDevCaps);

		//�\���L�[�͈̔͐ݒ�
		g_Pad->EnumObjects(EnumAxesCallback, (VOID*)hWnd, DIDFT_AXIS);

		// �f�o�C�X�̎擾�J�n
		g_Pad->Acquire();
		
		if (FAILED(hr))
		{
			MessageBox(hWnd, (char*)"error", (char*)"�G���[A", MB_OK);
			return false;
		}
	}

	g_hwnd=hWnd;

	return hr;
}

//=============================================================================
// ���͏����̏I������
//=============================================================================
void C_Input::UninitInput(void)
{
	// �L�[�{�[�h�̏I������
	UninitKeyboard();

	// �}�E�X�̏I������
	UninitMouse();

	//�p�b�h�̏I������
	if (g_Pad != NULL)
	{
		g_Pad->Unacquire();
	}

	//���ꂼ��̃f�o�C�X���J��
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
// ���͏����̍X�V����
//=============================================================================
void C_Input::UpdateInput(void)
{
	// �L�[�{�[�h�̍X�V
	UpdateKeyboard();

	// �}�E�X�̍X�V
	UpdateMouse();

	if (g_Pad != NULL)
	{//�p�b�h�̍X�V
		KeyUpdate();
	}
}

//=============================================================================
// �L�[�{�[�h�̏�����
//=============================================================================
HRESULT C_Input::InitKeyboard(HINSTANCE hInst, HWND hWnd)
{
	HRESULT hr;

	// �f�o�C�X�I�u�W�F�N�g���쐬
	hr = g_pDInput->CreateDevice(GUID_SysKeyboard, &g_pDIDevKeyboard, NULL);
	if(FAILED(hr) || g_pDIDevKeyboard == NULL)
	{
		MessageBox(hWnd, "�L�[�{�[�h���˂��I", "�x���I", MB_ICONWARNING);
		return hr;
	}

	// �f�[�^�t�H�[�}�b�g��ݒ�
	hr = g_pDIDevKeyboard->SetDataFormat(&c_dfDIKeyboard);
	if(FAILED(hr))
	{
		MessageBox(hWnd, "�L�[�{�[�h�̃f�[�^�t�H�[�}�b�g��ݒ�ł��܂���ł����B", "�x���I", MB_ICONWARNING);
		return hr;
	}

	// �������[�h��ݒ�i�t�H�A�O���E���h����r�����[�h�j
	hr = g_pDIDevKeyboard->SetCooperativeLevel(hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE));
	if(FAILED(hr))
	{
		MessageBox(hWnd, "�L�[�{�[�h�̋������[�h��ݒ�ł��܂���ł����B", "�x���I", MB_ICONWARNING);
		return hr;
	}

	// �L�[�{�[�h�ւ̃A�N�Z�X�����l��(���͐���J�n)
	g_pDIDevKeyboard->Acquire();

	return S_OK;
}

//=============================================================================
// �L�[�{�[�h�̏I������
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
// �L�[�{�[�h�̍X�V����
//=============================================================================
HRESULT C_Input::UpdateKeyboard(void)
{
	HRESULT hr;
	BYTE keyStateOld[NUM_KEY_MAX];

	// �O��̃f�[�^��ۑ�
	memcpy(keyStateOld, g_keyState, NUM_KEY_MAX);

	// �f�o�C�X����f�[�^���擾
	hr = g_pDIDevKeyboard->GetDeviceState(sizeof(g_keyState), g_keyState);
	if(SUCCEEDED(hr))
	{
		for (int cnt = 0; cnt < NUM_KEY_MAX; cnt++)
		{
			//--------------------------------------------------------------------------------------------
			//�g���K�[
			if (KEYBOARD_TRIGGER)g_keyStateTrigger[cnt] = 0x80;
			else g_keyStateTrigger[cnt] = 0;

			//�����[�X
			if (KEYBOARD_RELEASE)g_keyStateRelease[cnt] = 0x80;
			else g_keyStateRelease[cnt] = 0;
			//--------------------------------------------------------------------------------------------


			//--------------------------------------------------------------------------------------------
			// �L�[��������Ă���Ȃ烊�s�[�g�̔��菈��
			if(g_keyState[cnt])
			{
				if(g_keyStateRepeatCnt[cnt] < 30)
				{
					g_keyStateRepeatCnt[cnt]++;
					// �u������́v�������́u�{�^���������Ă���20�t���[���o�߁v
					// �����ꍇ�A���s�[�g�p�z��̃f�[�^��L���ɂ���
					if (g_keyStateTrigger[cnt] == 0x80 || g_keyStateRepeatCnt[cnt] >= 30)
					{
						g_keyStateRepeat[cnt] = 0x80;
						g_keyStateRepeatCnt[cnt] = 0;
					}
					// ��L�����ȊO�̓��s�[�g�p�z��̃f�[�^�𖳌��ɂ���
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
		// �L�[�{�[�h�ւ̃A�N�Z�X�����擾
		hr = g_pDIDevKeyboard->Acquire();
	}

	return hr;
}

//=============================================================================
// �L�[�{�[�h�̃v���X��Ԃ��擾
//=============================================================================
bool C_Input::GetKeyboardPress(int key)
{
 	return ((g_keyState[key] & 0x80) != 0);
}

//=============================================================================
// �L�[�{�[�h�̃g���K�[��Ԃ��擾
//=============================================================================
bool C_Input::GetKeyboardTrigger(int key)
{
	return ((g_keyStateTrigger[key] & 0x80) != 0);
}

//=============================================================================
// �L�[�{�[�h�̃��s�[�g��Ԃ��擾
//=============================================================================
bool C_Input::GetKeyboardRepeat(int key)
{
	return ((g_keyStateRepeat[key] & 0x80) != 0);
}

//=============================================================================
// �L�[�{�[�h�̃����|�X��Ԃ��擾
//=============================================================================
bool C_Input::GetKeyboardRelease(int key)
{
	return ((g_keyStateRelease[key] & 0x80) != 0);
}

//=============================================================================
// �}�E�X�̏�����
//=============================================================================
HRESULT C_Input::InitMouse(HINSTANCE hInst, HWND hWnd)
{
	HRESULT hr;

	// �f�o�C�X�I�u�W�F�N�g���쐬
	hr = g_pDInput->CreateDevice(GUID_SysMouse, &g_pDIDevMouse, NULL);
	if(FAILED(hr) || g_pDIDevMouse == NULL)
	{
		MessageBox(hWnd, "�}�E�X���˂��I", "�x���I", MB_ICONWARNING);
		return hr;
	}

	// �f�[�^�t�H�[�}�b�g��ݒ�
	hr = g_pDIDevMouse->SetDataFormat(&c_dfDIMouse2);
	if(FAILED(hr))
	{
		MessageBox(hWnd, "�}�E�X�̃f�[�^�t�H�[�}�b�g��ݒ�ł��܂���ł����B", "�x���I", MB_ICONWARNING);
		return hr;
	}

	// �������[�h��ݒ�i�t�H�A�O���E���h����r�����[�h�j
	hr = g_pDIDevMouse->SetCooperativeLevel(hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE));
	if(FAILED(hr))
	{
		MessageBox(hWnd, "�}�E�X�̋������[�h��ݒ�ł��܂���ł����B", "�x���I", MB_ICONWARNING);
		return hr;
	}

	// �f�o�C�X�̐ݒ�
	{
		DIPROPDWORD dipdw;

		dipdw.diph.dwSize = sizeof(dipdw);
		dipdw.diph.dwHeaderSize = sizeof(dipdw.diph);
		dipdw.diph.dwObj = 0;
		dipdw.diph.dwHow = DIPH_DEVICE;
		dipdw.dwData = DIPROPAXISMODE_REL;

		hr = g_pDIDevMouse->SetProperty(DIPROP_AXISMODE, &dipdw.diph);
	}

	// �L�[�{�[�h�ւ̃A�N�Z�X�����l��(���͐���J�n)
	g_pDIDevMouse->Acquire();

	return S_OK;
}

//=============================================================================
// �}�E�X�̏I������
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
// �}�E�X�̍X�V����
//=============================================================================
HRESULT C_Input::UpdateMouse(void)
{
	HRESULT hr;
	DIMOUSESTATE2 mouseStateOld;

	// �O��̃f�[�^��ۑ�
	mouseStateOld = g_mouseState;
		
	GetCursorPos(&g_MousePoint);
	ScreenToClient(g_hwnd, &g_MousePoint);


	// �f�o�C�X����f�[�^���擾
	hr = g_pDIDevMouse->GetDeviceState(sizeof(g_mouseState), &g_mouseState);
	if(SUCCEEDED(hr))
	{
		// �g���K�[�̎擾
		//g_mouseStateTrigger.lX = 
		//g_mouseStateTrigger.lY = 
		//g_mouseStateTrigger.lZ = 
		for(int cnt = 0; cnt < 8; cnt++)
		{
			//---------------------------------------------------------------
			//�g���K�[
			if (MOUSE_TRIGGER)
			{
				g_mouseStateTrigger.rgbButtons[cnt] = 0x80;
				//g_mouseStateTrigger.rgbButtons[cnt] = ((mouseStateOld.rgbButtons[cnt] ^ g_mouseState.rgbButtons[cnt]) & g_mouseState.rgbButtons[cnt]);
			}
  			else g_mouseStateTrigger.rgbButtons[cnt] = 0;
			//---------------------------------------------------------------

			//--------------------------f-------------------------------------
			//�����[�X
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
// �}�E�X�f�[�^�擾(���v���X)
//=============================================================================
bool C_Input::GetMouseLeftPress(void)
{
	return ((g_mouseState.rgbButtons[0] & 0x80) != 0);
}

//=============================================================================
// �}�E�X�f�[�^�擾(���g���K�[)
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
// �}�E�X�f�[�^�擾(�������[�X)
//=============================================================================
bool C_Input::GetMouseLeftRelease(void)
{
	return ((g_mouseStateRelease.rgbButtons[0] & 0x80) != 0);
}

//=============================================================================
// �}�E�X�f�[�^�擾(�E�v���X)
//=============================================================================
bool C_Input::GetMouseRightPress(void)
{
	return ((g_mouseState.rgbButtons[1] & 0x80) != 0);
}

//=============================================================================
// �}�E�X�f�[�^�擾(�E�g���K�[)
//=============================================================================
bool C_Input::GetMouseRightTrigger(void)
{
	return ((g_mouseStateTrigger.rgbButtons[1] & 0x80) != 0);
}

//=============================================================================
// �}�E�X�f�[�^�擾(�E�����[�X)
//=============================================================================
bool C_Input::GetMouseRightRelease(void)
{
	return ((g_mouseStateRelease.rgbButtons[1] & 0x80) != 0);
}

//=============================================================================
// �}�E�X�f�[�^�擾(�����v���X)
//=============================================================================
bool C_Input::GetMouseCenterPress(void)
{
	return ((g_mouseState.rgbButtons[2] & 0x80) != 0);
}

//=============================================================================
// �}�E�X�f�[�^�擾(�����g���K�[)
//=============================================================================
bool C_Input::GetMouseCenterTrigger(void)
{
	return ((g_mouseState.rgbButtons[2] & 0x80) != 0);
}

//=============================================================================
// �}�E�X�f�[�^�擾(���������[�X)
//=============================================================================
bool C_Input::GetMouseCenterRelease(void)
{
	return ((g_mouseStateRelease.rgbButtons[2] & 0x80) != 0);
}

//=============================================================================
// �}�E�X�f�[�^�擾(�w���ړ�)
//=============================================================================
long C_Input::GetMouseAxisX(void)
{
	return g_mouseState.lX;
}

//=============================================================================
// �}�E�X�f�[�^�擾(�x���ړ�)
//=============================================================================
long C_Input::GetMouseAxisY(void)
{
	return g_mouseState.lY;
}

//=============================================================================
// �}�E�X�f�[�^�擾(�y���ړ�)
//=============================================================================
long C_Input::GetMouseAxisZ(void)
{
	return g_mouseState.lZ;
}
//=============================================================================
// �}�E�X���W�擾(X)
//=============================================================================
long C_Input::GetMouseX(void)
{
	return g_MousePoint.x;
}

//=============================================================================
// �}�E�X���W�擾(Y)
//=============================================================================
long C_Input::GetMouseY(void)
{
	return g_MousePoint.y;
}

//=============================================================================
// �p�b�h�̃R�[���o�b�N�֐�
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
// �p�b�h�̓��͍X�V
//=============================================================================
void C_Input::KeyUpdate()
{
	const int Pushed = 128;

	// �L�[����i�[�p
	HRESULT hr;
	static BYTE OLDKEY[256];

	DIJOYSTATE js;

	//�Q�b�^�[
	g_Pad->Poll();
	hr = g_Pad->GetDeviceState(sizeof(DIJOYSTATE), &js);
	if (SUCCEEDED(hr))
	{
		//�L�[���̏�����
		for (int i = 0; i < 256; i++)
		{
			// 1�t���[���O�̃L�[���̊m��
			OLDKEY[i] = KeyState_Press[i];
			// �L�[���N���A
			KeyState_Press[i] = CLEAR_KEY;
		}

		// ���L�[
		if (js.lX < -200 || js.rgdwPOV[0] >18000 && js.rgdwPOV[0] < 36000)
		{
			KeyState_Press[LEFT_KEY] = LEFT_KEY;
		}

		// �E�L�[
		if (js.lX > 200 || js.rgdwPOV[0] >0 && js.rgdwPOV[0] < 18000)
		{
			KeyState_Press[RIGHT_KEY] = RIGHT_KEY;
		}

		// ��L�[
		if (js.lY < -200 ||(js.rgdwPOV[0] >27000 && js.rgdwPOV[0] < 36000) ||(js.rgdwPOV[0] >=0 && js.rgdwPOV[0] < 9000))
		{
			KeyState_Press[UP_KEY] = UP_KEY;
		}

		// ���L�[
		if (js.lY > 200 || js.rgdwPOV[0] >9000 && js.rgdwPOV[0] < 27000)
		{
			KeyState_Press[DOWN_KEY] = DOWN_KEY;
		}

		//���{�^��
		if (js.rgbButtons[SQUARE_KEY - 1] == Pushed)
		{
			KeyState_Press[SQUARE_KEY - 1] = SQUARE_KEY;
		}

		//�~�{�^��
		if (js.rgbButtons[CROSS_KEY - 1] == Pushed)
		{
			KeyState_Press[CROSS_KEY - 1] |= CROSS_KEY;
		}

		//���{�^��
		if (js.rgbButtons[CIRCLE_KEY - 1] == Pushed)
		{
			KeyState_Press[CIRCLE_KEY - 1] |= CIRCLE_KEY;
		}

		//���{�^��
		if (js.rgbButtons[TRIANGLE_KEY - 1] == Pushed)
		{
			KeyState_Press[TRIANGLE_KEY - 1] |= TRIANGLE_KEY;
		}

		//�I�v�V�����{�^��
		if (js.rgbButtons[OPTION_KEY - 1] == Pushed)
		{
			KeyState_Press[OPTION_KEY - 1] |= OPTION_KEY;
		}

		//�g���K�[�ƃ����[�X���X�V
		for (int i = 0; i < 256; i++)
		{
			KeyState_Trigger[i] = (KeyState_Press[i] & (~OLDKEY[i]));	// �g���K�[���擾
			KeyState_Release[i] = (~KeyState_Press[i]) & OLDKEY[i];	// �t�g���K�[���擾
		}
	}

	else if (hr == DIERR_INPUTLOST) 
	{/*�f�o�C�X�����X�g��������������ғ�������*/
		g_Pad->Acquire();
	}
}

//=============================================================================
// �p�b�h�̓��͎擾(�z�[���h)
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
// �p�b�h�̓��͍X�V�i�g���K�[�j
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
// �p�b�h�̓��͍X�V�i�����[�X�j
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
