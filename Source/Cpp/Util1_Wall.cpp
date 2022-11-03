//=============================================================================
//
// 壁描画処理 [Util1_Wall.cpp]
//
//=============================================================================

#include "C_Room.h"
#include "Drawutil.h"


void C_Room::Wall1Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i - 10.0f;
	Vertex[0].y = j - 10.0f;
	Vertex[0].z = 0.00f;
	Vertex[0].u = 0.28f;
	Vertex[0].v = 0.31f;

	Vertex[1].x = i + 150.0f;
	Vertex[1].y = j - 10.0f;
	Vertex[1].z = 0.0f;
	Vertex[1].u = 0.40f;
	Vertex[1].v = 0.31f;

	Vertex[2].x = i - 10.0f;
	Vertex[2].y = j + 100.0f;
	Vertex[2].z = 0.0f;
	Vertex[2].u = 0.28f;
	Vertex[2].v = 0.512f;

	Vertex[3].x = i + 150.0f;
	Vertex[3].y = j + 100.0f;
	Vertex[3].z = 0.0f;
	Vertex[3].u = 0.40f;
	Vertex[3].v = 0.512f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);

	// 頂点フォーマット指定
	dev->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	// テクスチャをセット
	dev->SetTexture(0, t_mapchip);

	dev->DrawPrimitiveUP(
		D3DPT_TRIANGLESTRIP,
		2,
		Vertex,
		sizeof(VERTEX_2DTEX));
}


void C_Room::Wall2Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i - 10.0f + 160.0f;
	Vertex[0].y = j - 10.f;
	Vertex[0].z = 0.00f;
	Vertex[0].u = 0.28f;
	Vertex[0].v = 0.311f;

	Vertex[1].x = i + 160.0f + 160.0f;
	Vertex[1].y = j - 10.0f;
	Vertex[1].z = 0.0f;
	Vertex[1].u = 0.40f;
	Vertex[1].v = 0.311f;

	Vertex[2].x = i - 10.0f + 160.0f;
	Vertex[2].y = j + 100.0f;
	Vertex[2].z = 0.0f;
	Vertex[2].u = 0.28f;
	Vertex[2].v = 0.512f;

	Vertex[3].x = i + 160.0f + 160.0f;
	Vertex[3].y = j + 100.0f;
	Vertex[3].z = 0.0f;
	Vertex[3].u = 0.40f;
	Vertex[3].v = 0.512f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);

	// 頂点フォーマット指定
	dev->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	// テクスチャをセット
	dev->SetTexture(0, t_mapchip);

	dev->DrawPrimitiveUP(
		D3DPT_TRIANGLESTRIP,
		2,
		Vertex,
		sizeof(VERTEX_2DTEX));
}


void C_Room::Wall3Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i - 10.0f + 160.0f + 160.0f;
	Vertex[0].y = j - 10.f;
	Vertex[0].z = 0.00f;
	Vertex[0].u = 0.28f;
	Vertex[0].v = 0.512f;

	Vertex[1].x = i + 160.0f + 160.0f + 160.0f;
	Vertex[1].y = j - 10.0f;
	Vertex[1].z = 0.0f;
	Vertex[1].u = 0.52f;
	Vertex[1].v = 0.512f;

	Vertex[2].x = i - 10.0f + 160.0f + 160.0f;
	Vertex[2].y = j + 100.0f;
	Vertex[2].z = 0.0f;
	Vertex[2].u = 0.28f;
	Vertex[2].v = 0.704f;

	Vertex[3].x = i + 160.0f + 160.0f + 160.0f;
	Vertex[3].y = j + 100.0f;
	Vertex[3].z = 0.0f;
	Vertex[3].u = 0.52f;
	Vertex[3].v = 0.704f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);

	// 頂点フォーマット指定
	dev->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	// テクスチャをセット
	dev->SetTexture(0, t_mapchip);

	dev->DrawPrimitiveUP(
		D3DPT_TRIANGLESTRIP,
		2,
		Vertex,
		sizeof(VERTEX_2DTEX));
}


void C_Room::Wall33Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i - 10.0f + 160.0f + 160.0f;
	Vertex[0].y = j - 10.f;
	Vertex[0].z = 0.00f;
	Vertex[0].u = 0.0f;
	Vertex[0].v = 0.32f;

	Vertex[1].x = i + 160.0f + 160.0f + 160.0f;
	Vertex[1].y = j - 10.0f;
	Vertex[1].z = 0.0f;
	Vertex[1].u = 0.04f;
	Vertex[1].v = 0.32f;

	Vertex[2].x = i - 10.0f + 160.0f + 160.0f;
	Vertex[2].y = j + 100.0f;
	Vertex[2].z = 0.0f;
	Vertex[2].u = 0.0f;
	Vertex[2].v = 0.384f;

	Vertex[3].x = i + 160.0f + 160.0f + 160.0f;
	Vertex[3].y = j + 100.0f;
	Vertex[3].z = 0.0f;
	Vertex[3].u = 0.04f;
	Vertex[3].v = 0.384f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);

	// 頂点フォーマット指定
	dev->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	// テクスチャをセット
	dev->SetTexture(0, t_mapchip);

	dev->DrawPrimitiveUP(
		D3DPT_TRIANGLESTRIP,
		2,
		Vertex,
		sizeof(VERTEX_2DTEX));
}


