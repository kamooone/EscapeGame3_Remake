//=============================================================================
//
// ゲームメイン処理 [Game.cpp]
//
//=============================================================================

#include "C_Game.h"


//***********************************************************************
// クラスのオブジェクト生成
//***********************************************************************
C_Input* objInput;
C_Sound* objSound;
C_Title* objTitle;
C_Select* objSelect;
C_Clear* objClear;
C_Manual* objManual;
C_Player* objPlayer;
C_Bullet* objBullet;
C_Enemy* objEnemy;
C_Enemy1* objEnemy1;
C_Enemy2_1* objEnemy2_1;
C_Enemy2_2* objEnemy2_2;
C_Enemy2_3* objEnemy2_3;
C_Enemy3_1* objEnemy3_1;
C_Enemy3_2* objEnemy3_2;
C_Enemy3_3* objEnemy3_3;
C_Boss* objBoss;
C_Room* objRoom;
C_Field* objField;
C_Field1* objField1;
C_Field2* objField2;
C_Field2_1* objField2_1;
C_Field2_2* objField2_2;
C_Field2_3* objField2_3;
C_Field3_1* objField3_1;
C_Field3_2* objField3_2;
C_Field3_3* objField3_3;


//*****************************************************************************
// 静的メンバ変数実体化
//*****************************************************************************
int C_Game_Manager::game_state_no = 1;
bool C_Game_Manager::room_sound = true;
bool C_Game_Manager::field_sound = true;
bool C_Game_Manager::field1_sound = true;


//==============================================================================
// 初期化処理
//==============================================================================
void C_Game::GameInit(LPDIRECT3DDEVICE9 g_pD3DDevice, HINSTANCE hInstance, HWND hWnd)
{
	objInput = new C_Input();
	objSound = new C_Sound();
	objTitle = new C_Title();
	objSelect = new C_Select();
	objClear = new C_Clear();
	objManual = new C_Manual();
	objPlayer = new C_Player();
	objBullet = new C_Bullet();
	objEnemy = new C_Enemy();
	objEnemy1 = new C_Enemy1();
	objEnemy2_1 = new C_Enemy2_1();
	objEnemy2_2 = new C_Enemy2_2();
	objEnemy2_3 = new C_Enemy2_3();
	objEnemy3_1 = new C_Enemy3_1();
	objEnemy3_2 = new C_Enemy3_2();
	objEnemy3_3 = new C_Enemy3_3();
	objBoss = new C_Boss();
	objRoom = new C_Room();
	objField = new C_Field();
	objField1 = new C_Field1();
	objField2 = new C_Field2();
	objField2_1 = new C_Field2_1();
	objField2_2 = new C_Field2_2();
	objField2_3 = new C_Field2_3();
	objField3_1 = new C_Field3_1();
	objField3_2 = new C_Field3_2();
	objField3_3 = new C_Field3_3();

	objInput->InitInput(hInstance, hWnd);
	objSound->InitSound(hWnd);
	objTitle->Init(g_pD3DDevice);
	objSelect->Init(g_pD3DDevice);
	objManual->Init(g_pD3DDevice);
	objRoom->Init(g_pD3DDevice);
	objField->Init(g_pD3DDevice);
	objField1->Init(g_pD3DDevice);
	objField2->Init(g_pD3DDevice);
	objField2_1->Init(g_pD3DDevice);
	objField2_2->Init(g_pD3DDevice);
	objField2_3->Init(g_pD3DDevice);
	objField3_1->Init(g_pD3DDevice);
	objField3_2->Init(g_pD3DDevice);
	objField3_3->Init(g_pD3DDevice);
	objPlayer->Init(g_pD3DDevice);
	objBullet->Init(g_pD3DDevice);
	objEnemy->Init(g_pD3DDevice);
	objEnemy1->Init(g_pD3DDevice);
	objEnemy2_1->Init(g_pD3DDevice);
	objEnemy2_2->Init(g_pD3DDevice);
	objEnemy2_3->Init(g_pD3DDevice);
	objEnemy3_1->Init(g_pD3DDevice);
	objEnemy3_2->Init(g_pD3DDevice);
	objEnemy3_3->Init(g_pD3DDevice);
	objBoss->Init(g_pD3DDevice);
	objClear->Init(g_pD3DDevice);
}


