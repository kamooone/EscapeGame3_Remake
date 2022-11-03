//=============================================================================
//
// �v���C���[���� [Player.cpp]
//
//=============================================================================

#include "C_Player.h"
#include "Struct_Input.h"
#include "Struct_player.h"
#include "C_Select.h"
#include "C_Game.h"


//=============================================================================
// ������
//=============================================================================
void C_Player::Init(LPDIRECT3DDEVICE9 dev)
{
	HRESULT hr = D3DXCreateTextureFromFile(dev, "assets/player.png", &t_player);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}

	hr = D3DXCreateTextureFromFile(dev, "assets/gage.png", &t_red_hp_gage);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}

	hr = D3DXCreateTextureFromFile(dev, "assets/gageYellow.png", &t_yellow_hp_gage);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}

	hr = D3DXCreateTextureFromFile(dev, "assets/shadow.png", &t_shadow);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}

	hr = D3DXCreateTextureFromFile(dev, "assets/controller1.png", &T_controller);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}
}


//=============================================================================
// �������
//=============================================================================
void C_Player::UnInit()
{
	if (t_player)
	{
		t_player->Release();
		t_player = NULL;
	}

	if (t_red_hp_gage)
	{
		t_red_hp_gage->Release();
		t_red_hp_gage = NULL;
	}

	if (t_yellow_hp_gage)
	{
		t_yellow_hp_gage->Release();
		t_yellow_hp_gage = NULL;
	}

	if (t_shadow)
	{
		t_shadow->Release();
		t_shadow = NULL;
	}

	if (T_controller)
	{
		T_controller->Release();
		T_controller = NULL;
	}
}


//=============================================================================
// �X�V����
//=============================================================================
void C_Player::UpdateProcess()
{
	//���݂̃��[���h�i���o�[�擾
	int world_no = C_Select::Get_World_No();
	C_Game_Manager::stage_no = C_Game_Manager::Get_Stage_No();

	//�X�e�[�W�J�ڃt���O
	TransStage_Flag();

	//�X�e�[�W�J�ڏ���
	TransStage();

	//�v���C���[�ړ�����
	if (damage < 40 && C_Game_Manager::color >= 240)
	{
		switch (world_no)
		{
		case WORLD_1:
			if (C_Game_Manager::manual_flag == false) { World1_UpdateProcess(); }
			break;

		case WORLD_2:
			World2_UpdateProcess();
			break;

		case WORLD_3:
			World3_UpdateProcess();
			break;
		}

		//��ʃX�N���[���l�i�[
		Store_Scroll_x(C_Game_Manager::scroll_x);
		Store_Scroll_y(C_Game_Manager::scroll_y);

		//�x�b�h�ŉ�
		if (C_Game_Manager::stage_no == 1) { HP_Recovery(); }

		//�e����(�����ł͒e�𔭎˂��Ȃ�)
		if (C_Game_Manager::trans_flag == false && C_Game_Manager::stage_no != 1)
		{
			Fire_Trigger_Process();
		}

		//�t���b�V���J�E���^�[����
		if (collision_flag == false)
		{
			Flash_Counter_Process();
		}

		//�v���C���[�R���W�����t���O�i�[
		Store_Collision_Flag(collision_flag);

		//�{�X�̒e���󂯂��_���[�W���Z
		C_Player::damage = Get_Player_Damage();
	}

	//�X�e�[�W�i���o�[�i�[
	Store_Stage_No(C_Game_Manager::stage_no);

	//�X�e�[�W�J�ڃt���O�i�[
	Store_Trans_Flag(C_Game_Manager::trans_flag);


	//�Q�[���I�[�o�[(�^�C�g���ɖ߂�)
	if (damage >= 40)
	{
		//�e�p�����[�^����������
		Game_Reset();
	}

	Store_Color(C_Game_Manager::color);
}


//=============================================================================
// World1_UpdateProcess
//=============================================================================
void C_Player::World1_UpdateProcess()
{
	//�X�e�[�W���擾
	GetParameter();

	if (C_Game_Manager::stage_no <= 2 || C_Game_Manager::stage_no >= 4)
	{
		Player_Move1();
	}

	if (C_Game_Manager::stage_no == 3)
	{
		Player_Move2();
	}

	Enemy_Collision();

	if (C_Game_Manager::stage_no == 4)
	{
		BossCollision();
	}
}


//=============================================================================
// World2_UpdateProcess
//=============================================================================
void C_Player::World2_UpdateProcess()
{
	//�X�e�[�W���擾
	GetParameter2();

	if (C_Game_Manager::stage_no <= 2 || C_Game_Manager::stage_no == 5)
	{
		Player_Move1();
	}

	if (C_Game_Manager::stage_no == 3 || C_Game_Manager::stage_no == 4)
	{
		Player_Move2();
	}

	Enemy_Collision();

	if (C_Game_Manager::stage_no == 5)
	{
		BossCollision();
	}
}


