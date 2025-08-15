//AVL算法
#include <stdio.h>
#include <malloc.h>
#define max(x,y) ((x)>(y)?(x):(y))
typedef int KeyType;					//关键字类型
typedef struct node 
{	
	KeyType key;                  		//关键字项
	int ht;                       		//当前结点的子树高度
    struct node *lchild,*rchild;		//左右孩子指针
} AVLNode;								//AVL树结点类型
void DestroyAVL(AVLNode* b)			//释放所有的结点空间
{
	if (b!=NULL)
	{
		DestroyAVL(b->lchild);			//递归释放左子树
		DestroyAVL(b->rchild);			//递归释放右子树
		delete b;							//释放根结点
	}
}
int getht(AVLNode* p)                 //返回结点p的子树高度
{	if (p==NULL)
		return 0;
    return p->ht;
 }
AVLNode* right_rotate(AVLNode* a) //以结点a为根做右旋转
{	AVLNode* b=a->lchild;
	a->lchild=b->rchild;
	b->rchild=a;
	a->ht=max(getht(a->rchild),getht(a->lchild))+1;
	b->ht=max(getht(b->rchild),getht(b->lchild))+1;
	return b;
}
AVLNode* left_rotate(AVLNode* a)            //以结点a为根做左旋转
{	AVLNode* b=a->rchild;
	a->rchild=b->lchild;
	b->lchild=a;
	a->ht=max(getht(a->rchild),getht(a->lchild))+1;
	b->ht=max(getht(b->rchild),getht(b->lchild))+1;
	return b;
}
AVLNode* LL(AVLNode* a)                    //LL型调整
{
	return right_rotate(a);
}
AVLNode* RR(AVLNode* a)                     //RR型调整
{
	return left_rotate(a);
}
AVLNode* LR(AVLNode* a)                     //LR型调整
{	AVLNode* b=a->lchild;
	a->lchild=left_rotate(b);    			//结点b左旋
	return right_rotate(a);     			//结点a右旋
}
AVLNode* RL(AVLNode* a)                     //RL型调整
{	AVLNode* b=a->rchild;
	a->rchild=right_rotate(b);   			//结点b右旋
	return left_rotate(a);     				 //结点a左旋
}
AVLNode* InsertAVL(AVLNode* p,KeyType k)	//在AVL树p中插入关键字k 
{	if (p==NULL)                             //空树时创建根结点
	{   AVLNode* q=(AVLNode*)malloc(sizeof(AVLNode));
		q->key=k; q->ht=1;
		q->lchild=q->rchild=NULL;
        return q;
    }
	else if (k==p->key)							//找到重复关键字时返回			
         return p;
	else if (k<p->key)                           	//k<p->key的情况
	{	p->lchild=InsertAVL(p->lchild,k);		 	//将k插入到p的左子树中
        if (getht(p->lchild)-getht(p->rchild)>=2)	//找到失衡结点p
        {	if (k<p->lchild->key)             		//k插入在p的左孩子的左子树中
                p=LL(p);               				//采用LL型调整
            else                           			//k插入在p的左孩子的右子树中
                p=LR(p);                			//采用LR型调整
        }
	}
	else                                   			//k>p->key的情况
	{	p->rchild=InsertAVL(p->rchild,k);		 	//将k插入到p的右子树中
        if (getht(p->rchild)-getht(p->lchild)>=2)   //找到失衡结点p
        {	if (k>p->rchild->key)              		//k插入在p的右孩子的右子树中
                p=RR(p);                			//采用RR型调整
            else                           			//k插入在p的右孩子的左子树中
                p=RL(p);                			//采用RL型调整
        }
    }
    p->ht=max(getht(p->lchild),getht(p->rchild))+1;   //更新结点p的高度
	return p;
}
   
