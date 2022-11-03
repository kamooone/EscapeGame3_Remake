//=============================================================================
//
// ボス描画処理 [BossDrawutil.cpp]
//
//=============================================================================

#include "C_Boss.h"
#include "Drawutil.h"


void C_Boss::Boss_LeftDraw(float x, float y, LPDIRECT3DDEVICE9 dev, LPDIRECT3DTEXTURE9 tex)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = pos_x - BOSS_WIDTH / 2 + x;
	Vertex[0].y = pos_y - BOSS_HIGHT / 2 + y;
	Vertex[0].z = 0.0f;
	Vertex[0].u = 0.69f;
	Vertex[0].v = 0.0f;
	
	Vertex[1].x = pos_x + BOSS_WIDTH / 4 + 30.0f + x;
	Vertex[1].y = pos_y - BOSS_HIGHT / 2 + y;
	Vertex[1].z = 0.0f;
	Vertex[1].u = 0.85f;
	Vertex[1].v = 0.0f;
	
	Vertex[2].x = pos_x - BOSS_WIDTH / 2 + x;
	Vertex[2].y = pos_y + BOSS_HIGHT + y;
	Vertex[2].z = 0.0f;
	Vertex[2].u = 0.69f;
	Vertex[2].v = 0.34f;
	
	Vertex[3].x = pos_x + BOSS_WIDTH / 4 + 30.0f + x;
	Vertex[3].y = pos_y + BOSS_HIGHT + y;
	Vertex[3].z = 0.0f;
	Vertex[3].u = 0.85f;
	Vertex[3].v = 0.34f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);

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

void C_Boss::Boss_Left1Draw(float x, float y, LPDIRECT3DDEVICE9 dev, LPDIRECT3DTEXTURE9 tex)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = pos_x - BOSS_WIDTH / 2 - 20.0f + x;
	Vertex[0].y = pos_y - BOSS_HIGHT / 2 + 19.0f + y;
	Vertex[0].z = 0.0f;
	Vertex[0].u = 0.25f;
	Vertex[0].v = 0.4f;
	
	Vertex[1].x = pos_x + BOSS_WIDTH / 4 + 25.0f + x;
	Vertex[1].y = pos_y - BOSS_HIGHT / 2 + 19.0f + y;
	Vertex[1].z = 0.0f;
	Vertex[1].u = 0.4f;
	Vertex[1].v = 0.4f;
	
	Vertex[2].x = pos_x - BOSS_WIDTH / 2 - 20.0f + x;
	Vertex[2].y = pos_y + BOSS_HIGHT - 20.0f + y;
	Vertex[2].z = 0.0f;
	Vertex[2].u = 0.25f;
	Vertex[2].v = 0.65f;
	
	Vertex[3].x = pos_x + BOSS_WIDTH / 4 + 25.0f + x;
	Vertex[3].y = pos_y + BOSS_HIGHT - 20.0f + y;
	Vertex[3].z = 0.0f;
	Vertex[3].u = 0.4f;
	Vertex[3].v = 0.65f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);

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

void C_Boss::Boss_Left2Draw(float x, float y, LPDIRECT3DDEVICE9 dev, LPDIRECT3DTEXTURE9 tex)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = pos_x - BOSS_WIDTH / 2 - 10.0f + x;
	Vertex[0].y = pos_y - BOSS_HIGHT / 2 + 18.0f + y;
	Vertex[0].z = 0.0f;
	Vertex[0].u = 0.4f;
	Vertex[0].v = 0.4f;
	
	Vertex[1].x = pos_x + BOSS_WIDTH / 4 + 35.0f + x;
	Vertex[1].y = pos_y - BOSS_HIGHT / 2 + 18.0f + y;
	Vertex[1].z = 0.0f;
	Vertex[1].u = 0.55f;
	Vertex[1].v = 0.4f;
	
	Vertex[2].x = pos_x - BOSS_WIDTH / 2 - 10.0f + x;
	Vertex[2].y = pos_y + BOSS_HIGHT - 17.0f + y;
	Vertex[2].z = 0.0f;
	Vertex[2].u = 0.4f;
	Vertex[2].v = 0.65f;
	
	Vertex[3].x = pos_x + BOSS_WIDTH / 4 + 35.0f + x;
	Vertex[3].y = pos_y + BOSS_HIGHT - 17.0f + y;
	Vertex[3].z = 0.0f;
	Vertex[3].u = 0.55f;
	Vertex[3].v = 0.65f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);

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

