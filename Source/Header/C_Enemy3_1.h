//=============================================================================
//
// �G�l�~�[�����N���X [C_Enemy3_1.h]
//
//=============================================================================

#pragma once
#include "Main.h"
#include "C_Game_Manager.h"


#define ENEMY_MAX3_1 17

#define ENEMY2_1_INIT_POS_X3_1 100.0f
#define ENEMY2_1_INIT_POS_Y3_1 200.0f

#define ENEMY2_2_INIT_POS_X3_1 240.0f
#define ENEMY2_2_INIT_POS_Y3_1 350.0f

#define ENEMY2_3_INIT_POS_X3_1 300.0f
#define ENEMY2_3_INIT_POS_Y3_1 600.0f

#define ENEMY2_4_INIT_POS_X3_1 700.0f
#define ENEMY2_4_INIT_POS_Y3_1 700.0f

#define ENEMY2_5_INIT_POS_X3_1 700.0f
#define ENEMY2_5_INIT_POS_Y3_1 900.0f

#define ENEMY2_6_INIT_POS_X3_1 500.0f
#define ENEMY2_6_INIT_POS_Y3_1 850.0f

#define ENEMY2_7_INIT_POS_X3_1 400.0f
#define ENEMY2_7_INIT_POS_Y3_1 820.0f

#define ENEMY2_8_INIT_POS_X3_1 900.0f
#define ENEMY2_8_INIT_POS_Y3_1 600.0f

#define ENEMY2_9_INIT_POS_X3_1 150.0f
#define ENEMY2_9_INIT_POS_Y3_1 600.0f

#define ENEMY2_10_INIT_POS_X3_1 750.0f
#define ENEMY2_10_INIT_POS_Y3_1 600.0f

#define ENEMY2_11_INIT_POS_X3_1 1050.0f
#define ENEMY2_11_INIT_POS_Y3_1 600.0f

#define ENEMY2_12_INIT_POS_X3_1 440.0f
#define ENEMY2_12_INIT_POS_Y3_1 350.0f

#define ENEMY2_13_INIT_POS_X3_1 750.0f
#define ENEMY2_13_INIT_POS_Y3_1 350.0f

#define ENEMY2_14_INIT_POS_X3_1 1050.0f
#define ENEMY2_14_INIT_POS_Y3_1 160.0f

#define ENEMY2_15_INIT_POS_X3_1 500.0f
#define ENEMY2_15_INIT_POS_Y3_1 150.0f


#define ENEMY2_16_INIT_POS_X3_1 700.0f
#define ENEMY2_16_INIT_POS_Y3_1 150.0f

#define ENEMY2_17_INIT_POS_X3_1 900.0f
#define ENEMY2_17_INIT_POS_Y3_1 160.0f

#define ENEMY_WIDTH 60
#define ENEMY_HIGHT 50



class C_Enemy3_1 :C_Monster {
private:
	static float pos_x[ENEMY_MAX3_1];
	static float pos_y[ENEMY_MAX3_1];

	//�G�l�~�[�A�j���[�V����
	unsigned int animtblidx_Enemy[ENEMY_MAX3_1] = { 0 };
	int animtime_Enemy[ENEMY_MAX3_1] = { 0 };
	unsigned int uvtblidx_Enemy[ENEMY_MAX3_1];

	//�����A�j���[�V����
	unsigned int animtblidx_Explosion[ENEMY_MAX3_1] = { 0 };
	int animtime_Explosion[ENEMY_MAX3_1] = { 0 };
	unsigned int uvtblidx_Explosion[ENEMY_MAX3_1];

	//�G�l�~�[�[�̌����Ă��������\��
	static int direction_no_enemy[ENEMY_MAX3_1];

	//�G�l�~�[�̐������
	static int enemy_state[ENEMY_MAX3_1];

	//�G�l�~�[��_���[�W��
	static int damage[ENEMY_MAX3_1];

	//�G�l�~�[�_���[�W�t���O
	static bool damage_flag[ENEMY_MAX3_1];

	bool double_check[ENEMY_MAX3_1] = { false };

	//�G�l�~�[�Ǐ]
	bool tuizyuu_flag[ENEMY_MAX3_1];

protected:

public:
	C_Enemy3_1()
	{	};
	~C_Enemy3_1() {};
	//Cplayer
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
	static void Store_Enemy_State(int store_state[ENEMY_MAX3_1])
	{
		for (int i = 0; i<ENEMY_MAX3_1; i++)
		{
			enemy_state[i] = store_state[i];
		}
	}
	static int* Get_enemy_State() { return enemy_state; }

