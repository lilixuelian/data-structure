void CreateList(LinkList &L){
	p = L;
	L = NULL;
	while(p){
		s = p;
		s->next = L;
		L = s;
		p = p->next;
	}
} 
