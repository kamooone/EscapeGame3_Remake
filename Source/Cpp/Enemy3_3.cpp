//=============================================================================
//
// �G�l�~�[���� [Enemy3_3.cpp]
//
//=============================================================================

#include "C_Enemy3_3.h"
#include "Struct_enemy3_3.h"
#include "C_Player.h"
#include <stdlib.h>
#include <time.h>


//*****************************************************************************
// �ÓI�����o�ϐ����̉�
//*****************************************************************************
float C_Enemy3_3::pos_x[ENEMY_MAX3_3] = { ENEMY2_1_INIT_POS_X3_3, ENEMY2_2_INIT_POS_X3_3, ENEMY2_3_INIT_POS_X3_3, ENEMY2_4_INIT_POS_X3_3 , ENEMY2_5_INIT_POS_X3_3,
ENEMY2_6_INIT_POS_X3_3, ENEMY2_7_INIT_POS_X3_3, ENEMY2_8_INIT_POS_X3_3, ENEMY2_9_INIT_POS_X3_3, ENEMY2_10_INIT_POS_X3_3,
ENEMY2_11_INIT_POS_X3_3 , ENEMY2_12_INIT_POS_X3_3 , ENEMY2_13_INIT_POS_X3_3 , ENEMY2_14_INIT_POS_X3_3 , ENEMY2_15_INIT_POS_X3_3 };


float C_Enemy3_3::pos_y[ENEMY_MAX3_3] = { ENEMY2_1_INIT_POS_Y3_3, ENEMY2_2_INIT_POS_Y3_3, ENEMY2_3_INIT_POS_Y3_3, ENEMY2_4_INIT_POS_Y3_3 , ENEMY2_5_INIT_POS_Y3_3,
ENEMY2_6_INIT_POS_Y3_3, ENEMY2_7_INIT_POS_Y3_3, ENEMY2_8_INIT_POS_Y3_3, ENEMY2_9_INIT_POS_Y3_3, ENEMY2_10_INIT_POS_Y3_3,
ENEMY2_11_INIT_POS_Y3_3, ENEMY2_12_INIT_POS_Y3_3, ENEMY2_13_INIT_POS_Y3_3, ENEMY2_14_INIT_POS_Y3_3, ENEMY2_15_INIT_POS_Y3_3 };

//�G�l�~�[�[�̌����ϐ������̉�
int C_Enemy3_3::direction_no_enemy[ENEMY_MAX3_3] = { 0 };

//�G�l�~�[�̐������
int C_Enemy3_3::enemy_state[ENEMY_MAX3_3] = { 0 };

//�G�l�~�[��_���[�W�����̉�
int C_Enemy3_3::damage[ENEMY_MAX3_3] = { 0 };

//�G�l�~�[�_���[�W�G�t�F�N�g�t���O
bool C_Enemy3_3::damage_flag[ENEMY_MAX3_3] = { false };


//==============================================================================
// ����������
//==============================================================================
void C_Enemy3_3::Init(LPDIRECT3DDEVICE9 dev)
{
	HRESULT hr = D3DXCreateTextureFromFile(dev, "assets/enemy1.png", &t_enemy);
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

	for (int i = 0; i<ENEMY_MAX3_3; i++)
	{
		tuizyuu_flag[i] = false;
	}

	hr = D3DXCreateTextureFromFile(dev, "assets/apple.png", &t_apple);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}
}


