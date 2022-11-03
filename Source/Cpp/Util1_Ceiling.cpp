//=============================================================================
//
// 天井描画処理 [Util1_Ceiling.cpp]
//
//=============================================================================

#include "C_Room.h"
#include "Drawutil.h"



void C_Room::Brack1Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i;
	Vertex[0].y = j;
	Vertex[0].z = .0f;
	Vertex[0].u = 0.08f;
	Vertex[0].v = 0.8f;

	Vertex[1].x = i + 20.0f;
	Vertex[1].y = j;
	Vertex[1].z = 0.0f;
	Vertex[1].u = 0.08f;
	Vertex[1].v = 0.8f;

	Vertex[2].x = i;
	Vertex[2].y = j + 30.0f;
	Vertex[2].z = 0.0f;
	Vertex[2].u = 0.08f;
	Vertex[2].v = 0.8f;

	Vertex[3].x = i + 20.0f;
	Vertex[3].y = j + 30.0f;
	Vertex[3].z = 0.0f;
	Vertex[3].u = 0.08f;
	Vertex[3].v = 0.8f;

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


void C_Room::Ceiling1Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i;
	Vertex[0].y = j;
	Vertex[0].z = 0.00f;
	Vertex[0].u = 0.25f;
	Vertex[0].v = 0.08f;

	Vertex[1].x = i + 10.0f;
	Vertex[1].y = j;
	Vertex[1].z = 0.0f;
	Vertex[1].u = 0.27f;
	Vertex[1].v = 0.08f;

	Vertex[2].x = i;
	Vertex[2].y = j + 580.0f;
	Vertex[2].z = 0.0f;
	Vertex[2].u = 0.25f;
	Vertex[2].v = 0.09f;

	Vertex[3].x = i + 10.0f;
	Vertex[3].y = j + 580.0f;
	Vertex[3].z = 0.0f;
	Vertex[3].u = 0.27f;
	Vertex[3].v = 0.09f;

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


void C_Room::Ceiling2Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i - 10.0f;
	Vertex[0].y = j;
	Vertex[0].z = 1.0f;
	Vertex[0].u = 0.25f;
	Vertex[0].v = 0.08f;

	Vertex[1].x = i + 30.0f;
	Vertex[1].y = j;
	Vertex[1].z = 1.0f;
	Vertex[1].u = 0.26f;
	Vertex[1].v = 0.08f;

	Vertex[2].x = i - 10.0f;
	Vertex[2].y = j + 10.0f;
	Vertex[2].z = 1.0f;
	Vertex[2].u = 0.25f;
	Vertex[2].v = 0.09f;

	Vertex[3].x = i + 30.0f;
	Vertex[3].y = j + 10.0f;
	Vertex[3].z = 1.0f;
	Vertex[3].u = 0.26f;
	Vertex[3].v = 0.09f;

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


void C_Room::Ceiling3Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

    //rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i + 10.0f;
	Vertex[0].y = j;
	Vertex[0].z = 0.00f;
	Vertex[0].u = 0.25f;
	Vertex[0].v = 0.08f;

	Vertex[1].x = i + 20.0f;
	Vertex[1].y = j;
	Vertex[1].z = 0.0f;
	Vertex[1].u = 0.26f;
	Vertex[1].v = 0.08f;

	Vertex[2].x = i + 10.0f;
	Vertex[2].y = j + 480.0f;
	Vertex[2].z = 0.0f;
	Vertex[2].u = 0.25f;
	Vertex[2].v = 0.09f;

	Vertex[3].x = i + 20.0f;
	Vertex[3].y = j + 480.0f;
	Vertex[3].z = 0.0f;
	Vertex[3].u = 0.26f;
	Vertex[3].v = 0.09f;

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


