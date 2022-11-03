//=============================================================================
//
// �v���C���[�����N���X [C_Player.h]
//
//=============================================================================

#pragma once
#include "Main.h"
#include "C_Game_Manager.h"

#define PLAYER_INIT_POS_X 300.0f
#define PLAYER_INIT_POS_Y 200.0f
#define PLAYER_WIDTH 60
#define PLAYER_HIGHT 50


//*****************************************************************************
// �񋓌^��`
//*****************************************************************************
enum direction_no {
	DIRECTION_DOWN = 0,
	DIRECTION_UP,
	DIRECTION_LEFT,
	DIRECTION_RIGHT
};


class C_Player : public C_Monster{
private:
	//�e�N�X�`��
	LPDIRECT3DTEXTURE9	 t_player,t_red_hp_gage, t_yellow_hp_gage, T_controller;

	static float pos_x;
	static float pos_y;
	
	//�v���C���[�_���[�W��
	static int damage;

	//�v���C���[�_���[�W�J���[�t���O
	static bool collision_flag;

	float rotatenumber= 0;//Z���̉�]����p�x
	
	bool key_push = false;//�ړ��{�^���t���O

	static bool flash_counter;  //�t���b�V���J�E���^�[�t���O
	
	int flash_counter_time = 0;  //�t���b�V���J�E���^�[��������(�Q�t���[��)
	int flash_counter_next = 50; //���Ƀt���b�V���J�E���^�[�𔭓��ł���܂ł̎���
	int flash_counter_color = 255;//�t���b�V���J�E���^�[���̃v���C���[�̐F

	//������
	static bool fire_trigger;

	//�v���C���[�̌����Ă��������\��
	static int direction_no;      

	//�_���[�W���󂯂�������ԃ_���[�W���󂯂Ȃ��悤�ɂ���
	bool enemy_colission_flag;
	bool boss_colission_flag;

	bool stage_sound, metu_sound;


	//�A�j���[�V�����Ԋu
	static unsigned int animtblidx;

	//�\��UV���W
	static unsigned int uvtblidx;


	//UpdateProcess
	//���[���h1�̃X�e�[�W�J��
	void TransStage_Flag();

	//��ʑJ�ڔ���
	void Trans_Judge1();
	void Trans_Judge2();

	//��ʑJ�ڏ���
	void TransStage();
	void TransStage_World1();
	void TransStage_World2();
	void TransStage_World3();


	void Player_Move1();
	void Up_Move1();
	void Down_Move1();
	void Left_Move1();
	void Right_Move1();

	void Player_Move2();
	void Up_Move2();
	void Down_Move2();
	void Left_Move2();
	void Right_Move2();

	void Footsteps();

	void HP_Recovery();
	void Fire_Trigger_Process();
	void Flash_Counter_Process();
	
	void Enemy_Collision();
	void Counter_Success();
	void Counter_Fail();

	void BossCollision();
	void Boss_Counter_Success();
	void Boss_Counter_Fail();
	void Damage_Effect(bool);

	void Game_Reset();
	void Reset_Process();

	void HPGageDraw(int, LPDIRECT3DDEVICE9, LPDIRECT3DTEXTURE9);

protected:


public:
	C_Player() :stage_sound(true), metu_sound(true) {};
	~C_Player() {};

	//StageSelect
	void SelectPlayerDraw(float, float, float tu[], float tv[], LPDIRECT3DDEVICE9);

	//Cplayer
	void Init(LPDIRECT3DDEVICE9);  //������
	void UnInit();                 //���
	void UpdateProcess();                    //InputProcess
	void World1_UpdateProcess();
	void World2_UpdateProcess();
	void World3_UpdateProcess();
	void Select_DrawProcess(LPDIRECT3DDEVICE9);	 //drawutil�Ăяo��
	void DrawProcess(LPDIRECT3DDEVICE9);	 //drawutil�Ăяo��
	void PlayerDraw(float tu[], float tv[], LPDIRECT3DDEVICE9);
	void ControllerDraw(LPDIRECT3DDEVICE9);
	void ShadowDraw(LPDIRECT3DDEVICE9);

	//�X�e�[�W���擾
	void GetParameter();
	void GetParameter2();
	void GetParameter3();

	//�A�j���[�V���������`�F���W
	void Anim_Select();
	void Anim_Main();

	//�G�l�~�[���W�擾
	static float Get_Player_Pos_x() { return pos_x; }
	static float Get_Player_Pos_y() { return pos_y; }

	//�G�l�~�[���i�[���擾
	static void StoreEnemy_Parameter(int[], int[], bool[]);
	static float* GetEnemy_Pos_x();
	static float* GetEnemy_Pos_y();
	static int* GetEnemy_Damage();
	static bool* GetEnemy_Damage_Flag();
	static int* GetEnemy_State();
	static int GetEnemy_Max();

	//�v���C���[�_���[�W���i�[&�擾
	static void Store_Player_Damage(int& storedamage)
	{
		damage = storedamage;
	}
	static int& Get_Player_Damage() { return damage; }

	//�v���C���[�̌����擾
	static int Get_Direction_No()
	{
		return direction_no;
	}

	//flash_counter�t���O�i�[&�擾
	//static void Store_flash_counter(bool& Get_Flash_Counter) { flash_counter = Get_Flash_Counter; }
	static bool& Get_Flash_Counter() { return flash_counter; }


	//�e���˃t���O�i�[&�擾
	static void Store_Fire_Trigger(bool& store_fire_trigger) { fire_trigger = store_fire_trigger; }
	static bool& Get_Fire_Trigger() { return fire_trigger; }

	//�v���C���[�R���W�����t���O�i�[&�擾
	static void Store_Collision_Flag(bool& store_collision_flag) { collision_flag = store_collision_flag; }
	static bool& Get_Collision_Flag() { return collision_flag; }
};