#include"BinaryTree.h"

int main()
{
	BiTree T;
	FILE *fp;
	errno_t err;
	Status result;
	int depth;
	InitBiTree(&T);
	if ((err = fopen_s(&fp, "MyOrderData.txt", "r")) != 0)    //��ͬ��2
	{
		printf("�޷��򿪴��ļ�\n");            //����򲻿���������򲻿�
		return 0;                            //��ֹ����
	}
	result = CreateBiTree(&T, fp);
	depth = BiTreeDepth(T);
	printf("BiTree Depth: %d\n", depth);
	printf("Preoder: ");
	PreOrderTraverse(T, Visit_Char);
	printf("\nInorder: ");
	InOrderTraverse(T, Visit_Char);
	printf("\nPostorder: ");
	PostOrderTraverse(T, Visit_Char);
	getchar();
	fclose(fp);
	ClearBiTree(&T);
	return 0;
}