//=============================================================================
//
// エネミー処理 [Enemy2_1.cpp]
//
//=============================================================================

#include "C_Enemy2_1.h"
#include "Struct_enemy2_1.h"
#include "C_Player.h"
#include <stdlib.h>
#include <time.h>


//*****************************************************************************
// 静的メンバ変数実体化
//*****************************************************************************
float C_Enemy2_1::pos_x[ENEMY_MAX2_1] = { ENEMY1_1_INIT_POS_X2_1, ENEMY1_2_INIT_POS_X2_1, ENEMY1_3_INIT_POS_X2_1, ENEMY1_4_INIT_POS_X2_1 };
float C_Enemy2_1::pos_y[ENEMY_MAX2_1] = { ENEMY1_1_INIT_POS_Y2_1, ENEMY1_2_INIT_POS_Y2_1, ENEMY1_3_INIT_POS_Y2_1, ENEMY1_4_INIT_POS_Y2_1 };

//エネミーーの向き変数実体化
int C_Enemy2_1::direction_no_enemy[ENEMY_MAX2_1] = { 0 };
//エネミーの生存状態実体化
int C_Enemy2_1::enemy_state[ENEMY_MAX2_1] = { 0 };

//エネミー被ダメージ数実体化
int C_Enemy2_1::damage[ENEMY_MAX2_1] = { 0 };

//エネミーダメージエフェクトフラグ
bool C_Enemy2_1::damage_flag[ENEMY_MAX2_1] = { false };



