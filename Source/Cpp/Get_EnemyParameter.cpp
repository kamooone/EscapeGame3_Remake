//=============================================================================
//
// エネミーパラメータ取得 [Get_EnemyPatameter.cpp]
//
//=============================================================================

#include "C_Player.h"
#include "C_Enemy.h"
#include "C_Enemy1.h"
#include "C_Enemy2_1.h"
#include "C_Enemy2_2.h"
#include "C_Enemy2_3.h"
#include "C_Enemy3_1.h"
#include "C_Enemy3_2.h"
#include "C_Enemy3_3.h"
#include "C_Select.h"


//=============================================================================
// エネミーX座標取得
//=============================================================================
float* C_Player::GetEnemy_Pos_x()
{
	//現在のワールドナンバー取得
	int world_no = C_Select::Get_World_No();

	//現在のステージナンバー取得
	C_Game_Manager::stage_no = C_Game_Manager::Get_Stage_No();

	//エネミー座標取得
	float* get_enemy_pos_x = NULL;

	switch (world_no)
	{
	case 1:
		switch (stage_no)
		{
		case 2:
			get_enemy_pos_x = C_Enemy::Get_enemy_Pos_x();
			break;

		case 3:
			get_enemy_pos_x = C_Enemy1::Get_enemy_Pos_x();
			break;
		}
		break;

	case 2:
		switch (stage_no)
		{
		case 2:
			get_enemy_pos_x = C_Enemy2_1::Get_enemy_Pos_x();
			break;

		case 3:
			get_enemy_pos_x = C_Enemy2_2::Get_enemy_Pos_x();
			break;

		case 4:
			get_enemy_pos_x = C_Enemy2_3::Get_enemy_Pos_x();
			break;
		}
		break;

	case 3:
		switch (stage_no)
		{
		case 2:
			get_enemy_pos_x = C_Enemy3_1::Get_enemy_Pos_x();
			break;

		case 3:
			get_enemy_pos_x = C_Enemy3_2::Get_enemy_Pos_x();
			break;

		case 4:
			get_enemy_pos_x = C_Enemy3_3::Get_enemy_Pos_x();
			break;
		}
		break;
	}

	return get_enemy_pos_x;
}


//=============================================================================
// エネミーY座標取得
//=============================================================================
float* C_Player::GetEnemy_Pos_y()
{
	//現在のワールドナンバー取得
	int world_no = C_Select::Get_World_No();

	//現在のステージナンバー取得
	C_Game_Manager::stage_no = C_Game_Manager::Get_Stage_No();

	//エネミー座標取得
	float* get_enemy_pos_y = NULL;

	switch (world_no)
	{
	case 1:
		switch (stage_no)
		{
		case 2:
			get_enemy_pos_y = C_Enemy::Get_enemy_Pos_y();
			break;

		case 3:
			get_enemy_pos_y = C_Enemy1::Get_enemy_Pos_y();
			break;
		}
		break;

	case 2:
		switch (stage_no)
		{
		case 2:
			get_enemy_pos_y = C_Enemy2_1::Get_enemy_Pos_y();
			break;

		case 3:
			get_enemy_pos_y = C_Enemy2_2::Get_enemy_Pos_y();
			break;

		case 4:
			get_enemy_pos_y = C_Enemy2_3::Get_enemy_Pos_y();
			break;
		}
		break;

	case 3:
		switch (stage_no)
		{
		case 2:
			get_enemy_pos_y = C_Enemy3_1::Get_enemy_Pos_y();
			break;

		case 3:
			get_enemy_pos_y = C_Enemy3_2::Get_enemy_Pos_y();
			break;

		case 4:
			get_enemy_pos_y = C_Enemy3_3::Get_enemy_Pos_y();
			break;
		}
		break;
	}

	return get_enemy_pos_y;
}


//=============================================================================
// エネミーダメージ数取得
//=============================================================================
int* C_Player::GetEnemy_Damage()
{
	//現在のワールドナンバー取得
	int world_no = C_Select::Get_World_No();

	//現在のステージナンバー取得
	C_Game_Manager::stage_no = C_Game_Manager::Get_Stage_No();

	//エネミー座標取得
	int* get_enemy_damage = NULL;

	switch (world_no)
	{
	case 1:
		switch (stage_no)
		{
		case 2:
			get_enemy_damage = C_Enemy::Get_enemy_Damage();
			break;

		case 3:
			get_enemy_damage = C_Enemy1::Get_enemy_Damage();
			break;
		}
		break;

	case 2:
		switch (stage_no)
		{
		case 2:
			get_enemy_damage = C_Enemy2_1::Get_enemy_Damage();
			break;

		case 3:
			get_enemy_damage = C_Enemy2_2::Get_enemy_Damage();
			break;

		case 4:
			get_enemy_damage = C_Enemy2_3::Get_enemy_Damage();
			break;
		}
		break;

	case 3:
		switch (stage_no)
		{
		case 2:
			get_enemy_damage = C_Enemy3_1::Get_enemy_Damage();
			break;

		case 3:
			get_enemy_damage = C_Enemy3_2::Get_enemy_Damage();
			break;

		case 4:
			get_enemy_damage = C_Enemy3_3::Get_enemy_Damage();
			break;
		}
		break;
	}

	return get_enemy_damage;
}


