#include "DxLib.h"
#include "Keyboard.h"
#include "Player.h"
#include "Fire.h"
#include "Score.h"
#include "Gameover.h"

static int b_Image;
static int b_x;
static int b_y;
static int mm_xx;
static int deadflag_b;
static int se_b;

// ������������
void Bomb_Initialize(){
	b_Image = LoadGraph("Illust/���e.png");
	b_x=GetRand(560);
	b_y=GetRand(150);
	mm_xx=570;
	deadflag_b=0;
	se_b = LoadSoundMem("Sound/�唚��.mp3");
}

// �������v�Z����
void Bomb_Update(){
	//���e�̓���
	b_y+=2;
	
	if(b_y>750 && b_y<800 ){
		PlaySoundMem( se_b, DX_PLAYTYPE_BACK );
		deadflag_b=1;
	}

	//�l�̓���
	if( Keyboard_Get( KEY_INPUT_LEFT ) > 0 ){
		mm_xx-=10;
	}
	if( Keyboard_Get( KEY_INPUT_RIGHT ) > 0 ){
		mm_xx+=10;
	}
	if(mm_xx<0) mm_xx=0;
	if(mm_xx>570) mm_xx=570;

	//�����蔻��
	if ( ( ( b_x > mm_xx && b_x < mm_xx + 70 ) || ( mm_xx > b_x && mm_xx < b_x + 80 ) ) && ( ( b_y-430 < 300 && b_y-430 > 300 + 100 ) || ( 300 > b_y-430 && 300 < b_y-430 + 100 ) ) ){
		b_x=GetRand(560);
		b_y=GetRand(100);
	}
			
	if(deadflag_b==1){
		Gameover_Draw();  // �Q�[���I�[�o�[�`��					
		Player_Finalize();  // �I������			
		Fire_Finalize();  // �I������
		Score_Finalize();  // �I������
		Gameover_Finalize();  // �I������
		DeleteGraph( b_Image );
	}
}

// �`�悷��
void Bomb_Draw(){
	DrawGraph( b_x, b_y-410, b_Image, TRUE );
}

// �I������������
void Bomb_Finalize(){
	DeleteGraph( b_Image );
}

