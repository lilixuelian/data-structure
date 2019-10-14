//以算法2.1为基础，求两个整数集合的并的运算（原集合不变，运算结果存放到新的集合中）。
#include "SqListFunc.cpp" // 采用线性表的顺序存储结构

void InputElement(SqList &L)   //输入集合元素到线性表L中
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

//求并集 ===> Lc
void Union(SqList La, SqList Lb, SqList &Lc)
{
	// 算法2.1的修改：将线性表La和Lb合并成新的线性表Lc，算法执行结束后，线性表La和Lb不变
	int i, j = 0;
	ElemType e;

	for (i = 1; i <= ListLength_Sq(La); i++)
	{
		GetElem_Sq(La, i, e);  //取集合A中的元素
		j++;
		ListInsert_Sq(Lc, j, e); //插入到集合C中
	}
	for (i = 1; i <= ListLength_Sq(Lb); i++)
	{
		GetElem_Sq(Lb, i, e);  //取集合B中的元素
		if (LocateElem_Sq(Lc, e))  //在集合C中存在该元素
			continue;
		j++;
		ListInsert_Sq(Lc, j, e); //插入到集合C中
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
	printf("A = {"); // 输出集合A
	ListTraverse_Sq(La);
	printf("}\n"); 

	//for(int i=0;i<La.length;i++)
	//	printf("La.elem[%d] = %d \n", i, La.elem[i]);

	printf("B = {"); // 输出集合B
	ListTraverse_Sq(Lb);
	printf("}\n"); 

	printf("A U B = {"); // 输出集合C
	ListTraverse_Sq(Lc);
	printf("}\n"); 
	printf("*************************************\n");

	DestroyList_Sq(La);// 对应InitList_Sq(La)中动态开辟的内存
    DestroyList_Sq(Lb);// 对应InitList_Sq(Lb)中动态开辟的内存
	DestroyList_Sq(Lc);// 对应InitList_Sq(Lc)中动态开辟的内存
}