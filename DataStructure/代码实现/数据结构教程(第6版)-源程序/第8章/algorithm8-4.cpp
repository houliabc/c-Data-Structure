//【例8.4】的算法:判断图G中从顶点u到v是否存在简单路径
#include "graph.cpp"
#include<string.h>
int visited[MAXV];					//全局数组
bool ExistPath(AdjGraph *G,int u,int v)
{
	int w; ArcNode *p;
	visited[u]=1;					//置已访问标记
	if (u==v)						//找到了一条路径
		return true;
	p=G->adjlist[u].firstarc;		//p指向顶点u的第一个邻接点
	while (p!=NULL)
	{	w=p->adjvex;				//w为顶点u的邻接点
		if (visited[w]==0)			//若w顶点未访问
		{
			if (ExistPath(G,w,v))	//若从顶点w出发找到到达v的路径 
				return true;		//返回true 
		}
		p=p->nextarc;				//p指向顶点u的下一个邻接点
	}
	return false;					//不存在u到v的路径，返回false 
}

int main()
{
	AdjGraph *G;
	int A[MAXV][MAXV]={{0,8,INF,5,INF},{INF,0,3,INF,INF},
			{INF,INF,0,INF,6},{INF,INF,9,0,INF},{INF,INF,INF,INF,0}};
	int n=5, e=5;
	CreateAdj(G,A,n,e);			//建立《教程》中图8.4的邻接表
	printf("图G的邻接表:\n");
	DispAdj(G);					//输出邻接表G
	int u=0, v=4;
	memset(visited,0,sizeof(visited));
	bool has=ExistPath(G,u,v);
	printf("图G中顶点%d到顶点%d%s路径\n\n",u,v,(has?"有":"没有"));
	u=4; v=0;
	memset(visited,0,sizeof(visited));
	has=ExistPath(G,u,v);
	printf("图G中顶点%d到顶点%d%s路径\n\n",u,v,(has?"有":"没有"));
	DestroyAdj(G);				//销毁邻接表
	return 1;
}
