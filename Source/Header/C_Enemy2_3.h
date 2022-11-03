//=============================================================================
//
// エネミー処理クラス [C_Enemy2_3.h]
//
//=============================================================================

#pragma once
#include "Main.h"
#include "C_Game_Manager.h"


#define ENEMY_MAX2_3 15

#define ENEMY2_1_INIT_POS_X2_3 900.0f
#define ENEMY2_1_INIT_POS_Y2_3 740.0f

#define ENEMY2_2_INIT_POS_X2_3 1100.0f
#define ENEMY2_2_INIT_POS_Y2_3 500.0f

#define ENEMY2_3_INIT_POS_X2_3 1100.0f
#define ENEMY2_3_INIT_POS_Y2_3 250.0f

#define ENEMY2_4_INIT_POS_X2_3 900.0f
#define ENEMY2_4_INIT_POS_Y2_3 500.0f

#define ENEMY2_5_INIT_POS_X2_3 900.0f
#define ENEMY2_5_INIT_POS_Y2_3 250.0f

#define ENEMY2_6_INIT_POS_X2_3 560.0f
#define ENEMY2_6_INIT_POS_Y2_3 880.0f

#define ENEMY2_7_INIT_POS_X2_3 200.0f
#define ENEMY2_7_INIT_POS_Y2_3 880.0f

#define ENEMY2_8_INIT_POS_X2_3 560.0f
#define ENEMY2_8_INIT_POS_Y2_3 650.0f

#define ENEMY2_9_INIT_POS_X2_3 560.0f
#define ENEMY2_9_INIT_POS_Y2_3 370.0f

#define ENEMY2_10_INIT_POS_X2_3 400.0f
#define ENEMY2_10_INIT_POS_Y2_3 300.0f

#define ENEMY2_11_INIT_POS_X2_3 200.0f
#define ENEMY2_11_INIT_POS_Y2_3 620.0f

#define ENEMY2_12_INIT_POS_X2_3 250.0f
#define ENEMY2_12_INIT_POS_Y2_3 280.0f

#define ENEMY2_13_INIT_POS_X2_3 200.0f
#define ENEMY2_13_INIT_POS_Y2_3 200.0f

#define ENEMY2_14_INIT_POS_X2_3 200.0f
#define ENEMY2_14_INIT_POS_Y2_3 700.0f

#define ENEMY2_15_INIT_POS_X2_3 740.0f
#define ENEMY2_15_INIT_POS_Y2_3 300.0f


#define ENEMY_WIDTH 60
#define ENEMY_HIGHT 50



class C_Enemy2_3 :C_Monster {
private:
	static float pos_x[ENEMY_MAX2_3];
	static float pos_y[ENEMY_MAX2_3];

	//エネミーアニメーション
	unsigned int animtblidx_Enemy[ENEMY_MAX2_3] = { 0 };
	int animtime_Enemy[ENEMY_MAX2_3] = { 0 };
	unsigned int uvtblidx_Enemy[ENEMY_MAX2_3];

	//爆発アニメーション
	unsigned int animtblidx_Explosion[ENEMY_MAX2_3] = { 0 };
	int animtime_Explosion[ENEMY_MAX2_3] = { 0 };
	unsigned int uvtblidx_Explosion[ENEMY_MAX2_3];

	//エネミーーの向いている方向を表す
	static int direction_no_enemy[ENEMY_MAX2_3];

	//エネミーの生存状態
	static int enemy_state[ENEMY_MAX2_3];

	//エネミー被ダメージ数
	static int damage[ENEMY_MAX2_3];

	//エネミーダメージフラグ
	static bool damage_flag[ENEMY_MAX2_3];

	bool double_check[ENEMY_MAX2_3] = { false };

	//エネミー追従
	bool tuizyuu_flag[ENEMY_MAX2_3];

protected:

public:
	C_Enemy2_3()
	{	};
	~C_Enemy2_3() {};
	//Cplayer
	void Init(LPDIRECT3DDEVICE9);  //初期化
	void UnInit();                 //解放
	void UpdateProcess();                 //InputProcess
	void MoveTuizyu(int);
	void TuizyuRight(int, float, float, float, float);
	void TuizyuLeft(int, float, float, float, float);
	void TuizyuUp(int, float, float, float, float);
	void TuizyuDown(int, float, float, float, float);
	void MoveDown(int);
	void MoveUp(int);
	void MoveLeft(int);
	void MoveRight(int);
	void Damage_Effect();

	void DrawProcess(LPDIRECT3DDEVICE9);	 //drawutil呼び出し
	void Enemy_Animation(LPDIRECT3DDEVICE9);
	void Explosion_Animation(LPDIRECT3DDEVICE9);
	void EnemyDraw(int, float, float, float tu[], float tv[], LPDIRECT3DDEVICE9, LPDIRECT3DTEXTURE9);
	void AppleDraw(int, float, float, LPDIRECT3DDEVICE9, LPDIRECT3DTEXTURE9);
	void ShadowDraw(int, float, float, LPDIRECT3DDEVICE9);
	void HPGageDraw(int i, float x, float y, int damage, LPDIRECT3DDEVICE9 dev, LPDIRECT3DTEXTURE9 tex);


