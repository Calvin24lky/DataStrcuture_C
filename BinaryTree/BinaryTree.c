#include"BinaryTree.h"

Status InitBiTree(BiTree *T)
{
	*T = NULL;
	return OK;
}

Status CreateBiTree(BiTree *T, FILE *fp)
{
	char ch;
	fscanf_s(fp, "%c", &ch, 1);
	if (ch == '^')
		*T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if (!(*T))
			exit(OVERFLOW);
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild, fp);
		CreateBiTree(&(*T)->rchild, fp);
	}
	return OK;
}

Status ClearBiTree(BiTree *T)
{
	if (*T) //��������Ϊ��
	{
		if ((*T)->lchild)
			ClearBiTree(&(*T)->lchild);
		if ((*T)->rchild)
			ClearBiTree(&(*T)->rchild);
		free(*T);
		*T = NULL;
	}
	return OK;
}


Status BiTreeEmpty(BiTree T)
{
	return T == NULL ? TRUE : FALSE;
}

int BiTreeDepth(BiTree T)
{
	int l, r; //lΪlchild���ֵĴ�����rΪrchild���ֵĴ���
			 //ȡ�����д�ļ�Ϊ���
	if (T == NULL)
		return 0;
	else
	{
		l = BiTreeDepth(T->lchild); //���������
		r = BiTreeDepth(T->rchild); //���������
		return l > r ? l + 1 : r + 1;
	}
}

ElemType_T Root(BiTree T)
{
	if (!T)
		return ERROR; //���ڵ㲻����
	return T->data;
}

ElemType_T Value(BiTree T, BiTree p)
{
	if (!T)
		return ERROR;
	return p->data;
}

Status Assign(BiTree T, BiTree *p, ElemType_T value)
{
	if (!T)
		return ERROR;
	(*p)->data = value;
	return OK;
}

void Visit_Int(ElemType_T i)
{
	printf("%d ", i);
}

void Visit_Char(ElemType_T i)
{
	printf("%c ", i);
}

void PreOrderTraverse(BiTree T, void(*Visit_ptr)(ElemType_T))
{
	if (T == NULL)
		return;
	Visit_ptr(T->data);
	PreOrderTraverse(T->lchild, Visit_Char);
	PreOrderTraverse(T->rchild, Visit_Char);
}

void InOrderTraverse(BiTree T, void(*Visit_ptr)(ElemType_T))
{
	if (T == NULL)
		return;
	InOrderTraverse(T->lchild, Visit_Char);
	Visit_ptr(T->data);
	InOrderTraverse(T->rchild, Visit_Char);
}

void PostOrderTraverse(BiTree T, void(*Visit_ptr)(ElemType_T))
{
	if (T == NULL)
		return;
	PostOrderTraverse(T->lchild, Visit_Char);
	PostOrderTraverse(T->rchild, Visit_Char);
	Visit_ptr(T->data);
}