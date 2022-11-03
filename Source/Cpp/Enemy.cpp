//=============================================================================
//
// エネミー処理 [Enemy.cpp]
//
//=============================================================================

#include "C_Enemy.h"
#include "Struct_enemy.h"
#include "C_Player.h"
#include <stdlib.h>
#include <time.h>


//*****************************************************************************
// 静的メンバ変数実体化
//*****************************************************************************
float C_Enemy :: pos_x[ENEMY_MAX1] = { ENEMY1_1_INIT_POS_X, ENEMY1_2_INIT_POS_X, ENEMY1_3_INIT_POS_X,
                                       ENEMY1_4_INIT_POS_X , ENEMY1_5_INIT_POS_X, ENEMY1_6_INIT_POS_X };
float C_Enemy:: pos_y[ENEMY_MAX1] = { ENEMY1_1_INIT_POS_Y, ENEMY1_2_INIT_POS_Y, ENEMY1_3_INIT_POS_Y,
                                      ENEMY1_4_INIT_POS_Y , ENEMY1_5_INIT_POS_Y, ENEMY1_6_INIT_POS_Y };

//エネミーーの向き変数実体化
int C_Enemy:: direction_no_enemy[ENEMY_MAX1] = { 0 };

//エネミーの生存状態実体化
int C_Enemy:: enemy_state[ENEMY_MAX1] = { 0 };

//エネミー被ダメージ数実体化
int C_Enemy:: damage[ENEMY_MAX1] = { 0 };

//エネミーダメージエフェクトフラグ
bool C_Enemy:: damage_flag[ENEMY_MAX1] = { false };


//==============================================================================
// 初期化処理
//==============================================================================
void C_Enemy::Init(LPDIRECT3DDEVICE9 dev)
{
	HRESULT hr = D3DXCreateTextureFromFile(dev, "assets/enemy0.png", &t_enemy);
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
// 終了処理
//==============================================================================
void C_Enemy::UnInit()
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

	if (t_apple)
	{
		t_apple->Release();
		t_apple = NULL;
	}
}


