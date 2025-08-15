/*------------------------------------------------------------------------------
	* file:amlgraph.h
	* date:10-12-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:邻接多重表实现无向图/网的基本操作
--------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>


#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

#define MAX_VERTEX_NUM 20

//顶点数据类型
typedef int VertexType;

typedef int Status;

typedef enum {unvisited,isvisited}VisitIf;

//图的种类:无向图/网
typedef enum {UDG,UDN}GraphKind;

typedef struct EBox {
	VisitIf mark;	//访问标记
	int ivex;	//边顶点一
	int jvex;	//边顶点二
	struct EBox *ilink;	//指向依附于顶点一的下一条边,类似于起点相同的一条弧
	struct EBox *jlink;	//指向依附于顶点二的下一条边,类似与终点想同的一条弧
	int weight;	//边的权值
}EBox;


typedef struct VexBox {
	VertexType data;
	EBox *firstarc;	//指向第一条依附于该顶点的边
} VexBox;


typedef struct {
	VexBox adjmulist[MAX_VERTEX_NUM];
	int vexnum;				//图的顶点数
	int arcnum;				//图的边数
	GraphKind kind;			//图的种类
} AMLGraph;



int visited[MAX_VERTEX_NUM];		//访问标志数组

Status CreateGraph(AMLGraph *G);  //创建图

//定位一个顶点值为图中的位置，否则返回-1
int LocateVex(AMLGraph G,VertexType v);


//返回顶点的值
VertexType GetVex(AMLGraph G,int v);

//赋值
Status PutVex(AMLGraph *G,VertexType v,VertexType value ); 

//插入一个顶点
void InsertVex(AMLGraph *G,VertexType v);

//插入一段弧
Status InsertArc(AMLGraph *G,VertexType v,VertexType w);

//返回顶点值为v的下一个邻接顶点的序号，否怎返回-1
int FirstAdjVex(AMLGraph G,VertexType v);

//返回顶点值为v相对于顶点值为w的下一个顶点的序号
int NextAdjVex(AMLGraph G,VertexType v,VertexType w);


//深度优先遍历
void DFSTraverse(AMLGraph G);


//递归实现深度遍历邻接点
void DFS(AMLGraph G,int i);

/*------------------------------------------------------------------------------
	* file:AMLGrpah.c
	* date:10-12-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:邻接多重表实现无向图/网的基本操作
	* more:在实现感觉和十字表有相似之处
--------------------------------------------------------------------------------*/
/*
* @description:创建图(无向图/网)
*/
Status CreateGraph(AMLGraph *G)
 {
	int i,j,k,w;
	VertexType va,vb;
	EBox *p;
	
	//确定图的种类
	printf("please enter the kind of graph:");
	scanf("%d",&(*G).kind);

	//确定图的顶点和边数
	printf("please enter vexnum and arcnum:");
	scanf("%d,%d",&(*G).vexnum,&(*G).arcnum);


	//确定图的各个顶点
	printf("please enter each value of graph:");
	for(i = 0; i < (*G).vexnum ; i++)  {
		scanf("%d,",&(*G).adjmulist[i].data);
		(*G).adjmulist[i].firstarc = NULL;
	}
	
	//确定各个顶点间关系，即建立边
	if((*G).kind == UDG)
		printf("please enter heads and tails:\n");
	else 
		printf("please enter heads,weights and tails\n");

	for(k = 0; k < (*G).arcnum ;k++) {
		if((*G).kind == UDG)
			scanf("%d,%d",&va,&vb);
		else 
			scanf("%d,%d",&va,&vb,&w);
		//放回两顶点在顶点向量数组中位置
		i = LocateVex(*G,va);
		j = LocateVex(*G,vb);
		

		if(i < 0 || j < 0)
			return ERROR;


		p = (EBox *) malloc(sizeof(struct EBox));
		if(!p)
			exit(OVERFLOW);

		///建立新节点
		p->ivex = i;
		p->jvex = j;
		p->mark = unvisited;
		//注意每次插入新节点都是在链表的表头进行
		p->ilink = (*G).adjmulist[i].firstarc;
		p->jlink = (*G).adjmulist[j].firstarc;
		(*G).adjmulist[i].firstarc = p;
		(*G).adjmulist[j].firstarc = p;
		if((*G).kind == UDN)
			p->weight = w;
	}
	return OK;
}


/*
* @description:定位一个顶点值在图中的位置,无则返回-1
*/

int LocateVex(AMLGraph G,VertexType v) {
	int i;

	for(i = 0; i < G.vexnum ; i++)
		if(G.adjmulist[i].data == v)
			return i;

	return -1;
}


/*
* @description:返回顶点v的值
*/
VertexType GetVex(AMLGraph G,int v) {
	if(v > G.vexnum || v < 0)
		exit(ERROR);
	
	return G.adjmulist[v].data;
}