void C_Room::Ceiling4Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

    //rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i + 10.0f;
	Vertex[0].y = j;
	Vertex[0].z = -1.0f;
	Vertex[0].u = 0.25f;
	Vertex[0].v = 0.08f;

	Vertex[1].x = i + 20.0f;
	Vertex[1].y = j;
	Vertex[1].z = -1.0f;
	Vertex[1].u = 0.26f;
	Vertex[1].v = 0.08f;

	Vertex[2].x = i + 10.0f;
	Vertex[2].y = j + 40.0f;
	Vertex[2].z = -1.0f;
	Vertex[2].u = 0.25f;
	Vertex[2].v = 0.09f;

	Vertex[3].x = i + 20.0f;
	Vertex[3].y = j + 40.0f;
	Vertex[3].z = -1.0f;
	Vertex[3].u = 0.26f;
	Vertex[3].v = 0.09f;

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


void C_Room::Ceiling5Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i - 0.0f;
	Vertex[0].y = j;
	Vertex[0].z = 1.0f;
	Vertex[0].u = 0.56f;
	Vertex[0].v = 0.5f;

	Vertex[1].x = i + 20.0f;
	Vertex[1].y = j;
	Vertex[1].z = 1.0f;
	Vertex[1].u = 0.60f;
	Vertex[1].v = 0.5f;

	Vertex[2].x = i - 0.0f;
	Vertex[2].y = j + 20.0f;
	Vertex[2].z = 1.0f;
	Vertex[2].u = 0.56f;
	Vertex[2].v = 0.565f;

	Vertex[3].x = i + 20.0f;
	Vertex[3].y = j + 20.0f;
	Vertex[3].z = 1.0f;
	Vertex[3].u = 0.60f;
	Vertex[3].v = 0.565f;

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


void C_Room::Ceiling6Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i;
	Vertex[0].y = j;
	Vertex[0].z = 0.00f;
	Vertex[0].u = 0.25f;
	Vertex[0].v = 0.08f;

	Vertex[1].x = i + 10.0f;
	Vertex[1].y = j;
	Vertex[1].z = 0.0f;
	Vertex[1].u = 0.27f;
	Vertex[1].v = 0.08f;

	Vertex[2].x = i;
	Vertex[2].y = j + 30.0f;
	Vertex[2].z = 0.0f;
	Vertex[2].u = 0.25f;
	Vertex[2].v = 0.09f;

	Vertex[3].x = i + 10.0f;
	Vertex[3].y = j + 30.0f;
	Vertex[3].z = 0.0f;
	Vertex[3].u = 0.27f;
	Vertex[3].v = 0.09f;

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


void C_Room::Ceiling7Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i + 10.0f;
	Vertex[0].y = j;
	Vertex[0].z = 0.00f;
	Vertex[0].u = 0.25f;
	Vertex[0].v = 0.08f;

	Vertex[1].x = i + 20.0f;
	Vertex[1].y = j;
	Vertex[1].z = 0.0f;
	Vertex[1].u = 0.26f;
	Vertex[1].v = 0.08f;

	Vertex[2].x = i + 10.0f;
	Vertex[2].y = j + 30.0f;
	Vertex[2].z = 0.0f;
	Vertex[2].u = 0.25f;
	Vertex[2].v = 0.09f;

	Vertex[3].x = i + 20.0f;
	Vertex[3].y = j + 30.0f;
	Vertex[3].z = 0.0f;
	Vertex[3].u = 0.26f;
	Vertex[3].v = 0.09f;

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


void C_Room::Ceiling8Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i - 0.0f;
	Vertex[0].y = j + 10.0f;
	Vertex[0].z = 0.00f;
	Vertex[0].u = 0.25f;
	Vertex[0].v = 0.08f;

	Vertex[1].x = i + 20.0f;
	Vertex[1].y = j + 10.0f;
	Vertex[1].z = 0.0f;
	Vertex[1].u = 0.26f;
	Vertex[1].v = 0.08f;

	Vertex[2].x = i - 0.0f;
	Vertex[2].y = j + 20.0f;
	Vertex[2].z = 0.0f;
	Vertex[2].u = 0.25f;
	Vertex[2].v = 0.09f;

	Vertex[3].x = i + 20.0f;
	Vertex[3].y = j + 20.0f;
	Vertex[3].z = 0.0f;
	Vertex[3].u = 0.26f;
	Vertex[3].v = 0.09f;

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