//=============================================================================
//
// �G�l�~�[�R���W�������� [EnemyCollision.cpp]
//
//=============================================================================

#include "C_Player.h"
#include "C_Enemy.h"
#include "C_Sound.h"


//=============================================================================
// �G�l�~�[�����蔻�菈��
//=============================================================================
void C_Player::Enemy_Collision()
{
	//�t���b�V���J�E���^�[�����������菈��
	if (flash_counter == true)
	{
		Counter_Success();
	}

	//�t���b�V���J�E���^�[���s
	if (flash_counter == false && damage != 40)
	{
		Counter_Fail();
	}
}


//=============================================================================
// �t���b�V���J�E���^�[�������菈��
//=============================================================================
void C_Player::Counter_Success()
{
	//�G�l�~�[���W�擾
	float* Get_enemy_Pos_x = GetEnemy_Pos_x();
	float* Get_enemy_Pos_y = GetEnemy_Pos_y();

	//�G�l�~�[�_���[�W���擾
	int* Get_enemy_Damage = GetEnemy_Damage();

	//�G�l�~�[��Ԏ擾
	int* Get_enemy_State = GetEnemy_State();

	//�G�l�~�[MAX���擾
	int enemy_max = GetEnemy_Max();

	//�G�l�~�[�_���[�W�t���O�擾
	bool* Get_enemy_Damage_Flag = GetEnemy_Damage_Flag();

	//�G�l�~�[�Ƃ̓����蔻�菈��
	for (int i = 0; i < enemy_max; i++)
	{
		if ((pos_y + (int)C_Game_Manager::scroll_y*-1 <= Get_enemy_Pos_y[i] + 30) && (pos_y + (int)C_Game_Manager::scroll_y*-1 >= Get_enemy_Pos_y[i] - 30))
		{
			if ((pos_x + (int)C_Game_Manager::scroll_x*-1 <= Get_enemy_Pos_x[i] + 30) && (pos_x + (int)C_Game_Manager::scroll_x*-1 >= Get_enemy_Pos_x[i] - 30))
			{
				if (Get_enemy_State[i] == 0)
				{
					Get_enemy_State[i] = 1;

					Get_enemy_Damage_Flag[i] = false;

					Get_enemy_Damage[i] += 255;

					C_Sound::PlaySound(SOUND_LABEL_SE_GUARD);
				}
			}	
		}
	}

	//�G�l�~�[�_���[�W������ԁA�i�[
	StoreEnemy_Parameter(&Get_enemy_Damage[0], &Get_enemy_State[0], &Get_enemy_Damage_Flag[0]);
}


//=============================================================================
// �t���b�V���J�E���^�[���s������
//=============================================================================
void C_Player::Counter_Fail()
{
	//�G�l�~�[���W�擾
	float* Get_enemy_Pos_x = GetEnemy_Pos_x();
	float* Get_enemy_Pos_y = GetEnemy_Pos_y();

	//�G�l�~�[�_���[�W���擾
	int* Get_enemy_Damage = GetEnemy_Damage();

	//�G�l�~�[��Ԏ擾
	int* Get_enemy_State = GetEnemy_State();

	//�G�l�~�[MAX���擾
	int enemy_max = GetEnemy_Max();

	//�G�l�~�[�Ƃ̓����蔻�菈��
	for (int i = 0; i < enemy_max; i++)
	{
		if ((pos_y + (int)C_Game_Manager::scroll_y*-1 <= Get_enemy_Pos_y[i] + 30) && (pos_y + (int)C_Game_Manager::scroll_y*-1 >= Get_enemy_Pos_y[i] - 30))
		{
			if ((pos_x + (int)C_Game_Manager::scroll_x*-1 <= Get_enemy_Pos_x[i] + 30) && (pos_x + (int)C_Game_Manager::scroll_x*-1 >= Get_enemy_Pos_x[i] - 30))
			{
				if (Get_enemy_State[i] == 0)
				{

					if (direction_no == 0)
					{
						pos_y -= 10.0f;
					}

					if (direction_no == 1)
					{
						pos_y += 10.0f;
					}

					if (direction_no == 2)
					{
						pos_x += 10.0f;
					}

					if (direction_no == 3)
					{
						pos_x -= 10.0f;
					}
					damage++;
					collision_flag = true;
					enemy_colission_flag = true;

					C_Sound::PlaySound(SOUND_LABEL_SE_HIT);
				}

				//�񕜃A�C�e���l��
				if (Get_enemy_State[i] == 2)
				{
					Get_enemy_State[i] = 3;

					//5��
					if (damage >= 5) { damage -= 5; }
					if (damage <= 4) { damage = 0; }


					C_Sound::PlaySound(SOUND_LABEL_SE_LASER);
				}
			}
		}
	}

	//�_���[�W�G�t�F�N�g�̎���
	static int effecttime = 0;
	if (collision_flag == true)
	{
		if (effecttime == 25)
		{
			collision_flag = false;
			effecttime = 0;
		}
		if (effecttime != 25)
		{
			effecttime++;
		}
	}
}