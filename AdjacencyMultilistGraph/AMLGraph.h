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

#define MAX_VEXTEX_NUM 20		//��󶥵����
#define INFINITY 65535			//���ֵ��

typedef char VertexType_AML;		//��������

typedef enum { DG, DN, UDG, UDN } GraphKind; //ͼ���ͣ�����ͼ��������������ͼ��������

typedef struct EdgeBox						//�߱���
{
	int ivex, jvex;
	struct EdgeBox *ilink, *jlink;
}EdgeBox;

typedef struct VertexBox					//�������
{
	VertexType_AML data;					//������Ϣ
	EdgeBox *firstedge;						//�ױ�ָ��
}VertexBox;

typedef struct
{
	VertexBox adjmulist[MAX_VEXTEX_NUM];							//���������
	int vexnum, edgenum;						//������������
	int kind;								//ͼ���ͣ�UDG��UDN
}AMLGraph;

int Scanf(FILE *fp, char *format, ...);

Status CreateGraph_AML(AMLGraph *G, FILE *fp, GraphKind Gkind);
Status CreateUDG_AML(FILE *fp, AMLGraph *G);
Status CreateUDN_AML(FILE *fp, AMLGraph *G);


