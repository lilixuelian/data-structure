//插入结点（后插）

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
//脑子不清不楚的。。。。傻逼了吗？要想实现插入操作，起码需要两个Node类型变量，一个是被插的项，一个是要插入的项，你只写了一个

//这种时候还是画图吧，尽管自己脑子里觉得自己会了。。。但是写了一次显然：不画出来脑子就是不清楚 

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
