//=============================================================================
//
// �X�e�[�W�J�ڏ��� [TransStage.cpp]
//
//=============================================================================

#include "C_Player.h"
#include "C_Select.h"
#include "C_Sound.h"


//=============================================================================
// �X�e�[�W�J�ڃt���O����
//=============================================================================
void C_Player::TransStage_Flag()
{
	//���݂̃��[���h�i���o�[�擾
	int world_no = C_Select::Get_World_No();
	C_Game_Manager::stage_no = C_Game_Manager::Get_Stage_No();


	//�ȉ��A�X�e�[�W�J�ڔ��菈��
	switch (stage_no)
	{
	case 1:
		C_Player::Trans_Judge1();

		break;

	case 2:
		if (world_no <= 2) { C_Player::Trans_Judge1(); }
		if (world_no >= 3) { C_Player::Trans_Judge2(); }

		break;

	case 3:
		C_Player::Trans_Judge2();

		break;

	case 4:
		if (world_no == 1) { C_Player::Trans_Judge1(); }
		if (world_no >= 2) { C_Player::Trans_Judge2(); }

		break;

	case 5:
		C_Player::Trans_Judge1();

		break;
	}
}


//=============================================================================
// �X�e�[�W�J�ڔ���1(���}�b�v)
//=============================================================================
void C_Player::Trans_Judge1()
{
	// �X�e�[�W�߂�======================================================================
	if (MapData_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 5 &&
		C_Game_Manager::trans_flag == false)
	{
		//�J�ڃt���O��true��(�e��A�b�v�f�[�g���~�߂�)
		Store_Trans_Flag(C_Game_Manager::trans_flag = true);

		//�J�ڌ�̃X�e�[�W�i���o�[�i�[
		Store_Backup_Stage_No(C_Game_Manager::stage_no - 1);
	}

	// �X�e�[�W�i��======================================================================
	if (MapData_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 9 &&
		C_Game_Manager::trans_flag == false)
	{
		//�J�ڃt���O��true��(�e��A�b�v�f�[�g���~�߂�)
		Store_Trans_Flag(C_Game_Manager::trans_flag = true);

		//�J�ڌ�̃X�e�[�W�i���o�[�i�[
		Store_Backup_Stage_No(C_Game_Manager::stage_no + 1);
	}

	// �G���f�B���O��======================================================================
	if (MapData_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 8 &&
		C_Game_Manager::trans_flag == false)
	{
		//�t�F�[�h�A�E�g����
		if (C_Game_Manager::color != 0)
		{
			C_Game_Manager::color--;
		}
		if (C_Game_Manager::color == 0)
		{
			//�Q�[������������
			Reset_Process();

			game_state_no = 4;
			C_Game_Manager::Store_Game_State_No(game_state_no);
		}

		Store_Color(C_Game_Manager::color);
	}
}


//=============================================================================
// �X�e�[�W�J�ڔ���2(��}�b�v)
//=============================================================================
void C_Player::Trans_Judge2()
{
	// �X�e�[�W�߂�======================================================================
	if (MapData_No2_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 5 &&
		C_Game_Manager::trans_flag == false)
	{
		//�J�ڃt���O��true��(�e��A�b�v�f�[�g���~�߂�)
		Store_Trans_Flag(C_Game_Manager::trans_flag = true);

		//�J�ڌ�̃X�e�[�W�i���o�[�i�[
		Store_Backup_Stage_No(C_Game_Manager::stage_no - 1);
	}

	// �X�e�[�W�i��======================================================================
	if (MapData_No2_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 9 &&
		C_Game_Manager::trans_flag == false)
	{
		//�J�ڃt���O��true��(�e��A�b�v�f�[�g���~�߂�)
		Store_Trans_Flag(C_Game_Manager::trans_flag = true);

		//�J�ڌ�̃X�e�[�W�i���o�[�i�[
		Store_Backup_Stage_No(C_Game_Manager::stage_no + 1);
	}
}


