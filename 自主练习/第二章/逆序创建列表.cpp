//逆序创建列表

//生成新结点： new LNode 

void CreateList(LinkList &H, int a[], int n){
	s = new LNode;
	s->data = a[n - 1];
	s->next = NULL;
	for(i = n - 2; i >= 0; i--){
		s = new LNode;
		s->data = a[i];
		
	}
} 
//这样子不会搞了。。。。必须要有前一个指针指着才行，不能光有现在的这个node s，直接利用H，每次移动H就可以了 
void CreateList(LinkList &H, int a[], int n){
	H = NULL;
	for(i = n - 1; i >= 0; i--){
		s = new LNode;
		s->data = a[i];
		s->next = H;
		H = s;
	}
} 
