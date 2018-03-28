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
typedef int ElemType_L;

/*�������ݽṹ*/
typedef struct LNode
{
	ElemType_L data;
	struct LNode *next;
	int test;
}LNode, *LinkList;

//typedef LNode* LinkList; //�ȼ��������*ListList

Status InitList_L(LinkList *L);
Status ListInsert_L(LinkList L, int i, ElemType_L e);
Status ListDelete_L(LinkList L, int i, ElemType_L *e);
void Visit_Int(ElemType_L i);
void Visit_Char(ElemType_L i);
Status ListTraverse_L(LinkList L, void(*Visit_ptr)(ElemType_L));
void ListDestory_L(LinkList *L); //ͷ�ڵ�Ҫɾ
Status ClearList_L(LinkList L); //ͷ�ڵ㲻ɾ
Status ListEmpty_L(LinkList L);
int ListLength_L(LinkList L);
Status GetElem_L(LinkList L, int i, ElemType_L *e);
Status Compare(ElemType_L l, ElemType_L e);
int LocateElem_L(LinkList L, ElemType_L e, Status(*compare_ptr)(ElemType_L, ElemType_L));
Status PriorElem_L(LinkList L, ElemType_L cur_e, ElemType_L *pri_e);
Status NextElem_L(LinkList L, ElemType_L cur_e, ElemType_L *next_e);