#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define  Maxsize 100

typedef char elemtype;
//二叉链表存储定义及各操作的实现
typedef struct node{
	elemtype data;
	struct node *lchild;
	struct node *rchild;
}btNode;

//二叉树基本思想实现
void createBtree(btNode *&b,char *str){
	btNode *st[Maxsize],*p;  //st数组为顺序栈
	int top=-1,k,j=0;    //top为栈顶指针
	char ch;
	b=NULL;   //初始时二叉链为空
	ch=str[j];
	while(ch!='\0'){
		switch (ch) {
			case '(':  //处理左孩子结点
				top++;   //入栈先加后放数据
				st[top]=p;
				k=1;
				break;
			case ')':   //栈顶结点的子树处理完毕
				top--;   //这里直接不出栈了，另指针减1，如果之后还有数据入栈会替代原本存在的
				break;
			case ',':
				k=2;  //开始处理右孩子结点
				break;
			default:
				p=(btNode *)malloc(sizeof(btNode));
				p->data=ch;
				p->lchild=p->rchild=NULL;   //指针初始化
				if(b==NULL)
					b=p;   //若是空树，则p作为根节点
				else{
					switch(k){
						case 1:   //新建结点作为栈顶结点的左孩子
							st[top]->lchild=p;
							break;
						case 2:   //新建结点作为栈顶结点的右孩子
							st[top]->rchild=p;
							break;
					}
				}
		}
		j++;
		ch=str[j];
	}
}
void dispBtree(btNode *b){
	if(b!=NULL){
		printf("%c",b->data);
		if(b->lchild!=NULL || b->rchild!=NULL){
			printf("(");
			dispBtree(b->lchild);  //递归左子树
			if(b->rchild!=NULL)
				printf(",");   //如果有右子树，则加逗号
			dispBtree(b->rchild);  //递归右子树
			printf(")");
		}
	}
}



//7.11用二叉链结构存储，计算一颗二叉树的所有结点个数
int countBtree(btNode *b){
	if(b==NULL)
		return 0;
	else{
		return countBtree(b->lchild)+countBtree(b->rchild)+1;
	}
}
//7.12输出一颗二叉树所有叶子结点
//我的
void dispZeroNode(btNode *b){
	if(b->lchild==NULL && b->rchild==NULL)
		dispBtree(b);
	else{
		if (b->lchild!=NULL)
			dispZeroNode(b->lchild);
		if (b->rchild!=NULL)
			dispZeroNode(b->rchild);
	}
}
//书的
void displeaf(btNode *b){
	if(b!=NULL){
		if(b->lchild==NULL && b->rchild==NULL)
			printf("%c,",b->data);
		displeaf(b->lchild);
		displeaf(b->rchild);
	}
}


//7.13求二叉树b中结点值为x的结点的层次，编写一个完整的程序，对于用户输入的任何结点值都输出其层次
//我的
int level(btNode *b,elemtype x,int h){
	if(b==NULL)   //需要把NULL放第一个判断先
		return 0;
	else if(b->data==x)
		return h;  //找到了则返回当前的高度
	else{
		if(level(b->lchild,x,h+1)!=0)  //表示左子树中找到了
			return level(b->lchild,x,h+1);  //＋1是还要算上根结点，否则只是到达左子树的高度
		else    //左子树没有，那就只能去右子树找了
			return level(b->rchild,x,h+1);
			
//一开始的错误写法
//		if(b->lchild!=NULL)    //这只能证明有左子树，最后的左子树的叶子结点还是会返回0的
//			return level(b->lchild,x,h+1);
//		if(b->rchild!=NULL)    //这只能证明有右子树，最后的左子树的叶子结点还是会返回0的
//			return level(b->rchild,x,h+1);
	}
}
//书上的7.13
int Level(btNode *b,elemtype x,int h)	//h置初值1
{	int l;
	if (b==NULL)
		return(0);
	else if (b->data==x)
		return(h);
	else
	{	l=Level(b->lchild,x,h+1);	//在左子树中查找
		if (l!=0)  //表示在该左子树找到了
			return(l);
		else						//在左子树中未找到,再在右子树中查找
			return(Level(b->rchild,x,h+1));
	}
}

//7.14求二叉树中第k层的结点个数
void BtreeNodeNum(btNode *b,int h,int k,int &n){
	if(!b)
		return;
	if(h==k)
		n++;
	else if(h<k){
		BtreeNodeNum(b->lchild,h+1,k,n);
		BtreeNodeNum(b->rchild,h+1,k,n);
	}
}
//7.15判断两颗二叉树是否相似  p231
//7.16设计一个输出值为x的结点的所有祖先的算法
//7.17  p239
//7.18  p241
//7.19  p246


int main(){
	btNode *b;
	int n=0,k=3;
	elemtype ch[]="A(B(D(,G)),C(E,F))",x;
	createBtree(b,ch);
	printf("b:");
	dispBtree(b);
	printf("\nb的结点个数为:%d",countBtree(b));
	printf("\n我的：叶子有:");
	dispZeroNode(b);
	printf("\n书的：叶子有:");
	displeaf(b);
	
	
//	while(1){
//		printf("\n请输入要求高度的结点（0退出）：");
//		x=getchar();
//		fflush(stdin);  //清除输入数据时的回车符
//		if(x=='0')
//			break;
//		printf("\n我的：值为%c的结点高度为:%d",x,level(b,x,1));
//		printf("\n书：值为%c的结点高度为:%d",x,Level(b,x,1));
//		printf("\n-----------------------------------");
//	}
	BtreeNodeNum(b,1,k,n);
	printf("\n----------------------------\n第%d层有%d个结点",k,n);
	return 0;
}
