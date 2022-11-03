//=============================================================================
//
// �G�l�~�[�����N���X [C_Enemy.h]
//
//=============================================================================

#pragma once
#include "Main.h"
#include "C_Game_Manager.h"


#define ENEMY_MAX1 6

#define ENEMY1_1_INIT_POS_X 600.0f
#define ENEMY1_1_INIT_POS_Y 200.0f

#define ENEMY1_2_INIT_POS_X 500.0f
#define ENEMY1_2_INIT_POS_Y 180.0f

#define ENEMY1_3_INIT_POS_X 200.0f
#define ENEMY1_3_INIT_POS_Y 400.0f

#define ENEMY1_4_INIT_POS_X 400.0f
#define ENEMY1_4_INIT_POS_Y 160.0f

#define ENEMY1_5_INIT_POS_X 650.0f
#define ENEMY1_5_INIT_POS_Y 450.0f

#define ENEMY1_6_INIT_POS_X 300.0f
#define ENEMY1_6_INIT_POS_Y 400.0f

#define ENEMY_WIDTH 60
#define ENEMY_HIGHT 50

class C_Enemy:C_Monster {
private:
	static float pos_x[ENEMY_MAX1];
	static float pos_y[ENEMY_MAX1];

	//�G�l�~�[�A�j���[�V����
	unsigned int animtblidx_ENEMY[ENEMY_MAX1];
	int animtime_ENEMY[ENEMY_MAX1];
	unsigned int uvtblidx_ENEMY[ENEMY_MAX1];

	//�����A�j���[�V����
	unsigned int animtblidx_Explosion[ENEMY_MAX1];
	int animtime_Explosion[ENEMY_MAX1];
	unsigned int uvtblidx_Explosion[ENEMY_MAX1];

	//�G�l�~�[�[�̌����Ă��������\��
	static int direction_no_enemy[ENEMY_MAX1];
	
	//�G�l�~�[�̐������
	static int enemy_state[ENEMY_MAX1];
	
	//�G�l�~�[��_���[�W��
	static int damage[ENEMY_MAX1];

	//�G�l�~�[�_���[�W�t���O
	static bool damage_flag[ENEMY_MAX1];

	//��d�����h�~�̂���
	bool double_check[ENEMY_MAX1];

protected:

public:
	C_Enemy() {};
	~C_Enemy() {};

	//CEnemyProcess
	void Init(LPDIRECT3DDEVICE9);  //������
	void UnInit();                 //���
	
	void UpdateProcess();                 //InputProcess
	void MoveDown(int);
	void MoveUp(int);
	void MoveLeft(int);
	void MoveRight(int);
	void Damage_Effect();

	void DrawProcess(LPDIRECT3DDEVICE9);	 //drawutil�Ăяo��
	void Enemy_Animation(LPDIRECT3DDEVICE9);
	void Explosion_Animation(LPDIRECT3DDEVICE9);
	void EnemyDraw(int, float, float, float tu[], float tv[], LPDIRECT3DDEVICE9, LPDIRECT3DTEXTURE9);
	void AppleDraw(int, float, float, LPDIRECT3DDEVICE9, LPDIRECT3DTEXTURE9);
	void ShadowDraw(int, float, float, LPDIRECT3DDEVICE9);

	void HPGageDraw(int i, float x, float y, int damage, LPDIRECT3DDEVICE9 dev, LPDIRECT3DTEXTURE9 tex);



	//�G�l�~�[���W�擾
	static float* Get_enemy_Pos_x() { return pos_x; }
	static float* Get_enemy_Pos_y() { return pos_y; }

	//�G�l�~�[�̌������擾
	static int* Get_Direction() { return direction_no_enemy; }


	//�G�l�~�[�̏�Ԕ���i�[&�擾
	static void Store_Enemy_State(int store_state[6])
	{
		for (int i = 0; i<6; i++)
		{
			enemy_state[i] = store_state[i];
		}
	}
	static int* Get_enemy_State() { return enemy_state; }


	//�G�l�~�[��_���[�W���i�[&�擾
	static void Store_Enemy_Damage(int store_damage[6])
	{
		for (int i = 0; i<6; i++)
		{
			damage[i] = store_damage[i];
		}
	}
	static int* Get_enemy_Damage() { return damage; }


	//�G�l�~�[�_���[�W�t���O�i�[&�擾
	static void Store_Enemy_Damage_Flag(bool store_damage_flag[6])
	{
		for (int i = 0; i<6; i++)
		{
			damage_flag[i] = store_damage_flag[i];
		}
	}
	static bool* Get_enemy_Damage_Flag() { return damage_flag; }


	//�X�e�[�W�ړ��ŃG�l�~�[����
	void Enemy_Resurrection()
	{
		for (int i = 0; i < ENEMY_MAX1; i++)
		{
			enemy_state[i] = 0;
			damage[i] = 0;

			C_Enemy::pos_x[0] = ENEMY1_1_INIT_POS_X;
			C_Enemy::pos_y[0] = ENEMY1_1_INIT_POS_Y;

			C_Enemy::pos_x[1] = ENEMY1_2_INIT_POS_X;
			C_Enemy::pos_y[1] = ENEMY1_2_INIT_POS_Y;

			C_Enemy::pos_x[2] = ENEMY1_3_INIT_POS_X;
			C_Enemy::pos_y[2] = ENEMY1_3_INIT_POS_Y;

			C_Enemy::pos_x[3] = ENEMY1_4_INIT_POS_X;
			C_Enemy::pos_y[3] = ENEMY1_4_INIT_POS_Y;

			C_Enemy::pos_x[4] = ENEMY1_5_INIT_POS_X;
			C_Enemy::pos_y[4] = ENEMY1_5_INIT_POS_Y;

			C_Enemy::pos_x[5] = ENEMY1_6_INIT_POS_X;
			C_Enemy::pos_y[5] = ENEMY1_6_INIT_POS_Y;
		}
	}
};