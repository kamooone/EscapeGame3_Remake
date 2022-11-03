//=============================================================================
//
// エネミーコリジョン処理 [EnemyCollision.cpp]
//
//=============================================================================

#include "C_Player.h"
#include "C_Enemy.h"
#include "C_Sound.h"


//=============================================================================
// エネミー当たり判定処理
//=============================================================================
void C_Player::Enemy_Collision()
{
	//フラッシュカウンター成功成功判定処理
	if (flash_counter == true)
	{
		Counter_Success();
	}

	//フラッシュカウンター失敗
	if (flash_counter == false && damage != 40)
	{
		Counter_Fail();
	}
}


//=============================================================================
// フラッシュカウンター成功判定処理
//=============================================================================
void C_Player::Counter_Success()
{
	//エネミー座標取得
	float* Get_enemy_Pos_x = GetEnemy_Pos_x();
	float* Get_enemy_Pos_y = GetEnemy_Pos_y();

	//エネミーダメージ数取得
	int* Get_enemy_Damage = GetEnemy_Damage();

	//エネミー状態取得
	int* Get_enemy_State = GetEnemy_State();

	//エネミーMAX数取得
	int enemy_max = GetEnemy_Max();

	//エネミーダメージフラグ取得
	bool* Get_enemy_Damage_Flag = GetEnemy_Damage_Flag();

	//エネミーとの当たり判定処理
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

	//エネミーダメージ数＆状態、格納
	StoreEnemy_Parameter(&Get_enemy_Damage[0], &Get_enemy_State[0], &Get_enemy_Damage_Flag[0]);
}


//=============================================================================
// フラッシュカウンター失敗時処理
//=============================================================================
void C_Player::Counter_Fail()
{
	//エネミー座標取得
	float* Get_enemy_Pos_x = GetEnemy_Pos_x();
	float* Get_enemy_Pos_y = GetEnemy_Pos_y();

	//エネミーダメージ数取得
	int* Get_enemy_Damage = GetEnemy_Damage();

	//エネミー状態取得
	int* Get_enemy_State = GetEnemy_State();

	//エネミーMAX数取得
	int enemy_max = GetEnemy_Max();

	//エネミーとの当たり判定処理
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

				//回復アイテム獲得
				if (Get_enemy_State[i] == 2)
				{
					Get_enemy_State[i] = 3;

					//5回復
					if (damage >= 5) { damage -= 5; }
					if (damage <= 4) { damage = 0; }


					C_Sound::PlaySound(SOUND_LABEL_SE_LASER);
				}
			}
		}
	}

	//ダメージエフェクトの時間
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