//==============================================================================
// �I������
//==============================================================================
void C_Enemy3_3::UnInit()
{
	if (t_enemy)
	{
		t_enemy->Release();
		t_enemy = NULL;
	}
	if (t_explosion)
	{
		t_explosion->Release();
		t_explosion = NULL;
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

	if (t_shadow)
	{
		t_shadow->Release();
		t_shadow = NULL;
	}

	if (t_apple)
	{
		t_apple->Release();
		t_apple = NULL;
	}
}


//==============================================================================
// �G�l�~�[�X�V����
//==============================================================================
void C_Enemy3_3::UpdateProcess()
{
	//�}�b�v�`�b�v�f�[�^�擾
	int* Get_MapData;//�ꎟ���z��Ɋi�[�p
	Get_MapData = C_Mapchip::MapData_Get3();
	for (int i = 0; i<1000 / 20; i++)
	{
		for (int j = 0; j < 1200 / 20; j++)
		{
			static int ij = 0;
			MapData_No2_TwoDim[i][j] = Get_MapData[ij];
			if (ij <= 2999) { ij++; }
			if (ij == 3000) { ij = 0; }
		}
	}

	//���ݎ����̏��ŏ�����
	srand((unsigned int)time(NULL));

	//�G�l�~�[�ړ�
	for (int i = 0; i<ENEMY_MAX3_3; i++)
	{
		if (enemy_state[i] == 0 && damage_flag[i] == false)
		{
			//�v���C���[�Ǐ]����
			MoveTuizyu(i);

			if (tuizyuu_flag[i] == false)
			{
				direction_no_enemy[i] = rand() % 4;//0�`3�̃����_��

				switch (direction_no_enemy[i])
				{
				case DIRECTION_DOWN:
					MoveDown(i);
					break;

				case DIRECTION_UP:
					MoveUp(i);
					break;

				case DIRECTION_LEFT:
					MoveLeft(i);
					break;

				case DIRECTION_RIGHT:
					MoveRight(i);
					break;
				}
			}
			tuizyuu_flag[i] = false;
		}
	}
	Damage_Effect();
}


//==============================================================================
// �v���C���[�Ǐ]��������
//==============================================================================
void C_Enemy3_3::MoveTuizyu(int i)
{
	//�v���C���[�̍��W���擾
	float Get_Player_Pos_x = C_Player::Get_Player_Pos_x();
	float Get_Player_Pos_y = C_Player::Get_Player_Pos_y();

	//��ʃX�N���[���l�擾
	scroll_x = C_Game_Manager::Get_Scroll_x();
	scroll_y = C_Game_Manager::Get_Scroll_y();

	TuizyuRight(i, Get_Player_Pos_x, Get_Player_Pos_y, scroll_x, scroll_y);

	TuizyuLeft(i, Get_Player_Pos_x, Get_Player_Pos_y, scroll_x, scroll_y);

	TuizyuUp(i, Get_Player_Pos_x, Get_Player_Pos_y, scroll_x, scroll_y);

	TuizyuDown(i, Get_Player_Pos_x, Get_Player_Pos_y, scroll_x, scroll_y);
}


//==============================================================================
// �E�Ǐ]����
//==============================================================================
void C_Enemy3_3::TuizyuRight(int i, float Get_Player_Pos_x, float Get_Player_Pos_y, float scroll_x, float scroll_y)
{
	if (Get_Player_Pos_x - scroll_x - pos_x[i] >= 0 && Get_Player_Pos_x - scroll_x - pos_x[i] <= 150 &&
		Get_Player_Pos_y - scroll_y - pos_y[i] >= -150 && Get_Player_Pos_y - scroll_y - pos_y[i] <= 150)
	{
		pos_x[i] += 1.0f;
		tuizyuu_flag[i] = true;
		direction_no_enemy[i] = 3;

		//��Q�����Ǝ~�܂�
		if (MapData_No2_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] <= -1 || MapData_No2_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] >= 2)
		{
			pos_x[i] -= 1.0f;
		}

		//�G�l�~�[���m�Փ˂��Ȃ��悤��
		for (int j = 0; j < ENEMY_MAX3_3; j++)
		{
			if ((pos_y[i] - 30 <= pos_y[j] + 30) && (pos_y[i] + 30 >= pos_y[j] - 30))
			{
				if ((pos_x[i] - 30 <= pos_x[j] + 30) && (pos_x[i] + 30 >= pos_x[j] - 30))
				{
					if (i != j && enemy_state[j] == 0)
					{
						pos_x[i] -= 1.0f;
					}
				}
			}
		}
	}
}