//=============================================================================
// World3_UpdateProcess
//=============================================================================
void C_Player::World3_UpdateProcess()
{
	//�X�e�[�W���擾
	GetParameter3();

	if (C_Game_Manager::stage_no == 1 || C_Game_Manager::stage_no == 5)
	{
		Player_Move1();
	}

	if (C_Game_Manager::stage_no == 2 || C_Game_Manager::stage_no == 3 || C_Game_Manager::stage_no == 4)
	{
		Player_Move2();
	}

	Enemy_Collision();

	if (C_Game_Manager::stage_no == 5)
	{
		BossCollision();
	}
}


//=============================================================================
// �`�揈��(�X�e�[�W�Z���N�g���)
//=============================================================================
void C_Player::Select_DrawProcess(LPDIRECT3DDEVICE9 dev)
{
	//���[���h�i���o�[�擾
	int wold_no = C_Select::Get_World_No();

	//�A�j���[�V��������
	Anim_Select();

	switch (wold_no)
	{
	case WORLD_1:
		//�v���C���[�`��
		SelectPlayerDraw(-85.0f, -8.0f, g_uvTable[uvtblidx].u, g_uvTable[uvtblidx].v, dev);
		break;

	case WORLD_2:
		//�v���C���[�`��
		SelectPlayerDraw(-235.0f, 60.0f, g_uvTable[uvtblidx].u, g_uvTable[uvtblidx].v, dev);
		break;

	case WORLD_3:
		//�v���C���[�`��
		SelectPlayerDraw(35.0f, 60.0f, g_uvTable[uvtblidx].u, g_uvTable[uvtblidx].v, dev);
		break;
	}

	C_Game_Manager::color = Get_Color();
}


//=============================================================================
// �`�揈��(�Q�[���{��)
//=============================================================================
void C_Player::DrawProcess(LPDIRECT3DDEVICE9 dev)
{
	//���[���h�i���o�[�擾
	int wold_no = C_Select::Get_World_No();

	//�A�j���[�V��������
	Anim_Main();

	//�ۉe�`��
	ShadowDraw(dev);

	//HP�Q�[�W�`��
	HPGageDraw(0, dev, t_red_hp_gage);
	HPGageDraw(damage, dev, t_yellow_hp_gage);

	//�v���C���[�`��
	PlayerDraw(g_uvTable[uvtblidx].u, g_uvTable[uvtblidx].v, dev);

	C_Game_Manager::color = Get_Color();
}


//=============================================================================
// �X�e�[�W���擾
//=============================================================================
void C_Player::GetParameter()
{
	C_Game_Manager::color = C_Game_Manager::Get_Color();

	//���݂̃X�e�[�W�i���o�[�擾
	C_Game_Manager::stage_no = C_Game_Manager::Get_Stage_No();

	//�X�e�[�W�J�ڃt���O�擾
	C_Game_Manager::trans_flag = C_Game_Manager::Get_Trans_Flag();

	//�ꎟ���z��Ɋi�[�p
	int* Get_MapData = C_Mapchip::MapData_Get1();

	//�񎟌��z��ɕϊ�
	for (int i = 0; C_Game_Manager::stage_no == 3 ? i < 1000 / 20 : i < SCREEN_HIGHT / 20; i++)
	{
		for (int j = 0; C_Game_Manager::stage_no == 3 ? j < 1200 / 20 : j < SCREEN_WIDTH / 20; j++)
		{
			static int ij = 0;
			C_Game_Manager::stage_no == 3 ? MapData_No2_TwoDim[i][j] = Get_MapData[ij] : MapData_TwoDim[i][j] = Get_MapData[ij];
			if (C_Game_Manager::stage_no == 3 ? ij <= 2999 : ij <= 1199) { ij++; }
			if (C_Game_Manager::stage_no == 3 ? ij == 3000 : ij == 1200) { ij = 0; }
		}
	}
}


//=============================================================================
// �X�e�[�W���擾2
//=============================================================================
void C_Player::GetParameter2()
{
	C_Game_Manager::color = C_Game_Manager::Get_Color();

	//���݂̃X�e�[�W�i���o�[�擾
	C_Game_Manager::stage_no = Get_Stage_No();

	//�X�e�[�W�J�ڃt���O�擾
	C_Game_Manager::trans_flag = C_Game_Manager::Get_Trans_Flag();

	//�ꎟ���z��Ɋi�[�p
	int* Get_MapData = C_Mapchip::MapData_Get2();

	//�񎟌��z��ɕϊ�
	for (int i = 0; C_Game_Manager::stage_no == 3 || stage_no == 4 ? i < 1000 / 20 : i < SCREEN_HIGHT / 20; i++)
	{
		for (int j = 0; C_Game_Manager::stage_no == 3 || stage_no == 4 ? j < 1200 / 20 : j < SCREEN_WIDTH / 20; j++)
		{
			static int ij = 0;
			C_Game_Manager::stage_no == 3 || stage_no == 4 ? MapData_No2_TwoDim[i][j] = Get_MapData[ij] : MapData_TwoDim[i][j] = Get_MapData[ij];
			if (C_Game_Manager::stage_no == 3 || stage_no == 4 ? ij <= 2999 : ij <= 1199) { ij++; }
			if (C_Game_Manager::stage_no == 3 || stage_no == 4 ? ij == 3000 : ij == 1200) { ij = 0; }
		}
	}
}


