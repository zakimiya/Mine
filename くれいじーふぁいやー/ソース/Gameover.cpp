#include "DxLib.h"

static int score_end;
static int scorecount_end;

// ������������
void Gameover_Initialize(){
	score_end=0;
	scorecount_end=1;
}

// �������v�Z����
void Gameover_Update(){
	score_end+=scorecount_end;  //1�t���[�����ƂɃX�R�A+1
	
}

// �`�悷��
void Gameover_Draw(){
	DrawString(100, 100,"�������`���b�^�@�_(^o^)�^ ",GetColor(255,255,255));
	DrawString(100, 140,"���Ȃ��̓��_��",GetColor(255,255,255));
	DrawFormatString( 100, 140 ,GetColor(255,255,0),"�@�@�@�@�@�@�@%d",score_end);
	DrawString(100, 140,"�@�@�@�@�@�@�@�@�@�_�ł�",GetColor(255,255,255));
	DrawString(100, 200,"���G�X�P�[�v�L�[�ōĒ���",GetColor(255,0,0));
}

// �I������������
void Gameover_Finalize(){
	scorecount_end=0;  //���ɓ�����ƃX�R�A�J�E���g���~�߂�
}

