//=============================================================================
//
// �{�X�R���W�������� [BossCollision.cpp]
//
//=============================================================================

#include "C_Player.h"
#include "C_Boss.h"
#include "C_Sound.h"


//=============================================================================
// �{�X�����蔻�菈��
//=============================================================================
void C_Player::BossCollision()
{
	//�{�X�̌��̓����蔻��(�t���b�V���K�[�h)
	Boss_Counter_Success();

	//�{�X�̌��̓����蔻��(�t���b�V���K�[�h���s)
	Boss_Counter_Fail();
}


//=============================================================================
// �{�X�펞�t���b�V���J�E���^�[�������菈��
//=============================================================================
void C_Player::Boss_Counter_Success()
{
	//�{�X���W�擾
	float Get_BossPos_x = C_Boss::Get_BossPos_x();
	float Get_BossPos_y = C_Boss::Get_BossPos_y();

	//�{�X�_���[�W���擾
	int Get_Boss_Damage = C_Boss::Get_Boss_Damage();

	//�{�X�_���[�W�t���O�擾
	bool Get_Boss_Damage_Flag = C_Boss::Get_Boss_Damage_Flag();

	//�{�X��Ԏ擾
	int Get_Boss_State = C_Boss::Get_Boss_State();

	if ((pos_y + (int)C_Game_Manager::scroll_y*-1 <= Get_BossPos_y + 110) && (pos_y + (int)C_Game_Manager::scroll_y*-1 >= Get_BossPos_y - 20))
	{
		if ((pos_x + (int)C_Game_Manager::scroll_x*-1 <= Get_BossPos_x - 20) && (pos_x + (int)C_Game_Manager::scroll_x*-1 >= Get_BossPos_x - 40))
		{
			if (Get_Boss_State == 0 && flash_counter == true && boss_colission_flag == false)
			{
				Get_Boss_Damage += 10;
				Get_Boss_Damage_Flag = true;
				boss_colission_flag = true;
				C_Sound::PlaySound(SOUND_LABEL_SE_GUARD);
				if (Get_Boss_Damage >= 220)
				{
					Get_Boss_State = 1;
				}
			}
		}
	}

	//�^�����_���[�W�i�[
	C_Boss::Store_Boss_Damage(Get_Boss_Damage);//�Q�Ɠn��

    //�_���[�W�t���O�i�[
	C_Boss::Store_Boss_Damage_Flag(Get_Boss_Damage_Flag);//�Q�Ɠn��

	//�{�X�̏�Ԕ���i�[
	C_Boss::Store_Boss_State(Get_Boss_State);//�Q�Ɠn��
}


//=============================================================================
// �{�X�펞�t���b�V���J�E���^�[���s������
//=============================================================================
void C_Player::Boss_Counter_Fail()
{
	static bool sword = false;

	//�{�X���W�擾
	float Get_BossPos_x = C_Boss::Get_BossPos_x();
	float Get_BossPos_y = C_Boss::Get_BossPos_y();

	//�{�X�_���[�W���擾
	int Get_Boss_Damage = C_Boss::Get_Boss_Damage();

	//�{�X�_���[�W�t���O�擾
	bool Get_Boss_Damage_Flag = C_Boss::Get_Boss_Damage_Flag();

	//�{�X��Ԏ擾
	int Get_Boss_State = C_Boss::Get_Boss_State();

	if ((pos_y + (int)C_Game_Manager::scroll_y*-1 <= Get_BossPos_y + 110) && (pos_y + (int)C_Game_Manager::scroll_y*-1 >= Get_BossPos_y - 20))
	{
		if ((pos_x + (int)C_Game_Manager::scroll_x*-1 <= Get_BossPos_x - 20) && (pos_x + (int)C_Game_Manager::scroll_x*-1 >= Get_BossPos_x - 40))
		{
			if (Get_Boss_State == 0 && flash_counter == false && boss_colission_flag == false)
			{
				C_Sound::PlaySound(SOUND_LABEL_SE_HIT);
				damage += 5;
				collision_flag = true;
				boss_colission_flag = true;
				sword = true;
			}
		}
	}

	//���_���[�W���󂯂��玟�̃_���[�W�󂯂�܂ň��̊Ԋu���󂯂�
	static int time = 0;
	if (boss_colission_flag == true)
	{
		if (time == 100)
		{
			boss_colission_flag = false;
			time = 0;
		}
		if (time != 100)
		{
			time++;
		}
	}

	//�{�X�ƏՓˎ��̃_���[�W�G�t�F�N�g����
	Damage_Effect(sword);
}


//=============================================================================
// �{�X�ƏՓˎ��̃_���[�W�G�t�F�N�g����
//=============================================================================
void C_Player::Damage_Effect(bool sword)
{
	//�_���[�W�G�t�F�N�g�̎���
	static int effecttime = 0;

	//���Փˎ��̃_���[�W�G�t�F�N�g�̎���
	if (sword == true && collision_flag == true)
	{
		if (effecttime == 25)
		{
			collision_flag = false;
			effecttime = 0;
			sword = false;
		}
		if (effecttime != 25)
		{
			effecttime++;
		}
	}

	//�{�X�̒e�Փˎ��̃_���[�W�G�t�F�N�g�̎���
	if (sword == false && collision_flag == true)
	{
		if (effecttime == 8)
		{
			collision_flag = false;
			effecttime = 0;
		}
		if (effecttime != 8)
		{
			effecttime++;
		}
	}
}