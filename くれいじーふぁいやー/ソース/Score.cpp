#include "DxLib.h"

static int score;
static int scorecount;
static int FigureColor;

// ������������
void Score_Initialize(){
	score=0;
	scorecount=1;
	FigureColor=GetColor(255,0,0);
}

// �������v�Z����
void Score_Update(){
	score+=scorecount;  //1�t���[�����ƂɃX�R�A+1
	
}

// �`�悷��
void Score_Draw(){
	DrawFormatString( 440, 440 ,FigureColor,"%d",score);
}

// �I������������
void Score_Finalize(){
	scorecount=0;  //���ɓ�����ƃX�R�A�J�E���g���~�߂�
	FigureColor=GetColor(0,0,0);  //�X�R�A������
}

