//=============================================================================
//
// �}�b�v�����N���X [C_Field3_1.h]
//
//=============================================================================

#pragma once
#include "Main.h"
#include "C_Game_Manager.h"

class C_Field3_1 :public C_Mapchip {
private:

protected:

public:
	C_Field3_1() {	};
	~C_Field3_1() {};

	//Cplayer
	void Init(LPDIRECT3DDEVICE9);  //������
	void UnInit();                 //���
	void UpdateProcess();                 //InputProcess
	void DrawProcess(LPDIRECT3DDEVICE9);	 //drawutil�Ăяo��


	void Field1Draw_Process(LPDIRECT3DDEVICE9);
	void Ground1Draw(float, float, LPDIRECT3DDEVICE9);
	void Ground2Draw(float, float, LPDIRECT3DDEVICE9);
	void Ground3Draw(float, float, LPDIRECT3DDEVICE9);
	void Guardrail1Draw(float, float, LPDIRECT3DDEVICE9);
	void Guardrail2Draw(float, float, LPDIRECT3DDEVICE9);
	void River1Draw(float, float, LPDIRECT3DDEVICE9);
	void Tree1Draw(float, float, LPDIRECT3DDEVICE9);
	void TosenboDraw(float, float, LPDIRECT3DDEVICE9);

	//�}�b�v�f�[�^�i�[&�擾
	void MapData_Store(int Store_MapData[(1000 / 20) * (1200 / 20)])
	{
		for (int i = 0; i<(1000 / 20) * (1200 / 20); i++)
		{
			MapData_No2_OneDim[i] = Store_MapData[i];
		}
	}
};