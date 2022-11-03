//=============================================================================
//
// �}�b�v�����N���X [C_Field2.h]
//
//=============================================================================

#pragma once
#include "Main.h"
#include "C_Game_Manager.h"

class C_Field2 :public C_Mapchip {
private:

protected:

public:
	C_Field2() {};
	~C_Field2() {};

	//Cplayer
	void Init(LPDIRECT3DDEVICE9);            //������
	void UnInit();                           //���
	void UpdateProcess();                    //InputProcess
	void DrawProcess(LPDIRECT3DDEVICE9);	 //drawutil�Ăяo��


	void FieldDraw_Process(LPDIRECT3DDEVICE9);
	void Ground1Draw(float, float, LPDIRECT3DDEVICE9);
	void Ground2Draw(float, float, LPDIRECT3DDEVICE9);
	void Ground3Draw(float, float, LPDIRECT3DDEVICE9);
	void Guardrail1Draw(float, float, LPDIRECT3DDEVICE9);
	void Guardrail2Draw(float, float, LPDIRECT3DDEVICE9);
	void River1Draw(float, float, LPDIRECT3DDEVICE9);
	void Tree1Draw(float, float, LPDIRECT3DDEVICE9);
	void TosenboDraw(float, float, LPDIRECT3DDEVICE9);

	//�}�b�v�f�[�^�i�[&�擾
	void MapData_Store(int Store_MapData[(SCREEN_HIGHT / 20) * (SCREEN_WIDTH / 20)])
	{
		for (int i = 0; i<(SCREEN_HIGHT / 20) * (SCREEN_WIDTH / 20); i++)
		{
			MapData_OneDim[i] = Store_MapData[i];
		}
	}
};