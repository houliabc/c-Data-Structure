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
//二叉链表实现创、删、查找结点、高度，孩子结点、输出。利用孩子链来实现
void createBtree(btNode *&b,char *str){
//思想：先是一个数据，因为一开始是空树，所以p作为根节点；然后会有左括号，表示后面是孩子节点
//，此时把k=1接下来如果有数据则放左边作为左子树；当有逗号‘，’时表示有兄弟；
//当遇到右括号表示该层结束。遇到数据要判断k的值来选择放左子树还是右子树。
	int i=0,k,top=-1;
	btNode *p,*stack[Maxsize];  //用btnode定义都是指针
	b=NULL;
	while(str[i]!='\0'){
		switch (str[i]) {
			case '(':
				top++;
				stack[top]=p;
				k=1;
				break;
			case ',':
				k=2;
				break;
			case ')':
				top--;
				break;
			default:
				p=(btNode *)malloc(sizeof(btNode));
				p->data=str[i];
				p->lchild=p->rchild=NULL;
				if(b==NULL)
					b=p;
				else{
					
					
					if(k==1){
						stack[top]->lchild=p;
					}
					else if (k==2){
						stack[top]->rchild=p;
					}
				}
		}
		i++;
	}
}
//只有删除和创建二叉链表不用递归
void destroyBtree(btNode *&b){
	free(b->lchild);
	free(b->rchild);
	free(b);
}
void dispBtree(btNode *b){
	if(b!=NULL){
		printf("%c",b->data);
		if(b->lchild!=NULL || b->rchild!=NULL){
			printf("(");
			dispBtree(b->lchild);
			if(b->rchild!=NULL){
				printf(",");
			}
			dispBtree(b->rchild);
			printf(")");
		}
	}
}
//左子树为空则find右子树
btNode *findBtree(btNode *b ,elemtype x){
	btNode *p;
	if(b==NULL){
		return NULL;
	}
	else if(b->data==x)
		return b;
	else{
		p=findBtree(b->lchild,x);
		if (p==NULL)
			p=findBtree(b->rchild,x);	
		return p;
	}
}
//要有返回0的
int BtreeHeight(btNode *b){
	int lchild,rchild;
	if(b==NULL)
		return 0;
	lchild=BtreeHeight(b->lchild);
	rchild=BtreeHeight(b->rchild);
	return (lchild>rchild) ? lchild+1 : rchild+1;
}
btNode *findleft(btNode *b){
	return b->lchild;
}
btNode *findright(btNode *b){
	return b->rchild;
}

int main(){
	btNode *b;
	elemtype ch[]="A(B(D(,G)),C(E,F))";
	createBtree(b,ch);
	printf("b:");
	dispBtree(b);
	printf("\nfind:");
	dispBtree(findBtree(b,'E'));
	printf("\nheight:%d",BtreeHeight(b));
	printf("\nleft:");
	dispBtree(findleft(b));
	printf("\nright:");
	dispBtree(findright(b));
	return 0;
}
