#ifndef WORD_H_INCLUDED
#define WORD_H_INCLUDED

#define MaxStrSize 256

//String struct
typedef struct{
    char ch[MaxStrSize];
    int length;
}SeqString;


/**
  ��ʾ�˵�
  void menu();
  ��������
  ���ܣ���ʾ�˵�
  ���أ���

*/
void menu();
/**
  ͳ���ļ�����
 int LineCount();
  ��������
  ���ܣ�ͳ���ļ�����
  ���أ�int����ζ�����Ƿ���ȷִ��

*/
int LineCount();


/**
  �鿴������Ŀ
  void SubStrCount();
  ��������
  ���ܣ��鿴������Ŀ
  ���أ�int����ζ�����Ƿ���ȷִ��

*/
void SubStrCount();
/**
  �鿴���ʶ�λ
  void SubStrInd();
  ��������
  ���ܣ��鿴���ʶ�λ
  ���أ�int����ζ�����Ƿ���ȷִ��

*/
void SubStrInd();

#endif // WORD_H_INCLUDED
