//=============================================================================
//
// マップ描画処理 [DrawField.3_3cpp]
//
//=============================================================================

#include "C_Field3_3.h"


void C_Field3_3::Field1Draw_Process(LPDIRECT3DDEVICE9 dev)
{
	for (int i = 0; i < 1000; i += 20)
	{
		for (int j = 0; j < 1200; j += 20)
		{
			//地面描画
			if (MapData_No2_TwoDim[i / 20][j / 20] == 9 || MapData_No2_TwoDim[i / 20][j / 20] == 5)
			{
				//Ground1Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}

			//木の下の地面
			if (MapData_No2_TwoDim[i / 20][j / 20] == -2 || MapData_No2_TwoDim[i / 20][j / 20] == -20
				|| MapData_No2_TwoDim[i / 20][j / 20] == 3 || MapData_No2_TwoDim[i / 20][j / 20] == 9 || MapData_No2_TwoDim[i / 20][j / 20] == 5)
			{
				Ground3Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}

			//ガードレール描画
			if (MapData_No2_TwoDim[i / 20][j / 20] == -11 || MapData_No2_TwoDim[i / 20][j / 20] == -98)
			{
				Guardrail1Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			if (MapData_No2_TwoDim[i / 20][j / 20] == -12 || MapData_No2_TwoDim[i / 20][j / 20] == -99)
			{
				Guardrail2Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}

			//川描画
			if (MapData_No2_TwoDim[i / 20][j / 20] == -10)
			{
				River1Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}

			//出入り口のタイル
			if (MapData_No2_TwoDim[i / 20][j / 20] == -5 || MapData_No2_TwoDim[i / 20][j / 20] == -102
				|| MapData_No2_TwoDim[i / 20][j / 20] == -100 || MapData_No2_TwoDim[i / 20][j / 20] == -101
				|| MapData_No2_TwoDim[i / 20][j / 20] == 1 || MapData_No2_TwoDim[i / 20][j / 20] == -90 || MapData_No2_TwoDim[i / 20][j / 20] == 2)
			{
				Ground2Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
		}
	}

	for (int i = 0; i < 1000; i += 20)
	{
		for (int j = 0; j < 1200; j += 20)
		{
			//木描画
			if (MapData_No2_TwoDim[i / 20][j / 20] == -20)
			{
				Tree1Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			//通せんぼ描画
			if (MapData_No2_TwoDim[i / 20][j / 20] == -100)
			{
				TosenboDraw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
		}
	}
}