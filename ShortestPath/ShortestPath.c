#include"ShortestPath.h"

Status CreateGraph_M(MGraph *G, FILE *fp, GraphKind Gkind)
{
	Status result;
	switch (Gkind)
	{
	case DG:
		result = CreateDG_M(fp, G);
		return result;
	case DN:
		result = CreateDN_M(fp, G);
		return result;
	case UDG:
		result = CreateUDG_M(fp, G);
		return result;
	case UDN:
		result = CreateUDN_M(fp, G);
		return result;
	default:
		result = ERROR;
		return result;
		break;
	}
	/*printf("kind: %d", Gkind);*/
	return OK;
}

int LocateVex_M(MGraph G, VertexType_M v)
{
	int i;
	for (i = 0; i < G.arcnum; i++)
	{
		if (G.vexs[i] == v)
		{
			return i;
		}
	}
	return -1;
}

Status CreateDG_M(FILE *fp, MGraph *G)
{
	char tmp;
	int i, j, k, vi, vj;
	VertexType_M vhead, vtail;
	Scanf(fp, "%d%d%d", &((*G).kind), &((*G).vexnum), &((*G).arcnum));		//����ͼ���͡�������������

	Scanf(fp, "%c", &tmp);								//�������з�

	for (i = 0; i < (*G).vexnum; i++)
		Scanf(fp, "%c", &((*G).vexs[i]));				//����ֵ���붥������

	Scanf(fp, "%c", &tmp);								//�������з�

	for (i = 0; i < (*G).vexnum; i++)
		for (j = 0; j < (*G).vexnum; j++)
			(*G).arcs[i][j] = INFINITY;					//��ʼ���ڽӾ���

	for (k = 0; k < (*G).arcnum; k++)
	{
		Scanf(fp, "%c%c", &vhead, &vtail);				//����ߵ���Ϣ
		vi = LocateVex_M(*G, vhead);
		vj = LocateVex_M(*G, vtail);					//vi��vj��Ӧ���ڽӾ����бߵ�ͷ��β
		if (vj != -1 && vi != -1)
			(*G).arcs[vi][vj] = 1;
	}
	for (i = 0; i < (*G).vexnum; i++)					//��ӡ�ڽӾ���
	{
		for (j = 0; j < (*G).vexnum; j++)
			if ((*G).arcs[i][j] == 65535)
				printf("- ");
			else
				printf("%d ", (*G).arcs[i][j]);
		printf("\n");
	}
	return OK;
}
Status CreateDN_M(FILE *fp, MGraph *G)
{
	char tmp;
	int i, j, k, vi, vj, weight;
	VertexType_M vhead, vtail;
	Scanf(fp, "%d%d%d", &((*G).kind), &((*G).vexnum), &((*G).arcnum));		//����ͼ���͡�������������

	Scanf(fp, "%c", &tmp);								//�������з�

	for (i = 0; i < (*G).vexnum; i++)
		Scanf(fp, "%c", &((*G).vexs[i]));				//����ֵ���붥������

	Scanf(fp, "%c", &tmp);								//�������з�

	for (i = 0; i < (*G).vexnum; i++)
		for (j = 0; j < (*G).vexnum; j++)
			(*G).arcs[i][j] = INFINITY;					//��ʼ���ڽӾ���

	for (k = 0; k < (*G).arcnum; k++)
	{
		Scanf(fp, "%c%c%d", &vhead, &vtail, &weight);				//����ߵ���Ϣ
		vi = LocateVex_M(*G, vhead);
		vj = LocateVex_M(*G, vtail);					//vi��vj��Ӧ���ڽӾ����бߵ�ͷ��β
		if (vj != -1 && vi != -1)
			(*G).arcs[vi][vj] = weight;
	}
	for (i = 0; i < (*G).vexnum; i++)					//��ӡ�ڽӾ���
	{
		for (j = 0; j < (*G).vexnum; j++)
			if ((*G).arcs[i][j] == 65535)
				printf("-- ");
			else
				printf("%d ", (*G).arcs[i][j]);
		printf("\n");
	}
	return OK;
}
Status CreateUDG_M(FILE *fp, MGraph *G)
{
	char tmp;
	int i, j, k, vi, vj;
	VertexType_M vhead, vtail;
	Scanf(fp, "%d%d%d", &((*G).kind), &((*G).vexnum), &((*G).arcnum));		//����ͼ���͡�������������

	Scanf(fp, "%c", &tmp);								//�������з�

	for (i = 0; i < (*G).vexnum; i++)
		Scanf(fp, "%c", &((*G).vexs[i]));				//����ֵ���붥������

	Scanf(fp, "%c", &tmp);								//�������з�

	for (i = 0; i < (*G).vexnum; i++)
		for (j = 0; j < (*G).vexnum; j++)
			(*G).arcs[i][j] = INFINITY;					//��ʼ���ڽӾ���

	for (k = 0; k < (*G).arcnum; k++)
	{
		Scanf(fp, "%c%c", &vhead, &vtail);				//����ߵ���Ϣ
		vi = LocateVex_M(*G, vhead);
		vj = LocateVex_M(*G, vtail);					//vi��vj��Ӧ���ڽӾ����бߵ�ͷ��β
		if (vj != -1 && vi != -1)
		{
			(*G).arcs[vi][vj] = 1;
			(*G).arcs[vj][vi] = (*G).arcs[vi][vj];
		}
	}
	for (i = 0; i < (*G).vexnum; i++)					//��ӡ�ڽӾ���
	{
		for (j = 0; j < (*G).vexnum; j++)
			if ((*G).arcs[i][j] == 65535)
				printf("- ");
			else
				printf("%d ", (*G).arcs[i][j]);
		printf("\n");
	}
	return OK;
}
Status CreateUDN_M(FILE *fp, MGraph *G)
{
	char tmp;
	int i, j, k, vi, vj, weight;
	VertexType_M vhead, vtail;
	Scanf(fp, "%d%d%d", &((*G).kind), &((*G).vexnum), &((*G).arcnum));		//����ͼ���͡�������������

	Scanf(fp, "%c", &tmp);								//�������з�

	for (i = 0; i < (*G).vexnum; i++)
		Scanf(fp, "%c", &((*G).vexs[i]));				//����ֵ���붥������

	Scanf(fp, "%c", &tmp);								//�������з�

	for (i = 0; i < (*G).vexnum; i++)
		for (j = 0; j < (*G).vexnum; j++)
			(*G).arcs[i][j] = INFINITY;					//��ʼ���ڽӾ���

	for (k = 0; k < (*G).arcnum; k++)
	{
		Scanf(fp, "%c%c%d", &vhead, &vtail, &weight);				//����ߵ���Ϣ
		vi = LocateVex_M(*G, vhead);
		vj = LocateVex_M(*G, vtail);					//vi��vj��Ӧ���ڽӾ����бߵ�ͷ��β
		if (vj != -1 && vi != -1)
		{
			(*G).arcs[vi][vj] = weight;
			(*G).arcs[vj][vi] = (*G).arcs[vi][vj];
		}
	}
	
	printf("  A B C D E F G H I \n");

	for (i = 0; i < (*G).vexnum; i++)					//��ӡ�ڽӾ���
	{
		printf("%c ", (*G).vexs[i]);
		for (j = 0; j < (*G).vexnum; j++)
			if ((*G).arcs[i][j] == 65535)
				printf("- ");
			else
				printf("%d ", (*G).arcs[i][j]);
		printf("\n");
	}
	return OK;
}

