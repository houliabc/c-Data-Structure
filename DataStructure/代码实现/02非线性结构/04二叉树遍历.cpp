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

//二叉树的递归遍历算法，返回的结果是便利的序列，没有括号逗号，不同于输出
//先序遍历
void preOrder(btNode *b){
	if(b!=NULL){
		printf("%c",b->data);  //访问结点
		preOrder(b->lchild);  //递归左子树
		preOrder(b->rchild);  //递归右子树
	}
}
//中序遍历
void inOrder(btNode *b){
	if(b!=NULL){
		inOrder(b->lchild);  //递归左子树
		printf("%c",b->data);  //访问结点
		inOrder(b->rchild);  //递归右子树
	}
}
//后序遍历
void postOrder(btNode *b){
	if(b!=NULL){	
		postOrder(b->lchild);  //递归左子树
		postOrder(b->rchild);  //递归右子树
		printf("%c",b->data);  //访问结点
	}
}

//二叉树的非递归遍历算法，利用栈
//前序遍历顺序是：根-左-右
//先打印根节点的值，由于栈是先进后出，所以先将 右子树放进去，再将左子树放进去
void preOrder2(btNode *b){
	int top=0;
	btNode *stack[Maxsize],*p=b;
	if(!p){
		printf("empty");
		return;
	}
	stack[top]=p;  //将根节点入栈，以便最先出根节点
	while(top>-1){
		p=stack[top--];  //出栈并访问
		printf("%c",p->data);
		
		// 先把右子树放进去再放左子树，这样每次出的都是左子树，最后会只剩右子树，再一次弹出
		if(p->rchild)
			stack[++top]=p->rchild;
		if(p->lchild)
			stack[++top]=p->lchild;
	}
}
//中序遍历的非递归方式实现思想是：
//1. 从根结点开始，遍历左孩子同时压栈，当遍历结束，说明当前遍历的结点没有左孩子，
//2. 从栈中取出来调用操作函数，然后访问该结点的右孩子，继续以上重复性的操作。
void inOrder2(btNode *b){
	int top=0;
	btNode *stack[Maxsize],*p=b;
	if(!p){
		printf("empty");
		return;
	}
	while(p||top>0){
		while(p){  //沿着根的左孩子，依次入栈，直至左孩子为空
			stack[++top]=p;
			p=p->lchild;
		}
		p=stack[top--];  //出栈并访问
		printf("%c",p->data);
		p=p->rchild;  //如果有右孩子，继续访问该右孩子的左孩子
	}
}
//后序遍历【较为复杂的方法】
//原理：入栈顺序：先根后右子树最后左子树
//每输出一个结点，将have_visit已经访问这个遍历设置为输出的结点用来记录看，以防重复输出
//并且p要归空，防止继续入栈
void postOrder2(btNode *b){
	int top=0;
	btNode *stack[Maxsize],*p=b,*have_visited=NULL;
	if(!p){  //空树
		printf("empty");
		return;
	}
	while(p||top>0){
		while(p){  //根节点先入栈，其次左孩子入栈
			stack[top++]=p;
			p=p->lchild;
		}
		p=stack[top-1];  //设置p为左叶子结点
		//如果该结点没有右子树，直接输出该结点。否则先输出右结点
		//右子树先入栈，这样先出的是左子树
		if(p->rchild==NULL || p->rchild==have_visited){  //如果没有右孩子则表示是叶子节点，并且要第二次访问该结点才能输出
			printf("%c",p->data);
			top--;
			have_visited=p;
			p=NULL;
		}
		else
			p=p->rchild;  //
	}
}
//后序遍历【较为简单的方法】
//后序：左->右->根
//那么可以把后序当作：根->右->左，最后再反转回来即可。
//由于我们是使用的栈，所以先保存根节点， 然后先放进去 左节点，再放 进去 右节点
void postOrder3(btNode *b){
	int top=1,count=0;elemtype array[Maxsize];  // 使用一个数组来保存数据，方便最后数组的反转
	//count用来计数树的结点数
	btNode *stack[Maxsize],*p;
	if(!b){  //空树
		printf("empty");
		return;
	}
	stack[top]=b;
	while(top>0){
		p=stack[top--];
		array[count++]=p->data;
		if(p->lchild!=NULL)
			stack[++top]=p->lchild;
		if(p->rchild!=NULL)
			stack[++top]=p->rchild;	
		}
	for(int i=count-1;i>=0;i--)
		printf("%c",array[i]);
}

//二叉树的层次遍历算法，利用队列
void levelOrder(btNode *b){
	if(!b){  //空树
		printf("empty");
		return;
	}
	btNode *stack[Maxsize],*p=b;
	int front=0,rear=0;  //环形队列
	stack[rear++]=p;
	while(front!=rear){  //队列不空
		p=stack[front++];
		printf("%c",p->data);
		if(p->lchild)
			stack[rear++]=p->lchild;
		if(p->rchild)
			stack[rear++]=p->rchild;
	}
}

//由前续加中序遍历序列构造二叉树，
btNode * createBt(char *pre,char *in,int n){   //n为二叉树结点个数
	btNode *b;elemtype *p;int k;
	if(n<=0)
		return NULL;
	b=(btNode *)malloc(sizeof(btNode));
	b->data=*pre;   //这里等号右边是用了间接引用字符串，那就是该字符串（数组）第一位A
	for (p=in;p<in+n;p++)  //这里p的初始值是D
		if(*p==*pre)  //此时p为in中根节点的位置
			break;
	k=p-in;  //相当于求出根节点在数组中的下标
	b->lchild=createBt(pre+1,in,k);  //pre+1是少了A的前序序列
	b->rchild=createBt(pre+k+1,p+1,n-k-1);  
	//pre+k+1是前序遍历序列的右子树序列部分，p+1是中序序列右子树部分，n-k-1因为k的下标从0开始
	return b;
}
//由后续加中序遍历序列构造二叉树，
btNode * createBt2(char *post,char *in,int n){   //n为二叉树结点个数
	btNode *b;elemtype *p,r;int k;
	if(n<=0)
		return NULL;
	r=*(post+n-1);   //r是根结点值
	b=(btNode *)malloc(sizeof(btNode));
	b->data=r;  
	for (p=in;p<in+n;p++)  //这里p的初始值是D
		if(*p==r)  //此时p为in中根节点的位置
			break;
	k=p-in;  //相当于求出根节点在数组中的下标
	b->lchild=createBt2(post,in,k);  //构造左子树
	b->rchild=createBt2(post+k,p+1,n-k-1);    //构造右子树
	return b;
}

int main(){
	btNode *b;
	elemtype ch[]="A(B(D(,G)),C(E,F))";
	createBtree(b,ch);
	printf("b:");
	dispBtree(b);
	printf("\npreOrder的b:");
	preOrder(b);
	printf("\ninOrder的b:");
	inOrder(b);
	printf("\npostOrder的b:");
	postOrder(b);
	printf("\n------------------------------------\npreOrder2的b:");
	preOrder2(b);
	printf("\ninOrder2的b:");
	inOrder2(b);
	printf("\npostOrder2的b:");
	postOrder2(b);
	printf("\npostOrder3的b:");
	postOrder3(b);
	printf("\nleverOrder的b:");
	levelOrder(b);
	printf("\n-------------------------------------\n前序＋中序：");
	dispBtree(createBt("ABDGCEF","DGBAECF",7));
	printf("\n后序＋中序：");
	dispBtree(createBt2("GDBEFCA","DGBAECF",7));
	return 0;
}
