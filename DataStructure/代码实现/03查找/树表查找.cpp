#include <stdio.h> 
#include <malloc.h>
#define MAXL 100

//二叉排序树
typedef int keytype;
typedef char infotype;
typedef struct node{
	keytype key;
	infotype data;
	struct node *lchild,*rchild;
}bstNode;
//插入和创建（递归）
bool insertBst(bstNode *&bt,keytype k){
	if(!bt){  //
		bt=(bstNode *)malloc(sizeof(bstNode));
		bt->key=k;
		bt->lchild=bt->rchild=NULL;
	}
	else if(k==bt->key)  //不能存在关键字相同的结点
		return false;
	else if(k<bt->key)
		return insertBst(bt->lchild,k);
	else
		return insertBst(bt->rchild,k);
}
bstNode * createBst(keytype a[],int n){
	//返回树的根节点
	bstNode *bt=NULL;
	int i=0;
	while(i<n){
		insertBst(bt,a[i]);
		i++;
	}
	return bt;
}
//查找（非递归）
bstNode *searchBst(bstNode *bt,keytype k){
	while(!bt && bt->key!=k){
		if(k<bt->key)
			bt=bt->lchild;
		else
			bt=bt->rchild;
	}
	return bt;
}
//查找（递归）
bstNode *searchBst2(bstNode *bt,keytype k){
	if(!bt && bt->key==k)
		return bt;
	if(k<bt->key)
		return searchBst2(bt->lchild,k);
	else
		return searchBst2(bt->rchild,k);
}
//递归输出排序树（中序）
void dispBst(bstNode *bt){
	if(bt){
		dispBst(bt->lchild);
		printf("%d,",bt->key);
		dispBst(bt->rchild);
	}
}

//删除右子树的演示
//结点删除的操作（仅有右子树）
void deleter(bstNode *&b){
	bstNode *p;
	p=b;
	b=b->rchild;
	free(p);
}
//删除仅有右子树的操作
bool deleteR(bstNode *&bt,keytype k){
	//先要查找到k的位置
	if(bt){
		if(bt->key==k){
			deleter(bt);
			return true;
		}
		else if(bt->key<k)
			deleteR(bt->lchild,k);
		else
			deleteR(bt->rchild,k);
	}
	else 
		return false;
}


//删除二叉排序树的结点算法
//函数声明
bool deleteBst(bstNode *&bt,keytype k);
void Delete(bstNode *&p);
void deleteboth(bstNode *p,bstNode *&r);
//函数定义
bool deleteBst(bstNode *&bt,keytype k){
	if(!bt)
		return false;
	else{
		if(bt->key>k)
			return deleteBst(bt->lchild,k);
		else if(bt->key<k)
			return deleteBst(bt->rchild,k);
		else{   //找到了要删除的结点
			Delete(bt);
			return true;
		}
	}
}
void Delete(bstNode *&p){  //排序树中删除结点p（总和）
	bstNode *q;
	if(p->rchild==NULL){  //没有右子树，用左孩子替代
		q=p;
		p=p->lchild;
		free(q);
	}
	else if(p->lchild==NULL){  //没有左子树，用右孩子替代
		q=p;
		p=p->rchild;
		free(q);
	}
	else 
		deleteboth(p,p->lchild); //左右子树都有的删除函数
		//这里是沿用了左子树的最大作为根替换
}
void deleteboth(bstNode *p,bstNode *&r){ //左右子树都有的删除算法
	bstNode *q;
	if(r->rchild!=NULL)  //递归找左子树中的最右下结点（最大）
		deleteboth(p,r->rchild);
	else{ //找到了最大结点或者没有右子树则是当前结点r最大
		p->key=r->key;
		p->data=r->data;
		q=r;
		r=r->rchild;  //用左孩子替代
		free(q);
	}
}


int main(){
	keytype a[]={1,2,3,4,5};
	int n=sizeof(a)/sizeof(a[0]);
	bstNode *bt=createBst(a,n);bstNode *p;
	dispBst(bt);printf("\n");
	deleteBst(bt,2);
	dispBst(bt);
    return 0;
}
