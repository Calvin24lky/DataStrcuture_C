#include"ALGraph.h"

Status CreateGraph_AL(ALGraph *G, FILE *fp, GraphKind Gkind)
{
	Status result;
	switch (Gkind)
	{
	case DG:
		result = CreateDG_AL(fp, G);
		return result;
	case DN:
		result = CreateDN_AL(fp, G);
		return result;
	default:
		result = ERROR;
		return result;
		break;
	}
	/*printf("kind: %d", Gkind);*/
	return OK;
}

int LocateVex_M(ALGraph G, VertexType_AL v)
{
	int i;
	for (i = 0; i < G.arcnum; i++)
	{
		if (G.vertices[i].data == v)
		{
			return i;
		}
	}
	return -1;
}

Status CreateDG_AL(FILE *fp, ALGraph *G)
{
	char tmp;
	int i, k, vi, vj;
	VertexType_AL vhead, vtail;
	ArcNode *arc;
	ArcNode **p;
	Scanf(fp, "%d%d%d", &((*G).kind), &((*G).vexnum), &((*G).arcnum));		//����ͼ���͡�������������

	Scanf(fp, "%c", &tmp);													//�������з�

	for (i = 0; i < (*G).vexnum; i++)
	{
		Scanf(fp, "%c", &((*G).vertices[i].data));							//����ֵ���붥������
		(*G).vertices[i].firstarc = NULL;									//�߱���Ϊ�ձ�
	}

	Scanf(fp, "%c", &tmp);													//�������з�

	for (k = 0; k < (*G).arcnum; k++)
	{
		Scanf(fp, "%c%c", &vhead, &vtail);				//����ߵ���Ϣ
		vi = LocateVex_M(*G, vhead);
		vj = LocateVex_M(*G, vtail);					//vi��vj��Ӧ���ڽӾ����бߵ�ͷ��β
		if (vj == -1 || vi == -1)
			return ERROR;
		arc = (ArcNode *)malloc(sizeof(ArcNode));		//���ɱ߽��
		if (!arc)
			exit(OVERFLOW);
		arc->adjvex = vj;
		arc->weight = 1;
		arc->nextarc = NULL;

		p = &((*G).vertices[vi].firstarc);		//p��ָ��firstarc�Ķ���ָ�� firstarc����adjvex,weight,nextarc����
		while ((*p) != NULL)					//����ΪNULL��˵��firstarc��ֵ����pָ��firstarc��nextarc
		{
			p = &((*p)->nextarc);				
		}
		*p = arc;
	}

	return OK;
}

void Print_DG(ALGraph G)
{
	int i;
	ArcNode *p;
	for (i = 0; i < G.vexnum; i++)
	{
		printf("%c ", G.vertices[i].data);
		p = G.vertices[i].firstarc;
		while (p)
		{
			printf("-> %d ", p->adjvex);
			p = p->nextarc;
		}
		printf("\n");
	}
}

Status CreateDN_AL(FILE *fp, ALGraph *G)
{
	char tmp;
	int i, k, vi, vj, weight;
	VertexType_AL vhead, vtail;
	ArcNode *arc;
	ArcNode **p;
	Scanf(fp, "%d%d%d", &((*G).kind), &((*G).vexnum), &((*G).arcnum));		//����ͼ���͡�������������

	Scanf(fp, "%c", &tmp);													//�������з�

	for (i = 0; i < (*G).vexnum; i++)
	{
		Scanf(fp, "%c", &((*G).vertices[i].data));							//����ֵ���붥������
		(*G).vertices[i].firstarc = NULL;									//�߱���Ϊ�ձ�
	}

	Scanf(fp, "%c", &tmp);													//�������з�

	for (k = 0; k < (*G).arcnum; k++)
	{
		Scanf(fp, "%c%c%d", &vhead, &vtail, &weight);				//����ߵ���Ϣ
		vi = LocateVex_M(*G, vhead);
		vj = LocateVex_M(*G, vtail);					//vi��vj��Ӧ���ڽӾ����бߵ�ͷ��β
		if (vj == -1 || vi == -1)
			return ERROR;
		arc = (ArcNode *)malloc(sizeof(ArcNode));		//���ɱ߽��
		if (!arc)
			exit(OVERFLOW);
		arc->adjvex = vj;
		arc->weight = weight;
		arc->nextarc = NULL;

		p = &((*G).vertices[vi].firstarc);		//p��ָ��firstarc�Ķ���ָ�� firstarc����adjvex,weight,nextarc����
		while ((*p) != NULL)					//����ΪNULL��˵��firstarc��ֵ����pָ��firstarc��nextarc
		{
			p = &((*p)->nextarc);
		}
		*p = arc;
	}

	return OK;
}

void Print_DN(ALGraph G)
{
	int i;
	ArcNode *p;
	for (i = 0; i < G.vexnum; i++)
	{
		printf("%c ", G.vertices[i].data);
		p = G.vertices[i].firstarc;
		while (p)
		{
			printf("-> %d ", p->adjvex);
			printf("%d ", p->weight);
			p = p->nextarc;
		}
		printf("\n");
	}
}