//=============================================================================
//
// タイトル画面処理 [C_Title.cpp]
//
//=============================================================================

#include "C_Title.h"
#include "C_Game_Manager.h"
#include "Struct_Input.h"
#include "C_Input.h"
#include "C_Sound.h"



//==============================================================================
// 初期化処理
//==============================================================================
void C_Title::Init(LPDIRECT3DDEVICE9 dev)
{
	HRESULT hr = D3DXCreateTextureFromFile(dev, "assets/title.png", &t_title);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}

	hr = D3DXCreateTextureFromFile(dev, "assets/title1.png", &t_title1);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}

	hr = D3DXCreateTextureFromFile(dev, "assets/title2.png", &t_title2);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}
}


//==============================================================================
// 終了処理
//==============================================================================
void C_Title::UnInit()
{
	if (t_title)
	{
		t_title->Release();
		t_title = NULL;
	}

	if (t_title1)
	{
		t_title1->Release();
		t_title1 = NULL;
	}

	if (t_title2)
	{
		t_title2->Release();
		t_title2 = NULL;
	}
}


//==============================================================================
// タイトル画面更新処理
//==============================================================================
void C_Title::UpdateProcess()
{
	C_Sound::StopSound(SOUND_LABEL_BGM000);
	C_Sound::StopSound(SOUND_LABEL_BGM001);

	if (title_sound == true)
	{
		C_Sound::PlaySound(SOUND_LABEL_BGM002);
		title_sound = false;
		C_Game_Manager::color = 255;
	}

	if ((C_Input::GetKeyboardTrigger(DIK_I) || C_Input::GetKeyDown(0x0003)) && flag == true)
	{
		C_Sound::PlaySound(SOUND_LABEL_SE_DECIDE);//決定音
		flag = false;
	}

	//フェードアウト開始
	if (flag == false)
	{
		C_Game_Manager::color--;
	}

	if (C_Game_Manager::color == 0)
	{
		game_state_no = 2;
		C_Game_Manager::Store_Game_State_No(game_state_no);

		flag = true;
		title_sound = true;
		C_Game_Manager::color = 255;
	}
}


//==============================================================================
// タイトル画面描画処理
//==============================================================================
void C_Title::DrawProcess(LPDIRECT3DDEVICE9 dev)
{
	TitleDraw(dev);
	TitleDraw1(dev);
	TitleDraw2(dev);
}