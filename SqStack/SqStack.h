#include<stdio.h>
#include<stdlib.h>

/* ״̬�� */
typedef int Status;

#define	TRUE		1			//�� 
#define	FALSE		0			//��
#define	OK			1			//ͨ��
#define	ERROR		0			//����

#ifndef _MATH_H_ 				//ϵͳ�����д�״̬�붨�壬Ҫ�����ͻ 
#define	OVERFLOW	-2			//��ջ����
#define UNDERFLOW	-3			//��ջ����
#endif

/* ջԪ�����Ͷ��� */
typedef int ElemType_S;

#define STACK_INIT_SIZE  10 //����ջ�洢�ռ�ĳ�ʼ������ 
#define STACKINCREMENT  10 //����ջ�洢�ռ�ķ�������

typedef struct 
{
	int stacksize;
	ElemType_S *base;
	ElemType_S *top;
}SqStack;

Status InitStack(SqStack *S);
void DestroyStack(SqStack *S);
Status Push(SqStack *S, ElemType_S e);
Status Pop(SqStack *S, ElemType_S *e);
void Visit_Int(ElemType_S e);
void Visit_Char(ElemType_S e);
Status StackTraverse(SqStack S, void(*visit_ptr)(ElemType_S));
Status StackEmpty(SqStack S);
int StackLength(SqStack S);
Status GetTop(SqStack S, ElemType_S *e);