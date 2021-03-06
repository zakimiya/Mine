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

// 初期化をする
void Bomb_Initialize(){
	b_Image = LoadGraph("Illust/爆弾.png");
	b_x=GetRand(560);
	b_y=GetRand(150);
	mm_xx=570;
	deadflag_b=0;
	se_b = LoadSoundMem("Sound/大爆発.mp3");
}

// 動きを計算する
void Bomb_Update(){
	//爆弾の動き
	b_y+=2;
	
	if(b_y>750 && b_y<800 ){
		PlaySoundMem( se_b, DX_PLAYTYPE_BACK );
		deadflag_b=1;
	}

	//人の動き
	if( Keyboard_Get( KEY_INPUT_LEFT ) > 0 ){
		mm_xx-=10;
	}
	if( Keyboard_Get( KEY_INPUT_RIGHT ) > 0 ){
		mm_xx+=10;
	}
	if(mm_xx<0) mm_xx=0;
	if(mm_xx>570) mm_xx=570;

	//当たり判定
	if ( ( ( b_x > mm_xx && b_x < mm_xx + 70 ) || ( mm_xx > b_x && mm_xx < b_x + 80 ) ) && ( ( b_y-430 < 300 && b_y-430 > 300 + 100 ) || ( 300 > b_y-430 && 300 < b_y-430 + 100 ) ) ){
		b_x=GetRand(560);
		b_y=GetRand(100);
	}
			
	if(deadflag_b==1){
		Gameover_Draw();  // ゲームオーバー描画					
		Player_Finalize();  // 終了処理			
		Fire_Finalize();  // 終了処理
		Score_Finalize();  // 終了処理
		Gameover_Finalize();  // 終了処理
		DeleteGraph( b_Image );
	}
}

// 描画する
void Bomb_Draw(){
	DrawGraph( b_x, b_y-410, b_Image, TRUE );
}

// 終了処理をする
void Bomb_Finalize(){
	DeleteGraph( b_Image );
}

