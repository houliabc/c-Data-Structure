//改进的Kruskal算法
#include "graph.cpp"
#define MaxSize 100
//-----并查集算法开始---------------------------------------
typedef struct 
{	
	int u;			//边的起始顶点
    int v;			//边的终止顶点
    int w;			//边的权值
} Edge;
typedef struct
{	
	int rank;						//结点对应秩
	int parent;						//结点对应双亲下标
} UFSTree;							//并查集树结点类型
void Init(UFSTree S[],int n)	//初始化并查集树
{ 
	int i;
	for (i=0;i<n;i++)				//顶点编号从0到n-1
	{
		S[i].rank=0;				//秩初始化为0
		S[i].parent=i;				//双亲初始化指向自已
	}
}
int Find(UFSTree S[],int x)				//在x所在子树中查找集合编号
{	if (x!=S[x].parent)					//双亲不是自已
		S[x].parent=Find(S,S[x].parent);	//路径压缩
	return S[x].parent;
}
void Union(UFSTree S[],int x,int y)	//将x和y所在的子树合并
{ 
	int rx=Find(S,x);
	int ry=Find(S,y);
	if (S[rx].rank>S[ry].rank)
		S[ry].parent=rx;
	else
	{ 
		S[rx].parent=ry;
		if (S[rx].rank==S[ry].rank)
			S[ry].rank++;
	}
}
//-----并查集算法结束---------------------------------------

//-----堆排序算法开始---------------------------------------
void sift(Edge E[],int low,int high)	//筛选算法
{
	int i=low,j=2*i;     				//E[j]是E[i]的左孩子
	Edge temp=E[i];
	while (j<=high) 
	{
		if (j<high && E[j].w<E[j+1].w) 	//若右孩子较大,把j指向右孩子
			j++;    					//f变为2i+1
		if (temp.w<E[j].w) 
		{
			E[i]=E[j];              	//将E[j]调整到双亲结点位置上
			i=j;                    	//修改i和j值,以便继续向下筛选
			j=2*i;
		}
		else break;                 	//筛选结束
	}
	E[i]=temp;                      	//被筛选结点的值放入最终位置
}
void HeapSort(Edge E[],int n)
{
	int i;
	Edge temp;
	for (i=n/2;i>=1;i--)  	//循环建立初始堆
		sift(E,i,n); 
	for (i=n;i>=2;i--)   	//进行n-1次循环,完成推排序
	{
		temp=E[1];        	//将第一个元素同当前区间内R[1]对换
		E[1]=E[i];
		E[i]=temp;
		sift(E,1,i-1);     	//筛选R[1]结点,得到i-1个结点的堆
	}
}
//-----堆排序算法结束---------------------------------------

void Kruskal(MatGraph g)
{
	int i,j,k,u1,v1,sn1,sn2;
	UFSTree S[MaxSize];
	Edge E[MaxSize];
	k=1;					//e数组的下标从1开始计
	for (i=0;i<g.n;i++)		//由g产生的边集e
		for (j=0;j<=i;j++)
			if (g.edges[i][j]!=0 && g.edges[i][j]!=INF)
			{
				E[k].u=i;E[k].v=j;E[k].w=g.edges[i][j];
				k++;
			}
	HeapSort(E,g.e);		//采用堆排序对E数组按权值递增排序
	Init(S,g.n);		//初始化并查集树t
	k=1;               		//k表示当前构造生成树的第几条边,初值为1
	j=1;               		//E中边的下标,初值为1
	while (k<g.n)       	//生成的边数小于n时循环
	{	
		u1=E[j].u;
		v1=E[j].v;			//取一条边的头尾顶点编号u1和v2
		sn1=Find(S,u1);
		sn2=Find(S,v1); //分别得到两个顶点所属的集合编号
		if (sn1!=sn2)     	//两顶点属于不同的集合,该边是最小生成树的一条边
		{	
			printf("  (%d,%d):%d\n",u1,v1,E[j].w);
			k++;			//生成边数增1
			Union(S,u1,v1);	//将u1和v1两个顶点合并
		}
		j++;   				//扫描下一条边
	}
}

int main()
{
	MatGraph g;
	int A[MAXV][MAXV]={
		{0,28,INF,INF,INF,10,INF},
		{28,0,16,INF,INF,INF,14},
		{INF,16,0,12,INF,INF,INF},
		{INF,INF,12,0,22,INF,18},
		{INF,INF,INF,22,0,25,24},
		{10,INF,INF,INF,25,0,INF},
		{INF,14,INF,18,24,INF,0}};
	int n=7, e=9;
	CreateMat(g,A,n,e);			//建立《教程》中图8.27的邻接矩阵
	printf("图G的邻接矩阵:\n");
	DispMat(g);					//输出邻接矩阵
	printf("Kruskal算法结果\n");
	Kruskal(g);
	return 1;
}
