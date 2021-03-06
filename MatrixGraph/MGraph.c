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
	Scanf(fp, "%d%d%d", &((*G).kind), &((*G).vexnum), &((*G).arcnum));		//读入图类型、顶点数、边数

	Scanf(fp, "%c", &tmp);								//跳过换行符

	for (i = 0; i < (*G).vexnum; i++)
		Scanf(fp, "%c", &((*G).vexs[i]));				//顶点值存入顶点数组

	Scanf(fp, "%c", &tmp);								//跳过换行符

	for (i = 0; i < (*G).vexnum; i++)
		for (j = 0; j < (*G).vexnum; j++)
			(*G).arcs[i][j] = INFINITY;					//初始化邻接矩阵

	for ( k = 0; k < (*G).arcnum; k++)
	{
		Scanf(fp, "%c%c", &vhead, &vtail);				//读入边的信息
		vi = LocateVex_M(*G, vhead);
		vj = LocateVex_M(*G, vtail);					//vi与vj对应于邻接矩阵中边的头与尾
		if (vj != -1 && vi != -1)
			(*G).arcs[vi][vj] = 1;
	}
	for (i = 0; i < (*G).vexnum; i++)					//打印邻接矩阵
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
	Scanf(fp, "%d%d%d", &((*G).kind), &((*G).vexnum), &((*G).arcnum));		//读入图类型、顶点数、边数

	Scanf(fp, "%c", &tmp);								//跳过换行符

	for (i = 0; i < (*G).vexnum; i++)
		Scanf(fp, "%c", &((*G).vexs[i]));				//顶点值存入顶点数组

	Scanf(fp, "%c", &tmp);								//跳过换行符

	for (i = 0; i < (*G).vexnum; i++)
		for (j = 0; j < (*G).vexnum; j++)
			(*G).arcs[i][j] = INFINITY;					//初始化邻接矩阵

	for (k = 0; k < (*G).arcnum; k++)
	{
		Scanf(fp, "%c%c%d", &vhead, &vtail, &weight);				//读入边的信息
		vi = LocateVex_M(*G, vhead);
		vj = LocateVex_M(*G, vtail);					//vi与vj对应于邻接矩阵中边的头与尾
		if (vj != -1 && vi != -1)
			(*G).arcs[vi][vj] = weight;
	}
	for (i = 0; i < (*G).vexnum; i++)					//打印邻接矩阵
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
	Scanf(fp, "%d%d%d", &((*G).kind), &((*G).vexnum), &((*G).arcnum));		//读入图类型、顶点数、边数

	Scanf(fp, "%c", &tmp);								//跳过换行符

	for (i = 0; i < (*G).vexnum; i++)
		Scanf(fp, "%c", &((*G).vexs[i]));				//顶点值存入顶点数组

	Scanf(fp, "%c", &tmp);								//跳过换行符

	for (i = 0; i < (*G).vexnum; i++)
		for (j = 0; j < (*G).vexnum; j++)
			(*G).arcs[i][j] = INFINITY;					//初始化邻接矩阵

	for (k = 0; k < (*G).arcnum; k++)
	{
		Scanf(fp, "%c%c", &vhead, &vtail);				//读入边的信息
		vi = LocateVex_M(*G, vhead);
		vj = LocateVex_M(*G, vtail);					//vi与vj对应于邻接矩阵中边的头与尾
		if (vj != -1 && vi != -1)
		{
			(*G).arcs[vi][vj] = 1;
			(*G).arcs[vj][vi] = (*G).arcs[vi][vj];
		}
	}
	for (i = 0; i < (*G).vexnum; i++)					//打印邻接矩阵
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
	Scanf(fp, "%d%d%d", &((*G).kind), &((*G).vexnum), &((*G).arcnum));		//读入图类型、顶点数、边数

	Scanf(fp, "%c", &tmp);								//跳过换行符

	for (i = 0; i < (*G).vexnum; i++)
		Scanf(fp, "%c", &((*G).vexs[i]));				//顶点值存入顶点数组

	Scanf(fp, "%c", &tmp);								//跳过换行符

	for (i = 0; i < (*G).vexnum; i++)
		for (j = 0; j < (*G).vexnum; j++)
			(*G).arcs[i][j] = INFINITY;					//初始化邻接矩阵

	for (k = 0; k < (*G).arcnum; k++)
	{
		Scanf(fp, "%c%c%d", &vhead, &vtail, &weight);				//读入边的信息
		vi = LocateVex_M(*G, vhead);
		vj = LocateVex_M(*G, vtail);					//vi与vj对应于邻接矩阵中边的头与尾
		if (vj != -1 && vi != -1)
		{
			(*G).arcs[vi][vj] = weight;
			(*G).arcs[vj][vi] = (*G).arcs[vi][vj];
		}
	}
	for (i = 0; i < (*G).vexnum; i++)					//打印邻接矩阵
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
	printf("%c ", G.vexs[i]);		//打印顶点
	for (j = 0; j < G.vexnum; j++)
		if (G.arcs[i][j] == 1 && !visted[j])
			DFS(G, j);
}

void DFS_Traverse_M(MGraph G)
{
	int i;
	for (i = 0; i < G.vexnum; i++)		//初始化所有结点
		visted[i] = FALSE;
	for (i = 0; i < G.vexnum; i++)		//顶点可随机选择，若是连通图，则只执行一次
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
	for (i = 3; i < G.vexnum; i++)		//顶点可随机选择，若是连通图，则只执行一次
	{
		if (!visted[i])		//顶点未访问过
		{
			visted[i] = TRUE;
			printf("%c ", G.vexs[i]);	//打印顶点
			EnQueue(&Q, i);				//顶点入队列，开始BFS：将与顶点相邻的顶点入队列并输出，重复
			while (!QueueEmpty(Q))		//队列非空
			{
				DeQueue(&Q, &i);		//出队列
				for (j = 0; j < G.vexnum; j++)		//找该点相邻的顶点并将其入队列
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