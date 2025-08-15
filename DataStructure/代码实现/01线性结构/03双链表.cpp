#include <stdio.h>
#include <malloc.h>

typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode * next,*prior;
}LinkNode; 
//Node强调的是双链表结点，LinkNode强调的是双链表本身

//一、建立双链表
//1.头插法
void createlist(LinkNode *&L,ElemType a[],int n){
	LinkNode *s;
	L=(LinkNode *)malloc(sizeof(LinkNode));
	L->prior=L->next=NULL;
	for(int i=0;i<n;i++){
		s=(LinkNode *)malloc(sizeof(LNode));
		s->data=a[i];
		s->next=L->next;
		if(L->next!=NULL)
			L->next->prior=s;
		s->prior=L;
		L->next=s;
	}
}
//2.尾插法
void createlist2(LinkNode *L,ElemType a[],int n){
	LinkNode *s,*r;
	L=(LinkNode *)malloc(sizeof(LinkNode));
	r=L;
	for(int i=0;i<n;i++){
		s=(LinkNode *)malloc(sizeof(LinkNode));
		s->data=a[i];
		r->next=s;
		s->prior=r;
		r=s;
	}
	r->next=NULL;
}

//三、双链表的基本操作
//1.初始化链表
void initlist(LinkNode *&L){
	L=(LinkNode *)malloc(sizeof(LinkNode));
	L->next=NULL;
	L->prior=NULL;
}
//2.销毁链表
void destroylist(LinkNode *&L){
	//销毁在于连头指针也要销毁
	LinkNode *pre=L,*p=L->next;
	while(p!=NULL){
		free(pre);
		pre=p;
		p=p->next;
	}
	free(pre);
}
//3.判断链表是否为空
bool listempty(LinkNode *L){
	return(L->next==NULL && L->prior==NULL);
}
//4.求链表的长度,头节点不算在内
int listlength(LinkNode *L){
	int n=0;
	LinkNode *p=L;
	while(p->next!=NULL){
		n++;
		p=p->next;
	}
	return n;
}
//5.输出链表
void displist(LinkNode *L){
	LinkNode *p=L;
	while(p->next!=NULL){
		printf("%d,",p->next->data);
		p=p->next;
	}
	printf("\n");
}
//6.求线性表中某个数据的元素值
bool getelem(LinkNode *L,int i,ElemType &e){
	LinkNode *p=L->next;
	if(i<=0)
		return false;
	for(int j=1;j<i;j++){
		if(p==NULL)
			return false;
		p=p->next;
	}
	e=p->data;
	return true;
}
//7.按元素值查找并返回位数
int locatelist(LinkNode *L,ElemType e){
	int i=1;
	LinkNode *p=L->next;
	if(p==NULL)
		return false;
	while(p->next!=NULL && e!=p->data){
		i++;p=p->next;
	}
	if(e==p->data)
		return i;
	else 
		return false;
}
//8.在指定位置前插入结点
bool insertlist(LinkNode *&L,int i,ElemType e){
	int j=0;
	LinkNode *p=L->next,*s;
	if(i<=0)
		return false;
	while(j<i-1 && p->next!=NULL){
		j++;
		p=p->next;
	}
	if(p->next==NULL){
		return false;
	}
	s=(LinkNode *)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	if(p->next!=NULL)    //未找到第i-1个结点
		p->next->prior=s;
	s->prior=p;
	p->next=s;
	return true;
}
//9.删除指定位置的结点
bool deletelist(LinkNode *&L,int i,ElemType &e){
	int j=0;
	LinkNode *p=L,*q;
	if(i<=0)
		return false;
	while(j<i-1 && p->next!=NULL){
		j++;
		p=p->next;
	}
	if(p->next==NULL)  //未找到第i-1个结点
		return false;
	q=p->next;  //先找到第i-1个结点，然后删除第i个结点即q结点
	e=q->data;
	p->next=q->next;
	if(p->next!=NULL){
		q->next->prior=p;
	}
	free(q);
	return true;
}

//三、应用实例
//1.将所有元素逆置（用的是头插法的思想）
bool reverselist(LinkNode *&L){
	LinkNode *p=L->next,*q=p; //p用来表示每次头插进去的指针
	//q表示p的下一个指针
	L->next=NULL;
	while(p!=NULL){
		q=p->next;//因为下面要使p的next每次指向首结点，所以需要一个变量保存现在p的next
		p->next=L->next;
		if(L->next!=NULL)
			L->next->prior=p;
		p->prior=L;
		L->next=p;
		p=q;
	}
}
//2.使一个带头节点的双链表，递增有序排序
//我的思想：依次比较，每次将最小的
void sortlist(LinkNode *&L){
	
}

int main(){
	ElemType a[]={10,20,30,40,50,60,70,80,90,100};
	ElemType n=3,e=114514;//e用来接收查找或删除的值留作备份
	LinkNode *L;
	createlist(L,a,sizeof(a)/sizeof(a[0]));
	//利用sizeof来判断数组长度
	displist(L);
	
	//插入
	insertlist(L,n,e);
	displist(L);
	//删除
	deletelist(L,n+1,e);
	displist(L);
	
	//逆置双链表
	reverselist(L);
	displist(L);
    return 0;
}
