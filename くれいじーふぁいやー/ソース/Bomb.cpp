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

// ‰Šú‰»‚ð‚·‚é
void Bomb_Initialize(){
	b_Image = LoadGraph("Illust/”š’e.png");
	b_x=GetRand(560);
	b_y=GetRand(150);
	mm_xx=570;
	deadflag_b=0;
	se_b = LoadSoundMem("Sound/‘å”š”­.mp3");
}

// “®‚«‚ðŒvŽZ‚·‚é
void Bomb_Update(){
	//”š’e‚Ì“®‚«
	b_y+=2;
	
	if(b_y>750 && b_y<800 ){
		PlaySoundMem( se_b, DX_PLAYTYPE_BACK );
		deadflag_b=1;
	}

	//l‚Ì“®‚«
	if( Keyboard_Get( KEY_INPUT_LEFT ) > 0 ){
		mm_xx-=10;
	}
	if( Keyboard_Get( KEY_INPUT_RIGHT ) > 0 ){
		mm_xx+=10;
	}
	if(mm_xx<0) mm_xx=0;
	if(mm_xx>570) mm_xx=570;

	//“–‚½‚è”»’è
	if ( ( ( b_x > mm_xx && b_x < mm_xx + 70 ) || ( mm_xx > b_x && mm_xx < b_x + 80 ) ) && ( ( b_y-430 < 300 && b_y-430 > 300 + 100 ) || ( 300 > b_y-430 && 300 < b_y-430 + 100 ) ) ){
		b_x=GetRand(560);
		b_y=GetRand(100);
	}
			
	if(deadflag_b==1){
		Gameover_Draw();  // ƒQ[ƒ€ƒI[ƒo[•`‰æ					
		Player_Finalize();  // I—¹ˆ—			
		Fire_Finalize();  // I—¹ˆ—
		Score_Finalize();  // I—¹ˆ—
		Gameover_Finalize();  // I—¹ˆ—
		DeleteGraph( b_Image );
	}
}

// •`‰æ‚·‚é
void Bomb_Draw(){
	DrawGraph( b_x, b_y-410, b_Image, TRUE );
}

// I—¹ˆ—‚ð‚·‚é
void Bomb_Finalize(){
	DeleteGraph( b_Image );
}

