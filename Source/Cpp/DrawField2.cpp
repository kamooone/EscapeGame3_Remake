//=============================================================================
//
// マップ描画処理 [DrawField2.cpp]
//
//=============================================================================

#include "C_Field2.h"


void C_Field2::FieldDraw_Process(LPDIRECT3DDEVICE9 dev)
{
	for (int i = 0; i < column; i += 20)
	{
		for (int j = 0; j < row; j += 20)
		{
			//地面描画
			if (MapData_TwoDim[i / 20][j / 20] == 1 || MapData_TwoDim[i / 20][j / 20] == 3 || MapData_TwoDim[i / 20][j / 20] == -99)
			{
				Ground1Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			if (MapData_TwoDim[i / 20][j / 20] == 2 || MapData_TwoDim[i / 20][j / 20] == -98 || MapData_TwoDim[i / 20][j / 20] == -100 ||
				MapData_TwoDim[i / 20][j / 20] == -101 || MapData_TwoDim[i / 20][j / 20] == -97 || MapData_TwoDim[i / 20][j / 20] == -96)
			{
				Ground2Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			//木の下の地面
			if (MapData_TwoDim[i / 20][j / 20] == 2 || MapData_TwoDim[i / 20][j / 20] == -20 || MapData_TwoDim[i / 20][j / 20] == 5 || MapData_TwoDim[i / 20][j / 20] == 4
				|| MapData_TwoDim[i / 20][j / 20] == 9 || MapData_TwoDim[i / 20][j / 20] == -2 || MapData_TwoDim[i / 20][j / 20] == -102)
			{
				Ground3Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			//ガードレール描画
			if (MapData_TwoDim[i / 20][j / 20] == -11)
			{
				Guardrail1Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			if (MapData_TwoDim[i / 20][j / 20] == -12)
			{
				Guardrail2Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			//川描画
			if (MapData_TwoDim[i / 20][j / 20] == -10)
			{
				River1Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
		}
	}

	for (int i = 0; i < column; i += 20)
	{
		for (int j = 0; j < row; j += 20)
		{
			//木描画
			if (MapData_TwoDim[i / 20][j / 20] == -20)
			{
				Tree1Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}

			//通せんぼ描画
			if (MapData_TwoDim[i / 20][j / 20] == -100)
			{
				TosenboDraw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
		}
	}
}