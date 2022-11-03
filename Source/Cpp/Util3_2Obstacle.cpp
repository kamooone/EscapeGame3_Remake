//=============================================================================
//
// 障害物描画処理 [Util3_2Obstacle.cpp]
//
//=============================================================================

#include "C_Field3_2.h"
#include "Drawutil.h"


void C_Field3_2::Tree1Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i;
	Vertex[0].y = j;
	Vertex[0].z = -1.0f;
	Vertex[0].u = 0.76f;
	Vertex[0].v = 0.75f;

	Vertex[1].x = i + 60.0f;
	Vertex[1].y = j;
	Vertex[1].z = -1.0f;
	Vertex[1].u = 0.92f;
	Vertex[1].v = 0.75f;

	Vertex[2].x = i;
	Vertex[2].y = j + 80.0f;
	Vertex[2].z = -1.0f;
	Vertex[2].u = 0.76f;
	Vertex[2].v = 1.0f;

	Vertex[3].x = i + 60.0f;
	Vertex[3].y = j + 80.0f;
	Vertex[3].z = -1.0f;
	Vertex[3].u = 0.92f;
	Vertex[3].v = 1.0f;

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


void C_Field3_2::TosenboDraw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i;
	Vertex[0].y = j - 60.0f;
	Vertex[0].z = -1.0f;
	Vertex[0].u = 0.76f;
	Vertex[0].v = 0.75f;

	Vertex[1].x = i + 80.0f;
	Vertex[1].y = j - 60.0f;
	Vertex[1].z = -1.0f;
	Vertex[1].u = 0.92f;
	Vertex[1].v = 0.75f;

	Vertex[2].x = i;
	Vertex[2].y = j + 20.0f;
	Vertex[2].z = -1.0f;
	Vertex[2].u = 0.76f;
	Vertex[2].v = 1.0f;

	Vertex[3].x = i + 80.0f;
	Vertex[3].y = j + 20.0f;
	Vertex[3].z = -1.0f;
	Vertex[3].u = 0.92f;
	Vertex[3].v = 1.0f;

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