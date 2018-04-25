#include"MGraph.h"

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
	int i,j,k,vi,vj;
	VertexType_M vhead, vtail;
	Scanf(fp, "%d%d%d", &((*G).kind), &((*G).vexnum), &((*G).arcnum));		//����ͼ���͡�������������

	Scanf(fp, "%c", &tmp);								//�������з�

	for (i = 0; i < (*G).vexnum; i++)
		Scanf(fp, "%c", &((*G).vexs[i]));				//����ֵ���붥������

	Scanf(fp, "%c", &tmp);								//�������з�

	for (i = 0; i < (*G).vexnum; i++)
		for (j = 0; j < (*G).vexnum; j++)
			(*G).arcs[i][j] = INFINITY;					//��ʼ���ڽӾ���

	for ( k = 0; k < (*G).arcnum; k++)
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

void DFS(MGraph G, int i)
{
	int j;
	visted[i] = TRUE;
	printf("%c ", G.vexs[i]);		//��ӡ����
	for (j = 0; j < G.vexnum; j++)
		if (G.arcs[i][j] == 1 && !visted[j])
			DFS(G, j);
}

void DFS_Traverse_M(MGraph G)
{
	int i;
	for (i = 0; i < G.vexnum; i++)		//��ʼ�����н��
		visted[i] = FALSE;
	for (i = 0; i < G.vexnum; i++)		//��������ѡ��������ͨͼ����ִֻ��һ��
		if (!visted[i])
			DFS(G, i);
}

void BFS_Traverse_M(MGraph G)
{
	int i, j;
	LinkQueue Q;
	for (i = 0; i < G.vexnum; i++)
		visted[i] = FALSE;
	InitQueue(&Q);
	for (i = 3; i < G.vexnum; i++)		//��������ѡ��������ͨͼ����ִֻ��һ��
	{
		if (!visted[i])		//����δ���ʹ�
		{
			visted[i] = TRUE;
			printf("%c ", G.vexs[i]);	//��ӡ����
			EnQueue(&Q, i);				//��������У���ʼBFS�����붥�����ڵĶ�������в�������ظ�
			while (!QueueEmpty(Q))		//���зǿ�
			{
				DeQueue(&Q, &i);		//������
				for (j = 0; j < G.vexnum; j++)		//�Ҹõ����ڵĶ��㲢���������
				{
					if (G.arcs[i][j] == 1 && !visted[j])
					{
						visted[j] = TRUE;
						printf("%c ", G.vexs[j]);
						EnQueue(&Q, j);
					}
				}

			}
		}
	}
}