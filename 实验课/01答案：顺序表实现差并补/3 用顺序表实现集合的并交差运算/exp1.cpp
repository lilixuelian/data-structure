//����˳���ʵ�������������ϵĲ�������������㡣��
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

//�󲢼�
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

//�󽻼�
void Inter(SqList La, SqList Lb, SqList &Lc)
{
	int i, j = 0;
	ElemType e;

	for (i = 1; i <= ListLength_Sq(La); i++)
	{
		GetElem_Sq(La, i, e);  //ȡ����A�е�Ԫ��
		if (LocateElem_Sq(Lb, e))  //�ڼ���B�д��ڸ�Ԫ��
		{
			j++;
			ListInsert_Sq(Lc, j, e); //���뵽����C��
		}
	}
}

//��
void Sub(SqList La, SqList Lb, SqList &Lc)
{
	int i, j = 0;
	ElemType e;

	for (i = 1; i <= ListLength_Sq(La); i++)
	{
		GetElem_Sq(La, i, e);  //ȡ����A�е�Ԫ��
		if (!LocateElem_Sq(Lb, e))  //�ڼ���B�в����ڸ�Ԫ��
		{
			j++;
			ListInsert_Sq(Lc, j, e); //���뵽����C��
		}
	}
}

void main()
{
	SqList La, Lb, Lc, Ld, Le, Lf;

	printf("************* Input A ***************\n");
	InitList_Sq(La);
	InputElement(La);

	printf("************* Input B ***************\n");
	InitList_Sq(Lb);
	InputElement(Lb);

	InitList_Sq(Lc); // ����C��A��B��
	Union(La,Lb,Lc);

	InitList_Sq(Ld); // ����D��A��B��
	Inter(La,Lb,Ld);

	InitList_Sq(Le); // ����E��A-B��
	Sub(La,Lb,Le);

	InitList_Sq(Lf); // ����F��B-A��
	Sub(Lb,La,Lf);
	
	printf("\n************* Result ****************\n");
	printf("A = {"); // �������A
	ListTraverse_Sq(La);
	printf("}\n"); 

	printf("B = {"); // �������B
	ListTraverse_Sq(Lb);
	printf("}\n"); 

	printf("A U B = {"); // �������C��A��B��
	ListTraverse_Sq(Lc);
	printf("}\n"); 
	
	printf("A * B = {"); // �������D��A��B��
	ListTraverse_Sq(Ld);
	printf("}\n"); 
	
	printf("A - B = {"); // �������E��A-B��
	ListTraverse_Sq(Le);
	printf("}\n"); 

	printf("B - A = {"); // �������F��B-A��
	ListTraverse_Sq(Lf);
	printf("}\n"); 
	printf("*************************************\n");

	DestroyList_Sq(La);
	DestroyList_Sq(Lb);
	DestroyList_Sq(Lc);
	DestroyList_Sq(Ld);
	DestroyList_Sq(Le);
	DestroyList_Sq(Lf);
}



