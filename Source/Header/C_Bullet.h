//=============================================================================
//
// �v���C���[�e�����N���X [C_Bullet.h]
//
//=============================================================================

#pragma once
#include "Main.h"
#include "C_Game_Manager.h"

#define BULLET_MAX 30
#define BULLET_WIDTH 60
#define BULLET_HIGHT 50

class C_Bullet : public C_Mapchip{
private:
	//�e�N�X�`��
	LPDIRECT3DTEXTURE9	 t_bullet;

	bool fire_trigger;//�v���C���[���e���˂������ǂ���
	bool bullet_fire[BULLET_MAX];  //�e�e�̔��˒����ۂ�
	float pos_x[BULLET_MAX];
	float pos_y[BULLET_MAX];
	int bullet_direction[BULLET_MAX];

protected:

public:
	C_Bullet()
	{
		for (int i=0;i<BULLET_MAX;i++)
		{
			bullet_fire[i] = false;
		}
	};
	~C_Bullet() {};
	
	//CBullet
	void Init(LPDIRECT3DDEVICE9);  //������
	void UnInit();                 //���
	void UpdateProcess();                 //InputProcess
	void DrawProcess(LPDIRECT3DDEVICE9);	 //drawutil�Ăяo��
	
	void BulletPos();
	void BulletMove();

	void BulletCollision();
	void BulletBossCollision();


	void BulletDraw(int, LPDIRECT3DDEVICE9);
};