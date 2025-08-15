//【例8.9】的算法:求不带权无向连通图G中从顶点u到顶点v的最短路径长度。
#include "graph.cpp"
#define MaxSize 100
int visited[MAXV];

//解法1 
typedef struct
{	int v;							//顶点编号
	int dist;						//路径长度
} QUEUE1;							//环形队列类型
//---------------------------------------------------------
//--广度优先遍历中使用队列的基本运算算法-------------------
//---------------------------------------------------------
typedef struct 
{	
	QUEUE1 data[MaxSize];
	int front,rear;		//队首和队尾指针
} SqQueue;
void InitQueue(SqQueue *&q)			//初始化 
{	q=(SqQueue *)malloc (sizeof(SqQueue));
	q->front=q->rear=0;
}
void DestroyQueue(SqQueue *&q)		//销毁队列 
{
	free(q);
}
bool QueueEmpty(SqQueue *q)			//判断队空 
{
	return(q->front==q->rear);
}
bool enQueue(SqQueue *&q,QUEUE1 e)		//元素e进队 
{	if ((q->rear+1)%MaxSize==q->front)	//队满上溢出
		return false;
	q->rear=(q->rear+1)%MaxSize;
	q->data[q->rear]=e;
	return true;
}
bool deQueue(SqQueue *&q,QUEUE1 &e)		//出队元素e 
{	if (q->front==q->rear)				//队空下溢出
		return false;
	q->front=(q->front+1)%MaxSize;
	e=q->data[q->front];
	return true;
}
//---------------------------------------------------------

int shortpathlen(AdjGraph *G,int u,int v)		//求顶点u到v的最短逆路径长度
{ 
	ArcNode *p;
	SqQueue *qu;					//定义环形队列(元素类型是QUEUE1)
	InitQueue(qu);					//初始化qu 
	int visited[MAXV];
	for (int i=0;i<G->n;i++) visited[i]=0;	//访问标记置初值0
	QUEUE1 e,e1;
	e.v=u;								//建立顶点u的队列元素e 
	e.dist=0;	
	enQueue(qu,e);						//元素e进队
	visited[u]=1;						//修改顶点u的访问标记 
	while (!QueueEmpty(qu))			//队不空循环
	{	deQueue(qu,e);				//出队元素e
		u=e.v;
		if (u==v)					//找到v时返回对应的路径长度
			return e.dist;
		p=G->adjlist[u].firstarc;			//找u的第一个邻接点
		while (p!=NULL)
		{	int w=p->adjvex;					//邻接点为w 
			if (visited[w]==0)				//若顶点w没有访问过 
			{	e1.v=w;						//建立顶点w的队列元素e1 
				e1.dist=e.dist+1;
				enQueue(qu,e1);				//元素e1进队	
				visited[w]=1;				//修改顶点w的访问标记
			}
			p=p->nextarc;					//找u的下一个邻接点
		}
	}
	DestroyQueue(qu);						//销毁队列
}

int main()
{ 
	int n=5, e=7;
	int A[MAXV][MAXV]={
		{0,1,1,0,0},{0,0,1,0,0},{0,0,0,1,1},
		{0,0,0,0,1},{1,0,0,0,0}};	

	AdjGraph *G;
	CreateAdj(G,A,n,e);			////建立图8.19的邻接表
	printf("图G:\n");DispAdj(G);//输出邻接表
	int u=0,v=4;
	printf("%d->%d的最短路径长度=%d\n",u,v,shortpathlen(G,u,v));
	DestroyAdj(G);				//销毁邻接表
	return 1;
}
