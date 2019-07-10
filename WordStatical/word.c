#include<stdio.h>
#include<string.h>
#include "word.h"
#define N 256



void menu(){
    int xz;
    do{
        printf("***********************************\n");
        printf("*文本文件的检索，子串的统计及定位*\n");
        printf("***********************************\n");
        printf("*      1.统计文本行数             *\n");
        printf("*      2.单词子串的计数           *\n");
        printf("*      3.单词子串的定位           *\n");
        printf("*      4.退出整个程序             *\n");
        printf("***********************************\n");
        printf("*       请选择：[1-4]             *\n");
        scanf("%d",&xz);
        switch(xz){
            case 1:
                printf("文件文本行数为：%d\n",LineCount());
                break;
            case 2:SubStrCount();break;
            case 3:SubStrInd();break;
            case 4:return 0;
            default: printf("选择错误！请重新选择！\n");
        }
    }while(1);
}



int LineCount(){

    FILE *fp;
    char fname[10] ;
    char buf[N];
    int i=0,j,k;
    printf("输入文本文件名");
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
//计算某单词数目
void SubStrCount()
{
    FILE *fp;
    char fname[10] ;
    char ch[N];
    char ch1[N];
    int i=0;
    printf("输入文本文件名");
    scanf("%s",fname);
    fp=fopen(fname,"r");
    printf("输入要统计计数的单词");
    scanf("%s",ch);
    FILE* file;

    int total=0;
    file = fopen(fname,"r");
    if(file == NULL) {
        printf("文件不存在\n");
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
            memset(ch1,0,sizeof(ch1));  //清空字符数组
       }
    }
    ch1[i]='\0';
    if(strcmp(ch1,ch)==0){
        total++;
    }

    printf("\n单词%s在文本文件%s中共出现%d次\n",ch,fname,total);
}
//计算单词位置
void SubStrInd()
{
    FILE *fp;
    char fname[10] ;
    char ch[N];
    char ch1[N];  //存放单词
    int i=0;
    printf("输入文本文件名");
    scanf("%s",fname);
    fp=fopen(fname,"r");
    printf("输入要统计计数的单词");
    scanf("%s",ch);
    FILE* file;

    int line_num = 0 ;//行数
    int loc =0 ; //行内位置
    int number =0 ; // 一行中的数目
    file = fopen(fname,"r");
    if(file == NULL) {
        printf("文件不存在\n");
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
                printf("\n单词%s在%d行%d位置出现\n",ch,line_num,loc);
            }
            if(ch1[0]!='\0')
                loc ++;
            i=0;
            ch1[0] = '\0';  //清空字符数组
            if(c == '\n'){
                loc = 0;
                printf("\n单词%s在%d行中共出现%d次\n",ch,line_num,number);
                number=0;
                line_num++;
            }
       }
    }
    ch1[i]='\0';
    if(strcmp(ch1,ch)==0){
         printf("\n单词%s在%d行%位置出现\n",ch,fname,loc);
    }
}

