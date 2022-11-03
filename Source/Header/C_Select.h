//=============================================================================
//
// セレクト画面処理クラス [C_Select.h]
//
//=============================================================================

#pragma once
#include "Main.h"
#include "C_Game_Manager.h"

class C_Select : public C_Game_Manager {
private:
	LPDIRECT3DTEXTURE9	 t_select, t_select1, t_select2, t_select3, t_select4;
	LPDIRECT3DTEXTURE9	 t_selectNow2, t_selectNow3, t_selectNow4;

	bool flag = true;

	bool select_sound = false;

protected:
	static int world_no;

public:
	C_Select() : select_sound(false) { };
	~C_Select() {};

	void Init(LPDIRECT3DDEVICE9);  //初期化
	void UnInit();                 //解放
	void UpdateProcess();                 //InputProcess
	void DrawProcess(LPDIRECT3DDEVICE9);	 //drawutil呼び出し


	void SelectDraw(LPDIRECT3DDEVICE9);

	void SelectDraw1(LPDIRECT3DDEVICE9);
	
	void SelectDraw2(LPDIRECT3DDEVICE9);
	void SelectNow2(LPDIRECT3DDEVICE9);

	void SelectDraw3(LPDIRECT3DDEVICE9);
	void SelectNow3(LPDIRECT3DDEVICE9);

	void SelectDraw4(LPDIRECT3DDEVICE9);
	void SelectNow4(LPDIRECT3DDEVICE9);

	//ワールドナンバー格納&取得
	static void Store_World_No(int store_world_no) { world_no = store_world_no; }
	static int Get_World_No() { return world_no; }
};