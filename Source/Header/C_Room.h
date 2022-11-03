//=============================================================================
//
// 部屋処理クラス [C_Room.h]
//
//=============================================================================

#pragma once
#include "Main.h"
#include "C_Game_Manager.h"

class C_Room:public C_Mapchip{
private:
	
protected:


public:
	C_Room() {};
	~C_Room() {};

	//Cplayer
	void Init(LPDIRECT3DDEVICE9);  //初期化
	void UnInit();                 //解放
	void UpdateProcess();                 //InputProcess
	void DrawProcess(LPDIRECT3DDEVICE9);	 //drawutil呼び出し

	//床描画
	void RoomDraw_Process(LPDIRECT3DDEVICE9);
	void Floor1Draw(float, float, LPDIRECT3DDEVICE9);
	void Floor2Draw(float, float, LPDIRECT3DDEVICE9);
	void Floor3Draw(float, float, LPDIRECT3DDEVICE9);
	void Floor4Draw(float, float, LPDIRECT3DDEVICE9);
	void Stairs1Draw(float, float, LPDIRECT3DDEVICE9);
	void Stairs2Draw(float, float, LPDIRECT3DDEVICE9);

	//天井描画
	void Brack1Draw(float, float, LPDIRECT3DDEVICE9);
	void Ceiling1Draw(float, float, LPDIRECT3DDEVICE9);
	void Ceiling2Draw(float, float, LPDIRECT3DDEVICE9);
	void Ceiling3Draw(float, float, LPDIRECT3DDEVICE9);
	void Ceiling4Draw(float, float, LPDIRECT3DDEVICE9);
	void Ceiling5Draw(float, float, LPDIRECT3DDEVICE9);
	void Ceiling6Draw(float, float, LPDIRECT3DDEVICE9);
	void Ceiling7Draw(float, float, LPDIRECT3DDEVICE9);
	void Ceiling8Draw(float, float, LPDIRECT3DDEVICE9);

	//壁描画
	void Wall1Draw(float, float, LPDIRECT3DDEVICE9);
	void Wall2Draw(float, float, LPDIRECT3DDEVICE9);
	void Wall3Draw(float, float, LPDIRECT3DDEVICE9);
	void Wall33Draw(float, float, LPDIRECT3DDEVICE9);
	void Wall4Draw(float, float, LPDIRECT3DDEVICE9);
	void Wall5Draw(float, float, LPDIRECT3DDEVICE9);
	void Wall6Draw(float, float, LPDIRECT3DDEVICE9);
	void Pillar1Draw(float, float, LPDIRECT3DDEVICE9);

	//置物描画
	void Ornament1Draw(float, float, LPDIRECT3DDEVICE9);
	void Ornament2Draw(float, float, LPDIRECT3DDEVICE9);
	void Ornament3Draw(float, float, LPDIRECT3DDEVICE9);
	void Desk1Draw(float, float, LPDIRECT3DDEVICE9);
	void Chair1Draw(float, float, LPDIRECT3DDEVICE9);
	void Chair2Draw(float, float, LPDIRECT3DDEVICE9);
	void Chair3Draw(float, float, LPDIRECT3DDEVICE9);
	void Chair4Draw(float, float, LPDIRECT3DDEVICE9);
	void wood1Draw(float, float, LPDIRECT3DDEVICE9);
	void bed1Draw(float, float, LPDIRECT3DDEVICE9);


	//マップデータ格納&取得
	void MapData_Store(int Store_MapData[(SCREEN_HIGHT / 20) * (SCREEN_WIDTH / 20)])
	{
		for (int i = 0; i<(SCREEN_HIGHT / 20) * (SCREEN_WIDTH / 20); i++)
		{
			MapData_OneDim[i] = Store_MapData[i];
		}
	}
};