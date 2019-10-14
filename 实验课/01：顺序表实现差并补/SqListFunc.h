 #include <stdio.h> 
 #include <stdlib.h> // exit()
 
 typedef int ElemType;
 typedef int Boolean; // Boolean�ǲ�������,��ֵ��TRUE��FALSE
 
 #define TRUE 1
 #define FALSE 0

 /**********************************************************/
 /*              ���Ա��˳��洢�ṹ                      */
 /**********************************************************/
 #define LIST_INIT_SIZE 100 // ���Ա�洢�ռ�ĳ�ʼ������
 #define LISTINCREMENT 10   // ���Ա�洢�ռ�ķ�������

 struct SqList
 {
   int *elem; // �洢�ռ��ַ
   int length;     // ��ǰ����
   int listsize;   // ��ǰ����Ĵ洢����(��ElemTypeΪ��λ)
   int incrementsize; //Լ���������ռ�
 };

 /**********************************************************/
 /*          ˳���Ļ�������(12��)                        */
 /**********************************************************/
 void InitList_Sq(SqList &L)                    // �㷨2.4
 { // �������������һ���յ�˳�����Ա�L---------------1
   L.elem = new int[LIST_INIT_SIZE];
   //L.elem = (ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
   L.length = 0;                                // �ձ���Ϊ0
   L.listsize = LIST_INIT_SIZE;                 // ��ʼ�洢����
   L.incrementsize = LISTINCREMENT;           // ��Ҫʱ�����ݵ�Ԫ�ظ���
 }

 void DestroyList_Sq(SqList &L)                // �㷨2.8
 { // ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������˳�����Ա�L--------2
   free(L.elem);
   L.listsize = 0;
   L.length = 0;
 }

 void ClearList_Sq(SqList &L)
 { // ��ʼ������˳�����Ա�L�Ѵ��ڡ������������L����Ϊ�ձ�----------3
   L.length=0;
 }

 Boolean ListEmpty_Sq(SqList L)
 { // ��ʼ������˳�����Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE------4
   if(L.length == 0)
     return TRUE;
   else
     return FALSE;
 }

 int ListLength_Sq(SqList L)
 { // ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ���--------5
   return L.length;
 }

 void GetElem_Sq(SqList L,int i,ElemType &e)
 { // ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L)-----------6
   // �����������e����L�е�i������Ԫ�ص�ֵ
   if(i<1 || i>L.length)
   {
	   printf("iֵ���Ϸ���");
	   exit(-1);
   }
   //e = *(L.elem+i-1);
   e = L.elem[i-1];
 }

 int LocateElem_Sq(SqList L,ElemType e)         // �㷨2.5
 { // ��˳�����Ա�L�в��ҵ�һ��ֵ��e��ȵ�����Ԫ��------7
   // ������������ҵ�����������L�е�λ��������������Ԫ�ز����ڣ��򷵻�ֵΪ0��
   int i=1;                       // i�ĳ�ֵΪ��1��Ԫ�ص�λ��
   ElemType *p=L.elem;            // p�ĳ�ֵΪ��1��Ԫ�صĴ洢λ��
   while(i<=L.length && *p++!=e)
     ++i;
   if(i<=L.length)
     return i;
   else
     return 0;
 }

 void PriorElem_Sq(SqList L,ElemType cur_e,ElemType &pre_e)
 { // ��ʼ������˳�����Ա�L�Ѵ���
   // �����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ����-----------8
   //           �������ʧ�ܣ�pre_e�޶���
   ElemType *p=L.elem+1;
   while(p<=L.elem+L.length && *p!=cur_e)
	   p++;
   if(p>L.elem+L.length)
	   exit(-1);
   else
	   pre_e=*--p;
 }

 void NextElem_Sq(SqList L,ElemType cur_e,ElemType &next_e)
 { // ��ʼ������˳�����Ա�L�Ѵ���
   // �����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣�--------9
   //           �������ʧ�ܣ�next_e�޶���
   ElemType *p=L.elem;
   while(p<=L.elem+L.length-1 && *p!=cur_e)
	   p++;
   if(p==L.elem+L.length)
	   exit(-1);
   else
	   next_e=*++p;    
 }

 void ListInsert_Sq(SqList &L,int i,ElemType e)        // �㷨2.6
 { // ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L)+1--------------10
   // �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1
   ElemType *a,*p,*q;

   if( i<1 || i>L.length+1 )                 // iֵ���Ϸ�
   {
	   printf("iֵ���Ϸ���");
	   exit(-1);
   }

   if(L.length>=L.listsize)             // ��ǰ�洢�ռ�����,���ӷ���
   {
	   a = new ElemType[L.listsize+L.incrementsize];
	   if(!a)
		   exit(-1);                    // �洢����ʧ��
	   for(i=0; i<L.length; i++)
		   a[i] = L.elem[i];
	   delete [] L.elem;
	   L.elem = a;                      // �»�ַ
	   L.listsize+=L.incrementsize;     // ���Ӵ洢����
   }
   
   q = L.elem+i-1;                      // qΪ����λ��
   for(p=L.elem+L.length-1;p>=q;--p)    // ����λ�ü�֮���Ԫ�غ���
	   *(p+1) = *p;
   *q = e; // ����e
   ++L.length; // ����1
 }

 void ListDelete_Sq(SqList &L,int i,ElemType &e)            // �㷨2.7
 { // ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L)----------------11
   // ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1
   ElemType *p,*q;
   if( i<1 || i>L.length ) // iֵ���Ϸ�
   {
	   printf("iֵ���Ϸ���");
	   exit(-1);
   }
   p = L.elem+i-1; // pΪ��ɾ��Ԫ�ص�λ��
   e = *p; // ��ɾ��Ԫ�ص�ֵ����e
   q = L.elem+L.length-1; // ��βԪ�ص�λ��
   for(++p;p<=q;++p) // ��ɾ��Ԫ��֮���Ԫ��ǰ��
	   *(p-1)=*p;
   L.length--; // ����1
 }

 void ListTraverse_Sq(SqList L)
 { // ��ʼ������˳�����Ա�L�Ѵ���
   // ����������������L�е�ÿ������Ԫ��-----------------------------12
   ElemType *p;
   int i;
   p = L.elem;
   for(i=1;i<=L.length;i++)
   {
	   printf("%d ",*p);   //ElemTypeΪint�������˴˴���%d����Ϊ�������ͣ��˴���Ҫ�޸�  
	   p++;
   }
 }