//=============================================================================
// �X�e�[�W�J�ڏ���
//=============================================================================
void C_Player::TransStage()
{
	//���݂̃��[���h�i���o�[�擾
	int world_no = C_Select::Get_World_No();
	C_Game_Manager::stage_no = C_Game_Manager::Get_Stage_No();

	static int trans_time = 0;             //��ʑJ�ڂ܂ł̎���
	static bool double_prevention = false; //��d�h�~

    //�J�ڊJ�n
	if (C_Game_Manager::trans_flag == true)
	{
		//�X�e�[�W�J�ڏ����I��
		if (trans_time == 100 && C_Game_Manager::trans_flag == true)
		{
			trans_time = 0;

			//�J�ڃt���O��false��(�e��A�b�v�f�[�g�ĊJ)
			Store_Trans_Flag(C_Game_Manager::trans_flag = false);

			double_prevention = true;
		}

		if (trans_time != 100) { trans_time++; }

		//�t�F�[�h�C������
		if (C_Game_Manager::color != 255 && trans_time >= 97)
		{
			Store_Color(C_Game_Manager::color += 85);

			//�J�ڌ�̃X�e�[�W�i���o�[�擾
			C_Game_Manager::stage_no = C_Game_Manager::backup_stage_no;
			stage_sound = true;

			//�����ɑJ�ڎ��̏���
			if (C_Game_Manager::stage_no == 1)
			{
				C_Game_Manager::scroll_x = -200;
				C_Game_Manager::scroll_y = -200;
				pos_x = 470.0f;
				pos_y = 360.0f;
				direction_no = 1;
			}

			//�ȉ��A���[���h���Ƃ̑J�ڏ���
			switch (world_no)
			{
			case 1:
				TransStage_World1();

				break;

			case 2:
				TransStage_World2();

				break;

			case 3:
				TransStage_World3();

				break;
			}
		}

		//�t�F�[�h�A�E�g����
		if (C_Game_Manager::color != 0 && trans_time <= 60)
		{
			Store_Color(C_Game_Manager::color -= 15);
		}

		//�X�e�[�W�i���o�[���Z�b�g(��ʂ��Ó]���邽��)
		if (C_Game_Manager::color == 0)
		{
			if (stage_sound == true)
			{
				C_Sound::PlaySound(SOUND_LABEL_SE_WARP);//���艹
			}
			stage_sound = false;
			C_Game_Manager::stage_no = 0;
		}
	}
}


//=============================================================================
// ���[���h1��ʑJ�ڏ���
//=============================================================================
void C_Player::TransStage_World1()
{
	// 1_2�֑J��======================================================================
	if (C_Game_Manager::stage_no == 2 && MapData_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 9)
	{
		C_Game_Manager::scroll_x = -100;
		C_Game_Manager::scroll_y = -200;
		pos_x = 300.0f;
		pos_y = 350.0f;
		direction_no = 1;
	}
	// 1_2�֑J��======================================================================
	if (C_Game_Manager::stage_no == 2 && MapData_No2_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 5)
	{
		C_Game_Manager::scroll_x = -100;
		C_Game_Manager::scroll_y = -0;
		pos_x = 300.0f;
		pos_y = 30.0f;
		direction_no = 0;
	}

	// 1_3�֑J��======================================================================
	if (C_Game_Manager::stage_no == 3 && MapData_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 9)
	{
		C_Game_Manager::scroll_x = -600;
		C_Game_Manager::scroll_y = -600;
		pos_x = 500.0f;
		pos_y = 350.0f;
		direction_no = 1;
	}
	// 1_3�֑J��======================================================================
	if (C_Game_Manager::stage_no == 3 && MapData_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 5)
	{
		C_Game_Manager::scroll_x = -305;
		C_Game_Manager::scroll_y = 0;
		pos_x = 295.0f;
		pos_y = 30.0f;
		direction_no = 0;
	}

	// 1_4�֑J��======================================================================
	if (C_Game_Manager::stage_no == 4 && MapData_No2_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 9)
	{
		C_Game_Manager::scroll_x = -100;
		C_Game_Manager::scroll_y = -200;
		pos_x = 300.0f;
		pos_y = 350.0f;
		direction_no = 1;
	}
}


