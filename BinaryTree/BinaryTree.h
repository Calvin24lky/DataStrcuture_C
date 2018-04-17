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

/* �������������Ͷ��� */
typedef char ElemType_T;

/* �����������ṹ���� */
typedef struct BiTNode
{
	ElemType_T data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//typedef BiTNode* BitTree; //�ȼ��������*BiTree

Status InitBiTree(BiTree *T);
Status CreateBiTree(BiTree *T, FILE *fp);
Status ClearBiTree(BiTree *T);
Status BiTreeEmpty(BiTree T);
int BiTreeDepth(BiTree T);
ElemType_T Root(BiTree T);
ElemType_T Value(BiTree T, BiTree p);
Status Assign(BiTree T, BiTree *p, ElemType_T value);
void Visit_Int(ElemType_T i);
void Visit_Char(ElemType_T i);
void PreOrderTraverse(BiTree T, void(*Visit_ptr)(ElemType_T));
void InOrderTraverse(BiTree T, void(*Visit_ptr)(ElemType_T));
void PostOrderTraverse(BiTree T, void(*Visit_ptr)(ElemType_T));
