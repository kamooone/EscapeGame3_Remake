//=============================================================================
//
// セレクト画面処理 [C_Select.cpp]
//
//=============================================================================

#include "C_Select.h"
#include "C_Game_Manager.h"
#include "Struct_Input.h"
#include "C_Input.h"
#include "C_Sound.h"


//*****************************************************************************
// 静的メンバ変数実体化
//*****************************************************************************
int C_Select::world_no = 1;



//==============================================================================
// 初期化処理
//==============================================================================
void C_Select::Init(LPDIRECT3DDEVICE9 dev)
{
	HRESULT hr = D3DXCreateTextureFromFile(dev, "assets/select.png", &t_select);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}
	
	hr = D3DXCreateTextureFromFile(dev, "assets/select1.png", &t_select1);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}
	
	hr = D3DXCreateTextureFromFile(dev, "assets/select2.png", &t_select2);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}

	hr = D3DXCreateTextureFromFile(dev, "assets/selectNow2.png", &t_selectNow2);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}

	hr = D3DXCreateTextureFromFile(dev, "assets/select3.png", &t_select3);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}

	hr = D3DXCreateTextureFromFile(dev, "assets/selectNow3.png", &t_selectNow3);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}

	hr = D3DXCreateTextureFromFile(dev, "assets/select4.png", &t_select4);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}

	hr = D3DXCreateTextureFromFile(dev, "assets/selectNow4.png", &t_selectNow4);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}	
}


//==============================================================================
// 終了処理
//==============================================================================
void C_Select::UnInit()
{
	if (t_select)
	{
		t_select->Release();
		t_select = NULL;
	}

	if (t_select1)
	{
		t_select1->Release();
		t_select1 = NULL;
	}
	
	if (t_select2)
	{
		t_select2->Release();
		t_select2 = NULL;
	}

	if (t_selectNow2)
	{
		t_selectNow2->Release();
		t_selectNow2 = NULL;
	}

	if (t_select3)
	{
		t_select3->Release();
		t_select3 = NULL;
	}

	if (t_selectNow3)
	{
		t_selectNow3->Release();
		t_selectNow3 = NULL;
	}

	if (t_select4)
	{
		t_select4->Release();
		t_select4 = NULL;
	}

	if (t_selectNow4)
	{
		t_selectNow4->Release();
		t_selectNow4 = NULL;
	}
}


//==============================================================================
// セレクト画面更新処理
//==============================================================================
void C_Select::UpdateProcess()
{
	if (flag == true && C_Game_Manager::color == 255)
	{
		if ((C_Input::GetKeyDown(0x00F1) || C_Input::GetKeyboardTrigger(DIK_W)) && (world_no > 1 && world_no <= 3))
		{
			world_no = 1;
			C_Sound::PlaySound(SOUND_LABEL_SE_CURSOR);
		}
		if ((C_Input::GetKeyDown(0x00F2) || C_Input::GetKeyboardTrigger(DIK_S)) && world_no == 1)
		{
			world_no++;
			C_Sound::PlaySound(SOUND_LABEL_SE_CURSOR);
		}
		if ((C_Input::GetKeyDown(0x00F4) || C_Input::GetKeyboardTrigger(DIK_D)) && world_no == 2)
		{
			world_no++;
			C_Sound::PlaySound(SOUND_LABEL_SE_CURSOR);
		}
		if ((C_Input::GetKeyDown(0x00F3) || C_Input::GetKeyboardTrigger(DIK_A)) && world_no == 3)
		{
			world_no--;
			C_Sound::PlaySound(SOUND_LABEL_SE_CURSOR);
		}
	}

	if (select_sound == true)
	{
		//C_Sound::PlaySound(SOUND_LABEL_BGM002);
		select_sound = false;
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
		game_state_no = 3;
		C_Game_Manager::Store_Game_State_No(game_state_no);

		flag = true;
		select_sound = true;
		C_Game_Manager::color = 255;
	}
}


//==============================================================================
// セレクト画面描画処理
//==============================================================================
void C_Select::DrawProcess(LPDIRECT3DDEVICE9 dev)
{
	SelectDraw(dev);
	SelectDraw1(dev);

	if (world_no != 1)
	{
		SelectDraw2(dev);
	}
	if (world_no == 1)
	{
		SelectNow2(dev);
	}

	if (world_no != 2)
	{
		SelectDraw3(dev);
	}
	if (world_no == 2)
	{
		SelectNow3(dev);
	}

	if (world_no != 3)
	{
		SelectDraw4(dev);
	}
	if (world_no == 3)
	{
		SelectNow4(dev);
	}
}