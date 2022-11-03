//========================
// [main.cpp]
//========================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//========================
#include "Main.h"
#include "C_Sound.h"
#include "C_Game.h"
//========================

//************************
//マクロ定義
//************************
#define CLASS_NAME "AppClass"         //ウィンドウのクラス名
#define WINDOW_NAME "脱出ゲームⅢ Remake" //ウィンドウのキャプション名

//***********************************************************************
//クラスのオブジェクト生成
//***********************************************************************
C_Game* objGame = new C_Game();

//************************
//プロトタイプ宣言
//************************

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow);
void Uninit(void);

//************************
// グローバル変数
//************************

LPDIRECT3D9       g_pD3D = NULL;         //Direct3Dオブジェクト
LPDIRECT3DDEVICE9 g_pD3DDevice = NULL; //Deviceオブジェクト(描画に必要)
int g_nCountFPS = 0;// ＦＰＳへのカウンタ


//========================
// メイン関数
//========================
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wcex =
	{
		sizeof(WNDCLASSEX),
		CS_CLASSDC,
		WndProc,
		0,
		0,
		hInstance,
		NULL,
		LoadCursor(NULL,IDC_ARROW),
		(HBRUSH)(COLOR_WINDOW + 1),
		NULL,
		CLASS_NAME,
		NULL
	};
	HWND hWnd;
	MSG msg;

	DWORD dwExecLastTime;		// 最後に実行した時間		
	DWORD dwFPSLastTime;		// 最後に計測した時間
	DWORD dwCurrentTime;		// 現在時刻
	DWORD dwFrameCount;			// フレーム数

	//ウィンドウクラスの登録
	RegisterClassEx(&wcex);

	//ウィンドウの作成
	hWnd = CreateWindowEx(0,
		CLASS_NAME,
		WINDOW_NAME,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		SCREEN_WIDTH,
		SCREEN_HIGHT,
		NULL,
		NULL,
		hInstance,
		NULL);

	//初期化処理(ウィンドウを作成してから行う)
	if (FAILED(Init(hInstance, hWnd, TRUE)))
	{
		return -1;
	}

	// フレームカウント初期化
	timeBeginPeriod(1);
	dwExecLastTime = dwFPSLastTime = timeGetTime();
	dwCurrentTime = dwFrameCount = 0;

	//ウィンドウの表示(初期化処理の後に行う)
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	//メッセージループ
	while (1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) != 0) //メッセージを取得しなかった場合"0"を返す
		{//windowsの処理
			if (msg.message == WM_QUIT)
			{// PostQuitMessage()が呼ばれて、WM_QUITメッセージが来たらループ終了
				break;
			}
			else
			{
				//メッセージの翻訳と送出
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			// ＦＰＳ一定化処理
			// 現在時間を取得
			dwCurrentTime = timeGetTime();
			// 0.5秒ごとに実行
			if ((dwCurrentTime - dwFPSLastTime) > 500) 
			{
				// FPSを計算
				g_nCountFPS = (dwFrameCount * 1000) / (dwCurrentTime - dwFPSLastTime);

				// ＦＰＳ計測時間に現座時間をセット
				dwFPSLastTime = dwCurrentTime;

				// フレーム数をゼロクリア
				dwFrameCount = 0;
			}
			// １６ミリ秒経過したら
			if ((dwCurrentTime - dwExecLastTime) >= (1000.0 / 60.0)) 
			{
				// 最終実行時間に現在時間をセット
				dwExecLastTime = dwCurrentTime;

				//DirectXの処理
				//ゲームループ
				objGame->GameMain(g_pD3DDevice);

				// フレーム数をインクリメント
				dwFrameCount++;
			}
		}
	}

	//ウィンドウクラスの登録を解除
	UnregisterClass(CLASS_NAME, wcex.hInstance);

	//終了処理
	Uninit();

	return (int)msg.wParam;
}

//===================================
// ウィンドウプロシージャ
//===================================
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	//int nID;

	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			//nID = MessageBox(NULL, "終了していいですか?", "確認", MB_YESNO);
			//if (nID == IDYES)
			//{
				DestroyWindow(hWnd);
			//}
			break;

		}
		break;

	case WM_CLOSE:
		//nID = MessageBox(hWnd, "終了しますか?", "終了", MB_YESNO);
		//if (nID == IDYES)
		//{
			DestroyWindow(hWnd);
		//}
		//else
		//{
			//return 0;
		//}
		break;

	default:
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}


