//É¾³ıÔªËØ 
void ListDelete (LinkList &H, LNode *p, int e){
	if(p == H) H = p->next;
	else{
		q = H;
		while(q->next != p){
			q = q->next;
		}
		q->next = p->next;
	}
	e = p->data;
	delete p;
} 
