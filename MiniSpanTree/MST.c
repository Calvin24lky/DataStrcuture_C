#include"MST.h"

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
				printf("- ");
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
	printf("  A B C D E F \n");
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

//For UDN
void MiniSpanTree_Prim(MGraph G, VertexType_M u)
{
	int i, j, min, k, a;
	int adjvex[MAX_VEXTEX_NUM];		//�洢lowcost��Ӧ����СȨֵ���ԵıߵĶ���ֵ
	int lowcost[MAX_VEXTEX_NUM];	//�洢�ñ��ϵ�Ȩֵ

	a = LocateVex_M(G, u);			//����һ����va��ʼ����

	for (i = 0; i < G.vexnum; i++)
	{
		lowcost[i] = G.arcs[a][i];	//va������ڱ߼���lowcost
		adjvex[i] = a;				//һ��ʼlowcostȫ������va����
	}

	lowcost[a] = 0;						//lowcost[k] = 0����va�Ѽ�����������

										//��ʼ����lowcost[]������СȨֵ�ҵ���һ������k������,����k���ڱ߼���lowcost

	for (i = 1; i < G.vexnum; i++)		//ѡ������G.vexnum - 1������
	{
		min = INFINITY;
		j = 0;
		k = 0;
		while (j < G.vexnum)
		{
			if (lowcost[j] != 0 && lowcost[j] < min)	//�ҵ�������СȨֵ�߶�Ӧ����һ������±�k
			{
				min = lowcost[j];
				k = j;
			}
			j++;
		}
		//���ҵ���һ����k,�������

		printf("{%c-- %d --%c}\n", adjvex[k] + 65, min, k + 65);

		lowcost[k] = 0;			//����k������������

								//��lowcost[]��������k���ڱ߽���lowcost[]��
		for (j = 0; j < G.vexnum; j++)
		{
			if (lowcost[j] != 0 && G.arcs[k][j] < lowcost[j])
			{
				lowcost[j] = G.arcs[k][j];
				adjvex[j] = k;				//�¼���lowcost���ڱ������ڶ���vk
			}
		}
	}
}

//����ΪѰ�Ҷ����������ĸ����
int Find(int *parent, int f)
{
	while (parent[f] > 0)
		f = parent[f];
	return f;
}

void MiniSpanTree_Kruskal(MGraph G)
{
	int i, j, m, n;
	int s = 0;
	Edge edges[MAX_EDGE_NUM];
	Edge tmp;
	int parent[MAX_VEXTEX_NUM];		//�жϱ�����Ƿ��γɻ�·

									//printf("begin  end  weight \n");
									//���ڽӾ���ת��Ϊ�߼�����edges[]
	for (i = 0; i < G.vexnum; i++)
	{
		for (j = i; j < G.vexnum; j++)
		{
			if (G.arcs[i][j] != INFINITY)
			{
				edges[s].begin = i;
				edges[s].end = j;
				edges[s].weight = G.arcs[i][j];
				//printf("%c  %c  %d  \n", edges[n].begin + 65, edges[n].end + 65, edges[n].weight);
				s++;
			}
		}
	}

	//��edges[]��С�������� ð������
	for (j = 0; j < G.arcnum; j++)
		for (i = 0; i < G.arcnum - 1 - j; i++)
		{
			if (edges[i].weight > edges[i + 1].weight)
			{
				tmp = edges[i];
				edges[i] = edges[i + 1];
				edges[i + 1] = tmp;
			}
		}

	//��ʼ��
	for (i = 0; i < G.vexnum; i++)
	{
		parent[i] = 0;					//parent�����ʼ����0	
	}

	for (i = 0; i < G.arcnum; i++)		//����СȨֵ�߿�ʼ��ӽ���������
	{
		n = Find(parent, edges[i].begin);	//Find����Ѱ�Ҷ�����parent�����еĸ��ڵ�
		m = Find(parent, edges[i].end);		//���ݸ��ڵ��Ƿ���ͬ�ó������Ƿ���ͬһ��ͨ������
		if (n != m)
		{
			parent[n] = m;				//end������Ϊbegin�����parent��㣬��parent�����й���һ����
			printf("{%c %d %c} \n", edges[i].begin + 65, edges[i].weight, edges[i].end + 65);
		}
	}
}

