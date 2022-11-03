//=============================================================================
//
// サウンド処理クラス [C_Sound.h]
//
//=============================================================================
#pragma once
#include	"main.h"

//*****************************************************************************
// サウンドファイル
//*****************************************************************************
enum SOUND_LABEL
{
	SOUND_LABEL_BGM000 = 0,		// BGM0
	SOUND_LABEL_BGM001,			// BGM1
	SOUND_LABEL_BGM002,			// BGM2
	SOUND_LABEL_BGM003,			// BGM2
	SOUND_LABEL_SE_DECIDE,		// 決定音
	SOUND_LABEL_SE_CANCEL,		// キャンセル音
	SOUND_LABEL_SE_SELECT,		// 選択音
	SOUND_LABEL_SE_SHOT,		// 弾発射音
	SOUND_LABEL_SE_LASER,		// レーザー発射音
	SOUND_LABEL_SE_LOCKON,		// ロックオン音
	SOUND_LABEL_SE_HIT,			// ヒット音
	SOUND_LABEL_SE_GUARD,		// ガード音
	SOUND_LABEL_SE_EXPLOSION,	// 弾発射音
	SOUND_LABEL_SE_WARP,		// ワープ音
	SOUND_LABEL_GAMEOVER,		// ゲームオーバー
	SOUND_LABEL_SE_METU,		// やられた
	SOUND_LABEL_SE_START,		// ゲーム起動
	SOUND_LABEL_SE_CURSOR,		// カーソル移動
	SOUND_LABEL_SE_BOMB,		// 爆発音
	SOUND_LABEL_SE_WALK,		// 爆発音
	SOUND_LABEL_SE_JUMP,		// 弾
	SOUND_LABEL_MAX,
};

class C_Sound {

private:



protected:


public:

	HRESULT InitSound(HWND hWnd);
	void UninitSound(void);
	static HRESULT PlaySound(SOUND_LABEL label);
	static void StopSound(SOUND_LABEL label);
	void StopSound(void);

};

