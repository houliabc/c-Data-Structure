#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define INF 32767				//定义∞
#define	MAXV 100				//最大顶点个数
#define MaxSize 100
typedef struct ANode
{	int adjvex;					//该边的邻接点编号
	struct ANode *nextarc;		//指向下一条边的指针
} ArcNode;						//边结点类型
typedef struct Vnode
{
	ArcNode *firstarc;			//指向第一条边
} VNode;						//邻接表头结点类型
typedef struct 
{	VNode adjlist[MAXV];		//邻接表头结点数组
	int n,e;					//图中顶点数n和边数e
} AdjGraph;						//完整的图邻接表类型
void CreateAdj(AdjGraph *&G,int A[MAXV][MAXV],int n,int e) //创建图的邻接表
{
	int i,j;
	ArcNode *p;
	G=(AdjGraph *)malloc(sizeof(AdjGraph));
	for (i=0;i<n;i++)								//给邻接表中所有头结点的指针域置初值
		G->adjlist[i].firstarc=NULL;
	for (i=0;i<n;i++)								//检查邻接矩阵中每个元素
		for (j=n-1;j>=0;j--)
			if (A[i][j]!=0 && A[i][j]!=INF)			//存在一条边
			{	p=(ArcNode *)malloc(sizeof(ArcNode));	//创建一个结点p
				p->adjvex=j;
				p->nextarc=G->adjlist[i].firstarc;	//采用头插法插入结点p
				G->adjlist[i].firstarc=p;
			}
	G->n=n; G->e=n;
}
void DispAdj(AdjGraph *G)	//输出邻接表G
{
	int i;
	ArcNode *p;
	for (i=0;i<G->n;i++)
	{
		p=G->adjlist[i].firstarc;
		printf("%3d: ",i);
		while (p!=NULL)
		{
			printf("%3d→",p->adjvex);
			p=p->nextarc;
		}
		printf("∧\n");
	}
}
void DestroyAdj(AdjGraph *&G)		//销毁图的邻接表
{	int i;
	ArcNode *pre,*p;
	for (i=0;i<G->n;i++)			//扫描所有的单链表
	{	pre=G->adjlist[i].firstarc;	//p指向第i个单链表的首结点
		if (pre!=NULL)
		{	p=pre->nextarc;
			while (p!=NULL)			//释放第i个单链表的所有边结点
			{	free(pre);
				pre=p; p=p->nextarc;
			}
			free(pre);
		}
	}
	free(G);						//释放头结点数组
}
//--广度优先遍历中使用队列的基本运算算法-------------------
//---------------------------------------------------------
typedef int ElemType;
typedef struct 
{	
	ElemType data[MaxSize];
	int front,rear;		//队首和队尾指针
} SqQueue;
void InitQueue(SqQueue *&q)
{	q=(SqQueue *)malloc (sizeof(SqQueue));
	q->front=q->rear=0;
}
void DestroyQueue(SqQueue *&q)
{
	free(q);
}
bool QueueEmpty(SqQueue *q)
{
	return(q->front==q->rear);
}
bool enQueue(SqQueue *&q,ElemType e)
{	if ((q->rear+1)%MaxSize==q->front)	//队满上溢出
		return false;
	q->rear=(q->rear+1)%MaxSize;
	q->data[q->rear]=e;
	return true;
}
bool deQueue(SqQueue *&q,ElemType &e)
{	if (q->front==q->rear)				//队空下溢出
		return false;
	q->front=(q->front+1)%MaxSize;
	e=q->data[q->front];
	return true;
}
int Count(SqQueue *q)
{
	return (q->rear-q->front+MaxSize)%MaxSize;
}

int BFS(AdjGraph* G,int u,int& v)		//分层次的广度优先遍历 
{
	int visited[MAXV];
	memset(visited,0,sizeof(visited));
	SqQueue *qu;				//定义一个队列
	InitQueue(qu); 
	int ans,level=0;
	ArcNode *p;
	visited[u]=1;					//访问起始顶点u 
	enQueue(qu,u);					//起始顶点u进队
	while(!QueueEmpty(qu))			//队不空时循环
	{
		int cnt=Count(qu);					//求队中元素个数cnt 
		for(int i=0;i<cnt;i++)				//循环cnt处理当前层次的所有顶点 
		{	deQueue(qu,u);					//出队顶点u
			v=u, ans=level;					//保存最后出队的顶点和层次 
			p=G->adjlist[u].firstarc;		//p指向顶点u的第一个邻接点
			while (p!=NULL)
			{	int w=p->adjvex;				//w为顶点u的邻接点
				if (visited[w]==0)			//若w未访问,则递归访问之
				{
					visited[w]=1;			//访问顶点w 
					enQueue(qu,w);			//顶点w进队 
				}
				p=p->nextarc;				//找u的下一个邻接点
			}
		}
		level++;
	}
	return ans;
}
int solve(AdjGraph* G)
{
	int u=0,v;
	BFS(G,u,v);						//从顶点0出发BFS求最远的顶点v 
	return BFS(G,v,u);				//再从顶点v出发搜索答案 
}
int main()
{ 
	int n=6, e=7;
	int A[MAXV][MAXV]={
		{0,1,1,0,0,0},{1,0,0,1,0,0},{1,0,0,0,1,0},
		{0,1,0,0,0,0},{0,0,1,0,0,1},{0,0,0,0,1,0}};	

	AdjGraph *G;
	CreateAdj(G,A,n,e);			////建立图8.19的邻接表
	printf("图G:\n");DispAdj(G);//输出邻接表

	int v;
	int ans=solve(G);
	printf("ans=%d\n",ans);
	DestroyAdj(G);				//销毁邻接表
	return 1;
}
