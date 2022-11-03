//========================
// [main.cpp]
//========================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//========================
#include "Main.h"
#include "C_Sound.h"
#include "C_Game.h"
//========================

//************************
//�}�N����`
//************************
#define CLASS_NAME "AppClass"         //�E�B���h�E�̃N���X��
#define WINDOW_NAME "�E�o�Q�[���V Remake" //�E�B���h�E�̃L���v�V������

//***********************************************************************
//�N���X�̃I�u�W�F�N�g����
//***********************************************************************
C_Game* objGame = new C_Game();

//************************
//�v���g�^�C�v�錾
//************************

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow);
void Uninit(void);

//************************
// �O���[�o���ϐ�
//************************

LPDIRECT3D9       g_pD3D = NULL;         //Direct3D�I�u�W�F�N�g
LPDIRECT3DDEVICE9 g_pD3DDevice = NULL; //Device�I�u�W�F�N�g(�`��ɕK�v)
int g_nCountFPS = 0;// �e�o�r�ւ̃J�E���^


//========================
// ���C���֐�
//========================
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wcex =
	{
		sizeof(WNDCLASSEX),
		CS_CLASSDC,
		WndProc,
		0,
		0,
		hInstance,
		NULL,
		LoadCursor(NULL,IDC_ARROW),
		(HBRUSH)(COLOR_WINDOW + 1),
		NULL,
		CLASS_NAME,
		NULL
	};
	HWND hWnd;
	MSG msg;

	DWORD dwExecLastTime;		// �Ō�Ɏ��s��������		
	DWORD dwFPSLastTime;		// �Ō�Ɍv����������
	DWORD dwCurrentTime;		// ���ݎ���
	DWORD dwFrameCount;			// �t���[����

	//�E�B���h�E�N���X�̓o�^
	RegisterClassEx(&wcex);

	//�E�B���h�E�̍쐬
	hWnd = CreateWindowEx(0,
		CLASS_NAME,
		WINDOW_NAME,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		SCREEN_WIDTH,
		SCREEN_HIGHT,
		NULL,
		NULL,
		hInstance,
		NULL);

	//����������(�E�B���h�E���쐬���Ă���s��)
	if (FAILED(Init(hInstance, hWnd, TRUE)))
	{
		return -1;
	}

	// �t���[���J�E���g������
	timeBeginPeriod(1);
	dwExecLastTime = dwFPSLastTime = timeGetTime();
	dwCurrentTime = dwFrameCount = 0;

	//�E�B���h�E�̕\��(�����������̌�ɍs��)
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	//���b�Z�[�W���[�v
	while (1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) != 0) //���b�Z�[�W���擾���Ȃ������ꍇ"0"��Ԃ�
		{//windows�̏���
			if (msg.message == WM_QUIT)
			{// PostQuitMessage()���Ă΂�āAWM_QUIT���b�Z�[�W�������烋�[�v�I��
				break;
			}
			else
			{
				//���b�Z�[�W�̖|��Ƒ��o
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			// �e�o�r��艻����
			// ���ݎ��Ԃ��擾
			dwCurrentTime = timeGetTime();
			// 0.5�b���ƂɎ��s
			if ((dwCurrentTime - dwFPSLastTime) > 500) 
			{
				// FPS���v�Z
				g_nCountFPS = (dwFrameCount * 1000) / (dwCurrentTime - dwFPSLastTime);

				// �e�o�r�v�����ԂɌ������Ԃ��Z�b�g
				dwFPSLastTime = dwCurrentTime;

				// �t���[�������[���N���A
				dwFrameCount = 0;
			}
			// �P�U�~���b�o�߂�����
			if ((dwCurrentTime - dwExecLastTime) >= (1000.0 / 60.0)) 
			{
				// �ŏI���s���ԂɌ��ݎ��Ԃ��Z�b�g
				dwExecLastTime = dwCurrentTime;

				//DirectX�̏���
				//�Q�[�����[�v
				objGame->GameMain(g_pD3DDevice);

				// �t���[�������C���N�������g
				dwFrameCount++;
			}
		}
	}

	//�E�B���h�E�N���X�̓o�^������
	UnregisterClass(CLASS_NAME, wcex.hInstance);

	//�I������
	Uninit();

	return (int)msg.wParam;
}

//===================================
// �E�B���h�E�v���V�[�W��
//===================================
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	//int nID;

	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			//nID = MessageBox(NULL, "�I�����Ă����ł���?", "�m�F", MB_YESNO);
			//if (nID == IDYES)
			//{
				DestroyWindow(hWnd);
			//}
			break;

		}
		break;

	case WM_CLOSE:
		//nID = MessageBox(hWnd, "�I�����܂���?", "�I��", MB_YESNO);
		//if (nID == IDYES)
		//{
			DestroyWindow(hWnd);
		//}
		//else
		//{
			//return 0;
		//}
		break;

	default:
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}


