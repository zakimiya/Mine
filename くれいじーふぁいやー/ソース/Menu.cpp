#include "DxLib.h"
#include "Keyboard.h"

static int title;

// ������������
void Menu_Initialize(){
	title = LoadGraph("Illust/�^�C�g���@.png");
}

// �������v�Z����
void Menu_Update(){
}

// �`�悷��
void Menu_Draw(){		
	while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 ){
		Keyboard_Update();

		DrawGraph( 80, 60, title , TRUE );
		DrawString(100, 120,"���X�Ɖ΂̋ʂƔ��e���ォ��P��������܂�",GetColor(255,255,255));
		DrawString(100, 140,"���̋ʂ͓�����Ǝ��ɂ܂���",GetColor(255,255,255));
		DrawString(100, 160,"�Ƃɂ��������ĉ�����",GetColor(255,255,255));
		DrawString(100, 180,"���e�͗�����Ɣ������Ď��ɂ܂���",GetColor(255,255,255));
		DrawString(100, 200,"�ڐG���ĉ�����Ă�������",GetColor(255,255,255));
		DrawString(100, 240,"�X�y�[�X�L�[�Ŏ���",GetColor(255,0,0));

		if( Keyboard_Get( KEY_INPUT_SPACE ) > 0 ) break;
	}
	
	while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 ){
		Keyboard_Update();

		DrawGraph( 80, 60, title , TRUE );
		DrawString(100, 120,"���L�[�A���L�[�ňړ����܂�",GetColor(255,255,255));
		DrawString(100, 140,"�X�y�[�X�L�[���������ƂŁA���G�̃o���A���g���܂�",GetColor(255,255,255));
		DrawString(100, 160,"�o���A���g���Ă���Ԃ͉��̋ʂɓ�����܂���",GetColor(255,255,255));
		DrawString(100, 180,"�������A�o���A�͂��������A�g����̂͂Q��܂łł�",GetColor(255,255,255));
		DrawString(100, 220,"���������c��قǓ_���������Ȃ�܂�",GetColor(255,255,255));
		DrawString(100, 260," �����Ȃ݂ɍ�҂̃n�C�X�R�A��2609�_�ł�",GetColor(255,255,255));
		DrawString(100, 320,"�G���^�[�L�[�������ăX�^�[�g�I",GetColor(255,0,0));

		if( Keyboard_Get( KEY_INPUT_RETURN ) > 0 ) break;
	}
}

// �I������������
void Menu_Finalize(){
	DeleteGraph( title );
}

