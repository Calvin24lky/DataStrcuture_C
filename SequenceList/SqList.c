#include"SqList.h"

/*************************************************
��������	������һ���յ�˳�����Ա�L
�������	�����Ա�Lָ��
�������	����
��������ֵ	��Status
*************************************************/
Status InitList_Sq(SqList *L)
{
	(*L).elem = (ElemType_Sq *)malloc(LIST_INIT_SIZE * sizeof(ElemType_Sq));
	if (!(*L).elem) exit(OVERFLOW);
	(*L).length = 0;
	(*L).listsize = LIST_INIT_SIZE;
	return OK;
}
/*************************************************
��������	���������Ա�L
�������	�����Ա�Lָ��
�������	����
��������ֵ	����
*************************************************/
void DestroyList_Sq(SqList *L)
{
	free((*L).elem);

	(*L).elem = NULL;
	(*L).length = 0;
	(*L).listsize = 0;
}

/*************************************************
��������	��������Ա�L
�������	�����Ա�Lָ��
�������	����
��������ֵ	����
*************************************************/
void ClearList_Sq(SqList *L)
{
	(*L).length = 0;
}

/*************************************************
��������	���ж����Ա�L�Ƿ�Ϊ�ձ�
�������	�����Ա�L�Ľṹ��ֵ��ֻ����д����ֵ����
�������	����
��������ֵ	��Status
*************************************************/
Status ListEmpty_Sq(SqList L)
{
	return 	L.length == 0 ? TRUE : FALSE;
}

/*************************************************
��������	���鿴���Ա�L����
�������	�����Ա�L�Ľṹ��ֵ��ֻ����д����ֵ����
�������	����
��������ֵ	��int
*************************************************/
int ListLength_Sq(SqList L)
{
	return 	L.length;
}

/*************************************************
��������	����e�������Ա�L�е�i��Ԫ�ص�ֵ
�������	�����Ա�L�Ľṹ��ֵ��Ԫ��λ��i�����ܷ���ֵ��ָ��
�������	����
��������ֵ	��Status
*************************************************/
Status GetElem_Sq(SqList L, int i, ElemType_Sq *e)
{
	if (i < 1 || i > L.length + 1)
	{
		return ERROR;
	}
	else
	{
		*e = L.elem[i - 1];
		//*e = *(L.elem + i - 1);  �������ȼ�
	}
	return OK;
}

/*************************************************
��������	������Ԫ���ж�����
�������	������Ԫ��l���ж���Ԫ��e
�������	����
��������ֵ	��Status
*************************************************/
Status Compare(ElemType_Sq l, ElemType_Sq e)
{
	return e == l ? TRUE : FALSE;
}

/*************************************************
��������	������L�е�һ����e����compare()��Ԫ�ص�λ��i���������ڸ�Ԫ���򷵻�0
�������	�����Ա�L���ж���Ԫ��e�� compare()����ָ��
�������	����
��������ֵ	��int
*************************************************/
int LocateElem_Sq(SqList L, ElemType_Sq e, Status(*compare_ptr)(ElemType_Sq, ElemType_Sq))
{
	int i = 1;
	//��ȷ��ѭ�����ٴΣ�ʹ��whileѭ��
	while (i <= L.length && !compare_ptr(L.elem[i-1], e))
	{
		i++;
	}
	if (i <= L.length)
	{
		return i;
	}
	else
	{
		return FALSE;
	}
}

/*************************************************
��������	����cur_e��L��Ԫ���Ҳ��ǵ�һ��������pri_e��������ǰ�������򷵻�ERROR��pre_e�޶���
�������	�����Ա�L����ǰԪ��cur_e��ǰ��Ԫ��pri_e
�������	����
��������ֵ	��Status
*************************************************/
Status PriorElem_Sq(SqList L, ElemType_Sq cur_e, ElemType_Sq *pri_e)
{
	int i = 0;

	while (i <= L.length && L.elem[i] != cur_e)
	{
		i++;
	}
	if (i < L.length && i != 0)//���д���cur_eֵ��cur_e���ǵ�һ��Ԫ��
	{
		//��cur_e��ǰ������pri_e
		*pri_e = L.elem[i - 1];
		return OK;
	}
	return ERROR;
}

