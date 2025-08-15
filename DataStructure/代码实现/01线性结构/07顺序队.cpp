#include <stdio.h>
#include <stdlib.h>
#define Maxsize 100

typedef int elemtype;
typedef struct{
	elemtype data[Maxsize];
	int rear,front;  //头指针和尾指针的下标
}SqQueue;


void initQueue(SqQueue *&q){
	q=(SqQueue *)malloc(sizeof(SqQueue));
	q->rear=q->front=-1;
}
void destroyQueue(SqQueue *&q){
	free(q);
}
bool emptyQueue(SqQueue *q){
	return q->front==q->rear;
}
bool enQueue(SqQueue *&q,elemtype e){
	//先判断是否队满
	if(q->rear==Maxsize-1)
		return false;
	q->rear++;
	q->data[q->rear]=e;
	//等价于q->data[++q->rear]=e
	return true;
}
bool deQueue(SqQueue *&q,elemtype &e){
	//先判断队是否为空
	if(q->rear==q->front)
		return false;
	e=q->data[++q->front];
//注意区别：顺序队入队出队都是先动指针后动元素
//而栈是入栈先动指针，出栈先动元素
	//q->front++;
	//e=q->data[q->front];
	return true;
}
void dispQueue(SqQueue *q){
	while(q->rear!=q->front){
		q->front++; 
		printf("%d,",q->data[q->front]);
	}
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
    return 0;
}