void C_Boss::Boss_Left3Draw(float x, float y, LPDIRECT3DDEVICE9 dev, LPDIRECT3DTEXTURE9 tex)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = pos_x - BOSS_WIDTH / 2 + 7.0f + x;
	Vertex[0].y = pos_y - BOSS_HIGHT / 2 + 20.0f + y;
	Vertex[0].z = 0.0f;
	Vertex[0].u = 0.55f;
	Vertex[0].v = 0.4f;
	
	Vertex[1].x = pos_x + BOSS_WIDTH / 4 + 40.0f + x;
	Vertex[1].y = pos_y - BOSS_HIGHT / 2 + 20.0f + y;
	Vertex[1].z = 0.0f;
	Vertex[1].u = 0.7f;
	Vertex[1].v = 0.4f;
	
	Vertex[2].x = pos_x - BOSS_WIDTH / 2 + 7.0f + x;
	Vertex[2].y = pos_y + BOSS_HIGHT - 20.0f + y;
	Vertex[2].z = 0.0f;
	Vertex[2].u = 0.55f;
	Vertex[2].v = 0.65f;
	
	Vertex[3].x = pos_x + BOSS_WIDTH / 4 + 40.0f + x;
	Vertex[3].y = pos_y + BOSS_HIGHT - 20.0f + y;
	Vertex[3].z = 0.0f;
	Vertex[3].u = 0.7f;
	Vertex[3].v = 0.65f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);

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

void C_Boss::Boss_Left4Draw(float x, float y, LPDIRECT3DDEVICE9 dev, LPDIRECT3DTEXTURE9 tex)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = pos_x - BOSS_WIDTH / 2 + 5.0f + x;
	Vertex[0].y = pos_y - BOSS_HIGHT / 2 + 20.0f + y;
	Vertex[0].z = 0.0f;
	Vertex[0].u = 0.68f;
	Vertex[0].v = 0.4f;
	
	Vertex[1].x = pos_x + BOSS_WIDTH / 4 + 8.0f + x;
	Vertex[1].y = pos_y - BOSS_HIGHT / 2 + 20.0f + y;
	Vertex[1].z = 0.0f;
	Vertex[1].u = 0.8f;
	Vertex[1].v = 0.4f;
	
	Vertex[2].x = pos_x - BOSS_WIDTH / 2 + 5.0f + x;
	Vertex[2].y = pos_y + BOSS_HIGHT - 20.0f + y;
	Vertex[2].z = 0.0f;
	Vertex[2].u = 0.68f;
	Vertex[2].v = 0.65f;
	
	Vertex[3].x = pos_x + BOSS_WIDTH / 4 + 8.0f + x;
	Vertex[3].y = pos_y + BOSS_HIGHT - 20.0f + y;
	Vertex[3].z = 0.0f;
	Vertex[3].u = 0.8f;
	Vertex[3].v = 0.65f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);

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

void C_Boss::Boss_Left5Draw(float x, float y, LPDIRECT3DDEVICE9 dev, LPDIRECT3DTEXTURE9 tex)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = pos_x - BOSS_WIDTH / 2 - 10.0f + x;
	Vertex[0].y = pos_y - BOSS_HIGHT / 2 + 20.0f + y;
	Vertex[0].z = 0.0f;
	Vertex[0].u = 0.81f;
	Vertex[0].v = 0.4f;
	
	Vertex[1].x = pos_x + BOSS_WIDTH / 4 + 27.0f + x;
	Vertex[1].y = pos_y - BOSS_HIGHT / 2 + 20.0f + y;
	Vertex[1].z = 0.0f;
	Vertex[1].u = 0.96f;
	Vertex[1].v = 0.4f;
	
	Vertex[2].x = pos_x - BOSS_WIDTH / 2 - 10.0f + x;
	Vertex[2].y = pos_y + BOSS_HIGHT - 20.0f + y;
	Vertex[2].z = 0.0f;
	Vertex[2].u = 0.81f;
	Vertex[2].v = 0.65f;
	
	Vertex[3].x = pos_x + BOSS_WIDTH / 4 + 27.0f + x;
	Vertex[3].y = pos_y + BOSS_HIGHT - 20.0f + y;
	Vertex[3].z = 0.0f;
	Vertex[3].u = 0.96f;
	Vertex[3].v = 0.65f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);

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

