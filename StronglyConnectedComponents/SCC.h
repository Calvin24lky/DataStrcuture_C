#include"OLGraph.h"
 
int count;
int finished[MAX_VEXTEX_NUM];
Status visited[MAX_VEXTEX_NUM];

//��������ͼ
void InverseGraph(OLGraph *G);

//������ȱ���
void DFS_Traverse_SCC(OLGraph G);

void DFS_SCC_1(OLGraph G, int i);

void DFS_SCC_2(OLGraph G, int i);

void Kosaraju(OLGraph G);