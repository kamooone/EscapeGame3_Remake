//=============================================================================
//
// エネミー処理クラス [C_Enemy2_1.h]
//
//=============================================================================

#pragma once
#include "Main.h"
#include "C_Game_Manager.h"


#define ENEMY_MAX2_1 4

#define ENEMY1_1_INIT_POS_X2_1 600.0f
#define ENEMY1_1_INIT_POS_Y2_1 500.0f

#define ENEMY1_2_INIT_POS_X2_1 500.0f
#define ENEMY1_2_INIT_POS_Y2_1 180.0f

#define ENEMY1_3_INIT_POS_X2_1 100.0f
#define ENEMY1_3_INIT_POS_Y2_1 200.0f

#define ENEMY1_4_INIT_POS_X2_1 250.0f
#define ENEMY1_4_INIT_POS_Y2_1 260.0f

#define ENEMY_WIDTH 60
#define ENEMY_HIGHT 50

class C_Enemy2_1:C_Monster {
private:
	static float pos_x[ENEMY_MAX2_1];
	static float pos_y[ENEMY_MAX2_1];

	//エネミーアニメーション
	unsigned int animtblidx_Enemy[ENEMY_MAX2_1] = { 0 };
	int animtime_Enemy[ENEMY_MAX2_1] = { 0 };
	unsigned int uvtblidx_Enemy[ENEMY_MAX2_1];

	//爆発アニメーション
	unsigned int animtblidx_Explosion[ENEMY_MAX2_1] = { 0 };
	int animtime_Explosion[ENEMY_MAX2_1] = { 0 };
	unsigned int uvtblidx_Explosion[ENEMY_MAX2_1];

	//エネミーーの向いている方向を表す
	static int direction_no_enemy[ENEMY_MAX2_1];

	//エネミーの生存状態
	static int enemy_state[ENEMY_MAX2_1];

	//エネミー被ダメージ数
	static int damage[ENEMY_MAX2_1];

	//エネミーダメージフラグ
	static bool damage_flag[ENEMY_MAX2_1];

	//二重処理防止のため
	bool double_check[ENEMY_MAX2_1];

	//エネミー追従
	bool tuizyuu_flag[ENEMY_MAX2_1];

protected:

public:
	C_Enemy2_1() {};
	~C_Enemy2_1() {};

	//CEnemyProcess
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
	static void Store_Enemy_State(int store_state[6])
	{
		for (int i = 0; i<6; i++)
		{
			enemy_state[i] = store_state[i];
		}
	}
	static int* Get_enemy_State() { return enemy_state; }


	//エネミー被ダメージ数格納&取得
	static void Store_Enemy_Damage(int store_damage[6])
	{
		for (int i = 0; i<6; i++)
		{
			damage[i] = store_damage[i];
		}
	}
	static int* Get_enemy_Damage() { return damage; }


	//エネミーダメージフラグ格納&取得
	static void Store_Enemy_Damage_Flag(bool store_damage_flag[6])
	{
		for (int i = 0; i<6; i++)
		{
			damage_flag[i] = store_damage_flag[i];
		}
	}
	static bool* Get_enemy_Damage_Flag() { return damage_flag; }


	//ステージ移動でエネミー復活
	void Enemy_Resurrection()
	{
		for (int i = 0; i < ENEMY_MAX2_1; i++)
		{
			enemy_state[i] = 0;
			damage[i] = 0;
			C_Enemy2_1::pos_x[0] =  ENEMY1_1_INIT_POS_X2_1;
			C_Enemy2_1::pos_y[0] =  ENEMY1_1_INIT_POS_Y2_1;

			C_Enemy2_1::pos_x[1] = ENEMY1_2_INIT_POS_X2_1;
			C_Enemy2_1::pos_y[1] = ENEMY1_2_INIT_POS_Y2_1;

			C_Enemy2_1::pos_x[2] = ENEMY1_3_INIT_POS_X2_1;
			C_Enemy2_1::pos_y[2] = ENEMY1_3_INIT_POS_Y2_1;

			C_Enemy2_1::pos_x[3] = ENEMY1_4_INIT_POS_X2_1;
			C_Enemy2_1::pos_y[3] = ENEMY1_4_INIT_POS_Y2_1;
		}
	}
};