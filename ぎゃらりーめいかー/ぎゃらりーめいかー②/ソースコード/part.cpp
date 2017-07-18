#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void part_make(char foldername[],char *pagename,int page,int picture[]){

    FILE *fp;
	int i,j;

	char filenumber[5] ={'0','0','0','0','\0' };
	char filename[256] = "\0";
	

	for(j=1;j<=page;j++){

		filename[5] = j + 48;

		for(i=1;i<=picture[j];i++){

			filenumber[2] = 48 + i/10;
			filenumber[3] = 48 + i%10;

			strcpy(filename, foldername);
			strcat(filename,"/");
			strcat(filename,foldername);

			switch(j){
				case 1  :
					strcat(filename,"1/images/"); break;
				case 2  :
					strcat(filename,"2/images/"); break;
				case 3  :
					strcat(filename,"3/images/"); break;
				case 4  : 
					strcat(filename,"4/images/"); break;
				default : 
					strcat(filename,"5/images/"); break;
			}

			strcat(filename,filenumber); 
			strcat(filename,".html");
			//filenameは『foldername/foldername(page)/images/(filenumber).html』

			fp = fopen(filename, "w");	//ファイルオープン

			//書込
			fprintf(fp, "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\"> \n");
			fprintf(fp, "<html lang=\"ja\"> \n");
			fprintf(fp, "<head> \n");
			fprintf(fp, "<meta http-equiv=\"Content-Type\" content=\"text/html;charset=Shift_JIS\"> \n");
			fprintf(fp, "<meta http-equiv=\"Content-Script-Type\" content=\"text/javascript\"> \n");
			fprintf(fp, "<link rev=\"made\" href=\"\"> \n");

			//次のリンクを指定
			//ページ番号が1桁か2桁かで場合分け
			if(i<9) fprintf(fp, "<link rel=\"next\" href=\"./000%d.html\"> \n",i+1);
			else	 fprintf(fp, "<link rel=\"next\" href=\"./00%d.html\"> \n",i+1);

			fprintf(fp, "<link rel=\"stylesheet\" href=\"../../default.css\" type=\"text/css\"> \n");
			fprintf(fp, "<title>%s</title> \n", pagename);	//pagenameをページの名前として代入
			fprintf(fp, "</head> \n");
			fprintf(fp, "<body class=\"html_album\"> \n");

			//リンク管理ここから--------------------------------------------------------------------------------------------
			fprintf(fp, "<hr><div class=\"button\"> \n");

			//前へのリンク
			if(i==1&&j==1){
				fprintf(fp, "");
			}
			else if(i==1&&j!=1)
				fprintf(fp, "<a class=\"button\" href=\"../../%s%d/images/00%d.html\">前の画像</a> \n",foldername,j-1,picture[j-1]);
			else{
				if(i<=10) fprintf(fp, "<a class=\"button\" href=\"000%d.html\">前の画像</a> \n",i-1);
				else	  fprintf(fp, "<a class=\"button\" href=\"00%d.html\">前の画像</a> \n",i-1);
			}


			fprintf(fp, "<a class=\"button\" href=\"../%s%d.html\">画像一覧に戻る</a> \n",foldername,j);	
			//トップページに戻る（1つ上のファイルを指定）

			//次へのリンク
			if(i!=picture[j]){
				if(i<9) fprintf(fp, "<a class=\"button\" href=\"000%d.html\">次の画像</a></div> \n",i+1);
				else	fprintf(fp, "<a class=\"button\" href=\"00%d.html\">次の画像</a></div> \n",i+1);
			}
			else if(j!=page)
				fprintf(fp, "<a class=\"button\" href=\"../../%s%d/images/0001.html\">次の画像</a></div> \n",foldername,j+1);

			//リンク管理ここまで--------------------------------------------------------------------------------------------


			fprintf(fp, "<hr> \n");
			fprintf(fp, "<!-- 表示画像 --><p> \n");

			//画像を指定して表示
			if(i<10) fprintf(fp, "<img class=\"html_album\" alt=\"img000%d.jpg\" src=\"img000%d.jpg\" width=\"690\" height=\"517\"></p> \n",i,i);
			else fprintf(fp, "<img class=\"html_album\" alt=\"img00%d.jpg\" src=\"img00%d.jpg\" width=\"690\" height=\"517\"></p> \n",i,i);

			fprintf(fp, "<hr> \n");

			//リンク管理ここから--------------------------------------------------------------------------------------------
			fprintf(fp, "<hr><div class=\"button\"> \n");

			//前へのリンク
			if(i==1&&j==1){
				fprintf(fp, "");
			}
			else if(i==1&&j!=1)
				fprintf(fp, "<a class=\"button\" href=\"../../%s%d/images/00%d.html\">前の画像</a> \n",foldername,j-1,picture[j-1]);
			else{
				if(i<=10) fprintf(fp, "<a class=\"button\" href=\"000%d.html\">前の画像</a> \n",i-1);
				else	  fprintf(fp, "<a class=\"button\" href=\"00%d.html\">前の画像</a> \n",i-1);
			}


			fprintf(fp, "<a class=\"button\" href=\"../%s%d.html\">画像一覧に戻る</a> \n",foldername,j);	
			//トップページに戻る（1つ上のファイルを指定）

			//次へのリンク
			if(i!=picture[j]){
				if(i<9) fprintf(fp, "<a class=\"button\" href=\"000%d.html\">次の画像</a></div> \n",i+1);
				else	fprintf(fp, "<a class=\"button\" href=\"00%d.html\">次の画像</a></div> \n",i+1);
			}
			else if(j!=page)
				fprintf(fp, "<a class=\"button\" href=\"../../%s%d/images/0001.html\">次の画像</a></div> \n",foldername,j+1);

			//リンク管理ここまで--------------------------------------------------------------------------------------------

			fprintf(fp, "</html> \n");

			fclose(fp);		//ファイルクローズ
		}
	}

}