//==============================================================================
// ゲームループ処理
//==============================================================================
void C_Game::GameMain(LPDIRECT3DDEVICE9 g_pD3DDevice)
{
	GameInput();					// 入力
	GameUpdate();					// 更新
	GameRender(g_pD3DDevice);		// 描画
}


//==============================================================================
// ゲーム入力検知処理
//==============================================================================
void C_Game::GameInput()
{
	objInput->UpdateInput();
}


//==============================================================================
// ゲーム更新処理
//==============================================================================
void C_Game::GameUpdate()
{
	Get_GameState();

	Stage_Resurrection();

	switch (C_Game_Manager::game_state_no)
	{
	case TITLE:
		objTitle->UpdateProcess();
		break;

	case SELECT:
		objSelect->UpdateProcess();
		break;

	case GAME_MAIN:
		Operator_Update();
		
		if (operator_flag == false)
		{
			World_Update();

			objPlayer->UpdateProcess();
			objBullet->UpdateProcess();
		}

		if (world_no == 1)
		{
			objManual->UpdateProcess();
		}

		operator_flag_chattering = false;
		break;

	case ENDING:
		objClear->UpdateProcess();
		break;
	}
}


//==============================================================================
// ゲーム描画処理
//==============================================================================
void C_Game::GameRender(LPDIRECT3DDEVICE9 g_pD3DDevice)
{
	//Count   :pRects配列にある短形の数
	//pRects  :クリアする短形の配列(NULL指定でビューポート短形全体をクリア)
	//Flags   :クリアするサーフェスを示すフラグ(少なくとも１つを使用しなければならない)
	//        :[D3DCLEAR_TARGET - レンダリングターゲットをクリアしてC_Game_Manager::colorパラメータの値にする]
	//        :[D3DCLEAR_ZBUFFER - 深度(Z)バッファをクリアしてZパラメータの値にする]
	//        :[D3DCLEAR_STENCIL - ステンシルバッファをクリアしてStencilパラメータの値にする]
	//C_Game_Manager::color   :サーフェスをクリアする色
	//Z       :デプスバッファに保存する値
	//Stencil :ステンシルバッファに保存する値(整数)
	g_pD3DDevice->Clear(0, NULL, (D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER), D3DCOLOR_RGBA(0, 0, 0, 255), 1.0, 0);

	//Direct3Dによる描画の開始
	if (SUCCEEDED(g_pD3DDevice->BeginScene()))
	{
		switch (C_Game_Manager::game_state_no)
		{
		case TITLE:
			objTitle->DrawProcess(g_pD3DDevice);
			break;

		case SELECT:
			objSelect->DrawProcess(g_pD3DDevice);
			objPlayer->Select_DrawProcess(g_pD3DDevice);
			break;

		case GAME_MAIN:
			if (operator_flag == false)
			{
				World_Draw(g_pD3DDevice);
			}

			if (operator_flag == true)
			{
				objManual->Operator_Draw(g_pD3DDevice);
			}
			break;

		case ENDING:
			objClear->DrawProcess(g_pD3DDevice);
			break;
		}

		 //Direct3Dによる描画の終了
		g_pD3DDevice->EndScene();
	}
	//バックバッファとフロントバッファの入れ替え
	//pSourceRect         :転送元短形
	//pDestRect           :転送先短形
	//hDestWindowOverride :転送先ウィンドウへのポインタ
	//pDirtyRegion        :通常はNULLで
	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}