//==============================================================================
// ���Ǐ]����
//==============================================================================
void C_Enemy3_3::TuizyuLeft(int i, float Get_Player_Pos_x, float Get_Player_Pos_y, float scroll_x, float scroll_y)
{
	if (Get_Player_Pos_x - scroll_x - pos_x[i] <= 0 && Get_Player_Pos_x - scroll_x - pos_x[i] >= -150 &&
		Get_Player_Pos_y - scroll_y - pos_y[i] >= -150 && Get_Player_Pos_y - scroll_y - pos_y[i] <= 150)
	{
		pos_x[i] -= 1.0f;
		tuizyuu_flag[i] = true;
		direction_no_enemy[i] = 2;

		//��Q�����Ǝ~�܂�
		if (MapData_No2_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] <= -1 || MapData_No2_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] >= 2)
		{
			pos_x[i] += 1.0f;
		}

		//�G�l�~�[���m�Փ˂��Ȃ��悤��
		for (int j = 0; j < ENEMY_MAX3_3; j++)
		{
			if ((pos_y[i] - 30 <= pos_y[j] + 30) && (pos_y[i] + 30 >= pos_y[j] - 30))
			{
				if ((pos_x[i] - 30 <= pos_x[j] + 30) && (pos_x[i] + 30 >= pos_x[j] - 30))
				{
					if (i != j && enemy_state[j] == 0)
					{
						pos_x[i] += 1.0f;
					}
				}
			}
		}
	}
}


//==============================================================================
// ��Ǐ]����
//==============================================================================
void C_Enemy3_3::TuizyuUp(int i, float Get_Player_Pos_x, float Get_Player_Pos_y, float scroll_x, float scroll_y)
{
	if (Get_Player_Pos_y - scroll_y - pos_y[i] <= 0 && Get_Player_Pos_y - scroll_y - pos_y[i] >= -150 &&
		Get_Player_Pos_x - scroll_x - pos_x[i] >= -150 && Get_Player_Pos_x - scroll_x - pos_x[i] <= 150)
	{
		pos_y[i] -= 1.0f;
		tuizyuu_flag[i] = true;
		direction_no_enemy[i] = 1;

		//�E
		if ((Get_Player_Pos_x - scroll_x) > pos_x[i] + 30.0f &&
			Get_Player_Pos_y - scroll_y - pos_y[i] >= -150 && Get_Player_Pos_y - scroll_y - pos_y[i] <= 150)
		{
			direction_no_enemy[i] = 3;
		}
		//��
		if ((Get_Player_Pos_x - scroll_x + 30.0f) < pos_x[i] &&
			Get_Player_Pos_y - scroll_y - pos_y[i] >= -150 && Get_Player_Pos_y - scroll_y - pos_y[i] <= 150)
		{
			direction_no_enemy[i] = 2;
		}

		//��Q�����Ǝ~�܂�
		if (MapData_No2_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] <= -1 || MapData_No2_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] >= 2)
		{
			pos_y[i] += 1.0f;
		}

		//�G�l�~�[���m�Փ˂��Ȃ��悤��
		for (int j = 0; j < ENEMY_MAX3_3; j++)
		{
			if ((pos_y[i] - 30 <= pos_y[j] + 30) && (pos_y[i] + 30 >= pos_y[j] - 30))
			{
				if ((pos_x[i] - 30 <= pos_x[j] + 30) && (pos_x[i] + 30 >= pos_x[j] - 30))
				{
					if (i != j && enemy_state[j] == 0)
					{
						pos_y[i] += 1.0f;
					}
				}
			}
		}
	}
}


