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
		Menu_Initialize();  //���j���[������
		Player_Initialize();  // �v���C���[������
		Barrier_Initialize();  // �o���A������
		Score_Initialize();  // �X�R�A������
		Fire_Initialize();  // ��������
		Bomb_Initialize();  // ���e������
		Gameover_Initialize();  // �Q�[���I�[�o�[������

		//���j���[��
		Menu_Update();  // ���j���[�v�Z
		Menu_Draw();  // ���j���[�`��
	
		//�Q�[���{�̕�
		while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 ){
			Keyboard_Update();

			Player_Update();  // �v���C���[�v�Z
			Player_Draw();  // �v���C���[�`��

			Score_Draw();  //�X�R�A�`��

			Barrier_Update();  // �o���A�v�Z
			Barrier_Draw();  // �o���A�`��

			Fire_Update();  // ���v�Z
			Fire_Draw();  // ���`��

			Bomb_Update();  // ���e�v�Z
			Bomb_Draw();  // ���e�`��

			if( Keyboard_Get( KEY_INPUT_ESCAPE ) > 0 ) break;
		}

		Menu_Finalize(); // ���j���[�I������
		Player_Finalize();  // �v���C���[�I������
		Barrier_Finalize();  // �v���C���[�I������
		Score_Finalize();  // �X�R�A�I������
		Fire_Finalize();  // ���I������
		Bomb_Finalize();  // ���e�I������
		Gameover_Finalize();  // �Q�[���I�[�o�[�I������
	}

	DxLib_End();
	return 0;
}
