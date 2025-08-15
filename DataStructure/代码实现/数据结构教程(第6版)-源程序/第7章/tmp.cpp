#include "bTree.cpp"		//包含二叉树的基本运算函数
BTNode* firstk1(BTNode*b,int level,int k)
{
	if(b==NULL)
		return NULL;		//空树返回NULL 
	if (level==k)				//找到值为x的结点b，返回其双亲
		return b;
	BTNode*left=firstk1(b->lchild,level+1,k);	//在左子树中递归查找 
	if(left!=NULL)						//在左子树中找到值为x的结点 
		return left;					//返回其双亲
	else								//在左子树中没有找到值为x的结点
		return firstk1(b->rchild,level+1,k); //返回在右子树中查找的结果 
}
	
	
BTNode* firstk(BTNode*b,int k)
{
	return firstk1(b,1,k);
}


void Output(BTNode *b)	//按层次输出所有结点
{  BTNode *Qu[MaxSize];	//定义循环队列
   int front,rear;		//定义队头和队尾指针
   int last;			//定义当前层中最右结点在队列中的位置
   front=rear=0;		//置队列为空队列
   rear++;			//根结点进队
   last=rear;			//第1层的最右结点在队列中的位置为1
   Qu[rear]=b;
  while (rear!=front)			//队列不为空时循环
  {  front=(front+1)%MaxSize;
     b=Qu[front];			//出队一个结点b
     printf("  %c",b->data);
     if (b->lchild!=NULL) 		//左孩子进队
     {  rear=(rear+1)%MaxSize;
        Qu[rear]=b->lchild;
     }
     if (b->rchild!=NULL) 		//右孩子进队
     {  rear=(rear+1)%MaxSize;
        Qu[rear]=b->rchild;
     }
     if (front==last)		//当前层的所有结点处理完毕
     {  printf("\n");		//换行进入下一层结点输出
        last=rear;		//让last指向下一层的最右结点在队列中的位置
     }
  }
}

bool brother(BTNode *b,char x,char y)
{
	if(b==NULL) return false;
	if(b->lchild!=NULL && b->rchild!=NULL)		//结点b存在左右孩子
	{	if((b->lchild->data==x && b->rchild->data==y) ||
				(b->lchild->data==y && b->rchild->data==x))
			return true;
	}
	if(brother(b->lchild,x,y))
		return true;
	else
		return brother(b->rchild,x,y);
}

void MaxPath(BTNode *b,ElemType maxpath[],int &maxpathlen) //求出的最长路径是maxpath[maxpathlen-1]
{	//maxpathlen的初值为0
	struct snode
	{	BTNode *node;					//存放当前结点指针
		int parent;					//存放双亲结点在队列中的位置
	} Qu[MaxSize];					//定义非环形队列
	ElemType path[MaxSize];				//存放一条路径
	int pathlen;						//存放一条路径长度
	int front,rear,p,i;				//定义队头和队尾指针
	front=rear=-1;					//置队列为空队列
	rear++;
	Qu[rear].node=b;					//根结点指针进进队
	Qu[rear].parent=-1;				//根结点没有双亲结点
	while (front<rear)					//队列不为空
	{	front++; b=Qu[front].node;		//队头出队列
		if (b->lchild==NULL && b->rchild==NULL) //b为叶子结点
		{	p=front;	pathlen=0;
			while (Qu[p].parent!=-1)
			{	path[pathlen]=Qu[p].node->data;
				pathlen++;
				p=Qu[p].parent;
			}
			path[pathlen]=Qu[p].node->data;
			pathlen++;
			if (pathlen>maxpathlen)		//通过比较求最长路径
			{	for (i=0;i<pathlen;i++)
					maxpath[i]=path[i];
				maxpathlen=pathlen;
			}
		}
		if (b->lchild!=NULL)			//左孩子结点进队
		{	rear++;
			Qu[rear].node=b->lchild;
			Qu[rear].parent=front;
		}
		if (b->rchild!=NULL)			//右孩子结点进队
		{	rear++;
			Qu[rear].node=b->rchild;
			Qu[rear].parent=front;
		}
	}
}

int main()
{
	BTNode *b;
	CreateBTree(b,"A(B(D(,G)),C(E,F))");
	printf("b:");DispBTree(b);printf("\n");
	char maxpath[MaxSize];
	int maxpathlen=0;
	MaxPath(b,maxpath,maxpathlen);
	printf("ans: ");
	for(int i=0;i<maxpathlen;i++)
		printf("%c ",maxpath[i]);
	printf("\n");
	DestroyBTree(b);
	return 0;
}
