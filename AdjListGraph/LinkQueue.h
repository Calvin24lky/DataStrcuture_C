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

/* �������Ͷ��� */
typedef int ElemType_Q;

typedef struct QNode
{
	ElemType_Q data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue *Q);
void DestroyQueue(LinkQueue *Q);
Status EnQueue(LinkQueue *Q, ElemType_Q e);
Status DeQueue(LinkQueue *Q, ElemType_Q *e);
void Visit_Int(ElemType_Q e);
void Visit_Char(ElemType_Q e);
Status QueueTraverse(LinkQueue Q, void(*visit_ptr)(ElemType_Q));
Status ClearQueue(LinkQueue *Q);
Status QueueEmpty(LinkQueue Q);
int QueueLength(LinkQueue Q);
Status GetHead(LinkQueue Q, ElemType_Q *e);