//=============================================================================
//
// �G�l�~�[���� [Enemy1.cpp]
//
//=============================================================================

#include "C_Enemy1.h"
#include "Struct_enemy1.h"
#include "C_Player.h"
#include <stdlib.h>
#include <time.h>


//*****************************************************************************
// �ÓI�����o�ϐ����̉�
//*****************************************************************************
float C_Enemy1 :: pos_x[ENEMY_MAX2] = { ENEMY2_1_INIT_POS_X, ENEMY2_2_INIT_POS_X, ENEMY2_3_INIT_POS_X, ENEMY2_4_INIT_POS_X , ENEMY2_5_INIT_POS_X,
ENEMY2_6_INIT_POS_X, ENEMY2_7_INIT_POS_X, ENEMY2_8_INIT_POS_X, ENEMY2_9_INIT_POS_X, ENEMY2_10_INIT_POS_X,
ENEMY2_11_INIT_POS_X , ENEMY2_12_INIT_POS_X , ENEMY2_13_INIT_POS_X , ENEMY2_14_INIT_POS_X , ENEMY2_15_INIT_POS_X,
ENEMY2_16_INIT_POS_X, ENEMY2_17_INIT_POS_X, ENEMY2_18_INIT_POS_X, ENEMY2_19_INIT_POS_X , ENEMY2_20_INIT_POS_X,
ENEMY2_21_INIT_POS_X, ENEMY2_22_INIT_POS_X, ENEMY2_23_INIT_POS_X, ENEMY2_24_INIT_POS_X, ENEMY2_25_INIT_POS_X,
ENEMY2_26_INIT_POS_X , ENEMY2_27_INIT_POS_X , ENEMY2_28_INIT_POS_X , ENEMY2_29_INIT_POS_X , ENEMY2_30_INIT_POS_X };


float C_Enemy1 :: pos_y[ENEMY_MAX2] = { ENEMY2_1_INIT_POS_Y, ENEMY2_2_INIT_POS_Y, ENEMY2_3_INIT_POS_Y, ENEMY2_4_INIT_POS_Y , ENEMY2_5_INIT_POS_Y,
ENEMY2_6_INIT_POS_Y, ENEMY2_7_INIT_POS_Y, ENEMY2_8_INIT_POS_Y, ENEMY2_9_INIT_POS_Y, ENEMY2_10_INIT_POS_Y,
ENEMY2_11_INIT_POS_Y, ENEMY2_12_INIT_POS_Y, ENEMY2_13_INIT_POS_Y, ENEMY2_14_INIT_POS_Y, ENEMY2_15_INIT_POS_Y,
ENEMY2_16_INIT_POS_Y, ENEMY2_17_INIT_POS_Y, ENEMY2_18_INIT_POS_Y, ENEMY2_19_INIT_POS_Y , ENEMY2_20_INIT_POS_Y,
ENEMY2_21_INIT_POS_Y, ENEMY2_22_INIT_POS_Y, ENEMY2_23_INIT_POS_Y, ENEMY2_24_INIT_POS_Y, ENEMY2_25_INIT_POS_Y,
ENEMY2_26_INIT_POS_Y, ENEMY2_27_INIT_POS_Y, ENEMY2_28_INIT_POS_Y, ENEMY2_29_INIT_POS_Y, ENEMY2_30_INIT_POS_Y };

//�G�l�~�[�[�̌����ϐ������̉�
int C_Enemy1 :: direction_no_enemy[ENEMY_MAX2] = { 0 };

//�G�l�~�[�̐������
int C_Enemy1::enemy_state[ENEMY_MAX2] = { 0 };

//�G�l�~�[��_���[�W�����̉�
int C_Enemy1::damage[ENEMY_MAX2] = { 0 };

//�G�l�~�[�_���[�W�G�t�F�N�g�t���O
bool C_Enemy1::damage_flag[ENEMY_MAX2] = { false };


//==============================================================================
// ����������
//==============================================================================
void C_Enemy1::Init(LPDIRECT3DDEVICE9 dev)
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

	hr = D3DXCreateTextureFromFile(dev, "assets/apple.png", &t_apple);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}
}


//==============================================================================
// �I������
//==============================================================================
void C_Enemy1::UnInit()
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
void C_Enemy1::UpdateProcess()
{
	//�}�b�v�`�b�v�f�[�^�擾
	int* Get_MapData;//�ꎟ���z��Ɋi�[�p
	Get_MapData = C_Mapchip::MapData_Get1();
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
	for (int i = 0; i<ENEMY_MAX2; i++)
	{
		direction_no_enemy[i] = rand() % 4;//0�`3�̃����_��

		if (enemy_state[i] == 0 && damage_flag[i] == false)
		{
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
	}

	Damage_Effect();
}


//==============================================================================
// �G�l�~�[���ړ�����
//==============================================================================
void C_Enemy1::MoveDown(int i)
{
	pos_y[i] += 1.0f;

	//��Q�����Ǝ~�܂�
	if (MapData_No2_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] <= -1 || MapData_No2_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] >= 2)
	{
		pos_y[i] -= 1.0f;
	}

	//�G�l�~�[���m�Փ˂��Ȃ��悤��
	for (int j = 0; j < ENEMY_MAX2; j++)
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