//==============================================================================
// ゲーム終了処理
//==============================================================================
void C_Game::GameExit()
{
	//各終了処理
	objInput->UninitInput();
	objSound->UninitSound();
	objTitle->UnInit();
	objSelect->UnInit();
	objRoom->UnInit();
	objField->UnInit();
	objField1->UnInit();
	objField2->UnInit();
	objField2_1->UnInit();
	objField2_2->UnInit();
	objField2_3->UnInit();
	objField3_1->UnInit();
	objField3_2->UnInit();
	objField3_3->UnInit();
	objPlayer->UnInit();
	objBullet->UnInit();
	objEnemy->UnInit();
	objEnemy1->UnInit();
	objEnemy2_1->UnInit();
	objEnemy2_2->UnInit();
	objEnemy2_3->UnInit();
	objEnemy3_1->UnInit();
	objEnemy3_2->UnInit();
	objEnemy3_3->UnInit();
	objBoss->UnInit();

	//デストラクタ(クラスオブジェクト開放)
	delete objInput;
	delete objSound;
	delete objTitle;
	delete objSelect;
	delete objRoom;
	delete objField;
	delete objField1;
	delete objField2;
	delete objField2_1;
	delete objField2_2;
	delete objField2_3;
	delete objField3_1;
	delete objField3_2;
	delete objField3_3;
	delete objPlayer;
	delete objBullet;
	delete objEnemy;
	delete objEnemy1;
	delete objEnemy2_1;
	delete objEnemy2_2;
	delete objEnemy2_3;
	delete objEnemy3_1;
	delete objEnemy3_2;
	delete objEnemy3_3;
	delete objBoss;
}


//==============================================================================
// 各種ステート取得
//==============================================================================
void C_Game::Get_GameState()
{
	//ゲームステート取得
	C_Game_Manager::game_state_no = C_Game_Manager::Get_Game_State_No();

	//現在のステージナンバー取得
	C_Select::world_no = C_Select::Get_World_No();
	C_Game_Manager::stage_no = C_Game_Manager::Get_Stage_No();

	C_Game_Manager::manual_flag = C_Game_Manager::Get_Manual_Flag();

	//ステージ遷移フラグ取得
	C_Game_Manager::trans_flag = C_Game_Manager::Get_Trans_Flag();
}


//==============================================================================
// Stage_Resurrection
//==============================================================================
void C_Game::Stage_Resurrection()
{
	if (world_no == 1)
	{
		//エネミーリセット
		if ((C_Game_Manager::stage_no = Get_Stage_No()) != 2) { objEnemy->Enemy_Resurrection(); }
		if ((C_Game_Manager::stage_no = Get_Stage_No()) != 3) { objEnemy1->Enemy_Resurrection(); }
		if ((C_Game_Manager::stage_no = Get_Stage_No()) != 4) { objBoss->Boss_Resurrection(); }

		//サウンドリセット
		if ((C_Game_Manager::stage_no = Get_Stage_No()) == 1) { C_Game_Manager::Store_Field_Sound(C_Game_Manager::field_sound = true); }
		if ((C_Game_Manager::stage_no = Get_Stage_No()) == 2) { C_Game_Manager::Store_Room_Sound(C_Game_Manager::room_sound = true); }
		if ((C_Game_Manager::stage_no = Get_Stage_No()) == 3) { C_Game_Manager::Store_Field1_Sound(C_Game_Manager::field1_sound = true); }
		if ((C_Game_Manager::stage_no = Get_Stage_No()) == 4) { C_Game_Manager::Store_Field_Sound(C_Game_Manager::field_sound = true); }
	}

	if (world_no == 2)
	{
		if ((C_Game_Manager::stage_no = Get_Stage_No()) != 2) { objEnemy2_1->Enemy_Resurrection(); }
		if ((C_Game_Manager::stage_no = Get_Stage_No()) != 3) { objEnemy2_2->Enemy_Resurrection(); }
		if ((C_Game_Manager::stage_no = Get_Stage_No()) != 4) { objEnemy2_3->Enemy_Resurrection(); }
		if ((C_Game_Manager::stage_no = Get_Stage_No()) != 5) { objBoss->Boss_Resurrection(); }

		if ((C_Game_Manager::stage_no = Get_Stage_No()) == 1) { C_Game_Manager::Store_Field_Sound(C_Game_Manager::field_sound = true); }
		if ((C_Game_Manager::stage_no = Get_Stage_No()) == 2) { C_Game_Manager::Store_Room_Sound(C_Game_Manager::room_sound = true); }
		if ((C_Game_Manager::stage_no = Get_Stage_No()) == 4) { C_Game_Manager::Store_Field1_Sound(C_Game_Manager::field1_sound = true); }
		if ((C_Game_Manager::stage_no = Get_Stage_No()) == 5) { C_Game_Manager::Store_Field_Sound(C_Game_Manager::field_sound = true); }
	}

	if (world_no == 3)
	{
		if ((C_Game_Manager::stage_no = Get_Stage_No()) != 2) { objEnemy3_1->Enemy_Resurrection(); }
		if ((C_Game_Manager::stage_no = Get_Stage_No()) != 3) { objEnemy3_2->Enemy_Resurrection(); }
		if ((C_Game_Manager::stage_no = Get_Stage_No()) != 4) { objEnemy3_3->Enemy_Resurrection(); }
		if ((C_Game_Manager::stage_no = Get_Stage_No()) != 5) { objBoss->Boss_Resurrection(); }

		if ((C_Game_Manager::stage_no = Get_Stage_No()) == 1) { C_Game_Manager::Store_Field_Sound(C_Game_Manager::field_sound = true); }
		if ((C_Game_Manager::stage_no = Get_Stage_No()) == 2) { C_Game_Manager::Store_Room_Sound(C_Game_Manager::room_sound = true); }
		if ((C_Game_Manager::stage_no = Get_Stage_No()) == 4) { C_Game_Manager::Store_Field1_Sound(C_Game_Manager::field1_sound = true); }
		if ((C_Game_Manager::stage_no = Get_Stage_No()) == 5) { C_Game_Manager::Store_Field_Sound(C_Game_Manager::field_sound = true); }
	}
}


