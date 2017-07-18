#include "DxLib.h"
#include "Keyboard.h"

static int title;

// 初期化をする
void Menu_Initialize(){
	title = LoadGraph("Illust/タイトル①.png");
}

// 動きを計算する
void Menu_Update(){
}

// 描画する
void Menu_Draw(){		
	while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 ){
		Keyboard_Update();

		DrawGraph( 80, 60, title , TRUE );
		DrawString(100, 120,"次々と火の玉と爆弾が上から襲いかかります",GetColor(255,255,255));
		DrawString(100, 140,"炎の玉は当たると死にます☆",GetColor(255,255,255));
		DrawString(100, 160,"とにかく避けて下さい",GetColor(255,255,255));
		DrawString(100, 180,"爆弾は落ちると爆発して死にます☆",GetColor(255,255,255));
		DrawString(100, 200,"接触して回収してください",GetColor(255,255,255));
		DrawString(100, 240,"スペースキーで次へ",GetColor(255,0,0));

		if( Keyboard_Get( KEY_INPUT_SPACE ) > 0 ) break;
	}
	
	while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 ){
		Keyboard_Update();

		DrawGraph( 80, 60, title , TRUE );
		DrawString(100, 120,"→キー、←キーで移動します",GetColor(255,255,255));
		DrawString(100, 140,"スペースキーを押すことで、無敵のバリアを使います",GetColor(255,255,255));
		DrawString(100, 160,"バリアを使っている間は炎の玉に当たりません",GetColor(255,255,255));
		DrawString(100, 180,"ただし、バリアはすぐ消え、使えるのは２回までです",GetColor(255,255,255));
		DrawString(100, 220,"長く生き残るほど点数が高くなります",GetColor(255,255,255));
		DrawString(100, 260," ※ちなみに作者のハイスコアは2609点です",GetColor(255,255,255));
		DrawString(100, 320,"エンターキーを押してスタート！",GetColor(255,0,0));

		if( Keyboard_Get( KEY_INPUT_RETURN ) > 0 ) break;
	}
}

// 終了処理をする
void Menu_Finalize(){
	DeleteGraph( title );
}

