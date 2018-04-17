#include"BiThrTree.h"

Status InitBiThrTree(BiThrTree *T)
{
	*T = NULL;
	return OK;
}

Status CreateBiThrTree(BiThrTree *T, FILE *fp)
{
	char ch;
	fscanf_s(fp, "%c", &ch, 1);
	if (ch == '^')
		*T = NULL;
	else
	{
		*T = (BiThrTree)malloc(sizeof(BiThrNode));
		if (!(*T))
			exit(OVERFLOW);
		(*T)->data = ch;
		CreateBiThrTree(&(*T)->lchild, fp);
		if ((*T)->lchild) /* ������ */
			(*T)->LTag = Link;
		CreateBiThrTree(&(*T)->rchild, fp);
		if ((*T)->rchild) /* ���Һ��� */
			(*T)->RTag = Link;
	}
	return OK;
}

void ClearBiThrTree(BiThrTree *T)
{
	if (*T) //��������Ϊ��
	{
		if ((*T)->lchild)
			if ((*T)->LTag != Thread)
				ClearBiThrTree(&(*T)->lchild);
		if ((*T)->rchild)
			if ((*T)->RTag != Thread)
				ClearBiThrTree(&(*T)->rchild);
		free(*T);
		*T = NULL;
	}
}

void Visit_Char(ElemType_Thr i)
{
	printf("%c ", i);
}

void InOrderTraverse(BiThrTree T, void(*Visit_ptr)(ElemType_Thr))
{
	if (T == NULL)
		return;
	InOrderTraverse(T->lchild, Visit_Char);
	Visit_ptr(T->data);
	InOrderTraverse(T->rchild, Visit_Char);
}

BiThrTree pre;

void InThreading(BiThrTree T)
{
	if (T) // ������������Ϊ��
	{
		InThreading(T->lchild);
		if (!T->lchild) //������
		{
			T->LTag = Thread;
			T->lchild = pre;
		}
		if (!pre->rchild) //ǰ�����Һ���
		{
			pre->RTag = Thread;
			pre->rchild = T;
		}
		pre = T; // ����preָ��ǰ��
		InThreading(T->rchild);
	}
}

Status InOrderThreading(BiThrTree *Thrt, BiThrTree T)
{
	//�������������T����������������Thrtָ��ͷ���
	*Thrt = (BiThrTree)malloc(sizeof(BiThrNode));
	if (!*Thrt)
		exit(OVERFLOW);
	(*Thrt)->LTag = Link; /* ��ͷ��� */
	(*Thrt)->RTag = Thread;
	(*Thrt)->rchild = (*Thrt); /* ��ָ���ָ */
	if (!T) /* ����������,����ָ���ָ */
		(*Thrt)->lchild = *Thrt;
	else
	{
		(*Thrt)->lchild = T; // ͷ���ָ������
		pre = (*Thrt);
		InThreading(T); /* ��������������������� */
		pre->rchild = *Thrt; //InThreading������preΪ���һ����㣬�����Һ���ָ��ͷ�ڵ�Thrt
		pre->RTag = Thread; /* ���һ����������� */
		(*Thrt)->rchild = pre;  //Thrt���Һ���ָ�����һ�����
	}
	return OK;
}