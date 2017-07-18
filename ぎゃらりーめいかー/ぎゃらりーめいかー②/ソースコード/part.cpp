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
			//filename�́wfoldername/foldername(page)/images/(filenumber).html�x

			fp = fopen(filename, "w");	//�t�@�C���I�[�v��

			//����
			fprintf(fp, "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\"> \n");
			fprintf(fp, "<html lang=\"ja\"> \n");
			fprintf(fp, "<head> \n");
			fprintf(fp, "<meta http-equiv=\"Content-Type\" content=\"text/html;charset=Shift_JIS\"> \n");
			fprintf(fp, "<meta http-equiv=\"Content-Script-Type\" content=\"text/javascript\"> \n");
			fprintf(fp, "<link rev=\"made\" href=\"\"> \n");

			//���̃����N���w��
			//�y�[�W�ԍ���1����2�����ŏꍇ����
			if(i<9) fprintf(fp, "<link rel=\"next\" href=\"./000%d.html\"> \n",i+1);
			else	 fprintf(fp, "<link rel=\"next\" href=\"./00%d.html\"> \n",i+1);

			fprintf(fp, "<link rel=\"stylesheet\" href=\"../../default.css\" type=\"text/css\"> \n");
			fprintf(fp, "<title>%s</title> \n", pagename);	//pagename���y�[�W�̖��O�Ƃ��đ��
			fprintf(fp, "</head> \n");
			fprintf(fp, "<body class=\"html_album\"> \n");

			//�����N�Ǘ���������--------------------------------------------------------------------------------------------
			fprintf(fp, "<hr><div class=\"button\"> \n");

			//�O�ւ̃����N
			if(i==1&&j==1){
				fprintf(fp, "");
			}
			else if(i==1&&j!=1)
				fprintf(fp, "<a class=\"button\" href=\"../../%s%d/images/00%d.html\">�O�̉摜</a> \n",foldername,j-1,picture[j-1]);
			else{
				if(i<=10) fprintf(fp, "<a class=\"button\" href=\"000%d.html\">�O�̉摜</a> \n",i-1);
				else	  fprintf(fp, "<a class=\"button\" href=\"00%d.html\">�O�̉摜</a> \n",i-1);
			}


			fprintf(fp, "<a class=\"button\" href=\"../%s%d.html\">�摜�ꗗ�ɖ߂�</a> \n",foldername,j);	
			//�g�b�v�y�[�W�ɖ߂�i1��̃t�@�C�����w��j

			//���ւ̃����N
			if(i!=picture[j]){
				if(i<9) fprintf(fp, "<a class=\"button\" href=\"000%d.html\">���̉摜</a></div> \n",i+1);
				else	fprintf(fp, "<a class=\"button\" href=\"00%d.html\">���̉摜</a></div> \n",i+1);
			}
			else if(j!=page)
				fprintf(fp, "<a class=\"button\" href=\"../../%s%d/images/0001.html\">���̉摜</a></div> \n",foldername,j+1);

			//�����N�Ǘ������܂�--------------------------------------------------------------------------------------------


			fprintf(fp, "<hr> \n");
			fprintf(fp, "<!-- �\���摜 --><p> \n");

			//�摜���w�肵�ĕ\��
			if(i<10) fprintf(fp, "<img class=\"html_album\" alt=\"img000%d.jpg\" src=\"img000%d.jpg\" width=\"690\" height=\"517\"></p> \n",i,i);
			else fprintf(fp, "<img class=\"html_album\" alt=\"img00%d.jpg\" src=\"img00%d.jpg\" width=\"690\" height=\"517\"></p> \n",i,i);

			fprintf(fp, "<hr> \n");

			//�����N�Ǘ���������--------------------------------------------------------------------------------------------
			fprintf(fp, "<hr><div class=\"button\"> \n");

			//�O�ւ̃����N
			if(i==1&&j==1){
				fprintf(fp, "");
			}
			else if(i==1&&j!=1)
				fprintf(fp, "<a class=\"button\" href=\"../../%s%d/images/00%d.html\">�O�̉摜</a> \n",foldername,j-1,picture[j-1]);
			else{
				if(i<=10) fprintf(fp, "<a class=\"button\" href=\"000%d.html\">�O�̉摜</a> \n",i-1);
				else	  fprintf(fp, "<a class=\"button\" href=\"00%d.html\">�O�̉摜</a> \n",i-1);
			}


			fprintf(fp, "<a class=\"button\" href=\"../%s%d.html\">�摜�ꗗ�ɖ߂�</a> \n",foldername,j);	
			//�g�b�v�y�[�W�ɖ߂�i1��̃t�@�C�����w��j

			//���ւ̃����N
			if(i!=picture[j]){
				if(i<9) fprintf(fp, "<a class=\"button\" href=\"000%d.html\">���̉摜</a></div> \n",i+1);
				else	fprintf(fp, "<a class=\"button\" href=\"00%d.html\">���̉摜</a></div> \n",i+1);
			}
			else if(j!=page)
				fprintf(fp, "<a class=\"button\" href=\"../../%s%d/images/0001.html\">���̉摜</a></div> \n",foldername,j+1);

			//�����N�Ǘ������܂�--------------------------------------------------------------------------------------------

			fprintf(fp, "</html> \n");

			fclose(fp);		//�t�@�C���N���[�Y
		}
	}

}
