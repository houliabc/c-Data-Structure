#include "graph.cpp"	//包含图的基本运算函数
void main()
{
	AdjGraph *G;
	int A[][MAXV]={{0,6,INF,INF,INF},{INF,0,1,INF,INF},{INF,INF,0,3,2},{INF,INF,INF,0,INF},{5,INF,INF,2,0}};
	int n=5,e=6;
	CreateAdj(G,A,n,e);		//创建图的邻接表
	printf("G的邻接表:\n");
	DispAdj(G);
	printf("销毁图G的邻接表\n");
	DestroyAdj(G);
}
