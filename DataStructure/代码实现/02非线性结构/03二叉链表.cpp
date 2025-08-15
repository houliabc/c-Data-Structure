#include <stdio.h>
#include <malloc.h>
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
//思想：先是一个数据，因为一开始是空树，所以p作为根节点；然后会有左括号，表示后面是孩子节点
//，此时把k=1接下来如果有数据则放左边作为左子树；当有逗号‘，’时表示有兄弟；
//当遇到右括号表示该层结束。遇到数据要判断k的值来选择放左子树还是右子树。

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
void destroyBtree(btNode *&b){
	if(b!=NULL){
		free(b->lchild);
		free(b->rchild);
		free(b);
	}
}
btNode *findBtree(btNode *b,elemtype x){
	btNode *p;
	if(b==NULL)
		return NULL;
	else if(x==b->data)
		return b;
	else{
		//这里另p等于左子树的查找结果，如果左子树空
		//则p为NULL，左子树只有一个结点，且等于x
		//则返回该结点，若有子节点则继续递归
		p=findBtree(b->lchild,x);
		if(p!=NULL)
			return p;
		else
		//若左子树不存在则返回右子树的查找结果
			return findBtree(b->rchild,x);
	}
}
btNode * lchildNode(btNode *b){
	return b->lchild;
}
btNode * rchildNode(btNode *b){
	return b->rchild;
}
int btHeight(btNode *b){
	int lchild,rchild;  //分别记录左右子树的高
	if(b==NULL)
		return 0;
	else{  //二叉链表求高度不像孩子链及兄弟链那么复杂
		lchild=btHeight(b->lchild);
		rchild=btHeight(b->rchild);
		//当左子树不存在时，此时高度就是1
		return (lchild>rchild) ? (lchild+1) : (rchild+1 );
	}
}


int main(){
	btNode *b,*p;
	elemtype ch[]="A(B(D(,G)),C(E,F))";
	createBtree(b,ch);
	printf("b:");
	dispBtree(b);
	printf("\nfind:");
	dispBtree(findBtree(b,'F'));
	printf("\nheight:%d",btHeight(b));
	printf("\nleft:");
	dispBtree(lchildNode(b));
	printf("\nright:");
	dispBtree(rchildNode(b));
	return 0;
}
