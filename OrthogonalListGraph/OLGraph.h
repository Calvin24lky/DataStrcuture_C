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

typedef char VertexType_OL;		//��������
typedef enum { DG, DN, UDG, UDN } GraphKind; //ͼ���ͣ�����ͼ��������������ͼ��������

typedef struct ArcBox						//�߱���
{
	int tailvex, headvex;					//β��ͷ�����±�
	int weight;								//Ȩֵ
	struct ArcBox *headlink, *taillink;		//
}ArcBox;

typedef struct VertexNode					//�������
{
	VertexType_OL data;						//������Ϣ
	ArcBox *firstin, *firstout;				//��/���߱�ͷָ��
}VertexNode;

typedef VertexNode OList[MAX_VEXTEX_NUM];

typedef struct
{
	OList xlist;							//���������
	int vexnum, arcnum;						//������������
	int kind;								//ͼ���ͣ�DG��DN
}OLGraph;

int Scanf(FILE *fp, char *format, ...);

Status CreateGraph_OL(OLGraph *G, FILE *fp, GraphKind Gkind);
Status CreateDG_OL(FILE *fp, OLGraph *G);
void Print_DG_order(OLGraph G);
void Print_DG_re_order(OLGraph G);
Status CreateDN_AL(FILE *fp, OLGraph *G);
//void Print_DN(OLGraph G);


