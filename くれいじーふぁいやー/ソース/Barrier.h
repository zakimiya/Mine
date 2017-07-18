#ifndef DEF_BARRIER_H //二重include防止

#define DEF_BARRIER_H

// 初期化をする
void Barrier_Initialize();

// 動きを計算する
void Barrier_Update();

// 描画する
void Barrier_Draw();

// 終了処理をする
void Barrier_Finalize();

#endif 