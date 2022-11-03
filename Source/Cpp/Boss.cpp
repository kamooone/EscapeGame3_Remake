//=============================================================================
//
// �{�X���� [Boss.cpp]
//
//=============================================================================

#include "C_Boss.h"
#include "Struct_Boss.h"
#include "C_Player.h"
#include "C_Select.h"
#include "C_Sound.h"
#include <stdlib.h>
#include <time.h>


//*****************************************************************************
// �ÓI�����o�ϐ����̉�
//*****************************************************************************

//�{�X�̈ʒu�ϐ������̉�
float C_Boss :: pos_x = BOSS_INIT_POS_X;
float C_Boss :: pos_y = BOSS_INIT_POS_Y;

//�{�X�_���[�W�����̉�
int C_Boss :: damage = 0;

//�{�X�_���[�W�G�t�F�N�g�t���O
bool C_Boss::damage_flag = false;

//�{�X�̐�����ԕϐ������̉�
int C_Boss :: boss_state = 0;



//==============================================================================
// ����������
//==============================================================================
void C_Boss::Init(LPDIRECT3DDEVICE9 dev)
{
	HRESULT hr = D3DXCreateTextureFromFile(dev, "assets/Boss.png", &t_boss);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}

	hr = D3DXCreateTextureFromFile(dev, "assets/explosion.png", &t_explosion);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}

	hr = D3DXCreateTextureFromFile(dev, "assets/gage.png", &t_red_hp_gage);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}

	hr = D3DXCreateTextureFromFile(dev, "assets/gageYellow.png", &t_yellow_hp_gage);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}

	hr = D3DXCreateTextureFromFile(dev, "assets/shadow.png", &t_shadow);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}
}


//==============================================================================
// �I������
//==============================================================================
void C_Boss::UnInit()
{
	if (t_boss)
	{
		t_boss->Release();
		t_boss = NULL;
	}
	if (t_explosion)
	{
		t_explosion->Release();
		t_explosion = NULL;
	}

	if (t_red_hp_gage)
	{
		t_red_hp_gage->Release();
		t_red_hp_gage = NULL;
	}

	if (t_yellow_hp_gage)
	{
		t_yellow_hp_gage->Release();
		t_yellow_hp_gage = NULL;
	}

	if (t_shadow)
	{
		t_shadow->Release();
		t_shadow = NULL;
	}
}


//==============================================================================
// �{�X�X�V����
//==============================================================================
void C_Boss::UpdateProcess()
{
	C_Game_Manager::manual_no = Get_Manual_No();

	//���݂̃X�e�[�W�i���o�[�擾
	C_Game_Manager::stage_no = Get_Stage_No();
	C_Boss::world_no = C_Select::Get_World_No();

	//�v���C���[�_���[�W���擾
	int Get_Player_Damage = C_Player::Get_Player_Damage();

	//�{�X�ړ�����
	BossMove();

	//�_���[�W�G�t�F�N�g����
	Damage_Effect();
}


//==============================================================================
// �{�X�`�揈��
//==============================================================================
void C_Boss::DrawProcess(LPDIRECT3DDEVICE9 dev)
{
	switch (boss_state)
	{
	case USUALLY:
		State1_Draw(dev);
		break;

	case DESTROY:
		State2_Draw(dev);
		break;
	}
}


//==============================================================================
// �{�X�ړ�����
//==============================================================================
void C_Boss::BossMove()
{
	if (boss_state == 0 && (C_Game_Manager::manual_no >= 5 || (world_no >= 2 && stage_no == 5)))
	{
		if (damage <= 110)
		{
			//�{�X���`��
			BossMove1();
		}
		if (damage >= 111)
		{
			//�`���[�g���A���\��
			if (C_Game_Manager::manual_no == 5 && world_no == 1)
			{
				Store_Manual_No(C_Game_Manager::manual_no = 6);
			}

			//�`���[�g���A���\�����͓����~
			if (C_Game_Manager::manual_no >= 7 || (world_no >= 2 && stage_no == 5))
			{
				//�{�X���`��
				BossMove2();

				//�{�X�̒e�̓����蔻��
				BossBullet_Collision();
			}
		}
	}
}


