//=============================================================================
//
// プレイヤー処理 [Player.cpp]
//
//=============================================================================

#include "C_Player.h"
#include "Struct_Input.h"
#include "Struct_player.h"
#include "C_Select.h"
#include "C_Game.h"


//=============================================================================
// 初期化
//=============================================================================
void C_Player::Init(LPDIRECT3DDEVICE9 dev)
{
	HRESULT hr = D3DXCreateTextureFromFile(dev, "assets/player.png", &t_player);
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

	hr = D3DXCreateTextureFromFile(dev, "assets/controller1.png", &T_controller);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}
}


//=============================================================================
// 解放処理
//=============================================================================
void C_Player::UnInit()
{
	if (t_player)
	{
		t_player->Release();
		t_player = NULL;
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

	if (T_controller)
	{
		T_controller->Release();
		T_controller = NULL;
	}
}


//=============================================================================
// 更新処理
//=============================================================================
void C_Player::UpdateProcess()
{
	//現在のワールドナンバー取得
	int world_no = C_Select::Get_World_No();
	C_Game_Manager::stage_no = C_Game_Manager::Get_Stage_No();

	//ステージ遷移フラグ
	TransStage_Flag();

	//ステージ遷移処理
	TransStage();

	//プレイヤー移動処理
	if (damage < 40 && C_Game_Manager::color >= 240)
	{
		switch (world_no)
		{
		case WORLD_1:
			if (C_Game_Manager::manual_flag == false) { World1_UpdateProcess(); }
			break;

		case WORLD_2:
			World2_UpdateProcess();
			break;

		case WORLD_3:
			World3_UpdateProcess();
			break;
		}

		//画面スクロール値格納
		Store_Scroll_x(C_Game_Manager::scroll_x);
		Store_Scroll_y(C_Game_Manager::scroll_y);

		//ベッドで回復
		if (C_Game_Manager::stage_no == 1) { HP_Recovery(); }

		//弾発射(部屋では弾を発射しない)
		if (C_Game_Manager::trans_flag == false && C_Game_Manager::stage_no != 1)
		{
			Fire_Trigger_Process();
		}

		//フラッシュカウンター発動
		if (collision_flag == false)
		{
			Flash_Counter_Process();
		}

		//プレイヤーコリジョンフラグ格納
		Store_Collision_Flag(collision_flag);

		//ボスの弾を受けたダメージ加算
		C_Player::damage = Get_Player_Damage();
	}

	//ステージナンバー格納
	Store_Stage_No(C_Game_Manager::stage_no);

	//ステージ遷移フラグ格納
	Store_Trans_Flag(C_Game_Manager::trans_flag);


	//ゲームオーバー(タイトルに戻る)
	if (damage >= 40)
	{
		//各パラメータ初期化処理
		Game_Reset();
	}

	Store_Color(C_Game_Manager::color);
}


//=============================================================================
// World1_UpdateProcess
//=============================================================================
void C_Player::World1_UpdateProcess()
{
	//ステージ情報取得
	GetParameter();

	if (C_Game_Manager::stage_no <= 2 || C_Game_Manager::stage_no >= 4)
	{
		Player_Move1();
	}

	if (C_Game_Manager::stage_no == 3)
	{
		Player_Move2();
	}

	Enemy_Collision();

	if (C_Game_Manager::stage_no == 4)
	{
		BossCollision();
	}
}


//=============================================================================
// World2_UpdateProcess
//=============================================================================
void C_Player::World2_UpdateProcess()
{
	//ステージ情報取得
	GetParameter2();

	if (C_Game_Manager::stage_no <= 2 || C_Game_Manager::stage_no == 5)
	{
		Player_Move1();
	}

	if (C_Game_Manager::stage_no == 3 || C_Game_Manager::stage_no == 4)
	{
		Player_Move2();
	}

	Enemy_Collision();

	if (C_Game_Manager::stage_no == 5)
	{
		BossCollision();
	}
}


//=============================================================================
// World3_UpdateProcess
//=============================================================================
void C_Player::World3_UpdateProcess()
{
	//ステージ情報取得
	GetParameter3();

	if (C_Game_Manager::stage_no == 1 || C_Game_Manager::stage_no == 5)
	{
		Player_Move1();
	}

	if (C_Game_Manager::stage_no == 2 || C_Game_Manager::stage_no == 3 || C_Game_Manager::stage_no == 4)
	{
		Player_Move2();
	}

	Enemy_Collision();

	if (C_Game_Manager::stage_no == 5)
	{
		BossCollision();
	}
}


//=============================================================================
// 描画処理(ステージセレクト画面)
//=============================================================================
void C_Player::Select_DrawProcess(LPDIRECT3DDEVICE9 dev)
{
	//ワールドナンバー取得
	int wold_no = C_Select::Get_World_No();

	//アニメーション処理
	Anim_Select();

	switch (wold_no)
	{
	case WORLD_1:
		//プレイヤー描画
		SelectPlayerDraw(-85.0f, -8.0f, g_uvTable[uvtblidx].u, g_uvTable[uvtblidx].v, dev);
		break;

	case WORLD_2:
		//プレイヤー描画
		SelectPlayerDraw(-235.0f, 60.0f, g_uvTable[uvtblidx].u, g_uvTable[uvtblidx].v, dev);
		break;

	case WORLD_3:
		//プレイヤー描画
		SelectPlayerDraw(35.0f, 60.0f, g_uvTable[uvtblidx].u, g_uvTable[uvtblidx].v, dev);
		break;
	}

	C_Game_Manager::color = Get_Color();
}


//=============================================================================
// 描画処理(ゲーム本編)
//=============================================================================
void C_Player::DrawProcess(LPDIRECT3DDEVICE9 dev)
{
	//ワールドナンバー取得
	int wold_no = C_Select::Get_World_No();

	//アニメーション処理
	Anim_Main();

	//丸影描画
	ShadowDraw(dev);

	//HPゲージ描画
	HPGageDraw(0, dev, t_red_hp_gage);
	HPGageDraw(damage, dev, t_yellow_hp_gage);

	//プレイヤー描画
	PlayerDraw(g_uvTable[uvtblidx].u, g_uvTable[uvtblidx].v, dev);

	C_Game_Manager::color = Get_Color();
}


//=============================================================================
// ステージ情報取得
//=============================================================================
void C_Player::GetParameter()
{
	C_Game_Manager::color = C_Game_Manager::Get_Color();

	//現在のステージナンバー取得
	C_Game_Manager::stage_no = C_Game_Manager::Get_Stage_No();

	//ステージ遷移フラグ取得
	C_Game_Manager::trans_flag = C_Game_Manager::Get_Trans_Flag();

	//一次元配列に格納用
	int* Get_MapData = C_Mapchip::MapData_Get1();

	//二次元配列に変換
	for (int i = 0; C_Game_Manager::stage_no == 3 ? i < 1000 / 20 : i < SCREEN_HIGHT / 20; i++)
	{
		for (int j = 0; C_Game_Manager::stage_no == 3 ? j < 1200 / 20 : j < SCREEN_WIDTH / 20; j++)
		{
			static int ij = 0;
			C_Game_Manager::stage_no == 3 ? MapData_No2_TwoDim[i][j] = Get_MapData[ij] : MapData_TwoDim[i][j] = Get_MapData[ij];
			if (C_Game_Manager::stage_no == 3 ? ij <= 2999 : ij <= 1199) { ij++; }
			if (C_Game_Manager::stage_no == 3 ? ij == 3000 : ij == 1200) { ij = 0; }
		}
	}
}


//=============================================================================
// ステージ情報取得2
//=============================================================================
void C_Player::GetParameter2()
{
	C_Game_Manager::color = C_Game_Manager::Get_Color();

	//現在のステージナンバー取得
	C_Game_Manager::stage_no = Get_Stage_No();

	//ステージ遷移フラグ取得
	C_Game_Manager::trans_flag = C_Game_Manager::Get_Trans_Flag();

	//一次元配列に格納用
	int* Get_MapData = C_Mapchip::MapData_Get2();

	//二次元配列に変換
	for (int i = 0; C_Game_Manager::stage_no == 3 || stage_no == 4 ? i < 1000 / 20 : i < SCREEN_HIGHT / 20; i++)
	{
		for (int j = 0; C_Game_Manager::stage_no == 3 || stage_no == 4 ? j < 1200 / 20 : j < SCREEN_WIDTH / 20; j++)
		{
			static int ij = 0;
			C_Game_Manager::stage_no == 3 || stage_no == 4 ? MapData_No2_TwoDim[i][j] = Get_MapData[ij] : MapData_TwoDim[i][j] = Get_MapData[ij];
			if (C_Game_Manager::stage_no == 3 || stage_no == 4 ? ij <= 2999 : ij <= 1199) { ij++; }
			if (C_Game_Manager::stage_no == 3 || stage_no == 4 ? ij == 3000 : ij == 1200) { ij = 0; }
		}
	}
}


//=============================================================================
// ステージ情報取得3
//=============================================================================
void C_Player::GetParameter3()
{
	C_Game_Manager::color = C_Game_Manager::Get_Color();

	//現在のステージナンバー取得
	C_Game_Manager::stage_no = Get_Stage_No();

	//ステージ遷移フラグ取得
	C_Game_Manager::trans_flag = C_Game_Manager::Get_Trans_Flag();

	//一次元配列に格納用
	int* Get_MapData = C_Mapchip::MapData_Get3();

	//二次元配列に変換
	for (int i = 0; C_Game_Manager::stage_no == 2 || stage_no == 3 || stage_no == 4 ? i < 1000 / 20 : i < SCREEN_HIGHT / 20; i++)
	{
		for (int j = 0; C_Game_Manager::stage_no == 2 || stage_no == 3 || stage_no == 4 ? j < 1200 / 20 : j < SCREEN_WIDTH / 20; j++)
		{
			static int ij = 0;
			C_Game_Manager::stage_no == 2 || stage_no == 3 || stage_no == 4 ? MapData_No2_TwoDim[i][j] = Get_MapData[ij] : MapData_TwoDim[i][j] = Get_MapData[ij];
			if (C_Game_Manager::stage_no == 2 || stage_no == 3 || stage_no == 4 ? ij <= 2999 : ij <= 1199) { ij++; }
			if (C_Game_Manager::stage_no == 2 || stage_no == 3 || stage_no == 4 ? ij == 3000 : ij == 1200) { ij = 0; }
		}
	}
}


//=============================================================================
// アニメーション(セレクト画面)
//=============================================================================
void C_Player::Anim_Select()
{
	//表示UV座標
	uvtblidx = g_anim[animtblidx].no;

	//アニメーションの速さ
	static int i = 0;

	if (animtblidx >= 4) { animtblidx = 0; }
	if (i <= 12) { i++; }
	if (i == 12)
	{
		animtblidx++;
		i = 0;
	}

	//アニメーション繰り返し
	if (animtblidx == 4 && direction_no == 0)
	{
		animtblidx = 0;
	}
}


//=============================================================================
// アニメーション(ゲーム本編)
//=============================================================================
void C_Player::Anim_Main()
{
	//表示UV座標
	uvtblidx = g_anim[animtblidx].no;

	//アニメーションの速さ--------------------------------------------------------------------------------------
	static int i = 0;
	if (i >= 6 && key_push == true)
	{
		animtblidx++;
		i = 0;
	}
	else if (i <= 6) { i++; } 

	//アニメーション繰り返し--------------------------------------------------------------------------------------
	if (direction_no == 0 && animtblidx == 4)
	{
		animtblidx = 0;
	}
	if (direction_no == 1 && animtblidx == 8)
	{
		animtblidx = 4;
	}
	if (direction_no == 2 && animtblidx == 12)
	{
		animtblidx = 8;
	}
	if (direction_no == 3 && animtblidx == 16)
	{
		animtblidx = 12;
	}

	//向きチェンジ--------------------------------------------------------------------------------------
	switch (direction_no)
	{
	case DIRECTION_DOWN:
		if (animtblidx != 0 && animtblidx != 1 && animtblidx != 2 && animtblidx != 3)
		{
			animtblidx = 0;
		}
		break;

	case DIRECTION_UP:
		if (animtblidx != 4 && animtblidx != 5 && animtblidx != 6 && animtblidx != 7)
		{
			animtblidx = 4;
		}
		break;

	case DIRECTION_LEFT:
		if (animtblidx != 8 && animtblidx != 9 && animtblidx != 10 && animtblidx != 11)
		{
			animtblidx = 8;
		}
		break;

	case DIRECTION_RIGHT:
		if (animtblidx != 12 && animtblidx != 13 && animtblidx != 14 && animtblidx != 15)
		{
			animtblidx = 12;
		}
		break;
	}

	//静止時のモーション--------------------------------------------------------------------------------------
	if (key_push == false)
	{
		switch (direction_no)
		{
		case DIRECTION_DOWN:
			animtblidx = 0;
			break;

		case 1:
			animtblidx = 4;
			break;

		case 2:
			animtblidx = 8;
			break;
			
		case 3:
			animtblidx = 12;
			break;
		}
	}

	key_push = false;
}