void C_Boss::Boss_RightDraw(float x, float y, LPDIRECT3DDEVICE9 dev, LPDIRECT3DTEXTURE9 tex)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = pos_x - 10.0f + x;
	Vertex[0].y = pos_y - BOSS_HIGHT / 4  - 5.0f+ y;
	Vertex[0].z = 0.0f;
	Vertex[0].u = 0.0f;
	Vertex[0].v = 0.78f;
	
	Vertex[1].x = pos_x + BOSS_WIDTH + 0.0f + x;
	Vertex[1].y = pos_y - BOSS_HIGHT / 4 - 5.0f + y;
	Vertex[1].z = 0.0f;
	Vertex[1].u = 0.12f;
	Vertex[1].v = 0.78f;
	
	Vertex[2].x = pos_x - 10.0f + x;
	Vertex[2].y = pos_y + BOSS_HIGHT -30.0f + y;
	Vertex[2].z = 0.0f;
	Vertex[2].u = 0.0f;
	Vertex[2].v = 1.0f;
	
	Vertex[3].x = pos_x + BOSS_WIDTH + 0.0f + x;
	Vertex[3].y = pos_y + BOSS_HIGHT - 30.0f + y;
	Vertex[3].z = 0.0f;
	Vertex[3].u = 0.12f;
	Vertex[3].v = 1.0f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);

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

void C_Boss::Boss_ShieldDraw(float x, float y, LPDIRECT3DDEVICE9 dev, LPDIRECT3DTEXTURE9 tex)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = pos_x + 10.0f + x;
	Vertex[0].y = pos_y - BOSS_HIGHT / 2 + 10.0f + 27.0f + y;
	Vertex[0].z = 0.0f;
	Vertex[0].u = 0.5f;
	Vertex[0].v = 0.78f;
	
	Vertex[1].x = pos_x + BOSS_WIDTH + 10.0f - 10.0f + x;
	Vertex[1].y = pos_y - BOSS_HIGHT / 2 + 10.0f + 27.0f + y;
	Vertex[1].z = 0.0f;
	Vertex[1].u = 0.6f;
	Vertex[1].v = 0.78f;
	
	Vertex[2].x = pos_x + 10.0f + x;
	Vertex[2].y = pos_y + BOSS_HIGHT +20.0f + 10.0f - 30.0f + y;
	Vertex[2].z = 0.0f;
	Vertex[2].u = 0.5f;
	Vertex[2].v = 1.0f;
	
	Vertex[3].x = pos_x + BOSS_WIDTH + 10.0f - 10.0f + x;
	Vertex[3].y = pos_y + BOSS_HIGHT + 20.0f + 10.0f - 30.0f + y;
	Vertex[3].z = 0.0f;
	Vertex[3].u = 0.6f;
	Vertex[3].v = 1.0f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);

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

void C_Boss::Boss_Shield1Draw(float x, float y, LPDIRECT3DDEVICE9 dev, LPDIRECT3DTEXTURE9 tex)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

    Vertex[0].x = pos_x + 10.0f + x;
	Vertex[0].y = pos_y - BOSS_HIGHT / 2 + 10.0f + 27.0f + y;
	Vertex[0].z = 0.0f;
	Vertex[0].u = 0.6f;
	Vertex[0].v = 0.78f;
	
	Vertex[1].x = pos_x + BOSS_WIDTH + 10.0f - 10.0f + x;
	Vertex[1].y = pos_y - BOSS_HIGHT / 2 + 10.0f + 27.0f + y;
	Vertex[1].z = 0.0f;
	Vertex[1].u = 0.7f;
	Vertex[1].v = 0.78f;
	
	Vertex[2].x = pos_x + 10.0f + x;
	Vertex[2].y = pos_y + BOSS_HIGHT +20.0f + 10.0f - 30.0f + y;
	Vertex[2].z = 0.0f;
	Vertex[2].u = 0.6f;
	Vertex[2].v = 1.0f;
	
	Vertex[3].x = pos_x + BOSS_WIDTH + 10.0f - 10.0f + x;
	Vertex[3].y = pos_y + BOSS_HIGHT + 20.0f + 10.0f - 30.0f + y;
	Vertex[3].z = 0.0f;
	Vertex[3].u = 0.7f;
	Vertex[3].v = 1.0f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);

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

