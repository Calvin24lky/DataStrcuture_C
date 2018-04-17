#include"BiThrTree.h"

int main()
{
	BiThrTree T;
	BiThrTree Thrt;
	FILE *fp;
	errno_t err;
	InitBiThrTree(&T);
	if ((err = fopen_s(&fp, "MyOrderData.txt", "r")) != 0)    //��ͬ��2
	{
		printf("�޷��򿪴��ļ�\n");            //����򲻿���������򲻿�
		return 0;                            //��ֹ����
	}
	CreateBiThrTree(&T, fp);
	printf("Inorder: ");
	InOrderTraverse(T, Visit_Char);
	InOrderThreading(&Thrt, T);
	//getchar();
	fclose(fp);
	ClearBiThrTree(&Thrt);
	return 0;
}