//=============================================================================
// エネミーダメージフラグ取得
//=============================================================================
bool* C_Player::GetEnemy_Damage_Flag()
{
	//現在のワールドナンバー取得
	int world_no = C_Select::Get_World_No();

	//現在のステージナンバー取得
	C_Game_Manager::stage_no = C_Game_Manager::Get_Stage_No();

	//エネミー状態取得
	bool* get_enemy_damage_flag = NULL;

	switch (world_no)
	{
	case 1:
		switch (stage_no)
		{
		case 2:
			get_enemy_damage_flag = C_Enemy::Get_enemy_Damage_Flag();
			break;

		case 3:
			get_enemy_damage_flag = C_Enemy1::Get_enemy_Damage_Flag();
			break;
		}
		break;

	case 2:
		switch (stage_no)
		{
		case 2:
			get_enemy_damage_flag = C_Enemy2_1::Get_enemy_Damage_Flag();
			break;

		case 3:
			get_enemy_damage_flag = C_Enemy2_2::Get_enemy_Damage_Flag();
			break;

		case 4:
			get_enemy_damage_flag = C_Enemy2_3::Get_enemy_Damage_Flag();
			break;
		}
		break;

	case 3:
		switch (stage_no)
		{
		case 2:
			get_enemy_damage_flag = C_Enemy3_1::Get_enemy_Damage_Flag();
			break;

		case 3:
			get_enemy_damage_flag = C_Enemy3_2::Get_enemy_Damage_Flag();
			break;

		case 4:
			get_enemy_damage_flag = C_Enemy3_3::Get_enemy_Damage_Flag();
			break;
		}
		break;
	}

	return get_enemy_damage_flag;
}


//=============================================================================
// エネミー状態取得
//=============================================================================
int* C_Player::GetEnemy_State()
{
	//現在のワールドナンバー取得
	int world_no = C_Select::Get_World_No();

	//現在のステージナンバー取得
	C_Game_Manager::stage_no = C_Game_Manager::Get_Stage_No();

	//エネミー状態取得
	int* get_enemy_state = NULL;

	switch (world_no)
	{
	case 1:
		switch (stage_no)
		{
		case 2:
			get_enemy_state = C_Enemy::Get_enemy_State();
			break;

		case 3:
			get_enemy_state = C_Enemy1::Get_enemy_State();
			break;
		}
		break;

	case 2:
		switch (stage_no)
		{
		case 2:
			get_enemy_state = C_Enemy2_1::Get_enemy_State();
			break;

		case 3:
			get_enemy_state = C_Enemy2_2::Get_enemy_State();
			break;

		case 4:
			get_enemy_state = C_Enemy2_3::Get_enemy_State();
			break;
		}
		break;

	case 3:
		switch (stage_no)
		{
		case 2:
			get_enemy_state = C_Enemy3_1::Get_enemy_State();
			break;

		case 3:
			get_enemy_state = C_Enemy3_2::Get_enemy_State();
			break;

		case 4:
			get_enemy_state = C_Enemy3_3::Get_enemy_State();
			break;
		}
		break;
	}

	return get_enemy_state;
}


//=============================================================================
// エネミーMax数取得
//=============================================================================
int C_Player::GetEnemy_Max()
{
	//現在のワールドナンバー取得
	int world_no = C_Select::Get_World_No();

	//現在のステージナンバー取得
	C_Game_Manager::stage_no = C_Game_Manager::Get_Stage_No();

	//エネミーMax数取得
	int get_enemy_max = 0;

	switch (world_no)
	{
	case 1:
		switch (stage_no)
		{
		case 2:
			get_enemy_max = ENEMY_MAX1;
			break;

		case 3:
			get_enemy_max = ENEMY_MAX2;
			break;
		}
		break;

	case 2:
		switch (stage_no)
		{
		case 2:
			get_enemy_max = ENEMY_MAX2_1;
			break;

		case 3:
			get_enemy_max = ENEMY_MAX2_2;
			break;

		case 4:
			get_enemy_max = ENEMY_MAX2_3;
			break;
		}
		break;

	case 3:
		switch (stage_no)
		{
		case 2:
			get_enemy_max = ENEMY_MAX3_1;
			break;

		case 3:
			get_enemy_max = ENEMY_MAX3_2;
			break;

		case 4:
			get_enemy_max = ENEMY_MAX3_3;
			break;
		}
		break;
	}

	return get_enemy_max;
}


