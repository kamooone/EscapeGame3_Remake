//=============================================================================
//
// プレイヤー描画処理 [PlayerDrawutil.cpp]
//
//=============================================================================

#include "C_Player.h"
#include "Drawutil.h"


void C_Player::PlayerDraw(float tu[], float tv[], LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	if (damage <= 39)
	{
		Vertex[0].x = pos_x - PLAYER_WIDTH / 2;
		Vertex[0].y = pos_y - PLAYER_HIGHT / 2;
		Vertex[0].z = 0.0f;
		Vertex[0].u = tu[0];
		Vertex[0].v = tv[0];

		Vertex[1].x = pos_x + PLAYER_WIDTH / 2;
		Vertex[1].y = pos_y - PLAYER_HIGHT / 2;
		Vertex[1].z = 0.0f;
		Vertex[1].u = tu[1];
		Vertex[1].v = tv[1];

		Vertex[2].x = pos_x - PLAYER_WIDTH / 2;
		Vertex[2].y = pos_y + PLAYER_HIGHT / 2;
		Vertex[2].z = 0.0f;
		Vertex[2].u = tu[2];
		Vertex[2].v = tv[2];

		Vertex[3].x = pos_x + PLAYER_WIDTH / 2;
		Vertex[3].y = pos_y + PLAYER_HIGHT / 2;
		Vertex[3].z = 0.0f;
		Vertex[3].u = tu[3];
		Vertex[3].v = tv[3];
	}

    if (damage >= 40)
	{
		Vertex[0].x = (-PLAYER_WIDTH / 2);
		Vertex[0].y = (-PLAYER_HIGHT / 2);
		Vertex[0].z = 0.0f;
		Vertex[0].u = 0.0f;
		Vertex[0].v = 0.0f;

		Vertex[1].x = (+PLAYER_WIDTH / 2);
		Vertex[1].y = (-PLAYER_HIGHT / 2);
		Vertex[1].z = 0.0f;
		Vertex[1].u = 0.25f;
		Vertex[1].v = 0.0f;

		Vertex[2].x = (-PLAYER_WIDTH / 2);
		Vertex[2].y = (+PLAYER_HIGHT / 2);
		Vertex[2].z = 0.0f;
		Vertex[2].u = 0.0f;
		Vertex[2].v = 0.25f;

		Vertex[3].x = (PLAYER_WIDTH / 2);
		Vertex[3].y = (PLAYER_HIGHT / 2);
		Vertex[3].z = 0.0f;
		Vertex[3].u = 0.25f;
		Vertex[3].v = 0.25f;


		rotatenumber += 0.15f;

		//変換結果をバックアップ
		VERTEX_2DTEX tempv[4];
		for (int cnt = 0; cnt < 4; cnt++)
		{
			tempv[cnt].x = Vertex[cnt].x * cosf(rotatenumber) + Vertex[cnt].y*sinf(rotatenumber);
			tempv[cnt].y = Vertex[cnt].x * -sinf(rotatenumber) + Vertex[cnt].y*cosf(rotatenumber);
		}

		//上記で変えた頂点座標を新たにセット
		for (int cnt = 0; cnt < 4; cnt++)
		{
			Vertex[cnt].x = tempv[cnt].x;
			Vertex[cnt].y = tempv[cnt].y;
		}

		// 
		for (int i = 0; i < 4; i++)
		{
			Vertex[i].x += pos_x;
			Vertex[i].y += pos_y;
		}
	}

	Vertex[0].col = D3DCOLOR_RGBA(flash_counter_color, collision_flag == false ? flash_counter_color : 0,
		                          collision_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(flash_counter_color, collision_flag == false ? flash_counter_color : 0,
		                          collision_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(flash_counter_color, collision_flag == false ? flash_counter_color : 0,
		                          collision_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(flash_counter_color, collision_flag == false ? flash_counter_color : 0,
		                          collision_flag == false ? C_Game_Manager::color : 0,C_Game_Manager::color);

	// 頂点フォーマット指定
	dev->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	// テクスチャをセット
	dev->SetTexture(0, t_player);

	dev->DrawPrimitiveUP(
		D3DPT_TRIANGLESTRIP,
		2,
		Vertex,
		sizeof(VERTEX_2DTEX));
}


void C_Player::HPGageDraw(int store_damage,LPDIRECT3DDEVICE9 dev, LPDIRECT3DTEXTURE9 tex)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = pos_x - PLAYER_WIDTH / 2+10.0f;//280
	Vertex[0].y = pos_y - PLAYER_HIGHT + 17.0f;
	Vertex[0].z = 0.0f;
	Vertex[0].u = 0.0f;
	Vertex[0].v = 0.0f;

	Vertex[1].x = pos_x + PLAYER_WIDTH / 2 - 10.0f - store_damage;//320
	Vertex[1].y = pos_y - PLAYER_HIGHT+17.0f;
	Vertex[1].z = 0.0f;
	Vertex[1].u = 1.0f;
	Vertex[1].v = 0.0f;

	Vertex[2].x = pos_x - PLAYER_WIDTH / 2 + 10.0f;
	Vertex[2].y = pos_y - PLAYER_HIGHT +25.0f;
	Vertex[2].z = 0.0f;
	Vertex[2].u = 0.0f;
	Vertex[2].v = 1.0f;

	Vertex[3].x = pos_x + PLAYER_WIDTH / 2 - 10.0f - store_damage;
	Vertex[3].y = pos_y - PLAYER_HIGHT + 25.0f;
	Vertex[3].z = 0.0f;
	Vertex[3].u = 1.0f;
	Vertex[3].v = 1.0f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, flash_counter_color, C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, flash_counter_color, C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, flash_counter_color, C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, flash_counter_color, C_Game_Manager::color);

	// 頂点フォーマット指定
	dev->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	// テクスチャをセット
	dev->SetTexture(0, tex);

	dev->DrawPrimitiveUP(
		D3DPT_TRIANGLESTRIP,
		2,
		Vertex,
		sizeof(VERTEX_2DTEX));
}


void C_Player::ShadowDraw(LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = pos_x - PLAYER_WIDTH / 2 + 11.0f;//280
	Vertex[0].y = pos_y - PLAYER_HIGHT + 60.0f;
	Vertex[0].z = 0.0f;
	Vertex[0].u = 0.0f;
	Vertex[0].v = 0.0f;

	Vertex[1].x = pos_x + PLAYER_WIDTH / 2 - 13.0f;//320
	Vertex[1].y = pos_y - PLAYER_HIGHT + 60.0f;
	Vertex[1].z = 0.0f;
	Vertex[1].u = 1.0f;
	Vertex[1].v = 0.0f;

	Vertex[2].x = pos_x - PLAYER_WIDTH / 2 + 11.0f;
	Vertex[2].y = pos_y - PLAYER_HIGHT + 80.0f;
	Vertex[2].z = 0.0f;
	Vertex[2].u = 0.0f;
	Vertex[2].v = 1.0f;

	Vertex[3].x = pos_x + PLAYER_WIDTH / 2 - 13.0f;
	Vertex[3].y = pos_y - PLAYER_HIGHT + 80.0f;
	Vertex[3].z = 0.0f;
	Vertex[3].u = 1.0f;
	Vertex[3].v = 1.0f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, flash_counter_color, C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, flash_counter_color, C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, flash_counter_color, C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, flash_counter_color, C_Game_Manager::color);

	// 頂点フォーマット指定
	dev->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	// テクスチャをセット
	dev->SetTexture(0, t_shadow);

	dev->DrawPrimitiveUP(
		D3DPT_TRIANGLESTRIP,
		2,
		Vertex,
		sizeof(VERTEX_2DTEX));
}


