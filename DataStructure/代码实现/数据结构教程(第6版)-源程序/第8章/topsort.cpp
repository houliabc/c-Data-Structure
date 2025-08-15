//拓扑排序算法
#include "graph.cpp"
#define MaxSize 100
//-----栈的基本运算算法--------------- 
typedef int ElemType;
typedef struct 
{	
	ElemType data[MaxSize];
	int top;				//栈指针
} SqStack;					//顺序栈类型
void InitStack(SqStack *&s)
{
	s=(SqStack *)malloc(sizeof(SqStack));
	s->top=-1;
} 
void DestroyStack(SqStack *&s)
{
	free(s);
}
bool StackEmpty(SqStack *s)
{
	return(s->top==-1);
}
bool Push(SqStack *&s,ElemType e)
{
	if (s->top==MaxSize-1)    //栈满的情况，即栈上溢出
		return false;
	s->top++;
	s->data[s->top]=e;
	return true;
}
bool Pop(SqStack *&s,ElemType &e)
{
	if (s->top==-1)		//栈为空的情况，即栈下溢出
		return false;
	e=s->data[s->top];
	s->top--;
	return true;
} 
bool GetTop(SqStack *s,ElemType &e)
{
	if (s->top==-1) 		//栈为空的情况，即栈下溢出
		return false;
	e=s->data[s->top];
	return true;
}
//-------------------------------------

void TopSort(AdjGraph *G)			//拓扑排序算法
{
	SqStack* st;					//定义一个栈(元素为int类型)
	InitStack(st);					//初始化
	int indegree[MAXV];				//定义一个入度数组
	for(int i=0;i<G->n;i++) indegree[i]=0; 
	for (int i=0;i<G->n;i++)			//求所有顶点的入度
	{	ArcNode *p=G->adjlist[i].firstarc;
		while (p!=NULL)
		{
			int w=p->adjvex;			//找到顶点i的邻接点w 
			indegree[w]++;				//顶点w的入度增1
			p=p->nextarc;
		}
	}
	for (int i=0;i<G->n;i++)			//将入度为0的顶点进栈
		if (indegree[i]==0)
			Push(st,i);
	int i;
	while (!StackEmpty(st))				//栈不空循环
	{	Pop(st,i);					//出栈一个顶点i
		printf("%d ",i);			//输出该顶点
		ArcNode* p=G->adjlist[i].firstarc;	//找第一个邻接点
		while (p!=NULL)				//将顶点i的出边邻接点的入度减1
		{	int w=p->adjvex;			//存在边<i,w> 
			indegree[w]--;			//顶点w的入度减1
			if (indegree[w]==0)		//将入度为0的邻接点w进栈
				Push(st,w);
			p=p->nextarc;			//找下一个邻接点
		}
	}
}

int main()
{
	AdjGraph *G;
	int A[MAXV][MAXV]=
	{{0,1,INF,INF,INF,INF},
	{INF,0,1,INF,INF,INF},
	{INF,INF,0,1,INF,INF},
	{INF,INF,INF,0,INF,INF},
	{INF,1,INF,INF,0,1},
	{INF,INF,INF,1,INF,0}};
	int n=6, e=6;
	CreateAdj(G,A,n,e);			//建立《教程》中图8.44的邻接表
	printf("图G的邻接表:\n");
	DispAdj(G);					//输出邻接表G
	printf("拓扑序列:");TopSort(G);printf("\n");
	DestroyAdj(G);				//销毁邻接表
	return 1;
}
