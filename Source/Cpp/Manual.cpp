//=============================================================================
//
// �}�j���A���\������ [Manual.cpp]
//
//=============================================================================

#include "C_Manual.h"
#include "C_Player.h"
#include "C_Input.h"
#include "C_Sound.h"



//==============================================================================
// ����������
//==============================================================================
void C_Manual::Init(LPDIRECT3DDEVICE9 dev)
{
	HRESULT hr = D3DXCreateTextureFromFile(dev, "assets/manual1.png", &t_manual1);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}

	hr = D3DXCreateTextureFromFile(dev, "assets/manual2.png", &t_manual2);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}

	hr = D3DXCreateTextureFromFile(dev, "assets/manual3.png", &t_manual3);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}

	hr = D3DXCreateTextureFromFile(dev, "assets/manual5.png", &t_manual4);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}

	hr = D3DXCreateTextureFromFile(dev, "assets/manual6.png", &t_manual5);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}

	hr = D3DXCreateTextureFromFile(dev, "assets/manual4.png", &t_manual6);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}

	hr = D3DXCreateTextureFromFile(dev, "assets/controller1.png", &t_operator);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}
}


//==============================================================================
// �I������
//==============================================================================
void C_Manual::UnInit()
{
	if (t_manual1)
	{
		t_manual1->Release();
		t_manual1 = NULL;
	}

	if (t_manual2)
	{
		t_manual2->Release();
		t_manual2 = NULL;
	}

	if (t_manual3)
	{
		t_manual3->Release();
		t_manual3 = NULL;
	}

	if (t_manual4)
	{
		t_manual4->Release();
		t_manual4 = NULL;
	}

	if (t_manual5)
	{
		t_manual5->Release();
		t_manual5 = NULL;
	}

	if (t_manual6)
	{
		t_manual6->Release();
		t_manual6 = NULL;
	}

	if (t_operator)
	{
		t_operator->Release();
		t_operator = NULL;
	}
}


//==============================================================================
// �}�j���A���X�V����
//==============================================================================
void C_Manual::UpdateProcess()
{
	C_Game_Manager::stage_no = Get_Stage_No();
	C_Game_Manager::manual_no = Get_Manual_No();
	C_Game_Manager::color = Get_Color();

	static int time = 0;

	//�}�j���A���\���t���O
	if (C_Game_Manager::stage_no == 1 && C_Game_Manager::manual_no == 1)
	{
		C_Game_Manager::manual_flag = true;
	}
	if (C_Game_Manager::color == 255 && C_Game_Manager::stage_no == 2 && C_Game_Manager::manual_no == 2)
	{
		C_Game_Manager::manual_flag = true;
	}
	if (C_Game_Manager::color == 255 && C_Game_Manager::stage_no == 3 && C_Game_Manager::manual_no == 3)
	{
		C_Game_Manager::manual_flag = true;
	}
	if (C_Game_Manager::color == 255 && C_Game_Manager::stage_no == 4 && C_Game_Manager::manual_no == 4)
	{
		C_Game_Manager::manual_flag = true;
	}
	if (C_Game_Manager::manual_no == 6)
	{
		C_Game_Manager::manual_flag = true;
	}

	//�x�b�h�ŋx�߃}�j���A���\��
	int damage = C_Player::Get_Player_Damage();
	//������
	if (C_Game_Manager::manual_no == 1)
	{
		manual_bed = false;
		manual_bedflag = false;
	}
	if (damage >= 1 && manual_bedflag == false)
	{
		manual_bed = true;
		C_Game_Manager::manual_flag = true;
	}

	//�t�F�[�h�C�����Ȃ���}�j���A���\��
	if (C_Game_Manager::manual_flag == true && (manual_bed == false && manual_bedflag == false || manual_bed == true && manual_bedflag == true))
	{
		if (manual_draw_flag ==false)
		{
			time++;
			if(time == 100)
			{
				manual_draw_flag = true;
				time = 0;
			}
		}

		if (manual_draw_flag == true && manual_color != 255)
		{
			manual_color+=5;
		}

		if (manual_color == 110)
		{
			C_Sound::PlaySound(SOUND_LABEL_SE_LASER);//���艹
		}

		if (manual_color == 255)
		{
			manual_draw_flag = false;
		}
	}

	//�}�j���A���\�������
	if ((C_Input::GetKeyboardTrigger(DIK_I) || C_Input::GetKeyDown(0x0003)) && manual_color == 255 && (manual_bed == false && manual_bedflag == false || manual_bed == true && manual_bedflag == true))
	{
		C_Sound::PlaySound(SOUND_LABEL_SE_DECIDE);//���艹
		C_Game_Manager::manual_flag = false;
		C_Game_Manager::manual_no += 1;
		manual_color = 0;
	}

	//�t�F�[�h�C�����Ȃ���}�j���A���\��
	if (manual_bed == true && manual_bedflag == false)
	{
		if (manual_draw_flag == false)
		{
			time++;
			if (time == 100)
			{
				manual_draw_flag = true;
				time = 0;
			}
		}

		if (manual_draw_flag == true && manual_color != 255)
		{
			manual_color += 5;
		}

		if (manual_color == 110)
		{
			C_Sound::PlaySound(SOUND_LABEL_SE_LASER);//���艹
		}

		if (manual_color == 255)
		{
			manual_draw_flag = false;
		}
	}

	//�}�j���A���\�������
	if ((C_Input::GetKeyboardTrigger(DIK_I) || C_Input::GetKeyDown(0x0003)) && manual_color == 255 && manual_bed == true && manual_bedflag == false)
	{
		C_Sound::PlaySound(SOUND_LABEL_SE_DECIDE);//���艹
		manual_bedflag = true;
		manual_color = 0;
		C_Game_Manager::manual_flag = false;
	}

	//�}�j���A���t���O�i�[
	Store_Manual_Flag(C_Game_Manager::manual_flag);
	Store_Manual_No(C_Game_Manager::manual_no);
}


//==============================================================================
// �}�j���A���`�揈��
//==============================================================================
void C_Manual::DrawProcess(LPDIRECT3DDEVICE9 dev)
{
	if (C_Game_Manager::manual_flag == true)
	{
		switch (C_Game_Manager::manual_no)
		{
		case 1:
			//�}�j���A���`��
			Manual_Draw(dev, t_manual1);
			break;
		case 2:
			//�}�j���A���`��
			Manual_Draw(dev, t_manual2);
			break;
		case 3:
			//�}�j���A���`��
			Manual_Draw(dev, t_manual3);
			break;
		case 4:
			//�}�j���A���`��
			Manual_Draw(dev, t_manual4);
			break;
		case 6:
			//�}�j���A���`��
			Manual_Draw(dev, t_manual5);
			break;
		}
	}

	if (manual_bed == true && manual_bedflag == false)
	{
		//�}�j���A���`��
		Manual_Draw(dev, t_manual6);
	}
}