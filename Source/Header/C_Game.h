//=============================================================================
//
// ゲーム処理クラス [C_Game.h]
//
//=============================================================================

#pragma once
#include "C_Select.h"
#include "C_Player.h"
#include "C_Bullet.h"
#include "C_Enemy.h"
#include "C_Enemy1.h"
#include "C_Enemy2_1.h"
#include "C_Enemy2_2.h"
#include "C_Enemy2_3.h"
#include "C_Enemy3_1.h"
#include "C_Enemy3_2.h"
#include "C_Enemy3_3.h"
#include "C_Boss.h"
#include "C_Title.h"
#include "C_Clear.h"
#include "C_Manual.h"
#include "C_Game_Manager.h"
#include "C_Room.h"
#include "C_Field.h"
#include "C_Field1.h"
#include "C_Field2.h"
#include "C_Field2_1.h"
#include "C_Field2_2.h"
#include "C_Field2_3.h"
#include "C_Field3_1.h"
#include "C_Field3_2.h"
#include "C_Field3_3.h"
#include "C_Input.h"
#include "Struct_Input.h"
#include "C_Sound.h"


//*****************************************************************************
// 列挙型定義
//*****************************************************************************
enum world_state {
	WORLD_1 = 1,
	WORLD_2,
	WORLD_3
};

enum game_state {
	TITLE = 1,
	SELECT,
	GAME_MAIN,
	ENDING
};

enum stage_state {
	STAGE_1 = 1,
	STAGE_2,
	STAGE_3,
	STAGE_4,
	STAGE_5
};


class C_Game : public C_Select
{
private:
	static bool game_flag;

	//操作説明表示
	bool operator_flag = false;
	bool operator_flag_chattering = false;

public:
	C_Game() {};
	~C_Game() {};

	void GameMain(LPDIRECT3DDEVICE9);

	void GameInit(LPDIRECT3DDEVICE9, HINSTANCE hInstance, HWND hWnd);
	void GameExit();
	void GameInput();
	void GameUpdate();
	void GameRender(LPDIRECT3DDEVICE9);

	void Get_GameState();
	void Stage_Resurrection();

	void Operator_Update();

	void World_Update();
	void World1_Update();
	void World2_Update();
	void World3_Update();

	void World_Draw(LPDIRECT3DDEVICE9 g_pD3DDevice);
	void World1_Draw(LPDIRECT3DDEVICE9 g_pD3DDevice);
	void World2_Draw(LPDIRECT3DDEVICE9 g_pD3DDevice);
	void World3_Draw(LPDIRECT3DDEVICE9 g_pD3DDevice);
};