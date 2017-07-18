#include "DxLib.h"
#include "Menu.h"
#include "Player.h"
#include "Barrier.h"
#include "Score.h"
#include "Fire.h"
#include "Bomb.h"
#include "Gameover.h"
#include "Keyboard.h"

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
	ChangeWindowMode(TRUE),DxLib_Init(),SetDrawScreen( DX_SCREEN_BACK );

	while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 ){
		Menu_Initialize();  //メニュー初期化
		Player_Initialize();  // プレイヤー初期化
		Barrier_Initialize();  // バリア初期化
		Score_Initialize();  // スコア初期化
		Fire_Initialize();  // 炎初期化
		Bomb_Initialize();  // 爆弾初期化
		Gameover_Initialize();  // ゲームオーバー初期化

		//メニュー部
		Menu_Update();  // メニュー計算
		Menu_Draw();  // メニュー描画
	
		//ゲーム本体部
		while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 ){
			Keyboard_Update();

			Player_Update();  // プレイヤー計算
			Player_Draw();  // プレイヤー描画

			Score_Draw();  //スコア描画

			Barrier_Update();  // バリア計算
			Barrier_Draw();  // バリア描画

			Fire_Update();  // 炎計算
			Fire_Draw();  // 炎描画

			Bomb_Update();  // 爆弾計算
			Bomb_Draw();  // 爆弾描画

			if( Keyboard_Get( KEY_INPUT_ESCAPE ) > 0 ) break;
		}

		Menu_Finalize(); // メニュー終了処理
		Player_Finalize();  // プレイヤー終了処理
		Barrier_Finalize();  // プレイヤー終了処理
		Score_Finalize();  // スコア終了処理
		Fire_Finalize();  // 炎終了処理
		Bomb_Finalize();  // 爆弾終了処理
		Gameover_Finalize();  // ゲームオーバー終了処理
	}

	DxLib_End();
	return 0;
}
