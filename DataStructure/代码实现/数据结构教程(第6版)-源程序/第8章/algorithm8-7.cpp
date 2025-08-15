//【例8.7】的算法:输出图G中从顶点u到v的长度为l的所有简单路径
#include "graph.cpp"
int visited[MAXV];
void PathlenAll(AdjGraph *G,int u,int v,int l,int path[],int d)
{	//d表示path中的路径长度，初始为-1
	int w,i; 	ArcNode *p;
	visited[u]=1;
	d++; path[d]=u;				//路径长度d增1，顶点u加入到路径中
	if (u==v && d==l)			//输出一条路径
	{	printf("  ");
		for (i=0;i<=d;i++)
			printf("%d ",path[i]);
		printf("\n");
		visited[u]=0;				//恢复环境：使该顶点可重新使用
		return; 
	}
	p=G->adjlist[u].firstarc;	//p指向顶点u的第一个邻接点
	while (p!=NULL)
	{	w=p->adjvex;			//w为u的邻接点
		if (visited[w]==0)		//若该顶点未标记访问,则递归访问之
			PathlenAll(G,w,v,l,path,d);
		p=p->nextarc;			//p指向顶点u的下一个邻接点
	}
	visited[u]=0;				//恢复环境：使该顶点可重新使用
}
int main()
{
	AdjGraph *G;
	int A[MAXV][MAXV]={{0,1,0,1,1},{1,0,1,1,0},
			{0,1,0,1,1},{1,1,1,0,1},{1,0,1,1,0}};
	int n=5, e=8;
	CreateAdj(G,A,n,e);			//建立《教程》中图8.1(a)的邻接表
	printf("图G的邻接表:\n");
	DispAdj(G);					//输出邻接表G
	int u=0, v=3,l=2;
	int path[MAXV];
	printf("\n图G中顶点%d到%d的所有长度为%d的简单路径:\n",u,v,l);
	PathlenAll(G,u,v,l,path,-1);
	DestroyAdj(G);				//销毁邻接表
	return 1;
}
/* 
int main()
{ 
	int path[MAXV];
	int u=1,v=4,l=3;
	int n=5, e=8;
	int A[MAXV][MAXV]={
		{0,1,0,1,1},
		{1,0,1,1,0},
		{0,1,0,1,1},
		{1,1,1,0,1},
		{1,0,1,1,0}};
	AdjGraph *G;
	CreateAdj(G,A,n,e);			//建立图8.1(a)的邻接表
	for (int i=0;i<n;i++) 		//visited数组置初值
		visited[i]=0;
	printf("图G:\n");DispAdj(G);//输出邻接表
	printf("从顶点%d到%d的所有长度为%d路径:\n",u,v,l);
	PathAll(G,u,v,l,path,-1);
	printf("\n");
	DestroyAdj(G);				//销毁邻接表
	return 1;
}
*/

