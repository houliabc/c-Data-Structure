#include <stdio.h>
#include <stdlib.h>
#define Maxsize 100
#define Maxsons 100 //为最多孩子结点个数，或成为树的度

typedef int elemtype;
//双亲顺序存储结构
typedef struct{
	elemtype data;  //结点的值
	int parent;  //双亲的位置
}ptree[Maxsize];  //为双亲存储结构类型
//孩子链式存储结构
typedef struct node{
	elemtype data;
	struct node *sons[Maxsons];  //指向孩子结点，表示每个结点最多的度数
}TSonNode;
//孩子兄弟链存储结构
typedef struct tnode{
	elemtype data;
	struct tnode *hp;  //指向兄弟
	struct tnode *vp;  //指向孩子结点
}TsbNode;

TSonNode *CreateTree(char *str)			//由str建立孩子链存储结构
{	struct{	
		TSonNode *nodep;				//节点指针
		int num;						//孩子个数
	} St[Maxsize];						//定义顺序栈
	int top=-1;							//栈顶指针
	int i=0,j; 
	char ch=str[i];
	TSonNode *t=NULL,*p;
	while (ch!='\0')
	{	switch(ch)
		{
		case '(': 
			top++; 
			St[top].nodep=p;
			St[top].num=0;				//当前节点*p进栈
			break;
		case ')':
			top--;	
			break;			//退栈
		case ',':
			St[top].num++; 
			break;	//栈顶节点增加一个孩子
		default:
			p=(TSonNode *)malloc(sizeof(TSonNode));
			p->data=ch;					//建立一个节点p存放ch
			for (j=0;j<Maxsons;j++)		//所有孩子指针置为NULL
				p->sons[j]=NULL;
			if (t==NULL)				//原为空树
				t=p;
			else						//将其作为栈顶节点的一个孩子
				St[top].nodep->sons[St[top].num]=p;
			break;
		}
		i++;
		ch=str[i];
	}
	return t;
}
void DispTree(TSonNode *t)				//输出孩子链存储结构
{	int i;
	if (t!=NULL)
	{	printf("%c",t->data);
		if (t->sons[0]!=NULL)			//t节点至少有一个孩子
		{	printf("(");				//输出一个左括号
			for (i=0;i<Maxsons;i++)
			{	DispTree(t->sons[i]);
				if (t->sons[i+1]!=NULL)	//如果有下一个孩子
					printf(",");		//输出一个','
				else					//如果没有下一个孩子
					break;				//退出循环
			}
			printf(")");				//输出一个右括号
		}
	}
}
void DestroryTree(TSonNode *&t)			//销毁树t
{	int i;
	if (t!=NULL)
	{	for (i=0;i<Maxsons;i++)
		{	if (t->sons[i]!=NULL)		//有子树
				DestroryTree(t->sons[i]);//销毁该子树
			else						//再没有子树
				break;					//退出循环
		}
		free(t);						//释放根节点
	}
}
//例题：以孩子链存储结构，设计一个求树的高度t的递归算法
int treeheight(TSonNode * t){
	TSonNode *p;
	int i,h,maxh=0;
	if(t==NULL)
		return 0;
	for(i=0;i<Maxsons;i++){    //p指向t的第i+1个孩子结点
		p=t->sons[i];
		if(p!=NULL){
			h=treeheight(p);  //求对应子树的高度
			if(maxh<h)
				maxh=h;
		}
	}
	return (maxh+1);  //返回树的高度
}
//以孩子兄弟链作为树的存储结构设计一个求树t高度的递归算法
int treeheight2(TsbNode *t){
	TsbNode *p;
	int h,maxh=0;
	if(t==NULL)
		return 0;
	p=t->vp;   //p指向第1个孩子结点
	while(p!=NULL){
		h=treeheight2(p);
		if(maxh<h)
			maxh=h;
		p=p->hp;    //继续处理其他兄弟，即其他子树
	}
	return(maxh+1);
	
}

int main(){
	TSonNode *t;
	t=CreateTree("A(B,C(E,F,G),D)");
	printf("t:"); DispTree(t);
	printf("\n树t的最大高度:%d\n",treeheight(t));
	DestroryTree(t);
	
	return 0;
}
