#include"OLGraph.h"

Status CreateGraph_OL(OLGraph *G, FILE *fp, GraphKind Gkind)
{
	Status result;
	switch (Gkind)
	{
	case DG:
		result = CreateDG_OL(fp, G);
		return result;
	case DN:
		result = CreateDN_OL(fp, G);
		return result;
	default:
		result = ERROR;
		return result;
		break;
	}
	/*printf("kind: %d", Gkind);*/
	return OK;
}

int LocateVex_M(OLGraph G, VertexType_OL v)
{
	int i;
	for (i = 0; i < G.arcnum; i++)
	{
		if (G.xlist[i].data == v)
		{
			return i;
		}
	}
	return -1;
}

Status CreateDG_OL(FILE *fp, OLGraph *G)
{
	char tmp;
	int i, k, vi, vj;
	VertexType_OL vhead, vtail;
	ArcBox *arc;
	ArcBox **pout, **pin;
	Scanf(fp, "%d%d%d", &((*G).kind), &((*G).vexnum), &((*G).arcnum));		//����ͼ���͡�������������

	Scanf(fp, "%c", &tmp);													//�������з�

	for (i = 0; i < (*G).vexnum; i++)
	{
		Scanf(fp, "%c", &((*G).xlist[i].data));							//����ֵ���붥������
		(*G).xlist[i].firstin = NULL;									//��߱���Ϊ�ձ�
		(*G).xlist[i].firstout = NULL;									//���߱���Ϊ�ձ�
	}

	Scanf(fp, "%c", &tmp);													//�������з�

	for (k = 0; k < (*G).arcnum; k++)
	{
		Scanf(fp, "%c%c", &vhead, &vtail);				//����ߵ���Ϣ
		vi = LocateVex_M(*G, vhead);
		vj = LocateVex_M(*G, vtail);					//vi��vj��Ӧ���ڽӾ����бߵ�ͷ��β
		if (vj == -1 || vi == -1)
			return ERROR;
		arc = (ArcBox *)malloc(sizeof(ArcBox));		//���ɱ߽��
		if (!arc)
			exit(OVERFLOW);

		arc->headvex = vj;
		arc->tailvex = vi;
		arc->weight = 1;
		arc->taillink = NULL;
		arc->headlink = NULL;

		pout = &((*G).xlist[vi].firstout);		//p��ָ��firstarc�Ķ���ָ�� firstarc����adjvex,weight,nextarc����
		while ((*pout) != NULL)					//����ΪNULL��˵��firstarc��ֵ����pָ��firstarc��nextarc
		{
			pout = &((*pout)->taillink);
		}
		*pout = arc;

		pin = &((*G).xlist[vj].firstin);		//
		while ((*pin) != NULL)
		{
			pin = &((*pin)->headlink);
		}
		*pin = arc;
	}

	return OK;
}

void Print_DG_order(OLGraph G)
{
	int i;
	ArcBox *p;
	for (i = 0; i < G.vexnum; i++)
	{
		printf("%c ", G.xlist[i].data);
		p = G.xlist[i].firstout;
		while (p)
		{
			printf("-> %d ", p->headvex);
			p = p->taillink;
		}
		printf("\n");
	}
}

void Print_DG_re_order(OLGraph G)
{
	int i;
	ArcBox *p;
	for (i = 0; i < G.vexnum; i++)
	{
		printf("%c ", G.xlist[i].data);
		p = G.xlist[i].firstin;
		while (p)
		{
			printf("<- %d ", p->tailvex);
			p = p->headlink;
		}
		printf("\n");
	}
}

Status CreateDN_AL(FILE *fp, OLGraph *G)
{
	char tmp;
	int i, k, vi, vj, weight;
	VertexType_OL vhead, vtail;
	ArcBox *arc;
	ArcBox **pout, **pin;
	Scanf(fp, "%d%d%d", &((*G).kind), &((*G).vexnum), &((*G).arcnum));		//����ͼ���͡�������������

	Scanf(fp, "%c", &tmp);													//�������з�

	for (i = 0; i < (*G).vexnum; i++)
	{
		Scanf(fp, "%c", &((*G).xlist[i].data));							//����ֵ���붥������
		(*G).xlist[i].firstin = NULL;									//��߱���Ϊ�ձ�
		(*G).xlist[i].firstout = NULL;									//���߱���Ϊ�ձ�
	}

	Scanf(fp, "%c", &tmp);													//�������з�

	for (k = 0; k < (*G).arcnum; k++)
	{
		Scanf(fp, "%c%c%d", &vhead, &vtail, &weight);				//����ߵ���Ϣ
		vi = LocateVex_M(*G, vhead);
		vj = LocateVex_M(*G, vtail);					//vi��vj��Ӧ���ڽӾ����бߵ�ͷ��β
		if (vj == -1 || vi == -1)
			return ERROR;
		arc = (ArcBox *)malloc(sizeof(ArcBox));		//���ɱ߽��
		if (!arc)
			exit(OVERFLOW);

		arc->headvex = vj;
		arc->tailvex = vi;
		arc->weight = weight;
		arc->taillink = NULL;
		arc->headlink = NULL;

		pout = &((*G).xlist[vi].firstout);		//p��ָ��firstarc�Ķ���ָ�� firstarc����adjvex,weight,nextarc����
		while ((*pout) != NULL)					//����ΪNULL��˵��firstarc��ֵ����pָ��firstarc��nextarc
		{
			pout = &((*pout)->taillink);
		}
		*pout = arc;

		pin = &((*G).xlist[vj].firstin);		//
		while ((*pin) != NULL)
		{
			pin = &((*pin)->headlink);
		}
		*pin = arc;
	}

	return OK;
}