#include "DxLib.h"

static int score_end;
static int scorecount_end;

// 初期化をする
void Gameover_Initialize(){
	score_end=0;
	scorecount_end=1;
}

// 動きを計算する
void Gameover_Update(){
	score_end+=scorecount_end;  //1フレームごとにスコア+1
	
}

// 描画する
void Gameover_Draw(){
	DrawString(100, 100,"ヤラレチャッタ　＼(^o^)／ ",GetColor(255,255,255));
	DrawString(100, 140,"あなたの得点は",GetColor(255,255,255));
	DrawFormatString( 100, 140 ,GetColor(255,255,0),"　　　　　　　%d",score_end);
	DrawString(100, 140,"　　　　　　　　　点です",GetColor(255,255,255));
	DrawString(100, 200,"※エスケープキーで再挑戦",GetColor(255,0,0));
}

// 終了処理をする
void Gameover_Finalize(){
	scorecount_end=0;  //炎に当たるとスコアカウントを止める
}