//=============================================================================
// ���[���h2��ʑJ�ڏ���
//=============================================================================
void C_Player::TransStage_World2()
{
	// 2_2�֑J��======================================================================
	if (C_Game_Manager::stage_no == 2 && MapData_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 9)
	{
		C_Game_Manager::scroll_x = -100;
		C_Game_Manager::scroll_y = -200;
		pos_x = 300.0f;
		pos_y = 350.0f;
		direction_no = 1;
	}
	// 2_2�֑J��======================================================================
	if (C_Game_Manager::stage_no == 2 && MapData_No2_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 5)
	{
		C_Game_Manager::scroll_x = -180;
		C_Game_Manager::scroll_y = 0;
		pos_x = 550.0f;
		pos_y = 200.0f;
		direction_no = 2;
	}

	// 2_3�֑J��======================================================================
	if (C_Game_Manager::stage_no == 3 && MapData_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 9)
	{
		C_Game_Manager::scroll_x = 0;
		C_Game_Manager::scroll_y = 0;
		pos_x = 50.0f;
		pos_y = 60.0f;
		direction_no = 3;
	}
	// 2_3�֑J��======================================================================
	if (C_Game_Manager::stage_no == 3 && MapData_No2_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 5)
	{
		C_Game_Manager::scroll_x = -600;
		C_Game_Manager::scroll_y = 0;
		pos_x = 425.0f;
		pos_y = 30.0f;
		direction_no = 0;
	}

	// 2_4�֑J��======================================================================
	if (C_Game_Manager::stage_no == 4 && MapData_No2_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 9)
	{
		C_Game_Manager::scroll_x = -600;
		C_Game_Manager::scroll_y = -600;
		pos_x = 475.0f;
		pos_y = 350.0f;
		direction_no = 1;
	}
	// 2_4�֑J��======================================================================
	if (C_Game_Manager::stage_no == 4 && MapData_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 5)
	{
		C_Game_Manager::scroll_x = -250;
		C_Game_Manager::scroll_y = 0;
		pos_x = 250.0f;
		pos_y = 30.0f;
		direction_no = 0;
	}

	// 2_5�֑J��======================================================================
	if (C_Game_Manager::stage_no == 5 && MapData_No2_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 9)
	{
		C_Game_Manager::scroll_x = -100;
		C_Game_Manager::scroll_y = -200;
		pos_x = 300.0f;
		pos_y = 350.0f;
		direction_no = 1;
	}
}


//=============================================================================
// ���[���h3��ʑJ�ڏ���
//=============================================================================
void C_Player::TransStage_World3()
{
	// 3_2�֑J��======================================================================
	if (C_Game_Manager::stage_no == 2 && MapData_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 9)
	{
		C_Game_Manager::scroll_x = -200;
		C_Game_Manager::scroll_y = 0;
		pos_x = 300.0f;
		pos_y = 20.0f;
		direction_no = 0;
	}
	// 3_2�֑J��======================================================================
	if (C_Game_Manager::stage_no == 2 && MapData_No2_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 5)
	{
		C_Game_Manager::scroll_x = -580;
		C_Game_Manager::scroll_y = -600;
		pos_x = 520.0f;
		pos_y = 340.0f;
		direction_no = 1;
	}

	// 3_3�֑J��======================================================================
	if (C_Game_Manager::stage_no == 3 && MapData_No2_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 9)
	{
		C_Game_Manager::scroll_x = 0;
		C_Game_Manager::scroll_y = 0;
		pos_x = 100.0f;
		pos_y = 20.0f;
		direction_no = 0;
	}
	// 3_3�֑J��======================================================================
	if (C_Game_Manager::stage_no == 3 && MapData_No2_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 5)
	{
		C_Game_Manager::scroll_x = 0;
		C_Game_Manager::scroll_y = -500;
		pos_x = 40.0f;
		pos_y = 200.0f;
		direction_no = 3;
	}

	// 3_4�֑J��======================================================================
	if (C_Game_Manager::stage_no == 4 && MapData_No2_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 9)
	{
		C_Game_Manager::scroll_x = -600;
		C_Game_Manager::scroll_y = -200;
		pos_x = 560.0f;
		pos_y = 200.0f;
		direction_no = 2;
	}
	// 3_4�֑J��======================================================================
	if (C_Game_Manager::stage_no == 4 && MapData_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 5)
	{
		C_Game_Manager::scroll_x = -600;
		C_Game_Manager::scroll_y = 0;
		pos_x = 440.0f;
		pos_y = 30.0f;
		direction_no = 0;
	}

	// 3_5�֑J��======================================================================
	if (C_Game_Manager::stage_no == 5 && MapData_No2_TwoDim[((int)pos_y + ((int)C_Game_Manager::scroll_y*-1)) / 20][((int)pos_x + ((int)C_Game_Manager::scroll_x*-1)) / 20] == 9)
	{
		C_Game_Manager::scroll_x = -100;
		C_Game_Manager::scroll_y = -200;
		pos_x = 300.0f;
		pos_y = 350.0f;
		direction_no = 1;
	}
}