//==============================================================================
// �{�X�ړ�����1
//==============================================================================
void C_Boss::BossMove1()
{
	//�v���C���[�ʒu���擾
	float Get_Player_Pos_x = C_Player::Get_Player_Pos_x();
	float Get_Player_Pos_y = C_Player::Get_Player_Pos_y();

	static int atack_start_flag = 0;

	//�v���C���[��W�I�Ɏ����ړ�
	if ((Get_Player_Pos_x + C_Game_Manager::scroll_x*-1 <= pos_x - 25.0f) && atack_flag == false)
	{
		pos_x -= 1.5f;//��
	}
	if ((Get_Player_Pos_x + C_Game_Manager::scroll_x*-1 >= pos_x - 25.0f) && atack_flag == false)
	{
		pos_x += 1.5f;//�E
	}

	//�{�X�̍U���̃^�C�~���O(�{�X�ƃv���C���[��������ɂȂ�����)
	if (Get_Player_Pos_x + C_Game_Manager::scroll_x*-1 + 20.0f >= pos_x - 25.0f && Get_Player_Pos_x + C_Game_Manager::scroll_x*-1 <= pos_x - 25.0f &&
		atack == true && pos_y <= BOSS_INIT_POS_Y)
	{
		if (atack_start_flag == 100)
		{
			atack_start_flag = 0;
			atack_flag = true;
			atack = false;
		}

		if (atack_start_flag != 100) { atack_start_flag++; }
	}

	//�U���J�n
	if (atack_flag == true)
	{
		if (pos_y <= 400.0f) { pos_y += 5; }
	}

	//�U���I��
	if (pos_y >= 400.0f && atack_flag == true)
	{
		atack_flag = false;
	}

	//�U�����I���ƌ��̈ʒu�ɖ߂�		
	if (pos_y >= BOSS_INIT_POS_Y && atack_flag == false && atack == false)
	{
		pos_y -= 5.0f;
	}
	//���̈ʒu�ɖ߂�ƍĂэU���\��Ԃ�
	else if (pos_y <= BOSS_INIT_POS_Y && atack_flag == false)
	{
		atack = true;
	}

	//�e�����������Ă���
	for (int i = 0; i < BOSSBULLET_MAX; i++)
	{
		boss_bullet_fire[i] = 0;
		bullet_pos_x[i] = 0.0f;
		bullet_pos_y[i] = 0.0f;
		bullet_cnt = 0;
		bullet_motion_no = 1;
	}
}


//==============================================================================
// �{�X�ړ�����2
//==============================================================================
void C_Boss::BossMove2()
{
	//�O�ɏo�Ă�������ɉ�����
	if (pos_y >= BOSS_INIT_POS_Y) { pos_y -= 5.0f; }


	if (pos_y <= BOSS_INIT_POS_Y)
	{
		//�v���C���[��W�I�Ɏ����ړ�
		Targeting_Move();

		Boss_Bullet_Move();
	}
}


//==============================================================================
// �v���C���[��W�I�Ɏ����ړ�����
//==============================================================================
void C_Boss::Targeting_Move()
{
	//�v���C���[�ʒu���擾
	float Get_Player_Pos_x = C_Player::Get_Player_Pos_x();
	float Get_Player_Pos_y = C_Player::Get_Player_Pos_y();

	static int atack_start_flag = 0;

	if ((Get_Player_Pos_x + C_Game_Manager::scroll_x*-1 <= pos_x - 25.0f))
	{
		pos_x -= 1.5f;//��
	}
	if ((Get_Player_Pos_x + C_Game_Manager::scroll_x*-1 >= pos_x - 25.0f))
	{
		pos_x += 1.5f;//�E
	}

	//�{�X�̍U���̃^�C�~���O(�{�X�ƃv���C���[��������ɂȂ�����)
	if (Get_Player_Pos_x + C_Game_Manager::scroll_x*-1 + 20.0f >= pos_x - 25.0f && Get_Player_Pos_x + C_Game_Manager::scroll_x*-1 <= pos_x - 25.0f &&
		atack == true)
	{
		if (atack_start_flag == 50)
		{
			atack_start_flag = 0;
			atack_flag = true;
			atack = false;
		}

		if (atack_start_flag != 50) { atack_start_flag++; }

		if (boss_bullet_fire[0] == 0)
		{
			if (atack_start_flag == 6)
			{
				bullet_motion_no = 2;
			}
			if (atack_start_flag == 12)
			{
				bullet_motion_no = 3;
			}
			if (atack_start_flag == 18)
			{
				bullet_motion_no = 4;
			}
			if (atack_start_flag == 24)
			{
				bullet_motion_no = 5;
			}
		}
	}
}


