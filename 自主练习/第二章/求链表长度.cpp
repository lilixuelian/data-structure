
//求链表长度

int Length(Linklist H){
	int k = 0;
	Linklist p = H;
	while(p){
		k++;
		p = p -> next;
	}
	return k;
} 
 
