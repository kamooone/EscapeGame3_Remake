//=============================================================================
//
// クリア処理 [Clear.cpp]
//
//=============================================================================

#include "C_Clear.h"
#include "C_Sound.h"



//==============================================================================
// 初期化処理
//==============================================================================
void C_Clear::Init(LPDIRECT3DDEVICE9 dev)
{
	HRESULT hr = D3DXCreateTextureFromFile(dev, "assets/clear.png", &t_clear);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}

	hr = D3DXCreateTextureFromFile(dev, "assets/clear1.png", &t_clear1);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}

	hr = D3DXCreateTextureFromFile(dev, "assets/clear2.png", &t_clear2);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}

	hr = D3DXCreateTextureFromFile(dev, "assets/clear3.png", &t_clear3);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}

}


//==============================================================================
// 終了処理
//==============================================================================
void C_Clear::UnInit()
{
	if (t_clear)
	{
		t_clear->Release();
		t_clear = NULL;
	}
	if (t_clear1)
	{
		t_clear1->Release();
		t_clear1 = NULL;
	}
	if (t_clear2)
	{
		t_clear2->Release();
		t_clear2 = NULL;
	}
	if (t_clear3)
	{
		t_clear3->Release();
		t_clear3 = NULL;
	}
}


//==============================================================================
// 更新処理
//==============================================================================
void C_Clear::UpdateProcess()
{
	C_Sound::StopSound(SOUND_LABEL_BGM001);
}


//==============================================================================
// クリア画面描画処理
//==============================================================================
void C_Clear::DrawProcess(LPDIRECT3DDEVICE9 dev)
{
	static int time = 0;
	time++;

	if (time == 0) { C_Game_Manager::color = 255; }

	if (time >= 0 && time<=300) { ClearDraw(dev,t_clear); }
	
	if (time >=300 && time <= 600) { ClearDraw(dev, t_clear1); }

	if (time >= 600 && time <= 900) { ClearDraw(dev, t_clear2); }

	if (time >= 900) { ClearDraw(dev, t_clear3); }

	if (time>=1100) { C_Game_Manager::color--; }

	if (time >= 1100 && C_Game_Manager::color==0) 
	{
		time = 0;
		Store_Color(C_Game_Manager::color);

		game_state_no = 1;
		C_Game_Manager::Store_Game_State_No(game_state_no);
	}
}