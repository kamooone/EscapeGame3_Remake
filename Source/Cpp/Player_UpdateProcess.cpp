//=============================================================================
//
// プレイヤー更新処理 [Player_UpdateProcess.cpp]
//
//=============================================================================

#include "C_Player.h"
#include "C_Title.h"
#include "C_Select.h"
#include "C_Game.h"
#include "C_Input.h"
#include "C_Sound.h"


//=============================================================================
// プレイヤー移動処理1
//=============================================================================
void C_Player::Player_Move1()
{
	if (C_Game_Manager::trans_flag == false)
	{
		/*位置座標をを20で割ると現在位置が求まる。その位置とマップデータ二次元配列の数字と照らし合わせて当たり判定を取る*/
		/*座標番号が一桁(0以外)のところだけ移動*/

		Up_Move1();

		Down_Move1();

		Left_Move1();

		Right_Move1();

		//足音を鳴らす
		Footsteps();
	}
}


//=============================================================================
// 上移動1
//=============================================================================
void C_Player::Up_Move1()
{
	if ((C_Input::GetKey(SQUARE_KEY) || C_Input::GetKeyboardPress(DIK_W)))
	{
		direction_no = 1;//上向き
		key_push = true;

		//移動
		if (pos_y <= 200 && C_Game_Manager::scroll_y <= 0)
		{
			C_Game_Manager::scroll_y += 2.0f;
		}
		else if (pos_y >= 200 || (C_Game_Manager::scroll_y >= 200 || pos_y <= 200))
		{
			pos_y -= 2.0f;
		}

		//オブジェクト等に衝突時
		if (MapData_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] <= -1)
		{
			pos_y += 2.0f;
		}
	}
}


//=============================================================================
// 下移動1
//=============================================================================
void C_Player::Down_Move1()
{
	if ((C_Input::GetKey(0x00F2) || C_Input::GetKeyboardPress(DIK_S)))
	{
		direction_no = 0;//下向き
		key_push = true;

		//移動
		if (pos_y >= 200 && C_Game_Manager::scroll_y >= -200)
		{
			C_Game_Manager::scroll_y -= 2.0f;
		}
		else if (pos_y <= 200 || C_Game_Manager::scroll_y <= -200)
		{
			pos_y += 2.0f;
		}

		//オブジェクト等に衝突時
		if (MapData_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] <= -1)
		{
			pos_y -= 2.0f;
		}
	}
}


//=============================================================================
// 左移動1
//=============================================================================
void C_Player::Left_Move1()
{
	if ((C_Input::GetKey(0x00F3) || C_Input::GetKeyboardPress(DIK_A)))
	{
		direction_no = 2;//左向き
		key_push = true;

		//移動
		if (C_Game_Manager::scroll_x <= 0 && pos_x <= 300)
		{
			C_Game_Manager::scroll_x += 2.0f;
		}
		else if (pos_x >= 300 || C_Game_Manager::scroll_x >= 0)
		{
			pos_x -= 2.0f;
		}

		//オブジェクト等に衝突時
		if (MapData_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] <= -1)
		{
			pos_x += 2.0f;
		}
	}
}


//=============================================================================
// 右移動1
//=============================================================================
void C_Player::Right_Move1()
{
	if ((C_Input::GetKey(0x00F4) || C_Input::GetKeyboardPress(DIK_D)))
	{
		direction_no = 3;//右向き
		key_push = true;

		//移動
		if (C_Game_Manager::scroll_x >= -200 && pos_x >= 300)
		{
			C_Game_Manager::scroll_x -= 2.0f;
		}
		else if (pos_x <= 300 || C_Game_Manager::scroll_x <= -200)
		{
			pos_x += 2.0f;
		}

		//オブジェクト等に衝突時
		if (MapData_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] <= -1)
		{
			pos_x -= 2.0f;
		}
	}
}


//=============================================================================
// プレイヤー移動処理2
//=============================================================================
void C_Player::Player_Move2()
{
	if (C_Game_Manager::trans_flag == false)
	{
		Up_Move2();

		Down_Move2();

		Left_Move2();

		Right_Move2();

		//足音を鳴らす
		Footsteps();
	}
}


//=============================================================================
// 上移動2
//=============================================================================
void C_Player::Up_Move2()
{
	if ((C_Input::GetKey(0x00F1) || C_Input::GetKeyboardPress(DIK_W)))
	{
		direction_no = 1;//上向き
		key_push = true;

		//移動
		if (pos_y <= 200 && C_Game_Manager::scroll_y <= 0)
		{
			C_Game_Manager::scroll_y += 2.0f;
		}
		else if (pos_y >= 200 || (C_Game_Manager::scroll_y >= 200 || pos_y <= 200))
		{
			pos_y -= 2.0f;
		}

		//オブジェクト等に衝突時
		if (MapData_No2_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] <= -1)
		{
			pos_y += 2.0f;
		}
	}
}


//=============================================================================
// 下移動2
//=============================================================================
void C_Player::Down_Move2()
{
	if ((C_Input::GetKey(0x00F2) || C_Input::GetKeyboardPress(DIK_S)))
	{
		direction_no = 0;//下向き
		key_push = true;

		//移動
		if (pos_y >= 200 && C_Game_Manager::scroll_y >= -600)
		{
			C_Game_Manager::scroll_y -= 2.0f;
		}
		else if (pos_y <= 200 || C_Game_Manager::scroll_y <= -600)
		{
			pos_y += 2.0f;
		}

		//オブジェクト等に衝突時
		if (MapData_No2_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] <= -1)
		{
			pos_y -= 2.0f;
		}
	}
}