AVLNode* DeleteAVL(AVLNode* p,KeyType k)				//在AVL树p中删除关键字k的结点		
{	if (p==NULL) return p;
	if (p->key==k)                        	//找到关键字为k的结点p
	{	if (p->lchild==NULL)              	//结点p只有右子树的情况
			return p->rchild;             	//直接用右孩子替代结点p
		else if (p->rchild==NULL)         	//结点p只有左子树的情况
			return p->lchild;             	//直接用左孩子替代结点p
		else                           		//结点p同时有左右子树的情况
		{	if (getht(p->lchild)>getht(p->rchild)) //结点p的左子树较高
			{	AVLNode* q=p->lchild;
            	while (q->rchild!=NULL)  	//在结点p的左子树中查找最大结点q
					q=q->rchild;
                p=DeleteAVL(p,q->key); 		//删除结点q
                p->key=q->key;             	//用q结点值替代p结点值
                return p;
            }
            else                      		//结点p的右子树较高
            {	AVLNode* q=p->rchild;
            	while (q->lchild!=NULL)   	//在结点p的右子树中查找最小结点q
                    q=q->lchild;
                p=DeleteAVL(p,q->key);			 //删除结点q
                p->key=q->key;             	//用q结点值替代p结点值
                return p;
            }
        }
    }
	else if (k<p->key)                       	//k<p->key的情况
	{	p->lchild=DeleteAVL(p->lchild,k);			//在左子树中删除关键字k的结点
        if (getht(p->rchild)-getht(p->lchild)>=2) //找到失衡结点p
        {	if (getht(p->rchild->lchild)>getht(p->rchild->rchild))
                    //print("以%d做RL调整" %(p->key))
                p=RL(p);                //若结点p的右孩子的左子树较高,做RL型调整
            else
                    //print("以%d做RR型调整" %(p->key))
                p=RR(p);                //若结点p的右孩子的右子树较高,做RR型调整
        }
    }
	else if (k>p->key)                           //k>p->key的情况
    {	p->rchild=DeleteAVL(p->rchild,k);   //在右子树中删除关键字k的结点
        if (getht(p->lchild)-getht(p->rchild)>=2) //找到失衡结点p
        { 	if (getht(p->lchild->rchild)>getht(p->lchild->lchild))
                    //print("以%d做LR型调整" %(p->key))
            	p=LR(p);                //若结点p的左孩子的右子树较高,做LR型调整
            else
                    //print("以%d做LL型调整" %(p->key))
                p=LL(p);                //若结点p的左孩子的左子树较高,做LL型调整
        }
    }
    p->ht=max(getht(p->lchild),getht(p->rchild))+1;   //更新结点p的高度
    return p;
}
AVLNode* SearchAVL(AVLNode* p,KeyType k)	         //在AVL树p中查找关键字k的结点
{	if (p==NULL) return NULL;					//空树返回Nonel
    if (p->key==k) return p;		        //找到后返回p
    if (k<p->key)
        return SearchAVL(p->lchild,k);	    //在左子树中递归查找
    else
        return SearchAVL(p->rchild,k);	    //在右子树中递归查找
}
void inorder(AVLNode* p)                    //中序遍历所有结点
{
    if (p!=NULL)
    {	inorder(p->lchild);
        printf("%d ",p->key);
        inorder(p->rchild);
    }
}
void  DispAVL(AVLNode* p)           		//以括号串输出AVL树p 
{	if (p!=NULL)
    {	printf("%d",p->key);								//输出根结点值
        if (p->lchild!=NULL || p->rchild!=NULL)
        {	printf("(");   			    			//有孩子结点时才输出"("
            DispAVL(p->lchild);			    	//递归处理左子树
            if (p->rchild!=NULL)
                printf(",");   		    			//有右孩子结点时才输出","
            DispAVL(p->rchild);			    	//递归处理右子树
            printf(")");   			    			//有孩子结点时才输出")"
		}
	}
}
int main()
{
	AVLNode *b=NULL;
	int i,j,k;
	KeyType a[]={16,3,7,11,9,26,18,14,15};
	int n=sizeof(a)/sizeof(a[0]);
	printf(" 创建一棵AVL树:\n");
	for(i=0;i<n;i++)
	{
		printf("   第%d步,插入%d元素:",i+1,a[i]);
		b=InsertAVL(b,a[i]);
		DispAVL(b);printf("\n"); 
	}
	printf("   AVL:");DispAVL(b);printf("\n");
	printf(" 删除操作:\n");						//例9.6
	k=11;
	printf("   删除关键字%d:",k);
	b=DeleteAVL(b,k);
	printf("   AVL:");DispAVL(b);printf("\n");
	k=9;
	printf("   删除关键字%d:",k);
	b=DeleteAVL(b,k);
	printf("   AVL:");DispAVL(b);printf("\n");
	k=3;
	printf("   删除关键字%d:",k);
	b=DeleteAVL(b,k);
	printf("   AVL:");DispAVL(b);printf("\n\n");
	DestroyAVL(b);
	return 1;
}
    
