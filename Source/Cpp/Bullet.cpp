//=============================================================================
//
// �v���C���[�e���� [Bullet.cpp]
//
//=============================================================================

#include "C_Bullet.h"
#include "C_Player.h"
#include "C_Boss.h"
#include "C_Enemy.h"
#include "C_Enemy1.h"
#include "C_Enemy2_1.h"
#include "C_Enemy2_2.h"
#include "C_Enemy2_3.h"
#include "C_Enemy3_1.h"
#include "C_Enemy3_2.h"
#include "C_Enemy3_3.h"
#include "C_Game.h"
#include "C_Sound.h"
#include "C_Select.h"


//==============================================================================
// ����������
//==============================================================================
void C_Bullet::Init(LPDIRECT3DDEVICE9 dev)
{
	HRESULT hr = D3DXCreateTextureFromFile(dev, "assets/bullet.png", &t_bullet);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}
}


//==============================================================================
// �I������
//==============================================================================
void C_Bullet::UnInit()
{
	if (t_bullet)
	{
		t_bullet->Release();
		t_bullet = NULL;
	}
}


//==============================================================================
// �e�X�V����
//==============================================================================
void C_Bullet::UpdateProcess()
{
	//���݂̃X�e�[�W�i���o�[�擾
	int world_no = C_Select::Get_World_No();
	C_Game_Manager::stage_no = Get_Stage_No();

	//�e�ʒu���W�w��
	BulletPos();

	//�e�ړ�����
	BulletMove();

	//�e�ƃG�l�~�[�̓����蔻��
	if (world_no == 1 && (stage_no == 2 || stage_no == 3))
	{
		BulletCollision();
	}
	if (world_no >= 2 && (stage_no == 2 || stage_no == 3 || stage_no == 4))
	{
		BulletCollision();
	}

	//�e�ƃ{�X�̓����蔻��
	if (world_no == 1 && stage_no == 4)
	{
		BulletBossCollision();
	}
	if (world_no >= 2 && stage_no == 5)
	{
		BulletBossCollision();
	}
}


//==============================================================================
// �e�`�揈��
//==============================================================================
void C_Bullet::DrawProcess(LPDIRECT3DDEVICE9 dev)
{
	//�F���擾
	C_Game_Manager::color = Get_Color();

	//���˂��Ă���e�����`��
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (bullet_fire[i] == true)
		{
			BulletDraw(i, dev);
		}
	}
}


//==============================================================================
// �e���ˈʒu���W�w�菈��
//==============================================================================
void C_Bullet::BulletPos()
{
	//�v���C���[�ʒu���擾
	float Get_Player_Pos_x = C_Player::Get_Player_Pos_x();
	float Get_Player_Pos_y = C_Player::Get_Player_Pos_y();

	//�v���C���[�̌������擾
	int direction_no = C_Player::Get_Direction_No();

	//�v���C���[�̒e���˃t���O�擾
	bool fire_trigger = C_Player::Get_Fire_Trigger();
	
	if (fire_trigger == true)
	{
		for (int i = 0; i < BULLET_MAX; i++)
		{
			//�e�e�̔��˒����ۂ��𔻒�
			if (bullet_fire[i] == false)
			{
				bullet_fire[i] = true;//�e����

				switch (direction_no)
				{
					//���˂���ʒu(����)
				case DIRECTION_DOWN:
					pos_x[i] = Get_Player_Pos_x - BULLET_WIDTH / 5;
					pos_y[i] = Get_Player_Pos_y + BULLET_HIGHT / 4;
					bullet_direction[i] = 0;
					break;

				case DIRECTION_UP:
					pos_x[i] = Get_Player_Pos_x - BULLET_WIDTH / 5;
					pos_y[i] = Get_Player_Pos_y - BULLET_HIGHT / 2;
					bullet_direction[i] = 1;
					break;

				case DIRECTION_LEFT:
					pos_x[i] = Get_Player_Pos_x - BULLET_WIDTH / 2;
					pos_y[i] = Get_Player_Pos_y;
					bullet_direction[i] = 2;
					break;

				case DIRECTION_RIGHT:
					pos_x[i] = Get_Player_Pos_x + BULLET_WIDTH / 7;
					pos_y[i] = Get_Player_Pos_y;
					bullet_direction[i] = 3;
					break;
				}
				break;
			}
		}
	}
	C_Player::Store_Fire_Trigger(fire_trigger = false);
}


//==============================================================================
// �e�ړ�����
//==============================================================================
void C_Bullet::BulletMove()
{
	//�e�̈ړ�����
	for (int i = 0; i < BULLET_MAX; i++)
	{
		//�e�����˒��Ȃ�
		if (bullet_fire[i] == true)
		{
			//���˂���ʒu�ɂ��A�ړ�����������قȂ�B
			switch (bullet_direction[i])
			{
			case DIRECTION_DOWN:
				pos_y[i] += 6;//�e�̈ړ�
				break;
			case DIRECTION_UP:
				pos_y[i] -= 6;//�e�̈ړ�
				break;
			case DIRECTION_LEFT:
				pos_x[i] -= 6;//�e�̈ړ�
				break;
			case DIRECTION_RIGHT:
				pos_x[i] += 6;//�e�̈ړ�
				break;
			}

			//�e����(��ʊO (600 400))
			if (pos_x[i] <= 0 || pos_x[i] >= 570.0f || pos_y[i] <= 10 || pos_y[i] >= 380.0f)
			{
				bullet_fire[i] = false;
			}
		}
	}
}


