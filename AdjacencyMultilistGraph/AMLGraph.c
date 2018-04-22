#include"AMLGraph.h"

Status CreateGraph_AML(AMLGraph *G, FILE *fp, GraphKind Gkind)
{
	Status result;
	switch (Gkind)
	{
	case UDG:
		result = CreateUDG_AML(fp, G);
		return result;
	case UDN:
		result = CreateUDN_AML(fp, G);
		return result;
	default:
		result = ERROR;
		return result;
		break;
	}
	/*printf("kind: %d", Gkind);*/
	return OK;
}

int LocateVex(AMLGraph G, VertexType_AML v)
{
	int i;
	for (i = 0; i < G.edgenum; i++)
	{
		if (G.adjmulist[i].data == v)
		{
			return i;
		}
	}
	return -1;
}

Status CreateUDG_AML(FILE *fp, AMLGraph *G)
{
	char tmp;
	int i, k, vi, vj;
	VertexType_AML vhead, vtail;
	EdgeBox *edge;
	//EdgeBox **p;
	Scanf(fp, "%d%d%d", &((*G).kind), &((*G).vexnum), &((*G).edgenum));		//����ͼ���͡�������������

	Scanf(fp, "%c", &tmp);													//�������з�

	for (i = 0; i < (*G).vexnum; i++)
	{
		Scanf(fp, "%c", &((*G).adjmulist[i].data));							//����ֵ���붥������
		(*G).adjmulist[i].firstedge = NULL;									//�߱���Ϊ�ձ�
	}

	Scanf(fp, "%c", &tmp);													//�������з�

	for (k = 0; k < (*G).edgenum; k++)
	{
		Scanf(fp, "%c%c", &vhead, &vtail);				//����ߵ���Ϣ
		vi = LocateVex(*G, vhead);
		vj = LocateVex(*G, vtail);					//vi��vj��Ӧ���ڽӾ����бߵ�ͷ��β
		if (vj == -1 || vi == -1)
			return ERROR;
		edge = (EdgeBox *)malloc(sizeof(EdgeBox));		//���ɱ�
		if (!edge)
			exit(OVERFLOW);
		edge->ivex = vi;
		edge->jvex = vj;
		edge->ilink = NULL;
		edge->jlink = NULL;

		edge->ilink = (*G).adjmulist[vi].firstedge;
		(*G).adjmulist[vi].firstedge = edge;

		edge->jlink = (*G).adjmulist[vj].firstedge;
		(*G).adjmulist[vj].firstedge = edge;

		//p = &((*G).adjmulist[vi].firstedge);		//p��ָ��firstedge�Ķ���ָ�� firstedge����ivex,jvex,*ilink,*jlink����
		//while ((*p) != NULL)					//����ΪNULL��˵��firstedge��ֵ����pָ��firstedge��ilink
		//{
		//	p = &((*p)->ilink);
		//}
		//*p = edge;
	}

	return OK;
}

Status CreateUDN_AML(FILE *fp, AMLGraph *G)
{
	return OK;
}