//==============================================================================
// エネミー更新処理
//==============================================================================
void C_Enemy::UpdateProcess()
{
	//マップチップデータ取得
	int* Get_MapData;//一次元配列に格納用
	Get_MapData = C_Mapchip::MapData_Get1();

	for (int i = 0; i<SCREEN_HIGHT / 20; i++)
	{
		for (int j = 0; j < SCREEN_WIDTH / 20; j++)
		{
			static int ij = 0;
			MapData_TwoDim[i][j] = Get_MapData[ij];
			if (ij <= 1199) { ij++; }
			if (ij == 1200) { ij = 0; }
		}
	}

	//現在時刻の情報で初期化
	srand((unsigned int)time(NULL));

	//エネミー移動
	for (int i = 0; i<ENEMY_MAX1; i++)
	{
		direction_no_enemy[i] = rand() % 4;//0～3のランダム
	
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
// エネミー下移動処理
//==============================================================================
void C_Enemy::MoveDown(int i)
{
	pos_y[i] += 1.0f;

	//障害物だと止まる
	if (MapData_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] <= -1 || MapData_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] >= 2)
	{
		pos_y[i] -= 1.0f;
	}

	//エネミー同士衝突しないように
	for (int j = 0; j < ENEMY_MAX1; j++)
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
// エネミー上移動処理
//==============================================================================
void C_Enemy::MoveUp(int i)
{
	pos_y[i] -= 1.0f;

	//障害物だと止まる
	if (MapData_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] <= -1 || MapData_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] >= 2)
	{
		pos_y[i] += 1.0f;
	}

	//エネミー同士衝突しないように
	for (int j = 0; j < ENEMY_MAX1; j++)
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
// エネミー左移動処理
//==============================================================================
void C_Enemy::MoveLeft(int i)
{
	pos_x[i] -= 1.0f;

	//障害物だと止まる
	if (MapData_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] <= -1 || MapData_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] >= 2)
	{
		pos_x[i] += 1.0f;
	}

	//エネミー同士衝突しないように
	for (int j = 0; j < ENEMY_MAX1; j++)
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
// エネミー右移動処理
//==============================================================================
void C_Enemy::MoveRight(int i)
{
	pos_x[i] += 1.0f;

	//障害物だと止まる
	if (MapData_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] <= -1 || MapData_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] >= 2)
	{
		pos_x[i] -= 1.0f;
	}

	//エネミー同士衝突しないように
	for (int j = 0; j < ENEMY_MAX1; j++)
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
// エネミーダメージエフェクト処理
//==============================================================================
void C_Enemy::Damage_Effect()
{
	static int time = 0;
	for (int i = 0; i<ENEMY_MAX1; i++)
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
// エネミー描画処理
//==============================================================================
void C_Enemy::DrawProcess(LPDIRECT3DDEVICE9 dev)
{	
	//色情報取得
	C_Game_Manager::color = C_Game_Manager::Get_Color();

	//生存アニメーション
	Enemy_Animation(dev);

	//爆発アニメーション
	Explosion_Animation(dev);

	for (int i = 0; i < ENEMY_MAX1; i++)
	{
		//生存
		if (enemy_state[i] == 0)
		{
			//丸影描画
			ShadowDraw(i, C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, dev);

			//HPゲージ描画
			HPGageDraw(i, C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, 0, dev, t_red_hp_gage);
			HPGageDraw(i, C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, damage[i], dev, t_yellow_hp_gage);

			//エネミー描画
			EnemyDraw(i, C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, g_uvTable_Enemy[uvtblidx_ENEMY[i]].u, g_uvTable_Enemy[uvtblidx_ENEMY[i]].v,
				dev, t_enemy);
		}

		//爆発
		if (enemy_state[i] == 1)
		{
			//HPゲージ描画
			HPGageDraw(i, C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, 0, dev, t_red_hp_gage);
			HPGageDraw(i, C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, damage[i], dev, t_yellow_hp_gage);

			//エネミー描画
			EnemyDraw(i, C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, g_uvTable_Explosion[uvtblidx_Explosion[i]].u, g_uvTable_Explosion[uvtblidx_Explosion[i]].v,
				dev, t_explosion);
		}

		//リンゴ描画
		if (enemy_state[i] == 2)
		{
			AppleDraw(i, C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, dev, t_apple);
		}
	}
}


//==============================================================================
// エネミーアニメーション処理
//==============================================================================
void C_Enemy::Enemy_Animation(LPDIRECT3DDEVICE9 dev)
{
	//uvtbl(エネミー)初期化
	for (int i = 0; i<ENEMY_MAX1; i++)
	{
		uvtblidx_ENEMY[i] = g_anim_Enemy[animtblidx_ENEMY[i]].no;
	}

	//生存アニメーション
	for (int i = 0; i < ENEMY_MAX1; i++)
	{
		if (damage_flag[i] == false && enemy_state[i] == 0)
		{
			//アニメーションの速さ
			if (animtime_ENEMY[i] >= 15)
			{
				animtblidx_ENEMY[i]++;
				animtime_ENEMY[i] = 0;
			}
			else if (animtime_ENEMY[i] <= 15)
			{
				animtime_ENEMY[i]++;
			}

			//アニメーション繰り返し
			if (animtblidx_ENEMY[i] == 3 && direction_no_enemy[i] == 0)
			{
				animtblidx_ENEMY[i] = 0;
			}
			if (animtblidx_ENEMY[i] == 6 && direction_no_enemy[i] == 1)
			{
				animtblidx_ENEMY[i] = 3;
			}
			if (animtblidx_ENEMY[i] == 9 && direction_no_enemy[i] == 2)
			{
				animtblidx_ENEMY[i] = 6;
			}
			if (animtblidx_ENEMY[i] == 12 && direction_no_enemy[i] == 3)
			{
				animtblidx_ENEMY[i] = 9;
			}

			//アニメーション向きチェンジ
			if (direction_no_enemy[i] == 0)
			{
				if (animtblidx_ENEMY[i] != 0 && animtblidx_ENEMY[i] != 1 && animtblidx_ENEMY[i] != 2)
				{
					animtblidx_ENEMY[i] = 0;
				}
			}
			if (direction_no_enemy[i] == 1)
			{
				if (animtblidx_ENEMY[i] != 3 && animtblidx_ENEMY[i] != 4 && animtblidx_ENEMY[i] != 5)
				{
					animtblidx_ENEMY[i] = 3;
				}
			}
			if (direction_no_enemy[i] == 2)
			{
				if (animtblidx_ENEMY[i] != 6 && animtblidx_ENEMY[i] != 7 && animtblidx_ENEMY[i] != 8)
				{
					animtblidx_ENEMY[i] = 6;
				}
			}
			if (direction_no_enemy[i] == 3)
			{
				if (animtblidx_ENEMY[i] != 9 && animtblidx_ENEMY[i] != 10 && animtblidx_ENEMY[i] != 11)
				{
					animtblidx_ENEMY[i] = 9;
				}
			}
		}
	}
}


//==============================================================================
// 爆発アニメーション処理
//==============================================================================
void C_Enemy::Explosion_Animation(LPDIRECT3DDEVICE9 dev)
{
	//uvtbl(爆発)初期化
	for (int i = 0; i<ENEMY_MAX1; i++)
	{
		uvtblidx_Explosion[i] = g_anim_Explosion[animtblidx_Explosion[i]].no;
	}

	//爆発アニメーション
	for (int i = 0; i < ENEMY_MAX1; i++)
	{
		if (enemy_state[i] == 1)
		{
			//アニメーションの速さ
			if (animtime_Explosion[i] >= 8)
			{
				animtblidx_Explosion[i]++;
				animtime_Explosion[i] = 0;
			}
			else if (animtime_Explosion[i] <= 8)
			{
				animtime_Explosion[i]++;
			}

			//アニメーション繰り返し
			if (animtblidx_Explosion[i] == 17)
			{
				animtblidx_Explosion[i] = 0;
				animtime_Explosion[i] = 0;
				enemy_state[i] = 2;
			}
		}
	}
}