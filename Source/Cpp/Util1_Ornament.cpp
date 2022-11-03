//=============================================================================
//
// �I�u�W�F�N�g�`�揈�� [Util1_Ornament.cpp]
//
//=============================================================================

#include "C_Room.h"
#include "Drawutil.h"


void C_Room::Ornament1Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// ���_���W

	//rhw���P�ɂ���
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i - 0.0f;
	Vertex[0].y = j - 0.0f;
	Vertex[0].z = -1.0f;
	Vertex[0].u = 0.88f;
	Vertex[0].v = 0.88f;

	Vertex[1].x = i + 40.0f;
	Vertex[1].y = j - 0.0f;
	Vertex[1].z = -1.0f;
	Vertex[1].u = 0.92f;
	Vertex[1].v = 0.88f;

	Vertex[2].x = i - 0.0f;
	Vertex[2].y = j + 80.0f;
	Vertex[2].z = -1.0f;
	Vertex[2].u = 0.88f;
	Vertex[2].v = 1.0f;

	Vertex[3].x = i + 40.0f;
	Vertex[3].y = j + 80.0f;
	Vertex[3].z = -1.0f;
	Vertex[3].u = 0.92f;
	Vertex[3].v = 1.0f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);

	// ���_�t�H�[�}�b�g�w��
	dev->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	// �e�N�X�`�����Z�b�g
	dev->SetTexture(0, t_mapchip);

	dev->DrawPrimitiveUP(
		D3DPT_TRIANGLESTRIP,
		2,
		Vertex,
		sizeof(VERTEX_2DTEX));
}


void C_Room::Ornament2Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// ���_���W

	//rhw���P�ɂ���
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i - 0.0f;
	Vertex[0].y = j - 0.0f;
	Vertex[0].z = -1.0f;
	Vertex[0].u = 0.92f;
	Vertex[0].v = 0.88f;

	Vertex[1].x = i + 40.0f;
	Vertex[1].y = j - 0.0f;
	Vertex[1].z = -1.0f;
	Vertex[1].u = 0.96f;
	Vertex[1].v = 0.88f;

	Vertex[2].x = i - 0.0f;
	Vertex[2].y = j + 80.0f;
	Vertex[2].z = -1.0f;
	Vertex[2].u = 0.92f;
	Vertex[2].v = 1.0f;

	Vertex[3].x = i + 40.0f;
	Vertex[3].y = j + 80.0f;
	Vertex[3].z = -1.0f;
	Vertex[3].u = 0.96f;
	Vertex[3].v = 1.0f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);

	// ���_�t�H�[�}�b�g�w��
	dev->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	// �e�N�X�`�����Z�b�g
	dev->SetTexture(0, t_mapchip);

	dev->DrawPrimitiveUP(
		D3DPT_TRIANGLESTRIP,
		2,
		Vertex,
		sizeof(VERTEX_2DTEX));
}


void C_Room::Ornament3Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// ���_���W

	//rhw���P�ɂ���
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i - 0.0f;
	Vertex[0].y = j - 0.0f;
	Vertex[0].z = -1.0f;
	Vertex[0].u = 0.96f;
	Vertex[0].v = 0.88f;

	Vertex[1].x = i + 40.0f;
	Vertex[1].y = j - 0.0f;
	Vertex[1].z = -1.0f;
	Vertex[1].u = 1.0f;
	Vertex[1].v = 0.88f;

	Vertex[2].x = i - 0.0f;
	Vertex[2].y = j + 80.0f;
	Vertex[2].z = -1.0f;
	Vertex[2].u = 0.96f;
	Vertex[2].v = 1.0f;

	Vertex[3].x = i + 40.0f;
	Vertex[3].y = j + 80.0f;
	Vertex[3].z = -1.0f;
	Vertex[3].u = 1.0f;
	Vertex[3].v = 1.0f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);

	// ���_�t�H�[�}�b�g�w��
	dev->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	// �e�N�X�`�����Z�b�g
	dev->SetTexture(0, t_mapchip);

	dev->DrawPrimitiveUP(
		D3DPT_TRIANGLESTRIP,
		2,
		Vertex,
		sizeof(VERTEX_2DTEX));
}



