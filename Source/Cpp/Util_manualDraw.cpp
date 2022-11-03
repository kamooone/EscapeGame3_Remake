//=============================================================================
//
// マニュアル画面描画処理 [Util_manualDraw.cpp]
//
//=============================================================================

#include "C_Manual.h"
#include "Drawutil.h"


void C_Manual::Manual_Draw(LPDIRECT3DDEVICE9 dev, LPDIRECT3DTEXTURE9 tex)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = 100.0f;
	Vertex[0].y = 100.0f;
	Vertex[0].z = -1.0f;
	Vertex[0].u = 0.0f;
	Vertex[0].v = 0.0f;

	Vertex[1].x = 500.0f;
	Vertex[1].y = 100.0f;
	Vertex[1].z = -1.0f;
	Vertex[1].u = 1.0f;
	Vertex[1].v = 0.0f;

	Vertex[2].x = 100.0f;
	Vertex[2].y = 300.0f;
	Vertex[2].z = -1.0f;
	Vertex[2].u = 0.0f;
	Vertex[2].v = 1.0;

	Vertex[3].x = 500.0f;
	Vertex[3].y = 300.0f;
	Vertex[3].z = -1.0f;
	Vertex[3].u = 1.0f;
	Vertex[3].v = 1.0f;

	Vertex[0].col = D3DCOLOR_RGBA(manual_color, manual_color, manual_color, manual_color);
	Vertex[1].col = D3DCOLOR_RGBA(manual_color, manual_color, manual_color, manual_color);
	Vertex[2].col = D3DCOLOR_RGBA(manual_color, manual_color, manual_color, manual_color);
	Vertex[3].col = D3DCOLOR_RGBA(manual_color, manual_color, manual_color, manual_color);

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


void C_Manual::Operator_Draw(LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = 0.0f;
	Vertex[0].y = 0.0f;
	Vertex[0].z = -1.0f;
	Vertex[0].u = 0.0f;
	Vertex[0].v = 0.0f;

	Vertex[1].x = 550.0f;
	Vertex[1].y = 0.0f;
	Vertex[1].z = -1.0f;
	Vertex[1].u = 1.0f;
	Vertex[1].v = 0.0f;

	Vertex[2].x = 0.0f;
	Vertex[2].y = 400.0f;
	Vertex[2].z = -1.0f;
	Vertex[2].u = 0.0f;
	Vertex[2].v = 1.0;

	Vertex[3].x = 550.0f;
	Vertex[3].y = 400.0f;
	Vertex[3].z = -1.0f;
	Vertex[3].u = 1.0f;
	Vertex[3].v = 1.0f;

	Vertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Vertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Vertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Vertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

	// 頂点フォーマット指定
	dev->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	// テクスチャをセット
	dev->SetTexture(0, t_operator);

	dev->DrawPrimitiveUP(
		D3DPT_TRIANGLESTRIP,
		2,
		Vertex,
		sizeof(VERTEX_2DTEX));
}