//=============================================================================
// �X�e�[�W���擾3
//=============================================================================
void C_Player::GetParameter3()
{
	C_Game_Manager::color = C_Game_Manager::Get_Color();

	//���݂̃X�e�[�W�i���o�[�擾
	C_Game_Manager::stage_no = Get_Stage_No();

	//�X�e�[�W�J�ڃt���O�擾
	C_Game_Manager::trans_flag = C_Game_Manager::Get_Trans_Flag();

	//�ꎟ���z��Ɋi�[�p
	int* Get_MapData = C_Mapchip::MapData_Get3();

	//�񎟌��z��ɕϊ�
	for (int i = 0; C_Game_Manager::stage_no == 2 || stage_no == 3 || stage_no == 4 ? i < 1000 / 20 : i < SCREEN_HIGHT / 20; i++)
	{
		for (int j = 0; C_Game_Manager::stage_no == 2 || stage_no == 3 || stage_no == 4 ? j < 1200 / 20 : j < SCREEN_WIDTH / 20; j++)
		{
			static int ij = 0;
			C_Game_Manager::stage_no == 2 || stage_no == 3 || stage_no == 4 ? MapData_No2_TwoDim[i][j] = Get_MapData[ij] : MapData_TwoDim[i][j] = Get_MapData[ij];
			if (C_Game_Manager::stage_no == 2 || stage_no == 3 || stage_no == 4 ? ij <= 2999 : ij <= 1199) { ij++; }
			if (C_Game_Manager::stage_no == 2 || stage_no == 3 || stage_no == 4 ? ij == 3000 : ij == 1200) { ij = 0; }
		}
	}
}


//=============================================================================
// �A�j���[�V����(�Z���N�g���)
//=============================================================================
void C_Player::Anim_Select()
{
	//�\��UV���W
	uvtblidx = g_anim[animtblidx].no;

	//�A�j���[�V�����̑���
	static int i = 0;

	if (animtblidx >= 4) { animtblidx = 0; }
	if (i <= 12) { i++; }
	if (i == 12)
	{
		animtblidx++;
		i = 0;
	}

	//�A�j���[�V�����J��Ԃ�
	if (animtblidx == 4 && direction_no == 0)
	{
		animtblidx = 0;
	}
}


//=============================================================================
// �A�j���[�V����(�Q�[���{��)
//=============================================================================
void C_Player::Anim_Main()
{
	//�\��UV���W
	uvtblidx = g_anim[animtblidx].no;

	//�A�j���[�V�����̑���--------------------------------------------------------------------------------------
	static int i = 0;
	if (i >= 6 && key_push == true)
	{
		animtblidx++;
		i = 0;
	}
	else if (i <= 6) { i++; } 

	//�A�j���[�V�����J��Ԃ�--------------------------------------------------------------------------------------
	if (direction_no == 0 && animtblidx == 4)
	{
		animtblidx = 0;
	}
	if (direction_no == 1 && animtblidx == 8)
	{
		animtblidx = 4;
	}
	if (direction_no == 2 && animtblidx == 12)
	{
		animtblidx = 8;
	}
	if (direction_no == 3 && animtblidx == 16)
	{
		animtblidx = 12;
	}

	//�����`�F���W--------------------------------------------------------------------------------------
	switch (direction_no)
	{
	case DIRECTION_DOWN:
		if (animtblidx != 0 && animtblidx != 1 && animtblidx != 2 && animtblidx != 3)
		{
			animtblidx = 0;
		}
		break;

	case DIRECTION_UP:
		if (animtblidx != 4 && animtblidx != 5 && animtblidx != 6 && animtblidx != 7)
		{
			animtblidx = 4;
		}
		break;

	case DIRECTION_LEFT:
		if (animtblidx != 8 && animtblidx != 9 && animtblidx != 10 && animtblidx != 11)
		{
			animtblidx = 8;
		}
		break;

	case DIRECTION_RIGHT:
		if (animtblidx != 12 && animtblidx != 13 && animtblidx != 14 && animtblidx != 15)
		{
			animtblidx = 12;
		}
		break;
	}

	//�Î~���̃��[�V����--------------------------------------------------------------------------------------
	if (key_push == false)
	{
		switch (direction_no)
		{
		case DIRECTION_DOWN:
			animtblidx = 0;
			break;

		case 1:
			animtblidx = 4;
			break;

		case 2:
			animtblidx = 8;
			break;
			
		case 3:
			animtblidx = 12;
			break;
		}
	}

	key_push = false;
}