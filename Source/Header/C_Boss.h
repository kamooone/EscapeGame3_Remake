//=============================================================================
//
// �{�X�����N���X [C_Boss.h]
//
//=============================================================================

#pragma once
#include "Main.h"
#include "C_Game_Manager.h"

#define BOSS_INIT_POS_X 200.0f
#define BOSS_INIT_POS_Y 250.0f

#define BOSS_WIDTH 120
#define BOSS_HIGHT 100

#define BOSSBULLET_MAX 10


enum boss_state_no {
	USUALLY = 0,//�ʏ펞
	DESTROY     //����
};

class C_Boss : public C_Monster{
private:
	LPDIRECT3DTEXTURE9	 t_boss;
	static float pos_x;
	static float pos_y;

	//�{�X�_���[�W�����̉�
	static int damage;

	//�{�X�_���[�W�t���O
	static bool damage_flag;

	//�{�X�̐�����ԕϐ������̉�
	static int boss_state;

	float bullet_pos_x[BOSSBULLET_MAX];
	float bullet_pos_y[BOSSBULLET_MAX];

	int bullet_motion_no = 1;//�e���˃��[�V�����ԍ�

	int bullet_cnt = 0;//�ő�10���̒e�ԍ�

	int boss_bullet_fire[BOSSBULLET_MAX];//�e���ˑO�A���˒��A����

	bool atack = true;//�U���\���ǂ���
	bool atack_flag;//�U�������ۂ�

	bool boss_bullet_collision_flag[BOSSBULLET_MAX];//�{�X�̒e�ƃv���C���[�Ƃ̏Փ˔���

	int world_no;

protected:


public:
	C_Boss() {};
	~C_Boss() {};

	//Cplayer
	void Init(LPDIRECT3DDEVICE9);  //������
	void UnInit();                 //���
	void UpdateProcess();                 //InputProcess
	void DrawProcess(LPDIRECT3DDEVICE9);	 //drawutil�Ăяo��

	void State1_Draw(LPDIRECT3DDEVICE9);
	void State2_Draw(LPDIRECT3DDEVICE9);
	
	void BossMove();
	void BossMove1();
	void BossMove2();

	void Targeting_Move();
	void Boss_Bullet_Move();

	void Damage_Effect();

	void BossBullet_Collision();

	void BossDraw(float, float, float tu[], float tv[], LPDIRECT3DDEVICE9, LPDIRECT3DTEXTURE9);
	
	void Boss_LeftDraw(float, float, LPDIRECT3DDEVICE9, LPDIRECT3DTEXTURE9);
	
	void Boss_Left1Draw(float, float, LPDIRECT3DDEVICE9, LPDIRECT3DTEXTURE9);
	void Boss_Left2Draw(float, float, LPDIRECT3DDEVICE9, LPDIRECT3DTEXTURE9);
	void Boss_Left3Draw(float, float, LPDIRECT3DDEVICE9, LPDIRECT3DTEXTURE9);
	void Boss_Left4Draw(float, float, LPDIRECT3DDEVICE9, LPDIRECT3DTEXTURE9);
	void Boss_Left5Draw(float, float, LPDIRECT3DDEVICE9, LPDIRECT3DTEXTURE9);
	
	void Boss_RightDraw(float, float, LPDIRECT3DDEVICE9, LPDIRECT3DTEXTURE9);
	
	void Boss_ShieldDraw(float, float, LPDIRECT3DDEVICE9, LPDIRECT3DTEXTURE9);
	void Boss_Shield1Draw(float, float, LPDIRECT3DDEVICE9, LPDIRECT3DTEXTURE9);

	void BossBullet(int i, float, float, LPDIRECT3DDEVICE9, LPDIRECT3DTEXTURE9);

	void ShadowDraw(float, float, LPDIRECT3DDEVICE9);

	void HPGageDraw(float x, float y, int damage, LPDIRECT3DDEVICE9 dev, LPDIRECT3DTEXTURE9 tex);

	//�{�X���W�擾
	static float Get_BossPos_x() { return pos_x; }
	static float Get_BossPos_y() { return pos_y; }

	//�{�X��_���[�W���i�[&�擾
	static void Store_Boss_Damage(int storedamage)
	{
		damage = storedamage;
	}
	static int& Get_Boss_Damage() { return damage; }


	//�G�l�~�[�_���[�W�t���O�i�[&�擾
	static void Store_Boss_Damage_Flag(bool store_damage_flag)
	{
		for (int i = 0; i<6; i++)
		{
			damage_flag = store_damage_flag;
		}
	}
	static bool& Get_Boss_Damage_Flag() { return damage_flag; }


	//�{�X�̏�Ԕ���i�[&�擾
	static void Store_Boss_State(int& store_state)
	{	
		boss_state = store_state;
	}
	static int& Get_Boss_State() { return boss_state; }


	//���񎞃{�X����
	static void Boss_Resurrection()
	{
		boss_state = 0;
		C_Boss::pos_x = BOSS_INIT_POS_X;
		C_Boss::pos_y = BOSS_INIT_POS_Y;
	}

};