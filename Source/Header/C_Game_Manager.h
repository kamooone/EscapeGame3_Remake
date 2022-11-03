//=============================================================================
//
// �Q�[���}�l�[�W���[�N���X [C_Game_Manager.h]
//
//=============================================================================

#pragma once
#include "Main.h"
#include <vector>


class C_Game_Manager {
private:
	
protected:
	//�Q�[���X�e�[�g
	static int game_state_no;

	//���݂̃X�e�[�W�i���o�[
	static int stage_no;

	//���݂̃X�e�[�W�i���o�[�o�b�N�A�b�v
	static int backup_stage_no;

	//��ʃX�N���[���ϐ�
	static float scroll_x;
	static float scroll_y;

	//�J���[�l
	static int color;

	//�}�j���A���\�������ۂ�
	static bool manual_flag;

	//�}�j���A���\���i���o�[
	static int manual_no;

	//��ʑJ�ڃt���O
	static bool trans_flag;

	//�T�E���h�}�l�[�W���[
	static bool room_sound, field_sound, field1_sound;

public:
	//�Q�[���X�e�[�g���i�[&�擾
	static void Store_Game_State_No(int& store_game_state_no)
	{
		game_state_no = store_game_state_no;
	}
	static int Get_Game_State_No()
	{
		return game_state_no;
	}

	//�X�e�[�W�i���o�[�i�[&�擾
	static void Store_Stage_No(int& Store_Stage_No)
	{
		stage_no = Store_Stage_No;
	}
	static int Get_Stage_No()
	{
		return stage_no;
	}

	//�o�b�N�A�b�v�X�e�[�W�i���o�[�i�[(�l�n��)
	static void Store_Backup_Stage_No(int Store_Stage_No)
	{
		backup_stage_no = Store_Stage_No;
	}

	//�X�N���[���l�i�[&�擾
	static void Store_Scroll_x(float& x) { scroll_x = x; }
	static void Store_Scroll_y(float& y) { scroll_y = y; }

	static float& Get_Scroll_x() { return scroll_x; }
	static float& Get_Scroll_y() { return scroll_y; }


	//�J���[�l�i�[
	static void Store_Color(int store_color) { color = store_color; }
	//�J���[�l�擾
	static int Get_Color() { return color; }


	//�}�j���A���\�������ۂ��i�[
	static void Store_Manual_Flag(bool& store_manual_flag) { manual_flag = store_manual_flag; }
	//�}�j���A���\�������ۂ��擾
	static bool Get_Manual_Flag() { return manual_flag; }


	//�}�j���A���i���o�[�t���O�i�[
	static void Store_Manual_No(int& store_manual_no) { manual_no = store_manual_no; }
	//�}�j���A���i���o�[�擾
	static int Get_Manual_No() { return manual_no; }

	//��ʑJ�ڃt���O�i�[
	static void Store_Trans_Flag(bool& store_trans_flag) { trans_flag = store_trans_flag; }
	//��ʑJ�ڃt���O�擾
	static bool Get_Trans_Flag() { return trans_flag; }


	//�T�E���h�}�l�[�W���[�i�[
	static void Store_Room_Sound(bool store_flag) { room_sound = store_flag; }
	//�T�E���h�}�l�[�W���[�擾
	static bool Get_Room_Sound() { return room_sound; }

	//�T�E���h�}�l�[�W���[�i�[
	static void Store_Field_Sound(bool store_flag) { field_sound = store_flag; }
	//�T�E���h�}�l�[�W���[�擾
	static bool Get_Field_Sound() { return field_sound; }

	//�T�E���h�}�l�[�W���[�i�[
	static void Store_Field1_Sound(bool store_flag) { field1_sound = store_flag; }
	//�T�E���h�}�l�[�W���[�擾
	static bool Get_Field1_Sound() { return field1_sound; }
};



class C_Mapchip : public C_Game_Manager {
private:
	
protected:
	//�e�N�X�`��
	LPDIRECT3DTEXTURE9	 t_mapchip, t_shadow;

	bool manual = true;

	int row = SCREEN_WIDTH;//�s(��)
	int column = SCREEN_HIGHT;//��(�c)

	//�}�b�v�f�[�^�񎟌��z��
	int MapData_TwoDim[SCREEN_HIGHT / 20][SCREEN_WIDTH / 20];
	
	//�ꎟ���z��ɕϊ�
	static int MapData_OneDim[(SCREEN_HIGHT / 20) * (SCREEN_WIDTH / 20)];
	
	//�ꎟ���z��ɕϊ��o�b�N�A�b�v�p
	int MapData_OneDim_Store[(SCREEN_HIGHT / 20) * (SCREEN_WIDTH / 20)];


	
	//�}�b�v�f�[�^�񎟌��z��	
	int MapData_No2_TwoDim[1000 / 20][1200 / 20];
	
	//�ꎟ���z��ɕϊ�
	static int MapData_No2_OneDim[(1000 / 20) * (1200 / 20)];
	
	//�ꎟ���z��ɕϊ��o�b�N�A�b�v�p
	int MapData_No2_OneDim_Store[(1000 / 20) * (1200 / 20)];

public:
	
	static int* MapData_Get1()
	{
		return C_Game_Manager::stage_no == 3 ? MapData_No2_OneDim : MapData_OneDim;
	}

	static int* MapData_Get2()
	{
		return (C_Game_Manager::stage_no == 3 || stage_no == 4) ? MapData_No2_OneDim : MapData_OneDim;
	}

	static int* MapData_Get3()
	{
		return (C_Game_Manager::stage_no == 2 || stage_no == 3 || stage_no == 4) ? MapData_No2_OneDim : MapData_OneDim;
	}
};



class C_Monster : public C_Mapchip {
private:

protected:
	//�e�N�X�`��
	LPDIRECT3DTEXTURE9	 t_enemy, t_explosion, t_red_hp_gage, t_yellow_hp_gage, t_apple;

public:
};