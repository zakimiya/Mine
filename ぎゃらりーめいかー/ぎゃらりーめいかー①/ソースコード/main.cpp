#include "DxLib.h"
#include "stdio.h"
#include "stdlib.h"

#include "part.h"
#include "gallary.h"
#include "folder.h"
#include "rename_p.h"

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
	SetMainWindowText( "ぎゃらりーめいかー" ) ;
	ChangeWindowMode(TRUE);	//小ウィンドウモード
	DxLib_Init();   // DXライブラリ初期化処理
	SetDrawScreen( DX_SCREEN_BACK ); //描画先を裏画面に設定

	char pagename[20] = "";		//ページの名前
//	char foldername_1[20] = "";	//フォルダの名前(番号含む)
	char foldername_2[20] = "";	//フォルダの名前(年度含む)
	int page = 0;				//ページの枚数
	int picture[6] ={0,0,0,0,0,0};			//1ページあたりの写真の枚数
	char comment_1[256] = "",comment_2[256] = "",comment_3[256] = "",comment_4[256] = "",comment_5[256] = "";	//ページごとに表示するコメント
	char url[256] = ""; //トップページのURL
	int end = 0;
	int i;

	int back = LoadGraph( "illust/back.jpg" ) ;
	int title = LoadGraph( "illust/title.jpg" ) ;

	int y = 50;
	int upflag = 0;
	int downflag = 0;


	while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 ){

		DrawRotaGraph( 350 , 250 ,0.8, 0.0 ,back, FALSE ) ;
		DrawGraph( 460 , 440 ,title, FALSE ) ;

		DrawString( 10 , 10 , "十字キーの上下で選択してスペースキーで入力開始，エンターキーで入力終了" , GetColor( 240 , 240 , 240 ) );

		DrawString( 40 , 50 , "フォルダ名：" , GetColor( 255 , 255 , 255 ) );
		DrawString( 40 , 80 , "ページ名：" , GetColor( 255 , 255 , 255 ) );
		DrawString( 40 , 110 , "ページ数：" , GetColor( 255 , 255 , 255 ) );
		DrawString( 40 , 140 , "トップページのURL：" , GetColor( 255 , 255 , 255 ) );

		DrawString( 10 , y , "⇒" , GetColor( 255 , 255 , 255 ) );
		
		if( CheckHitKey( KEY_INPUT_DOWN ) == 1 ){
			if(downflag==0){
				if(y==140 + page*60) y = 450;
				else if(y==450) y = 50;
				else y += 30;
			}
			downflag = 1;
		}
		else downflag = 0;

		
		if( CheckHitKey( KEY_INPUT_UP ) == 1 ){
			if(upflag==0){
				if(y==50) y = 450;
				else if(y==450) y = 140 + page*60;
				else y -= 30;
			}
			upflag = 1;
		}
		else upflag = 0;


		if(foldername_2!="") DrawFormatString( 200 , 50 , GetColor( 255 , 255 , 255 ),"%s" ,foldername_2) ;
		if(pagename!="") DrawFormatString( 200 , 80 , GetColor( 255 , 255 , 255 ),"%s" ,pagename) ;
		if(page!=0) DrawFormatString( 200 , 110 , GetColor( 255 , 255 , 255 ),"%d" ,page) ;
		if(url!="") DrawFormatString( 200 , 140 , GetColor( 255 , 255 , 255 ),"%s" ,url) ;

		
		for(i=1;i<=page;i++){
			DrawFormatString( 40 , 110+i*60 , GetColor( 255 , 255 , 255 ), "%dページ目の写真の枚数：" ,i );
			if(picture[i]!=0) DrawFormatString( 340 , 110+i*60 , GetColor( 255 , 255 , 255 ),"%d" ,picture[i]) ;
			DrawFormatString(  40 , 140+i*60 , GetColor( 255 , 255 , 255 ),"%dページ目のコメント：" ,i) ;
		}
		
		if(comment_1!="") DrawFormatString( 340 , 200 , GetColor( 0 , 0 , 255 ),"%s" ,comment_1) ;
		if(comment_2!="") DrawFormatString( 340 , 260 , GetColor( 0 , 0 , 255 ),"%s" ,comment_2) ;
		if(comment_3!="") DrawFormatString( 340 , 320 , GetColor( 0 , 0 , 255 ),"%s" ,comment_3) ;
		if(comment_4!="") DrawFormatString( 340 , 380 , GetColor( 0 , 0 , 255 ),"%s" ,comment_4) ;
		if(comment_5!="") DrawFormatString( 340 , 440 , GetColor( 0 , 0 , 255 ),"%s" ,comment_5) ;

		DrawString( 60 , 450 , "実行！" , GetColor( 255 , 0 , 0 ) );

		if( CheckHitKey( KEY_INPUT_SPACE ) == 1 ){
			switch(y){
				case 50   : KeyInputString( 140 , 50 , 20 , foldername_2 , FALSE ); break;
				case 80   : KeyInputString( 140 , 80 , 20 , pagename , FALSE ); break;
				case 110  : page = KeyInputNumber( 140 , 110 , 5 , 1 , FALSE ) ; break;
				case 140  : KeyInputString( 200 , 140 , 256 , url , FALSE ); break;
				case 170  : picture[1] = KeyInputNumber( 280 , 170 , 60 , 1 , FALSE ) ; break;
				case 200  : KeyInputString( 280 , 200 , 50 , comment_1 , FALSE ) ; break;
				case 230  : picture[2] = KeyInputNumber( 280 , 230 , 60 , 1 , FALSE ) ; break;
				case 260  : KeyInputString( 280 , 260 , 50 , comment_2 , FALSE ) ; break;
				case 290  : picture[3] = KeyInputNumber( 280 , 290 , 60 , 1 , FALSE ) ; break;
				case 320  : KeyInputString( 280 , 320 , 50 , comment_3 , FALSE ) ; break;
				case 350  : picture[4] = KeyInputNumber( 280 , 350 , 60 , 1 , FALSE ) ; break;
				case 380  : KeyInputString( 280 , 380 , 50 , comment_4 , FALSE ) ; break;
				case 410  : picture[5] = KeyInputNumber( 280 , 410 , 60 , 1 , FALSE ) ; break;
				case 440  : KeyInputString( 280 , 440 , 50 , comment_5 , FALSE ) ; break;
				case 450  : end = 1 ; break;
			}
		}	

		if(end==1) break;

	}

	folder_make(foldername_2,page);
	part_make(foldername_2,pagename,page,picture);
	gallary_make(foldername_2,pagename,page,picture,comment_1,comment_2,comment_3,comment_4,comment_5,url);

	rename_picture(foldername_2,picture);

	DxLib_End();    // DXライブラリ終了処理
	return 0;
}