void C_Room::Desk1Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// ���_���W

	//rhw���P�ɂ���
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i - 0.0f;
	Vertex[0].y = j - 0.0f;
	Vertex[0].z = -1.0f;
	Vertex[0].u = 0.88f;
	Vertex[0].v = 0.65f;

	Vertex[1].x = i + 40.0f;
	Vertex[1].y = j - 0.0f;
	Vertex[1].z = -1.0f;
	Vertex[1].u = 0.92f;
	Vertex[1].v = 0.65f;

	Vertex[2].x = i - 0.0f;
	Vertex[2].y = j + 60.0f;
	Vertex[2].z = -1.0f;
	Vertex[2].u = 0.88f;
	Vertex[2].v = 0.75f;

	Vertex[3].x = i + 40.0f;
	Vertex[3].y = j + 60.0f;
	Vertex[3].z = -1.0f;
	Vertex[3].u = 0.92f;
	Vertex[3].v = 0.75f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);

	// ���_�t�H�[�}�b�g�w��
	dev->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	// �e�N�X�`�����Z�b�g
	dev->SetTexture(0, t_mapchip);

	dev->DrawPrimitiveUP(
		D3DPT_TRIANGLESTRIP,
		2,
		Vertex,
		sizeof(VERTEX_2DTEX));
}



void C_Room::Chair1Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// ���_���W

    //rhw���P�ɂ���
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i - 0.0f;
	Vertex[0].y = j - 0.0f;
	Vertex[0].z = -1.0f;
	Vertex[0].u = 0.92f;
	Vertex[0].v = 0.69f;

	Vertex[1].x = i + 40.0f;
	Vertex[1].y = j - 0.0f;
	Vertex[1].z = -1.0f;
	Vertex[1].u = 0.96f;
	Vertex[1].v = 0.69f;

	Vertex[2].x = i - 0.0f;
	Vertex[2].y = j + 40.0f;
	Vertex[2].z = -1.0f;
	Vertex[2].u = 0.92f;
	Vertex[2].v = 0.75f;

	Vertex[3].x = i + 40.0f;
	Vertex[3].y = j + 40.0f;
	Vertex[3].z = -1.0f;
	Vertex[3].u = 0.96f;
	Vertex[3].v = 0.75f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);

	// ���_�t�H�[�}�b�g�w��
	dev->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	// �e�N�X�`�����Z�b�g
	dev->SetTexture(0, t_mapchip);

	dev->DrawPrimitiveUP(
		D3DPT_TRIANGLESTRIP,
		2,
		Vertex,
		sizeof(VERTEX_2DTEX));
}


void C_Room::Chair2Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// ���_���W

	//rhw���P�ɂ���
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i + 0.0f;
	Vertex[0].y = j - 0.0f;
	Vertex[0].z = -1.0f;
	Vertex[0].u = 0.93f;
	Vertex[0].v = 0.6f;

	Vertex[1].x = i + 40.0f;
	Vertex[1].y = j - 0.0f;
	Vertex[1].z = -1.0f;
	Vertex[1].u = 0.96f;
	Vertex[1].v = 0.6f;

	Vertex[2].x = i + 0.0f;
	Vertex[2].y = j + 40.0f;
	Vertex[2].z = -1.0f;
	Vertex[2].u = 0.93f;
	Vertex[2].v = 0.69f;

	Vertex[3].x = i + 40.0f;
	Vertex[3].y = j + 40.0f;
	Vertex[3].z = -1.0f;
	Vertex[3].u = 0.96f;
	Vertex[3].v = 0.69f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);

	// ���_�t�H�[�}�b�g�w��
	dev->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	// �e�N�X�`�����Z�b�g
	dev->SetTexture(0, t_mapchip);

	dev->DrawPrimitiveUP(
		D3DPT_TRIANGLESTRIP,
		2,
		Vertex,
		sizeof(VERTEX_2DTEX));
}



void C_Room::Chair3Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// ���_���W

	//rhw���P�ɂ���
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i + 0.0f;
	Vertex[0].y = j - 0.0f;
	Vertex[0].z = -1.0f;
	Vertex[0].u = 0.96f;
	Vertex[0].v = 0.69f;

	Vertex[1].x = i + 40.0f;
	Vertex[1].y = j - 0.0f;
	Vertex[1].z = -1.0f;
	Vertex[1].u = 1.0f;
	Vertex[1].v = 0.69f;

	Vertex[2].x = i + 0.0f;
	Vertex[2].y = j + 40.0f;
	Vertex[2].z = -1.0f;
	Vertex[2].u = 0.96f;
	Vertex[2].v = 0.75f;

	Vertex[3].x = i + 40.0f;
	Vertex[3].y = j + 40.0f;
	Vertex[3].z = -1.0f;
	Vertex[3].u = 1.0f;
	Vertex[3].v = 0.75f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);

	// ���_�t�H�[�}�b�g�w��
	dev->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	// �e�N�X�`�����Z�b�g
	dev->SetTexture(0, t_mapchip);

	dev->DrawPrimitiveUP(
		D3DPT_TRIANGLESTRIP,
		2,
		Vertex,
		sizeof(VERTEX_2DTEX));
}


