#pragma once
typedef int ElemType;
typedef struct {
	ElemType* elem;     
	int top;    
	int size;    
	int increment;    
} SqStack;        

#define OVERFLOW -1
#define OK 1
#define ERROR 0
#define TRUE 2
#define FALSE -2

#define INITSIZE 5  
#define INCREMENT 2   

typedef int Status;

Status InitStack_Sq(SqStack& S, int size, int inc);
Status StackEmpty_Sq(SqStack S);
Status Push_Sq(SqStack& S, ElemType e);
Status Pop_Sq(SqStack& S, ElemType& e);