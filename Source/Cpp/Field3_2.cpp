//=============================================================================
//
// マップ描画処理 [Field2_1.cpp]
//
//=============================================================================

#include "C_Field3_2.h"
#include "C_Sound.h"

#include<stdio.h>
#include<string.h>
#include<stdlib.h>



//==============================================================================
// 初期化処理
//==============================================================================
void C_Field3_2::Init(LPDIRECT3DDEVICE9 dev)
{
	HRESULT hr = D3DXCreateTextureFromFile(dev, "assets/field.png", &t_mapchip);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}

	errno_t error;
	FILE *f;

	//マップデータファイル読み込み
	error = fopen_s(&f, "External_File/field3_2.csv", "r");

	if (error != 0)
	{
		MessageBox(NULL, "load file error", "error", MB_OK);
	}
	else {
		//ファイルのデータを二次元配列に格納
		for (int i = 0; i<1000 / 20; i++)
		{
			fscanf_s(f,
				"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
				&MapData_No2_TwoDim[i][0], &MapData_No2_TwoDim[i][1], &MapData_No2_TwoDim[i][2], &MapData_No2_TwoDim[i][3], &MapData_No2_TwoDim[i][4],
				&MapData_No2_TwoDim[i][5], &MapData_No2_TwoDim[i][6], &MapData_No2_TwoDim[i][7], &MapData_No2_TwoDim[i][8], &MapData_No2_TwoDim[i][9],
				&MapData_No2_TwoDim[i][10], &MapData_No2_TwoDim[i][11], &MapData_No2_TwoDim[i][12], &MapData_No2_TwoDim[i][13], &MapData_No2_TwoDim[i][14],
				&MapData_No2_TwoDim[i][15], &MapData_No2_TwoDim[i][16], &MapData_No2_TwoDim[i][17], &MapData_No2_TwoDim[i][18], &MapData_No2_TwoDim[i][19],
				&MapData_No2_TwoDim[i][20], &MapData_No2_TwoDim[i][21], &MapData_No2_TwoDim[i][22], &MapData_No2_TwoDim[i][23], &MapData_No2_TwoDim[i][24],
				&MapData_No2_TwoDim[i][25], &MapData_No2_TwoDim[i][26], &MapData_No2_TwoDim[i][27], &MapData_No2_TwoDim[i][28], &MapData_No2_TwoDim[i][29],
				&MapData_No2_TwoDim[i][30], &MapData_No2_TwoDim[i][31], &MapData_No2_TwoDim[i][32], &MapData_No2_TwoDim[i][33], &MapData_No2_TwoDim[i][34],
				&MapData_No2_TwoDim[i][35], &MapData_No2_TwoDim[i][36], &MapData_No2_TwoDim[i][37], &MapData_No2_TwoDim[i][38], &MapData_No2_TwoDim[i][39],
				&MapData_No2_TwoDim[i][40], &MapData_No2_TwoDim[i][41], &MapData_No2_TwoDim[i][42], &MapData_No2_TwoDim[i][43], &MapData_No2_TwoDim[i][44],
				&MapData_No2_TwoDim[i][45], &MapData_No2_TwoDim[i][46], &MapData_No2_TwoDim[i][47], &MapData_No2_TwoDim[i][48], &MapData_No2_TwoDim[i][49],
				&MapData_No2_TwoDim[i][50], &MapData_No2_TwoDim[i][51], &MapData_No2_TwoDim[i][52], &MapData_No2_TwoDim[i][53], &MapData_No2_TwoDim[i][54],
				&MapData_No2_TwoDim[i][55], &MapData_No2_TwoDim[i][56], &MapData_No2_TwoDim[i][57], &MapData_No2_TwoDim[i][58], &MapData_No2_TwoDim[i][59]);
		}
	}
	fclose(f);

	//二次元配列データを一次元に代入
	for (int i = 0; i<1000 / 20; i++)
	{
		for (int j = 0; j < 1200 / 20; j++)
		{
			static int ij = 0;
			MapData_No2_OneDim_Store[ij] = MapData_No2_TwoDim[i][j];
			ij++;
		}
	}
}


//==============================================================================
// 終了処理
//==============================================================================
void C_Field3_2::UnInit()
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
void C_Field3_2::UpdateProcess()
{
	C_Game_Manager::manual_no = Get_Manual_No();

	for (int i = 0; i < 1000; i += 20)
	{
		for (int j = 0; j < 1200; j += 20)
		{
			if (MapData_No2_TwoDim[i / 20][j / 20] == -100)
			{
				MapData_No2_TwoDim[i / 20][j / 20] = -98;
			}
			if (MapData_No2_TwoDim[i / 20][j / 20] == -101)
			{
				MapData_No2_TwoDim[i / 20][j / 20] = 4;
			}
			if (MapData_No2_TwoDim[i / 20][j / 20] == -102)
			{
				MapData_No2_TwoDim[i / 20][j / 20] = -99;
			}
		}
	}

	//二次元配列データを一次元に代入
	for (int i = 0; i<1000 / 20; i++)
	{
		for (int j = 0; j < 1200 / 20; j++)
		{
			static int ij = 0;
			MapData_No2_OneDim_Store[ij] = MapData_No2_TwoDim[i][j];
			if (ij <= 2999) { ij++; }
			if (ij == 3000) { ij = 0; }
		}
	}

	//マップデータ格納
	MapData_Store(MapData_No2_OneDim_Store);
}


//==============================================================================
// マップ描画処理
//==============================================================================
void C_Field3_2::DrawProcess(LPDIRECT3DDEVICE9 dev)
{
	//カラー値取得
	C_Game_Manager::color = Get_Color();

	//フィールド描画
	Field1Draw_Process(dev);
}