//==============================================================================
// ���Ǐ]����
//==============================================================================
void C_Enemy3_3::TuizyuDown(int i, float Get_Player_Pos_x, float Get_Player_Pos_y, float scroll_x, float scroll_y)
{
	if (Get_Player_Pos_y - scroll_y - pos_y[i] >= 0 && Get_Player_Pos_y - scroll_y - pos_y[i] <= 150 &&
		Get_Player_Pos_x - scroll_x - pos_x[i] >= -150 && Get_Player_Pos_x - scroll_x - pos_x[i] <= 150)
	{
		pos_y[i] += 1.0f;
		tuizyuu_flag[i] = true;
		direction_no_enemy[i] = 0;

		//�E
		if ((Get_Player_Pos_x - scroll_x) > pos_x[i] + 30.0f &&
			Get_Player_Pos_y - scroll_y - pos_y[i] >= -150 && Get_Player_Pos_y - scroll_y - pos_y[i] <= 150)
		{
			direction_no_enemy[i] = 3;
		}
		//��
		if ((Get_Player_Pos_x - scroll_x + 30.0f) < pos_x[i] &&
			Get_Player_Pos_y - scroll_y - pos_y[i] >= -150 && Get_Player_Pos_y - scroll_y - pos_y[i] <= 150)
		{
			direction_no_enemy[i] = 2;
		}

		//��Q�����Ǝ~�܂�
		if (MapData_No2_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] <= -1 || MapData_No2_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] >= 2)
		{
			pos_y[i] -= 1.0f;
		}

		//�G�l�~�[���m�Փ˂��Ȃ��悤��
		for (int j = 0; j < ENEMY_MAX3_3; j++)
		{
			if ((pos_y[i] - 30 <= pos_y[j] + 30) && (pos_y[i] + 30 >= pos_y[j] - 30))
			{
				if ((pos_x[i] - 30 <= pos_x[j] + 30) && (pos_x[i] + 30 >= pos_x[j] - 30))
				{
					if (i != j && enemy_state[j] == 0)
					{
						pos_y[i] -= 1.0f;
					}
				}
			}
		}
	}
}


//==============================================================================
// �G�l�~�[���ړ�����
//==============================================================================
void C_Enemy3_3::MoveDown(int i)
{
	pos_y[i] += 1.0f;

	//��Q�����Ǝ~�܂�
	if (MapData_No2_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] <= -1 || MapData_No2_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] >= 2)
	{
		pos_y[i] -= 1.0f;
	}

	//�G�l�~�[���m�Փ˂��Ȃ��悤��
	for (int j = 0; j < ENEMY_MAX3_3; j++)
	{
		if ((pos_y[i] - 30 <= pos_y[j] + 30) && (pos_y[i] + 30 >= pos_y[j] - 30))
		{
			if ((pos_x[i] - 30 <= pos_x[j] + 30) && (pos_x[i] + 30 >= pos_x[j] - 30))
			{
				if (i != j)
				{
					pos_y[i] -= 1.0f;
				}
			}
		}
	}
}


//==============================================================================
// �G�l�~�[��ړ�����
//==============================================================================
void C_Enemy3_3::MoveUp(int i)
{
	pos_y[i] -= 1.0f;

	//��Q�����Ǝ~�܂�
	if (MapData_No2_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] <= -1 || MapData_No2_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] >= 2)
	{
		pos_y[i] += 1.0f;
	}

	//�G�l�~�[���m�Փ˂��Ȃ��悤��
	for (int j = 0; j < ENEMY_MAX3_3; j++)
	{
		if ((pos_y[i] - 30 <= pos_y[j] + 30) && (pos_y[i] + 30 >= pos_y[j] - 30))
		{
			if ((pos_x[i] - 30 <= pos_x[j] + 30) && (pos_x[i] + 30 >= pos_x[j] - 30))
			{
				if (i != j)
				{
					pos_y[i] += 1.0f;
				}
			}
		}
	}
}


//==============================================================================
// �G�l�~�[���ړ�����
//==============================================================================
void C_Enemy3_3::MoveLeft(int i)
{
	pos_x[i] -= 1.0f;

	//��Q�����Ǝ~�܂�
	if (MapData_No2_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] <= -1 || MapData_No2_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] >= 2)
	{
		pos_x[i] += 1.0f;
	}

	//�G�l�~�[���m�Փ˂��Ȃ��悤��
	for (int j = 0; j < ENEMY_MAX3_3; j++)
	{
		if ((pos_y[i] - 30 <= pos_y[j] + 30) && (pos_y[i] + 30 >= pos_y[j] - 30))
		{
			if ((pos_x[i] - 30 <= pos_x[j] + 30) && (pos_x[i] + 30 >= pos_x[j] - 30))
			{
				if (i != j)
				{
					pos_x[i] += 1.0f;
				}
			}
		}
	}
}


