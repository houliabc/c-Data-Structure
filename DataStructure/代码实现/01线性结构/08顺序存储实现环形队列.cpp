#include <stdio.h>
#include <stdlib.h>
#define Maxsize 100

//普通的环形队列
typedef int elemtype;
typedef struct{
	elemtype data[Maxsize];
	int rear,front;  //头指针和尾指针的下标
}SqQueue;
void initQueue(SqQueue *&q){
	q=(SqQueue *)malloc(sizeof(SqQueue));
	q->rear=q->front=0;
}
void destroyQueue(SqQueue *&q){
	free(q);
}
bool emptyQueue(SqQueue *q){
	return q->front==q->rear;
}
bool enQueue(SqQueue *&q,elemtype e){
	//先判断是否队满
	if((q->rear+1)%Maxsize==q->front)
		return false;
	q->rear=(q->rear+1)%Maxsize;
	q->data[q->rear]=e;
	return true;
}
bool deQueue(SqQueue *&q,elemtype &e){
	//先判断队是否为空
	if(q->rear==q->front)
		return false;
//注意区别：顺序队入队出队都是先动指针后动元素
//而栈是入栈先动指针，出栈先动元素
	q->front=(q->front+1)%Maxsize;
	e=q->data[q->front];
	return true;
}
void dispQueue(SqQueue *q){
	while(q->rear!=q->front){
		q->front++; 
		printf("%d,",q->data[q->front]);
	}
}



//只知道队头指针及元素个数的环形队列
typedef struct{
	elemtype data[Maxsize];
	int front,count;
}SqQueue2;
void initQueue2(SqQueue2 *&q){
	q=(SqQueue2 *)malloc(sizeof(SqQueue2));
	q->front=q->count=0;
}
bool emptyqueue2(SqQueue2 *q){
	return (q->count==0);
}
bool enqueue2(SqQueue2 *&q,elemtype e){
	if(q->count==Maxsize)
		return false;
	//计算队尾元素
	int rear=(q->front+q->count)%Maxsize;
	rear=(rear+1)%Maxsize;
	q->data[rear]=e;
	q->count++;
	return true;
}
bool deQueue2(SqQueue2 *&q,elemtype e){
	if(q->count==0)
		return false;
	q->front=(q->front+1)%Maxsize;
	e=q->data[q->front];
	q->count--;
	return true;
}


//设n个人站成一排，从左往右编号分别是1-n，现在从左往右报数1，2，1，2.。。数到1的出列，数到2的立刻站队伍最右端。直到n个人都出列为止
void number(int n){
	int i;elemtype e;
	SqQueue *q;
	initQueue(q);
	for(i=1;i<=n;i++){
		enQueue(q,i);	
	}
	printf("报数出列顺序：");
	while(!emptyQueue(q)){
		//一次删两个，增一个，相当于每次删一个，那么只需要执行n次就能全部删完，此时emptyqueue为1跳出循环
		deQueue(q,e);
		printf("%d ",e);
		if(!emptyQueue(q)){
			deQueue(q,e);
			enQueue(q,e);			
		}
	}
	printf("\n");
	destroyQueue(q);
}


//双端环形队列的操作
//双端环形队列从队尾删除运算
bool dequeue3(SqQueue *&q,elemtype e){
	if(q->front==q->rear)
		return false;
	e=q->data[q->rear];
	q->rear=(q->rear-1+Maxsize)%Maxsize;
	return true;
}
//从队头插入运算
bool enqueue3(SqQueue *&q,elemtype e){
	if(q->front==(q->rear+1)%Maxsize)
		return false;
	q->data[q->front]=e;
	q->front=(q->front-1+Maxsize)%Maxsize;
	return true;
}

int main(){
	elemtype a[]={1,2,3,4,5,6,7,8,9,10};
	SqQueue *q;
	initQueue(q);
	for(int i=0;i<(sizeof(a)/sizeof(a[0]));i++)
		enQueue(q,a[i]);
	dispQueue(q);
	destroyQueue(q);
	printf("\n%d",emptyQueue(q));
	
	//实现报数问题
	int i,n=8;
	printf("初始序列：");
	for(i=1;i<=n;i++){
		printf("%d ",i);
	}
	printf("\n");
	number(n);
	
    return 0;
}
