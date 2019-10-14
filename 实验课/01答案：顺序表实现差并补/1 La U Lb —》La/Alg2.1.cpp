//����������Ϊ����ʵ���㷨2.1�����������ϵĲ������㡣
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

void Union(SqList &La, SqList &Lb) 
{
    // �㷨2.1�������Ա� Lb �������� La �в����ڵ�����Ԫ�ز��뵽 La �У��㷨ִ�н��������Ա� Lb ���ٴ���
    ElemType e;  
	int La_len = ListLength_Sq(La);          // �����Ա� La �ĳ���
    while (!ListEmpty_Sq(Lb)) {          // Lb ���Ԫ����δ������
       ListDelete_Sq(Lb, 1, e);          // �� Lb ��ɾ����һ������Ԫ�ظ��� e
       if (!LocateElem_Sq(La, e))
		   ListInsert_Sq(La, ++La_len, e ); // ��La�в�����ֵ�� e ��ȵ�����Ԫ�أ�����������La �����һ������Ԫ��֮��
      } // while
      DestroyList_Sq(Lb);             // �������Ա�Lb����ӦInitList_Sq(Lb)�ж�̬���ٵ��ڴ�
} 

void main()
{
	SqList La, Lb;
	
	printf("************* Input A ***************\n");
	InitList_Sq(La);
	InputElement(La);

	printf("************* Input B ***************\n");
	InitList_Sq(Lb);
	InputElement(Lb);
	
	Union(La,Lb);

	printf("\n************* Result ****************\n");
	printf("A = {"); // �������A
	ListTraverse_Sq(La);
	printf("}\n"); 
	printf("*************************************\n");

	DestroyList_Sq(La);// ��ӦInitList_Sq(La)�ж�̬���ٵ��ڴ�
}