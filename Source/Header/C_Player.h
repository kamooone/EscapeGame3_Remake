//=============================================================================
//
// プレイヤー処理クラス [C_Player.h]
//
//=============================================================================

#pragma once
#include "Main.h"
#include "C_Game_Manager.h"

#define PLAYER_INIT_POS_X 300.0f
#define PLAYER_INIT_POS_Y 200.0f
#define PLAYER_WIDTH 60
#define PLAYER_HIGHT 50


//*****************************************************************************
// 列挙型定義
//*****************************************************************************
enum direction_no {
	DIRECTION_DOWN = 0,
	DIRECTION_UP,
	DIRECTION_LEFT,
	DIRECTION_RIGHT
};


class C_Player : public C_Monster{
private:
	//テクスチャ
	LPDIRECT3DTEXTURE9	 t_player,t_red_hp_gage, t_yellow_hp_gage, T_controller;

	static float pos_x;
	static float pos_y;
	
	//プレイヤーダメージ数
	static int damage;

	//プレイヤーダメージカラーフラグ
	static bool collision_flag;

	float rotatenumber= 0;//Z軸の回転する角度
	
	bool key_push = false;//移動ボタンフラグ

	static bool flash_counter;  //フラッシュカウンターフラグ
	
	int flash_counter_time = 0;  //フラッシュカウンター持続時間(２フレーム)
	int flash_counter_next = 50; //次にフラッシュカウンターを発動できるまでの時間
	int flash_counter_color = 255;//フラッシュカウンター時のプレイヤーの色

	//引き金
	static bool fire_trigger;

	//プレイヤーの向いている方向を表す
	static int direction_no;      

	//ダメージを受けたら一定期間ダメージを受けないようにする
	bool enemy_colission_flag;
	bool boss_colission_flag;

	bool stage_sound, metu_sound;


	//アニメーション間隔
	static unsigned int animtblidx;

	//表示UV座標
	static unsigned int uvtblidx;


	//UpdateProcess
	//ワールド1のステージ遷移
	void TransStage_Flag();

	//画面遷移判定
	void Trans_Judge1();
	void Trans_Judge2();

	//画面遷移処理
	void TransStage();
	void TransStage_World1();
	void TransStage_World2();
	void TransStage_World3();


	void Player_Move1();
	void Up_Move1();
	void Down_Move1();
	void Left_Move1();
	void Right_Move1();

	void Player_Move2();
	void Up_Move2();
	void Down_Move2();
	void Left_Move2();
	void Right_Move2();

	void Footsteps();

	void HP_Recovery();
	void Fire_Trigger_Process();
	void Flash_Counter_Process();
	
	void Enemy_Collision();
	void Counter_Success();
	void Counter_Fail();

	void BossCollision();
	void Boss_Counter_Success();
	void Boss_Counter_Fail();
	void Damage_Effect(bool);

	void Game_Reset();
	void Reset_Process();

	void HPGageDraw(int, LPDIRECT3DDEVICE9, LPDIRECT3DTEXTURE9);

protected:


public:
	C_Player() :stage_sound(true), metu_sound(true) {};
	~C_Player() {};

	//StageSelect
	void SelectPlayerDraw(float, float, float tu[], float tv[], LPDIRECT3DDEVICE9);

	//Cplayer
	void Init(LPDIRECT3DDEVICE9);  //初期化
	void UnInit();                 //解放
	void UpdateProcess();                    //InputProcess
	void World1_UpdateProcess();
	void World2_UpdateProcess();
	void World3_UpdateProcess();
	void Select_DrawProcess(LPDIRECT3DDEVICE9);	 //drawutil呼び出し
	void DrawProcess(LPDIRECT3DDEVICE9);	 //drawutil呼び出し
	void PlayerDraw(float tu[], float tv[], LPDIRECT3DDEVICE9);
	void ControllerDraw(LPDIRECT3DDEVICE9);
	void ShadowDraw(LPDIRECT3DDEVICE9);

	//ステージ情報取得
	void GetParameter();
	void GetParameter2();
	void GetParameter3();

	//アニメーション向きチェンジ
	void Anim_Select();
	void Anim_Main();

	//エネミー座標取得
	static float Get_Player_Pos_x() { return pos_x; }
	static float Get_Player_Pos_y() { return pos_y; }

	//エネミー情報格納＆取得
	static void StoreEnemy_Parameter(int[], int[], bool[]);
	static float* GetEnemy_Pos_x();
	static float* GetEnemy_Pos_y();
	static int* GetEnemy_Damage();
	static bool* GetEnemy_Damage_Flag();
	static int* GetEnemy_State();
	static int GetEnemy_Max();

	//プレイヤーダメージ数格納&取得
	static void Store_Player_Damage(int& storedamage)
	{
		damage = storedamage;
	}
	static int& Get_Player_Damage() { return damage; }

	//プレイヤーの向き取得
	static int Get_Direction_No()
	{
		return direction_no;
	}

	//flash_counterフラグ格納&取得
	//static void Store_flash_counter(bool& Get_Flash_Counter) { flash_counter = Get_Flash_Counter; }
	static bool& Get_Flash_Counter() { return flash_counter; }


	//弾発射フラグ格納&取得
	static void Store_Fire_Trigger(bool& store_fire_trigger) { fire_trigger = store_fire_trigger; }
	static bool& Get_Fire_Trigger() { return fire_trigger; }

	//プレイヤーコリジョンフラグ格納&取得
	static void Store_Collision_Flag(bool& store_collision_flag) { collision_flag = store_collision_flag; }
	static bool& Get_Collision_Flag() { return collision_flag; }
};