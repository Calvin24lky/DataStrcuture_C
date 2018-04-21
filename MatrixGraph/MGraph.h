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

typedef char VertexType_M;		//��������
typedef int EdgeType;			//������

typedef enum { DG, DN, UDG, UDN } GraphKind; //ͼ���ͣ�����ͼ��������������ͼ��������

typedef struct
{
	VertexType_M vexs[MAX_VEXTEX_NUM];		//��������
	EdgeType arcs[MAX_VEXTEX_NUM][MAX_VEXTEX_NUM];  //��/��-�ڽӾ���
	int vexnum, arcnum;						//��ǰ����������/����
	GraphKind kind;
}MGraph;

int Scanf(FILE *fp, char *format, ...);
Status CreateGraph_M(MGraph *G, FILE *fp, GraphKind Gkind);
Status CreateDG_M(FILE *fp, MGraph *G);
Status CreateDN_M(FILE *fp, MGraph *G);
Status CreateUDG_M(FILE *fp, MGraph *G);
Status CreateUDN_M(FILE *fp, MGraph *G);