//==============================================================================
// �G�l�~�[�E�ړ�����
//==============================================================================
void C_Enemy3_3::MoveRight(int i)
{
	pos_x[i] += 1.0f;

	//��Q�����Ǝ~�܂�
	if (MapData_No2_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] <= -1 || MapData_No2_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] >= 2)
	{
		pos_x[i] -= 1.0f;
	}

	//�G�l�~�[���m�Փ˂��Ȃ��悤��
	for (int j = 0; j < ENEMY_MAX3_3; j++)
	{
		if ((pos_y[i] - 30 <= pos_y[j] + 30) && (pos_y[i] + 30 >= pos_y[j] - 30))
		{
			if ((pos_x[i] - 30 <= pos_x[j] + 30) && (pos_x[i] + 30 >= pos_x[j] - 30))
			{
				if (i != j)
				{
					pos_x[i] -= 1.0f;
				}
			}
		}
	}
}


//==============================================================================
// �G�l�~�[�_���[�W�G�t�F�N�g����
//==============================================================================
void C_Enemy3_3::Damage_Effect()
{
	static int time = 0;
	for (int i = 0; i<ENEMY_MAX3_3; i++)
	{
		if (damage_flag[i] == true)
		{
			if (time == 25)
			{
				damage_flag[i] = false;
				time = 0;
			}
			if (time != 25)
			{
				time++;
			}
		}
	}
}


//==============================================================================
// �G�l�~�[�`�揈��
//==============================================================================
void C_Enemy3_3::DrawProcess(LPDIRECT3DDEVICE9 dev)
{
	//�F���擾
	C_Game_Manager::color = C_Game_Manager::Get_Color();

	//�����A�j���[�V����
	Enemy_Animation(dev);

	//�����A�j���[�V����
	Explosion_Animation(dev);

	for (int i = 0; i < ENEMY_MAX3_3; i++)
	{
		//����
		if (enemy_state[i] == 0)
		{
			//�ۉe�`��
			ShadowDraw(i, C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, dev);

			//HP�Q�[�W�`��
			HPGageDraw(i, C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, 0, dev, t_red_hp_gage);
			HPGageDraw(i, C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, damage[i], dev, t_yellow_hp_gage);

			//�G�l�~�[�`��
			if (i < 10)
			{
				EnemyDraw(i, C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, g_uvTable_Enemy3_3[uvtblidx_Enemy[i]].u, g_uvTable_Enemy3_3[uvtblidx_Enemy[i]].v,
					dev, t_enemy);
			}
			else if (i < 20)
			{
				EnemyDraw(i, C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, g_uvTable_Enemy3_3[uvtblidx_Enemy[i]].u, g_uvTable_Enemy3_3[uvtblidx_Enemy[i]].v,
					dev, t_enemy);
			}
			else if (i < 30)
			{
				EnemyDraw(i, C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, g_uvTable_Enemy3_3[uvtblidx_Enemy[i]].u, g_uvTable_Enemy3_3[uvtblidx_Enemy[i]].v,
					dev, t_enemy);
			}
		}
		//����
		if (enemy_state[i] == 1)
		{
			//HP�Q�[�W�`��
			HPGageDraw(i, C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, 0, dev, t_red_hp_gage);
			HPGageDraw(i, C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, damage[i], dev, t_yellow_hp_gage);
			EnemyDraw(i, C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, g_uvTable_Explosion3_3[uvtblidx_Explosion[i]].u, g_uvTable_Explosion3_3[uvtblidx_Explosion[i]].v,
				dev, t_explosion);
		}
		//�����S�`��
		if (enemy_state[i] == 2)
		{
			AppleDraw(i, C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, dev, t_apple);
		}
	}
}


