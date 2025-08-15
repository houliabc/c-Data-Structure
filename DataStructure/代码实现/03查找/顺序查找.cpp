#include <stdio.h> 
#define MAXL 100

typedef int keytype;
typedef char infotype;
typedef struct{
	keytype key;  //这是查找的关键字
	infotype data;
}rectype;
//顺序查找1
int seqSearch(rectype r[],int n,keytype k){
	int i=0;
	for(;i<n;i++)
		if(r[i].key==k)   //这里因为用的是结构体所以是.key来访问值
			break;
	if(i>=n)
		return 0;
	else
		return i+1;
}
//顺序查找2（添加了一个哨兵）
//好处：不需要对下标和边界特殊处理；缺点：表的长度需要多一个
int seqSearch2(rectype r[],int n,keytype k){
	int i=n;
	r[0].key=k;
	for(;i>0;i--)
		if(r[i].key==k)   //这里因为用的是结构体所以是.key来访问值
			break;
	return i;
}

//二分查找（升序）
int binSearch(rectype r[],int n ,keytype k){
	int low=0,high=n-1,mid;
	while(low<=high){
		mid=(low+high)/2;
		if(k==r[mid].key)
			return mid+1;
		if (k<r[mid].key)
			high=mid-1;
		else
			low=mid+1;
	}
	printf("%d,%d",low,high);
	return 0;  //如果while没有ruturn则没找到，返回0
}
//利用二分查找算法在一个有序表中插入一个元素x，并保持表的有序性。该算法使用了哨兵的方式，舍弃了下标0的结点
typedef struct
{  int key;
}sqlist;
void createlist(sqlist R[],keytype keys[],int n)	//创建顺序表
{
	for (int i=1;i<=n;i++)
		R[i].key=keys[i-1];
}
void displist(sqlist R[],int n)	//输出顺序表
{
	for (int i=1;i<=n;i++)
		printf("%d ",R[i].key);
	printf("\n");
}
void bininsert (sqlist  r[] , int x , int  n)
{
	int  low=1, high=n, mid, inplace, i, find=0;
	while (low<=high && !find)
	{  
		mid= (low+high)/2;
		if ( x<r[mid].key) high= mid-1;
		else  if ( x>r[mid].key) low= mid+1  ;
		else{
			i=  mid;
			find=1;
			}
	}
	if (find) inplace=mid;
	else inplace=low;
	for (i=n; i>=inplace; i--)
		r[i+1].key=r[i].key;
	r[inplace].key=  x;
}
//-----------------------------------------------------------------------------------------------


//为了演示所要用的顺序表创建
void CreateList(rectype R[],keytype keys[],int n)	//创建顺序表
{
	for (int i=0;i<n;i++)
		R[i].key=keys[i];
}
void DispList(rectype R[],int n)	//输出顺序表
{
	for (int i=0;i<n;i++)
		printf("%d ",R[i].key);
	printf("\n");
}


//分块查找的类型定义
typedef struct{
	keytype key;
	int link;    //指向对应块的起始下标
}indexType;


int main(){
	int n=10;
	rectype R[MAXL],R2[MAXL],R3[MAXL];
	sqlist R4[MAXL];
	keytype a[]={2,3,1,8,5,4,9,0,7,6},k=6;
	keytype b[]={-1,2,3,1,8,5,4,9,0,7,6};//第一个用于放哨兵
	keytype c[]={0,2,3,4,5,6,9,12,14,15};
	CreateList(R,a,n);
	CreateList(R2,b,n+1);  //这里要多创一个结点
	CreateList(R3,c,n);
	createlist(R4,c,n);
	printf("查找表："); DispList(R,n);
	printf("R[%d]=%d\n",seqSearch(R,n,k),k);
	printf("查找表2："); DispList(R2,n+1);
	printf("R[%d]=%d\n",seqSearch2(R2,n,k),k);
	printf("查找表3："); DispList(R3,n);
	printf("R[%d]=%d\n",binSearch(R3,n,k),k);
	printf("-------------------------查找表4：\n"); 
	displist(R4,n);
	bininsert(R4,-1,n);
	displist(R4,n+1);
    return 0;
}
