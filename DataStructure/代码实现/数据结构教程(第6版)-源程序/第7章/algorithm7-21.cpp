#include<stdio.h>
#define MaxSize 100
#define N 10					//问题涉及的人数,人的编号从1到N
#define M 7						//亲戚关系个数
#define Q 3						//询问个数
typedef struct
{
	int rank;					//结点秩
	int parent;					//结点的双亲
} UFSTree;
void Init(UFSTree S[],int n)	//初始化并查集树
{ 
	for (int i=1;i<=n;i++)
	{
		S[i].rank=0;			//秩初始化为0
		S[i].parent=i;			//双亲初始化指向自已
	}
}

int Find(UFSTree S[],int x)					//递归算法:查找x的集合编号
{	if (x!=S[x].parent)						//非根结点
		S[x].parent=Find(S,S[x].parent);	//路径压缩
	return S[x].parent;
}

/*
int Find(UFSTree S[],int x)					//非递归算法:查找x的集合编号
{	int rx=x;
	while (S[rx].parent!=rx)				//找x的根rx
		rx=S[rx].parent;
	int y=x;
	while (y!=rx)							//路径压缩
	{	int tmp=S[y].parent;
		S[y].parent=rx;						//将结点y的双亲置为rx 
		y=tmp;
	}
	return rx;								//返回根
}
*/
void Union(UFSTree S[],int x,int y)		//将x和y所属子集树合并
{ 
	int rx=Find(S,x);
	int ry=Find(S,y);
	if (rx==ry)							//x和y属于同一棵子集树
		return;
	if (S[rx].rank>S[ry].rank)			//rx结点秩大于ry结点秩
		S[ry].parent=rx;				//将结点ry作为结点rx的孩子结点
	else								//rx结点秩小于等于ry结点秩
	{ 
		S[rx].parent=ry;				//将结点rx作为结点ry的孩子结点
		if (S[rx].rank==S[ry].rank)		//秩相同时 
			S[ry].rank++;				//ry结点的秩增1
	}
}
int friends(int R[][2],int m,int n)			//求解算法
{
	UFSTree S[MaxSize];						//定义并查集S 
	Init(S,n);								//初始化 
	for(int i=0;i<m;i++)					//遍历所有朋友对
	{	int a=R[i][0];						//朋友对为(a,b)
		int b=R[i][1];
		Union(S,a,b);						//合并 
	}
	int ans=0;								//表示朋友圈个数
	for(int i=1;i<=n;i++)
	{
		if (S[i].parent==i && S[i].rank>0)	//找到一个朋友圈 
			ans++;
	}
	return ans;
}

int main()
{
	int n=10;
	int m=7;
	int R[M][2]={{2,4},{5,7},{1,3},{8,9},{1,2},{5,6},{2,3}};
	printf("朋友圈个数=%d\n",friends(R,m,n));
	return 0;
}

