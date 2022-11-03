//=============================================================================
//
// �T�E���h�����N���X [C_Sound.h]
//
//=============================================================================
#pragma once
#include	"main.h"

//*****************************************************************************
// �T�E���h�t�@�C��
//*****************************************************************************
enum SOUND_LABEL
{
	SOUND_LABEL_BGM000 = 0,		// BGM0
	SOUND_LABEL_BGM001,			// BGM1
	SOUND_LABEL_BGM002,			// BGM2
	SOUND_LABEL_BGM003,			// BGM2
	SOUND_LABEL_SE_DECIDE,		// ���艹
	SOUND_LABEL_SE_CANCEL,		// �L�����Z����
	SOUND_LABEL_SE_SELECT,		// �I����
	SOUND_LABEL_SE_SHOT,		// �e���ˉ�
	SOUND_LABEL_SE_LASER,		// ���[�U�[���ˉ�
	SOUND_LABEL_SE_LOCKON,		// ���b�N�I����
	SOUND_LABEL_SE_HIT,			// �q�b�g��
	SOUND_LABEL_SE_GUARD,		// �K�[�h��
	SOUND_LABEL_SE_EXPLOSION,	// �e���ˉ�
	SOUND_LABEL_SE_WARP,		// ���[�v��
	SOUND_LABEL_GAMEOVER,		// �Q�[���I�[�o�[
	SOUND_LABEL_SE_METU,		// ���ꂽ
	SOUND_LABEL_SE_START,		// �Q�[���N��
	SOUND_LABEL_SE_CURSOR,		// �J�[�\���ړ�
	SOUND_LABEL_SE_BOMB,		// ������
	SOUND_LABEL_SE_WALK,		// ������
	SOUND_LABEL_SE_JUMP,		// �e
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

