#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define  Maxsize 100

typedef char elemtype;
//二叉链表存储定义及各操作的实现
typedef struct node{
	elemtype data;
	int ltag,rtag;  //0表示是左孩子右兄弟，1表示是左前驱右后继
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

//二叉树的线索化（边遍历边判断左右指针是否为空，如果为空就线索化）
//中序线索化
btNode *pre;
void inthread(btNode *&p){   //一开始传递进来b根结点，对每一个结点线索化就是添加前驱后继，所以要用引用
	if(p){
		inthread(p->lchild);  //按照中序序列，先对左子树线索化
		if(p->lchild==NULL){  //左指针为空，则指向其前驱
			p->lchild=pre;   
			p->ltag=1;
		}
		else
			p->ltag=0; 
		if(pre->rchild==NULL){  //右指针为空，则指向其后继
			pre->rchild=p;
			pre->rtag=1;
		}
		else
			pre->rtag=0;
		pre=p;
		inthread(p->rchild);  //对右子树线索化
	}
}
btNode *createThread(btNode *b){   //创建中序线索二叉树
	btNode *root;  //创建头结点
	root=(btNode *)malloc(sizeof(btNode));
	root->ltag=0;    //头结点基本都有左孩子，即有根结点，是非空树
	root->rtag=1;   //头结点没有兄弟结点
	root->rchild=b;   //头结点后继是根结点
	if(b==NULL)   //空树
		root->rchild=root;
	else{
		root->lchild=b;  //否则头结点的左孩子是根结点
		pre=root;   //pre始终是p的前驱结点，用来线索化
		inthread(b);
		pre->rchild=root;   //当pre指向最后一个结点时，线索化其右指针。书上是=root，王道是NULL
		pre->rtag=1;
		root->rchild=pre;
	}
	return root;
}
void thInOrder(btNode *tb)   //输出中序线索二叉树的序列
{
	btNode *p=tb->lchild;		//指向根节点，tb是头结点
	while (p!=tb)		
	{
		while (p->ltag==0)   //左指针存在，即有左孩子
			p=p->lchild;     //走到最左
		printf("%c",p->data);
		while (p->rtag==1 && p->rchild!=tb)   //最左结点的右指针为空，则该右指针就是其后继结点。若该结点是最后一个结点，那么其右指针就是头结点，不满足条件，结束循环
		{
			p=p->rchild;
			printf("%c",p->data);
		}
		p=p->rchild;
	}
}

int main(){
	btNode *b;
	elemtype ch[]="A(B(D(,G)),C(E,F))";
	createBtree(b,ch);
	printf("b:");
	dispBtree(b);
	printf("\n中序线索二叉树的序列:");
	thInOrder(createThread(b));
	return 0;
}
