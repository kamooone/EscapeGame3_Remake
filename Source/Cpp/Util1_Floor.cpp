//=============================================================================
//
// 床描画処理 [Util1_Floor.cpp]
//
//=============================================================================

#include "C_Room.h"
#include "Drawutil.h"


void C_Room::Floor1Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i;
	Vertex[0].y = j;
	Vertex[0].z = 1.0f;
	Vertex[0].u = 0.36f;
	Vertex[0].v = 0.0f;

	Vertex[1].x = i + 20.0f;
	Vertex[1].y = j;
	Vertex[1].z = 1.0f;
	Vertex[1].u = 0.40f;
	Vertex[1].v = 0.0f;

	Vertex[2].x = i;
	Vertex[2].y = j + 20.0f;
	Vertex[2].z = 1.0f;
	Vertex[2].u = 0.36f;
	Vertex[2].v = 0.064f;

	Vertex[3].x = i + 20.0f;
	Vertex[3].y = j + 20.0f;
	Vertex[3].z = 1.0f;
	Vertex[3].u = 0.40f;
	Vertex[3].v = 0.064f;

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


void C_Room::Floor2Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i - 10.0f;
	Vertex[0].y = j - 20.0f;
	Vertex[0].z = 1.00f;
	Vertex[0].u = 0.28f;
	Vertex[0].v = 0.0f;

	Vertex[1].x = i + 20.0f;
	Vertex[1].y = j - 20.0f;
	Vertex[1].z = 1.0f;
	Vertex[1].u = 0.32f;
	Vertex[1].v = 0.0f;

	Vertex[2].x = i - 10.0f;
	Vertex[2].y = j + 20.0f;
	Vertex[2].z = 1.0f;
	Vertex[2].u = 0.28f;
	Vertex[2].v = 0.064f;

	Vertex[3].x = i + 20.0f;
	Vertex[3].y = j + 20.0f;
	Vertex[3].z = 1.0f;
	Vertex[3].u = 0.32f;
	Vertex[3].v = 0.064f;

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


void C_Room::Floor3Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i - 0.0f;
	Vertex[0].y = j - 20.0f;
	Vertex[0].z = 1.0f;
	Vertex[0].u = 0.28f;
	Vertex[0].v = 0.0f;

	Vertex[1].x = i + 30.0f;
	Vertex[1].y = j - 20.0f;
	Vertex[1].z = 1.0f;
	Vertex[1].u = 0.32f;
	Vertex[1].v = 0.0f;

	Vertex[2].x = i - 0.0f;
	Vertex[2].y = j + 20.0f;
	Vertex[2].z = 1.0f;
	Vertex[2].u = 0.28f;
	Vertex[2].v = 0.064f;

	Vertex[3].x = i + 30.0f;
	Vertex[3].y = j + 20.0f;
	Vertex[3].z = 1.0f;
	Vertex[3].u = 0.32f;
	Vertex[3].v = 0.064f;

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


void C_Room::Floor4Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i;
	Vertex[0].y = j;
	Vertex[0].z = -1.0f;
	Vertex[0].u = 0.04f;
	Vertex[0].v = 0.315f;

	Vertex[1].x = i + 160.0f;
	Vertex[1].y = j;
	Vertex[1].z = -1.0f;
	Vertex[1].u = 0.16f;
	Vertex[1].v = 0.315f;

	Vertex[2].x = i;
	Vertex[2].y = j + 160.0f;
	Vertex[2].z = -1.0f;
	Vertex[2].u = 0.04f;
	Vertex[2].v = 0.5f;

	Vertex[3].x = i + 160.0f;
	Vertex[3].y = j + 160.0f;
	Vertex[3].z = -1.0f;
	Vertex[3].u = 0.16f;
	Vertex[3].v = 0.5f;

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


void C_Room::Stairs1Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

    //rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i;
	Vertex[0].y = j;
	Vertex[0].z = -1.0f;
	Vertex[0].u = 0.52f;
	Vertex[0].v = 0.128f;

	Vertex[1].x = i + 50.0f;
	Vertex[1].y = j;
	Vertex[1].z = -1.0f;
	Vertex[1].u = 0.6f;
	Vertex[1].v = 0.128f;

	Vertex[2].x = i;
	Vertex[2].y = j + 100.0f;
	Vertex[2].z = -1.0f;
	Vertex[2].u = 0.52f;
	Vertex[2].v = 0.3f;

	Vertex[3].x = i + 50.0f;
	Vertex[3].y = j + 100.0f;
	Vertex[3].z = -1.0f;
	Vertex[3].u = 0.6f;
	Vertex[3].v = 0.3f;

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


void C_Room::Stairs2Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i + 50.0f;
	Vertex[0].y = j;
	Vertex[0].z = -1.0f;
	Vertex[0].u = 0.52f;
	Vertex[0].v = 0.128f;

	Vertex[1].x = i + 50.0f + 50.0f;
	Vertex[1].y = j;
	Vertex[1].z = -1.0f;
	Vertex[1].u = 0.6f;
	Vertex[1].v = 0.128f;

	Vertex[2].x = i + 50.0f;
	Vertex[2].y = j + 100.0f;
	Vertex[2].z = -1.0f;
	Vertex[2].u = 0.52f;
	Vertex[2].v = 0.3f;

	Vertex[3].x = i + 50.0f + 50.0f;
	Vertex[3].y = j + 100.0f;
	Vertex[3].z = -1.0f;
	Vertex[3].u = 0.6f;
	Vertex[3].v = 0.3f;

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