//==============================================================================
// �e�ƃG�l�~�[�����蔻�菈��
//==============================================================================
void C_Bullet::BulletCollision()
{
	//�G�l�~�[���W�擾
	float* Get_enemy_Pos_x = C_Player::GetEnemy_Pos_x();
	float* Get_enemy_Pos_y = C_Player::GetEnemy_Pos_y();

	//�G�l�~�[�_���[�W���擾
	int* Get_enemy_Damage = C_Player::GetEnemy_Damage();

	//�G�l�~�[��Ԏ擾
	int* Get_enemy_State = C_Player::GetEnemy_State();

	//�G�l�~�[�_���[�W�t���O�擾
	bool* Get_enemy_Damage_Flag = C_Player::GetEnemy_Damage_Flag();

	//�G�l�~�[MAX���擾
	int enemy_max = C_Player::GetEnemy_Max();

	//�e�̓����蔻��
	for (int i = 0; i < BULLET_MAX; i++)
	{
		for (int j = 0; j < enemy_max; j++)
		{
			if ((pos_y[i] + (int)C_Game_Manager::scroll_y*-1 <= Get_enemy_Pos_y[j] + 10) && (pos_y[i] + (int)C_Game_Manager::scroll_y*-1 >= Get_enemy_Pos_y[j] - 20))
			{
				if ((pos_x[i] + (int)C_Game_Manager::scroll_x*-1 <= Get_enemy_Pos_x[j] + 10) && (pos_x[i] + (int)C_Game_Manager::scroll_x*-1 >= Get_enemy_Pos_x[j] - 20))
				{
					if (Get_enemy_State[j] == 0 && bullet_fire[i] == true)
					{
						C_Sound::PlaySound(SOUND_LABEL_SE_HIT);

						Get_enemy_Damage[j] += 5;
						bullet_fire[i] = false;
						Get_enemy_Damage_Flag[j] = true;

						if (Get_enemy_Damage[j] >= 40)
						{
							C_Sound::PlaySound(SOUND_LABEL_SE_BOMB);
							Get_enemy_State[j] = 1;
						}
					}
				}
			}
		}
	}

	//�G�l�~�[�_���[�W������ԁ��_���[�W�t���O�A�i�[
	C_Player::StoreEnemy_Parameter(&Get_enemy_Damage[0], &Get_enemy_State[0], &Get_enemy_Damage_Flag[0]);
}


//==============================================================================
// �e�ƃ{�X�����蔻�菈��
//==============================================================================
void C_Bullet::BulletBossCollision()
{
	//�{�X���W�擾
	float Get_BossPos_x = C_Boss::Get_BossPos_x();
	float Get_BossPos_y = C_Boss::Get_BossPos_y();

	//�{�X�_���[�W���擾
	int Get_Boss_Damage = C_Boss::Get_Boss_Damage();

	//�{�X�_���[�W�t���O�擾
	bool Get_Boss_Damage_Flag = C_Boss::Get_Boss_Damage_Flag();

	//�G�l�~�[��Ԏ擾
	int Get_Boss_State = C_Boss::Get_Boss_State();
	
	//�e�̓����蔻��
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if ((pos_y[i] + (int)C_Game_Manager::scroll_y*-1 <= Get_BossPos_y + 50) && (pos_y[i] + (int)C_Game_Manager::scroll_y*-1 >= Get_BossPos_y - 60))
		{
			if ((pos_x[i] + (int)C_Game_Manager::scroll_x*-1 <= Get_BossPos_x + 160) && (pos_x[i] + (int)C_Game_Manager::scroll_x*-1 >= Get_BossPos_x - 90))
			{
				if (Get_Boss_State == 0 && bullet_fire[i] == true)
				{
					C_Sound::PlaySound(SOUND_LABEL_SE_HIT);

					Get_Boss_Damage += 1;
					Get_Boss_Damage_Flag = true;
					bullet_fire[i] = false;

					if (Get_Boss_Damage >= 220)
					{
						C_Sound::PlaySound(SOUND_LABEL_SE_BOMB);
						Get_Boss_State = 1;
					}
				}
			}
		}
	}

	//�^�����_���[�W�i�[
	C_Boss::Store_Boss_Damage(Get_Boss_Damage);//�Q�Ɠn��

	//�_���[�W�t���O�i�[
	C_Boss::Store_Boss_Damage_Flag(Get_Boss_Damage_Flag);//�Q�Ɠn��

	//�{�X��Ԕ���i�[
	C_Boss::Store_Boss_State(Get_Boss_State);//�Q�Ɠn��
}