//==============================
// ����������
// hInstance  :�C���X�^���X�̃n���h��
// hWnd       :�E�B���h�E�̃n���h��
// bWindow    :�E�B���h�E���[�h�ɂ��邩�ǂ���
//===============================
HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	D3DPRESENT_PARAMETERS d3dpp;
	D3DDISPLAYMODE d3ddm;

	//Direct3D�I�u�W�F�N�g�̐���
	g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
	if (g_pD3D == NULL)
	{
		return E_FAIL;
	}

	//���݂̃f�B�X�v���C���[�h���擾
	if (FAILED(g_pD3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm)))
	{
		return E_FAIL;
	}

	//�f�o�C�X�̃v���[���e�[�V�����p�����[�^�̐ݒ�
	ZeroMemory(&d3dpp, sizeof(d3dpp));        //���[�N���[���N���A
	d3dpp.BackBufferWidth = 600;    //�Q�[����ʃT�C�Y(��)
	d3dpp.BackBufferHeight = 400;   //�Q�[����ʃT�C�Y(����)
	d3dpp.BackBufferFormat = d3ddm.Format;    //�J���[���[�h�̐ݒ�
	d3dpp.BackBufferCount = 1;             //�o�b�N�o�b�t�@�̐�
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;    //�f���M���ɓ������ĕs���b�v����
	d3dpp.Windowed = bWindow;    //�E�B���h�E���[�h
	d3dpp.EnableAutoDepthStencil = TRUE;    //�f�v�X�o�b�t�@(Z�o�b�t�@)�ƃX�e���V���o�b�t�@���쐬
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;    //�f�v�X�o�b�t�@�Ƃ���16bit���g��


	if (bWindow)
	{//�E�B���h�E���[�h
		d3dpp.FullScreen_RefreshRateInHz = 0;        //���t���b�V�����[�g(�w��ł��Ȃ��̂�0�Œ�)
		d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;//�C���^�[�o��(VSync��҂����ɕ`��)
	}
	else
	{//�t���X�N���[�����[�h
		d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT; //���t���b�V�����[�g(���݂̑��x�ɍ��킹��)
		d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;  //�C���^�[�o��(VSync��҂��ĕ`��)
	}

	//�f�o�C�X�I�u�W�F�N�g�̐���
	//[�f�o�C�X�쐬����]<�`��>��<���_����>���n�[�h�E�F�A�ōs��
	if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, //�f�B�X�v���C�A�_�v�^
		D3DDEVTYPE_HAL,//�f�o�C�X�^�C�v
		hWnd,//�t�H�[�J�X����E�B���h�E�ւ̃n���h��
		D3DCREATE_HARDWARE_VERTEXPROCESSING,//�f�o�C�X�쐬����̑g�ݍ��킹
		&d3dpp,         //�f�o�C�X�̃v���[���e�[�V�����p�����[�^
		&g_pD3DDevice)))//�f�o�C�X�C���^�[�t�F�[�X�ւ̃|�C���^
	{
		//��L�̐ݒ肪���s������
		//[�f�o�C�X�쐬����]<�`��>���n�[�h�E�F�A�ōs���A<���_����>��CPU�ōs��
		if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT,
			D3DDEVTYPE_HAL,
			hWnd,
			D3DCREATE_SOFTWARE_VERTEXPROCESSING,
			&d3dpp,
			&g_pD3DDevice)))
		{
			//��L�̐ݒ肪���s������
			//[�f�o�C�X�쐬����]<�`��>��<���_����>��CPU�ōs��
			if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT,
				D3DDEVTYPE_REF,
				hWnd,
				D3DCREATE_SOFTWARE_VERTEXPROCESSING,
				&d3dpp,
				&g_pD3DDevice)))
			{
				//���������s
				return E_FAIL;
			}
		}
	}

	//���ߏ���(����Ń��̒l���������)
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);

	// �����_�����O�X�e�[�g�p�����[�^�̐ݒ�
	g_pD3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);				// ���ʂ��J�����O����
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);				// ���u�����h���s��
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);		// ���\�[�X�J���[�̎w��
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);		// ���f�X�e�B�l�[�V�����J���[�̎w��

	g_pD3DDevice->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP);	//
	g_pD3DDevice->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP);	//
	g_pD3DDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);	//
	g_pD3DDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);	//
	
	//�Q�[����������
	objGame->GameInit(g_pD3DDevice, hInstance, hWnd);

	return S_OK;
}

//==================================
//�I���ݒ�
//==================================
void Uninit(void)
{
	delete objGame;//�f�X�g���N�^�Ăяo��

	if (g_pD3DDevice != NULL)
	{//�f�o�C�X�̊J��
		g_pD3DDevice->Release();
		g_pD3DDevice = NULL;
	}

	if (g_pD3D != NULL)
	{//Direct3D�I�u�W�F�N�g�̊J��
		g_pD3D->Release();
		g_pD3D = NULL;
	}
}