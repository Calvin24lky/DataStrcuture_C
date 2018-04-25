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

void DFS_Traverse_AL(ALGraph G)
{
	int i;
	for (i = 0; i < G.vexnum; i++)		//��ʼ�����н��
		visted[i] = FALSE;

	for (i = 0; i < G.vexnum; i++)		//��δ���ʹ��Ľ�����DFS��������ͨͼ��ֻ��ִ��һ��
		if (!visted[i])
			DFS(G, i);
}

void DFS(ALGraph G, int i)
{
	ArcNode *p;
	visted[i] = TRUE;
	printf("%c ", G.vertices[i].data);		//��ӡ����
	p = G.vertices[i].firstarc;				//���ʶ�����ָ��ĵ�һ����
	while (p)
	{
		if (!visted[p->adjvex])				//����δ���ʹ�
			DFS(G, p->adjvex);
		p = p->nextarc;
	}
}

void BFS_Traverse_AL(ALGraph G)
{
	LinkQueue Q;
	ArcNode *arc;
	int i, e;
	InitQueue(&Q);
	for (i = 0; i < G.vexnum; i++)
		visted[i] = FALSE;
	for (i = 3; i < G.vexnum; i++)		//��������ѡ��������ͨͼ����ִֻ��һ��
		if (!visted[i])
		{
			visted[i] = TRUE;
			printf("%c ", G.vertices[i].data);
			EnQueue(&Q, i);				//��������У���ʼBFS�����붥�����ڵĶ�������в�������ظ�
			while (!QueueEmpty(Q))
			{
				DeQueue(&Q, &e);
				arc = G.vertices[e].firstarc;		
				while (arc)				//�Ҹõ����ڵĶ��㲢���������
				{
					if (!visted[arc->adjvex])//�ö���δ���ʹ�
					{
						visted[arc->adjvex] = TRUE;
						printf("%c ", G.vertices[arc->adjvex].data);
						EnQueue(&Q, arc->adjvex);
					}
					arc = arc->nextarc;
				}
			}
		}
}