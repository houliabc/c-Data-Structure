// 循环双链表 ，删除data结点
bool deletem(DLinkNode *&L,ElemType x){
	DlinkNode *p=L->next;
	while(p!=L && p->data!=x)
		p=p->next;
	if(p!=L){
		p->next->prior=p->prior;
		p->prior-next=p->next;
		free(q)
	}
} 
