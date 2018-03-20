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

/* ˳������Ͷ��� */
typedef char ElemType_Sq;

/* �궨�� */
#define LIST_INIT_SIZE 10				//˳���洢�ռ�ĳ�ʼ������ 
#define LISTINCREMENT  10				//˳���洢�ռ�ķ�������

/*���Ա�洢�ṹ*/
typedef struct
{
	int length;			//��ǰ����
	int listsize;       //��ǰ����Ĵ洢����
	ElemType_Sq *elem;			//�洢�ռ����ַ
}SqList;

Status InitList_Sq(SqList *L);
void DestroyList_Sq(SqList *L);
void ClearList_Sq(SqList *L);
Status ListEmpty_Sq(SqList L);
int ListLength_Sq(SqList L);
Status GetElem_Sq(SqList L, int i, ElemType_Sq *e);
Status Compare(ElemType_Sq l, ElemType_Sq e);
int LocateElem_Sq(SqList L, ElemType_Sq e, Status (*compare_ptr)(ElemType_Sq, ElemType_Sq));
Status PriorElem_Sq(SqList L, ElemType_Sq cur_e, ElemType_Sq *pri_e);
Status NextElem_Sq(SqList L, ElemType_Sq cur_e, ElemType_Sq *next_e);
Status ListInsert_Sq(SqList *L, int i, ElemType_Sq e);
Status ListDelete_Sq(SqList *L, int i, ElemType_Sq *e);
void Visit_Int(ElemType_Sq i);
void Visit_Char(ElemType_Sq i);
Status ListTraverse_Sq(SqList L, void (*Visit_ptr)(ElemType_Sq));