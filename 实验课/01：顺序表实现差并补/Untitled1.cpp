#include<stdio.h>
#include "SqListFunc.h"

void merge(SqList &a, SqList &b, SqList &add){
	int i, j;
	for(i = 0; i < ListLength_Sq(a); i++){
		add.elem[i] = a.elem[i];
		add.length++;
	}
	for(j = 0; j < ListLength_Sq(b); j++){
		if(!LocateElem_Sq(add, b.elem[j])){
			add.elem[i++] = b.elem[j];
			add.length++;
		}
	}
}

void intersect(SqList &a, SqList &b, SqList &diff){
	int i, j = 0;
	
	for(i = 0; i < ListLength_Sq(a); i++){
		if(LocateElem_Sq(b, a.elem[i])){
			diff.elem[j++] = b.elem[i];
			diff.length++;
		}
	}
}

void Minus(SqList &a, SqList &b, SqList &minus){
	int i, j = 0;
	struct SqList diff;
	InitList_Sq(diff);
	intersect(a, b, diff);
	
	for(i = 0; i < ListLength_Sq(a); i++){
		if(!LocateElem_Sq(diff, a.elem[i])){
			minus.elem[j++] = a.elem[i];
			minus.length++;
		}
	}
}

int main (void){
	
	int a[100], b[100];
	int i, na, nb;
	
	struct SqList A;
	struct SqList B;
	struct SqList add;
	struct SqList diff;
	struct SqList aminusb;
	struct SqList bminusa;
	
	InitList_Sq(A);
	InitList_Sq(B);
	InitList_Sq(add);
	InitList_Sq(diff);
	InitList_Sq(aminusb);
	InitList_Sq(bminusa);
	
	printf("�����뼯��A��Ԫ�ظ�����");
	scanf("%d", &na);
	printf("���������뼯��AԪ�ص���ֵ��");
	for(i = 0; i < na; i++){
		scanf("%d", &a[i]);
		A.elem[i] = a[i];
		A.length++;
	}
	printf("�����뼯��B��Ԫ�ظ�����");
	scanf("%d", &nb);
	printf("���������뼯��BԪ�ص���ֵ��");
	for(i = 0; i < nb; i++){
		scanf("%d", &b[i]);
		B.elem[i] = b[i];
		B.length++;
	}  
	
	merge(A, B, add);
	intersect(A, B, diff);
	Minus(A, B, aminusb);
	Minus(B, A, bminusa);
	
	printf("A��B�Ĳ�����"); 
	for(i = 0; i < add.length; i++){
		printf("%d ", add.elem[i]);
	}
	printf("\nA��B�Ľ�����");
	for(i = 0; i < diff.length; i++){
		printf("%d ", diff.elem[i]);
	}
	printf("\nA - B�Ĳ��");
	for(i = 0; i < aminusb.length; i++){
		printf("%d ", aminusb.elem[i]);
	}
	printf("\nB - A�Ĳ��");
	for(i = 0; i < bminusa.length; i++){
		printf("%d ", bminusa.elem[i]);
	}

	return 0;
}