//==============================================================================
// 操作説明表示
//==============================================================================
void C_Game::Operator_Update()
{
	if (C_Input::GetKeyboardTrigger(DIK_K) || C_Input::GetKeyDown(0x0004) && operator_flag_chattering == false)
	{
		//操作表示切替フラグ
		if (operator_flag == false && operator_flag_chattering == false)
		{
			operator_flag = true;
			operator_flag_chattering = true;
		}

		//操作表示切替フラグ
		if (operator_flag == true && operator_flag_chattering == false)
		{
			operator_flag = false;
			operator_flag_chattering = true;
		}
	}
}


//==============================================================================
// World_Update
//==============================================================================
void C_Game::World_Update()
{
	switch (world_no)
	{
	case WORLD_1:
		World1_Update();
		break;

	case WORLD_2:
		World2_Update();
		break;

	case WORLD_3:
		World3_Update();
		break;
	}
}


//==============================================================================
// World1_Update
//==============================================================================
void C_Game::World1_Update()
{
	switch (C_Game_Manager::stage_no)
	{
	case STAGE_1:
		objRoom->UpdateProcess();
		break;

	case STAGE_2:
		objField->UpdateProcess();
		if (C_Game_Manager::manual_flag == false) { objEnemy->UpdateProcess(); }
		break;

	case STAGE_3:
		objField1->UpdateProcess();
		if (C_Game_Manager::manual_flag == false) { objEnemy1->UpdateProcess(); }
		break;

	case STAGE_4:
		objField2->UpdateProcess();
		if (C_Game_Manager::manual_flag == false) { objBoss->UpdateProcess(); }
		break;
	}
}


//==============================================================================
// World2_Update
//==============================================================================
void C_Game::World2_Update()
{
	switch (C_Game_Manager::stage_no)
	{
	case STAGE_1:
		objRoom->UpdateProcess();
		break;

	case STAGE_2:
		objField2_1->UpdateProcess();
		objEnemy2_1->UpdateProcess();
		break;

	case STAGE_3:
		objField2_2->UpdateProcess();
		objEnemy2_2->UpdateProcess();
		break;

	case STAGE_4:
		objField2_3->UpdateProcess();
		objEnemy2_3->UpdateProcess();
		break;

	case STAGE_5:
		objField2->UpdateProcess();
		objBoss->UpdateProcess();
		break;
	}
}


