#ifndef WORD_H_INCLUDED
#define WORD_H_INCLUDED

#define MaxStrSize 256

//String struct
typedef struct{
    char ch[MaxStrSize];
    int length;
}SeqString;


/**
  显示菜单
  void menu();
  参数：无
  功能：显示菜单
  返回：无

*/
void menu();
/**
  统计文件行数
 int LineCount();
  参数：无
  功能：统计文件行数
  返回：int，意味程序是否正确执行

*/
int LineCount();


/**
  查看单词数目
  void SubStrCount();
  参数：无
  功能：查看单词数目
  返回：int，意味程序是否正确执行

*/
void SubStrCount();
/**
  查看单词定位
  void SubStrInd();
  参数：无
  功能：查看单词定位
  返回：int，意味程序是否正确执行

*/
void SubStrInd();

#endif // WORD_H_INCLUDED
