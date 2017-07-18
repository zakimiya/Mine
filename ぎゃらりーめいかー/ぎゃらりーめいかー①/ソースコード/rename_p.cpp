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
	// コンストラクタ
	Dir(void){}
	// デストラクタ
	virtual ~Dir(void){}

	// ファイル一覧取得
	// folder : フォルダの絶対パスを入力とする 
	// 例 : "D:\\Users\\Pictures\\"
	static vector<string> read(string folder){
		// 宣言
		vector<string> fileList;
		HANDLE hFind;
		WIN32_FIND_DATA fd;

		// ファイル名検索のためにワイルドカード追加
		// 例 : "D:\\Users\\Pictures\\*.*"
		stringstream ss;
		ss << folder;
		string::iterator itr = folder.end();
		itr--;
		if(*itr != '\\') ss << '\\';
		ss << "*.*";

		// ファイル探索
		// FindFirstFile(ファイル名, &fd);
		hFind = FindFirstFile(ss.str().c_str(), &fd);

		// 検索失敗
		if(hFind == INVALID_HANDLE_VALUE){
			std::cout << "ファイル一覧を取得できませんでした" << std::endl;
			exit(1); // エラー終了
		}

		// ファイル名をリストに格納するためのループ
		do{
			// フォルダは除く
			if(!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			  && !(fd.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN))
			{
				//ファイル名をリストに格納
				char *file = fd.cFileName;
				string str = file;
				fileList.push_back(str);
			}
		}while(FindNextFile(hFind, &fd)); //次のファイルを探索
		
		// hFindのクローズ
		FindClose(hFind); 

		return fileList;
	}
};


//string型のデータをchar *型に変換
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

	// ファイル入力
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