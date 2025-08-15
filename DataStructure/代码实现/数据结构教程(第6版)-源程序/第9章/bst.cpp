//二叉排序树算法
#include <stdio.h>
#include <malloc.h>
typedef int KeyType;
typedef char InfoType[10];
typedef struct node
{
	KeyType key;              		//关键字项
	InfoType data;             		//其他数据域
	struct node *lchild,*rchild;	//左右孩子指针
} BSTNode;           				//二叉排序树结点类型
BSTNode* InsertBST(BSTNode* bt,KeyType k)	//在二叉排序树bt中插入一个关键字为k的结点
{	if (bt==NULL)								//原树为空
	{	bt=(BSTNode *)malloc(sizeof(BSTNode));	//新建根结点bt 
		bt->key=k; bt->lchild=bt->rchild=NULL;
	}
	else if (k<bt->key) 
		bt->lchild=InsertBST(bt->lchild,k);	//插入到左子树中
	else if(k>bt->key)
		bt->rchild=InsertBST(bt->rchild,k);	//插入到右子树中
	return bt;								//返回插入后二叉排序树的根结点 
}

BSTNode *CreateBST(KeyType A[],int n)	//创建二叉排序树
//返回BST树根结点指针
{	BSTNode *bt=NULL;				//初始时bt为空树
	int i=0;
	while (i<n)
	{	bt=InsertBST(bt,A[i]);			//将关键字A[i]插入二叉排序树bt中
		i++;
	}
	return bt;						//返回建立的二叉排序树的根指针
}

void DispBST(BSTNode *bt)		//输出一棵排序二叉树
{
	if (bt!=NULL)
	{	printf("%d",bt->key);
		if (bt->lchild!=NULL || bt->rchild!=NULL)
		{	printf("(");						//有孩子结点时才输出(
			DispBST(bt->lchild);				//递归处理左子树
			if (bt->rchild!=NULL) printf(",");	//有右孩子结点时才输出,
			DispBST(bt->rchild);				//递归处理右子树
			printf(")");						//有孩子结点时才输出)
		}
	}
}
BSTNode *SearchBST(BSTNode *bt,KeyType k)	//递归算法：在二叉排序树bt中查找关键字为k的结点
{ 
    if (bt==NULL || bt->key==k)      	//递归终结条件
		return bt;
	if (k<bt->key)
       	return SearchBST(bt->lchild,k);  //在左子树中递归查找
    else
     	return SearchBST(bt->rchild,k);  //在右子树中递归查找
}
BSTNode *SearchBST1(BSTNode *bt,KeyType k)	//非递归算法：在二叉排序树bt中查找关键字为k的结点
{ 
	BSTNode* p=bt;
	while(p!=NULL)
    { 	if(p->key==k) break;                 //找到关键字为k的结点p
        else if(k<p->key)
			p=p->lchild;
        else
			p=p->rchild;
    }
    return p;
}

BSTNode *DeleteBST(BSTNode *bt,KeyType k)	//在bt中删除关键字为k的结点
{	if(bt==NULL) return bt;
    BSTNode* p=bt,*f=NULL;      			//f指向被删结点p的双亲结点
    while(p!=NULL)                          //查找被删结点p，其双亲是f结点 
    {
	 	if(p->key==k) break;                 //找到被删结点p时退出循环
    	f=p;
        if(k<p->key)
			p=p->lchild;
        else
			p=p->rchild;
    }
    if(p==NULL) return bt;                        //没有找到被删除结点p，返回bt
    if(p->lchild==NULL && p->rchild==NULL)     		//情况(1)-结点p是叶子结点
    {	if(p==bt)                                   //结点p是根结点
        	bt=NULL;
    	else                                        //结点p不是根结点
        {	if(f->lchild==p)						//结点p是结点f的左孩子 
				f->lchild=NULL;
            else									//结点p是结点f的右孩子
				f->rchild=NULL;
    	}
        free(p);
	}
    else if(p->rchild==NULL)                           //情况(2)-结点p的右子树为空
    {
    	if(f==NULL)	 
	    	bt=bt->lchild;                       		//结点p是根结点bt，用其左孩子替代bt 
    	else                        				//结点p存在双亲f（p不是根结点） 
        {	if(f->lchild==p)							//结点p是结点f的左孩子 
				f->lchild=p->lchild;					//用结点p的左孩子替代结点p 
            else										//结点p是结点f的右孩子
				f->rchild=p->lchild;					//用结点p的左孩子替代结点p
    	}
    	free(p);
	}
    else if (p->lchild==NULL)                            //情况(3)-结点p的左子树为空
    {
    	if(f==NULL)
	        bt=bt->rchild;                  			//结点p是根结点bt，用其右孩子替代bt
		else                        				//结点p存在双亲f（p不是根结点）
        {	if(f->lchild==p)							//结点p是结点f的左孩子 
				f->lchild=p->rchild;					//用结点p的右孩子替代结点p
            else										//结点p是结点f的右孩子
				f->rchild=p->rchild;					//用结点p的右孩子替代结点p
    	}
        free(p);
	}
    else                                                  //情况(4)-结点p有左右孩子的情况
    {	BSTNode* q=p->lchild;                				//q指向结点p的左孩子结点
        f=p;                               					//f指向结点q的双亲结点
        while(q->rchild!=NULL)                   			//找到结点p的左孩子的最右下结点q
        {	f=q;
            q=q->rchild;
    	}
        p->key=q->key;                  		     	//将结点p的值用结点q的值替换
        if(q==f->lchild)								//删除结点q(用结点q的左孩子替代结点q)
			f->lchild=q->lchild;           
        else
			f->rchild=q->lchild;
        free(q);
    }
    return bt;
}

void DestroyBST(BSTNode *&bt)		//销毁二叉排序树bt
{
	if (bt!=NULL)
	{
		DestroyBST(bt->lchild);
		DestroyBST(bt->rchild);
		free(bt);
	}
}
int main()
{
	BSTNode *bt,*p,*f;
	KeyType a[]={5,2,1,6,7,4,8,3,9};
	int n=sizeof(a)/sizeof(a[0]);
	bt=CreateBST(a,n);
	printf("BST:");DispBST(bt);printf("\n");
	int x=5;
	printf("删除%d结点\n",x);
	if (SearchBST(bt,x)!=NULL)
	{
		DeleteBST(bt,x);
		printf("BST:");DispBST(bt);printf("\n");
	}
	DestroyBST(bt);
	return 1;
}

/*
int main()
{
	BSTNode *bt,*p,*f;
	int n=12,x=46;
	KeyType a[]={25,18,46,2,53,39,32,4,74,67,60,11};
	bt=CreateBST(a,n);
	printf("BST:");DispBST(bt);printf("\n");
	printf("删除%d结点\n",x);
	if (SearchBST(bt,x)!=NULL)
	{
		DeleteBST(bt,x);
		printf("BST:");DispBST(bt);printf("\n");
	}
	DestroyBST(bt);
	return 1;
}
*/