/*
* @description:对顶点值为v的顶点赋值为value
*/
Status PutVex(AMLGraph *G,VertexType v,VertexType value) {
	int i;

	i = LocateVex(*G,v);

	if(i < 0)
		return ERROR;

	(*G).adjmulist[i].data = value;

	return OK;
}


/*
* @description:返回顶点值为v的下一个邻接点的序号，否则返回-1
*/
int FirstAdjVex(AMLGraph G,VertexType v) {
	int i;
	EBox *p;

	i = LocateVex(G,v);

	if(i < 0)
		return -1;
	
	p = G.adjmulist[i].firstarc;

	if(p)
		if(p->ivex == i)
			return p->jvex;
		//要注意这种情况的理解
		else
			return p->ivex;

	else 
		return -1;

}


/*
* @description:返回顶点值为v相对于顶点值为w的下一个邻接顶点的序号
*/
int NextAdjVex(AMLGraph G,VertexType v,VertexType w) {
	int i,j;
	EBox *p;

	i = LocateVex(G,v);
	j = LocateVex(G,w);

	p = G.adjmulist[i].firstarc;	//不管怎样先找到入口
	
	while(p)
		if(p->ivex == i && p->jvex != j ) //情况1
			p = p->ilink; 
		else if(p->jvex == i && p->ivex != j) //情况2
			p = p->jlink;
		else
			break;
	
	//情况1
	if(p && p->ivex == i && p->jvex == j) {
		p = p->ilink;

		if(p && p->ivex == i)
			return p->jvex;
		else if(p && p->jvex == i)
			return p->ivex;
	}

	//情况2
	if(p && p->ivex == j && p->jvex == i) {
		p = p->jlink;

		if(p && p->ivex == i)
			return p->jvex;
		else if(p && p->jvex == i)
			return p->ivex;
	}


	return -1;
}


/*
* @description:插入一个顶点
*/
void InsertVex(AMLGraph *G,VertexType v) {
	int i;

	i = (*G).vexnum;

	(*G).adjmulist[i].data = v;
	(*G).adjmulist[i].firstarc = NULL;
	(*G).vexnum++;
}


/*
* @description:插入一段弧
*/
Status InsertArc(AMLGraph *G,VertexType v,VertexType w)
{
        int i,j;
        EBox *p;
        //放回两顶点在顶点向量数组中位置
	i = LocateVex(*G,v);
	j = LocateVex(*G,w);


	if(i < 0 || j < 0)
		return ERROR;

	p = (EBox *) malloc(sizeof(struct EBox));

	if(!p)
		exit(OVERFLOW);

	///建立新节点
	p->ivex = i;
	p->jvex = j;
	p->mark = unvisited;
	//注意每次插入新节点都是在链表的表头进行
	p->ilink = (*G).adjmulist[i].firstarc;
	p->jlink = (*G).adjmulist[j].firstarc;
	(*G).adjmulist[i].firstarc = p;
	(*G).adjmulist[j].firstarc = p;

	if((*G).kind == UDN) {
		printf("please enter the weight of the arc:");
		scanf("%d",&p->weight);
	}


	return OK;

}



/*
 * @description:深度优先遍历图
 */
void DFSTraverse(AMLGraph G)
{
	int i;

	for(i = 0;i < G.vexnum ; i++) 
		visited[i] = FALSE;
	//循环是为保证每个顶点都能被访问到
	for(i = 0; i < G.vexnum; i++) 
		if(!visited[i])
			DFS(G,i);

}


/*
 * @description:递归实现深度优先遍历
 */
void DFS(AMLGraph G,int i)
{
	int j;
	EBox *p;

	printf("%d",G.adjmulist[i].data);
	visited[i] = TRUE;

	p = G.adjmulist[i].firstarc;

	while(p) {
		j = p->ivex == i ? p->jvex : p->ivex;
		if(!visited[j])
			DFS(G,j);

		p = p->ivex == i ? p->ilink : p->jlink ;
	}
}

void DispGraph(AMLGraph *G)
{
	EBox *p;
	for (int i=0;i<G->vexnum;i++)
	{
		printf("顶点%d[%d]): ",i,G->adjmulist[i].firstarc);
		p=G->adjmulist[i].firstarc;
		while (p!=NULL)
		{
			printf("%d[%d,%d,%d,%d]  ",p,p->ivex,p->ilink,p->jvex,p->jlink);
			p=p->ilink;
		}
		printf("\n");
	}
}

void main() 
{
	AMLGraph G;

	CreateGraph(&G);
	DispGraph(&G);

	//DFSTraverse(G);
	printf("\n");

	/*	
	测试用例结果：
	please enter the kind of graph:0
	please enter vexnum and arcnum:8,8
	please enter each value of graph:1,2,3,4,5,6,7,8
	please enter heads and tails:
	1,2
	1,3
	2,4
	2,5
	3,6
	3,7
	4,8
	5,8
	13762584

	*/
}