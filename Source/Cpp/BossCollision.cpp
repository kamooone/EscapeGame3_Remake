//=============================================================================
//
// ボスコリジョン処理 [BossCollision.cpp]
//
//=============================================================================

#include "C_Player.h"
#include "C_Boss.h"
#include "C_Sound.h"


//=============================================================================
// ボス当たり判定処理
//=============================================================================
void C_Player::BossCollision()
{
	//ボスの剣の当たり判定(フラッシュガード)
	Boss_Counter_Success();

	//ボスの剣の当たり判定(フラッシュガード失敗)
	Boss_Counter_Fail();
}


//=============================================================================
// ボス戦時フラッシュカウンター成功判定処理
//=============================================================================
void C_Player::Boss_Counter_Success()
{
	//ボス座標取得
	float Get_BossPos_x = C_Boss::Get_BossPos_x();
	float Get_BossPos_y = C_Boss::Get_BossPos_y();

	//ボスダメージ数取得
	int Get_Boss_Damage = C_Boss::Get_Boss_Damage();

	//ボスダメージフラグ取得
	bool Get_Boss_Damage_Flag = C_Boss::Get_Boss_Damage_Flag();

	//ボス状態取得
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

	//与えたダメージ格納
	C_Boss::Store_Boss_Damage(Get_Boss_Damage);//参照渡し

    //ダメージフラグ格納
	C_Boss::Store_Boss_Damage_Flag(Get_Boss_Damage_Flag);//参照渡し

	//ボスの状態判定格納
	C_Boss::Store_Boss_State(Get_Boss_State);//参照渡し
}


//=============================================================================
// ボス戦時フラッシュカウンター失敗時処理
//=============================================================================
void C_Player::Boss_Counter_Fail()
{
	static bool sword = false;

	//ボス座標取得
	float Get_BossPos_x = C_Boss::Get_BossPos_x();
	float Get_BossPos_y = C_Boss::Get_BossPos_y();

	//ボスダメージ数取得
	int Get_Boss_Damage = C_Boss::Get_Boss_Damage();

	//ボスダメージフラグ取得
	bool Get_Boss_Damage_Flag = C_Boss::Get_Boss_Damage_Flag();

	//ボス状態取得
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

	//剣ダメージを受けたら次のダメージ受けるまで一定の間隔を空ける
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

	//ボスと衝突時のダメージエフェクト処理
	Damage_Effect(sword);
}


//=============================================================================
// ボスと衝突時のダメージエフェクト処理
//=============================================================================
void C_Player::Damage_Effect(bool sword)
{
	//ダメージエフェクトの時間
	static int effecttime = 0;

	//剣衝突時のダメージエフェクトの時間
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

	//ボスの弾衝突時のダメージエフェクトの時間
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