#include "DxLib.h"
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <Windows.h>
#include <string.h>
#include <Windows.h>

using namespace std;


class Dir
{
public:
	// �R���X�g���N�^
	Dir(void){}
	// �f�X�g���N�^
	virtual ~Dir(void){}

	// �t�@�C���ꗗ�擾
	// folder : �t�H���_�̐�΃p�X����͂Ƃ��� 
	// �� : "D:\\Users\\Pictures\\"
	static vector<string> read(string folder){
		// �錾
		vector<string> fileList;
		HANDLE hFind;
		WIN32_FIND_DATA fd;

		// �t�@�C���������̂��߂Ƀ��C���h�J�[�h�ǉ�
		// �� : "D:\\Users\\Pictures\\*.*"
		stringstream ss;
		ss << folder;
		string::iterator itr = folder.end();
		itr--;
		if(*itr != '\\') ss << '\\';
		ss << "*.*";

		// �t�@�C���T��
		// FindFirstFile(�t�@�C����, &fd);
		hFind = FindFirstFile(ss.str().c_str(), &fd);

		// �������s
		if(hFind == INVALID_HANDLE_VALUE){
			std::cout << "�t�@�C���ꗗ���擾�ł��܂���ł���" << std::endl;
			exit(1); // �G���[�I��
		}

		// �t�@�C���������X�g�Ɋi�[���邽�߂̃��[�v
		do{
			// �t�H���_�͏���
			if(!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			  && !(fd.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN))
			{
				//�t�@�C���������X�g�Ɋi�[
				char *file = fd.cFileName;
				string str = file;
				fileList.push_back(str);
			}
		}while(FindNextFile(hFind, &fd)); //���̃t�@�C����T��
		
		// hFind�̃N���[�Y
		FindClose(hFind); 

		return fileList;
	}
};


//string�^�̃f�[�^��char *�^�ɕϊ�
inline char* str2char(char* dest, const std::string& src, size_t num) {
    strncpy(dest, src.c_str(), num-1);
    *(dest+num-1) = '\0';
    return dest;
}


void rename_picture(char foldername[],int picture[]){

	char number[256];
	char filename[256][256];
	char oldname[256] = "C:\\picture\\";
	char newname[256];

	// �t�@�C������
	std::vector<std::string> backfilelist = Dir::read("C:\\picture\\");

	for(int i = 0; i < backfilelist.size(); i++){
		std::cout << backfilelist[i] << std::endl;

		str2char(filename[i], backfilelist[i], 256);

	}

	int k = 0;
	int j = 0;

	for(int i = 0; i < backfilelist.size(); i++){

		if(j==picture[k]){
			k++;
			j=0;
		}
		j++;

		sprintf(oldname, "C:\\picture\\");
		strcat(oldname,filename[i]);

		sprintf(newname,"");
		
		strcat(newname,foldername);
		strcat(newname,"/");
		strcat(newname,foldername);
		sprintf(number, "%d", k);
		strcat(newname,number);

		if(j<=9)        strcat(newname, "/images/img000");
		else if(j<=99)  strcat(newname, "/images/img00");
		else if(j<=999) strcat(newname, "/images/img0");
		else            strcat(newname, "/images/img");

		sprintf(number, "%d", j);
		strcat(newname,number);
		strcat(newname,".jpg");

		rename(oldname, newname);
	}
}