//�����㣨��壩

void ListInsert(LinkList &H, Node *p, char mode){
	LinkList q = H;
	if(mode == 'A'){
		while(q != p){
			q = p -> next;
		}
		t = q -> next;
		q -> next = p;
		p -> next = q;
	}
} 
//���Ӳ��岻���ġ�������ɵ������Ҫ��ʵ�ֲ��������������Ҫ����Node���ͱ�����һ���Ǳ�����һ����Ҫ��������ֻд��һ��

//����ʱ���ǻ�ͼ�ɣ������Լ�����������Լ����ˡ���������д��һ����Ȼ�������������Ӿ��ǲ���� 

void ListInsert(LinkList &H, LNode *p, LNode *s, char mode){
	if(p == L){
		s -> next = L;
		L = s;
		return;
	}
	if(mode == 'A'){
		s -> next = p -> next;
		p -> next = s;
		return; 	
	}
	LinkList q = L;
	while(q -> next != p){
		q = q->next;
	}
	q->next = s;
	s->next = p;
} 
