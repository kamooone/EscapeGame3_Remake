//=============================================================================
//
// マップ描画処理 [Field.cpp]
//
//=============================================================================

#include "C_Field.h"
#include "C_Sound.h"

#include<stdio.h>
#include<string.h>
#include<stdlib.h>



//==============================================================================
// 初期化処理
//==============================================================================
void C_Field::Init(LPDIRECT3DDEVICE9 dev)
{
	HRESULT hr = D3DXCreateTextureFromFile(dev, "assets/field.png", &t_mapchip);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}


	errno_t error;
	FILE *f;

	//マップデータファイル読み込み
	error = fopen_s(&f, "External_File/field.csv", "r");
	
	if (error != 0)
	{
		MessageBox(NULL, "load file error", "error", MB_OK);
	}
	else {
		//ファイルのデータを二次元配列に格納
		for (int i = 0; i<column / 20; i++) 
		{
			fscanf_s(f,
				"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
				&MapData_TwoDim[i][0], &MapData_TwoDim[i][1], &MapData_TwoDim[i][2], &MapData_TwoDim[i][3], &MapData_TwoDim[i][4],
				&MapData_TwoDim[i][5], &MapData_TwoDim[i][6], &MapData_TwoDim[i][7], &MapData_TwoDim[i][8], &MapData_TwoDim[i][9],
				&MapData_TwoDim[i][10], &MapData_TwoDim[i][11], &MapData_TwoDim[i][12], &MapData_TwoDim[i][13], &MapData_TwoDim[i][14],
				&MapData_TwoDim[i][15], &MapData_TwoDim[i][16], &MapData_TwoDim[i][17], &MapData_TwoDim[i][18], &MapData_TwoDim[i][19],
				&MapData_TwoDim[i][20], &MapData_TwoDim[i][21], &MapData_TwoDim[i][22], &MapData_TwoDim[i][23], &MapData_TwoDim[i][24],
				&MapData_TwoDim[i][25], &MapData_TwoDim[i][26], &MapData_TwoDim[i][27], &MapData_TwoDim[i][28], &MapData_TwoDim[i][29],
				&MapData_TwoDim[i][30], &MapData_TwoDim[i][31], &MapData_TwoDim[i][32], &MapData_TwoDim[i][33], &MapData_TwoDim[i][34],
				&MapData_TwoDim[i][35], &MapData_TwoDim[i][36], &MapData_TwoDim[i][37], &MapData_TwoDim[i][38], &MapData_TwoDim[i][39]);
		}
	}
	fclose(f);

	//二次元配列データを一次元に代入
	for (int i = 0; i<SCREEN_HIGHT / 20; i++)
	{
		for (int j = 0; j < SCREEN_WIDTH / 20; j++)
		{
			static int ij = 0;
			MapData_OneDim_Store[ij] = MapData_TwoDim[i][j];
			ij++;
		}
	}
}


//==============================================================================
// 終了処理
//==============================================================================
void C_Field::UnInit()
{
	if (t_mapchip)
	{
		t_mapchip->Release();
		t_mapchip = NULL;
	}
}


//==============================================================================
// マップ更新処理
//==============================================================================
void C_Field::UpdateProcess()
{
	field_sound = Get_Field_Sound();
	if (field_sound == true)
	{
		C_Sound::StopSound(SOUND_LABEL_BGM003);
		C_Sound::PlaySound(SOUND_LABEL_BGM000);
		Store_Field_Sound(field_sound = false);
	}

	C_Game_Manager::manual_no = C_Monster::Get_Manual_No();

	//障害物消滅
	for (int i = 0; i < column; i += 20)
	{
		for (int j = 0; j < row; j += 20)
		{
			if (MapData_TwoDim[i / 20][j / 20] == -100)
			{
				MapData_TwoDim[i / 20][j / 20] = -97;
			}
			if (MapData_TwoDim[i / 20][j / 20] == -101)
			{
				MapData_TwoDim[i / 20][j / 20] = -98;
			}
			if (MapData_TwoDim[i / 20][j / 20] == -102)
			{
				MapData_TwoDim[i / 20][j / 20] = 4;
			}
		}
	}

	//二次元配列データを一次元に代入
	for (int i = 0; i<SCREEN_HIGHT / 20; i++)
	{
		for (int j = 0; j < SCREEN_WIDTH / 20; j++)
		{
			static int ij = 0;
			MapData_OneDim_Store[ij] = MapData_TwoDim[i][j];
			if (ij <= 1199) { ij++; }
			if (ij == 1200) { ij = 0; }
		}
	}

	//マップデータ格納
	MapData_Store(MapData_OneDim_Store);	
}


//==============================================================================
// マップ描画処理
//==============================================================================
void C_Field::DrawProcess(LPDIRECT3DDEVICE9 dev)
{
	C_Game_Manager::color = Get_Color();

	//フィールド描画
	FieldDraw_Process(dev);
}