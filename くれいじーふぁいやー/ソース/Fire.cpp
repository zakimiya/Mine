#include "DxLib.h"
#include "Keyboard.h"
#include "Player.h"
#include "Barrier.h"
#include "Bomb.h"
#include "Score.h"
#include "Gameover.h"

static int f_Image;
static int fa_x;
static int fb_x_a;
static int fb_x_b;
static int fc_x_a;
static int fc_x_b;
static int fc_x_c;
static int f_y;
static int m_xx;
static int levelcount;
static int deadflag;
static int barrierflag_f;
static int barriercount_f;
static int barrierlimit_f;
static int se;

// 初期化をする
void Fire_Initialize(){
	f_Image = LoadGraph("Illust/火球.png");
	fa_x=GetRand(520);
	fb_x_a=GetRand(590);
	fb_x_b=GetRand(590);
	fc_x_a=GetRand(590);
	fc_x_b=GetRand(590);
	fc_x_c=GetRand(590);
	f_y=-20;
	m_xx=570;
	levelcount=0;
	deadflag=0;
	barrierflag_f=0;
	barriercount_f=0;
	barrierlimit_f=2;
	se = LoadSoundMem("Sound/大爆発.mp3");
}

// 動きを計算する
void Fire_Update(){
	//炎の動き
	f_y+=10;
	
	if(f_y>500){
		fa_x  =GetRand(590);
		fb_x_a=GetRand(590);
		fb_x_b=GetRand(590);
		fc_x_a=GetRand(590);
		fc_x_b=GetRand(590);
		fc_x_c=GetRand(590);
		f_y=-20;
	}

	//人の動き
	if( Keyboard_Get( KEY_INPUT_LEFT ) > 0 ){
		m_xx-=10;
	}
	if( Keyboard_Get( KEY_INPUT_RIGHT ) > 0 ){
		m_xx+=10;
	}
	if(m_xx<0) m_xx=0;
	if(m_xx>570) m_xx=570;

	//バリアの処理
	if( Keyboard_Get( KEY_INPUT_SPACE ) && barrierflag_f==0 && barrierlimit_f>0 ) barrierflag_f = 1 ;

	if(barrierflag_f==1) barriercount_f++;

	if(barriercount_f>60){
		barrierflag_f=0;
		barriercount_f=0;
		barrierlimit_f--;
	}

	levelcount++;

	if(barrierflag_f==0){
		//当たり判定
		if(levelcount<422){
			if ( ( ( fa_x > m_xx && fa_x < m_xx + 70 ) || ( m_xx > fa_x && m_xx < fa_x + 50 ) ) && ( ( f_y < 300 && f_y > 300 + 100 ) || ( 300 > f_y && 300 < f_y + 50 ) ) ){
				PlaySoundMem( se, DX_PLAYTYPE_NORMAL );
				deadflag=1;
			}
			
			//得点計算
			else{
				Score_Update();
				Gameover_Update();
			}
		}

		if(levelcount>422 && levelcount<844){
			if ( ( ( fb_x_a > m_xx && fb_x_a < m_xx + 70 ) || ( m_xx > fb_x_a && m_xx < fb_x_a + 50 ) ) && ( ( f_y < 300 && f_y > 300 + 100 ) || ( 300 > f_y && 300 < f_y + 50 ) ) ){
				deadflag=1;
				PlaySoundMem( se, DX_PLAYTYPE_BACK );
			}

			if ( ( ( fb_x_b > m_xx && fb_x_b < m_xx + 70 ) || ( m_xx > fb_x_b && m_xx < fb_x_b + 50 ) ) && ( ( f_y < 300 && f_y > 300 + 100 ) || ( 300 > f_y && 300 < f_y + 50 ) ) ){
				deadflag=1;
				PlaySoundMem( se, DX_PLAYTYPE_BACK );
			}

			//得点計算
			else{
				Score_Update();
				Gameover_Update();
			}
		}

		if(levelcount>844){
			if ( ( ( fc_x_a > m_xx && fc_x_a < m_xx + 70 ) || ( m_xx > fc_x_a && m_xx < fc_x_a + 50 ) ) && ( ( f_y < 300 && f_y > 300 + 100 ) || ( 300 > f_y && 300 < f_y + 50 ) ) ){
				deadflag=1;
				if(deadflag==0){
					PlaySoundMem( se, DX_PLAYTYPE_BACK );}
			}

			if ( ( ( fc_x_b > m_xx && fc_x_b < m_xx + 70 ) || ( m_xx > fc_x_b && m_xx < fc_x_b + 50 ) ) && ( ( f_y < 300 && f_y > 300 + 100 ) || ( 300 > f_y && 300 < f_y + 50 ) ) ){
				deadflag=1;
				if(deadflag==0){
					PlaySoundMem( se, DX_PLAYTYPE_BACK );}
			}

			if ( ( ( fc_x_c > m_xx && fc_x_c < m_xx + 70 ) || ( m_xx > fc_x_c && m_xx < fc_x_c + 50 ) ) && ( ( f_y < 300 && f_y > 300 + 100 ) || ( 300 > f_y && 300 < f_y + 50 ) ) ){
				deadflag=1;
				if(deadflag==0){
					PlaySoundMem( se, DX_PLAYTYPE_BACK );}
			}

			//得点計算
			else{
				Score_Update();
				Gameover_Update();
			}
		}
	}

	if(deadflag==1){
		Gameover_Draw();  // ゲームオーバー描画					
		Player_Finalize();  // 終了処理
		Bomb_Finalize();  // 終了処理
		Barrier_Finalize();  // 終了処理
		Score_Finalize();  // 終了処理
		Gameover_Finalize();  // 終了処理
		DeleteGraph( f_Image );
	}
}

// 描画する
void Fire_Draw(){
	if(levelcount<422){
		DrawGraph( fa_x, f_y, f_Image, TRUE );
	}

	if(levelcount>422 && levelcount<844){
		DrawGraph( fb_x_a, f_y, f_Image, TRUE );
		DrawGraph( fb_x_b, f_y, f_Image, TRUE );
	}

	if(levelcount>844){
		DrawGraph( fc_x_a, f_y, f_Image, TRUE );
		DrawGraph( fc_x_b, f_y, f_Image, TRUE );
		DrawGraph( fc_x_c, f_y, f_Image, TRUE );
	}
}

// 終了処理をする
void Fire_Finalize(){
	DeleteGraph( f_Image );
}