//==============================================================================
// �{�X�e�ړ�����
//==============================================================================
void C_Boss::Boss_Bullet_Move()
{
	//�U���J�n
	if (atack_flag == true)
	{
		static int time = 0;
		time++;

		if (time == 20)
		{
			boss_bullet_fire[bullet_cnt] = 1;
			time = 0;
			if (bullet_cnt < BOSSBULLET_MAX)
			{
				bullet_cnt++;
			}
		}
	}

	for (int i = 0; i < BOSSBULLET_MAX; i++)
	{
		//�e�����˒��Ȃ�
		if (boss_bullet_fire[i] == 1)
		{
			bullet_pos_y[i] += 5;//�e�̈ړ�

								 //�e����(��ʊO (600 400))
			if (bullet_pos_y[i] >= 400.0f)
			{
				boss_bullet_fire[i] = 2;
			}
		}
	}

	if (boss_bullet_fire[BOSSBULLET_MAX - 1] == 2)
	{
		atack_flag = false;
		atack = true;
		for (int i = 0; i < BOSSBULLET_MAX; i++)
		{
			boss_bullet_fire[i] = 0;
			bullet_pos_x[i] = 0.0f;
			bullet_pos_y[i] = 0.0f;
			bullet_cnt = 0;
			bullet_motion_no = 1;
		}
	}
}


//==============================================================================
// �{�X�_���[�W�G�t�F�N�g
//==============================================================================
void C_Boss::Damage_Effect()
{
	static int time = 0;
	if (damage_flag == true)
	{
		if (time == 25)
		{
			damage_flag = false;
			time = 0;
		}
		if (time != 25)
		{
			time++;
		}
	}
}


//==============================================================================
// �{�X�ʏ펞�`��
//==============================================================================
void C_Boss::State1_Draw(LPDIRECT3DDEVICE9 dev)
{
	//�ۉe�`��
	ShadowDraw(C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, dev);

	//HP�Q�[�W�`��
	HPGageDraw(C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, 0, dev, t_red_hp_gage);
	HPGageDraw(C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, damage, dev, t_yellow_hp_gage);


	if (damage <= 110)
	{
		Boss_LeftDraw(C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, dev, t_boss);
		Boss_RightDraw(C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, dev, t_boss);
		Boss_ShieldDraw(C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, dev, t_boss);
	}

	if (damage >= 111)
	{
		//�e���˃��[�V����
		switch (bullet_motion_no)
		{
		case 1:
			Boss_Left1Draw(C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, dev, t_boss);
			break;
		case 2:
			Boss_Left2Draw(C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, dev, t_boss);
			break;
		case 3:
			Boss_Left3Draw(C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, dev, t_boss);
			break;
		case 4:
			Boss_Left4Draw(C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, dev, t_boss);
			break;
		case 5:
			Boss_Left5Draw(C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, dev, t_boss);
			break;
		}

		Boss_RightDraw(C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, dev, t_boss);
		//�V�[���h�j��
		Boss_Shield1Draw(C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, dev, t_boss);

		//�{�X�e�`��
		for (int i = 0; i < BOSSBULLET_MAX; i++)
		{
			if (boss_bullet_fire[i] == 1)
			{
				BossBullet(i, C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, dev, t_boss);
			}
		}
	}
}


