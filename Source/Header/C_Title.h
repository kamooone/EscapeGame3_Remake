//=============================================================================
//
// タイトル処理クラス [C_Title.h]
//
//=============================================================================

#pragma once
#include "Main.h"
#include "C_Game_Manager.h"

class C_Title : public C_Game_Manager{
private:
	LPDIRECT3DTEXTURE9	 t_title, t_title1, t_title2;

	bool flag = true;
	
	bool title_sound = true;
	
protected:


public:
	C_Title() : title_sound(true) { };
	~C_Title() {};
	
	void Init(LPDIRECT3DDEVICE9);  //初期化
	void UnInit();                 //解放
	void UpdateProcess();                 //InputProcess
	void DrawProcess(LPDIRECT3DDEVICE9);	 //drawutil呼び出し

	void TitleDraw(LPDIRECT3DDEVICE9);
	void TitleDraw1(LPDIRECT3DDEVICE9);
	void TitleDraw2(LPDIRECT3DDEVICE9);

};