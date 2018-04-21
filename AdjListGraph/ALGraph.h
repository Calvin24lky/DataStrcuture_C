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

typedef char VertexType_AL;		//��������
typedef int EdgeType;			//������
typedef enum { DG, DN, UDG, UDN } GraphKind; //ͼ���ͣ�����ͼ��������������ͼ��������

typedef struct ArcNode			//�߱���
{
	int adjvex;					//��ָ��Ľ����±�
	EdgeType weight;			//Ȩֵ
	struct ArcNode *nextarc;	//ָ����һ���߽��
}ArcNode;

typedef struct VertexNode		//�������
{
	VertexType_AL data;			//������Ϣ
	ArcNode *firstarc;			//�߱�ͷָ��
}VertexNode;

typedef VertexNode AdjList[MAX_VEXTEX_NUM];


typedef struct
{
	AdjList vertices;
	int vexnum, arcnum;
	int kind;
}ALGraph;

int Scanf(FILE *fp, char *format, ...);

Status CreateGraph_AL(ALGraph *G, FILE *fp, GraphKind Gkind);
Status CreateDG_AL(FILE *fp, ALGraph *G);
void Print_DG(ALGraph G);
Status CreateDN_AL(FILE *fp, ALGraph *G);
void Print_DN(ALGraph G);


