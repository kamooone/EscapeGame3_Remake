//=============================================================================
//
// プレイヤー弾処理 [Bullet.cpp]
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
// 初期化処理
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
// 終了処理
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
// 弾更新処理
//==============================================================================
void C_Bullet::UpdateProcess()
{
	//現在のステージナンバー取得
	int world_no = C_Select::Get_World_No();
	C_Game_Manager::stage_no = Get_Stage_No();

	//弾位置座標指定
	BulletPos();

	//弾移動処理
	BulletMove();

	//弾とエネミーの当たり判定
	if (world_no == 1 && (stage_no == 2 || stage_no == 3))
	{
		BulletCollision();
	}
	if (world_no >= 2 && (stage_no == 2 || stage_no == 3 || stage_no == 4))
	{
		BulletCollision();
	}

	//弾とボスの当たり判定
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
// 弾描画処理
//==============================================================================
void C_Bullet::DrawProcess(LPDIRECT3DDEVICE9 dev)
{
	//色情報取得
	C_Game_Manager::color = Get_Color();

	//発射している弾だけ描画
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (bullet_fire[i] == true)
		{
			BulletDraw(i, dev);
		}
	}
}


//==============================================================================
// 弾発射位置座標指定処理
//==============================================================================
void C_Bullet::BulletPos()
{
	//プレイヤー位置情報取得
	float Get_Player_Pos_x = C_Player::Get_Player_Pos_x();
	float Get_Player_Pos_y = C_Player::Get_Player_Pos_y();

	//プレイヤーの向き情報取得
	int direction_no = C_Player::Get_Direction_No();

	//プレイヤーの弾発射フラグ取得
	bool fire_trigger = C_Player::Get_Fire_Trigger();
	
	if (fire_trigger == true)
	{
		for (int i = 0; i < BULLET_MAX; i++)
		{
			//各弾の発射中か否かを判定
			if (bullet_fire[i] == false)
			{
				bullet_fire[i] = true;//弾発射

				switch (direction_no)
				{
					//発射する位置(向き)
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
// 弾移動処理
//==============================================================================
void C_Bullet::BulletMove()
{
	//弾の移動処理
	for (int i = 0; i < BULLET_MAX; i++)
	{
		//弾が発射中なら
		if (bullet_fire[i] == true)
		{
			//発射する位置により、移動する方向が異なる。
			switch (bullet_direction[i])
			{
			case DIRECTION_DOWN:
				pos_y[i] += 6;//弾の移動
				break;
			case DIRECTION_UP:
				pos_y[i] -= 6;//弾の移動
				break;
			case DIRECTION_LEFT:
				pos_x[i] -= 6;//弾の移動
				break;
			case DIRECTION_RIGHT:
				pos_x[i] += 6;//弾の移動
				break;
			}

			//弾消滅(画面外 (600 400))
			if (pos_x[i] <= 0 || pos_x[i] >= 570.0f || pos_y[i] <= 10 || pos_y[i] >= 380.0f)
			{
				bullet_fire[i] = false;
			}
		}
	}
}


//==============================================================================
// 弾とエネミー当たり判定処理
//==============================================================================
void C_Bullet::BulletCollision()
{
	//エネミー座標取得
	float* Get_enemy_Pos_x = C_Player::GetEnemy_Pos_x();
	float* Get_enemy_Pos_y = C_Player::GetEnemy_Pos_y();

	//エネミーダメージ数取得
	int* Get_enemy_Damage = C_Player::GetEnemy_Damage();

	//エネミー状態取得
	int* Get_enemy_State = C_Player::GetEnemy_State();

	//エネミーダメージフラグ取得
	bool* Get_enemy_Damage_Flag = C_Player::GetEnemy_Damage_Flag();

	//エネミーMAX数取得
	int enemy_max = C_Player::GetEnemy_Max();

	//弾の当たり判定
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

	//エネミーダメージ数＆状態＆ダメージフラグ、格納
	C_Player::StoreEnemy_Parameter(&Get_enemy_Damage[0], &Get_enemy_State[0], &Get_enemy_Damage_Flag[0]);
}


//==============================================================================
// 弾とボス当たり判定処理
//==============================================================================
void C_Bullet::BulletBossCollision()
{
	//ボス座標取得
	float Get_BossPos_x = C_Boss::Get_BossPos_x();
	float Get_BossPos_y = C_Boss::Get_BossPos_y();

	//ボスダメージ数取得
	int Get_Boss_Damage = C_Boss::Get_Boss_Damage();

	//ボスダメージフラグ取得
	bool Get_Boss_Damage_Flag = C_Boss::Get_Boss_Damage_Flag();

	//エネミー状態取得
	int Get_Boss_State = C_Boss::Get_Boss_State();
	
	//弾の当たり判定
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

	//与えたダメージ格納
	C_Boss::Store_Boss_Damage(Get_Boss_Damage);//参照渡し

	//ダメージフラグ格納
	C_Boss::Store_Boss_Damage_Flag(Get_Boss_Damage_Flag);//参照渡し

	//ボス状態判定格納
	C_Boss::Store_Boss_State(Get_Boss_State);//参照渡し
}