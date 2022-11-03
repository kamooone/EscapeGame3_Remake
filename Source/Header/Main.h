//=========================
// [main.h]
//=========================

//=========================
#ifndef _MAIN_H_
#define _MAIN_H_

//*********************************
//インクルードファイル
//*********************************
#include <windows.h>
#include <d3dx9.h>  //描画処理に必要
#include <xaudio2.h>

//*********************************
//ライブラリのリンク
//*********************************
#if 1 //[ここを"0"にした場合、"構成プロパティ"->"リンカ"->"入力"->"追加の既存ファイル"に対象ライブラリを設定する]
#pragma comment (lib,"d3d9.lib")   //描画処理に必要
#pragma comment (lib,"d3dx9.lib")  //[d3d9.lib]の拡張ライブラリ
#pragma comment (lib,"dxguid.lib") //DirectXコンポーネント使用に必要
#pragma comment (lib, "winmm.lib")		// DirectXコンポーネント使用に必要
#endif

//*********************************
//マクロ定義
//*********************************
#define SCREEN_WIDTH  (800)  //ウィンドウの幅
#define SCREEN_HIGHT (600)  //ウィンドウの高さ

#define COLOR_MAX 255 //色の値

#endif