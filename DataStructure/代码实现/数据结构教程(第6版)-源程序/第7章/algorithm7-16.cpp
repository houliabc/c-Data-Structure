//【例7.16】的算法：输出二叉树中值为x的节点的所有祖先。
#include "btree.cpp"
bool ancestor(BTNode *b,ElemType x)
{
	if (b==NULL)
		return false;
	else if (b->lchild!=NULL && b->lchild->data==x || b->rchild!=NULL && b->rchild->data==x)
	{
		printf("%c ",b->data);
		return true;
	}
	else if (ancestor(b->lchild,x) || ancestor(b->rchild,x))
	{
		printf("%c ",b->data);
		return true;
	}
	else
		return false;
}
bool ancestor1(BTNode *b,ElemType x,ElemType path[],int d)
{
	bool find;
	if (b==NULL)				//空树返回false
		return false;
	d++; path[d]=b->data;		//当前结点加入path
	if (b->data==x)				//当前结点值为x，输出
	{
		for (int i=0;i<d;i++)
			printf("%c ",path[i]);
		printf("\n");
		return true;
	}
	find=ancestor1(b->lchild,x,path,d);	//在左子树中查找
	if (find)							//左子树中成功找到
		return true;
	else				//左子树中没有找到，在右子树中查找
		return ancestor1(b->rchild,x,path,d);
}
void main()
{
	BTNode *b;
	ElemType x='G';
	CreateBTree(b,"A(B(D(,G)),C(E,F))");
	printf("b:");DispBTree(b);printf("\n");
	ElemType path[100];
	int d=-1;
	printf("结点%c的所有祖先:",x);
	ancestor1(b,x,path,d);
	DestroyBTree(b);
}