	//�G�l�~�[��_���[�W���i�[&�擾
	static void Store_Enemy_Damage(int store_damage[ENEMY_MAX3_1])
	{
		for (int i = 0; i<ENEMY_MAX3_1; i++)
		{
			damage[i] = store_damage[i];
		}
	}
	static int* Get_enemy_Damage() { return damage; }

	//�G�l�~�[�_���[�W�t���O�i�[&�擾
	static void Store_Enemy_Damage_Flag(bool store_damage_flag[ENEMY_MAX3_1])
	{
		for (int i = 0; i<ENEMY_MAX3_1; i++)
		{
			damage_flag[i] = store_damage_flag[i];
		}
	}
	static bool* Get_enemy_Damage_Flag() { return damage_flag; }

	//�X�e�[�W�ړ��ŃG�l�~�[����
	void Enemy_Resurrection()
	{
		for (int i = 0; i < ENEMY_MAX3_1; i++)
		{
			enemy_state[i] = 0;
			damage[i] = 0;
		}

		C_Enemy3_1::pos_x[0] = ENEMY2_1_INIT_POS_X3_1;
		C_Enemy3_1::pos_x[1] = ENEMY2_2_INIT_POS_X3_1;
		C_Enemy3_1::pos_x[2] = ENEMY2_3_INIT_POS_X3_1;
		C_Enemy3_1::pos_x[3] = ENEMY2_4_INIT_POS_X3_1;
		C_Enemy3_1::pos_x[4] = ENEMY2_5_INIT_POS_X3_1;
		C_Enemy3_1::pos_x[5] = ENEMY2_6_INIT_POS_X3_1;
		C_Enemy3_1::pos_x[6] = ENEMY2_7_INIT_POS_X3_1;
		C_Enemy3_1::pos_x[7] = ENEMY2_8_INIT_POS_X3_1;
		C_Enemy3_1::pos_x[8] = ENEMY2_9_INIT_POS_X3_1;
		C_Enemy3_1::pos_x[9] = ENEMY2_10_INIT_POS_X3_1;
		C_Enemy3_1::pos_x[10] = ENEMY2_11_INIT_POS_X3_1;
		C_Enemy3_1::pos_x[11] = ENEMY2_12_INIT_POS_X3_1;
		C_Enemy3_1::pos_x[12] = ENEMY2_13_INIT_POS_X3_1;
		C_Enemy3_1::pos_x[13] = ENEMY2_14_INIT_POS_X3_1;
		C_Enemy3_1::pos_x[14] = ENEMY2_15_INIT_POS_X3_1;
		C_Enemy3_1::pos_x[15] = ENEMY2_16_INIT_POS_X3_1;
		C_Enemy3_1::pos_x[16] = ENEMY2_17_INIT_POS_X3_1;


		C_Enemy3_1::pos_y[0] = ENEMY2_1_INIT_POS_Y3_1;
		C_Enemy3_1::pos_y[1] = ENEMY2_2_INIT_POS_Y3_1;
		C_Enemy3_1::pos_y[2] = ENEMY2_3_INIT_POS_Y3_1;
		C_Enemy3_1::pos_y[3] = ENEMY2_4_INIT_POS_Y3_1;
		C_Enemy3_1::pos_y[4] = ENEMY2_5_INIT_POS_Y3_1;
		C_Enemy3_1::pos_y[5] = ENEMY2_6_INIT_POS_Y3_1;
		C_Enemy3_1::pos_y[6] = ENEMY2_7_INIT_POS_Y3_1;
		C_Enemy3_1::pos_y[7] = ENEMY2_8_INIT_POS_Y3_1;
		C_Enemy3_1::pos_y[8] = ENEMY2_9_INIT_POS_Y3_1;
		C_Enemy3_1::pos_y[9] = ENEMY2_10_INIT_POS_Y3_1;
		C_Enemy3_1::pos_y[10] = ENEMY2_11_INIT_POS_Y3_1;
		C_Enemy3_1::pos_y[11] = ENEMY2_12_INIT_POS_Y3_1;
		C_Enemy3_1::pos_y[12] = ENEMY2_13_INIT_POS_Y3_1;
		C_Enemy3_1::pos_y[13] = ENEMY2_14_INIT_POS_Y3_1;
		C_Enemy3_1::pos_y[14] = ENEMY2_15_INIT_POS_Y3_1;
		C_Enemy3_1::pos_y[15] = ENEMY2_16_INIT_POS_Y3_1;
		C_Enemy3_1::pos_y[16] = ENEMY2_17_INIT_POS_Y3_1;
	}
};