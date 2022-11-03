//=============================================================================
//
// 弾描画処理 [BulletDrawutil.cpp]
//
//=============================================================================

#include "C_Bullet.h"
#include "Drawutil.h"


void C_Bullet::BulletDraw(int i, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// 頂点座標

	//rhwを１にする
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = (float)pos_x[i] - BULLET_WIDTH / 2;
	Vertex[0].y = (float)pos_y[i] - BULLET_HIGHT / 2;
	Vertex[0].z = 0.0f;
	Vertex[0].u = 0.8f;
	Vertex[0].v = 0.0f;

	Vertex[1].x = (float)pos_x[i] + BULLET_WIDTH / 2;
	Vertex[1].y = (float)pos_y[i] - BULLET_HIGHT / 2;
	Vertex[1].z = 0.0f;
	Vertex[1].u = 1.0f;
	Vertex[1].v = 0.0f;

	Vertex[2].x = (float)pos_x[i] - BULLET_WIDTH / 2;
	Vertex[2].y = (float)pos_y[i] + BULLET_HIGHT / 2;
	Vertex[2].z = 0.0f;
	Vertex[2].u = 0.8f;
	Vertex[2].v = 0.2f;

	Vertex[3].x = (float)pos_x[i] + BULLET_WIDTH / 2;
	Vertex[3].y = (float)pos_y[i] + BULLET_HIGHT / 2;
	Vertex[3].z = 0.0f;
	Vertex[3].u = 1.0f;
	Vertex[3].v = 0.2f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color, C_Game_Manager::color);

	// 頂点フォーマット指定
	dev->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	// テクスチャをセット
	dev->SetTexture(0, t_bullet);

	dev->DrawPrimitiveUP(
		D3DPT_TRIANGLESTRIP,
		2,
		Vertex,
		sizeof(VERTEX_2DTEX));
}