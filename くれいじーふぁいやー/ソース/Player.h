#ifndef DEF_PLAYER_H //二重include防止

#define DEF_PLAYER_H

// 初期化をする
void Player_Initialize();

// 動きを計算する
void Player_Update();

// 描画する
void Player_Draw();

// 終了処理をする
void Player_Finalize();

#endif 