//=============================================================================
//
// �}�b�v�`�揈�� [DrawField1.cpp]
//
//=============================================================================

#include "C_Field1.h"


void C_Field1::Field1Draw_Process(LPDIRECT3DDEVICE9 dev)
{
	for (int i = 0; i < 1000; i += 20)
	{
		for (int j = 0; j < 1200; j += 20)
		{
			//�n�ʕ`��
			if (MapData_No2_TwoDim[i / 20][j / 20] == 1)
			{
				Ground1Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}

			//�؂̉��̒n��
			if (MapData_No2_TwoDim[i / 20][j / 20] == -2 || MapData_No2_TwoDim[i / 20][j / 20] == -20 || MapData_No2_TwoDim[i / 20][j / 20] == 3)
			{
				Ground3Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			
			//�K�[�h���[���`��
			if (MapData_No2_TwoDim[i / 20][j / 20] == -11)
			{
				Guardrail1Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			if (MapData_No2_TwoDim[i / 20][j / 20] == -12)
			{
				Guardrail2Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}

			//��`��
			if (MapData_No2_TwoDim[i / 20][j / 20] == -10)
			{
				River1Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}

			//�o������̃^�C��
			if (MapData_No2_TwoDim[i / 20][j / 20] == 9 || MapData_No2_TwoDim[i / 20][j / 20] == 5 || MapData_No2_TwoDim[i / 20][j / 20] == 2
				|| MapData_No2_TwoDim[i / 20][j / 20] == -5 || MapData_No2_TwoDim[i / 20][j / 20] == -99 || MapData_No2_TwoDim[i / 20][j / 20] == -102
				|| MapData_No2_TwoDim[i / 20][j / 20] == -100 || MapData_No2_TwoDim[i / 20][j / 20] == -101 || MapData_No2_TwoDim[i / 20][j / 20] == -98
				|| MapData_No2_TwoDim[i / 20][j / 20] == 4)
			{
				Ground2Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
		}
	}

	for (int i = 0; i < 1000; i += 20)
	{
		for (int j = 0; j < 1200; j += 20)
		{
			//�ؕ`��
			if (MapData_No2_TwoDim[i / 20][j / 20] == -20)
			{
				Tree1Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			//�ʂ���ڕ`��
			if (MapData_No2_TwoDim[i / 20][j / 20] == -100)
			{
				TosenboDraw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
		}
	}
}