//==============================================================================
// �G�l�~�[��ړ�����
//==============================================================================
void C_Enemy1::MoveUp(int i)
{
	pos_y[i] -= 1.0f;

	//��Q�����Ǝ~�܂�
	if (MapData_No2_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] <= -1 || MapData_No2_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] >= 2)
	{
		pos_y[i] += 1.0f;
	}

	//�G�l�~�[���m�Փ˂��Ȃ��悤��
	for (int j = 0; j < ENEMY_MAX2; j++)
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


//==============================================================================
// �G�l�~�[���ړ�����
//==============================================================================
void C_Enemy1::MoveLeft(int i)
{
	pos_x[i] -= 1.0f;

	//��Q�����Ǝ~�܂�
	if (MapData_No2_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] <= -1 || MapData_No2_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] >= 2)
	{
		pos_x[i] += 1.0f;
	}

	//�G�l�~�[���m�Փ˂��Ȃ��悤��
	for (int j = 0; j < ENEMY_MAX2; j++)
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


//==============================================================================
// �G�l�~�[�E�ړ�����
//==============================================================================
void C_Enemy1::MoveRight(int i)
{
	pos_x[i] += 1.0f;

	//��Q�����Ǝ~�܂�
	if (MapData_No2_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] <= -1 || MapData_No2_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] >= 2)
	{
		pos_x[i] -= 1.0f;
	}

	//�G�l�~�[���m�Փ˂��Ȃ��悤��
	for (int j = 0; j < ENEMY_MAX2; j++)
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


//==============================================================================
// �G�l�~�[�_���[�W�G�t�F�N�g����
//==============================================================================
void C_Enemy1::Damage_Effect()
{
	static int time = 0;
	for (int i = 0; i<ENEMY_MAX2; i++)
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
void C_Enemy1::DrawProcess(LPDIRECT3DDEVICE9 dev)
{
	//�F���擾
	C_Game_Manager::color = C_Game_Manager::Get_Color();

	//�����A�j���[�V����
	Enemy_Animation(dev);

	//�����A�j���[�V����
	Explosion_Animation(dev);

	for (int i = 0; i < ENEMY_MAX2; i++)
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
				EnemyDraw(i, C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, g_uvTable_Enemy1[uvtblidx_Enemy[i]].u, g_uvTable_Enemy1[uvtblidx_Enemy[i]].v,
					dev, t_enemy);
			}
			else if (i < 20)
			{
				EnemyDraw(i, C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, g_uvTable_Enemy2[uvtblidx_Enemy[i]].u, g_uvTable_Enemy2[uvtblidx_Enemy[i]].v,
					dev, t_enemy);
			}
			else if (i < 30)
			{
				EnemyDraw(i, C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, g_uvTable_Enemy3[uvtblidx_Enemy[i]].u, g_uvTable_Enemy3[uvtblidx_Enemy[i]].v,
					dev, t_enemy);
			}
		}
		//����
		if (enemy_state[i] == 1)
		{
			//HP�Q�[�W�`��
			HPGageDraw(i, C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, 0, dev, t_red_hp_gage);
			HPGageDraw(i, C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, damage[i], dev, t_yellow_hp_gage);
			EnemyDraw(i, C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, g_uvTable_Explosion[uvtblidx_Explosion[i]].u, g_uvTable_Explosion[uvtblidx_Explosion[i]].v,
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
void C_Enemy1::Enemy_Animation(LPDIRECT3DDEVICE9 dev)
{
	//uvtbl(�G�l�~�[)������
	for (int i = 0; i<ENEMY_MAX2; i++)
	{
		uvtblidx_Enemy[i] = g_anim_Enemy1[animtblidx_Enemy[i]].no;
	}

	for (int i = 0; i < ENEMY_MAX2; i++)
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
void C_Enemy1::Explosion_Animation(LPDIRECT3DDEVICE9 dev)
{
	//uvtbl(����)������
	for (int i = 0; i<ENEMY_MAX2; i++)
	{
		uvtblidx_Explosion[i] = g_anim_Explosion1[animtblidx_Explosion[i]].no;
	}

	for (int i = 0; i < ENEMY_MAX2; i++)
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