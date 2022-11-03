//=============================================================================
//
// ボス処理 [Boss.cpp]
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
// 静的メンバ変数実体化
//*****************************************************************************

//ボスの位置変数を実体化
float C_Boss :: pos_x = BOSS_INIT_POS_X;
float C_Boss :: pos_y = BOSS_INIT_POS_Y;

//ボスダメージ数実体化
int C_Boss :: damage = 0;

//ボスダメージエフェクトフラグ
bool C_Boss::damage_flag = false;

//ボスの生存状態変数を実体化
int C_Boss :: boss_state = 0;



//==============================================================================
// 初期化処理
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
// 終了処理
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
// ボス更新処理
//==============================================================================
void C_Boss::UpdateProcess()
{
	C_Game_Manager::manual_no = Get_Manual_No();

	//現在のステージナンバー取得
	C_Game_Manager::stage_no = Get_Stage_No();
	C_Boss::world_no = C_Select::Get_World_No();

	//プレイヤーダメージ数取得
	int Get_Player_Damage = C_Player::Get_Player_Damage();

	//ボス移動処理
	BossMove();

	//ダメージエフェクト処理
	Damage_Effect();
}


//==============================================================================
// ボス描画処理
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
// ボス移動処理
//==============================================================================
void C_Boss::BossMove()
{
	if (boss_state == 0 && (C_Game_Manager::manual_no >= 5 || (world_no >= 2 && stage_no == 5)))
	{
		if (damage <= 110)
		{
			//ボス第一形態
			BossMove1();
		}
		if (damage >= 111)
		{
			//チュートリアル表示
			if (C_Game_Manager::manual_no == 5 && world_no == 1)
			{
				Store_Manual_No(C_Game_Manager::manual_no = 6);
			}

			//チュートリアル表示中は動作停止
			if (C_Game_Manager::manual_no >= 7 || (world_no >= 2 && stage_no == 5))
			{
				//ボス第二形態
				BossMove2();

				//ボスの弾の当たり判定
				BossBullet_Collision();
			}
		}
	}
}


