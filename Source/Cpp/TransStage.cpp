//=============================================================================
//
// ステージ遷移処理 [TransStage.cpp]
//
//=============================================================================

#include "C_Player.h"
#include "C_Select.h"
#include "C_Sound.h"


//=============================================================================
// ステージ遷移フラグ処理
//=============================================================================
void C_Player::TransStage_Flag()
{
	//現在のワールドナンバー取得
	int world_no = C_Select::Get_World_No();
	C_Game_Manager::stage_no = C_Game_Manager::Get_Stage_No();


	//以下、ステージ遷移判定処理
	switch (stage_no)
	{
	case 1:
		C_Player::Trans_Judge1();

		break;

	case 2:
		if (world_no <= 2) { C_Player::Trans_Judge1(); }
		if (world_no >= 3) { C_Player::Trans_Judge2(); }

		break;

	case 3:
		C_Player::Trans_Judge2();

		break;

	case 4:
		if (world_no == 1) { C_Player::Trans_Judge1(); }
		if (world_no >= 2) { C_Player::Trans_Judge2(); }

		break;

	case 5:
		C_Player::Trans_Judge1();

		break;
	}
}


//=============================================================================
// ステージ遷移判定1(小マップ)
//=============================================================================
void C_Player::Trans_Judge1()
{
	// ステージ戻る======================================================================
	if (MapData_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 5 &&
		C_Game_Manager::trans_flag == false)
	{
		//遷移フラグをtrueに(各種アップデートを止める)
		Store_Trans_Flag(C_Game_Manager::trans_flag = true);

		//遷移後のステージナンバー格納
		Store_Backup_Stage_No(C_Game_Manager::stage_no - 1);
	}

	// ステージ進む======================================================================
	if (MapData_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 9 &&
		C_Game_Manager::trans_flag == false)
	{
		//遷移フラグをtrueに(各種アップデートを止める)
		Store_Trans_Flag(C_Game_Manager::trans_flag = true);

		//遷移後のステージナンバー格納
		Store_Backup_Stage_No(C_Game_Manager::stage_no + 1);
	}

	// エンディングへ======================================================================
	if (MapData_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 8 &&
		C_Game_Manager::trans_flag == false)
	{
		//フェードアウト処理
		if (C_Game_Manager::color != 0)
		{
			C_Game_Manager::color--;
		}
		if (C_Game_Manager::color == 0)
		{
			//ゲーム初期化処理
			Reset_Process();

			game_state_no = 4;
			C_Game_Manager::Store_Game_State_No(game_state_no);
		}

		Store_Color(C_Game_Manager::color);
	}
}


//=============================================================================
// ステージ遷移判定2(大マップ)
//=============================================================================
void C_Player::Trans_Judge2()
{
	// ステージ戻る======================================================================
	if (MapData_No2_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 5 &&
		C_Game_Manager::trans_flag == false)
	{
		//遷移フラグをtrueに(各種アップデートを止める)
		Store_Trans_Flag(C_Game_Manager::trans_flag = true);

		//遷移後のステージナンバー格納
		Store_Backup_Stage_No(C_Game_Manager::stage_no - 1);
	}

	// ステージ進む======================================================================
	if (MapData_No2_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 9 &&
		C_Game_Manager::trans_flag == false)
	{
		//遷移フラグをtrueに(各種アップデートを止める)
		Store_Trans_Flag(C_Game_Manager::trans_flag = true);

		//遷移後のステージナンバー格納
		Store_Backup_Stage_No(C_Game_Manager::stage_no + 1);
	}
}


