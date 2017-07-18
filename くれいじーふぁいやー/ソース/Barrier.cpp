#include "DxLib.h"
#include "Keyboard.h"

static int b_Image;
static int b_x;
static int barrierflag;
static int barriercount;
static int barrierlimit;

// 初期化をする
void Barrier_Initialize(){
	b_Image = LoadGraph("Illust/バリア.png");
	b_x = 550;
	barrierflag=0;
	barriercount=0;
	barrierlimit=2;
}

// 動きを計算する
void Barrier_Update(){
	if( Keyboard_Get( KEY_INPUT_LEFT ) > 0 ){
		b_x-=10;
	}
	if( Keyboard_Get( KEY_INPUT_RIGHT ) > 0 ){
		b_x+=10;
	}

	if(b_x<-20) b_x=-20;
	if(b_x>550) b_x=550;

	if( Keyboard_Get( KEY_INPUT_SPACE ) && barrierflag==0 && barrierlimit>0 ) barrierflag = 1 ;

	if(barrierflag==1) barriercount++;

	if(barriercount>60){
		barrierflag=0;
		barriercount=0;
		barrierlimit--;
	}
}

// 描画する
void Barrier_Draw(){
	if(barrierflag==1) DrawGraph( b_x, 280, b_Image, TRUE );
}

// 終了処理をする
void Barrier_Finalize(){
	DeleteGraph( b_Image );
}

