//=============================================================================
//
// ���͏����N���X [C_Input.h]
//
//=============================================================================
#ifndef _C_INPUT_H_
#define _C_INPUT_H_

#include <dinput.h>
#include <Windows.h>
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "dinput8.lib")


//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define KEYBOARD_TRIGGER g_keyState[cnt] != keyStateOld[cnt] && g_keyStateTrigger[cnt] != 0x80 && (g_keyState[cnt]&0x80) 
#define KEYBOARD_RELEASE g_keyState[cnt] != keyStateOld[cnt] && g_keyStateRelease[cnt] != 0x80 && (g_keyState[cnt]^0x80)
#define MOUSE_TRIGGER g_mouseState.rgbButtons[cnt] != mouseStateOld.rgbButtons[cnt] && /*g_mouseStateTrigger.rgbButtons[cnt] != 0x80&&*/(g_mouseState.rgbButtons[cnt]&0x80)
#define MOUSE_RELEASE g_mouseState.rgbButtons[cnt] != mouseStateOld.rgbButtons[cnt] && /*g_mouseStateRelease.rgbButtons[cnt] != 0x80&&*/(g_mouseState.rgbButtons[cnt]^0x80)

// �L�[���GetKey�V���[�Y�̊֐��Ŏg�p����
#define CLEAR_KEY	 0x0000		// �L�[�N���A�p
#define UP_KEY		 0x00F1		// ��L�[
#define DOWN_KEY	 0x00F2		// ���L�[
#define LEFT_KEY	 0x00F3		// ���L�[
#define RIGHT_KEY	 0x00F4		// �E�L�[

#define SQUARE_KEY	 0x0001		// ���L�[
#define CROSS_KEY    0x0002		// �~�L�[
#define CIRCLE_KEY	 0x0003		// ���L�[
#define TRIANGLE_KEY 0x0004		// ���L�[
#define OPTION_KEY	 0x000A		// �I�v�V�����{�^��

#define MOVE_ON (GetKeyboardPress(DIK_A)||GetKeyboardPress(DIK_S)||GetKeyboardPress(DIK_D)||GetKeyboardPress(DIK_W)||GetKey(UP_KEY)||GetKey(DOWN_KEY)||GetKey(LEFT_KEY)||GetKey(RIGHT_KEY))


//*****************************************************************************
// �萔��`
//*****************************************************************************
const int NUM_KEY_MAX = 256;



class C_Input {

private:

	static LPDIRECTINPUT8			g_pDInput;					// IDirectInput8�C���^�[�t�F�[�X�ւ̃|�C���^
	static LPDIRECTINPUTDEVICE8	g_pDIDevKeyboard;			// IDirectInputDevice8�C���^�[�t�F�[�X�ւ̃|�C���^(�L�[�{�[�h)
	static LPDIRECTINPUTDEVICE8	g_pDIDevMouse;				// IDirectInputDevice8�C���^�[�t�F�[�X�ւ̃|�C���^(�}�E�X)
	static BYTE					g_keyState[NUM_KEY_MAX];			// �L�[�{�[�h�̏�Ԃ��󂯎�郏�[�N
	static BYTE					g_keyStateTrigger[NUM_KEY_MAX];		// �L�[�{�[�h�̏�Ԃ��󂯎�郏�[�N
	static BYTE					g_keyStateRepeat[NUM_KEY_MAX];		// �L�[�{�[�h�̏�Ԃ��󂯎�郏�[�N
	static BYTE					g_keyStateRelease[NUM_KEY_MAX];		// �L�[�{�[�h�̏�Ԃ��󂯎�郏�[�N
	static int						g_keyStateRepeatCnt[NUM_KEY_MAX];	// �L�[�{�[�h�̃��s�[�g�J�E���^
	static DIMOUSESTATE2			g_mouseState;						// �}�E�X�̏�Ԃ��󂯎�郏�[�N
	static DIMOUSESTATE2			g_mouseStateTrigger;				// �}�E�X�̏�Ԃ��󂯎�郏�[�N
	static DIMOUSESTATE2			g_mouseStateRelease;				// �}�E�X�̏�Ԃ��󂯎�郏�[�N
	static POINT					g_MousePoint;						// �}�E�X�̌��ݍ��W
	static HWND					g_hwnd;


	static DIDEVCAPS g_diDevCaps;
	static BYTE KeyState_Press[256];
	static BYTE KeyState_Trigger[256];
	static BYTE KeyState_Release[256];

protected:


public:

	HRESULT InitKeyboard(HINSTANCE hInst, HWND hWnd);
	void UninitKeyboard(void);
	HRESULT UpdateKeyboard(void);
	HRESULT InitMouse(HINSTANCE hInst, HWND hWnd);
	void UninitMouse(void);
	HRESULT UpdateMouse(void);


	HRESULT InitInput(HINSTANCE hInstance, HWND hWnd);
	void UninitInput(void);
	void UpdateInput(void);

	static bool GetKeyboardPress(int key);
	static bool GetKeyboardTrigger(int key);
	static bool GetKeyboardRepeat(int key);
	static bool GetKeyboardRelease(int key);

	static bool GetMouseLeftPress(void);
	static bool GetMouseLeftTrigger(void);
	static bool GetMouseLeftRelease(void);
	static bool GetMouseRightPress(void);
	static bool GetMouseRightTrigger(void);
	static bool GetMouseRightRelease(void);
	static bool GetMouseCenterPress(void);
	static bool GetMouseCenterTrigger(void);
	static bool GetMouseCenterRelease(void);
	static long GetMouseAxisX(void);
	static long GetMouseAxisY(void);
	static long GetMouseAxisZ(void);
	static long GetMouseX(void);
	static long GetMouseY(void);

	/*�Q�[���p�b�h���g�p���邽�߂̊֐���K��*/
	static void KeyUpdate(void);
	static bool GetKey(DWORD key_code);
	static bool GetKeyDown(DWORD key_code);
	static bool GetKeyUp(DWORD key_code);

	DWORD WatchKey(DWORD key_code);

};
#endif