#include <stdio.h>
#include <malloc.h>
#define MaxSize 50

typedef int ElemType;
typedef struct{
	ElemType data[MaxSize];  //elemtype都用int替代
	int length;
}Sqlist;  //这里在struct后面这样写了所以就是结构体指针类型，所以要用指针？

//1.建立顺序表
void Create(Sqlist * &L,ElemType a[],int n){
	int i=0;
	L=(Sqlist *)malloc(sizeof(Sqlist));
	while(i<n){
		L->data[i]=a[i];
		i++;
	}
	L->length=i;
}

//2.顺序表基本运算算法
//1.初始化顺序表
void initlist(Sqlist *& L){
	L=(Sqlist *)malloc(sizeof(Sqlist));
	L->length=0;
}
//2.销毁顺序表
void destroylist(Sqlist *&L){
	free(L);
}
//3.判断顺序表是否为空表
bool listempty(Sqlist *L){
	return(L->length==0);
}
//4.求顺序表的长度
int listlength(Sqlist *L){
	return(L->length);
}
//5.输出顺序表
void displist(Sqlist * L){
	for(int i=0;i<L->length;i++)
		printf("%d,",L->data[i]);
	printf("\n");
}
//6.求顺序表中对应位置的元素值
bool getelem(Sqlist *L,int i,ElemType &e){
	if(i<1 || i>L->length)
		return false;
	e=L->data[i-1];
	return true;
}
//7.按元素值查找位置
int locateelem(Sqlist *L,ElemType e){
	int i=0;
	while(i<L->length && L->length!=e)
		i++;
	if(i>=L->length)
		return 0;
	else
		return i+1;
}
//8.按位置前插入数据元素
bool listinsert(Sqlist * &L,int i,ElemType e){
	int j;
	if(i<1 || i>L->length)
		return false;
	i--;
	for(j=L->length;j>i;j--)
		L->data[j]=L->data[j-1];
	L->data[i]=e;
	L->length++;
	return true;
}
//9.删除第i个数据元素
bool listdelete(Sqlist * &L,int i,ElemType &e){
	int j;
	if(i<1 || i>L->length)
		return false;
	i--;
	e=L->data[i];
	for(j=i;j<L->length;j++)
		L->data[j]=L->data[j+1];
	L->length--;
	return true;
}

//3.顺序表的应用
//1.删除所有值等于x的元素，时间复杂度为On、空间复杂度为O1\
//我自己写的错误版本
void listdeleteall(Sqlist * &L,ElemType x){
	int i=0;
	while(i<L->length){
		if(L->data[i]==x){
			for(int j=i;j<L->length;j++){
				L->data[j]=L->data[j+1];
			}
			L->length--;
		}
		else
			i++;
	}
}
//答案版本
void listdeleteall2(Sqlist *&L,ElemType x){
	int k=0,i;
	for(i=0;i<L->length;i++){
		if(L->data[i]!=x){
			L->data[k]=L->data[k];
			k++;
		}
	}
	L->length=k;  //k为不等于x的个数，将不等于x的数据往前放，覆盖掉，最后设置表长，就后面的元素扔掉
}
//2.设计一个尽可能高效的算法，使第一个元素为分界线，小于的放左边，大于的放右边
void boundaryList(Sqlist *&L){
	ElemType x=L->data[0];
}


int main(){
	ElemType a1[]={10,20,30,40,50,60,70,80,90,100,10};
	Sqlist *L;
	initlist(L);
	Create(L,a1,sizeof(a1)/sizeof(a1[0]));
	printf("是否为空表：%d\n",listempty(L));
	printf("表的长度：%d\n",listlength(L));
	displist(L);
	
	listinsert(L,4,999);
	printf("test------------------------------\n");
	displist(L);
	listdeleteall(L,10);
	displist(L);
	
	destroylist(L);
	printf("摧毁数据后没有free则还会有很多脏数据\n");
	displist(L);//摧毁数据后没有free则还会有很多脏数据
	return 0;
}
