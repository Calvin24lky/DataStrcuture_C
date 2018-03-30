#include"SqStack.h"

/*************************************************
��������	������һ����ջ
�������	��ջ�ṹ��ָ��&S
�������	����
��������ֵ	��Status
*************************************************/
Status InitStack(SqStack *S)
{
	(*S).base = (ElemType_S *)malloc(STACK_INIT_SIZE * sizeof(ElemType_S));
	if (!(*S).base)
		exit(OVERFLOW);
	(*S).top = (*S).base; //��ջ��ջ��ָ����ջ��ָ����ͬ
	(*S).stacksize = STACK_INIT_SIZE;
	return OK;
}

/*************************************************
��������	������ջ
�������	��ջ�ṹ��ָ��&S
�������	����
��������ֵ	��void
*************************************************/
void DestroyStack(SqStack *S)
{
	free((*S).base);
	(*S).top = NULL;
	(*S).base = NULL;
	(*S).stacksize = 0;
}

/*************************************************
��������	��PushԪ��e��ջ
�������	��ջ�ṹ��ָ��&S,Ԫ��e
�������	����
��������ֵ	��Status
*************************************************/
Status Push(SqStack *S, ElemType_S e)
{
	if ((*S).top - (*S).base >= (*S).stacksize)
	{
		(*S).base = (ElemType_S *)realloc((*S).base, (STACK_INIT_SIZE + STACKINCREMENT) * sizeof(ElemType_S));
		if (!(*S).base)
			exit(OVERFLOW);
		(*S).top = (*S).base + (*S).stacksize;
		(*S).stacksize += STACKINCREMENT;
	}
	//�����㹻����ʼѹջ
	*((*S).top) = e;
	(*S).top = (*S).top + 1;
	return OK;
}

/*************************************************
��������	��PopԪ��e��ջ��������ֵ����
�������	��ջ�ṹ��ָ��&S,����ֵԪ��&e
�������	����
��������ֵ	��Status
*************************************************/
Status Pop(SqStack *S, ElemType_S *e)
{
	if ((*S).base == (*S).top) //ջΪ�գ���ջʧ��
	{
		return ERROR;
	}
	*e = *((*S).top - 1);
	(*S).top = (*S).top - 1;
	return OK;
}

void Visit_Int(ElemType_S e)
{
	printf("%d \n", e);
}
void Visit_Char(ElemType_S e)
{
	printf("%c \n", e);
}

/*************************************************
��������	����ջ�׵�ջ����ջԪ�ص���Visit()��������ջ
�������	��ջS,Visit()����ָ��
�������	����
��������ֵ	��Status
*************************************************/
Status StackTraverse(SqStack S, void(*visit_ptr)(ElemType_S))
{
	ElemType_S* p = S.base;
	if (S.base == S.top) //ջΪ��
	{
		return ERROR;
	}
	while (p != S.top)
	{
		visit_ptr(*p);
		p++;
	}
	return OK;
}

/*************************************************
��������	����ջΪ�շ���TRUE�����򷵻�FALSE
�������	��ջS
�������	����
��������ֵ	��Status
*************************************************/
Status StackEmpty(SqStack S)
{
	return S.base == S.top ? TRUE : FALSE;
}

/*************************************************
��������	������ջԪ�ظ�������ջ����
�������	��ջS
�������	����
��������ֵ	��int 
*************************************************/
int StackLength(SqStack S)
{
	int i = 0;
	ElemType_S *p = S.top;
	if (S.base == S.top)
	{
		return 0;
	}
	while (p != S.base)
	{
		i++;
		p--;
	}
	return i;
}

/*************************************************
��������	�����ջ��Ԫ��
�������	��ջS ����ֵԪ��&e
�������	����
��������ֵ	��Status
*************************************************/
Status GetTop(SqStack S, ElemType_S *e)
{
	if(S.base == S.top)
	{
		return ERROR;
	}
	*e = *(S.top - 1);
	return OK;
}