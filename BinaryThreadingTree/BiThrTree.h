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
#define UNDERFLOW	-3			//��ջ����CreateBiTree
#endif

/* ���Ͷ��� */
typedef char ElemType_Thr;

typedef enum { Link, Thread } PointerTag;// 0(Link)Ϊָ�룬1(Thread)Ϊ����

/* �����������ṹ���� */
typedef struct BiThrNode
{
	ElemType_Thr data;
	struct BiThrNode *lchild, *rchild;
	PointerTag LTag,RTag;
}BiThrNode, *BiThrTree;

//typedef BiThrNode* BiThrTree;
Status InitBiThrTree(BiThrTree *T);
Status CreateBiThrTree(BiThrTree *T, FILE *fp);
void ClearBiThrTree(BiThrTree *T);
void Visit_Char(ElemType_Thr i);
void InOrderTraverse(BiThrTree T, void(*Visit_ptr)(ElemType_Thr));
void InThreading(BiThrTree T);
Status InOrderThreading(BiThrTree *Thrt, BiThrTree T);




