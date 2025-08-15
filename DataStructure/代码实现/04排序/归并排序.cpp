#include <stdio.h> 
#define MAXL 100
#include <malloc.h>

typedef int keytype;
typedef char infotype;
typedef struct{
	keytype key;
	infotype data;
}rectype;
void createlist(rectype R[],keytype keys[],int n)	//创建顺序表
{
	for (int i=0;i<n;i++)
		R[i].key=keys[i];
}
void displist(rectype R[],int n)	//输出顺序表
{
	for (int i=0;i<n;i++)
		printf("%d ",R[i].key);
	printf("\n");
}
void createlist2(rectype R[],keytype keys[],int n)	//创建顺序表
{
	for (int i=1;i<=n;i++)
		R[i].key=keys[i-1];
}
void displist2(rectype R[],int n)	//输出顺序表
{
	for (int i=1;i<=n;i++)
		printf("%d ",R[i].key);
	printf("\n");
}
//简单排序（王）
void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}

//二路归并排序（递归式）
void merge(rectype r[],int low,int mid,int high){
	rectype* r1;  //辅助变量进行排序
	int i=low,j=mid+1,k;  //i是第一段，j是第二段，k表示r的位置
	r1=(rectype*)malloc((high-low+1)*sizeof(rectype)); //分配和r一样的空间
	for(k=low;k<=high;k++)  //先将第一段和第二段都移去r1
		r1[k].key=r[k].key;  
	for(k=i;i<=mid&&j<=high;k++){
		if(r1[i].key<=r1[j].key)
			r[k].key=r1[i++].key;
		else
			r[k].key=r1[j++].key;
	}
	//当其中一段完了另一段没完时
	while(i<=mid)
		r[k++].key=r1[i++].key;
	while(j<=high)
		r[k++].key=r1[j++].key;
	free(r1);
}
void mergeSort(rectype r[],int low,int high){
	if(low<high){  //low=high表示就剩一个元素了？
		int mid=(low+high)/2;  //中间划分，分别对两边递归的归并排序
		mergeSort(r,low,mid);
		mergeSort(r,mid+1,high);
		merge(r,low,mid,high);  //再对上面两个归并
	}
}



//非递归式
void MergePass(rectype R[],int length,int n)	//对整个数序进行一趟归并
{
	int i;
	for (i=0;i+2*length-1<n;i=i+2*length) 	//归并length长的两相邻子表
		merge(R,i,i+length-1,i+2*length-1);
	if (i+length-1<n-1)                		//余下两个子表,后者长度小于length
		merge(R,i,i+length-1,n-1);  		//归并这两个子表
}
void MergeSort(rectype R[],int n)			//自底向上的二路归并算法
{
	int length;
	for (length=1;length<n;length=2*length)//进行log2n趟归并
		MergePass(R,length,n);
}


int main(){
	int n=8;
	rectype R4[MAXL],R[MAXL];
	keytype c[]={15,6,0,7,9,3,10,30};
	printf("归并排序（递归）-------------------------------------\n");
	createlist(R4,c,n);
	displist(R4,n);
	mergeSort(R4,0,n-1);
	displist(R4,n);	
	
	printf("归并排序（非递归）-------------------------------------\n");
	createlist(R,c,n);
	displist(R,n);
	MergeSort(R,n-1);
	displist(R,n);	
    return 0;
}
