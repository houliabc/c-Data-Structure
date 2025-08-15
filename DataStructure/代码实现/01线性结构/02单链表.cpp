#include <stdio.h>
#include <malloc.h>

typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode * next;
}LinkNode; //LNode强调的是结点，LinkNode强调的是链表

//二、建立单链表
//1.头插法
void createlisthead(LinkNode *&L,ElemType a[],int n){
	LinkNode *s;  //先创建单节点，在分别为链表L和每次新建的新节点分配空间
	//大小分别是链表的大小和结点的大小
	L=(LinkNode *)malloc(sizeof(LinkNode));
	L->next=NULL;
	for(int i=0;i<n;i++){
		s=(LinkNode *)malloc(sizeof(LNode));
		s->data=a[i];
		s->next=L->next;
		L->next=s;
	}
}
//2.尾插法
void createlisttail(LinkNode *&L,ElemType a[],int n){
	LinkNode *s,*r;  //尾指针
	L=(LinkNode *)malloc(sizeof(LinkNode));
	L->next=NULL;
	r=L;
	for(int i=0;i<n;i++){
		s=(LinkNode *)malloc(sizeof(LNode));
		s->data=a[i];
		r->next=s;
		r=s;
	}
	r->next=NULL;
}

//三、链表的基本运算
//1.初始化链表
void initlist(LinkNode *&L){
	L=(LinkNode *)malloc(sizeof(LinkNode));
	L->next=NULL;
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
	return(L->next==NULL);
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
//8.在指定位置前插入数据元素
bool insertlist(LinkNode *&L,int n,ElemType e){
	LinkNode *p=L,*s;
	int i=0;
	if(n<1||n>listlength(L))
	{
		printf("位置错误");
		return false;
	}
	for(i=0;i<n-1 && p->next!=NULL;i++){
		p=p->next;
	}
	if(p->next==NULL)
		return false;
	else{
		s=(LinkNode *)malloc(sizeof(LinkNode));
		s->data=e;
		s->next=p->next;
		p->next=s;
		return true;
	}
}
//9.删除指定位置的结点
bool deletelist(LinkNode *&L,int n,ElemType &e){
	LinkNode *p=L,*q;//p是前指针，q是后指针，要free的
	int i=0;
	if(n<1)
		return false;
	while(i<n-1 && p->next!=NULL){
		i++;
		p=p->next;
	}
	if(p==NULL)
		return false;
	else{
		q=p->next;
		if(q==NULL)
			return false;
		e=q->data;
		p->next=q->next;
		free(q);
		return true;
	}
}
//四、应用
//1.将L的元素依次分给L1（尾插）和L2（头插）
void splitlist(LinkNode *&L,LinkNode *&L1,LinkNode *&L2){
	LinkNode *p=L->next,*r1=L1=L,*q;//r1每次指向L1的尾指针进行尾插入
	//L1用L的头结点，L2另开创一个头结点
	L2=(LinkNode *)malloc(sizeof(LinkNode));
	L2->next=NULL;
	int i=1;  //记录当前是L表中的第几个元素，奇数入L1，偶数入L2
	while(p!=NULL){
		q=p->next;
		if(i%2==1){  //尾插入到L1中
			r1->next=p;
			r1=p;
		}
		else{  //头插入到L2中
			
			p->next=L2->next;
			L2->next=p;
		}
		p=q;
		i++;
	}
	r1->next=NULL;
}
//或者
void splitlist2(LinkNode *&L,LinkNode *&L1,LinkNode *&L2){
	LinkNode *p=L->next,*r1=L1=L,*q;
	L2=(LinkNode *)malloc(sizeof(LinkNode));
	L2->next=NULL;
	
	while(p!=NULL){
		r1->next=p;
		r1=p;
		p=p->next;
		q=p->next;	
		p->next=L2->next;
		L2->next=p;
		p=q;
		}
	r1->next=NULL;
}
	
//2.设计一个算法，删除L中元素值最大的结点（假设这样的结点唯一）
void deletemax(LinkNode *&L,ElemType &e){
	LinkNode *p=L->next,*pre=L,*q=L;  //q用来存放最大的结点的前一个，pre始终p的前一个
	ElemType max=p->data;
	while(p->next!=NULL){
		pre=p;
		p=p->next;
		if(p->data>max){
			q=pre;
			max=p->data;	
		}
	}
	e=max;
	p=q->next;
	q->next=p->next;
	free(p);
}

//3.有一个带头结点的单链表L（至少有一个数据结点），设计一个算法使其元素递增有序排列
//思路：每次遍历n次单链表，其中应该执行n*（n-1）*（n-2）*。。。
//每一次遍历都取出最小的结点，每次将其再运用头插法插入链表当中，还要用一个结点保存每次头插后的新的头结点，而不是每次都是L
void ranklist(LinkNode *&L){
	LinkNode *minpre,*p,*l=L,*pre,*q;
	ElemType min;
	while(l->next!=NULL){
		p=l->next;
		min=p->data;
		minpre=l;
		while(p->next!=NULL){
			pre=p;
			p=p->next;
			if(p->data<min){
				min=p->data;
				minpre=pre;	
			}
		}//已找出最小的结点，准备头插
		q=minpre->next;
		minpre->next=minpre->next->next;
		q->next=l->next;
		l->next=q;
		l=l->next;
	}
}
//课本的写法
//基本思想：将首节点后一位到表尾的链表拎出来，用p来表示。头结点与首节点单出拿出来构成L
//然后依次判断p链表的元素是否＜L链表当中最大的元素，如果是，则放最大元素的前面，同时，这也是放最小元素的后面
void ranklist2(LinkNode *&L){
	LinkNode *p,*pre,*q;
	p=L->next->next;
	L->next->next=NULL;
	while(p!=NULL){
		q=p->next;
		pre=L;
		while(pre->next!=NULL && pre->next->data>p->data){  //为了区别，这里就用降序好了
			pre=pre->next;
		}
		p->next=pre->next;
		pre->next=p;
		p=q;
	}
}

	


int main(){
	
	ElemType a[]={10,20,30,40,50,60,70,80,90,100};
	ElemType n=3,e=false;//e用来接收查找或删除的值留作备份
	LinkNode *L,*L1,*L2;
	//printf("：%d\n",);
	//displist(L);
	initlist(L);//先初始化在插入吧？
	createlisthead(L,a,sizeof(a)/sizeof(a[0]));
	createlisttail(L,a,sizeof(a)/sizeof(a[0]));
	printf("链表是否为空呢：%d\n",listempty(L));
	printf("链表的长度是：%d\n",listlength(L));
	printf("输出链表：\n");
	displist(L);
	
	printf("第%d个元素存在吗：%d。存在的话是",n,getelem(L,n,e));
	printf("%d\n",e);   //这里当行做的修改没那么快生效
	printf("%d是第%d个元素\n",e,locatelist(L,e));
	
	printf("插入了元素之后\n");
	insertlist(L,2,200);
	displist(L);
	printf("删除了元素之后\n");
	deletelist(L,5,e);
	displist(L);
	printf("删除了%d\n",e);
	
	printf("-------------\n");
	displist(L);
	printf("单链表分二\n");
	splitlist2(L,L1,L2);
	displist(L1);
	displist(L2);
	splitlist(L,L1,L2);
	displist(L1);
	displist(L2);
	printf("deletemax-------------\n");
	deletelist(L,3,e);
	insertlist(L,2,100);  
	displist(L);
	deletemax(L,e);
	displist(L);
	printf("e=%d",e);
	
	printf("\nranklist-------------\n");
	for(int i=0;i<10;i++)
		insertlist(L,1,i);
	displist(L);
	ranklist(L);
	displist(L);
	ranklist2(L);
	displist(L);
	
	
	destroylist(L);
	return 0;
}
