//=============================================================================
//
// マップ描画処理 [DrawRoom.cpp]
//
//=============================================================================

#include "C_Room.h"


void C_Room::RoomDraw_Process(LPDIRECT3DDEVICE9 dev)
{
	//奥(Z軸)の物を先に全て描画してから手前の物を描画する
	for (int i = 0; i < column; i += 20)
	{
		for (int j = 0; j < row; j += 20)
		{
			//地面描画
			if (MapData_TwoDim[i / 20][j / 20] == 1 || MapData_TwoDim[i / 20][j / 20] == -99 || MapData_TwoDim[i / 20][j / 20] == -13 || MapData_TwoDim[i / 20][j / 20] == -30
				|| MapData_TwoDim[i / 20][j / 20] == 0)
			{
				Floor1Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			if (MapData_TwoDim[i / 20][j / 20] == 2 || MapData_TwoDim[i / 20][j / 20] == -98)
			{
				Floor2Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			if (MapData_TwoDim[i / 20][j / 20] == 3 || MapData_TwoDim[i / 20][j / 20] == -97)
			{
				Floor3Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			if (MapData_TwoDim[i / 20][j / 20] == 4)
			{
				Floor4Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			if (MapData_TwoDim[i / 20][j / 20] == -115)
			{
				Stairs1Draw((float)j + scroll_x, (float)i + scroll_y, dev);
				Stairs2Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}

			//天井描画
			if (MapData_TwoDim[i / 20][j / 20] == -90 || MapData_TwoDim[i / 20][j / 20] == -15 || MapData_TwoDim[i / 20][j / 20] == -16)
			{
				Brack1Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			if (MapData_TwoDim[i / 20][j / 20] == -10)
			{
				Ceiling1Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			if (MapData_TwoDim[i / 20][j / 20] == -11)
			{
				Ceiling2Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			if (MapData_TwoDim[i / 20][j / 20] == -12)
			{
				Ceiling3Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			if (MapData_TwoDim[i / 20][j / 20] == -13)
			{
				Ceiling4Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			if (MapData_TwoDim[i / 20][j / 20] == -14)
			{
				Ceiling5Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			if (MapData_TwoDim[i / 20][j / 20] == -15)
			{
				Ceiling6Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			if (MapData_TwoDim[i / 20][j / 20] == -16)
			{
				Ceiling7Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			if (MapData_TwoDim[i / 20][j / 20] == -17)
			{
				Ceiling8Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}


			//壁描画
			if (MapData_TwoDim[i / 20][j / 20] == -39)
			{
				Wall1Draw((float)j + scroll_x, (float)i + scroll_y, dev);
				Wall2Draw((float)j + scroll_x, (float)i + scroll_y, dev);
				Wall33Draw((float)j + scroll_x, (float)i + scroll_y, dev);
				Wall3Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			if (MapData_TwoDim[i / 20][j / 20] == -38)
			{
				Wall5Draw((float)j + scroll_x, (float)i + scroll_y, dev);
				Wall6Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			if (MapData_TwoDim[i / 20][j / 20] == -37)
			{
				Wall4Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			//柱描画
			if (MapData_TwoDim[i / 20][j / 20] == -20)
			{
				Pillar1Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
		}
	}

	for (int i = 0; i < column; i += 20)
	{
		for (int j = 0; j < row; j += 20)
		{
			//置物描画
			if (MapData_TwoDim[i / 20][j / 20] == -21)
			{
				Ornament1Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			if (MapData_TwoDim[i / 20][j / 20] == -22)
			{
				Ornament2Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			if (MapData_TwoDim[i / 20][j / 20] == -23)
			{
				Ornament3Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			if (MapData_TwoDim[i / 20][j / 20] == -24)
			{
				Desk1Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			if (MapData_TwoDim[i / 20][j / 20] == -25)
			{
				Chair1Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			if (MapData_TwoDim[i / 20][j / 20] == -26)
			{
				Chair2Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			if (MapData_TwoDim[i / 20][j / 20] == -27)
			{
				Chair3Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			if (MapData_TwoDim[i / 20][j / 20] == -28)
			{
				Chair4Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			if (MapData_TwoDim[i / 20][j / 20] == -29)
			{
				wood1Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
			if (MapData_TwoDim[i / 20][j / 20] == -30)
			{
				bed1Draw((float)j + scroll_x, (float)i + scroll_y, dev);
			}
		}
	}
}