//==============================
// 初期化処理
// hInstance  :インスタンスのハンドル
// hWnd       :ウィンドウのハンドル
// bWindow    :ウィンドウモードにするかどうか
//===============================
HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	D3DPRESENT_PARAMETERS d3dpp;
	D3DDISPLAYMODE d3ddm;

	//Direct3Dオブジェクトの生成
	g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
	if (g_pD3D == NULL)
	{
		return E_FAIL;
	}

	//現在のディスプレイモードを取得
	if (FAILED(g_pD3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm)))
	{
		return E_FAIL;
	}

	//デバイスのプレゼンテーションパラメータの設定
	ZeroMemory(&d3dpp, sizeof(d3dpp));        //ワークをゼロクリア
	d3dpp.BackBufferWidth = 600;    //ゲーム画面サイズ(幅)
	d3dpp.BackBufferHeight = 400;   //ゲーム画面サイズ(高さ)
	d3dpp.BackBufferFormat = d3ddm.Format;    //カラーモードの設定
	d3dpp.BackBufferCount = 1;             //バックバッファの数
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;    //映像信号に同期して不リップする
	d3dpp.Windowed = bWindow;    //ウィンドウモード
	d3dpp.EnableAutoDepthStencil = TRUE;    //デプスバッファ(Zバッファ)とステンシルバッファを作成
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;    //デプスバッファとして16bitを使う


	if (bWindow)
	{//ウィンドウモード
		d3dpp.FullScreen_RefreshRateInHz = 0;        //リフレッシュレート(指定できないので0固定)
		d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;//インターバル(VSyncを待たずに描画)
	}
	else
	{//フルスクリーンモード
		d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT; //リフレッシュレート(現在の速度に合わせる)
		d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;  //インターバル(VSyncを待って描画)
	}

	//デバイスオブジェクトの生成
	//[デバイス作成制御]<描画>と<頂点処理>をハードウェアで行う
	if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, //ディスプレイアダプタ
		D3DDEVTYPE_HAL,//デバイスタイプ
		hWnd,//フォーカスするウィンドウへのハンドル
		D3DCREATE_HARDWARE_VERTEXPROCESSING,//デバイス作成制御の組み合わせ
		&d3dpp,         //デバイスのプレゼンテーションパラメータ
		&g_pD3DDevice)))//デバイスインターフェースへのポインタ
	{
		//上記の設定が失敗したら
		//[デバイス作成制御]<描画>をハードウェアで行い、<頂点処理>はCPUで行う
		if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT,
			D3DDEVTYPE_HAL,
			hWnd,
			D3DCREATE_SOFTWARE_VERTEXPROCESSING,
			&d3dpp,
			&g_pD3DDevice)))
		{
			//上記の設定が失敗したら
			//[デバイス作成制御]<描画>と<頂点処理>をCPUで行う
			if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT,
				D3DDEVTYPE_REF,
				hWnd,
				D3DCREATE_SOFTWARE_VERTEXPROCESSING,
				&d3dpp,
				&g_pD3DDevice)))
			{
				//初期化失敗
				return E_FAIL;
			}
		}
	}

	//透過処理(これでαの値をいじれる)
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);

	// レンダリングステートパラメータの設定
	g_pD3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);				// 裏面をカリングする
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);				// αブレンドを行う
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);		// αソースカラーの指定
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);		// αデスティネーションカラーの指定

	g_pD3DDevice->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP);	//
	g_pD3DDevice->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP);	//
	g_pD3DDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);	//
	g_pD3DDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);	//
	
	//ゲーム初期処理
	objGame->GameInit(g_pD3DDevice, hInstance, hWnd);

	return S_OK;
}

//==================================
//終了設定
//==================================
void Uninit(void)
{
	delete objGame;//デストラクタ呼び出し

	if (g_pD3DDevice != NULL)
	{//デバイスの開放
		g_pD3DDevice->Release();
		g_pD3DDevice = NULL;
	}

	if (g_pD3D != NULL)
	{//Direct3Dオブジェクトの開放
		g_pD3D->Release();
		g_pD3D = NULL;
	}
}