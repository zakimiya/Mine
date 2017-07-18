#include "DxLib.h"
#include "Keyboard.h"

static int m_Image;
static int m_x;
static int field;
static int back;

// 初期化をする
void Player_Initialize(){
	m_Image = LoadGraph("Illust/プレイヤー.png");
	m_x = 570;
	field = LoadGraph("Illust/フィールド.jpg");
	back = LoadGraph("Illust/背景①.jpg");
}

// 動きを計算する
void Player_Update(){
	if( Keyboard_Get( KEY_INPUT_LEFT ) > 0 ){
		m_x-=10;
	}
	if( Keyboard_Get( KEY_INPUT_RIGHT ) > 0 ){
		m_x+=10;
	}

	if(m_x<0) m_x=0;
	if(m_x>570) m_x=570;
}

// 描画する
void Player_Draw(){
	DrawGraph( 0, 0, back, TRUE );
	DrawGraph( m_x, 300, m_Image, TRUE );
	DrawGraph( 0, 400, field, TRUE );
}

// 終了処理をする
void Player_Finalize(){
	DeleteGraph( back );
	DeleteGraph( m_Image );
	DeleteGraph( field );
}

