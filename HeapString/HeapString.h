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

typedef struct
{
	char *ch;
	int length;
}HString;

void InitString(HString *T);
Status StrAssign(HString *T, char *chars);
Status ClearString(HString *T);
int StrLength(HString S);
int StrCompare(HString S, HString T);
Status Concat(HString *T, HString S1, HString S2);
Status SubString(HString *Sub, HString S, int pos, int len);
void StrPrint(HString S);
Status StrEmpty(HString S);
Status StrCopy(HString *T, HString S);
Status StrDelete(HString *T, int pos, int len);
Status StrInsert(HString *T, int pos, HString S);
Status Replace(HString *T, HString S, HString V);
int Index(HString S, HString T, int pos);
void get_next(HString T, int *next);
void get_nextval(HString T, int *nextval);
int Index_KMP(HString S, HString T, int pos);
