#pragma once
typedef int ElemType;
typedef struct {
	ElemType* elem;     // �洢�ռ�Ļ�ַ
	int top;    // ջ��Ԫ�ص���һ��λ�ã����ջ��λ��
	int size;    // ��ǰ����Ĵ洢����
	int increment;    // ����ʱ�����ӵĴ洢����
} SqStack;         // ˳��ջ

#define OVERFLOW -1
#define OK 1
#define ERROR 0
#define TRUE 2
#define FALSE -2

#define INITSIZE 5   //ջ�ĳ�ʼ����
#define INCREMENT 2   //ջ����ʱ������

typedef int Status;

Status InitStack_Sq(SqStack& S, int size, int inc);
Status StackEmpty_Sq(SqStack S);
Status Push_Sq(SqStack& S, ElemType e);
Status Pop_Sq(SqStack& S, ElemType& e);