//==============================================================================
// �{�X���Ŏ��`��
//==============================================================================
void C_Boss::State2_Draw(LPDIRECT3DDEVICE9 dev)
{
	static unsigned int animtblidx_Explosion_C_Boss[1] = { 0 };
	static int animtime_Explosion_C_Boss[1] = { 0 };
	unsigned int uvtblidx_Explosion_C_Boss[1];

	uvtblidx_Explosion_C_Boss[0] = g_anim_Explosion_Boss[animtblidx_Explosion_C_Boss[0]].no;

	//�����A�j���[�V����
	if (boss_state == 1)
	{
		if (animtime_Explosion_C_Boss[0] >= 8)
		{
			animtblidx_Explosion_C_Boss[0]++;
			animtime_Explosion_C_Boss[0] = 0;
		}
		else if (animtime_Explosion_C_Boss[0] <= 8)
		{
			animtime_Explosion_C_Boss[0]++;
		}

		//�A�j���[�V�����J��Ԃ�
		if (animtblidx_Explosion_C_Boss[0] == 17)
		{
			animtblidx_Explosion_C_Boss[0] = 0;
			animtime_Explosion_C_Boss[0] = 0;
			boss_state = 2;
		}
	}

	//����
	if (boss_state == 1)
	{
		//HP�Q�[�W�`��
		HPGageDraw(C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, 0, dev, t_red_hp_gage);
		HPGageDraw(C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, damage, dev, t_yellow_hp_gage);

		//����
		BossDraw(C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, g_uvTable_Explosion_Boss[uvtblidx_Explosion_C_Boss[0]].u,
			g_uvTable_Explosion_Boss[uvtblidx_Explosion_C_Boss[0]].v, dev, t_explosion);
	}
}


//==============================================================================
// �{�X�̒e�̓����蔻��
//==============================================================================
void C_Boss::BossBullet_Collision()
{
	//�v���C���[�ʒu���擾
	float Player_Pos_x = C_Player::Get_Player_Pos_x();
	float Player_Pos_y = C_Player::Get_Player_Pos_y();

	//��ʃX�N���[���l�擾
	scroll_x = C_Game_Manager::Get_Scroll_x();
	scroll_y = C_Game_Manager::Get_Scroll_y();

	//�v���C���[�_���[�W���擾
	int Get_Player_Damage = C_Player::Get_Player_Damage();

	//�v���C���[�R���W�����t���O�擾
	bool G_collision_flag = C_Player::Get_Collision_Flag();

	//�v���C���[�J�E���^�[�t���O�擾
	bool Get_Flash_Counter = C_Player::Get_Flash_Counter();

	if (boss_state == 0)
	{
		//�e�̓����蔻��flag������
		for (int i = 0; i < BOSSBULLET_MAX; i++)
		{
			boss_bullet_collision_flag[i] = false;
		}

		//�e�̓����蔻�菈��
		for (int i = 0; i < BOSSBULLET_MAX; i++)
		{
			if ((pos_y + bullet_pos_y[i] + BOSS_HIGHT - 20.0f <= Player_Pos_y + scroll_y*-1 + 25) &&
				(pos_y + bullet_pos_y[i] + BOSS_HIGHT - 50.0f >= Player_Pos_y + scroll_y*-1 - 25))
			{
				if ((pos_x + bullet_pos_x[i] - BOSS_WIDTH / 2 + 30.0f <= Player_Pos_x + scroll_x*-1 + 30) &&
					(pos_x + bullet_pos_x[i] - 30.0f >= Player_Pos_x + scroll_x*-1 - 30))
				{
					//�K�[�h����
					if (boss_bullet_fire[i] == 1 && boss_bullet_collision_flag[i] == false && Get_Flash_Counter == true)
					{
						C_Sound::PlaySound(SOUND_LABEL_SE_GUARD);
						boss_bullet_collision_flag[i] = true;
						boss_bullet_fire[i] = 2;
					}

					//�K�[�h���s
					else if (boss_bullet_fire[i] == 1 && boss_bullet_collision_flag[i] == false && Get_Flash_Counter == false)
					{
						C_Sound::PlaySound(SOUND_LABEL_SE_HIT);
						Get_Player_Damage += 1;
						boss_bullet_collision_flag[i] = true;
						boss_bullet_fire[i] = 2;
						G_collision_flag = true;
					}
				}
			}
		}

		//�v���C���[�R���W�����t���O�i�[
		C_Player::Store_Collision_Flag(G_collision_flag);
	}

	//�^�����_���[�W�i�[
	C_Player::Store_Player_Damage(Get_Player_Damage);//�Q�Ɠn��
}