	//エネミー座標取得
	static float* Get_enemy_Pos_x() { return pos_x; }
	static float* Get_enemy_Pos_y() { return pos_y; }

	//エネミーの向き情報取得
	static int* Get_Direction() { return direction_no_enemy; }

	//エネミーの状態判定格納&取得
	static void Store_Enemy_State(int store_state[ENEMY_MAX2_3])
	{
		for (int i = 0; i<ENEMY_MAX2_3; i++)
		{
			enemy_state[i] = store_state[i];
		}
	}
	static int* Get_enemy_State() { return enemy_state; }

	//エネミー被ダメージ数格納&取得
	static void Store_Enemy_Damage(int store_damage[ENEMY_MAX2_3])
	{
		for (int i = 0; i<ENEMY_MAX2_3; i++)
		{
			damage[i] = store_damage[i];
		}
	}
	static int* Get_enemy_Damage() { return damage; }

	//エネミーダメージフラグ格納&取得
	static void Store_Enemy_Damage_Flag(bool store_damage_flag[ENEMY_MAX2_3])
	{
		for (int i = 0; i<ENEMY_MAX2_3; i++)
		{
			damage_flag[i] = store_damage_flag[i];
		}
	}
	static bool* Get_enemy_Damage_Flag() { return damage_flag; }

	//ステージ移動でエネミー復活
	void Enemy_Resurrection()
	{
		for (int i = 0; i < ENEMY_MAX2_3; i++)
		{
			enemy_state[i] = 0;
			damage[i] = 0;
		}

		C_Enemy2_3::pos_x[0] = ENEMY2_1_INIT_POS_X2_3;
		C_Enemy2_3::pos_x[1] = ENEMY2_2_INIT_POS_X2_3;
		C_Enemy2_3::pos_x[2] = ENEMY2_3_INIT_POS_X2_3;
		C_Enemy2_3::pos_x[3] = ENEMY2_4_INIT_POS_X2_3;
		C_Enemy2_3::pos_x[4] = ENEMY2_5_INIT_POS_X2_3;
		C_Enemy2_3::pos_x[5] = ENEMY2_6_INIT_POS_X2_3;
		C_Enemy2_3::pos_x[6] = ENEMY2_7_INIT_POS_X2_3;
		C_Enemy2_3::pos_x[7] = ENEMY2_8_INIT_POS_X2_3;
		C_Enemy2_3::pos_x[8] = ENEMY2_9_INIT_POS_X2_3;
		C_Enemy2_3::pos_x[9] = ENEMY2_10_INIT_POS_X2_3;
		C_Enemy2_3::pos_x[10] = ENEMY2_11_INIT_POS_X2_3;
		C_Enemy2_3::pos_x[11] = ENEMY2_12_INIT_POS_X2_3;
		C_Enemy2_3::pos_x[12] = ENEMY2_13_INIT_POS_X2_3;
		C_Enemy2_3::pos_x[13] = ENEMY2_14_INIT_POS_X2_3;
		C_Enemy2_3::pos_x[14] = ENEMY2_15_INIT_POS_X2_3;


		C_Enemy2_3::pos_y[0] = ENEMY2_1_INIT_POS_Y2_3;
		C_Enemy2_3::pos_y[1] = ENEMY2_2_INIT_POS_Y2_3;
		C_Enemy2_3::pos_y[2] = ENEMY2_3_INIT_POS_Y2_3;
		C_Enemy2_3::pos_y[3] = ENEMY2_4_INIT_POS_Y2_3;
		C_Enemy2_3::pos_y[4] = ENEMY2_5_INIT_POS_Y2_3;
		C_Enemy2_3::pos_y[5] = ENEMY2_6_INIT_POS_Y2_3;
		C_Enemy2_3::pos_y[6] = ENEMY2_7_INIT_POS_Y2_3;
		C_Enemy2_3::pos_y[7] = ENEMY2_8_INIT_POS_Y2_3;
		C_Enemy2_3::pos_y[8] = ENEMY2_9_INIT_POS_Y2_3;
		C_Enemy2_3::pos_y[9] = ENEMY2_10_INIT_POS_Y2_3;
		C_Enemy2_3::pos_y[10] = ENEMY2_11_INIT_POS_Y2_3;
		C_Enemy2_3::pos_y[11] = ENEMY2_12_INIT_POS_Y2_3;
		C_Enemy2_3::pos_y[12] = ENEMY2_13_INIT_POS_Y2_3;
		C_Enemy2_3::pos_y[13] = ENEMY2_14_INIT_POS_Y2_3;
		C_Enemy2_3::pos_y[14] = ENEMY2_15_INIT_POS_Y2_3;
	}
};