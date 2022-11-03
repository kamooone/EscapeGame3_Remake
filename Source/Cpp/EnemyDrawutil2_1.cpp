//=============================================================================
//
// エネミー描画処理 [EnemyDrawutil2_1.cpp]
//
//=============================================================================

#include "C_Enemy2_1.h"
#include "Drawutil.h"


void C_Enemy2_1::EnemyDraw(int i, float x, float y, float tu[], float tv[], LPDIRECT3DDEVICE9 dev, LPDIRECT3DTEXTURE9 tex)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

									//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = pos_x[i] - ENEMY_WIDTH / 2 + x;
	Vertex[0].y = pos_y[i] - ENEMY_HIGHT / 2 + y;
	Vertex[0].z = 0.0f;
	Vertex[0].u = tu[0];
	Vertex[0].v = tv[0];

	Vertex[1].x = pos_x[i] + ENEMY_WIDTH / 2 + x;
	Vertex[1].y = pos_y[i] - ENEMY_HIGHT / 2 + y;
	Vertex[1].z = 0.0f;
	Vertex[1].u = tu[1];
	Vertex[1].v = tv[1];

	Vertex[2].x = pos_x[i] - ENEMY_WIDTH / 2 + x;
	Vertex[2].y = pos_y[i] + ENEMY_HIGHT / 2 + y;
	Vertex[2].z = 0.0f;
	Vertex[2].u = tu[2];
	Vertex[2].v = tv[2];

	Vertex[3].x = pos_x[i] + ENEMY_WIDTH / 2 + x;
	Vertex[3].y = pos_y[i] + ENEMY_HIGHT / 2 + y;
	Vertex[3].z = 0.0f;
	Vertex[3].u = tu[3];
	Vertex[3].v = tv[3];

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag[i] == false ? C_Game_Manager::color : 0,
		damage_flag[i] == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag[i] == false ? C_Game_Manager::color : 0,
		damage_flag[i] == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag[i] == false ? C_Game_Manager::color : 0,
		damage_flag[i] == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag[i] == false ? C_Game_Manager::color : 0,
		damage_flag[i] == false ? C_Game_Manager::color : 0, C_Game_Manager::color);

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


void C_Enemy2_1::AppleDraw(int i, float x, float y, LPDIRECT3DDEVICE9 dev, LPDIRECT3DTEXTURE9 tex)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

									//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = pos_x[i] - ENEMY_WIDTH / 2 + x + 10.0f;
	Vertex[0].y = pos_y[i] - ENEMY_HIGHT / 2 + y + 5.0f;
	Vertex[0].z = 0.0f;
	Vertex[0].u = 0.0f;
	Vertex[0].v = 0.0f;

	Vertex[1].x = pos_x[i] + ENEMY_WIDTH / 2 + x - 10.0f;
	Vertex[1].y = pos_y[i] - ENEMY_HIGHT / 2 + y + 5.0f;
	Vertex[1].z = 0.0f;
	Vertex[1].u = 1.0f;
	Vertex[1].v = 0.0f;

	Vertex[2].x = pos_x[i] - ENEMY_WIDTH / 2 + x + 10.0f;
	Vertex[2].y = pos_y[i] + ENEMY_HIGHT / 2 + y - 5.0f;
	Vertex[2].z = 0.0f;
	Vertex[2].u = 0.0f;
	Vertex[2].v = 1.0f;

	Vertex[3].x = pos_x[i] + ENEMY_WIDTH / 2 + x - 10.0f;
	Vertex[3].y = pos_y[i] + ENEMY_HIGHT / 2 + y - 5.0f;
	Vertex[3].z = 0.0f;
	Vertex[3].u = 1.0f;
	Vertex[3].v = 1.0f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag[i] == false ? C_Game_Manager::color : 0,
		damage_flag[i] == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag[i] == false ? C_Game_Manager::color : 0,
		damage_flag[i] == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag[i] == false ? C_Game_Manager::color : 0,
		damage_flag[i] == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag[i] == false ? C_Game_Manager::color : 0,
		damage_flag[i] == false ? C_Game_Manager::color : 0, C_Game_Manager::color);

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


void C_Enemy2_1::HPGageDraw(int i, float x, float y, int damage, LPDIRECT3DDEVICE9 dev, LPDIRECT3DTEXTURE9 tex)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

									//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = pos_x[i] - ENEMY_WIDTH / 2 + x + 10.0f;//280
	Vertex[0].y = pos_y[i] - ENEMY_HIGHT + y + 17.0f;
	Vertex[0].z = 0.0f;
	Vertex[0].u = 0.0f;
	Vertex[0].v = 0.0f;

	Vertex[1].x = pos_x[i] + ENEMY_WIDTH / 2 + x - 10.0f - damage;//320
	Vertex[1].y = pos_y[i] - ENEMY_HIGHT + y + 17.0f;
	Vertex[1].z = 0.0f;
	Vertex[1].u = 1.0f;
	Vertex[1].v = 0.0f;

	Vertex[2].x = pos_x[i] - ENEMY_WIDTH / 2 + x + 10.0f;
	Vertex[2].y = pos_y[i] - ENEMY_HIGHT + y + 25.0f;
	Vertex[2].z = 0.0f;
	Vertex[2].u = 0.0f;
	Vertex[2].v = 1.0f;

	Vertex[3].x = pos_x[i] + ENEMY_WIDTH / 2 + x - 10.0f - damage;
	Vertex[3].y = pos_y[i] - ENEMY_HIGHT + y + 25.0f;
	Vertex[3].z = 0.0f;
	Vertex[3].u = 1.0f;
	Vertex[3].v = 1.0f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color);

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


void C_Enemy2_1::ShadowDraw(int i, float x, float y, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

									//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = pos_x[i] - ENEMY_WIDTH / 2 - 3.0f + x;
	Vertex[0].y = pos_y[i] - ENEMY_HIGHT + 40.0f + y;
	Vertex[0].z = 0.0f;
	Vertex[0].u = 0.0f;
	Vertex[0].v = 0.0f;

	Vertex[1].x = pos_x[i] + ENEMY_WIDTH / 2 - 3.0f + x;
	Vertex[1].y = pos_y[i] - ENEMY_HIGHT + 40.0f + y;
	Vertex[1].z = 0.0f;
	Vertex[1].u = 1.0f;
	Vertex[1].v = 0.0f;

	Vertex[2].x = pos_x[i] - ENEMY_WIDTH / 2 - 3.0f + x;
	Vertex[2].y = pos_y[i] - ENEMY_HIGHT + 80.0f + y;
	Vertex[2].z = 0.0f;
	Vertex[2].u = 0.0f;
	Vertex[2].v = 1.0f;

	Vertex[3].x = pos_x[i] + ENEMY_WIDTH / 2 - 3.0f + x;
	Vertex[3].y = pos_y[i] - ENEMY_HIGHT + 80.0f + y;
	Vertex[3].z = 0.0f;
	Vertex[3].u = 1.0f;
	Vertex[3].v = 1.0f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color);

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