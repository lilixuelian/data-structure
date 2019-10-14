//���㷨2.1Ϊ�������������������ϵĲ������㣨ԭ���ϲ��䣬��������ŵ��µļ����У���
#include "SqListFunc.cpp" // �������Ա��˳��洢�ṹ

void InputElement(SqList &L)   //���뼯��Ԫ�ص����Ա�L��
{
	int i, num, e;
	
	printf("num  = ");
	scanf("%d", &num);
	printf("elem = ");
	for(i = 1; i <= num; i++)
	{
		scanf("%d", &e);
		ListInsert_Sq(L, i, e); 
	}
}

//�󲢼� ===> Lc
void Union(SqList La, SqList Lb, SqList &Lc)
{
	// �㷨2.1���޸ģ������Ա�La��Lb�ϲ����µ����Ա�Lc���㷨ִ�н��������Ա�La��Lb����
	int i, j = 0;
	ElemType e;

	for (i = 1; i <= ListLength_Sq(La); i++)
	{
		GetElem_Sq(La, i, e);  //ȡ����A�е�Ԫ��
		j++;
		ListInsert_Sq(Lc, j, e); //���뵽����C��
	}
	for (i = 1; i <= ListLength_Sq(Lb); i++)
	{
		GetElem_Sq(Lb, i, e);  //ȡ����B�е�Ԫ��
		if (LocateElem_Sq(Lc, e))  //�ڼ���C�д��ڸ�Ԫ��
			continue;
		j++;
		ListInsert_Sq(Lc, j, e); //���뵽����C��
	}
} 

void main()
{
	SqList La, Lb, Lc;
	
	printf("************* Input A ***************\n");
	InitList_Sq(La);
	InputElement(La);

	printf("************* Input B ***************\n");
	InitList_Sq(Lb);
	InputElement(Lb);

	InitList_Sq(Lc);
	
	Union(La,Lb,Lc);

	printf("\n************* Result ****************\n");
	printf("A = {"); // �������A
	ListTraverse_Sq(La);
	printf("}\n"); 

	//for(int i=0;i<La.length;i++)
	//	printf("La.elem[%d] = %d \n", i, La.elem[i]);

	printf("B = {"); // �������B
	ListTraverse_Sq(Lb);
	printf("}\n"); 

	printf("A U B = {"); // �������C
	ListTraverse_Sq(Lc);
	printf("}\n"); 
	printf("*************************************\n");

	DestroyList_Sq(La);// ��ӦInitList_Sq(La)�ж�̬���ٵ��ڴ�
    DestroyList_Sq(Lb);// ��ӦInitList_Sq(Lb)�ж�̬���ٵ��ڴ�
	DestroyList_Sq(Lc);// ��ӦInitList_Sq(Lc)�ж�̬���ٵ��ڴ�
}