void C_Room::Wall4Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i;
	Vertex[0].y = j - 10.0f;
	Vertex[0].z = 0.00f;
	Vertex[0].u = 0.76f;
	Vertex[0].v = 0.448f;

	Vertex[1].x = i + 250.0f;
	Vertex[1].y = j - 10.0f;
	Vertex[1].z = 0.0f;
	Vertex[1].u = 1.0f;
	Vertex[1].v = 0.448f;

	Vertex[2].x = i;
	Vertex[2].y = j + 100.0f;
	Vertex[2].z = 0.0f;
	Vertex[2].u = 0.76f;
	Vertex[2].v = 0.59f;

	Vertex[3].x = i + 250.0f;
	Vertex[3].y = j + 100.0f;
	Vertex[3].z = 0.0f;
	Vertex[3].u = 1.0f;
	Vertex[3].v = 0.59f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);

	// 頂点フォーマット指定
	dev->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	// テクスチャをセット
	dev->SetTexture(0, t_mapchip);

	dev->DrawPrimitiveUP(
		D3DPT_TRIANGLESTRIP,
		2,
		Vertex,
		sizeof(VERTEX_2DTEX));
}


void C_Room::Wall5Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i - 0.0f;
	Vertex[0].y = j - 10.0f;
	Vertex[0].z = 0.00f;
	Vertex[0].u = 0.28f;
	Vertex[0].v = 0.31f;

	Vertex[1].x = i + 125.0f;
	Vertex[1].y = j - 10.0f;
	Vertex[1].z = 0.0f;
	Vertex[1].u = 0.40f;
	Vertex[1].v = 0.31f;

	Vertex[2].x = i - 0.0f;
	Vertex[2].y = j + 100.0f;
	Vertex[2].z = 0.0f;
	Vertex[2].u = 0.28f;
	Vertex[2].v = 0.512f;

	Vertex[3].x = i + 125.0f;
	Vertex[3].y = j + 100.0f;
	Vertex[3].z = 0.0f;
	Vertex[3].u = 0.40f;
	Vertex[3].v = 0.512f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);

	// 頂点フォーマット指定
	dev->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	// テクスチャをセット
	dev->SetTexture(0, t_mapchip);

	dev->DrawPrimitiveUP(
		D3DPT_TRIANGLESTRIP,
		2,
		Vertex,
		sizeof(VERTEX_2DTEX));
}


void C_Room::Wall6Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i - 0.0f + 125.0f;
	Vertex[0].y = j - 10.0f;
	Vertex[0].z = 0.00f;
	Vertex[0].u = 0.28f;
	Vertex[0].v = 0.31f;

	Vertex[1].x = i + 125.0f + 125.0f;
	Vertex[1].y = j - 10.0f;
	Vertex[1].z = 0.0f;
	Vertex[1].u = 0.40f;
	Vertex[1].v = 0.31f;

	Vertex[2].x = i - 0.0f + 125.0f;
	Vertex[2].y = j + 100.0f;
	Vertex[2].z = 0.0f;
	Vertex[2].u = 0.28f;
	Vertex[2].v = 0.512f;

	Vertex[3].x = i + 125.0f + 125.0f;
	Vertex[3].y = j + 100.0f;
	Vertex[3].z = 0.0f;
	Vertex[3].u = 0.40f;
	Vertex[3].v = 0.512f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);

	// 頂点フォーマット指定
	dev->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	// テクスチャをセット
	dev->SetTexture(0, t_mapchip);

	dev->DrawPrimitiveUP(
		D3DPT_TRIANGLESTRIP,
		2,
		Vertex,
		sizeof(VERTEX_2DTEX));
}


void C_Room::Pillar1Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i;
	Vertex[0].y = j;
	Vertex[0].z = 0.00f;
	Vertex[0].u = 0.28f;
	Vertex[0].v = 0.5f;

	Vertex[1].x = i + 40.0f;
	Vertex[1].y = j;
	Vertex[1].z = 0.0f;
	Vertex[1].u = 0.32f;
	Vertex[1].v = 0.5f;

	Vertex[2].x = i;
	Vertex[2].y = j + 120.0f;
	Vertex[2].z = 0.0f;
	Vertex[2].u = 0.28f;
	Vertex[2].v = 0.69f;

	Vertex[3].x = i + 40.0f;
	Vertex[3].y = j + 120.0f;
	Vertex[3].z = 0.0f;
	Vertex[3].u = 0.32f;
	Vertex[3].v = 0.69f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);

	// 頂点フォーマット指定
	dev->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	// テクスチャをセット
	dev->SetTexture(0, t_mapchip);

	dev->DrawPrimitiveUP(
		D3DPT_TRIANGLESTRIP,
		2,
		Vertex,
		sizeof(VERTEX_2DTEX));
}