//=============================================================================
//
// �}�b�v�`�揈�� [Field2.cpp]
//
//=============================================================================

#include "C_Field2.h"
#include "C_Boss.h"
#include "C_Sound.h"

#include<stdio.h>
#include<string.h>
#include<stdlib.h>



//==============================================================================
// ����������
//==============================================================================
void C_Field2::Init(LPDIRECT3DDEVICE9 dev)
{
	HRESULT hr = D3DXCreateTextureFromFile(dev, "assets/field.png", &t_mapchip);
	if (FAILED(hr))
	{
		MessageBox(NULL, "load tex error", "error", MB_OK);
	}

	errno_t error;
	FILE *f;
	
	//�}�b�v�f�[�^�t�@�C���ǂݍ���
	error = fopen_s(&f, "External_File/field2.csv", "r");
	
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
void C_Field2::UnInit()
{
	if (t_mapchip)
	{
		t_mapchip->Release();
		t_mapchip = NULL;
	}
}


//==============================================================================
// �}�b�v�X�V����
//==============================================================================
void C_Field2::UpdateProcess()
{

	field1_sound = C_Game_Manager::Get_Field1_Sound();
	if (field1_sound == true)
	{
		C_Sound::StopSound(SOUND_LABEL_BGM000);
		C_Sound::PlaySound(SOUND_LABEL_BGM001);
		C_Game_Manager::Store_Field1_Sound(field1_sound = false);
	}

	//�{�X��Ԏ擾
	int Get_Boss_State = C_Boss::Get_Boss_State();

	//��Q������
	if (Get_Boss_State == 2)
	{
		for (int i = 0; i < 1000; i += 20)
		{
			for (int j = 0; j < 1200; j += 20)
			{
				if (MapData_TwoDim[i / 20][j / 20] == -100)
				{
					MapData_TwoDim[i / 20][j / 20] = -97;
				}
				if (MapData_TwoDim[i / 20][j / 20] == -101)
				{
					MapData_TwoDim[i / 20][j / 20] = -96;
				}
				if (MapData_TwoDim[i / 20][j / 20] == -102)
				{
					MapData_TwoDim[i / 20][j / 20] = 4;
				}
			}
		}
		//�񎟌��z��f�[�^���ꎟ���ɑ��
		for (int i = 0; i<SCREEN_HIGHT / 20; i++)
		{
			for (int j = 0; j < SCREEN_WIDTH / 20; j++)
			{
				static int ij = 0;
				MapData_OneDim_Store[ij] = MapData_TwoDim[i][j];
				if (ij <= 1199) { ij++; }
				if (ij == 1200) { ij = 0; }
			}
		}
	}

	//��Q�����Z�b�g
	if (Get_Boss_State == 0)
	{
		for (int i = 0; i < 1000; i += 20)
		{
			for (int j = 0; j < 1200; j += 20)
			{
				if (MapData_TwoDim[i / 20][j / 20] == -97)
				{
					MapData_TwoDim[i / 20][j / 20] = -100;
				}
				if (MapData_TwoDim[i / 20][j / 20] == 4)
				{
					MapData_TwoDim[i / 20][j / 20] = -102;
				}
				if (MapData_TwoDim[i / 20][j / 20] == -96)
				{
					MapData_TwoDim[i / 20][j / 20] = -101;
				}
			}
		}
		//�񎟌��z��f�[�^���ꎟ���ɑ��
		for (int i = 0; i<SCREEN_HIGHT / 20; i++)
		{
			for (int j = 0; j < SCREEN_WIDTH / 20; j++)
			{
				static int ij = 0;
				MapData_OneDim_Store[ij] = MapData_TwoDim[i][j];
				if (ij <= 1199) { ij++; }
				if (ij == 1200) { ij = 0; }
			}
		}
	}

	//�}�b�v�f�[�^�i�[
	MapData_Store(MapData_OneDim_Store);
}


//==============================================================================
// �}�b�v�`�揈��
//==============================================================================
void C_Field2::DrawProcess(LPDIRECT3DDEVICE9 dev)
{
	C_Game_Manager::color = Get_Color();

	//�t�B�[���h�`��
	FieldDraw_Process(dev);
}