//=============================================================================
// 左移動2
//=============================================================================
void C_Player::Left_Move2()
{
	if ((C_Input::GetKey(0x00F3) || C_Input::GetKeyboardPress(DIK_A)))
	{
		direction_no = 2;//左向き
		key_push = true;

		//移動
		if (C_Game_Manager::scroll_x <= 0 && pos_x <= 300)
		{
			C_Game_Manager::scroll_x += 2.0f;
		}
		else if (pos_x >= 300 || C_Game_Manager::scroll_x >= 0)
		{
			pos_x -= 2.0f;
		}

		//オブジェクト等に衝突時
		if (MapData_No2_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] <= -1)
		{
			pos_x += 2.0f;
		}
	}
}


//=============================================================================
// 右移動2
//=============================================================================
void C_Player::Right_Move2()
{
	if ((C_Input::GetKey(0x00F4) || C_Input::GetKeyboardPress(DIK_D)))
	{
		direction_no = 3;//右向き
		key_push = true;

		//移動
		if (C_Game_Manager::scroll_x >= -600 && pos_x >= 300)
		{
			C_Game_Manager::scroll_x -= 2.0f;
		}
		else if (pos_x <= 300 || C_Game_Manager::scroll_x <= -600)
		{
			pos_x += 2.0f;
		}

		//オブジェクト等に衝突時
		if (MapData_No2_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] <= -1)
		{
			pos_x -= 2.0f;
		}
	}
}


//=============================================================================
// 足音処理
//=============================================================================
void C_Player::Footsteps()
{
	static int walk_sound_time = 0;

	//足音を鳴らす
	if (key_push == true)
	{
		walk_sound_time++;
		if (walk_sound_time == 15)
		{
			C_Sound::PlaySound(SOUND_LABEL_SE_WALK);
		}
		if (walk_sound_time == 15)
		{
			walk_sound_time = 0;
		}
	}
}


//=============================================================================
// ベッド回復処理
//=============================================================================
void C_Player::HP_Recovery()
{
	if ((C_Input::GetKeyboardTrigger(DIK_I) || C_Input::GetKeyDown(0x0003)) &&
		MapData_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 0)
	{
		C_Sound::PlaySound(SOUND_LABEL_SE_GUARD);
		damage = 0;
	}
}


//=============================================================================
// 弾発射開始処理
//=============================================================================
void C_Player::Fire_Trigger_Process()
{
	//現在のワールドナンバー取得
	int world_no = C_Select::Get_World_No();

	//マニュアル表示中か否か
	bool manual_flag = Get_Manual_Flag();

	if (world_no >= 2) { manual_flag = false; }

	if ((C_Input::GetKeyboardTrigger(DIK_I) || C_Input::GetKeyDown(0x0001)) && fire_trigger == false && manual_flag == false)
	{
		C_Sound::PlaySound(SOUND_LABEL_SE_JUMP);
		fire_trigger = true;
	}
}


//=============================================================================
// フラッシュカウンター発動処理
//=============================================================================
void C_Player::Flash_Counter_Process()
{
	if ((C_Input::GetKeyboardTrigger(DIK_SPACE) || C_Input::GetKeyDown(0x0002)) && flash_counter == false)
	{
		flash_counter = true;
	}
	//フラッシュカウンターの持続時間
	if (flash_counter == true && flash_counter_time <= 10)
	{
		flash_counter_time++;
		flash_counter_color = 0;
	}
	//フラッシュカウンター解除
	if (flash_counter == true && flash_counter_time >= 10)
	{
		flash_counter = false;
		flash_counter_next = 0;
		flash_counter_time = 0;
		flash_counter_color = 255;
	}
}


//=============================================================================
// ゲーム初期化処理処理
//=============================================================================
void C_Player::Game_Reset()
{
	//ゲームオーバー画面に切り替わる際のフェードアウト
	static bool manual_draw_flag = false;

	//フェードアウトの時間
	static int time_cnt = 0;
	static int time = 0;

	direction_no = 0;

	if (metu_sound == true)
	{
		C_Sound::PlaySound(SOUND_LABEL_SE_METU);
		metu_sound = false;
	}

	if (manual_draw_flag == false)
	{
		if (time_cnt != 200)
		{
			time_cnt++;
		}

		if (time_cnt == 200)
		{
			time++;
			if (time == 2)
			{
				C_Game_Manager::color -= 1;
				time = 0;
			}
			if (C_Game_Manager::color == 0)
			{
				manual_draw_flag = true;
				time_cnt = 0;
			}
		}
	}

	if (manual_draw_flag == true)
	{
		Reset_Process();
		manual_draw_flag = false;
		time = 0;
	}
}


//=============================================================================
// パラメータ初期化処理
//=============================================================================
void C_Player::Reset_Process()
{
	//プレイヤーダメージリセット
	damage = 0;

	//ボスダメージリセット
	C_Boss::Store_Boss_Damage(0);

	//ゲームステートリセット
	game_state_no = 1;
	C_Game_Manager::Store_Game_State_No(game_state_no);

	//ステージナンバー格納
	Store_Stage_No(C_Game_Manager::stage_no = 1);
	C_Select::Store_World_No(1);

	//マニュアル表示フラグリセット
	C_Game_Manager::Store_Manual_Flag(C_Game_Manager::manual_flag = false);

	C_Game_Manager::scroll_x = 0.0f;
	C_Game_Manager::scroll_y = 0.0f;
	pos_x = PLAYER_INIT_POS_X, pos_y = PLAYER_INIT_POS_Y;
	Store_Manual_No(C_Game_Manager::manual_no = 1);
	direction_no = 0;
	C_Game_Manager::color = 255;
	C_Sound::StopSound(SOUND_LABEL_SE_METU);
	metu_sound = true;
	flash_counter = false;
	collision_flag = false;
}