//=============================================================================
// ステージ遷移処理
//=============================================================================
void C_Player::TransStage()
{
	//現在のワールドナンバー取得
	int world_no = C_Select::Get_World_No();
	C_Game_Manager::stage_no = C_Game_Manager::Get_Stage_No();

	static int trans_time = 0;             //画面遷移までの時間
	static bool double_prevention = false; //二重防止

    //遷移開始
	if (C_Game_Manager::trans_flag == true)
	{
		//ステージ遷移処理終了
		if (trans_time == 100 && C_Game_Manager::trans_flag == true)
		{
			trans_time = 0;

			//遷移フラグをfalseに(各種アップデート再開)
			Store_Trans_Flag(C_Game_Manager::trans_flag = false);

			double_prevention = true;
		}

		if (trans_time != 100) { trans_time++; }

		//フェードイン処理
		if (C_Game_Manager::color != 255 && trans_time >= 97)
		{
			Store_Color(C_Game_Manager::color += 85);

			//遷移後のステージナンバー取得
			C_Game_Manager::stage_no = C_Game_Manager::backup_stage_no;
			stage_sound = true;

			//部屋に遷移時の処理
			if (C_Game_Manager::stage_no == 1)
			{
				C_Game_Manager::scroll_x = -200;
				C_Game_Manager::scroll_y = -200;
				pos_x = 470.0f;
				pos_y = 360.0f;
				direction_no = 1;
			}

			//以下、ワールドごとの遷移処理
			switch (world_no)
			{
			case 1:
				TransStage_World1();

				break;

			case 2:
				TransStage_World2();

				break;

			case 3:
				TransStage_World3();

				break;
			}
		}

		//フェードアウト処理
		if (C_Game_Manager::color != 0 && trans_time <= 60)
		{
			Store_Color(C_Game_Manager::color -= 15);
		}

		//ステージナンバーリセット(画面を暗転するため)
		if (C_Game_Manager::color == 0)
		{
			if (stage_sound == true)
			{
				C_Sound::PlaySound(SOUND_LABEL_SE_WARP);//決定音
			}
			stage_sound = false;
			C_Game_Manager::stage_no = 0;
		}
	}
}


//=============================================================================
// ワールド1画面遷移処理
//=============================================================================
void C_Player::TransStage_World1()
{
	// 1_2へ遷移======================================================================
	if (C_Game_Manager::stage_no == 2 && MapData_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 9)
	{
		C_Game_Manager::scroll_x = -100;
		C_Game_Manager::scroll_y = -200;
		pos_x = 300.0f;
		pos_y = 350.0f;
		direction_no = 1;
	}
	// 1_2へ遷移======================================================================
	if (C_Game_Manager::stage_no == 2 && MapData_No2_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 5)
	{
		C_Game_Manager::scroll_x = -100;
		C_Game_Manager::scroll_y = -0;
		pos_x = 300.0f;
		pos_y = 30.0f;
		direction_no = 0;
	}

	// 1_3へ遷移======================================================================
	if (C_Game_Manager::stage_no == 3 && MapData_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 9)
	{
		C_Game_Manager::scroll_x = -600;
		C_Game_Manager::scroll_y = -600;
		pos_x = 500.0f;
		pos_y = 350.0f;
		direction_no = 1;
	}
	// 1_3へ遷移======================================================================
	if (C_Game_Manager::stage_no == 3 && MapData_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 5)
	{
		C_Game_Manager::scroll_x = -305;
		C_Game_Manager::scroll_y = 0;
		pos_x = 295.0f;
		pos_y = 30.0f;
		direction_no = 0;
	}

	// 1_4へ遷移======================================================================
	if (C_Game_Manager::stage_no == 4 && MapData_No2_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 9)
	{
		C_Game_Manager::scroll_x = -100;
		C_Game_Manager::scroll_y = -200;
		pos_x = 300.0f;
		pos_y = 350.0f;
		direction_no = 1;
	}
}


