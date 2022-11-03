//=============================================================================
//
// 床描画処理 [Util2_3Ground.cpp]
//
//=============================================================================

#include "C_Field2_3.h"
#include "Drawutil.h"


void C_Field2_3::Ground1Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i;
	Vertex[0].y = j;
	Vertex[0].z = 1.0f;
	Vertex[0].u = 0.0f;
	Vertex[0].v = 0.5f;

	Vertex[1].x = i + 20.0f;
	Vertex[1].y = j;
	Vertex[1].z = 1.0f;
	Vertex[1].u = 0.04f;
	Vertex[1].v = 0.5f;

	Vertex[2].x = i;
	Vertex[2].y = j + 20.0f;
	Vertex[2].z = 1.0f;
	Vertex[2].u = 0.0f;
	Vertex[2].v = 0.5625f;

	Vertex[3].x = i + 20.0f;
	Vertex[3].y = j + 20.0f;
	Vertex[3].z = 1.0f;
	Vertex[3].u = 0.04f;
	Vertex[3].v = 0.5625f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color);

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


void C_Field2_3::Ground2Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i;
	Vertex[0].y = j;
	Vertex[0].z = 1.0f;
	Vertex[0].u = 0.043f;
	Vertex[0].v = 0.25f;

	Vertex[1].x = i + 20.0f;
	Vertex[1].y = j;
	Vertex[1].z = 1.0f;
	Vertex[1].u = 0.083f;
	Vertex[1].v = 0.25f;

	Vertex[2].x = i;
	Vertex[2].y = j + 20.0f;
	Vertex[2].z = 1.0f;
	Vertex[2].u = 0.043f;
	Vertex[2].v = 0.3125f;

	Vertex[3].x = i + 20.0f;
	Vertex[3].y = j + 20.0f;
	Vertex[3].z = 1.0f;
	Vertex[3].u = 0.083f;
	Vertex[3].v = 0.3125f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color);

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


void C_Field2_3::Ground3Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i;
	Vertex[0].y = j;
	Vertex[0].z = 1.0f;
	Vertex[0].u = 0.16f;
	Vertex[0].v = 0.0625f;

	Vertex[1].x = i + 20.0f;
	Vertex[1].y = j;
	Vertex[1].z = 1.0f;
	Vertex[1].u = 0.25f;
	Vertex[1].v = 0.0625f;

	Vertex[2].x = i;
	Vertex[2].y = j + 20.0f;
	Vertex[2].z = 1.0f;
	Vertex[2].u = 0.16f;
	Vertex[2].v = 0.25f;

	Vertex[3].x = i + 20.0f;
	Vertex[3].y = j + 40.0f;
	Vertex[3].z = 1.0f;
	Vertex[3].u = 0.25f;
	Vertex[3].v = 0.25f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color);

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


void C_Field2_3::Guardrail1Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i;
	Vertex[0].y = j;
	Vertex[0].z = 1.0f;
	Vertex[0].u = 0.96f;
	Vertex[0].v = 0.5f;

	Vertex[1].x = i + 20.0f;
	Vertex[1].y = j;
	Vertex[1].z = 1.0f;
	Vertex[1].u = 1.0f;
	Vertex[1].v = 0.5f;

	Vertex[2].x = i;
	Vertex[2].y = j + 20.0f;
	Vertex[2].z = 1.0f;
	Vertex[2].u = 0.96f;
	Vertex[2].v = 0.5625f;

	Vertex[3].x = i + 20.0f;
	Vertex[3].y = j + 20.0f;
	Vertex[3].z = 1.0f;
	Vertex[3].u = 1.0f;
	Vertex[3].v = 0.5625f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color);

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


void C_Field2_3::Guardrail2Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i;
	Vertex[0].y = j;
	Vertex[0].z = 1.0f;
	Vertex[0].u = 0.92f;
	Vertex[0].v = 0.5f;

	Vertex[1].x = i + 20.0f;
	Vertex[1].y = j;
	Vertex[1].z = 1.0f;
	Vertex[1].u = 0.96f;
	Vertex[1].v = 0.5f;

	Vertex[2].x = i;
	Vertex[2].y = j + 20.0f;
	Vertex[2].z = 1.0f;
	Vertex[2].u = 0.92f;
	Vertex[2].v = 0.5625f;

	Vertex[3].x = i + 20.0f;
	Vertex[3].y = j + 20.0f;
	Vertex[3].z = 1.0f;
	Vertex[3].u = 0.96f;
	Vertex[3].v = 0.5625f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color);

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


void C_Field2_3::River1Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i;
	Vertex[0].y = j;
	Vertex[0].z = 1.0f;
	Vertex[0].u = 0.0f;
	Vertex[0].v = 0.4375f;

	Vertex[1].x = i + 20.0f;
	Vertex[1].y = j;
	Vertex[1].z = 1.0f;
	Vertex[1].u = 0.04f;
	Vertex[1].v = 0.4375f;

	Vertex[2].x = i;
	Vertex[2].y = j + 20.0f;
	Vertex[2].z = 1.0f;
	Vertex[2].u = 0.0f;
	Vertex[2].v = 0.5f;

	Vertex[3].x = i + 20.0f;
	Vertex[3].y = j + 20.0f;
	Vertex[3].z = 1.0f;
	Vertex[3].u = 0.04f;
	Vertex[3].v = 0.5f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color);

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