/*************************************************
��������	����cur_e��L��Ԫ���Ҳ������һ��������next_e�������ĺ�̣����򷵻�ERROR��next_e�޶���
�������	�����Ա�L����ǰԪ��cur_e�����Ԫ��next_e
�������	����
��������ֵ	��Status
*************************************************/
Status NextElem_Sq(SqList L, ElemType_Sq cur_e, ElemType_Sq *next_e)
{
	int i = 0;

	while (i <= L.length && L.elem[i] != cur_e)
	{
		i++;
	}

	if (i < L.length && i != L.length - 1)//���д���cur_eֵ��cur_e�������һ��Ԫ��
	{
		*next_e = L.elem[i + 1];
		return OK;
	}
	return ERROR;
}

/*************************************************
��������	����˳�����Ա�L�е�i��λ��֮ǰ����Ԫ��e��L���ȼ�1
�������	�����Ա�Lָ�룬Ԫ��λ��i��Ԫ��ֵe
�������	����
��������ֵ	��Status
*************************************************/
Status ListInsert_Sq(SqList *L, int i, ElemType_Sq e)
{
	ElemType_Sq *newbase;
	ElemType_Sq *q, *tail;
	//λ��i���Ϸ������ش���
	if (i < 1 || i > (*L).length + 1)
	{
		return ERROR;
	}
	if ((*L).length > (*L).listsize)
	{
		//�����������ӷ���
		newbase = (ElemType_Sq *)realloc((*L).elem, ((*L).listsize + LISTINCREMENT) * sizeof(ElemType_Sq));
		if (!newbase)
		{
			//����ʧ�ܣ�����
			exit(OVERFLOW);
		}
		(*L).elem = newbase;
		(*L).listsize = (*L).listsize + LISTINCREMENT;
		//����ɹ�����������Ӹ�Ԫ��
	}

	q = &((*L).elem[i - 1]);//qΪ����λ��
	tail = &((*L).elem[(*L).length - 1]); //tailΪ��βԪ��λ��
	//tail = (*L).elem + (*L).length - 1; 	//�������ȼ�
	for (; tail >= q; tail--)
	{
		*(tail + 1) = *tail; //��i��n��Ԫ����������ƶ�һλ
	}
	*q = e; //��e������i��Ԫ�أ���ɲ���
	(*L).length++;
	return OK;
}


/*************************************************
��������	��ɾ�����Ա��i��Ԫ�أ�����e������ֵ��L���ȼ�1
�������	�����Ա�Lָ�룬Ԫ��λ��i��Ԫ��ֵe
�������	����
��������ֵ	��Status
*************************************************/
Status ListDelete_Sq(SqList *L, int i, ElemType_Sq *e)
{
	ElemType_Sq *q, *tail;
	//λ��i���Ϸ������ش���
	if (i < 1 || i >(*L).length + 1)
	{
		return ERROR;
	}
	q = &((*L).elem[i - 1]);				//qΪ����λ��
	*e = *q;								//ȡ�õ�i��Ԫ�ص�ֵ
	tail = &((*L).elem[(*L).length - 1]);	//tailΪ��βԪ��λ��
	//tail = (*L).elem + (*L).length - 1; 	//�������ȼ�
	for (++q; q <= tail; q++)
	{
		//�ɵ�q+1��Ԫ�������θ���ǰһ��Ԫ��
		*(q - 1) = *q;
	}
	(*L).length--;
	return OK;
}

/*************************************************
��������	������Ԫ��
�������	��Ԫ��ָ��i
�������	��Ԫ��ֵ
��������ֵ	����
*************************************************/
void Visit_Int(ElemType_Sq i)
{
	printf("%d  ", i);
}

void Visit_Char(ElemType_Sq i)
{
	printf("%c  ", i);
}

/*************************************************
��������	��������������Ա�Ԫ��
�������	�����Ա�Lָ�룬����Visit()ָ��
�������	����
��������ֵ	��Status
*************************************************/
Status ListTraverse_Sq(SqList L, void(*Visit_ptr)(ElemType_Sq))
{
	int i;
	for (i = 0; i < L.length; i++)
	{
		Visit_ptr(L.elem[i]);
	}
	return OK;
}