void C_Boss::BossDraw(float x, float y, float tu[], float tv[], LPDIRECT3DDEVICE9 dev, LPDIRECT3DTEXTURE9 tex)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = pos_x - BOSS_WIDTH / 2 + x;
	Vertex[0].y = pos_y - BOSS_HIGHT / 2 + y;
	Vertex[0].z = 0.0f;
	Vertex[0].u = tu[0];
	Vertex[0].v = tv[0];

	Vertex[1].x = pos_x + BOSS_WIDTH / 2 + x;
	Vertex[1].y = pos_y - BOSS_HIGHT / 2 + y;
	Vertex[1].z = 0.0f;
	Vertex[1].u = tu[1];
	Vertex[1].v = tv[1];

	Vertex[2].x = pos_x - BOSS_WIDTH / 2 + x;
	Vertex[2].y = pos_y + BOSS_HIGHT / 2 + y;
	Vertex[2].z = 0.0f;
	Vertex[2].u = tu[2];
	Vertex[2].v = tv[2];

	Vertex[3].x = pos_x + BOSS_WIDTH / 2 + x;
	Vertex[3].y = pos_y + BOSS_HIGHT / 2 + y;
	Vertex[3].z = 0.0f;
	Vertex[3].u = tu[3];
	Vertex[3].v = tv[3];

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color, damage_flag == false ? C_Game_Manager::color : 0,
		damage_flag == false ? C_Game_Manager::color : 0, C_Game_Manager::color);

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

void C_Boss::HPGageDraw(float x, float y, int damage, LPDIRECT3DDEVICE9 dev, LPDIRECT3DTEXTURE9 tex)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = pos_x - 90 + x + 20.0f;//120
	Vertex[0].y = pos_y - 130 + y + 90.0f;
	Vertex[0].z = 0.0f;
	Vertex[0].u = 0.0f;
	Vertex[0].v = 0.0f;
	
	Vertex[1].x = pos_x + 90 + x + 60.0f - damage;//340
	Vertex[1].y = pos_y - 130 + y + 90.0f;
	Vertex[1].z = 0.0f;
	Vertex[1].u = 1.0f;
	Vertex[1].v = 0.0f;
	
	Vertex[2].x = pos_x - 90 + x + 20.0f;
	Vertex[2].y = pos_y - 130 + y + 98.0f;
	Vertex[2].z = 0.0f;
	Vertex[2].u = 0.0f;
	Vertex[2].v = 1.0f;
	
	Vertex[3].x = pos_x + 90 + x + 60.0f - damage;
	Vertex[3].y = pos_y - 130 + y + 98.0f;
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

void C_Boss::BossBullet(int i, float x, float y, LPDIRECT3DDEVICE9 dev, LPDIRECT3DTEXTURE9 tex)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = bullet_pos_x[i] + 20.0f + pos_x - 180.0f / 2 +30.0f + x;
	Vertex[0].y = bullet_pos_y[i] + pos_y + 150.0f - 100.0f + y;
	Vertex[0].z = 0.0f;
	Vertex[0].u = 0.04f;
	Vertex[0].v = 0.63f;

	Vertex[1].x = bullet_pos_x[i] + 20.0f + pos_x - 30.0f + x;
	Vertex[1].y = bullet_pos_y[i] + pos_y + 150.0f - 100.0f + y;
	Vertex[1].z = 0.0f;
	Vertex[1].u = 0.13f;
	Vertex[1].v = 0.63f;

	Vertex[2].x = bullet_pos_x[i] + 20.0f + pos_x - 180.0f / 2 + 30.0f + x;
	Vertex[2].y = bullet_pos_y[i] + pos_y + 150.0f - 60.0f + y;
	Vertex[2].z = 0.0f;
	Vertex[2].u = 0.04f;
	Vertex[2].v = 0.75f;

	Vertex[3].x = bullet_pos_x[i] + 20.0f + pos_x - 30.0f + x;
	Vertex[3].y = bullet_pos_y[i] + pos_y + 150.0f - 60.0f + y;
	Vertex[3].z = 0.0f;
	Vertex[3].u = 0.13f;
	Vertex[3].v = 0.75f;

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

void C_Boss::ShadowDraw(float x, float y, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = pos_x - BOSS_WIDTH / 2 + 41.0f + x;
	Vertex[0].y = pos_y - BOSS_HIGHT + 110.0f + y;
	Vertex[0].z = 0.0f;
	Vertex[0].u = 0.0f;
	Vertex[0].v = 0.0f;

	Vertex[1].x = pos_x + BOSS_WIDTH / 2 + 33.0f + x;
	Vertex[1].y = pos_y - BOSS_HIGHT + 110.0f + y;
	Vertex[1].z = 0.0f;
	Vertex[1].u = 1.0f;
	Vertex[1].v = 0.0f;

	Vertex[2].x = pos_x - BOSS_WIDTH / 2 + 41.0f + x;
	Vertex[2].y = pos_y - BOSS_HIGHT + 160.0f + y;
	Vertex[2].z = 0.0f;
	Vertex[2].u = 0.0f;
	Vertex[2].v = 1.0f;

	Vertex[3].x = pos_x + BOSS_WIDTH / 2 + 33.0f + x;
	Vertex[3].y = pos_y - BOSS_HIGHT + 160.0f + y;
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