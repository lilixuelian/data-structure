//���򴴽��б�

//�����½�㣺 new LNode 

void CreateList(LinkList &H, int a[], int n){
	s = new LNode;
	s->data = a[n - 1];
	s->next = NULL;
	for(i = n - 2; i >= 0; i--){
		s = new LNode;
		s->data = a[i];
		
	}
} 
//�����Ӳ�����ˡ�����������Ҫ��ǰһ��ָ��ָ�Ų��У����ܹ������ڵ����node s��ֱ������H��ÿ���ƶ�H�Ϳ����� 
void CreateList(LinkList &H, int a[], int n){
	H = NULL;
	for(i = n - 1; i >= 0; i--){
		s = new LNode;
		s->data = a[i];
		s->next = H;
		H = s;
	}
} 
