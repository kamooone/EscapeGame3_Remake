//=========================
// [main.h]
//=========================

//=========================
#ifndef _MAIN_H_
#define _MAIN_H_

//*********************************
//�C���N���[�h�t�@�C��
//*********************************
#include <windows.h>
#include <d3dx9.h>  //�`�揈���ɕK�v
#include <xaudio2.h>

//*********************************
//���C�u�����̃����N
//*********************************
#if 1 //[������"0"�ɂ����ꍇ�A"�\���v���p�e�B"->"�����J"->"����"->"�ǉ��̊����t�@�C��"�ɑΏۃ��C�u������ݒ肷��]
#pragma comment (lib,"d3d9.lib")   //�`�揈���ɕK�v
#pragma comment (lib,"d3dx9.lib")  //[d3d9.lib]�̊g�����C�u����
#pragma comment (lib,"dxguid.lib") //DirectX�R���|�[�l���g�g�p�ɕK�v
#pragma comment (lib, "winmm.lib")		// DirectX�R���|�[�l���g�g�p�ɕK�v
#endif

//*********************************
//�}�N����`
//*********************************
#define SCREEN_WIDTH  (800)  //�E�B���h�E�̕�
#define SCREEN_HIGHT (600)  //�E�B���h�E�̍���

#define COLOR_MAX 255 //�F�̒l

#endif