//=============================================================================
// ワールド2画面遷移処理
//=============================================================================
void C_Player::TransStage_World2()
{
	// 2_2へ遷移======================================================================
	if (C_Game_Manager::stage_no == 2 && MapData_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 9)
	{
		C_Game_Manager::scroll_x = -100;
		C_Game_Manager::scroll_y = -200;
		pos_x = 300.0f;
		pos_y = 350.0f;
		direction_no = 1;
	}
	// 2_2へ遷移======================================================================
	if (C_Game_Manager::stage_no == 2 && MapData_No2_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 5)
	{
		C_Game_Manager::scroll_x = -180;
		C_Game_Manager::scroll_y = 0;
		pos_x = 550.0f;
		pos_y = 200.0f;
		direction_no = 2;
	}

	// 2_3へ遷移======================================================================
	if (C_Game_Manager::stage_no == 3 && MapData_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 9)
	{
		C_Game_Manager::scroll_x = 0;
		C_Game_Manager::scroll_y = 0;
		pos_x = 50.0f;
		pos_y = 60.0f;
		direction_no = 3;
	}
	// 2_3へ遷移======================================================================
	if (C_Game_Manager::stage_no == 3 && MapData_No2_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 5)
	{
		C_Game_Manager::scroll_x = -600;
		C_Game_Manager::scroll_y = 0;
		pos_x = 425.0f;
		pos_y = 30.0f;
		direction_no = 0;
	}

	// 2_4へ遷移======================================================================
	if (C_Game_Manager::stage_no == 4 && MapData_No2_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 9)
	{
		C_Game_Manager::scroll_x = -600;
		C_Game_Manager::scroll_y = -600;
		pos_x = 475.0f;
		pos_y = 350.0f;
		direction_no = 1;
	}
	// 2_4へ遷移======================================================================
	if (C_Game_Manager::stage_no == 4 && MapData_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 5)
	{
		C_Game_Manager::scroll_x = -250;
		C_Game_Manager::scroll_y = 0;
		pos_x = 250.0f;
		pos_y = 30.0f;
		direction_no = 0;
	}

	// 2_5へ遷移======================================================================
	if (C_Game_Manager::stage_no == 5 && MapData_No2_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 9)
	{
		C_Game_Manager::scroll_x = -100;
		C_Game_Manager::scroll_y = -200;
		pos_x = 300.0f;
		pos_y = 350.0f;
		direction_no = 1;
	}
}


//=============================================================================
// ワールド3画面遷移処理
//=============================================================================
void C_Player::TransStage_World3()
{
	// 3_2へ遷移======================================================================
	if (C_Game_Manager::stage_no == 2 && MapData_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 9)
	{
		C_Game_Manager::scroll_x = -200;
		C_Game_Manager::scroll_y = 0;
		pos_x = 300.0f;
		pos_y = 20.0f;
		direction_no = 0;
	}
	// 3_2へ遷移======================================================================
	if (C_Game_Manager::stage_no == 2 && MapData_No2_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 5)
	{
		C_Game_Manager::scroll_x = -580;
		C_Game_Manager::scroll_y = -600;
		pos_x = 520.0f;
		pos_y = 340.0f;
		direction_no = 1;
	}

	// 3_3へ遷移======================================================================
	if (C_Game_Manager::stage_no == 3 && MapData_No2_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 9)
	{
		C_Game_Manager::scroll_x = 0;
		C_Game_Manager::scroll_y = 0;
		pos_x = 100.0f;
		pos_y = 20.0f;
		direction_no = 0;
	}
	// 3_3へ遷移======================================================================
	if (C_Game_Manager::stage_no == 3 && MapData_No2_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 5)
	{
		C_Game_Manager::scroll_x = 0;
		C_Game_Manager::scroll_y = -500;
		pos_x = 40.0f;
		pos_y = 200.0f;
		direction_no = 3;
	}

	// 3_4へ遷移======================================================================
	if (C_Game_Manager::stage_no == 4 && MapData_No2_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 9)
	{
		C_Game_Manager::scroll_x = -600;
		C_Game_Manager::scroll_y = -200;
		pos_x = 560.0f;
		pos_y = 200.0f;
		direction_no = 2;
	}
	// 3_4へ遷移======================================================================
	if (C_Game_Manager::stage_no == 4 && MapData_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 5)
	{
		C_Game_Manager::scroll_x = -600;
		C_Game_Manager::scroll_y = 0;
		pos_x = 440.0f;
		pos_y = 30.0f;
		direction_no = 0;
	}

	// 3_5へ遷移======================================================================
	if (C_Game_Manager::stage_no == 5 && MapData_No2_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 9)
	{
		C_Game_Manager::scroll_x = -100;
		C_Game_Manager::scroll_y = -200;
		pos_x = 300.0f;
		pos_y = 350.0f;
		direction_no = 1;
	}
}