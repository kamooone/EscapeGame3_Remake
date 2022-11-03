//=============================================================================
//
// タイトル画面描画処理 [Util_TitleDraw.cpp]
//
//=============================================================================

#include "C_Title.h"
#include "C_Clear.h"
#include "Drawutil.h"


void C_Title::TitleDraw(LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = 0.0f;
	Vertex[0].y = 0.0f;
	Vertex[0].z = 0.0f;
	Vertex[0].u = 0.0f;
	Vertex[0].v = 0.0f;

	Vertex[1].x = 600.0f;
	Vertex[1].y = 0.0f;
	Vertex[1].z = 0.0f;
	Vertex[1].u = 1.0f;
	Vertex[1].v = 0.0f;

	Vertex[2].x = 0.0f;
	Vertex[2].y = 400.0f;
	Vertex[2].z = 0.0f;
	Vertex[2].u = 0.0f;
	Vertex[2].v = 1.0f;

	Vertex[3].x = 600.0f;
	Vertex[3].y = 400.0f;
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
	dev->SetTexture(0, t_title);

	dev->DrawPrimitiveUP(
		D3DPT_TRIANGLESTRIP,
		2,
		Vertex,
		sizeof(VERTEX_2DTEX));
}


void C_Title::TitleDraw1(LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = 0.0f;
	Vertex[0].y = 0.0f;
	Vertex[0].z = 0.0f;
	Vertex[0].u = 0.0f;
	Vertex[0].v = 0.0f;

	Vertex[1].x = 600.0f;
	Vertex[1].y = 0.0f;
	Vertex[1].z = 0.0f;
	Vertex[1].u = 1.0f;
	Vertex[1].v = 0.0f;

	Vertex[2].x = 0.0f;
	Vertex[2].y = 300.0f;
	Vertex[2].z = 0.0f;
	Vertex[2].u = 0.0f;
	Vertex[2].v = 1.0f;

	Vertex[3].x = 600.0f;
	Vertex[3].y = 300.0f;
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
	dev->SetTexture(0, t_title1);

	dev->DrawPrimitiveUP(
		D3DPT_TRIANGLESTRIP,
		2,
		Vertex,
		sizeof(VERTEX_2DTEX));
}


void C_Title::TitleDraw2(LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = 100.0f;
	Vertex[0].y = 250.0f;
	Vertex[0].z = 0.0f;
	Vertex[0].u = 0.0f;
	Vertex[0].v = 0.0f;

	Vertex[1].x = 500.0f;
	Vertex[1].y = 250.0f;
	Vertex[1].z = 0.0f;
	Vertex[1].u = 1.0f;
	Vertex[1].v = 0.0f;

	Vertex[2].x = 100.0f;
	Vertex[2].y = 400.0f;
	Vertex[2].z = 0.0f;
	Vertex[2].u = 0.0f;
	Vertex[2].v = 1.0f;

	Vertex[3].x = 500.0f;
	Vertex[3].y = 400.0f;
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
	dev->SetTexture(0, t_title2);

	dev->DrawPrimitiveUP(
		D3DPT_TRIANGLESTRIP,
		2,
		Vertex,
		sizeof(VERTEX_2DTEX));
}


void C_Clear::ClearDraw(LPDIRECT3DDEVICE9 dev, LPDIRECT3DTEXTURE9 tex)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = 0.0f;
	Vertex[0].y = 0.0f;
	Vertex[0].z = 0.0f;
	Vertex[0].u = 0.0f;
	Vertex[0].v = 0.0f;

	Vertex[1].x = 600.0f;
	Vertex[1].y = 0.0f;
	Vertex[1].z = 0.0f;
	Vertex[1].u = 1.0f;
	Vertex[1].v = 0.0f;

	Vertex[2].x = 0.0f;
	Vertex[2].y = 400.0f;
	Vertex[2].z = 0.0f;
	Vertex[2].u = 0.0f;
	Vertex[2].v = 1.0f;

	Vertex[3].x = 600.0f;
	Vertex[3].y = 400.0f;
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