//=============================================================================
//
// �����`�揈�� [Room.cpp]
//
//=============================================================================

#include "C_Room.h"
#include "C_Sound.h"

#include<stdio.h>
#include<string.h>
#include<stdlib.h>



//==============================================================================
// ����������
//==============================================================================
void C_Room::Init(LPDIRECT3DDEVICE9 dev)
{
	HRESULT hr = D3DXCreateTextureFromFile(dev, "assets/room.png", &t_mapchip);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}

	errno_t error;
	FILE *f;
	//�}�b�v�f�[�^�t�@�C���ǂݍ���
	error = fopen_s(&f, "External_File/room.csv", "r");
	
	//�}�b�v�f�[�^�t�@�C���ǂݍ���
	if (error != 0)
	{
		MessageBox(NULL, "load file error", "error", MB_OK);
	}
	else {
		//�t�@�C���̃f�[�^��񎟌��z��Ɋi�[
		for (int i = 0; i<column / 20; i++) 
		{
			fscanf_s(f,
				"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
				&MapData_TwoDim[i][0], &MapData_TwoDim[i][1], &MapData_TwoDim[i][2], &MapData_TwoDim[i][3], &MapData_TwoDim[i][4],
				&MapData_TwoDim[i][5], &MapData_TwoDim[i][6], &MapData_TwoDim[i][7], &MapData_TwoDim[i][8], &MapData_TwoDim[i][9],
				&MapData_TwoDim[i][10], &MapData_TwoDim[i][11], &MapData_TwoDim[i][12], &MapData_TwoDim[i][13], &MapData_TwoDim[i][14],
				&MapData_TwoDim[i][15], &MapData_TwoDim[i][16], &MapData_TwoDim[i][17], &MapData_TwoDim[i][18], &MapData_TwoDim[i][19],
				&MapData_TwoDim[i][20], &MapData_TwoDim[i][21], &MapData_TwoDim[i][22], &MapData_TwoDim[i][23], &MapData_TwoDim[i][24],
				&MapData_TwoDim[i][25], &MapData_TwoDim[i][26], &MapData_TwoDim[i][27], &MapData_TwoDim[i][28], &MapData_TwoDim[i][29],
				&MapData_TwoDim[i][30], &MapData_TwoDim[i][31], &MapData_TwoDim[i][32], &MapData_TwoDim[i][33], &MapData_TwoDim[i][34],
				&MapData_TwoDim[i][35], &MapData_TwoDim[i][36], &MapData_TwoDim[i][37], &MapData_TwoDim[i][38], &MapData_TwoDim[i][39]);
		}
	}
	fclose(f);

	//�񎟌��z��f�[�^���ꎟ���ɑ��
	for (int i = 0; i<SCREEN_HIGHT / 20; i++)
	{
		for (int j = 0; j < SCREEN_WIDTH / 20; j++)
		{
			static int ij = 0;
			MapData_OneDim_Store[ij] = MapData_TwoDim[i][j];
			ij++;
		}
	}
}


//==============================================================================
// �I������
//==============================================================================
void C_Room::UnInit()
{
	if (t_mapchip)
	{
		t_mapchip->Release();
		t_mapchip = NULL;
	}
}


//==============================================================================
// �����X�V����
//==============================================================================
void C_Room::UpdateProcess()
{
	room_sound = Get_Room_Sound();

	if (room_sound == true)
	{
		C_Sound::StopSound(SOUND_LABEL_BGM002);
		C_Sound::StopSound(SOUND_LABEL_BGM000);
		C_Sound::PlaySound(SOUND_LABEL_BGM003);
		Store_Room_Sound(room_sound = false);
	}

	//�}�b�v�f�[�^�i�[
	MapData_Store(MapData_OneDim_Store);
}


//==============================================================================
// �����`�揈��
//==============================================================================
void C_Room::DrawProcess(LPDIRECT3DDEVICE9 dev)
{	
	C_Game_Manager::color = Get_Color();

	//�����`��
	RoomDraw_Process(dev);
}