void C_Room::Chair4Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// ���_���W

    //rhw���P�ɂ���
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i + 0.0f;
	Vertex[0].y = j - 0.0f;
	Vertex[0].z = -1.0f;
	Vertex[0].u = 0.96f;
	Vertex[0].v = 0.6f;

	Vertex[1].x = i + 40.0f;
	Vertex[1].y = j - 0.0f;
	Vertex[1].z = -1.0f;
	Vertex[1].u = 1.0f;
	Vertex[1].v = 0.6f;

	Vertex[2].x = i + 0.0f;
	Vertex[2].y = j + 40.0f;
	Vertex[2].z = -1.0f;
	Vertex[2].u = 0.96f;
	Vertex[2].v = 0.69f;

	Vertex[3].x = i + 40.0f;
	Vertex[3].y = j + 40.0f;
	Vertex[3].z = -1.0f;
	Vertex[3].u = 1.0f;
	Vertex[3].v = 0.69f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);

	// ���_�t�H�[�}�b�g�w��
	dev->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	// �e�N�X�`�����Z�b�g
	dev->SetTexture(0, t_mapchip);

	dev->DrawPrimitiveUP(
		D3DPT_TRIANGLESTRIP,
		2,
		Vertex,
		sizeof(VERTEX_2DTEX));
}


void C_Room::wood1Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// ���_���W

	//rhw���P�ɂ���
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i - 0.0f;
	Vertex[0].y = j - 0.0f;
	Vertex[0].z = -1.0f;
	Vertex[0].u = 0.88f;
	Vertex[0].v = 0.75f;

	Vertex[1].x = i + 40.0f;
	Vertex[1].y = j - 0.0f;
	Vertex[1].z = -1.0f;
	Vertex[1].u = 0.92f;
	Vertex[1].v = 0.75f;

	Vertex[2].x = i - 0.0f;
	Vertex[2].y = j + 80.0f;
	Vertex[2].z = -1.0f;
	Vertex[2].u = 0.88f;
	Vertex[2].v = 0.87f;

	Vertex[3].x = i + 40.0f;
	Vertex[3].y = j + 80.0f;
	Vertex[3].z = -1.0f;
	Vertex[3].u = 0.92f;
	Vertex[3].v = 0.87f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);

	// ���_�t�H�[�}�b�g�w��
	dev->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	// �e�N�X�`�����Z�b�g
	dev->SetTexture(0, t_mapchip);

	dev->DrawPrimitiveUP(
		D3DPT_TRIANGLESTRIP,
		2,
		Vertex,
		sizeof(VERTEX_2DTEX));
}


void C_Room::bed1Draw(float i, float j, LPDIRECT3DDEVICE9 dev)
{
	VERTEX_2DTEX Vertex[4];			// ���_���W

	//rhw���P�ɂ���
	Vertex[0].rhw = Vertex[1].rhw = Vertex[2].rhw = Vertex[3].rhw = 1.0f;

	dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Vertex[0].x = i - 0.0f;
	Vertex[0].y = j - 0.0f;
	Vertex[0].z = -1.0f;
	Vertex[0].u = 0.9625f;
	Vertex[0].v = 0.25f;

	Vertex[1].x = i + 40.0f;
	Vertex[1].y = j - 0.0f;
	Vertex[1].z = -1.0f;
	Vertex[1].u = 1.0f;
	Vertex[1].v = 0.25f;

	Vertex[2].x = i - 0.0f;
	Vertex[2].y = j + 100.0f;
	Vertex[2].z = -1.0f;
	Vertex[2].u = 0.9625f;
	Vertex[2].v = 0.4375f;

	Vertex[3].x = i + 40.0f;
	Vertex[3].y = j + 100.0f;
	Vertex[3].z = -1.0f;
	Vertex[3].u = 1.0f;
	Vertex[3].v = 0.4375f;

	Vertex[0].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[1].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[2].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);
	Vertex[3].col = D3DCOLOR_RGBA(C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color,C_Game_Manager::color);

	// ���_�t�H�[�}�b�g�w��
	dev->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	// �e�N�X�`�����Z�b�g
	dev->SetTexture(0, t_mapchip);

	dev->DrawPrimitiveUP(
		D3DPT_TRIANGLESTRIP,
		2,
		Vertex,
		sizeof(VERTEX_2DTEX));
}