#include <stdio.h> 
#define MAXL 100

typedef int keytype;
typedef char infotype;
typedef struct{
	keytype key;
	infotype data;
}rectype;

//直接插入排序,我的
void insertSort(rectype R[],int n){
	int i=1,temp,k;
	for(;i<n;i++){   //若是0或1个则不执行
		if(R[i-1].key>R[i].key){
			temp=R[i].key;  
			//将前面大于的往后移
			k=i-1;    //升序的前一项
			while(R[k].key>temp && k>=0){  //构造稳定的排序
				R[k+1]=R[k];
				k--;
			}
			R[k+1].key=temp;
		}
	}
}
//王道（带哨兵实现，0空出来，插入数据时，下表从1开始）
void insertSort2(rectype R[],int n){
	int i=2,k;
	for(;i<=n;i++){   //若是0或1个则不执行
		if(R[i-1].key>R[i].key){
			R[0].key=R[i].key;  //每次将需要插入的数据放到哨兵位
			k=i-1;  
			while(R[k].key>R[0].key){ //用了哨兵不需要在判断k>=0，当R[k]==哨兵时，跳出循环
				R[k+1]=R[k];
				k--;
			}
			R[k+1].key=R[0].key;  //插入哨兵
		}
	}
}
//折半插入，减少比较次数，但是移动次数还是一样的
void binInsertSort(rectype R[],int n){
	int i,temp,k,low,high,mid;
	for(i=1;i<n;i++){   //若是0或1个则不执行
		if(R[i-1].key>R[i].key){
			temp=R[i].key;  
			//将前面大于的往后移
			low=0;high=i-1;
			while(low<=high){
				mid=(low+high)/2;
				if(temp<R[mid].key)
					high=mid-1;
				else
					low=mid+1;
			}
			for(k=i-1;k>=high+1;k--)
				R[k+1]=R[k];
			R[high+1].key=temp;
		}
	}
}
//哨兵实现
void binInsertSort2(rectype R[],int n){
	int i,k,low,high,mid;
	for(i=2;i<=n;i++){
		low=1,high=i-1;
		R[0].key=R[i].key;
		while(low<=high){
			mid=(low+high)/2;
			if(R[0].key<R[mid].key)
				high=mid-1;
			else   //为了保持稳定性，应该在相同元素的右边进行插入，那就需要相等时，继续在右边进行查找
				low=mid+1;	
		}
		for(k=i-1;k>=low;k--)  //用high+1或者low都行
			R[k+1].key=R[k].key;
		R[low].key=R[0].key;
		
	}
}
//希尔排序（牺牲了0的下标）
void shellSort(rectype R[],int n){
	int d,j,i;
	for(d=n/2;d>=1;d/=2){  //d表示的是两个数据之间的距离
		for(i=d+1;i<=n;i++){  //下标0不放数据，从1开始放，这里i=d+1就类似插入排序中i=1一样，放到第二个数上
			R[0].key=R[i].key;  //不是用的哨兵，0是暂存数据区	
			j=i-d;  //j就是第一个数
			for(;j>0 && R[j].key>R[i].key;j-=d)
				R[j+d].key=R[j].key;
			R[j+d].key=R[0].key;
		}
	}
}
//希尔排序（课本）
void shellSort2(rectype R[],int n){
	int d,j,i,temp;  //用了临时变量，而不用0下标的位置暂存，但这里第一个数据还是放的1位置
	for(d=n/2;d>=1;d/=2){
		for(i=d;i<n;i++){
			temp=R[i].key;  
			j=i-d;
			for(;j>=0 && R[j].key>R[i].key;j-=d)
				R[j+d].key=R[j].key;
			R[j+d].key=temp;
		}
	}
}





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
int main(){
	int n=8;
	rectype R4[MAXL];
	keytype c[]={15,6,0,7,9,3,10,30};
	printf("插入排序--------------------\n");
	createlist(R4,c,n);
	displist(R4,n);
	insertSort(R4,n);
	displist(R4,n);
	printf("折半插入排序--------------------\n");
	createlist(R4,c,n);
	displist(R4,n);
	binInsertSort(R4,n);
	displist(R4,n);
	printf("希尔排序--------------------\n");
	createlist2(R4,c,n);
	displist2(R4,n);
	shellSort(R4,n);
	displist2(R4,n);
    return 0;
}
