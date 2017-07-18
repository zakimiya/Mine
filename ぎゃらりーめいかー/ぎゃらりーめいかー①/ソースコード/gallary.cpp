#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void gallary_make(char foldername[],char *pagename,int page,int picture[],
	char *comment_1,char *comment_2,char *comment_3,char *comment_4,char *comment_5,
	char *url){

    FILE *fp;
	int i,j,k;

	char filename[256] = "\0";


	for(i=1;i<=page;i++){

		strcpy(filename, foldername);
		strcat(filename,"/");
		strcat(filename,foldername);

		switch(i){
			case 1  :
				strcat(filename,"1/");
				strcat(filename,foldername);
				strcat(filename,"1.html"); break;
			case 2  :
				strcat(filename,"2/");
				strcat(filename,foldername);
				strcat(filename,"2.html"); break;
			case 3  :
				strcat(filename,"3/");
				strcat(filename,foldername);
				strcat(filename,"3.html"); break;
			case 4  : 
				strcat(filename,"4/");
				strcat(filename,foldername);
				strcat(filename,"4.html"); break;
			default : 
				strcat(filename,"5/");
				strcat(filename,foldername);
				strcat(filename,"5.html"); break;
		}
		//filenameは『foldername/foldername(page)/foldername(page).html』

		fp = fopen(filename, "w");	//ファイルオープン

		fprintf(fp, "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\"> \n");
		fprintf(fp, "<html lang=\"ja\"> \n");
		fprintf(fp, "<head> \n");
		fprintf(fp, "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=Shift_JIS\"> \n");
		fprintf(fp, "<title>%s</title> \n",pagename);
//		fprintf(fp, "<link rev=\"made\" href=\"mailto:mrfeintng@yahoo.co.jp\"> \n");
		fprintf(fp, "<link rev=\"made\" href=\"\"> \n");
		fprintf(fp, "<link rel=\"next\" href=\"./0001.html\"> \n");
		fprintf(fp, "<link rel=\"stylesheet\" href=\"../default.css\" type=\"text/css\"> \n");
		fprintf(fp, "</head> \n");
//		fprintf(fp, "<body class=\"html_album\" background=\"../../../../logo/005.gif\" #de0013 #0e000 #00000> \n");
		fprintf(fp, "<body class=\"html_album\" background=\"\" #de0013 #0e000 #00000> \n");

		fprintf(fp, "<div class=\"title\" align=\"center\">%s</div> \n",pagename);

		fprintf(fp, "<blockquote><div class=\"com_big\" align=\"center\"> \n");

		switch(i){
			case 1  : fprintf(fp, "%s \n",comment_1); break;
			case 2  : fprintf(fp, "%s \n",comment_2); break;
			case 3  : fprintf(fp, "%s \n",comment_3); break;
			case 4  : fprintf(fp, "%s \n",comment_4); break;
			default : fprintf(fp, "%s \n",comment_5); break;
		}

		fprintf(fp, "</div> \n");
		fprintf(fp, "</blockquote> \n");
		fprintf(fp, "<div align=\"center\"> \n");
		fprintf(fp, "<hr> \n");
		fprintf(fp, "</div><div class=\"button\" align=\"center\"> \n");

		if(i!=1) fprintf(fp, "<a class=\"button\" href=\"../%s%d/%s%d.html\">前のアルバム</a> \n",foldername,i-1,foldername,i-1);

		fprintf(fp, "<a class=\"button\" href=\"%s\">戻る</a> \n",url);

		if(i!=page) fprintf(fp, "<a class=\"button\" href=\"../%s%d/%s%d.html\">次のアルバム</a></div> \n",foldername,i+1,foldername,i+1);

		fprintf(fp, "<div align=\"center\"> \n");
		fprintf(fp, "<hr> \n");
		fprintf(fp, "</div> \n");
		fprintf(fp, "<div align=\"center\"> \n");
		fprintf(fp, "<table class=\"html_album\" align=\"center\" summary=\"メイン一覧表\"> \n");


		for(j=0;j<picture[i]/5;j++){
			fprintf(fp, "<tr> \n");

			for(k=1;k<=5;k++){
				fprintf(fp, "<td class=\"html_album\"> \n");
				if(j*5+k<10){
					fprintf(fp, "<a class=\"html_album\" href=\"images/000%d.html\"> \n",j*5+k);
//					fprintf(fp, "<img class=\"html_album\" alt=\"img000%d.jpg\" src=\"thumb/img000%d_t.jpg\" width=\"190\" height=\"142\"></a> \n",j*5+k,j*5+k);
					fprintf(fp, "<img class=\"html_album\" alt=\"img000%d.jpg\" src=\"images/img000%d.jpg\" width=\"190\" height=\"142\"></a> \n",j*5+k,j*5+k);
				}
				else{
					fprintf(fp, "<a class=\"html_album\" href=\"images/00%d.html\"> \n",j*5+k);
//					fprintf(fp, "<img class=\"html_album\" alt=\"img00%d.jpg\" src=\"thumb/img00%d_t.jpg\" width=\"190\" height=\"142\"></a> \n",j*5+k,j*5+k);
					fprintf(fp, "<img class=\"html_album\" alt=\"img00%d.jpg\" src=\"images/img00%d.jpg\" width=\"190\" height=\"142\"></a> \n",j*5+k,j*5+k);
				}
				fprintf(fp, "</td> \n");
			}

			fprintf(fp, "</tr> \n");
		}

		fprintf(fp, "</table></div> \n");
		fprintf(fp, "<div align=\"center\"> \n");
		fprintf(fp, "<hr> \n");
		fprintf(fp, "</div> \n");
		fprintf(fp, "<blockquote><div class=\"com_big\" align=\"center\"> \n");
		fprintf(fp, "</div> \n");
		fprintf(fp, "</blockquote> \n");
		fprintf(fp, "<div align=\"center\"> \n");
		fprintf(fp, "<hr> \n");
		fprintf(fp, "</div> \n");
		fprintf(fp, "<div align=\"center\"> \n");

		fprintf(fp, "</div><div class=\"button\" align=\"center\"> \n");

		if(i!=1) fprintf(fp, "<a class=\"button\" href=\"../%s%d/%s%d.html\">前のアルバム</a> \n",foldername,i-1,foldername,i-1);

//		fprintf(fp, "<a class=\"button\" href=\"http://mrfeint.s376.xrea.com/gallahtm/gallery15-17.html\">戻る</a> \n");
		fprintf(fp, "<a class=\"button\" href=\"%s\">戻る</a> \n",url);

		if(i!=page) fprintf(fp, "<a class=\"button\" href=\"../%s%d/%s%d.html\">次のアルバム</a></div> \n",foldername,i+1,foldername,i+1);

		fprintf(fp, "<div align=\"center\"> \n");
		fprintf(fp, "<hr> \n");
		fprintf(fp, "</html> \n");

		fclose(fp);		//ファイルクローズ
	}
}