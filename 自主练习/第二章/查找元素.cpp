//����Ԫ�� 

LNode * LocateElem(LinkList H, int e){
	LinkList p = H;
	while(p){
		if(p.data == e){
			return p;
			break;
		}
		p = p -> next;
	}
	return -1; //������ˣ�����ֵ��һ��ָ�룬��ô����д��һ��intֵ 
} 

//�������ѭ�������Ļ���pָ�����NULL�����Բ���Ҫר��дһ��return NULL��ֱ��returnp�Ϳ�����

//����������û�ҵ������ն���Ҫreturn p���ǾͰ�return pд��һ��

LNode * LocateElem(LinkList H, int e){
	LinkList p = H;
	while(p && p.data != e) p = p -> next;
	return p;
} 