//==============================================================================
// ボス移動処理1
//==============================================================================
void C_Boss::BossMove1()
{
	//プレイヤー位置情報取得
	float Get_Player_Pos_x = C_Player::Get_Player_Pos_x();
	float Get_Player_Pos_y = C_Player::Get_Player_Pos_y();

	static int atack_start_flag = 0;

	//プレイヤーを標的に自動移動
	if ((Get_Player_Pos_x + C_Game_Manager::scroll_x*-1 <= pos_x - 25.0f) && atack_flag == false)
	{
		pos_x -= 1.5f;//左
	}
	if ((Get_Player_Pos_x + C_Game_Manager::scroll_x*-1 >= pos_x - 25.0f) && atack_flag == false)
	{
		pos_x += 1.5f;//右
	}

	//ボスの攻撃のタイミング(ボスとプレイヤーが直線状になった時)
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

	//攻撃開始
	if (atack_flag == true)
	{
		if (pos_y <= 400.0f) { pos_y += 5; }
	}

	//攻撃終了
	if (pos_y >= 400.0f && atack_flag == true)
	{
		atack_flag = false;
	}

	//攻撃が終わると元の位置に戻る		
	if (pos_y >= BOSS_INIT_POS_Y && atack_flag == false && atack == false)
	{
		pos_y -= 5.0f;
	}
	//元の位置に戻ると再び攻撃可能状態に
	else if (pos_y <= BOSS_INIT_POS_Y && atack_flag == false)
	{
		atack = true;
	}

	//弾を初期化しておく
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
// ボス移動処理2
//==============================================================================
void C_Boss::BossMove2()
{
	//前に出ていたら後ろに下がる
	if (pos_y >= BOSS_INIT_POS_Y) { pos_y -= 5.0f; }


	if (pos_y <= BOSS_INIT_POS_Y)
	{
		//プレイヤーを標的に自動移動
		Targeting_Move();

		Boss_Bullet_Move();
	}
}


//==============================================================================
// プレイヤーを標的に自動移動処理
//==============================================================================
void C_Boss::Targeting_Move()
{
	//プレイヤー位置情報取得
	float Get_Player_Pos_x = C_Player::Get_Player_Pos_x();
	float Get_Player_Pos_y = C_Player::Get_Player_Pos_y();

	static int atack_start_flag = 0;

	if ((Get_Player_Pos_x + C_Game_Manager::scroll_x*-1 <= pos_x - 25.0f))
	{
		pos_x -= 1.5f;//左
	}
	if ((Get_Player_Pos_x + C_Game_Manager::scroll_x*-1 >= pos_x - 25.0f))
	{
		pos_x += 1.5f;//右
	}

	//ボスの攻撃のタイミング(ボスとプレイヤーが直線状になった時)
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
// ボス弾移動処理
//==============================================================================
void C_Boss::Boss_Bullet_Move()
{
	//攻撃開始
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
		//弾が発射中なら
		if (boss_bullet_fire[i] == 1)
		{
			bullet_pos_y[i] += 5;//弾の移動

								 //弾消滅(画面外 (600 400))
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
// ボスダメージエフェクト
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
// ボス通常時描画
//==============================================================================
void C_Boss::State1_Draw(LPDIRECT3DDEVICE9 dev)
{
	//丸影描画
	ShadowDraw(C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, dev);

	//HPゲージ描画
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
		//弾発射モーション
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
		//シールド破壊
		Boss_Shield1Draw(C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, dev, t_boss);

		//ボス弾描画
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
// ボス消滅時描画
//==============================================================================
void C_Boss::State2_Draw(LPDIRECT3DDEVICE9 dev)
{
	static unsigned int animtblidx_Explosion_C_Boss[1] = { 0 };
	static int animtime_Explosion_C_Boss[1] = { 0 };
	unsigned int uvtblidx_Explosion_C_Boss[1];

	uvtblidx_Explosion_C_Boss[0] = g_anim_Explosion_Boss[animtblidx_Explosion_C_Boss[0]].no;

	//爆発アニメーション
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

		//アニメーション繰り返し
		if (animtblidx_Explosion_C_Boss[0] == 17)
		{
			animtblidx_Explosion_C_Boss[0] = 0;
			animtime_Explosion_C_Boss[0] = 0;
			boss_state = 2;
		}
	}

	//爆発
	if (boss_state == 1)
	{
		//HPゲージ描画
		HPGageDraw(C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, 0, dev, t_red_hp_gage);
		HPGageDraw(C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, damage, dev, t_yellow_hp_gage);

		//爆発
		BossDraw(C_Game_Manager::scroll_x, C_Game_Manager::scroll_y, g_uvTable_Explosion_Boss[uvtblidx_Explosion_C_Boss[0]].u,
			g_uvTable_Explosion_Boss[uvtblidx_Explosion_C_Boss[0]].v, dev, t_explosion);
	}
}


//==============================================================================
// ボスの弾の当たり判定
//==============================================================================
void C_Boss::BossBullet_Collision()
{
	//プレイヤー位置情報取得
	float Player_Pos_x = C_Player::Get_Player_Pos_x();
	float Player_Pos_y = C_Player::Get_Player_Pos_y();

	//画面スクロール値取得
	scroll_x = C_Game_Manager::Get_Scroll_x();
	scroll_y = C_Game_Manager::Get_Scroll_y();

	//プレイヤーダメージ数取得
	int Get_Player_Damage = C_Player::Get_Player_Damage();

	//プレイヤーコリジョンフラグ取得
	bool G_collision_flag = C_Player::Get_Collision_Flag();

	//プレイヤーカウンターフラグ取得
	bool Get_Flash_Counter = C_Player::Get_Flash_Counter();

	if (boss_state == 0)
	{
		//弾の当たり判定flag初期化
		for (int i = 0; i < BOSSBULLET_MAX; i++)
		{
			boss_bullet_collision_flag[i] = false;
		}

		//弾の当たり判定処理
		for (int i = 0; i < BOSSBULLET_MAX; i++)
		{
			if ((pos_y + bullet_pos_y[i] + BOSS_HIGHT - 20.0f <= Player_Pos_y + scroll_y*-1 + 25) &&
				(pos_y + bullet_pos_y[i] + BOSS_HIGHT - 50.0f >= Player_Pos_y + scroll_y*-1 - 25))
			{
				if ((pos_x + bullet_pos_x[i] - BOSS_WIDTH / 2 + 30.0f <= Player_Pos_x + scroll_x*-1 + 30) &&
					(pos_x + bullet_pos_x[i] - 30.0f >= Player_Pos_x + scroll_x*-1 - 30))
				{
					//ガード成功
					if (boss_bullet_fire[i] == 1 && boss_bullet_collision_flag[i] == false && Get_Flash_Counter == true)
					{
						C_Sound::PlaySound(SOUND_LABEL_SE_GUARD);
						boss_bullet_collision_flag[i] = true;
						boss_bullet_fire[i] = 2;
					}

					//ガード失敗
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

		//プレイヤーコリジョンフラグ格納
		C_Player::Store_Collision_Flag(G_collision_flag);
	}

	//与えたダメージ格納
	C_Player::Store_Player_Damage(Get_Player_Damage);//参照渡し
}