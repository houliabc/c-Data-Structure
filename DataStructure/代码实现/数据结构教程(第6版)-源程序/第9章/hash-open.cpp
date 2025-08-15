//开放地址法构造的哈希表的运算算法
#include <stdio.h>
#define MaxSize 100			//定义最大哈希表长度
#define NULLKEY -1			//定义空关键字值
typedef int KeyType;		//关键字类型
typedef struct
{
	KeyType key;			//关键字域
	int count;				//探测次数域
} HashTable;				//哈希表类型
void InsertHT(HashTable ha[],int &n,int m,int p,KeyType k)  //将关键字k插入到哈希表中
{
	int cnt,adr;
	adr=k % p;					//计算哈希函数值
	if (ha[adr].key==NULLKEY)	//k可以直接放在哈希表中
	{
		ha[adr].key=k;
		ha[adr].count=1;
	}
	else						//发生冲突时采用线性探测法解决冲突
	{
		cnt=1;					//cnt记录k发生冲突的次数
		do 
		{
			adr=(adr+1) % m;	//线性探测
			cnt++;
		} while (ha[adr].key!=NULLKEY);
		ha[adr].key=k;			//在adr处放置k
		ha[adr].count=cnt;		//设置探测次数
	}
	n++;						//总关键字个数增1
}
void CreateHT(HashTable ha[],int &n,int m,int p,KeyType keys[],int total)  //由keys中total个关键字创建哈希表
{
	for (int i=0;i<m;i++)				//哈希表置空的初值
    {
        ha[i].key=NULLKEY;
	    ha[i].count=0;
    }
	n=0;
	for (int i=0;i<total;i++)
		InsertHT(ha,n,m,p,keys[i]);		//插入n个关键字
}
void SearchHT(HashTable ha[],int m,int p,KeyType k)  //在哈希表中查找关键字k
{
	int cnt=1,adr;
	adr=k % p;					//计算哈希函数值
	while (ha[adr].key!=NULLKEY && ha[adr].key!=k)
	{
		cnt++;					//累计关键字比较次数
		adr=(adr+1) % m;		//线性探测
	}
	if (ha[adr].key==k)			//查找成功
		printf("成功：关键字%d，比较%d次\n",k,cnt);
	else						//查找失败
		printf("失败：关键字%d，比较%d次\n",k,cnt);
}
bool DeleteHT(HashTable ha[],int &n,int m,int p,KeyType k)	//删除哈希表中关键字k
{
	int adr;
	adr=k % p;					//计算哈希函数值
	while (ha[adr].key!=NULLKEY && ha[adr].key!=k)
		adr=(adr+1) % m;		//线性探测
	if (ha[adr].key==k)			//查找成功
	{	
		int j=(adr+1)%m;								//j为adr的循环后继位置 
		while (ha[j].key!=NULLKEY && ha[j].key%p==k%p)	//查找adr位置后面的同义词
		{
			ha[(j-1+m)%m].key=ha[j].key;				//将同义词前移动 
			j=(j+1)%m;									//继续试探循环后继位置 
		}
		ha[(j-1+m)%m].key=NULLKEY;						//删除最后一个同义词
		ha[(j-1+m)%m].count=0;
		n--;											//哈希表中元素个数减少1
		return true;									//查找成功返回true 
	}
	else												//查找失败的情况 
		return false;									//返回false
}
void DispHT(HashTable ha[],int n,int m,int p)  //输出哈希表
{
	int i,j;
	int succ=0,unsucc=0,s;
	printf("哈希表:\n");
	printf(" 哈希表地址:\t");
	for (i=0;i<m;i++) 
		printf(" %3d",i);
	printf(" \n");
    printf(" 哈希表关键字:\t");
	for (i=0;i<m;i++) 
		if (ha[i].key==NULLKEY)
			printf("    ");			//输出3个空格
		else
			printf(" %3d",ha[i].key);
	printf(" \n");
	printf(" 探测次数:\t");
	for (i=0;i<m;i++)
		if (ha[i].key==NULLKEY)
			printf("    ");			//输出3个空格
		else
			printf(" %3d",ha[i].count);
	printf(" \n");
}
/*
int main()
{
	int keys[]={16,74,60,43,54,90,46,31,29,88,77};
	int n,m=13,p=13,k;
	HashTable ha[MaxSize];
	printf("(1)创建哈希表\n"); CreateHT(ha,n,m,p,keys,11);
	printf("(2)显示哈希表:\n"); DispHT(ha,n,m,p);
	k=29;
	printf("(3)查找"); SearchHT(ha,m,p,k);
	k=31;
	printf("(4)删除：关键字%d\n",k);
	DeleteHT(ha,n,m,p,k);
	printf("(5)显示哈希表:\n"); DispHT(ha,n,m,p);
	printf("(6)查找"); SearchHT(ha,m,p,k);
	printf("(7)插入：关键字%d\n",k);
	InsertHT(ha,n,m,p,k);
	printf("(8)显示哈希表:\n"); DispHT(ha,n,m,p);
	printf("\n");
	return 1;
}
*/
int main()
{
	int keys[]={7,12,17,22};
	int n,m=5,p=5,k;
	HashTable ha[MaxSize];
	printf("(1)创建哈希表\n"); CreateHT(ha,n,m,p,keys,4);
	printf("(2)显示哈希表:\n"); DispHT(ha,n,m,p);
	k=12;
	printf("(3)查找"); SearchHT(ha,m,p,k);
	k=7;
	printf("(4)删除：关键字%d\n",k);
	DeleteHT(ha,n,m,p,k);
	printf("(5)显示哈希表:\n"); DispHT(ha,n,m,p);
	printf("(6)查找"); SearchHT(ha,m,p,k);
	printf("(7)插入：关键字%d\n",k);
	InsertHT(ha,n,m,p,k);
	printf("(8)显示哈希表:\n"); DispHT(ha,n,m,p);
	printf("\n");
	return 1;
}

