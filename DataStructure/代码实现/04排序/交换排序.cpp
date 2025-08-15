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




void swap(int &x,int &y){
	int temp=x;x=y;y=temp;
}
//冒泡排序（从后往前.每次最小放前面）
void bubbleSort(rectype R[],int n){
	int i,j,flag=1;
	for(i=0;i<n;i++){   //最小的放前面
		for(j=n-1;j>i;j--){   //从后往前比较
			if(R[j].key<R[j-1].key){
				swap(R[j].key,R[j-1].key);
				flag=0;
			}
		}
		if(flag)
			break;
	}
}
//冒泡排序（从前往后.每次最大放后面）
void bubbleSort2(rectype R[],int n){
	int i,j,flag=1;
	for(i=n-1;i>=0;i--){  //每次将最大的放后面
		for(j=0;j<i;++j){      //从前往后比较
			if(R[j].key>R[j+1].key){
				swap(R[j].key,R[j+1].key);
				flag=0;
			}
		}
		if(flag)
			break;
	}
}
//冒泡排序之链表
//typedef struct sqNode{
//	infotype data;
//	struct sqNode *next;
//}sqList;
//void initialSqList(sqList *&L){
//	L=(sqList *)malloc(sizeof(sqList));
//	L->next=NULL;
//}
//void createSqList(sqList *&L,infotype str[],int n){
//	L=(sqList *)malloc(sizeof(sqList));
//	L->next=NULL;
//	sqList *p,*r=L;
//	for(int i=0;i<n;i++){
//		p=(sqList *)malloc(sizeof(sqList));
//		p->data=str[i];
//		r->next=p;
//		r=p;	
//	}
//	r->next=NULL;
//}
//void dispSqlist(sqList *L){
//	sqList *p=L->next;
//	while(p){
//		printf("%c,",p->data);
//		p=p->next;
//	}
//	printf("\n");
//}
//链表实现的具体方法
//void bubbleSort3(sqList *L){
//	   if (L == NULL) 
//	        return;  
//	    sqList* temp = L;  
//	    int swapped = 1;  
//	    while (swapped) {  
//	        swapped = 0;  
//	        sqList* prev = NULL;  
//	        temp = L;  
//	        while (temp->next != NULL) {  
//	            if (temp->data > temp->next->data) {  
//	                if (prev != NULL) {  
//	                    sqList* temp1 = temp->next;  
//	                    temp->next = temp1->next;  
//	                    temp1->next = temp;  
//	                    prev->next = temp1;  
//	                } else {  
//	                    sqList* temp1 = temp->next;  
//	                    temp->next = temp1->next;  
//	                    temp1->next = temp;  
//	                    L = temp1;  
//	                }  
//	                swapped = 1;  
//	            } else {  
//	                prev = temp;  
//	                temp = temp->next;  
//	            }  
//	        }  
//	    } 
//	//从后往前，每次最小的放前面
//	sqList *p=L->next;
//	while(p){
//		
//	}
//}

//快速排序（王）
int partition(rectype r[],int low,int high){
	int pivot=r[low].key;   //pivot是基准、枢轴的意思，这里每次让第一个元素作为基准
	while(low<high){   //找出low=high的枢轴位置
		while(low<high && r[high].key>=pivot)//找出比基准小的high
			high--;
		r[low].key=r[high].key;  //比枢轴小的值移到枢轴左边
		while(low<high && r[low].key<=pivot)//比low基准大时不成立
			low++;  
		r[high].key=r[low].key;  //比枢轴大的值移到枢轴右边
	}
	r[low].key=pivot; //结束循环表示，low=high，此处就是枢轴的位置，这里也可以用high
	return low;  //返回枢轴的下标
}
void quickSort(rectype r[],int low,int high){
	if(low<high){    //递归退出的条件
		int pivot=partition(r,low,high);  //这是枢轴的下标，进行划分
		quickSort(r,low,pivot-1);  //对枢轴左侧快速排序
		quickSort(r,pivot+1,high);  //对枢轴右侧快速排序
	}
}

//快速排序（优化）--选择mid作为基准
void quickSort2(rectype r[],int low,int high){
	int mid,pivot;
	mid=(low+high)/2;
	if(low<high){
		if(mid!=low)//若基准不是区间中的第一个元素，将其与第一个元素交换
			swap(r[mid].key,r[low].key); //可能是懒得搞了，把基准放去low的位置，统一操作 
		pivot=partition(r,low,high);
		quickSort2(r,low,pivot-1);
		quickSort2(r,pivot+1,high);
	}
}



int main(){
	int n=8;
	rectype R4[MAXL];
	keytype c[]={15,6,0,7,9,3,10,30};
//	sqList *L;initialSqList(L);createSqList(L,d,n);dispSqlist(L);
//	bubbleSort3(L);dispSqlist(L);
	printf("冒泡排序-------------------------------------\n");
	createlist(R4,c,n);
	displist(R4,n);
	bubbleSort2(R4,n);
	displist(R4,n);
	printf("快速排序-------------------------------------\n");
	createlist(R4,c,n);
	displist(R4,n);
	quickSort(R4,0,n-1);
	displist(R4,n);	
	printf("快速排序优化-------------------------------------\n");
	createlist(R4,c,n);
	displist(R4,n);
	quickSort2(R4,0,n-1);
	displist(R4,n);	
    return 0;
}