//==============================================================================
// �G�l�~�[�A�j���[�V��������
//==============================================================================
void C_Enemy3_3::Enemy_Animation(LPDIRECT3DDEVICE9 dev)
{
	//uvtbl(�G�l�~�[)������
	for (int i = 0; i<ENEMY_MAX3_3; i++)
	{
		uvtblidx_Enemy[i] = g_anim_Enemy3_3[animtblidx_Enemy[i]].no;
	}

	for (int i = 0; i < ENEMY_MAX3_3; i++)
	{
		if (damage_flag[i] == false)
		{
			if (enemy_state[i] == 0)
			{
				if (animtime_Enemy[i] >= 15)
				{
					animtblidx_Enemy[i]++;
					animtime_Enemy[i] = 0;
				}
				else
				{
					if (animtime_Enemy[i] <= 15)
					{
						animtime_Enemy[i]++;
					}
				}
				//�A�j���[�V�����J��Ԃ�
				if (animtblidx_Enemy[i] == 3 && direction_no_enemy[i] == 0)
				{
					animtblidx_Enemy[i] = 0;
				}
				if (animtblidx_Enemy[i] == 6 && direction_no_enemy[i] == 1)
				{
					animtblidx_Enemy[i] = 3;
				}
				if (animtblidx_Enemy[i] == 9 && direction_no_enemy[i] == 2)
				{
					animtblidx_Enemy[i] = 6;
				}
				if (animtblidx_Enemy[i] == 12 && direction_no_enemy[i] == 3)
				{
					animtblidx_Enemy[i] = 9;
				}

				//�A�j���[�V���������`�F���W
				if (direction_no_enemy[i] == 0)
				{
					if (animtblidx_Enemy[i] != 0 && animtblidx_Enemy[i] != 1 && animtblidx_Enemy[i] != 2)
					{
						animtblidx_Enemy[i] = 0;
					}
				}
				if (direction_no_enemy[i] == 1)
				{
					if (animtblidx_Enemy[i] != 3 && animtblidx_Enemy[i] != 4 && animtblidx_Enemy[i] != 5)
					{
						animtblidx_Enemy[i] = 3;
					}
				}
				if (direction_no_enemy[i] == 2)
				{
					if (animtblidx_Enemy[i] != 6 && animtblidx_Enemy[i] != 7 && animtblidx_Enemy[i] != 8)
					{
						animtblidx_Enemy[i] = 6;
					}
				}
				if (direction_no_enemy[i] == 3)
				{
					if (animtblidx_Enemy[i] != 9 && animtblidx_Enemy[i] != 10 && animtblidx_Enemy[i] != 11)
					{
						animtblidx_Enemy[i] = 9;
					}
				}
			}
		}
	}
}


//==============================================================================
// �����A�j���[�V��������
//==============================================================================
void C_Enemy3_3::Explosion_Animation(LPDIRECT3DDEVICE9 dev)
{
	//uvtbl(����)������
	for (int i = 0; i<ENEMY_MAX3_3; i++)
	{
		uvtblidx_Explosion[i] = g_anim_Explosion3_3[animtblidx_Explosion[i]].no;
	}

	for (int i = 0; i < ENEMY_MAX3_3; i++)
	{
		//�����A�j���[�V����
		if (enemy_state[i] == 1)
		{
			if (animtime_Explosion[i] >= 8)
			{
				animtblidx_Explosion[i]++;
				animtime_Explosion[i] = 0;
			}
			else
			{
				if (animtime_Explosion[i] <= 8)
				{
					animtime_Explosion[i]++;
				}
			}
			//�A�j���[�V�����J��Ԃ�
			if (animtblidx_Explosion[i] == 17)
			{
				animtblidx_Explosion[i] = 0;
				animtime_Explosion[i] = 0;
				enemy_state[i] = 2;
			}
		}
	}
}