//==============================================================================
// 初期化処理
//==============================================================================
void C_Enemy2_1::Init(LPDIRECT3DDEVICE9 dev)
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

	for (int i = 0; i<ENEMY_MAX2_1; i++)
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
// 終了処理
//==============================================================================
void C_Enemy2_1::UnInit()
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
void C_Enemy2_1::UpdateProcess()
{
	//マップチップデータ取得
	int* Get_MapData;//一次元配列に格納用
	Get_MapData = C_Mapchip::MapData_Get2();
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
	for (int i = 0; i < ENEMY_MAX2_1; i++)
	{
		if (enemy_state[i] == 0 && damage_flag[i] == false)
		{
			//プレイヤー追従処理
			MoveTuizyu(i);

			if (tuizyuu_flag[i] == false)
			{
				direction_no_enemy[i] = rand() % 4;//0～3のランダム

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
// プレイヤー追従処理処理
//==============================================================================
void C_Enemy2_1::MoveTuizyu(int i)
{
	//プレイヤーの座標を取得
	float Get_Player_Pos_x = C_Player::Get_Player_Pos_x();
	float Get_Player_Pos_y = C_Player::Get_Player_Pos_y();

	//画面スクロール値取得
	scroll_x = C_Game_Manager::Get_Scroll_x();
	scroll_y = C_Game_Manager::Get_Scroll_y();

	TuizyuRight(i, Get_Player_Pos_x, Get_Player_Pos_y, scroll_x, scroll_y);

	TuizyuLeft(i, Get_Player_Pos_x, Get_Player_Pos_y, scroll_x, scroll_y);

	TuizyuUp(i, Get_Player_Pos_x, Get_Player_Pos_y, scroll_x, scroll_y);

	TuizyuDown(i, Get_Player_Pos_x, Get_Player_Pos_y, scroll_x, scroll_y);
}


//==============================================================================
// 右追従処理
//==============================================================================
void C_Enemy2_1::TuizyuRight(int i, float Get_Player_Pos_x, float Get_Player_Pos_y, float scroll_x, float scroll_y)
{
	if (Get_Player_Pos_x - scroll_x - pos_x[i] >= 0 && Get_Player_Pos_x - scroll_x - pos_x[i] <= 150 &&
		Get_Player_Pos_y - scroll_y - pos_y[i] >= -150 && Get_Player_Pos_y - scroll_y - pos_y[i] <= 150)
	{
		pos_x[i] += 1.0f;
		tuizyuu_flag[i] = true;
		direction_no_enemy[i] = 3;

		//障害物だと止まる
		if (MapData_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] <= -1 || MapData_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] >= 2)
		{
			pos_x[i] -= 1.0f;
		}

		//エネミー同士衝突しないように
		for (int j = 0; j < ENEMY_MAX2_1; j++)
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
// 左追従処理
//==============================================================================
void C_Enemy2_1::TuizyuLeft(int i, float Get_Player_Pos_x, float Get_Player_Pos_y, float scroll_x, float scroll_y)
{
	if (Get_Player_Pos_x - scroll_x - pos_x[i] <= 0 && Get_Player_Pos_x - scroll_x - pos_x[i] >= -150 &&
		Get_Player_Pos_y - scroll_y - pos_y[i] >= -150 && Get_Player_Pos_y - scroll_y - pos_y[i] <= 150)
	{
		pos_x[i] -= 1.0f;
		tuizyuu_flag[i] = true;
		direction_no_enemy[i] = 2;

		//障害物だと止まる
		if (MapData_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] <= -1 || MapData_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] >= 2)
		{
			pos_x[i] += 1.0f;
		}

		//エネミー同士衝突しないように
		for (int j = 0; j < ENEMY_MAX2_1; j++)
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
// 上追従処理
//==============================================================================
void C_Enemy2_1::TuizyuUp(int i, float Get_Player_Pos_x, float Get_Player_Pos_y, float scroll_x, float scroll_y)
{
	if (Get_Player_Pos_y - scroll_y - pos_y[i] <= 0 && Get_Player_Pos_y - scroll_y - pos_y[i] >= -150 &&
		Get_Player_Pos_x - scroll_x - pos_x[i] >= -150 && Get_Player_Pos_x - scroll_x - pos_x[i] <= 150)
	{
		pos_y[i] -= 1.0f;
		tuizyuu_flag[i] = true;

		direction_no_enemy[i] = 1;

		//右
		if ((Get_Player_Pos_x - scroll_x) > pos_x[i] + 30.0f &&
			Get_Player_Pos_y - scroll_y - pos_y[i] >= -150 && Get_Player_Pos_y - scroll_y - pos_y[i] <= 150)
		{
			direction_no_enemy[i] = 3;
		}
		//左
		if ((Get_Player_Pos_x - scroll_x + 30.0f) < pos_x[i] &&
			Get_Player_Pos_y - scroll_y - pos_y[i] >= -150 && Get_Player_Pos_y - scroll_y - pos_y[i] <= 150)
		{
			direction_no_enemy[i] = 2;
		}

		//障害物だと止まる
		if (MapData_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] <= -1 || MapData_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] >= 2)
		{
			pos_y[i] += 1.0f;
		}

		//エネミー同士衝突しないように
		for (int j = 0; j < ENEMY_MAX2_1; j++)
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
// 下追従処理
//==============================================================================
void C_Enemy2_1::TuizyuDown(int i, float Get_Player_Pos_x, float Get_Player_Pos_y, float scroll_x, float scroll_y)
{
	if (Get_Player_Pos_y - scroll_y - pos_y[i] >= 0 && Get_Player_Pos_y - scroll_y - pos_y[i] <= 150 &&
		Get_Player_Pos_x - scroll_x - pos_x[i] >= -150 && Get_Player_Pos_x - scroll_x - pos_x[i] <= 150)
	{
		pos_y[i] += 1.0f;
		tuizyuu_flag[i] = true;

		direction_no_enemy[i] = 0;

		//右
		if ((Get_Player_Pos_x - scroll_x) > pos_x[i] + 30.0f &&
			Get_Player_Pos_y - scroll_y - pos_y[i] >= -150 && Get_Player_Pos_y - scroll_y - pos_y[i] <= 150)
		{
			direction_no_enemy[i] = 3;
		}
		//左
		if ((Get_Player_Pos_x - scroll_x + 30.0f) < pos_x[i] &&
			Get_Player_Pos_y - scroll_y - pos_y[i] >= -150 && Get_Player_Pos_y - scroll_y - pos_y[i] <= 150)
		{
			direction_no_enemy[i] = 2;
		}

		//障害物だと止まる
		if (MapData_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] <= -1 || MapData_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] >= 2)
		{
			pos_y[i] -= 1.0f;
		}

		//エネミー同士衝突しないように
		for (int j = 0; j < ENEMY_MAX2_1; j++)
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
// エネミー下移動処理
//==============================================================================
void C_Enemy2_1::MoveDown(int i)
{
	pos_y[i] += 1.0f;

	//障害物だと止まる
	if (MapData_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] <= -1 || MapData_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] >= 2)
	{
		pos_y[i] -= 1.0f;
	}

	//エネミー同士衝突しないように
	for (int j = 0; j < ENEMY_MAX2_1; j++)
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
// エネミー上移動処理
//==============================================================================
void C_Enemy2_1::MoveUp(int i)
{
	pos_y[i] -= 1.0f;

	//障害物だと止まる
	if (MapData_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] <= -1 || MapData_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] >= 2)
	{
		pos_y[i] += 1.0f;
	}

	//エネミー同士衝突しないように
	for (int j = 0; j < ENEMY_MAX2_1; j++)
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
// エネミー左移動処理
//==============================================================================
void C_Enemy2_1::MoveLeft(int i)
{
	pos_x[i] -= 1.0f;

	//障害物だと止まる
	if (MapData_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] <= -1 || MapData_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] >= 2)
	{
		pos_x[i] += 1.0f;
	}

	//エネミー同士衝突しないように
	for (int j = 0; j < ENEMY_MAX2_1; j++)
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
// エネミー右移動処理
//==============================================================================
void C_Enemy2_1::MoveRight(int i)
{
	pos_x[i] += 1.0f;

	//障害物だと止まる
	if (MapData_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] <= -1 || MapData_TwoDim[(int)pos_y[i] / 20][(int)pos_x[i] / 20] >= 2)
	{
		pos_x[i] -= 1.0f;
	}

	//エネミー同士衝突しないように
	for (int j = 0; j < ENEMY_MAX2_1; j++)
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
// エネミーダメージエフェクト処理
//==============================================================================
void C_Enemy2_1::Damage_Effect()
{
	static int time = 0;
	for (int i = 0; i<ENEMY_MAX2_1; i++)
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
void C_Enemy2_1::DrawProcess(LPDIRECT3DDEVICE9 dev)
{
	//色情報取得
	C_Game_Manager::color = C_Game_Manager::Get_Color();

	//生存アニメーション
	Enemy_Animation(dev);

	//爆発アニメーション
	Explosion_Animation(dev);

	for (int i = 0; i < ENEMY_MAX2_1; i++)
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
			EnemyDraw(i, C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, g_uvTable_Enemy2_1[uvtblidx_Enemy[i]].u, g_uvTable_Enemy2_1[uvtblidx_Enemy[i]].v,
				dev, t_enemy);
		}
		//爆発
		if (enemy_state[i] == 1)
		{
			//HPゲージ描画
			HPGageDraw(i, C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, 0, dev, t_red_hp_gage);
			HPGageDraw(i, C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, damage[i], dev, t_yellow_hp_gage);

			//エネミー描画
			EnemyDraw(i, C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, g_uvTable_Explosion2_1[uvtblidx_Explosion[i]].u, g_uvTable_Explosion2_1[uvtblidx_Explosion[i]].v,
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
void C_Enemy2_1::Enemy_Animation(LPDIRECT3DDEVICE9 dev)
{
	//uvtbl(エネミー)初期化
	for (int i = 0; i<ENEMY_MAX2_1; i++)
	{
		uvtblidx_Enemy[i] = g_anim_Enemy2_1[animtblidx_Enemy[i]].no;
	}

	for (int i = 0; i < ENEMY_MAX2_1; i++)
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
				//アニメーション繰り返し
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

				//アニメーション向きチェンジ
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
// 爆発アニメーション処理
//==============================================================================
void C_Enemy2_1::Explosion_Animation(LPDIRECT3DDEVICE9 dev)
{
	//uvtbl(爆発)初期化
	for (int i = 0; i<ENEMY_MAX2_1; i++)
	{
		uvtblidx_Explosion[i] = g_anim_Explosion2_1[animtblidx_Explosion[i]].no;
	}

	for (int i = 0; i < ENEMY_MAX2_1; i++)
	{
		//爆発アニメーション
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