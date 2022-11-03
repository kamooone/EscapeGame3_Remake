//=============================================================================
//
// ゲームマネージャークラス [C_Game_Manager.h]
//
//=============================================================================

#pragma once
#include "Main.h"
#include <vector>


class C_Game_Manager {
private:
	
protected:
	//ゲームステート
	static int game_state_no;

	//現在のステージナンバー
	static int stage_no;

	//現在のステージナンバーバックアップ
	static int backup_stage_no;

	//画面スクロール変数
	static float scroll_x;
	static float scroll_y;

	//カラー値
	static int color;

	//マニュアル表示中か否か
	static bool manual_flag;

	//マニュアル表示ナンバー
	static int manual_no;

	//画面遷移フラグ
	static bool trans_flag;

	//サウンドマネージャー
	static bool room_sound, field_sound, field1_sound;

public:
	//ゲームステート情報格納&取得
	static void Store_Game_State_No(int& store_game_state_no)
	{
		game_state_no = store_game_state_no;
	}
	static int Get_Game_State_No()
	{
		return game_state_no;
	}

	//ステージナンバー格納&取得
	static void Store_Stage_No(int& Store_Stage_No)
	{
		stage_no = Store_Stage_No;
	}
	static int Get_Stage_No()
	{
		return stage_no;
	}

	//バックアップステージナンバー格納(値渡し)
	static void Store_Backup_Stage_No(int Store_Stage_No)
	{
		backup_stage_no = Store_Stage_No;
	}

	//スクロール値格納&取得
	static void Store_Scroll_x(float& x) { scroll_x = x; }
	static void Store_Scroll_y(float& y) { scroll_y = y; }

	static float& Get_Scroll_x() { return scroll_x; }
	static float& Get_Scroll_y() { return scroll_y; }


	//カラー値格納
	static void Store_Color(int store_color) { color = store_color; }
	//カラー値取得
	static int Get_Color() { return color; }


	//マニュアル表示中か否か格納
	static void Store_Manual_Flag(bool& store_manual_flag) { manual_flag = store_manual_flag; }
	//マニュアル表示中か否か取得
	static bool Get_Manual_Flag() { return manual_flag; }


	//マニュアルナンバーフラグ格納
	static void Store_Manual_No(int& store_manual_no) { manual_no = store_manual_no; }
	//マニュアルナンバー取得
	static int Get_Manual_No() { return manual_no; }

	//画面遷移フラグ格納
	static void Store_Trans_Flag(bool& store_trans_flag) { trans_flag = store_trans_flag; }
	//画面遷移フラグ取得
	static bool Get_Trans_Flag() { return trans_flag; }


	//サウンドマネージャー格納
	static void Store_Room_Sound(bool store_flag) { room_sound = store_flag; }
	//サウンドマネージャー取得
	static bool Get_Room_Sound() { return room_sound; }

	//サウンドマネージャー格納
	static void Store_Field_Sound(bool store_flag) { field_sound = store_flag; }
	//サウンドマネージャー取得
	static bool Get_Field_Sound() { return field_sound; }

	//サウンドマネージャー格納
	static void Store_Field1_Sound(bool store_flag) { field1_sound = store_flag; }
	//サウンドマネージャー取得
	static bool Get_Field1_Sound() { return field1_sound; }
};



class C_Mapchip : public C_Game_Manager {
private:
	
protected:
	//テクスチャ
	LPDIRECT3DTEXTURE9	 t_mapchip, t_shadow;

	bool manual = true;

	int row = SCREEN_WIDTH;//行(横)
	int column = SCREEN_HIGHT;//列(縦)

	//マップデータ二次元配列
	int MapData_TwoDim[SCREEN_HIGHT / 20][SCREEN_WIDTH / 20];
	
	//一次元配列に変換
	static int MapData_OneDim[(SCREEN_HIGHT / 20) * (SCREEN_WIDTH / 20)];
	
	//一次元配列に変換バックアップ用
	int MapData_OneDim_Store[(SCREEN_HIGHT / 20) * (SCREEN_WIDTH / 20)];


	
	//マップデータ二次元配列	
	int MapData_No2_TwoDim[1000 / 20][1200 / 20];
	
	//一次元配列に変換
	static int MapData_No2_OneDim[(1000 / 20) * (1200 / 20)];
	
	//一次元配列に変換バックアップ用
	int MapData_No2_OneDim_Store[(1000 / 20) * (1200 / 20)];

public:
	
	static int* MapData_Get1()
	{
		return C_Game_Manager::stage_no == 3 ? MapData_No2_OneDim : MapData_OneDim;
	}

	static int* MapData_Get2()
	{
		return (C_Game_Manager::stage_no == 3 || stage_no == 4) ? MapData_No2_OneDim : MapData_OneDim;
	}

	static int* MapData_Get3()
	{
		return (C_Game_Manager::stage_no == 2 || stage_no == 3 || stage_no == 4) ? MapData_No2_OneDim : MapData_OneDim;
	}
};



class C_Monster : public C_Mapchip {
private:

protected:
	//テクスチャ
	LPDIRECT3DTEXTURE9	 t_enemy, t_explosion, t_red_hp_gage, t_yellow_hp_gage, t_apple;

public:
};