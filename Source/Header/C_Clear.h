//=============================================================================
//
// �N���A�����N���X [C_Clear.h]
//
//=============================================================================

#pragma once
#include "Main.h"
#include "C_Game_Manager.h"

class C_Clear : public C_Game_Manager{
private:
	LPDIRECT3DTEXTURE9	 t_clear, t_clear1, t_clear2, t_clear3;

	bool flag = false;
	bool clear_sound = false;
protected:


public:
	C_Clear() :clear_sound(true) {};
	~C_Clear() {};
	
	void Init(LPDIRECT3DDEVICE9);  //������
	void UnInit();                 //���
	void UpdateProcess();                 //InputProcess
	void DrawProcess(LPDIRECT3DDEVICE9);	 //drawutil�Ăяo��

	void ClearDraw(LPDIRECT3DDEVICE9, LPDIRECT3DTEXTURE9);
};