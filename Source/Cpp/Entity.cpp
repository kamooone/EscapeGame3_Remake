//=============================================================================
//
// �ÓI�����o�ϐ����̉� [Entity.cpp]
//
//=============================================================================


#include "C_Player.h"
#include "C_Game_Manager.h"


//�ÓI�ꎟ���z��Ɋi�[�p�z������̉�
int C_Mapchip::MapData_OneDim[(SCREEN_HIGHT / 20) * (SCREEN_WIDTH / 20)];
int C_Mapchip::MapData_No2_OneDim[(1000 / 20) * (1200 / 20)];

//�ÓI�X�e�[�W�i���o�[�����̉�
int C_Game_Manager::C_Game_Manager::stage_no = 1;

//�ÓI�v���C���[�����������̉�
int C_Player::direction_no = 0;

//�ÓI�v���C���[�ʒu�������̉�
float C_Player::pos_x = PLAYER_INIT_POS_X;
float C_Player::pos_y = PLAYER_INIT_POS_Y;

//�ÓI�v���C���[�_���[�W�G�t�F�N�g�����̉�
bool C_Player::collision_flag = false;

//�t���b�V���J�E���^�[�t���O
bool C_Player::flash_counter = false;

//������
bool C_Player::fire_trigger = false;

//�v���C���[�_���[�W�����̉�
int C_Player::damage = 0;

//�v���C���[�A�j���[�V�����Ԋu
unsigned int C_Player::animtblidx = 0;

//�\��UV���W
unsigned int C_Player::uvtblidx = 0;

//��ʃX�N���[���ϐ����̉�
float C_Game_Manager::scroll_x = 0;
float C_Game_Manager::scroll_y = 0;

//�t�F�[�h�C���t�F�[�h�A�E�g�Ɏg��
int C_Game_Manager::color = 255;

//�}�j���A���\���t���O
bool C_Game_Manager::C_Game_Manager::manual_flag = false;

//�}�j���A���\���i���o�[
int C_Game_Manager::C_Game_Manager::manual_no = 1;

//���݂̃X�e�[�W�i���o�[�o�b�N�A�b�v
int C_Game_Manager::backup_stage_no = false;

//��ʑJ�ڃt���O
bool C_Game_Manager::trans_flag = false;