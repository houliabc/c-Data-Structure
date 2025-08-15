#include <stdio.h>
#include <malloc.h>
#include <ctype.h>
#define Maxsize 100

//定义结点类型
typedef int elemtype;
//定义单链表的结构
typedef struct qnode{
	elemtype data;
	struct qnode *next;
}Datanode;  //表示单链表结点
//定义链队的结构
typedef struct{
	Datanode *front;
	Datanode *rear;
}LinkquNode;  //表示单链表链队结点

//链队的实现就是：入队用尾插法插入单链表表尾
//出队就是把头节点的后一位拿掉并释放空间，并使头节点指向头节点后两位


//数据操作：初始化、销毁、判断空、进队、出队
void initqueue(LinkquNode *&q){
	q=(LinkquNode *)malloc(sizeof(LinkquNode));
	q->rear=q->front=NULL;
}
bool emptyqueue(LinkquNode *q){
	return q->rear==NULL;
}
void enqueue(LinkquNode *&q,elemtype e){
	Datanode *p;
	p=(Datanode *)malloc(sizeof(Datanode));
	p->data=e;
	p->next=NULL;
	if(q->rear==NULL){
		q->front=q->rear=p;
	}
	else{
		q->rear->next=p;
		q->rear=p;
	}
}
bool dequeue(LinkquNode *&q,elemtype &e){
	Datanode *p=q->front;
	if(p==NULL)
		return false;
	if(q->front==q->rear)  //当队列仅有一个数据结点时
		q->front=q->rear=NULL;
	else  //当正常情况下
		q->front=p->next;
	e=p->data;
	free(p);
	return true;
}
void destroyqueue(LinkquNode *&q){
	//这里定义的是单链表中的单个结点，这样才能有data和next
	Datanode *pre=q->front,*p; //pre指向队首结点
	while(pre!=NULL){
		p=pre;
		pre=pre->next;
		free(p);
	}
	free(q);
//书上这么写，不知道为什么写这么复杂
//	if(pre!=NULL){
//		p=pre->next;
//		while(p!=NULL){
//			free(pre);
//			pre=p;
//			p=p->next;
//		}
//		free(pre);
//	}
//	free(q);
}
void dispqueue(LinkquNode *q){
	Datanode *p=q->front;
	while(p!=NULL){
		printf("%d,",p->data);
		p=p->next;
	}
}



//采用一个不带头结点只有一个尾指针rear的循环单链表来实现链队，设计初始化、进队、出队操作
typedef int elemtype;
//定义单链表的结构
typedef struct node{
	elemtype data;
	struct node *next;
}LinkNode;  

//只给你尾指针
void initqueue1(LinkNode *&rear){
	rear=NULL;
}
void enqueue1(LinkNode *&rear,elemtype e){
	LinkNode *p;
	p=(LinkNode *)malloc(sizeof(LinkNode));
	p->data=e;
	if(rear==NULL){
		p->next=p;  //使链表循环起来
		rear=p;
	}
	else{
		p->next=NULL;
		rear->next=p;
		rear=p;
	}
}
bool dequeue1(LinkNode *&rear,elemtype &e){
	LinkNode *p=rear->next;
	if(rear==NULL)
		return false;
	if(rear->next==rear){  //当队列仅有一个数据结点时
		e=rear->data;
		free(rear);
		rear=NULL;
	}
	else  //当正常情况下
	{
		e=p->data;
		rear->next=p->next;
		free(p);
	}
	return true;
}



int main(){
	elemtype e=1;
	LinkquNode *q;
	initqueue(q);
	for(int i=0;i<Maxsize;i++)
		enqueue(q,i);
	dequeue(q,e);   //0最先进去所以最先出来
	printf("%d\n",emptyqueue(q));  
	dispqueue(q);
	destroyqueue(q); //队列销毁后，不能再对该队列进行操作
	return 0;
}
