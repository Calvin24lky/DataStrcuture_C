#include"LinkQueue.h"

/*************************************************
��������	����ʼ�����У����е�ͷָ��(α)��βָ������LinkQueue�ṹ����
�������	���ṹ��LinkQueueָ��
�������	����
��������ֵ	��Status
*************************************************/
Status InitQueue(LinkQueue *Q)
{
	(*Q).front = (*Q).rear = (QueuePtr)malloc(sizeof(QNode));
	if (!(*Q).front)
		exit(OVERFLOW);
	(*Q).front->next = NULL;
	//(*Q).front->data = 65535;
	return OK;	
}

/*************************************************
��������	������Ԫ��eΪ����Q�µĶ�βԪ��
�������	���ṹ��LinkQueueָ�룬Ԫ��ֵe
�������	����
��������ֵ	��Status
*************************************************/
Status EnQueue(LinkQueue *Q, ElemType_Q e)
{
	QueuePtr new_node;
	new_node = (QueuePtr)malloc(sizeof(QNode));
	if (!new_node)
		exit(OVERFLOW);
	new_node->next = NULL;
	new_node->data = e;
	(*Q).rear->next = new_node;
	(*Q).rear = new_node;
	return OK;
}

/*************************************************
��������	�������зǿգ���ɾ����ͷԪ�ز�������ֵe�����򷵻�error
�������	���ṹ��LinkQueueָ�룬����Ԫ��ֵeָ��
�������	����
��������ֵ	��Status
*************************************************/
Status DeQueue(LinkQueue *Q, ElemType_Q *e)
{
	QueuePtr real_front;
	if ((*Q).front == (*Q).rear) //����Ϊ��
		return ERROR;
	real_front = (*Q).front->next;
	*e = real_front->data;
	(*Q).front->next = real_front->next;
	if (real_front == (*Q).rear) //��ͷ�ڵ�Ϊβ�ڵ�
	{
		(*Q).rear = (*Q).front;
	}
	free(real_front);
	return OK;
}

void Visit_Int(ElemType_Q e)
{
	printf("%d  ", e);
}

void Visit_Char(ElemType_Q e)
{
	printf("%c  ", e);
}

/*************************************************
��������	�������зǿգ���������Ԫ�ز�����visit_ptrָ��ĺ���������ֵ
�������	���ṹ��LinkQueue������ָ��*visit_ptr
�������	����
��������ֵ	��Status
*************************************************/
Status QueueTraverse(LinkQueue Q, void(*visit_ptr)(ElemType_Q))
{
	QueuePtr p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	while (p != NULL)
	{
		visit_ptr(p->data);
		p = p->next;
	}
	return OK;
}

/*************************************************
��������	�����ٶ���
�������	���ṹ��LinkQueueָ��
�������	����
��������ֵ	����
*************************************************/
void DestroyQueue(LinkQueue *Q)
{
	while ((*Q).front)
	{
		(*Q).rear = (*Q).front->next;
		free((*Q).front);
		(*Q).front = (*Q).rear;
	}
}

/*************************************************
��������	����ն���
�������	���ṹ��LinkQueueָ��
�������	����
��������ֵ	��Status
*************************************************/
Status ClearQueue(LinkQueue *Q)
{
	while ((*Q).front->next)
	{
		(*Q).rear = (*Q).front->next;
		(*Q).front->next = (*Q).rear->next;
		free((*Q).rear);
	}
	(*Q).rear = (*Q).front;
	return OK;
}

/*************************************************
��������	���ж϶����Ƿ�Ϊ�գ������򷵻�TRUE�����򷵻�FALSE
�������	���ṹ��LinkQueue
�������	����
��������ֵ	��Status
*************************************************/
Status QueueEmpty(LinkQueue Q)
{
	return Q.front->next == NULL ? TRUE : FALSE;
}

/*************************************************
��������	�����ض��г���
�������	���ṹ��LinkQueue
�������	����
��������ֵ	��int
*************************************************/
int QueueLength(LinkQueue Q)
{
	QueuePtr p = Q.front->next;
	int j = 0;
	if (p == NULL)
		return 0;
	while (p != NULL)
	{
		j++;
		p = p->next;
	}
	return j;
}

/*************************************************
��������	�������зǿգ����ض�ͷԪ��e
�������	���ṹ��LinkQueue������Ԫ��ֵ*e
�������	����
��������ֵ	��Status
*************************************************/
Status GetHead(LinkQueue Q, ElemType_Q *e)
{
	if (Q.front == Q.rear) //����Ϊ��
	{
		return ERROR;
	}
	*e = Q.front->next->data;
	return OK;
}
