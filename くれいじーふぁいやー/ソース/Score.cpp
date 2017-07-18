#include "DxLib.h"

static int score;
static int scorecount;
static int FigureColor;

// 初期化をする
void Score_Initialize(){
	score=0;
	scorecount=1;
	FigureColor=GetColor(255,0,0);
}

// 動きを計算する
void Score_Update(){
	score+=scorecount;  //1フレームごとにスコア+1
	
}

// 描画する
void Score_Draw(){
	DrawFormatString( 440, 440 ,FigureColor,"%d",score);
}

// 終了処理をする
void Score_Finalize(){
	scorecount=0;  //炎に当たるとスコアカウントを止める
	FigureColor=GetColor(0,0,0);  //スコアを消す
}