//==============================================================================
// World3_Update
//==============================================================================
void C_Game::World3_Update()
{
	switch (C_Game_Manager::stage_no)
	{
	case STAGE_1:
		objRoom->UpdateProcess();
		break;

	case STAGE_2:
		objField3_1->UpdateProcess();
		objEnemy3_1->UpdateProcess();
		break;

	case STAGE_3:
		objField3_2->UpdateProcess();
		objEnemy3_2->UpdateProcess();
		break;

	case STAGE_4:
		objField3_3->UpdateProcess();
		objEnemy3_3->UpdateProcess();
		break;

	case STAGE_5:
		objField2->UpdateProcess();
		objBoss->UpdateProcess();
		break;
	}
}


//==============================================================================
// World_Draw
//==============================================================================
void C_Game::World_Draw(LPDIRECT3DDEVICE9 g_pD3DDevice)
{
	switch (world_no)
	{
	case WORLD_1:
		World1_Draw(g_pD3DDevice);
		break;

	case WORLD_2:
		World2_Draw(g_pD3DDevice);
		break;

	case WORLD_3:
		World3_Draw(g_pD3DDevice);
		break;
	}

	objPlayer->DrawProcess(g_pD3DDevice);
	objBullet->DrawProcess(g_pD3DDevice);

	if (world_no == 1)
	{
		objManual->DrawProcess(g_pD3DDevice);
	}
}


//==============================================================================
// World1_Draw
//==============================================================================
void C_Game::World1_Draw(LPDIRECT3DDEVICE9 g_pD3DDevice)
{
	switch (C_Game_Manager::stage_no)
	{
	case STAGE_1:
		objRoom->DrawProcess(g_pD3DDevice);
		break;

	case STAGE_2:
		objField->DrawProcess(g_pD3DDevice);

		objEnemy->DrawProcess(g_pD3DDevice);
		break;

	case STAGE_3:
		objField1->DrawProcess(g_pD3DDevice);

		objEnemy1->DrawProcess(g_pD3DDevice);
		break;

	case STAGE_4:
		objField2->DrawProcess(g_pD3DDevice);

		objBoss->DrawProcess(g_pD3DDevice);
		break;

	case STAGE_5:
		break;
	}
}


//==============================================================================
// World2_Draw
//==============================================================================
void C_Game::World2_Draw(LPDIRECT3DDEVICE9 g_pD3DDevice)
{
	switch (C_Game_Manager::stage_no)
	{
	case STAGE_1:
		objRoom->DrawProcess(g_pD3DDevice);
		break;

	case STAGE_2:
		objField2_1->DrawProcess(g_pD3DDevice);

		objEnemy2_1->DrawProcess(g_pD3DDevice);
		break;

	case STAGE_3:
		objField2_2->DrawProcess(g_pD3DDevice);

		objEnemy2_2->DrawProcess(g_pD3DDevice);
		break;

	case STAGE_4:
		objField2_3->DrawProcess(g_pD3DDevice);

		objEnemy2_3->DrawProcess(g_pD3DDevice);
		break;

	case STAGE_5:
		objField2->DrawProcess(g_pD3DDevice);

		objBoss->DrawProcess(g_pD3DDevice);
		break;
	}
}


//==============================================================================
// World3_Draw
//==============================================================================
void C_Game::World3_Draw(LPDIRECT3DDEVICE9 g_pD3DDevice)
{
	switch (C_Game_Manager::stage_no)
	{
	case STAGE_1:
		objRoom->DrawProcess(g_pD3DDevice);
		break;

	case STAGE_2:
		objField3_1->DrawProcess(g_pD3DDevice);

		objEnemy3_1->DrawProcess(g_pD3DDevice);
		break;

	case STAGE_3:
		objField3_2->DrawProcess(g_pD3DDevice);

		objEnemy3_2->DrawProcess(g_pD3DDevice);
		break;

	case STAGE_4:
		objField3_3->DrawProcess(g_pD3DDevice);

		objEnemy3_3->DrawProcess(g_pD3DDevice);
		break;

	case STAGE_5:
		objField2->DrawProcess(g_pD3DDevice);

		objBoss->DrawProcess(g_pD3DDevice);
		break;
	}
}