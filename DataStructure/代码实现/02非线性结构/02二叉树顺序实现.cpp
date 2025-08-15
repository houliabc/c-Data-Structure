#include <stdio.h>
#include <malloc.h>
#define  Maxsize 100


typedef char elemtype;
//课本上二叉树的顺序存储定义如下
typedef elemtype sqBinTree[Maxsize];


//王道上二叉树的顺序存储定义如下
struct TreeNode{
	elemtype value;
	bool isempty;  //结点是否为空
};
TreeNode t[Maxsize];  //定义一个长度为Maxsize的数组t，按照从上至下、从左至右的顺序依次存储完全二叉树中的各个结点
 //二叉树的顺序存储定义及各操作的实现
 //i的左右孩子、父节点、所在层次
 void initTree(TreeNode *&t){
 	for(int i=0;i<Maxsize;i++){
	 	t[i].isempty=true;  //初始化时，所有结点标记为空
	 }
 }
 

int main(){
	//课本的初始数据赋值
	sqBinTree bt="#ABD#C#E######F";
	
	return 0;
}
