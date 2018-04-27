#include"SCC.h"
//��������ͼ
void InverseGraph(OLGraph *G)
{
	int i, t;
	ArcBox *tmp, *q;
	ArcBox *p = NULL;
	VertexNode *h;
	for (i = 0; i < (*G).vexnum; i++)
	{
		h = &((*G).xlist[i]);			//�Զ����Ķ������β���
		if (h->firstout)				
			p = h->firstout;

			tmp = h->firstout;			//�������firstout �� firstin����
			h->firstout = h->firstin;
			h->firstin = tmp;

			while (p)					//�Զ���ָ��ĳ��߱���������߱�����߱����һ������,��Ϊ�������ڱ߱��У�
			{
				q = p;
				p = p->taillink;		//pָ���¸�����

				t = q->headvex;			//vexֵ����
				q->headvex = q->tailvex;
				q->tailvex = t;

				tmp = q->headlink;		//linkֵ����
				q->headlink = q->taillink;
				q->taillink = tmp;
			}

	}
}

void DFS_Traverse_SCC(OLGraph G)
{
	int i;

	for (i = 0; i < G.vexnum; i++)		//��ʼ�����ʱ������
		visited[i] = FALSE;

	count = 0;

	for (i = 2; i < G.vexnum; i++)		//��������ѡ��������ͨͼ����ִֻ��һ��
		if (!visited[i])
			DFS_SCC_1(G, i);
}

//��һ��DFS
void DFS_SCC_1(OLGraph G, int i)
{
	ArcBox *p;
	visited[i] = TRUE;					//��Ǹö����ѷ���
	printf("%c ", G.xlist[i].data);		//��ӡ�ö���
	p = G.xlist[i].firstout;
	while (p)
	{
		if (!visited[p->headvex])
			DFS_SCC_1(G, p->headvex);
		p = p->taillink;
	}
	finished[count++] = i;
}

void DFS_SCC_2(OLGraph G, int i)
{
	ArcBox *p;
	visited[i] = TRUE;					//��Ǹö����ѷ���
	printf("%c ", G.xlist[i].data);		//��ӡ�ö���
	p = G.xlist[i].firstout;
	while (p)
	{
		if (!visited[p->headvex])
			DFS_SCC_2(G, p->headvex);
		p = p->taillink;
	}
}

void Kosaraju(OLGraph G)
{
	int i, j;

	//��һ��DFS
	printf("\nfirst DFS: ------\n");
	DFS_Traverse_SCC(G);
	printf("\n--------first DFS\n");

	printf("\nfinished[count]: ------\n");
	for (j = 0; j < G.vexnum; j++)
	{
		printf("%d ", finished[j]);
	}
	printf("\n--------finished[count]\n");

	//��������ͼ
	InverseGraph(&G);

	printf("\nInverseGraph: ------\n");
	Print_DG_order(G);
	printf("--------InverseGraph\n");


	//�ڶ���DFS����
	for (i = 0; i < G.vexnum; i++)
		visited[i] = FALSE;

	printf("\nǿ��ͨ����Ϊ�� \n");
	for (i = G.vexnum - 1; i >= 0; i--)
	{
		if (!visited[finished[i]])
		{
			DFS_SCC_2(G, finished[i]);
			printf("\n");
		}
	}
}
