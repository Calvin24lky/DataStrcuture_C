#include"HeapString.h"
#include<string.h>

/*******************************************
�������: ��ʼ����S
*******************************************/
void InitString(HString *T)
{ 
	(*T).length = 0;
	(*T).ch = NULL;
}

/*******************************************
��ʼ����: chars���ַ�������
�������: ����һ����ֵ���ڴ�����chars�Ĵ�T
*******************************************/
Status StrAssign(HString *T, char *chars)
{
	int i = 0;
	char *c = chars;
	if ((*T).ch)
		free((*T).ch);
	while (*c) //�����ַ�������
	{
		i++;
		c++;
	}
	(*T).ch = (char *)malloc(i * sizeof(char));
	if (!(*T).ch)
		exit(OVERFLOW);
	memcpy((*T).ch, chars, i); //��chars�ַ������Ƶ�T.ch��
	(*T).length = i;
	return OK;
}

/*******************************************
��ʼ����: ��S����
�������: ��S��Ϊ�մ�
*******************************************/
Status ClearString(HString *T)
{
	if ((*T).ch)
	{
		free((*T).ch);
		(*T).ch = NULL;
	}
	(*T).length = 0;
	return OK;
}

/*******************************************
��ʼ����: ��S����
�������: ����S��Ԫ�ظ���,��Ϊ���ĳ���
*******************************************/
int StrLength(HString S)
{
	return S.length;
}

/*******************************************
��ʼ����: ��S��T������
�������: ��S>T,�򷵻�ֵ>0;��S=T,�򷵻�ֵ=0;��S<T,�򷵻�ֵ<0
*******************************************/
int StrCompare(HString S, HString T)
{
	int i;
	for (i = 0; i < S.length && i < T.length; i++)
	{
		if (S.ch[i] != T.ch[i])
		{
			return S.ch[i] - T.ch[i];
		}
	}
	//���������
	return S.length - T.length;
}

/*******************************************
��ʼ����: ��S1��S2������
�������: ��T������S1��S2���Ӷ��ɵ��´�
*******************************************/
Status Concat(HString *T, HString S1, HString S2)
{
	int i;
	if ((*T).ch) //�ͷžɿռ�
		free((*T).ch);
	(*T).ch = (char *)malloc((S1.length + S2.length) * sizeof(char));
	if (!(*T).ch)
		exit(OVERFLOW);
	for (i = 0; i < S1.length; i++)
	{
		(*T).ch[i] = S1.ch[i];
	}
	(*T).length = S1.length + S2.length;
	for (i = 0; i < S2.length; i++)
	{
		(*T).ch[i + S1.length] = S2.ch[i];
	}
	return OK;
}

/*******************************************
��ʼ����: ��S���ڣ�1<= pos <= S.length && 0 <= len <= S.length - pos +1
�������: ��Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ�
*******************************************/
Status SubString(HString *Sub, HString S, int pos, int len)
{
	int i;
	if (pos < 1 || pos > S.length || len < 0 || len > S.length - pos +1)
	{
		return ERROR;
	}
	if ((*Sub).ch)
		free((*Sub).ch); //��վ��ִ�
	if (!len) //len == 0
	{
		(*Sub).ch = NULL;
		(*Sub).length = 0;
	}
	else
	{
		(*Sub).ch = (char *)malloc(len * sizeof(char));
		for (i = 0; i < len; i++)
		{
			(*Sub).ch[i] = S.ch[pos - 1 + i];
		}
		(*Sub).length = len;
	}
	return OK;
}

/*******************************************
��ʼ����: ��S����
�������: ���T�ַ���
*******************************************/
void StrPrint(HString S)
{
	int i;
	for (i = 0; i < S.length; i++)
	{
		printf("%c", S.ch[i]);
	}
	printf("\n");
}

/*******************************************
��ʼ����: ��S����
�������: ��SΪ�մ�,�򷵻�TRUE,���򷵻�FALSE 
*******************************************/
Status StrEmpty(HString S)
{
	return S.ch == NULL ? TRUE : FALSE;
}

/*******************************************
��ʼ����:��T����
�������: �ɴ�T���Ƶô�S
*******************************************/
Status StrCopy(HString *T, HString S)
{
	int i;
	if (!S.ch)
	{
		return ERROR;
	}
	if ((*T).ch)
		free((*T).ch);
	(*T).ch = (char *)malloc(S.length * sizeof(char));
	if (!(*T).ch)
		exit(OVERFLOW);
	for (i = 0; i < S.length; i++)
	{
		(*T).ch[i] = S.ch[i];
	}
	(*T).length = S.length;
	return OK;
}

/*******************************************
��ʼ����:��T���ڣ�1<= pos <= S.length && 0 <= len <= S.length - pos +1
�������: �Ӵ�T��ɾ����pos���ַ��𳤶�Ϊlen���Ӵ�
*******************************************/
Status StrDelete(HString *T, int pos, int len)
{
	int i;
	if (pos < 1 || pos > (*T).length || len < 0 || len > (*T).length - pos + 1)
	{
		return ERROR;
	}
	for (i = pos -1; i < (*T).length - len; i++)
	{
		(*T).ch[i] = (*T).ch[i + len];
	}
	(*T).length = (*T).length - len;
	(*T).ch = (char *)realloc((*T).ch, (*T).length * sizeof(char));
	return OK;
}

