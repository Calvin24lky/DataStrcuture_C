#include"LinkList.h"

/*************************************************
��������	������������������ͷ�ڵ�L
�������	��ͷ�ڵ�ṹ���ַ&L
�������	����
��������ֵ	��Status
*************************************************/
Status InitList_L(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(LNode));
	if (!(*L))
		exit(OVERFLOW);
	(*L)->next = NULL;
	(*L)->test = 255;
	return OK;
}

/*************************************************
��������	��������L�е�i��λ��֮ǰ����Ԫ��e
�������	��ͷ�ڵ�L��Ԫ��λ��i��Ԫ��ֵe
�������	����
��������ֵ	��Status
*************************************************/
Status ListInsert_L(LinkList L, int i, ElemType_L e)
{
	LinkList p = L;
	LinkList new_node;
	int j = 0;//��ͷ�ڵ㿪ʼ�ҵ���i-1���ڵ�

	while (p && j < i -1)
	{
		p = p->next;
		j++;
	}
	//p��ָ��i-1�ڵ㣬��ʼ�����½ڵ�

	new_node = (LinkList)malloc(sizeof(LNode));
	if (!new_node)
		exit(OVERFLOW);
	new_node->data = e;
	new_node->next = p->next;
	p->next = new_node;

	return OK;
}

void Visit_Int(ElemType_L i)
{
	printf("%d  ", i);
}

void Visit_Char(ElemType_L i)
{
	printf("%c  ", i);
}

/*************************************************
��������	���������������Ԫ��
�������	��ͷ�ڵ�L������Visit()ָ��
�������	����
��������ֵ	��Status
*************************************************/
Status ListTraverse_L(LinkList L, void(*Visit_ptr)(ElemType_L))
{
	LinkList p = L->next;

	while (p != NULL)
	{
		Visit_ptr(p->data);
		p = p->next;
	}

	return OK;
}

/*************************************************
��������	���������нڵ�
�������	��ͷ�ڵ�ṹ���ַ&L
�������	����
��������ֵ	��void
*************************************************/
void ListDestory_L(LinkList *L)
{
	LinkList p = *L;
	while (p)
	{
		p = (*L)->next;
		free(*L);
		*L = p;

	}
}

/*************************************************
��������	�������������ͷ�ڵ�
�������	��ͷ�ڵ�L
�������	����
��������ֵ	��void
*************************************************/
Status ClearList_L(LinkList L)
{
	if (!L)
		return ERROR;

	LinkList pre,p; //preΪǰ���ڵ�

	pre = L->next;

	while (pre)
	{
		p = pre->next;
		free(pre);
		pre = p;
	}
	L->next = NULL;

	return OK;
}

/*************************************************
��������	��ɾ��ָ��λ��i�Ľڵ㲢�÷��ظýڵ�ֵe
�������	��ͷ�ڵ�L��ɾ��λ��i,�ڵ�dataֵ
�������	����
��������ֵ	��Status
*************************************************/
Status ListDelete_L(LinkList L, int i, ElemType_L *e)
{
	LinkList pre,p; //pre:��i���ڵ��ǰ��
	pre = L;
	int j = 1;
	//�ҵ�i-1����
	while (pre->next && j < i)
	{
		pre = pre->next;
		j++;
	}

	if (!pre->next || j > i) //!pre-next��j>=���������j>i��j<=0�����
	{
		return ERROR;
	}
	//������λ����ȷ
	p = pre->next;
	pre->next = p->next;
	*e = p->data;
	free(p);

	return OK;
}

/*************************************************
��������	���ж�����L�Ƿ�Ϊ�ձ�
�������	��ͷ�ڵ�L
�������	����
��������ֵ	��Status
*************************************************/
Status ListEmpty_L(LinkList L)
{
	if (L != NULL && L->next == NULL)
	{
		return TRUE;
	}
	return FALSE;
}

/*************************************************
��������	���鿴������
�������	��ͷ�ڵ�L
�������	����
��������ֵ	��int
*************************************************/
int ListLength_L(LinkList L)
{
	LinkList p;
	int j=0;
	p = L;
	while (p->next)
	{
		p = p->next;
		j++;
	}
	return j;
}

/*************************************************
��������	����e��������L�е�i��Ԫ�ص�ֵ
�������	��ͷ�ڵ�L��Ԫ��λ��i�����ܷ���ֵ��ָ��
�������	����
��������ֵ	��Status
*************************************************/
Status GetElem_L(LinkList L, int i, ElemType_L *e)
{
	LinkList pre, p; //pre:��i���ڵ��ǰ��
	pre = L;
	int j = 1;
	//�ҵ�i-1����
	while (pre->next && j < i)
	{
		pre = pre->next;
		j++;
	}

	if (!pre->next || j > i) //!pre-next��j>=���������j>i��j<=0�����
	{
		return ERROR;
	}
	//������λ����ȷ
	p = pre->next;
	*e = p->data;
	return OK;
}

Status Compare(ElemType_L l, ElemType_L e)
{
	return e == l ? TRUE : FALSE;
}

/*************************************************
��������	������L�е�һ����e����compare()��Ԫ�ص�λ��j���������ڸ�Ԫ���򷵻�0
�������	��ͷ�ڵ�L���ж���Ԫ��e�� compare()����ָ��
�������	����
��������ֵ	��int
*************************************************/
int LocateElem_L(LinkList L, ElemType_L e, Status(*compare_ptr)(ElemType_L, ElemType_L))
{
	LinkList p = L->next;
	int j=1;
	while (p && !compare_ptr(p->data, e))
	{
		p = p->next;
		j++;
	}
	if (p)
	{
		return j;
	}
	else
	{
		return FALSE;
	}
	
}

/*************************************************
��������	����cur_e��L��Ԫ���Ҳ��ǵ�һ��������pri_e��������ǰ�������򷵻�ERROR��pre_eΪ-1
�������	��ͷ�ڵ�L����ǰԪ��cur_e��ǰ��Ԫ��&pri_e
�������	����
��������ֵ	��Status
*************************************************/
Status PriorElem_L(LinkList L, ElemType_L cur_e, ElemType_L *pri_e)
{
	LinkList p, pre;
	pre = L;
	p = L->next;
	while (p && p->data != cur_e)
	{
		pre = p;
		p = p->next;
	}
	if (p != NULL && p != L->next) //cur_e�����ڻ�cur_eΪͷ�ڵ�
	{
		*pri_e = pre->data;
		return OK;
	}
	*pri_e = -1; //cur_e�����ڣ�pri_e����-1
	return ERROR;
}

/*************************************************
��������	����cur_e��L��Ԫ���Ҳ��ǵ�һ��������next_e�������ĺ�̣����򷵻�ERROR��next_eΪ-1
�������	��ͷ�ڵ�L����ǰԪ��cur_e��ǰ��Ԫ��&next_e
�������	����
��������ֵ	��Status
*************************************************/
Status NextElem_L(LinkList L, ElemType_L cur_e, ElemType_L *next_e)
{
	LinkList p;
	p = L->next;
	while (p && p->data != cur_e)
	{
		p = p->next;
	}
	if (p && p->next != NULL) //cur_e������ && cur_eΪβ�ڵ�
	{
		*next_e = p->next->data;
		return OK;
	}
	*next_e = -1; //cur_e�����ڣ�pri_e����-1
	return ERROR;
}