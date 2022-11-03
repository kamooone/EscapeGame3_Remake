//=============================================================================
//
// �G�l�~�[�����N���X [C_Enemy2_1.h]
//
//=============================================================================

#pragma once
#include "Main.h"
#include "C_Game_Manager.h"


#define ENEMY_MAX2_1 4

#define ENEMY1_1_INIT_POS_X2_1 600.0f
#define ENEMY1_1_INIT_POS_Y2_1 500.0f

#define ENEMY1_2_INIT_POS_X2_1 500.0f
#define ENEMY1_2_INIT_POS_Y2_1 180.0f

#define ENEMY1_3_INIT_POS_X2_1 100.0f
#define ENEMY1_3_INIT_POS_Y2_1 200.0f

#define ENEMY1_4_INIT_POS_X2_1 250.0f
#define ENEMY1_4_INIT_POS_Y2_1 260.0f

#define ENEMY_WIDTH 60
#define ENEMY_HIGHT 50

class C_Enemy2_1:C_Monster {
private:
	static float pos_x[ENEMY_MAX2_1];
	static float pos_y[ENEMY_MAX2_1];

	//�G�l�~�[�A�j���[�V����
	unsigned int animtblidx_Enemy[ENEMY_MAX2_1] = { 0 };
	int animtime_Enemy[ENEMY_MAX2_1] = { 0 };
	unsigned int uvtblidx_Enemy[ENEMY_MAX2_1];

	//�����A�j���[�V����
	unsigned int animtblidx_Explosion[ENEMY_MAX2_1] = { 0 };
	int animtime_Explosion[ENEMY_MAX2_1] = { 0 };
	unsigned int uvtblidx_Explosion[ENEMY_MAX2_1];

	//�G�l�~�[�[�̌����Ă��������\��
	static int direction_no_enemy[ENEMY_MAX2_1];

	//�G�l�~�[�̐������
	static int enemy_state[ENEMY_MAX2_1];

	//�G�l�~�[��_���[�W��
	static int damage[ENEMY_MAX2_1];

	//�G�l�~�[�_���[�W�t���O
	static bool damage_flag[ENEMY_MAX2_1];

	//��d�����h�~�̂���
	bool double_check[ENEMY_MAX2_1];

	//�G�l�~�[�Ǐ]
	bool tuizyuu_flag[ENEMY_MAX2_1];

protected:

public:
	C_Enemy2_1() {};
	~C_Enemy2_1() {};

	//CEnemyProcess
	void Init(LPDIRECT3DDEVICE9);  //������
	void UnInit();                 //���
	void UpdateProcess();                 //InputProcess
	void MoveTuizyu(int);
	void TuizyuRight(int, float, float, float, float);
	void TuizyuLeft(int, float, float, float, float);
	void TuizyuUp(int, float, float, float, float);
	void TuizyuDown(int, float, float, float, float);
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
		for (int i = 0; i < ENEMY_MAX2_1; i++)
		{
			enemy_state[i] = 0;
			damage[i] = 0;
			C_Enemy2_1::pos_x[0] =  ENEMY1_1_INIT_POS_X2_1;
			C_Enemy2_1::pos_y[0] =  ENEMY1_1_INIT_POS_Y2_1;

			C_Enemy2_1::pos_x[1] = ENEMY1_2_INIT_POS_X2_1;
			C_Enemy2_1::pos_y[1] = ENEMY1_2_INIT_POS_Y2_1;

			C_Enemy2_1::pos_x[2] = ENEMY1_3_INIT_POS_X2_1;
			C_Enemy2_1::pos_y[2] = ENEMY1_3_INIT_POS_Y2_1;

			C_Enemy2_1::pos_x[3] = ENEMY1_4_INIT_POS_X2_1;
			C_Enemy2_1::pos_y[3] = ENEMY1_4_INIT_POS_Y2_1;
		}
	}
};