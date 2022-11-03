//=============================================================================
//
// 静的メンバ変数実体化 [Entity.cpp]
//
//=============================================================================


#include "C_Player.h"
#include "C_Game_Manager.h"


//静的一次元配列に格納用配列を実体化
int C_Mapchip::MapData_OneDim[(SCREEN_HIGHT / 20) * (SCREEN_WIDTH / 20)];
int C_Mapchip::MapData_No2_OneDim[(1000 / 20) * (1200 / 20)];

//静的ステージナンバーを実体化
int C_Game_Manager::C_Game_Manager::stage_no = 1;

//静的プレイヤー向き情報を実体化
int C_Player::direction_no = 0;

//静的プレイヤー位置情報を実体化
float C_Player::pos_x = PLAYER_INIT_POS_X;
float C_Player::pos_y = PLAYER_INIT_POS_Y;

//静的プレイヤーダメージエフェクトを実体化
bool C_Player::collision_flag = false;

//フラッシュカウンターフラグ
bool C_Player::flash_counter = false;

//引き金
bool C_Player::fire_trigger = false;

//プレイヤーダメージ数実体化
int C_Player::damage = 0;

//プレイヤーアニメーション間隔
unsigned int C_Player::animtblidx = 0;

//表示UV座標
unsigned int C_Player::uvtblidx = 0;

//画面スクロール変数実体化
float C_Game_Manager::scroll_x = 0;
float C_Game_Manager::scroll_y = 0;

//フェードインフェードアウトに使う
int C_Game_Manager::color = 255;

//マニュアル表示フラグ
bool C_Game_Manager::C_Game_Manager::manual_flag = false;

//マニュアル表示ナンバー
int C_Game_Manager::C_Game_Manager::manual_no = 1;

//現在のステージナンバーバックアップ
int C_Game_Manager::backup_stage_no = false;

//画面遷移フラグ
bool C_Game_Manager::trans_flag = false;