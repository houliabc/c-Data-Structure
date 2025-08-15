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
void eazySort(rectype r[],int n){
	int k,min;
	for(int i=0;i<n-1;i++){
		min=i;
		for(k=i+1;k<n;k++)
			if(r[k].key<r[min].key)
				min=k;
		if(min!=i)  //表示不是原地交换
			swap(r[min].key,r[i].key);
	}
}

//大根堆排序
//筛选函数，选出最大的上浮，小元素下坠
void sift(rectype r[],int i,int len){ 
	//left是左孩子,i是根，len是多少个数据
	r[0]=r[i];   //将0腾出，暂存数据
	for(int left=2*i;left<=len;left*=2){
		if(left<len && r[left].key<r[left+1].key)  //选出左右孩子最大的一个
			left++;  //右孩子更大，将left指向右孩子
		if(r[0].key<r[left].key){  //左孩子比根大
			r[i]=r[left];  //将左孩子挪到根上
			i=left;
		}
		else  //根比左右孩子都大
			break;
	}
	r[i]=r[0];
}
//建立大根堆的方式：从最后一个分支节点开始，大的上浮，小的筛下去
void createHeap(rectype r[],int n){
	for(int i=n/2;i>=1;i--)
		sift(r,i,n);
}
//堆排序的建立，每次根（最大的）和最后一个元素交换，这样每次选出最大的放末尾，就形成了升序
void heapSort(rectype r[],int n){
	createHeap(r,n);
	for(int i=n;i>=2;i--){  //进行n-1躺堆排序，每一趟堆中元素个数减1
		swap(r[1].key,r[i].key);  //将最后一个元素和根交换
		sift(r,1,i-1);
	}
}


//小根堆排序
//筛选函数，选出最大的上浮，小元素下坠
void sift2(rectype r[],int i,int len){ 
	r[0]=r[i];   
	for(int left=2*i;left<=len;left*=2){
		if(left<len && r[left].key>r[left+1].key)  //如果右孩子更小
			left++;    //也就只需改动两个if的大于小于号即可 
		if(r[0].key>r[left].key){  
			r[i]=r[left];  
			i=left;
		}
		else 
			break;
	}
	r[i]=r[0];
}
void createHeap2(rectype r[],int n){
	for(int i=n/2;i>=1;i--)
		sift2(r,i,n);
}

void heapSort2(rectype r[],int n){
	createHeap2(r,n);
	for(int i=n;i>=2;i--){ 
		swap(r[1].key,r[i].key);  
		sift2(r,1,i-1);
	}
}

//下标从0开始的堆排序
void sift3(rectype r[],int i,int len){
	 int temp=r[i].key;
	 int left;
	 for(left=i*2+1;left<len;left=i*2+1){
	     if(left!=len-1 && r[left+1].key>r[left].key)
	        left++;
	    if(temp>r[left].key)
	        break;
	    else
	        {r[i].key=r[left].key;i=left;}
	 }
	 r[i].key=temp;
}
void heapsort(rectype r[],int n){
     for(int i=n/2-1;i>=0;i--)
        sift3(r,i,n);
    for(int i=n-1;i>=1;i--){
        int temp=r[0].key;
        r[0].key=r[i].key;
        r[i].key=temp;
        sift3(r,0,i);
    }
 }



int main(){
	int n=8;
	rectype R4[MAXL];rectype R3[MAXL];
	keytype c[]={15,6,0,7,9,3,10,30};
	printf("冒泡排序-------------------------------------\n");
	createlist(R4,c,n);
	displist(R4,n);
	eazySort(R4,n);
	displist(R4,n);
	printf("堆排序-------------------------------------\n");
	createlist2(R3,c,n);
	createHeap2(R3,n);  //实现小根堆
	displist2(R3,n);
	heapSort2(R3,n);  //小根堆的排序（降序）
	displist2(R3,n);	
	
	heapSort(R3,n);  //大根堆的排序（升序）
	displist2(R3,n);	
    return 0;
}