//=============================================================================
// エネミーダメージ数＆状態、格納
//=============================================================================
void C_Player::StoreEnemy_Parameter(int get_enemy_damage[], int get_enemy_state[], bool get_enemy_damage_flag[])
{
	//現在のワールドナンバー取得
	int world_no = C_Select::Get_World_No();

	//現在のステージナンバー取得
	C_Game_Manager::stage_no = C_Game_Manager::Get_Stage_No();

	switch (world_no)
	{
	case 1:
		switch (stage_no)
		{
		case 2:
			//与えたダメージ格納
			C_Enemy::Store_Enemy_Damage(&get_enemy_damage[0]);//参照渡し

			//エネミーとの状態判定格納
			C_Enemy::Store_Enemy_State(&get_enemy_state[0]);//参照渡し

			//ダメージフラグ格納
			C_Enemy::Store_Enemy_Damage_Flag(&get_enemy_damage_flag[0]);//参照渡し
			break;

		case 3:
			//与えたダメージ格納
			C_Enemy1::Store_Enemy_Damage(&get_enemy_damage[0]);//参照渡し

			//エネミーとの状態判定格納
			C_Enemy1::Store_Enemy_State(&get_enemy_state[0]);//参照渡し

			//ダメージフラグ格納
			C_Enemy1::Store_Enemy_Damage_Flag(&get_enemy_damage_flag[0]);//参照渡し
			break;
		}
		break;

	case 2:
		switch (stage_no)
		{
		case 2:
			//与えたダメージ格納
			C_Enemy2_1::Store_Enemy_Damage(&get_enemy_damage[0]);//参照渡し

			//エネミーとの状態判定格納
			C_Enemy2_1::Store_Enemy_State(&get_enemy_state[0]);//参照渡し

			//ダメージフラグ格納
			C_Enemy2_1::Store_Enemy_Damage_Flag(&get_enemy_damage_flag[0]);//参照渡し
			break;

		case 3:
			//与えたダメージ格納
			C_Enemy2_2::Store_Enemy_Damage(&get_enemy_damage[0]);//参照渡し

			//エネミーとの状態判定格納
			C_Enemy2_2::Store_Enemy_State(&get_enemy_state[0]);//参照渡し

			//ダメージフラグ格納
			C_Enemy2_2::Store_Enemy_Damage_Flag(&get_enemy_damage_flag[0]);//参照渡し
			break;

		case 4:
			//与えたダメージ格納
			C_Enemy2_3::Store_Enemy_Damage(&get_enemy_damage[0]);//参照渡し

			//エネミーとの状態判定格納
			C_Enemy2_3::Store_Enemy_State(&get_enemy_state[0]);//参照渡し

		    //ダメージフラグ格納
			C_Enemy2_3::Store_Enemy_Damage_Flag(&get_enemy_damage_flag[0]);//参照渡し
			break;
		}
		break;

	case 3:
		switch (stage_no)
		{
		case 2:
			//与えたダメージ格納
			C_Enemy3_1::Store_Enemy_Damage(&get_enemy_damage[0]);//参照渡し

			//エネミーとの状態判定格納
			C_Enemy3_1::Store_Enemy_State(&get_enemy_state[0]);//参照渡し

			//ダメージフラグ格納
			C_Enemy3_1::Store_Enemy_Damage_Flag(&get_enemy_damage_flag[0]);//参照渡し
			break;

		case 3:
			//与えたダメージ格納
			C_Enemy3_2::Store_Enemy_Damage(&get_enemy_damage[0]);//参照渡し

			//エネミーとの状態判定格納
			C_Enemy3_2::Store_Enemy_State(&get_enemy_state[0]);//参照渡し

			//ダメージフラグ格納
			C_Enemy3_2::Store_Enemy_Damage_Flag(&get_enemy_damage_flag[0]);//参照渡し
			break;

		case 4:
			//与えたダメージ格納
			C_Enemy3_3::Store_Enemy_Damage(&get_enemy_damage[0]);//参照渡し

			//エネミーとの状態判定格納
			C_Enemy3_3::Store_Enemy_State(&get_enemy_state[0]);//参照渡し

			//ダメージフラグ格納
			C_Enemy3_3::Store_Enemy_Damage_Flag(&get_enemy_damage_flag[0]);//参照渡し
			break;
		}
		break;
	}
}