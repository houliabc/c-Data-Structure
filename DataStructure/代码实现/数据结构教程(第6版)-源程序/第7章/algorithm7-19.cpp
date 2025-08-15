//【例7.19】的算法：将二叉树的顺序存储结构转换成二叉链存储结构
#include "btree.cpp"
typedef char Elemtype;
typedef ElemType SqBTree[MaxSize];
BTNode *trans(SqBTree a,int i)
{
	BTNode *b;
	if (i>MaxSize)
		return(NULL);
	if (a[i]=='#')	return(NULL);			//当节点不存在时返回NULL
	b=(BTNode *)malloc(sizeof(BTNode));	//创建根节点
	b->data=a[i];
	b->lchild=trans(a,2*i);					//递归创建左子树
	b->rchild=trans(a,2*i+1);				//递归创建右子树
	return(b);								//返回根节点
}
void trans1(BTNode *b,SqBTree a,int i)
{
   if (b!=NULL)
   {  a[i]=b->data;					//创建根结点
      trans1(b->lchild,a,2*i);		//递归创建左子树
      trans1(b->rchild,a,2*i+1);	//递归创建右子树
   }
}
void main()
{
	BTNode *b;
	CreateBTree(b,"A(B(D),C(E,F))");
	printf("b: ");DispBTree(b);printf("\n");
	SqBTree a;
	for (int i=1;i<30;i++) a[i]='#';
	trans1(b,a,1);
	printf("a: ");
	for (int j=1;j<30;j++)
		printf("%c",a[j]);
	printf("\n");
	DestroyBTree(b);
}
