//【例8.10】的算法
#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
#define M 20
#define N 20 
int dx[]={-1,0,1,0};                                                	//水平方向偏移量
int dy[]={0,1,0,-1};                                                	//垂直方向偏移量
typedef struct                                                             	
{   int x,y;                                                          	//记录(x,y)位置
} QNode; 					//队列元素类型
//---------------------------------------------------------
//--广度优先遍历中使用队列的基本运算算法-------------------
//---------------------------------------------------------
typedef struct 
{	
	QNode data[MaxSize];
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
bool enQueue(SqQueue *&q,QNode e)		//元素e进队 
{	if ((q->rear+1)%MaxSize==q->front)	//队满上溢出
		return false;
	q->rear=(q->rear+1)%MaxSize;
	q->data[q->rear]=e;
	return true;
}
bool deQueue(SqQueue *&q,QNode &e)		//出队元素e 
{	if (q->front==q->rear)				//队空下溢出
		return false;
	q->front=(q->front+1)%MaxSize;
	e=q->data[q->front];
	return true;
}
int Count(SqQueue *&q)					//求队列中的元素个数 
{
	return (q->rear-q->front+MaxSize)%MaxSize;
}
int s=0;
SqQueue *qu;							//定义环形队列(元素类型是Qnode)
int visited[M][N];                     	//访问标记数组
void dfs(int A[M][N],int m,int n,int x,int y)   	//DFS算法
{	visited[x][y]=1;
 	QNode e;
    	e.x=x; e.y=y;
    	printf("[%d,%d]进队\n",x,y); 
    	enQueue(qu,e);
    	for (int di=0;di<4;di++)
        {	int nx=x+dx[di];
           	int ny=y+dy[di];
           	if (nx>=0 && nx<m && ny>=0 && ny<n && !visited[nx][ny] && A[nx][ny]==1)
               	dfs(A,m,n,nx,ny);
        }
}
int bfs(int A[M][N],int m,int n)                         //BFS算法
{	int ans=0;
	QNode e,e1;
    while (!QueueEmpty(qu))
	{	int cnt=Count(qu);          					//求队列中元素个数cnt
        for (int i=0;i<cnt;i++)             			//处理一层的元素
        {	deQueue(qu,e);       						//出队元素e
            int x=e.x;
            int y=e.y;
            printf("[%d,%d]出队\n",x,y); 
            for (int di=0;di<4;di++)
            {	int nx=x+dx[di];
               	int ny=y+dy[di];
               	if (nx>=0 && nx<m && ny>=0 && ny<n && visited[nx][ny]==0)
                {	if (A[nx][ny]==1)
                	{
                		printf("找到目标[%d,%d]\n",nx,ny); 
                    	return ans;
                    }
                    e1.x=nx; e1.y=ny;
					enQueue(qu,e1);       				//(nx,ny)进队
			    	printf("(%d)[%d,%d]进队\n",++s,nx,ny); 
                    visited[nx][ny]=1;
                }
            }
        }
        ans++;
    }
    return ans;
}

int shortestdist(int A[M][N],int m,int n)			//求解算法 
{
	InitQueue(qu);									//初始化队列qu 
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
			visited[i][j]=0;
	bool find=false;
    int x,y;
    for (int i=0;i<m;i++)                           //找到任意一个陆地(x,y)
    {	for (int j=0;j<n;j++)
        {	if(A[i][j]==1 &&  !find)
            {	find=true;
                x=i; y=j;
                break;
            }
        }
        if (find) break;							//找到任意一个陆地后退出循环 
    }
    dfs(A,m,n,x,y);
    int ans=bfs(A,m,n);
	DestroyQueue(qu);						//销毁队列
	return ans;
}
int main()
{
	int A[M][N]={{1,1,0,0,0},{1,0,0,0,0},{0,0,1,0,0},{0,0,1,1,1},{0,0,0,1,0}};
	printf("ans=%d\n",shortestdist(A,5,5));
	return 1;
}
	
