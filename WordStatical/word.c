#include<stdio.h>
#include<string.h>
#include "word.h"
#define N 256



void menu(){
    int xz;
    do{
        printf("***********************************\n");
        printf("*�ı��ļ��ļ������Ӵ���ͳ�Ƽ���λ*\n");
        printf("***********************************\n");
        printf("*      1.ͳ���ı�����             *\n");
        printf("*      2.�����Ӵ��ļ���           *\n");
        printf("*      3.�����Ӵ��Ķ�λ           *\n");
        printf("*      4.�˳���������             *\n");
        printf("***********************************\n");
        printf("*       ��ѡ��[1-4]             *\n");
        scanf("%d",&xz);
        switch(xz){
            case 1:
                printf("�ļ��ı�����Ϊ��%d\n",LineCount());
                break;
            case 2:SubStrCount();break;
            case 3:SubStrInd();break;
            case 4:return 0;
            default: printf("ѡ�����������ѡ��\n");
        }
    }while(1);
}



int LineCount(){

    FILE *fp;
    char fname[10] ;
    char buf[N];
    int i=0,j,k;
    printf("�����ı��ļ���");
    scanf("%s",fname);
    fp=fopen(fname,"r");
    int count = 0;
    if((fp = fopen(fname, "r")) == NULL)
        return -1;
    while(fgets(buf,N,fp) != NULL)
    {
        if(buf[strlen(buf) - 1] == '\n')
        count++;
    }
    fclose(fp);
    return count+1;
}
//����ĳ������Ŀ
void SubStrCount()
{
    FILE *fp;
    char fname[10] ;
    char ch[N];
    char ch1[N];
    int i=0;
    printf("�����ı��ļ���");
    scanf("%s",fname);
    fp=fopen(fname,"r");
    printf("����Ҫͳ�Ƽ����ĵ���");
    scanf("%s",ch);
    FILE* file;

    int total=0;
    file = fopen(fname,"r");
    if(file == NULL) {
        printf("�ļ�������\n");
        return 0;
    }
    while(!feof(file)) {
       char c = fgetc(file);
       if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
            ch1[i++]=c;
       else{
            ch1[i]='\0';
            if(strcmp(ch1,ch)==0){
                total++;
            }
            i=0;
            memset(ch1,0,sizeof(ch1));  //����ַ�����
       }
    }
    ch1[i]='\0';
    if(strcmp(ch1,ch)==0){
        total++;
    }

    printf("\n����%s���ı��ļ�%s�й�����%d��\n",ch,fname,total);
}
//���㵥��λ��
void SubStrInd()
{
    FILE *fp;
    char fname[10] ;
    char ch[N];
    char ch1[N];  //��ŵ���
    int i=0;
    printf("�����ı��ļ���");
    scanf("%s",fname);
    fp=fopen(fname,"r");
    printf("����Ҫͳ�Ƽ����ĵ���");
    scanf("%s",ch);
    FILE* file;

    int line_num = 0 ;//����
    int loc =0 ; //����λ��
    int number =0 ; // һ���е���Ŀ
    file = fopen(fname,"r");
    if(file == NULL) {
        printf("�ļ�������\n");
        return 0;
    }
    while(!feof(file)) {
       char c = fgetc(file);
       if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
            ch1[i++]=c;
       else{
            ch1[i]='\0';
            if(strcmp(ch1,ch)==0){
                number++;
                printf("\n����%s��%d��%dλ�ó���\n",ch,line_num,loc);
            }
            if(ch1[0]!='\0')
                loc ++;
            i=0;
            ch1[0] = '\0';  //����ַ�����
            if(c == '\n'){
                loc = 0;
                printf("\n����%s��%d���й�����%d��\n",ch,line_num,number);
                number=0;
                line_num++;
            }
       }
    }
    ch1[i]='\0';
    if(strcmp(ch1,ch)==0){
         printf("\n����%s��%d��%λ�ó���\n",ch,fname,loc);
    }
}

