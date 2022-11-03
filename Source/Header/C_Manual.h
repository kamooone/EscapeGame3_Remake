//=============================================================================
//
// �}�j���A����ʏ����N���X [C_Manual.h]
//
//=============================================================================

#pragma once
#include "Main.h"
#include "C_Game_Manager.h"

class C_Manual : public C_Game_Manager{
private:
	LPDIRECT3DTEXTURE9	 t_manual1, t_manual2, t_manual3, t_manual4, t_manual5, t_manual6;
	LPDIRECT3DTEXTURE9	 t_operator;

	bool manual_bedflag = false;
	bool manual_bed = false;

	//�}�j���A���\���t���O
	bool manual_draw_flag = false;
	int manual_color = 0;
protected:


public:
	C_Manual() {};
	~C_Manual() {};
	
	void Init(LPDIRECT3DDEVICE9);  //������
	void UnInit();                 //���
	void UpdateProcess();                 //InputProcess
	void DrawProcess(LPDIRECT3DDEVICE9);	 //drawutil�Ăяo��


	void Manual_Draw(LPDIRECT3DDEVICE9, LPDIRECT3DTEXTURE9);

	void Operator_Draw(LPDIRECT3DDEVICE9);
};