/*******************************************
��ʼ����:��T���ڣ�1<= pos <= S.length
�������: �ڴ�T�еĵ�pos���ַ�֮ǰ���봮S
*******************************************/
Status StrInsert(HString *T, int pos, HString S)
{
	int i;
	if (pos < 1 || pos >(*T).length + 1)
	{
		return ERROR;
	}
	if (S.length)
	{
		(*T).ch = (char *)realloc((*T).ch, ((*T).length + S.length) * sizeof(char));
		if (!(*T).ch)
			exit(OVERFLOW);
		for (i = (*T).length - 1; i >= pos - 1; i--)
		{
			(*T).ch[S.length + i] = (*T).ch[i];
		}
		for (i = 0; i < S.length; i++)
		{
			(*T).ch[pos - 1 + i] = S.ch[i];
		}
		(*T).length += S.length;
	}
	return OK;
}

/*******************************************
��ʼ����:��S��T��V���ڣ�T�Ƿǿմ�
�������:��V�滻����S�г��ֵ�������T��ȵĲ��ص����Ӵ�
*******************************************/
Status Replace(HString *S, HString T, HString V)
{
	int pos;
	if (StrEmpty(T)) /* T�ǿմ� */
		return ERROR;
	pos = Index(*S, T, 1);
	while (pos) //��S�д��ڴ�T 
	{
		StrDelete(S, pos, T.length);
		StrInsert(S, pos, V);
		pos += V.length;
		pos = Index(*S, T, pos);
	}
	return OK;
}

/*******************************************
��ʼ����:��S��T���ڣ�T�Ƿǿմ���1<= pos <= S.length
�������:������S�д��ںʹ�Tֵ��ͬ���Ӵ����򷵻���������S�е�pos���ַ�֮���һ��
		 ���ֵ�λ�ã�������ֵΪ0
ע����ͨģʽƥ��
*******************************************/
int Index(HString S, HString T, int pos)
{
	int i;
	HString tmp;
	InitString(&tmp);
	if (pos < 0 || pos > S.length)
	{
		return ERROR;
	}
	i = pos;
	while (i <= S.length + T.length - 1)
	{
		SubString(&tmp, S, i, T.length);
		if (StrCompare(tmp, T) != 0)
		{
			i++;
		}
		else
		{
			return i;
		}
	}
	return 0;
}
/*******************************************
��ʼ����:�Ӵ��ǿ�
�������:���㷵���Ӵ�T��next����(����ƥ���)������KMPƥ��
*******************************************/
void get_next(HString T, int *next)
{
	int i, j;
	i = 1;
	j = 0;
	next[i] = j; //��һ����Ϊ0
	while (i < T.length)
	{
		if (j == 0 || T.ch[i - 1] == T.ch[j - 1]) //j==0���ڶ�����Ϊ1��Ȼ��j=1 
												  //�ӵ�������ʼ����ǰ׺T.ch[i-1]���ں�׺T.ch[j-1]����i��j��������
		{
			++i;
			++j;
			next[i - 1] = j;
		}
		else                      //����j����
		{
			j = next[j - 1];
		}
	}
}

/*******************************************
��ʼ����:�Ӵ��ǿ�
�������:KMPƥ�䣬������iֵ��ͨ��next[]����������jֵ���ﵽKMPƥ��i������
*******************************************/
int Index_KMP(HString S, HString T, int pos)
{
	int i = pos;
	int j = 0;
	int next[20] = { 0 };
	get_next(T, next);
	while (i <= S.length + T.length - 1 && j < T.length)
	{
		if (j == -1 || S.ch[i] == T.ch[j])
		{
			++i;
			++j;
		}
		else
		{
			j = next[j] - 1;
		}
	}
	if (j >= T.length)
	{
		return i - T.length + 1;
	}
	else
	{
		return 0;
	}
}

/*******************************************
��ʼ����:�Ӵ��ǿ�
�������:get_next()�㷨�ĸĽ�
*******************************************/
void get_nextval(HString T, int *nextval)
{
	int i, j;
	i = 1;
	j = 0;
	nextval[i] = j; //��һ����Ϊ0
	while (i < T.length)
	{
		if (j == 0 || T.ch[i - 1] == T.ch[j - 1]) //j==0���ڶ�����Ϊ1��Ȼ��j=1 
												  //�ӵ�������ʼ����ǰ׺T.ch[i-1]���ں�׺T.ch[j-1]����i��j��������
		{
			++i;
			++j;
			if (T.ch[i - 1] != T.ch[j - 1])
			{
				nextval[i - 1] = j;
			}
			else
			{
				nextval[i - 1] = nextval[j - 1];
			}
		}
		else                      //����j����
		{
			j = nextval[j - 1];
		}
	}
}