//=============================================================================
//
// É}ÉbÉvï`âÊèàóù [DrawField2_1.cpp]
//
//=============================================================================

#include "C_Field2_1.h"


void C_Field2_1::FieldDraw_Process(LPDIRECT3DDEVICE9 dev)
{
	for (int i = 0; i < column; i += 20)
	{
		for (int j = 0; j < row; j += 20)
		{
			//ínñ ï`âÊ
			if (MapData_TwoDim[i / 20][j / 20] == 1 || MapData_TwoDim[i / 20][j / 20] == 3 || MapData_TwoDim[i / 20][j / 20] == -99 || MapData_TwoDim[i / 20][j / 20] == 5 || MapData_TwoDim[i / 20][j / 20] == 9
				|| MapData_TwoDim[i / 20][j / 20] == -20)
			{
				Ground1Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			if (MapData_TwoDim[i / 20][j / 20] == 2 || MapData_TwoDim[i / 20][j / 20] == -98 ||
				MapData_TwoDim[i / 20][j / 20] == -100 || MapData_TwoDim[i / 20][j / 20] == -101 || MapData_TwoDim[i / 20][j / 20] == -97)
			{
				Ground2Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			//ñÿÇÃâ∫ÇÃínñ 
			if (MapData_TwoDim[i / 20][j / 20] == 2 || MapData_TwoDim[i / 20][j / 20] == 4
				|| MapData_TwoDim[i / 20][j / 20] == -2 || MapData_TwoDim[i / 20][j / 20] == -102 || MapData_TwoDim[i / 20][j / 20] == -90)
			{
				Ground3Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			//ÉKÅ[ÉhÉåÅ[Éãï`âÊ
			if (MapData_TwoDim[i / 20][j / 20] == -11)
			{
				Guardrail1Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			if (MapData_TwoDim[i / 20][j / 20] == -12)
			{
				Guardrail2Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			//êÏï`âÊ
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
			//ñÿï`âÊ
			if (MapData_TwoDim[i / 20][j / 20] == -20)
			{
				Tree1Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}

			//í ÇπÇÒÇ⁄ï`âÊ
			if (MapData_TwoDim[i / 20][j / 20] == -100)
			{
				TosenboDraw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
		}
	}
}