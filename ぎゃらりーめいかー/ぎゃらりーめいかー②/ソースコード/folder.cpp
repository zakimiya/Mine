#include "stdio.h"
#include "direct.h"
#include "string.h"

void folder_make(char foldername[],int page){

	char foldername_s[256] = "\0";
	int i,j;

	strcpy(foldername_s, foldername);	//foldername_s��foldername���R�s�[

	_mkdir(foldername_s);	//�wfoldername�x�t�H���_���쐬

	for(i=1;i<=page;i++){
		for(j=0;j<2;j++){
			strcat(foldername_s,"/");
			strcat(foldername_s,foldername);
			switch (i){
				case 1:  strcat(foldername_s,"1");	break;
				case 2:  strcat(foldername_s,"2");	break;
				case 3:	 strcat(foldername_s,"3");	break;
				case 4:	 strcat(foldername_s,"4");	break;
				default: strcat(foldername_s,"5");	break;
			}
			_mkdir(foldername_s);
			//�wfoldername�x�̉���page�������wfoldername1�`page�x�t�H���_���쐬

//			if(j==0) strcat(foldername_s,"/images");
//			else	 strcat(foldername_s,"/thumb");
			strcat(foldername_s,"/images");
			_mkdir(foldername_s);
			//�wfoldername1~page�x�̉��Ɂwimage�x�wthumb�x�t�H���_���쐬

			strcpy(foldername_s, foldername);	//foldername_s��foldername���R�s�[�i�t�H���_�������Z�b�g�j
		}
	}
}