void C_Player::SelectPlayerDraw(float x, float y, float tu[], float tv[], LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = pos_x + x - PLAYER_WIDTH / 2;
	Vertex[0].y = pos_y + y - PLAYER_HIGHT / 2;
	Vertex[0].z = 0.0f;
	Vertex[0].u = tu[0];
	Vertex[0].v = tv[0];

	Vertex[1].x = pos_x + x + PLAYER_WIDTH / 2;
	Vertex[1].y = pos_y + y - PLAYER_HIGHT / 2;
	Vertex[1].z = 0.0f;
	Vertex[1].u = tu[1];
	Vertex[1].v = tv[1];

	Vertex[2].x = pos_x + x - PLAYER_WIDTH / 2;
	Vertex[2].y = pos_y + y + PLAYER_HIGHT / 2;
	Vertex[2].z = 0.0f;
	Vertex[2].u = tu[2];
	Vertex[2].v = tv[2];

	Vertex[3].x = pos_x + x + PLAYER_WIDTH / 2;
	Vertex[3].y = pos_y + y + PLAYER_HIGHT / 2;
	Vertex[3].z = 0.0f;
	Vertex[3].u = tu[3];
	Vertex[3].v = tv[3];
	
	Vertex[0].col = D3DCOLOR_RGBA(flash_counter_color, collision_flag == false ? flash_counter_color : 0,
		collision_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(flash_counter_color, collision_flag == false ? flash_counter_color : 0,
		collision_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(flash_counter_color, collision_flag == false ? flash_counter_color : 0,
		collision_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(flash_counter_color, collision_flag == false ? flash_counter_color : 0,
		collision_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);

	// 頂点フォーマット指定
	dev->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	// テクスチャをセット
	dev->SetTexture(0, t_player);

	dev->DrawPrimitiveUP(
		D3DPT_TRIANGLESTRIP,
		2,
		Vertex,
		sizeof(VERTEX_2DTEX));
}


void C_Player::ControllerDraw(LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = pos_x - PLAYER_WIDTH / 2 - 250.0f;
	Vertex[0].y = pos_y - PLAYER_HIGHT / 2 - 200.0f;
	Vertex[0].z = 0.0f;
	Vertex[0].u = 0.0f;
	Vertex[0].v = 0.0f;

	Vertex[1].x = pos_x + PLAYER_WIDTH / 2 + 250.0f;
	Vertex[1].y = pos_y - PLAYER_HIGHT / 2 - 200.0f;
	Vertex[1].z = 0.0f;
	Vertex[1].u = 1.0f;
	Vertex[1].v = 0.0f;

	Vertex[2].x = pos_x - PLAYER_WIDTH / 2 - 250.0f;
	Vertex[2].y = pos_y + PLAYER_HIGHT / 2 + 200.0f;
	Vertex[2].z = 0.0f;
	Vertex[2].u = 0.0f;
	Vertex[2].v = 1.0f;

	Vertex[3].x = pos_x + PLAYER_WIDTH / 2 + 250.0f;
	Vertex[3].y = pos_y + PLAYER_HIGHT / 2 + 200.0f;
	Vertex[3].z = 0.0f;
	Vertex[3].u = 1.0f;
	Vertex[3].v = 1.0f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, flash_counter_color, C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, flash_counter_color, C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, flash_counter_color, C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, flash_counter_color, C_Game_Manager::color);

	// 頂点フォーマット指定
	dev->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	// テクスチャをセット
	dev->SetTexture(0, T_controller);

	dev->DrawPrimitiveUP(
		D3DPT_TRIANGLESTRIP,
		2,
		Vertex,
		sizeof(VERTEX_2DTEX));
}