void ShortestPath_Dijkstra(MGraph G, int v0, Patharc *P, ShortPathTable *D)
{
	int v, min, w, k;
	int final[MAX_VEXTEX_NUM];

	for (v = 0; v < G.vexnum; v++)		//��ʼ��
	{
		final[v] = 0;					//final��������Ӧ�±�Ķ����Ƿ��Ѽ������·��
		(*D)[v] = G.arcs[v0][v];		//D����ָʾѡ���Ķ��㵽��Ӧ�±������ľ��룬final[]ÿ����һ�����㣬��Ҫ����һ��D����
		(*P)[v] = 0;					//P����ָʾ��Ӧ�±궥���ǰ��
	}

	(*D)[v0] = 0;						//v0��v0·��Ϊ0
	final[v0] = 1;						//v0����������·��

	//��ʼ��ѭ����ÿ�����v0��ĳ��v��������·��������v��S����
	for (v = 1; v < G.vexnum; v++)
	{
		min = INFINITY;
		for (w = 0; w < G.vexnum; w++)		//Ѱ����v0����Ķ���
		{
			if (!final[w] && (*D)[w] < min)	//w�����ڷ�S������w�������ڱߣ��ҳ���̵��ڱ�
			{
				k = w;
				min = (*D)[w];				//w������v0���
			}
		}
		
		final[k] = 1;					//���ҵ���w�������S��

		//���µ�ǰ���·���;���

		for (w = 0; w < G.vexnum; w++)
		{
			if (!final[w] &&  (min + G.arcs[k][w] < (*D)[w]))
			{
				//�ҵ���·�����޸�D[w]��P[w]
				(*D)[w] = min + G.arcs[k][w];
				(*P)[w] = k;
			}
		}
	}
}

void ShortestPath_Floyd(MGraph G, Pathmatrix *P, ShortPathTable_F *D)
{
	int v, w, k;

	for (v = 0; v < G.vexnum; v++)		//��ʼ��
	{									
		for (w = 0; w < G.vexnum; w++)
		{
			if (v != w)
			{
				(*D)[v][w] = G.arcs[v][w];		//D��ʼ�����ڽӾ�����ͬ
				(*P)[v][w] = w;					//P��ʼ��Ϊ0-w
			}
			else
			{
				(*D)[v][w] = 0;
			}

		}
	}

	for (k = 0; k < G.vexnum; k++)
	{
		for (v = 0; v < G.vexnum; v++)
		{
			for (w = 0; w < G.vexnum; w++)
			{
				if ( (*D)[v][w] > (*D)[v][k] + (*D)[k][w] )
				{
					(*D)[v][w] = (*D)[v][k] + (*D)[k][w];
					(*P)[v][w] = (*P)[v][k];
				}
			}
		}
	}

	for (v = 0; v < G.vexnum; v++)
	{
		for (w = 0; w < G.vexnum; w++)
		{
			if ((*D)[v][w] != INFINITY)
			{
				printf("%2d ", (*D)[v][w]);
			}
			else
			{
				printf("-- ");
			}
		}
		printf("\n");
	}
}