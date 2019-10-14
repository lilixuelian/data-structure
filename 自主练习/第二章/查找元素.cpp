//查找元素 

LNode * LocateElem(LinkList H, int e){
	LinkList p = H;
	while(p){
		if(p.data == e){
			return p;
			break;
		}
		p = p -> next;
	}
	return -1; //这里错了，返回值是一个指针，怎么可以写成一个int值 
} 

//如果最终循环结束的话，p指向的是NULL，所以不需要专门写一个return NULL，直接returnp就可以了

//反正不管找没找到，最终都是要return p，那就把return p写到一起

LNode * LocateElem(LinkList H, int e){
	LinkList p = H;
	while(p && p.data != e) p = p -> next;
	return p;
} 


