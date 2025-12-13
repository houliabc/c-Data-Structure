[toc]

# 绪论

## 数据结构

### 概念

- **数据**

  描述客观事物的数和字符的**集合**，是由很多个数据元素组成的集合

  > **数据有逻辑结构及存储结构（又叫做物理地址）**

- **数据元素**

  数据的**基本单位**，用来构成数据对象集合或数据集合，表示的是行

- **数据项**

  **独立的最小单位**，也叫**字段或域，表示的是列**

- **数据对象**

  指的是**性质相同**的数据元素**的集合**，其中数据的运算是对数据对象而言的，因此数据运算时，需要对性质相同的数据元素的集合进行运算

### 逻辑结构

> **逻辑结构与数据元素本身的形式、内容、相对位置、个数无关**

1. 线性结构

   - 一般线性表

     **数据元素存在一对一的关系，也叫结点间的关系**

     线性表（相同特性的一个有限序列）

     - 顺序表
     - 链表

   - 受限线性表

     - 栈
       - 顺序栈
       - 共享栈
       - 链栈
     - 队列
       - 顺序队
       - 顺序（循环）队
       - 链队
     - 串

   - 线性表推广

     - 数组

2. 非线性结构

   - 集合

     > **除了同属一个集合外没有关系，关系强度最弱**

   - 树形结构

     **关系**：一对多

     - 树
     - 二叉树

   - 图形结构

     **关系**：多对多

     - 有向图
     - 无向图

- 逻辑结构的表示

  - 图表表示

    ![](img/45.png)

  - **二元组表示（主要的）**

    **B = （D , R）**

    > B——数据结构
    > **D——数据元素的集合**
    > **R——D上二元关系的集合**
    >
    > **用<>表示的是从左到右顺序不可更改**
    >
    > **()表示连上即可，可以颠倒过来**

    - 线性结构二元组表示

      ```
      学生表=（D,R）
      D={100,101,102,103}
      R={r}
      r={<100,101>,<101,102>,<102,103>}
      ```

    - 树的二元组表示

      ```
      B1 = （D，R）
      D = {a，b，c，d，e，f，g，h，i，j}
      R = {r}
      r = { <a，b>，<a，c>，<a，d>，<b，e>，<c，f>，<c，g>，<d，h>，<d，i>，<d，j> }
      ```

    - 无向图的二元组表示

      ```
      B2 = （D，R）
      D = {a，b，c，d，e}
      R = {r}
      r = { (a，b)， (a，c)， (b，c)， (c，d)， (c，e)， (d，e) }
      ```

      > 一个关系

    - 有向图的二元组表示

      ```
      B3 = （D，R）
      D = {48，25，64，57，82，36，75}
      R = {r1 ， r2}
      
      r1 = {<48，25>，<48，64>，<64，57>，<64，82>，<25，36>，<82，75>}
      
      r2 = {<25，36>，<36，48>，<48，57>，<57，64>，<64，57>，<75，82>}
      ```

      > 两个关系

    - 矩阵的二元组表示

      ```
      B = {D,R}
      D = {2,6,3,1,8,12,7,4,5,10,9,11}
      R = {r1 ,r2} （r1表示行关系,r2表示列关系）
      
      r1 = {<2,6>,<6,3>,<3,1>,<8,12>,<12,7>,<7,14>,<5,10>,<10,9>,<9,11>}（行关系）
      
      r2 = {<2,8>,<8,5>,<6,12>,<12,10>,<3,7>,<7,9>,<1,4>,<4,11>}（列关系）
      ```

      > 特点：有两个关系

    > 设某数据结构的二元组形式表示为  A=(D  ,  R)  ,  D={01  ,  02  ,  03  ,  04  ,  05  ,  06  ,  07  ,  08  ,  09}  ,  R={r}  ,  r={<01  ,  02>  ,  <01  ,  03>  ,  <01  ,  04>  ,  <02  ,  05>  ,  <02  ,  06>  ,  <03  ,  07>  ,  <03  ,  08>  ,  <03  ,  09>}  ,则数据结构A是（）  。
    >
    > 1. 线性结构
    > 2. 树型结构
    > 3. 物理结构
    > 4. 图型结构

### 物理（存储）结构

- 顺序存储

  第n个数据的存储地址为：第一个数据的起始地址 +（n-1）* 数据类型大小

  > 逻辑上相邻的节点存储在物理位置上也相邻的连续存储单元
  >
  > 可以存储线性结构与非线性结构

- 链式存储

  > 可以存储线性结构与非线性结构

- **索引存储**

  > 如分块查找

- **散列（哈希）存储** 

  > 如哈希查找

### 数据运算

- 数据运算是指对数据实施的操作，如：插入删除等

  > 运算定义是运算功能的描述，是抽象的，是基于逻辑结构的。运算实现是程序员完成运算的实现算法，是具体的，是基于存储结构的

### 数据类型与抽象数据类型

- **数据类型**是一组**性质相同**的值的**集合和定义**在此集合上的一组操作的**总称**，是某种程序设计语言中已实现的数据结构

- **抽象数据类型**（Abstract Data Type，**ADT**）指的是用户进行软件系统设计时从问题的**数学模型中抽象出来的逻辑数据结构**上的运算，而**不考虑**计算机的具体存储结构和运算的**具体实现**算法。

  > 也就是对于某些问题，只需根据数学相关知识想出对应的思路，而实现不实现的了不管

- 抽象数据类型的两个重要特征

  1. **数据抽象**，是指用ADT描述程序处理的实体时强调的是其本质的特征、其所能完成的功能以及它和外部用户的接口（即外界使用它的方法）
  2. **数据封装**，是指将实体的外部特性和其内部实现细节分离，并且对外部用户隐藏其内部实现细节。

  > 从数据结构的角度看，一个求解问题可以通过抽象数据类型来描述，也就是说，抽象数据类型对一个求解问题从逻辑上进行了准确的定义，所以**抽象数据类型由数据逻辑结构和运算定义两部分组成**。抽象意味着一个抽象数据类型可能有多种实现方式

## 算法描述

- 算法是**对特定问题求解步骤**的**一种描述**，他是指令的**有限序列**

  > 用我的话来说就是：解决问题的一种思想

### 算法特性

- 有穷性

- **确定性**

- **可行性**

- **有输入**（零/多)

- **有输出**（至少一个）

  > 确定有穷可行

### 算法设计目标

- **正确性**

- **可使用性**

- **可读性**

- 健壮性

- **高效率与低存储量需求**

  > 高效可读可使用的正确性
  >
  > 可行性对应可使用性
  >
  > 确定性对于正确性

## 算法分析

### 时间复杂度

> 有事后统计法、事前估算法

- 算法的问题规模为n

- 常数阶：即不带问题规模n的时间复杂度

  - 如：10000次=T（1）

- > **O(1) < O(log2 n) < O(n) < O(nlog2 n) < O(n^2) <O(n^3) < O(2^n) < O(n!)**
  >
  > 在算法中，我们主要考察最坏与平均的时间复杂度情况：
  >
  > 1. 最坏情况时间复杂度（Worse-case Time Complexity）：这是一种保守的估计，表示最不利情况下的时间消耗，这**对于关键任务和高稳定性系统至关重要**。选择算法时，我们通常会考虑最坏情况的时间复杂度，以保证即使在最不利的情况下，算法的性能也能符合预期。
  > 2. 平均情况时间复杂度（Average-case Time Complexity）：平均时间复杂度描述的是在所有输入中随机抽取一个，算法可能的平均运行时间。这对于**评估算法的整体效率**十分有用。

### 空间复杂度

- S（n）=O（n）来表示

# 线性表

> 无论是线性表的顺序存储还是链式存储，其元素可以是任意数据类型，包括简单的整数、字符，也可以是复杂的如结构体、类的实例等

## 基本概念

**线性表是一个具有相同特性的数据元素的有限序列。**

> 一致性（相同特性）：所有元素属于同一数据类型。
>
> 有穷性：数据元素个数是有限的。
>
> 序列：数据元素由逻辑序号唯一确定。一个线性表中可以有相同值的元素。**一个线性表中所有元素之间的相对位置是线性的**
>
> 线性表的入和出的操作都要考虑元素是否满|空

## 顺序表

> 随机存取

按逻辑顺序依次存储到存储器中一片连续的存储空间中。

- 定义

  ```c
  typedef struct 
  {  ElemType data[MaxSize];
     int length;
  } SqList;    	//顺序表类型  
  ```

  > 说明：注意逻辑位序和物理位序相差1。

- 各算法实现：

  > 插⼊数据要判满，删除数据要判空
  >
  > 插⼊删除有可能移动数据
  >
  > **顺序表中插入一个元素平均移动n/2次，删除一个元素平均移动(n-1)/2，两者的时间复杂度都是O（n）**

  ```c
  //1.建立顺序表
  void CreateList(SqList * &L，ElemType a[]，int n){ 
     L=(SqList *)malloc(sizeof(SqList));
     for(int i=0;i<n;i++)
         L->data[i]=a[i];
     L->length=k;
  }
  ```

  ```c
  //2.初始化线性表
  void InitList(SqList *&L){  
     L=(SqList *)malloc(sizeof(SqList));
  　　　　//分配存放线性表的顺序表空间
     L->length=0;
  }
  ```

  ```c
  //3.销毁
  void DestroyList(SqList *&L){
      free(L);
  }   
  ```

  ```c
  //4.判断空
  bool ListEmpty(SqList *L){
     return(L->length==0);
  }
  ```

  ```c
  //5.长度
  int ListLength(SqList *L){
       return(L->length);
  }
  ```

  ```c
  //6.输出
  void DispList(SqList *L){  
     int i;
     if (ListEmpty(L)) 
         return;
     for (i=0;i<L->length;i++)
        printf("%c"，L->data[i]);
     printf("\n");
  } 
  ```

  ```c
  //7.根据位序访问值
  bool GetElem(SqList *L，int i，ElemType &e){     
     if (i<1 || i>L->length)  //i是位序，所以最小是1，最大是length
         return false;
     e=L->data[i-1];
     return true;
  }  
  ```

  ```c
  //8.按元素值查找位序
  int LocateElem(SqList *L，ElemType e){  
     for(int i=0;i<L->length;i++)
         if(e==L->data[i])
             return i+1;
      return 0;
  }
  ```

  ```c
  //9.插入数据
  bool  ListInsert(SqList *&L，int i，ElemType e)
  {  int j;
     if (i<1 || i>L->length+1)
        return false;		//参数错误时返回false
     i--;				//将顺序表逻辑序号转化为物理序号
     for (j=L->length;j>i;j--)	//将data[i..n]元素后移一个位置
  	  L->data[j]=L->data[j-1];
     L->data[i]=e;		//插入元素e
     L->length++;		//顺序表长度增1
     return true;		//成功插入返回true
  }
  ```

  ```c
  //10.删除数据
  bool ListDelete(SqList *&L，int i，ElemType &e)
  {  int j;
     if (i<1 || i>L->length)	　	//参数错误时返回false
        return false;
     i--;					//将顺序表逻辑序号转化为物理序号
     e=L->data[i];
     for (j=i;j<L->length-1;j++)  	//将data[i..n-1]元素前移
  	L->data[j]=L->data[j+1];
     L->length--;			//顺序表长度减1
     return true;			//成功删除返回true
  }
  ```

## 链表

> 每个物理结点增加一个指向后继结点的指针域为单链表。
>
> 每个物理结点增加一个指向后继结点的指针域和一个指向前驱结点的指针域为双链表。
>
> 链表的存储是无序的，但是链表的查找还是得用顺序查找，叫做**顺序存取**

### 单链表

- 单链表的考察（存储密度）

  **存储密度=数据占用的空间/结点总占用空间**

- 定义

  ```c
  typedef int ElemType;
  typedef struct LNode{
  	ElemType data;
  	struct LNode * next;
  }LinkNode; //LNode强调的是结点，LinkNode强调的是链表
  ```

- 创建

  > 创建有头插法和尾插法
  >
  > 头插法可以同于链表的逆置。逆序
  >
  > 尾插法正序

  ```c
  //1.头插法
  void createlisthead(LinkNode *&L,ElemType a[],int n){
  	LinkNode *s;  //先创建单节点，在分别为链表L和每次新建的新节点分配空间
  	//大小分别是链表的大小和结点的大小
  	L=(LinkNode *)malloc(sizeof(LinkNode));
  	L->next=NULL;
  	for(int i=0;i<n;i++){
  		s=(LinkNode *)malloc(sizeof(LNode));
  		s->data=a[i];
  		s->next=L->next;
  		L->next=s;
  	}
  }
  //2.尾插法
  void createlisttail(LinkNode *&L,ElemType a[],int n){
  	LinkNode *s,*r;  //尾指针
  	L=(LinkNode *)malloc(sizeof(LinkNode));
  	L->next=NULL;
  	r=L;
  	for(int i=0;i<n;i++){
  		s=(LinkNode *)malloc(sizeof(LNode));
  		s->data=a[i];
  		r->next=s;
  		r=s;
  	}
  	r->next=NULL;
  }
  ```

- 初始化

  ```c
  void initlist(LinkNode *&L){
  	L=(LinkNode *)malloc(sizeof(LinkNode));
  	L->next=NULL;
  }
  ```

- 销毁

  ```c
  void destroylist(LinkNode *&L){
  	//销毁在于连头指针也要销毁
  	LinkNode *pre=L,*p=L->next;
  	while(p!=NULL){
  		free(pre);
  		pre=p;
  		p=p->next;
  	}
  	free(pre);
  }
  ```

- 判空

  ```c
  bool listempty(LinkNode *L){
  	return(L->next==NULL);
  }
  ```

- 输出

  ```c
  void displist(LinkNode *L){
  	LinkNode *p=L;
  	while(p->next!=NULL){
  		printf("%d,",p->next->data);
  		p=p->next;
  	}
  	printf("\n");
  }
  ```

- 求长度

  ```c
  int listlength(LinkNode *L){
  	int n=0;
  	LinkNode *p=L;
  	while(p->next!=NULL){
  		n++;
  		p=p->next;
  	}
  	return n;
  }
  ```

- 求第i个数据的值

  ```c
  bool getelem(LinkNode *L,int i,ElemType &e){
  	LinkNode *p=L->next;
  	if(i<=0)
  		return false;
  	for(int j=1;j<i;j++){
  		if(p==NULL)
  			return false;
  		p=p->next;
  	}
  	e=p->data;
  	return true;
  }
  //或者是（自写）
  bool getelem2(LinkNode *L,int i,ElemType &e){
  	LinkNode *p=L->next;
      int j=0;
  	if(i<=0)
  		return false;
  	while(p){
          j++;
  		if(j==i){
              e=p->data;
              return true;
          }
  		p=p->next;
  	}
  	return false;
  }
  ```

- 按元素值查找位置

  ```c
  int locatelist(LinkNode *L,ElemType e){
  	int i=1;
  	LinkNode *p=L->next;
  	if(p==NULL)
  		return false;
  	while(p->next!=NULL && e!=p->data){
  		i++;p=p->next;
  	}
  	if(e==p->data)
  		return i;
  	else 
  		return false;
  }
  ```

- 后插

  ```c
  bool insertlist(LinkNode *&L,int n,ElemType e){
  	LinkNode *p=L,*s;
  	int i;
  	if(n<1||n>listlength(L))
  		return false;
  	for(i=1;i<n && p->next!=NULL;i++){
  		p=p->next;
  	}
  	if(p->next==NULL)
  		return false;
  	else{
  		s=(LinkNode *)malloc(sizeof(LinkNode));
  		s->data=e;
  		s->next=p->next;
  		p->next=s;
  		return true;
  	}
  }
  //自写
  bool insertlist(LinkNode *&L,int n,ElemType e){
  	LinkNode *p=L->next,*pre=L,*s;
  	int i=0;
  	if(n<1||n>listlength(L))
  		return false;
  	while(p){
          i++;
          if(i==n){
          	s=(LinkNode *)malloc(sizeof(LinkNode));
              s->data=e;
              s->next=p;
              pre->next=s;
              return true;
          }
  		pre=p;
          p=p->next;
  	}
      return false;
  }
  ```

- 删除第i个位置的结点

  ```c
  bool deletelist(LinkNode *&L,int n,ElemType &e){
  	LinkNode *p=L,*q;//p是前指针，q是后指针，要free的
  	int i=0;
  	if(n<1)
  		return false;
  	while(i<n-1 && p->next!=NULL){
  		i++;
  		p=p->next;
  	}
  	if(p==NULL)
  		return false;
  	else{
  		q=p->next;
  		if(q==NULL)
  			return false;
  		e=q->data;
  		p->next=q->next;
  		free(q);
  		return true;
  	}
  }
  //自写
  bool deletelist(LinkNode *&L,int n,ElemType &e){
  	LinkNode *p=L->next,*pre=L;//p是前指针，q是后指针，要free的
  	int i=0;
  	if(n<1 || !p)
  		return false;
  	while(p){
          i++;
          if(i==n){
              e=p->data;
              pre->next=p->next;
              free(p);
              return true;
          }
          pre=p;
  		p=p->next;
  	}
      return false;
  }
  ```

### 双链表

> 与单链表大同小异，下面只写有区别的

- 定义

  ```c
  typedef int ElemType;
  typedef struct LNode{
  	ElemType data;
  	struct LNode * next,*prior;
  }LinkNode; 
  ```

- 创建

  > 创建有头插法和尾插法

  > **头插法可以同于链表的逆置。逆序**
  >
  > 尾插法正序

  ```c
  //1.头插法
  void createlist(LinkNode *&L,ElemType a[],int n){
  	LinkNode *s;
  	L=(LinkNode *)malloc(sizeof(LinkNode));
  	L->prior=L->next=NULL;
  	for(int i=0;i<n;i++){
  		s=(LinkNode *)malloc(sizeof(LNode));
  		s->data=a[i];
  		s->next=L->next;
  		if(L->next!=NULL)
  			L->next->prior=s;
  		s->prior=L;
  		L->next=s;
  	}
  }
  //2.尾插法
  void createlist2(LinkNode *L,ElemType a[],int n){
  	LinkNode *s,*r;
  	L=(LinkNode *)malloc(sizeof(LinkNode));
  	r=L;
  	for(int i=0;i<n;i++){
  		s=(LinkNode *)malloc(sizeof(LinkNode));
  		s->data=a[i];
  		r->next=s;
  		s->prior=r;
  		r=s;
  	}
  	r->next=NULL;
  }
  ```

- 初始化

  ```c
  void initlist(LinkNode *&L){
  	L=(LinkNode *)malloc(sizeof(LinkNode));
  	L->next=NULL;
  	L->prior=NULL;
  }
  ```

- 判空

  ```c
  bool listempty(LinkNode *L){
  	return(L->next==NULL && L->prior==NULL);
  }
  ```

### 静态链表

![](img/48.PNG)

### 刷题

#### 顺序表必刷

- [[合并两个有序数组](https://leetcode.cn/problems/merge-sorted-array/)](https://leetcode.cn/problems/kth-node-from-end-of-list-lcci/)

  ```c
  void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
      for (int i = 0; i != n; ++i) {
          nums1[m + i] = nums2[i];
      }
      int t;
      for(int j=0;j<n+m;j++){
          for(int i=0;i<n+m-1;i++){
          if(nums1[i+1]<nums1[i]){
              t=nums1[i];
              nums1[i]=nums1[i+1];
              nums1[i+1]=t;
          }
      }
      }
  }
  ```

- [排序数组](https://leetcode.cn/problems/sort-an-array/)

  ```c
  int* sortArray(int* nums, int numsSize, int* returnSize) {
      *returnSize = numsSize;
      int t;
      bool flag;
      for(int i=0;i<numsSize;i++){
          flag=false;
          for(int j=0;j<numsSize-1;j++){
              if(nums[j]>nums[j+1]){
                  t=nums[j];
                  nums[j]=nums[j+1];
                  nums[j+1]=t;
                  flag=true;  //如果有交换则退出
              }
          }
          //如果没交换表示已排好，退出
          if(!flag)
              break;
      }
      return nums;
  }
  ```

- [二分查找](https://leetcode.cn/problems/binary-search/)

  ```c
  int search(int* nums, int numsSize, int target) {
      int front=0,rear=numsSize-1,mid;
      // 思路：先取一个中间数，如果小则范围边0-中间，大则中间-大
      while(front<=rear){
          mid=(front+rear)/2;
          if(target<nums[mid])
              rear=mid-1;
          else if(target>nums[mid])
              front=mid+1;
          else
              return mid;
      }
      return -1;
  }
  ```

- [反转字符串](https://leetcode.cn/problems/reverse-string/)

  ```c
  void reverseString(char* s, int sSize) {
      int j,i=sSize-1;
      char c;
      for(j=0;j<sSize/2;j++){
          c=s[j];
          s[j]=s[i];
          s[i--]=c;
      }
  }
  ```

#### 链表必刷

- [返回倒数第 k 个节点](https://leetcode.cn/problems/kth-node-from-end-of-list-lcci/)

  ```c
  /**定义类型
   * struct ListNode {
   *     int val;
   *     struct ListNode *next;
   * };
   */
  //方法2.用双指针
  int kthToLast(struct ListNode* head, int k){
      //他这里的head是首结点
      if(head->next==NULL)  //当只有一个元素的时候，更快，且更省空间
          return head->val;
      struct ListNode *p=head,*pre=p;
      for(int i=0;i<k;i++){
          p=p->next;
      }
      while(p){
          p=p->next;
          pre=pre->next;
      }
      return pre->val;
  }
  ```

- [合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/)

  ```c
  struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
      if(!list1)
          return list2;
      else if(!list2)
          return list1;
      struct ListNode *list3=(struct ListNode *)malloc(sizeof(struct ListNode));
      // list3->next=NULL;   //malloc开辟了空间后，自动创建头结点，因此也就不用自己初始化了
      struct ListNode *l1=list1,*l2=list2,*p,*r=list3;
      while(l1&&l2){
          if(l1->val<l2->val){
              p=l1;
              l1=l1->next;
          }
          else{
              p=l2;
              l2=l2->next;
          }
          r->next=p;
          r=p;
      }
      if(l1){
          r->next=l1;
      }
      else if(l2){
          r->next=l2;
      }
      return list3->next;   //不能返回list3，会包括头指针进去
  }
  ```

- 反转链表

  ```c
  struct ListNode* reverseList(struct ListNode* head) {
      struct ListNode *p=head,*q=NULL,*next;
      while(p){
          next=p->next;
          p->next=q;
          q=p;  //第一次这里执行的时候，q就是拿到了头结点，所以最后返回的是q
          p=next;
      }
      return q;
  }
  ```

## 有序表

> **注意区分顺序表和有序表的概念：有序表要求数据是有序存放的，顺序表没有这个要求**
>
> 很显然，有序表是线性表的一个子集。
>
> 有序表也可以用顺序存储实现或链式存储实现

- 以顺序表存储有序表

  ```c
  void ListInsert(SqList *&L，ElemType e)
  {  int i=0，j;
     while (i<L->length && L->data[i]<e)
        i++;				//查找值为e的元素
     for (j=ListLength(L);j>i;j--)	//将data[i..n]后移一个位置
        L->data[j]=L->data[j-1]; 
     L->data[i]=e;
     L->length++;			//有序顺序表长度增1
  }
  ```

- 以单链表存储有序表

  ```c
  void ListInsert(LinkNode *&L，ElemType e)
  {  LinkNode *pre=L，*p;
  
     while (pre->next!=NULL && pre->next->data<e)
  	pre=pre->next; 	//查找插入结点的前驱结点pre
  
     p=(LinkNode *)malloc(sizeof(LinkNode));
     p->data=e;			//创建存放e的数据结点p
     p->next=pre->next;		//在pre结点之后插入p结点
     pre->next=p;
  }
  ```

- 重点应用：二路归并

  - 顺序

    ```c
    void UnionList(SqList *LA，SqList *LB，SqList *&LC)
    {  int i=0，j=0，k=0;	 //i、j分别为LA、LB的下标，k为LC中元素个数
       LC=(SqList *)malloc(sizeof(SqList)); 	//建立有序顺序表LC
       while (i<LA->length && j<LB->length)
       {  if (LA->data[i]<LB->data[j])
          {  LC->data[k]=LA->data[i];
    	  i++;k++;
          }
          else	       //LA->data[i]>LB->data[j]
          {  LC->data[k]=LB->data[j];
    	  j++;k++;
          }
      }   
         while (i<LA->length)	//LA尚未扫描完，将其余元素插入LC中
         {	LC->data[k]=LA->data[i];
    	i++;k++;
         }
         while (j<LB->length)	//LB尚未扫描完，将其余元素插入LC中
         {	LC->data[k]=LB->data[j];
    	j++;k++;
         }
         LC->length=k;
    }
    ```

  - 链式

    ```c
    void UnionList1(LinkNode *LA，LinkNode *LB，LinkNode *&LC)
    {  LinkNode *pa=LA->next，*pb=LB->next，*r，*s;
       LC=(LinkNode *)malloc(sizeof(LinkNode));	//创建LC的头结点
       r=LC;					//r始终指向LC的尾结点
       while (pa!=NULL && pb!=NULL)
       {  if (pa->data<pb->data)
          {  s=(LinkNode *)malloc(sizeof(LinkNode));  //复制结点
    	  s->data=pa->data;
    	  r->next=s;r=s;			//采用尾插法将s插入到LC中
    	  pa=pa->next;
          }
          else
          {  s=(LinkNode *)malloc(sizeof(LinkNode));   //复制结点
    	  s->data=pb->data;
    	  r->next=s;r=s;			//采用尾插法将s插入到LC中
    	  pb=pb->next;
          }
       }
       while (pa!=NULL)
       {  s=(LinkNode *)malloc(sizeof(LinkNode));    //复制结点
          s->data=pa->data;
          r->next=s;r=s;			//采用尾插法将s插入到LC中
          pa=pa->next;
       }
       while (pb!=NULL)
       {  s=(LinkNode *)malloc(sizeof(LinkNode));    //复制结点
          s->data=pb->data;
          r->next=s;r=s;			//采用尾插法将s插入到LC中
          pb=pb->next;
       }
       r->next=NULL			//尾结点的next域置空
    }
    ```

# 栈与队列

> 栈和队列是操作受限制的线性表

## 栈

> LIFO
>
> 栈的顺序存储结构入栈都是指针先，出栈都是指针后

### 顺序栈

> 演示：[Array Stack Visualization (usfca.edu)](https://www.cs.usfca.edu/~galles/visualization/StackArray.html)

- 定义：

  ```c
  typedef struct{ 
      Elemtype data[Maxsize]; 
      int top; 
  }SqStack;
  ```

  - **栈空（初始化）：s->top==-1**

  - **栈满：s->top==Maxsize-1**

  - 进栈：指针**先加**1

  - 出栈：**先取**出来，指针**再减**1


  > 注意看题目需求条件，也可以栈空从top==0开始，然后入栈就是后指针，出栈就是先指针
  >
  > n个元素的合法出栈序列个数**（卡特兰数）：**
  >
  > **Cn 2n/(n+1)      ==         An 2n/(n! * (n+1))**
  >
  > 例如n=4时，=8*7*6*5/(4! * 5)=14

- 各算法实现

  ```c
  void initlist(SqStack *&s){
  	s=(SqStack *)malloc(sizeof(SqStack));
  	//因为传入的是指针型s所以要用->的方式访问
  	s->top=-1;  //顺序栈初始化栈顶-1
  }
  void destroylist(SqStack *&s){
  //对于用顺序存储实现的即用数组实现的结构释放空间都是直接释放整个，不用逐一释放
  	free(s);
  }
  bool Stackempty(SqStack *s){
  	return (s->top==-1);
  }
  //进栈
  bool push(SqStack *&s,Elemtype e){
  	if(s->top==Maxsize-1)
  	//栈满
  		return false;
  	//入栈操作：先加后放
  	s->top++;
  	s->data[s->top]=e;
  	//上面两句等价于s->data[++s->top]=e;
  	return true;
  }
  //出栈
  bool pop(SqStack *&s,Elemtype &e){
  	if(s->top==-1){ 
  	//栈空
  		return false;
  	}
  	//出栈顺序：先出后减
  	e=s->data[s->top];
  	s->top--;
  	//等价于e=s->data[s->top--];
  	return true;
  }
  bool gettop(SqStack *s,Elemtype &e){
  	//栈空则取不出
  	if(s->top==-1)
  		return false;
  	e=s->data[s->top];
  	return true;
  }
  void displist(SqStack *s){
  	while(s->top!=-1){
  		printf("%d,",s->data[s->top--]);
  	}
  }
  ```

  > 因为入栈与出栈不需要移动表中元素，因此入栈出栈**时间复杂度都是O（1）**

### 顺序共享栈

> 是为了节省普通顺序栈中浪费的空间

- 定义：

  ```c
  typedef struct{ 
      Elemtype data[Maxsize]; 
      int top,top2; //top是左边下标从0开始的栈，top2是右边下标从Maxsize开始的栈 
  }SqStack;
  ```

  - 栈空（初始化）：栈1空为top1==-1；栈2空为top2==Maxsize

  - 栈满：**top1==top2-1**

  - 进栈：先动指针

  - 出栈：先取出来，再动指针

- 算法的实现：多了一个变量用来判断是对哪个栈进行操作，了解即可

### 链栈

> [Linked List Stack Visualization (usfca.edu)](https://www.cs.usfca.edu/~galles/visualization/StackLL.html)

- 定义：

  ```c
  typedef struct linknode{ 
      Elemtype data; 
      struct linknode *next; 
  }LinkStNode;
  ```

  - **栈空（初始化）：s->next==NULL**

  - 栈满：不会栈满

  - 进栈：新建结点**头插法**

  - 出栈：**取出第一个值**后删除结点

    > p=head->next;e=p->data;head->next=p->next;free(p);

  > 栈底存在时，栈底->next==NULL

- 各算法的实现

  ```c
  void initlist(LinkStNode *&s){
  	s=(LinkStNode *)malloc(sizeof(LinkStNode));
  	s->next=NULL;
  }
  void destroylist(LinkStNode *&s){
  	linknode *p=s->next,*q=s;
  	//销毁链表并不需要使头指针一直指向删除后的剩下的结点
  	while(p!=NULL){  //p为NULL时，q为尾节点
  		free(q);
  		q=p;  //指向删除节点的下一个节点
  		p=p->next;
  	}
  	free(q);  //一个个释放节点
  }
  bool Stackempty(LinkStNode *s){
  	return (s->next==NULL);
  }
  //因为链栈不会满，所以不用判定是否满了，所以用void
  void push(LinkStNode *&s,Elemtype e){
  	LinkStNode *p=(LinkStNode *)malloc(sizeof(linknode));
  	p->data=e;
  	p->next=s->next;
  	s->next=p;
  }
  bool pop(LinkStNode *&s,Elemtype &e){
  	if(s->next==NULL)
  		return false;
  	linknode *p=s->next;
  	e=p->data;
  	s->next=p->next;
  	free(p);
  	return true;
  }
  bool gettop(LinkStNode *&s,Elemtype &e){
  	if(s->next==NULL)
  		return false;
  	e=s->next->data;
  	return true;
  }
  
  void displist(LinkStNode *s){
  	linknode *p=s->next;
  	while(p!=NULL){
  		printf("%d,",p->data);
  		p=p->next;
  	}
  }
  ```

## 栈的应用

> - 括号匹配
> - 表达式求值
> - 递归
> - 求解迷宫
> - （二）进制转换
> - c语言中临时变量

- 判断字符串是否为对称串

  ```c
  bool symmetry(char str[]){
  	Elemtype e; //用来接收退栈的值来与字符串第一位开始比较
  	//什么时候需要自己定义结构指针？
  	//当题目没给你结构体指针时你需要自行定义并初始化结构
  	//或者是你需要自行把数据插进去时，就可以采用
  	
  	SqStack *s;  //定义顺序栈指针
  	initlist(s);
  	for(int i=0;str[i]!='\0';i++){
  		//先遍历一次字符串，将全部插入栈中
  		push(s,str[i]);
  	}
  	for(int i=0;str[i]!='\0';i++){
  		pop(s,e);
  		if(str[i]!=e){
  			//题目没要求销毁栈，但是判断已经完成，该栈无用了，故可以销毁掉
  			destroylist(s);  
  			return false;
  		}
  	}
  	destroylist(s);
  	return true;
  }
  ```

- 检查圆括号是否配对

  ```c
  bool check(char str[]){
  	int i=0;Elemtype e;
  	SqStack *s;  //定义顺序栈指针
  	initlist(s);
  	if(str[i]=='\0')
  		return false;
  	
  	while(str[i]!='\0'){
  		if(str[i]=='(')
  			push(s,'(');
  		else if(str[i]==')'){
  			gettop(s,e);
  			if(e=='('){
  				pop(s,e);
  				e='\0';  //用完e临时变量后清空
  			}
  			else
  				return false;
  		}
  		i++;
  	}
  	if(Stackempty(s)==1)
  		return true;
  	else
  		return false;
  }
  ```

- 表达式求值

  - 前缀表达式==先序遍历

  - **中缀表达式（加括号）==中序遍历**

  - 后缀表达式==后序遍历

    > 前缀表达式也叫波兰表达式，后缀表达式也叫逆波兰表达式
    >
    > **转换规则：转换后的运算数的相对位置不能变，但是运算符号可以改变位置，意味着一个中缀表达式可能有多个后缀表达式或前缀表达式。但如果按相同运算符等级从左到右则转换的结果唯一**
    >
    > 转化成后缀表达式后的运算符的从左到右的顺序就是原本中缀表达式中运算符的执行顺序
    >
    > 前缀：运算符在中缀表达式的操作数的前面；后缀：运算符在中缀表达式的操作数的后面；也就是遵循就近原则
    >
    > **如中缀：1+2*3**
    >
    > - **前缀：+1*2 3**
    > - **后缀：1 2 3 * +**

  - 核心算法：

    ```c
    void trans(char *exp,char postexp[]){
    	char e;
    	SqStack * Optr;
    	initlist(Optr);
    	int i=0;
    	while(*exp!='\0')
    	{
    		switch(*exp)
    		{
    			case '(':
    				push(Optr,'(');
    				exp++;  //字符串加1表示下一个字符的地址，即下一个字符
    				break;
    			case ')':
    				pop(Optr,e);
    				while(e!='(')
    				{
    					postexp[i++]=e;
    					pop(Optr,e);
    				}
    				exp++;
    				break;
    			case '+':
    			case '-':
    				while(!Stackempty(Optr))
    				{
    					gettop(Optr,e);
    					if(e!='(')
    					{
    						postexp[i++]=e;
    						pop(Optr,e);
    					}
    					else
    						break;
    				}
    				push(Optr,*exp);
    				exp++;
    				break;
    			case '*':
    			case '/':
    				while(!Stackempty(Optr))
    				{
    					gettop(Optr,e);
    					if(e=='*'||e=='/')
    					{
    						postexp[i++]=e;
    						pop(Optr,e);
    					}
    					else
    						break;
    				}
    				push(Optr,*exp);
    				exp++; 
    				break;
    			default:
    				while(*exp>='0'&&*exp<='9')
    				{
    					postexp[i++]=*exp;
    					exp++;
    				}
    				postexp[i++]='#';
    		}
    	}
    	while(!Stackempty(Optr))
    	{
    		pop(Optr,e);
    		postexp[i++]=e;
    	}
    	postexp[i]='\0';
    	destroylist(Optr);
    }
    ```

    > 后缀表达式是从左到右入栈
    >
    > 前缀表达式是从右到左入栈

## 队列

> FIFO
>
> **入动rear**
>
> **出动front**

### 顺序队

> [Array Queue Visualization (usfca.edu)](https://www.cs.usfca.edu/~galles/visualization/QueueArray.html)

- 定义：

  ```c
  typedef struct{ 
      elemtype data[Maxsize]; 
      int rear,front;  //头指针和尾指针的下标 
  }SqQueue;
  ```

  - 初始化：q->rear=q->front**=-1**

  - **队空：q->front==q->rear**

    > **不一定==-1**

  - 队满：q->rear==Maxsize-1

  - **入队：++rear**

  - **出队：++front**


  > 如果题目要求初始化从0开始，那么入队出队都是后指针
  >
  > 注：**front始终是首节点的前一个位置**
  >
  > 队的所有入队出队都是先动下标（指针）后放（拿）数据
  >
  > 有n个空间的队列最多只能执行n次入队，有n个空间的循环队列，最多只能执行n-1次入队

- 算法实现

  ```c
  void initQueue(SqQueue *&q){
  	q=(SqQueue *)malloc(sizeof(SqQueue));
  	q->rear=q->front=-1;
  }
  void destroyQueue(SqQueue *&q){
  	free(q);
  }
  bool emptyQueue(SqQueue *q){
  	return q->front==q->rear;
  }
  bool enQueue(SqQueue *&q,elemtype e){
  	//先判断是否队满
  	if(q->rear==Maxsize-1)
  		return false;
  	q->rear++;
  	q->data[q->rear]=e;
  	//等价于q->data[++q->rear]=e
  	return true;
  }
  bool deQueue(SqQueue *&q,elemtype &e){
  	//先判断队是否为空
  	if(q->rear==q->front)
  		return false;
  	e=q->data[++q->front];
  //注意区别：顺序队入队出队都是先动指针后动元素
  //而栈是入栈先动指针，出栈先动元素
  	//q->front++;
  	//e=q->data[q->front];
  	return true;
  }
  void dispQueue(SqQueue *q){
  	while(q->rear!=q->front){
  		q->front++; 
  		printf("%d,",q->data[q->front]);
  	}
  }
  ```

  > 因为入与出操作都不需要移动表中元素，因此入和出的**时间复杂度都是O（1）**

### 顺序循环（环形）队

> 避免空间浪费
>
> **循环队，那一定就是顺序存储的队，且该队的操作要取余（除了rear）**

- 定义：

  - **初始化：q->front=q->rear=0**


    - **队空：q->rear==q->front**

      > 那么初始化状态也算做队空
      >
      > **但是队空不一定是0位置**


    - **队满：(q->rear+1)%Maxsize==q->front**

      > **队尾指针正好在队头指针的后一位，则队满**
      >
      > **浪费掉一个空间，用来区分队空与队满**


    - **入队：q->rear=(q->rear+1)%Maxsize**


    - **出队：front=(front+1)%Maxsize**


- 在尾指针头指针和元素个数中仅有两个的情况

  - **元素个数：count=(rear-front+Maxsize)%Maxsize**

  - **队头位置：front=(rear-count+Maxsize)%Maxsize**

    > **只要有减号-，那就是需要加上Maxsize再取整的**

  - **队尾位置：rear=(front+count)**

    > 注：front始终是首节点的前一个位置
    >
    > **只有加号+，没有减号-，则与Maxsize无关，不用Maxsize**

- 代码：

  ```c
  bool enQueue(SqQueue *&q,elemtype e){
  	//先判断是否队满
  	if((q->rear+1)%Maxsize==q->front)
  		return false;
  	q->rear=(q->rear+1)%Maxsize;
  	q->data[q->rear]=e;
  	return true;
  }
  bool deQueue(SqQueue *&q,elemtype &e){
  	//先判断队是否为空
  	if(q->rear==q->front)
  		return false;
  //注意区别：顺序队入队出队都是先动指针后动元素
  //而栈是入栈先动指针，出栈先动元素
  	q->front=(q->front+1)%Maxsize;
  	e=q->data[q->front];
  	return true;
  }
  ```

### 链队

- 定义：

  ```c
  //定义单链表的结构 
  typedef struct qnode{ 
      elemtype data; 
      struct qnode *next; 
  }Datanode;  //表示单链表结点 
  //定义链队的结构 
  typedef struct{ 
      Datanode *front; Datanode *rear; 
  }LinkquNode;  //表示链队结点
  ```

  - 初始化：q->front=q->rear=NULL

  - 队空：q->rear==NULL **或** q->front==NULL

  - 队满：不存在

  - 入队：分配结点，尾插入链表中（链表为空要特殊处理），动尾指针

  - 出队：动头指针（只有一个元素要特殊处理），拿出数据，释放节点空间

  - 判断**链队只有一个结点：q->front==q->rear!=NULL**


  > 注：若用无头结点的单链表实现，且此时front指向首节点，默认是头节点

- 代码：

  ```c
  //链队的实现就是：入队用尾插法插入单链表表尾
  //出队就是把头节点的后一位拿掉并释放空间，并使头节点指向头节点后两位
  
  //数据操作：初始化、销毁、判断空、进队、出队
  void initqueue(LinkquNode *&q){
  	q=(LinkquNode *)malloc(sizeof(LinkquNode));
  	q->rear=q->front=NULL;
  }
  bool emptyqueue(LinkquNode *q){
  	return q->rear==NULL;//q->front也行
  }
  void enqueue(LinkquNode *&q,elemtype e){
  	Datanode *p;
  	p=(Datanode *)malloc(sizeof(Datanode));
  	p->data=e;
  	p->next=NULL;
  	if(q->rear==NULL)  //链表为空要特殊处理
  		q->front=q->rear=p;
  	else{
  		q->rear->next=p;
  		q->rear=p;
  	}
  }
  bool dequeue(LinkquNode *&q,elemtype &e){
  	Datanode *p=q->front;
  	if(p==NULL)
  		return false;
  	if(q->front==q->rear)  //当队列仅有一个数据结点时
  		q->front=q->rear=NULL;
  	else  //当正常情况下
  		q->front=p->next;
  	e=p->data;
  	free(p);
  	return true;
  }
  void destroyqueue(LinkquNode *&q){
  	//这里定义的是单链表中的单个结点，这样才能有data和next
  	Datanode *pre=q->front,*p; //pre指向队首结点
  	while(pre!=NULL){
  		p=pre;
  		pre=pre->next;
  		free(p);
  	}
  	free(q);
  }
  void dispqueue(LinkquNode *q){
  	Datanode *p=q->front;
  	while(p!=NULL){
  		printf("%d,",p->data);
  		p=p->next;
  	}
  }
  ```

## 队列的应用

> - 求解报数问题
> - 求解迷宫问题
> - 层次遍历
> - 计算机系统的应用
> - 缓冲区
> - 页面替换算法

## 栈与队列的区别

|              | 栈                        | 队列              |
| ------------ | ------------------------- | ----------------- |
| 主要区别     | 仅关心top，完全不用管栈底 | 即有rear也有front |
| **入操作先** | **指针**                  | **rear动**        |
| **出操作先** | **先数据**                | **front动**       |



# 树与二叉树

- 通用概念

> 树是⼀个递归概念（有且仅有⼀个根节点，其余节点互不相交，每个集合本⾝⼜是⼀棵树）
>
> 要掌握树的树形表示法和**括号表示法**
>
> **路径长度：是通过的结点数-1**
>
> **树的度：树中结点最大的度称为树的度**

- 树的表示方法

  - 树形表示法（主要的）

  - 文氏图表示法

  - 凹入表示法

  - 括号表示法（代码）

    ![](img/44.png)

## 树和森林

### 树的性质（重点）

1. **树总结点树=度之和+1=分支节点总和+1**

   > **度之和=分支结点度数=0\*n0+1\*n1+2\*n2...**

2. **第i层最多有m^(i-1)个结点**

3. **高度为h的m次树的总结点最多为(m^h-1)/(m-1)**

   > **一定要记得高度h的总结点个数还有除数的**

4. **具有n个结点的m次树的最小高度为logm(n*(m-1)+1)  （上取整）**

### 树的遍历

1. 先根遍历

   > =森林的先根遍历=二叉树的先序遍历
   >
   > 这里的意思是先转换成对应的树|二叉树在进行遍历的序列相同

2. 后根遍历

   > =森林的后根遍历=**二叉树的中序遍历**

3. 层次遍历

   > =图的广度优先遍历

### 树的存储结构

1. 双亲存储

   ```c
   typedef struct{
   	elemtype data;  //结点的值
   	int parent;  //双亲的位置
   }ptree[Maxsize];  //为双亲存储结构类型
   ```

2. 孩子链存储

   ```c
   typedef struct node{
   	elemtype data;
   	struct node *sons[Maxsons];  //指向孩子结点，表示每个结点最多的度数
   }TSonNode;
   ```

   > **空域：指针个数-分支个数=n*m-(n-1)**

   - 设计一个求树t高度的递归算法：

     ```c
     int treeheight(TSonNode * t){
     	TSonNode *p;
     	int i,h,maxh=0;
     	if(t==NULL)
     		return 0;
     	for(i=0;i<Maxsons;i++){    //p指向t的第i+1个孩子结点
     		p=t->sons[i];
     		if(p!=NULL){
     			h=treeheight(p);  //求对应子树的高度
     			if(maxh<h)
     				maxh=h;
     		}
     	}
     	return (maxh+1);  //返回树的高度
     }
     ```

3. 兄弟链存储

   ```c
   typedef struct tnode{
   	elemtype data;
   	struct tnode *hp;  //指向兄弟
   	struct tnode *vp;  //指向孩子结点
   }TsbNode;
   ```

   > 最重要，用于实现树与二叉树的互相转换
   >
   > **左孩子右兄弟**
   >
   > **空域：指针个数-分支个数=2n-(n-1)=n+1**
   >
   > 👆因为一个节点就两个指针，相当于孩子链中m次树为2的情况

   - 设计一个求树t高度的递归算法：

     ```c
     int treeheight2(TsbNode *t){
     	TsbNode *p;
     	int h,maxh=0;
     	if(t==NULL)
     		return 0;
     	p=t->vp;   //p指向第1个孩子结点
     	while(p!=NULL){
     		h=treeheight2(p);
     		if(maxh<h)
     			maxh=h;
     		p=p->hp;  //继续处理其他兄弟，即其他子树
     	}
     	return(maxh+1);
     }
     ```

## 二叉树

### （完全）二叉树的性质

> 叶子结点仅有可能在最后两层出现

1. **n0=n2+1**
2. **n2=n0-1**
3. **n=2n2+1=2n0-1**
4. **.i层最多有2^(i-1)个结点**
5. **深度为k的⼆叉树⾄多有2^k - 1个结点**
6. **具有n个结点的完全⼆叉树的深度为log2(n)向下取整+1**
7. **n为奇数时，n1=0；n为偶数时，n1=1（因为n0+n2为奇数）**
8. 如果对⼀棵有n个结点的完全⼆叉树，可以通过⽗节点求⼦⼥结点，也可以通过⼦⼥结点 求⽗节点，不过**要注意，根节点的编号是从0开始还是从1开始**。下面计层序编号为i
   - **若i<=n/2，则i为分支结点，否则是叶子结点**
   - **若i有左孩子，则左孩子编号是2i，右孩子为2i+1**

### 二叉树遍历

1. **先序（前缀表达式）**

   > 第一个是根节点。若有左右子树，则第二个是左子树根节点，第三个是右子树根节点

   - 递归算法：

     ```c
     void preOrder(btNode *b){
     	if(b!=NULL){
     		printf("%c",b->data);  //访问结点
     		preOrder(b->lchild);  //递归左子树
     		preOrder(b->rchild);  //递归右子树
     	}
     }
     ```

2. 中序（中缀表达式（要加括号））

   > 若有左右子树，则根节点在中间，左右子树在两边

   递归算法：

   ```c
   void inOrder(btNode *b){
   	if(b!=NULL){
   		inOrder(b->lchild);  //递归左子树
   		printf("%c",b->data);  //访问结点
   		inOrder(b->rchild);  //递归右子树
   	}
   }
   ```

3. 后序（后缀表达式）

   > 最后一个是根结点

   递归算法：

   ```c
   void postOrder(btNode *b){
   	if(b!=NULL){	
   		postOrder(b->lchild);  //递归左子树
   		postOrder(b->rchild);  //递归右子树
   		printf("%c",b->data);  //访问结点
   	}
   }
   ```

4. 层次遍历

   > 非递归
   >
   > 借助环形队列



> 先序中序后序非递归遍历需要用到临时栈

### 二叉树和树和森林的转换

> 只用知道以下四种情况，树和森林间的转换就是增加一个根或删去一个根

1. **二叉树转树**

   > 孩子左兄弟右：孩子在左边，兄弟在右边

   ![](img/09.png)

   > 规则：
   >
   > 1. 二叉树的左孩子是树中该结点（该左孩子的双亲）的最左孩子（第一个孩子）
   > 2. 二叉树的右孩子是树中该结点（该右孩子的双亲）的一个兄弟
   >
   > 要求：**根节点必须无右孩子，否则就是转成森林了**
   >
   > 方法：
   >
   > 1. 将所有有右孩子的线左转45°
   > 2. 去掉兄弟之间的线，并连上各自的双亲

2. **二叉树转森林**

   > 孩子左兄弟右，并且**根兄弟要切断**

   ![](img/10.png)

   > 规则：
   >
   > 1. 二叉树的左孩子是树中该结点（该左孩子的双亲）的最左孩子（第一个孩子）
   > 2. 二叉树的右孩子是树中该结点（该右孩子的双亲）的一个兄弟
   >
   > 要求：**根节点一定要有右子树，否则就是树了**
   >
   > 方法：
   >
   > 1. 将所有有右孩子的线左转45°
   > 2. 去掉兄弟之间的线，并连上各自的双亲

3. **树转二叉树**

   > 第一棵子树（如果有的话）作为左孩子，下一个兄弟（如果有的话）作为右孩子
   >
   > **第一棵子树作为左孩子，下一个兄弟作为右孩子**

   ![](img/11.png)

   > 方法：
   >
   > 1. 兄弟结点之间连接条虚线，并把所有的非最左结点（右结点）的线删去
   > 2. 将兄弟的线右转45°

4. **森林转二叉树**

   ![](img/12.png)

   >方法：
   >
   >1. 兄弟结点**（根节点）之间连接条虚线**，并把所有的非最左结点（右结点）的线删去
   >2. 将兄弟的线右转45°

### 二叉树的存储结构

1. 顺序存储

   ```c
   typedef char elemtype;
   //课本上二叉树的顺序存储定义如下
   typedef elemtype sqBinTree[Maxsize];
   ---------------------------------------------
   //王道上二叉树的顺序存储定义如下
   struct TreeNode{
   	elemtype value;
   	bool isempty;  //结点是否为空
   };
   TreeNode t[Maxsize];  //定义一个长度为Maxsize的数组t，按照从上至下、从左至右的顺序依次存储完全二叉树中的各个结点
   ```

2. 二叉链表

   ```c
   typedef char elemtype;
   //二叉链表存储定义及各操作的实现
   typedef struct node{
   	elemtype data;
   	struct node *lchild;
   	struct node *rchild;
   }btNode;
   ```

   > **n+1个空域**

3. 三叉链表

   ```c
   typedef char elemtype;
   //二叉链表存储定义及各操作的实现
   typedef struct node{
   	elemtype data;
   	struct node *lchild;
   	struct node *rchild;
       struct node *parent;
   }btNode;
   ```

   > **3n-2(n-1)=n+2个空域**

### 二叉树的构造

1. **先序遍历序列+中序遍历序列画出二叉树**

   用先序第一个确认根的位置，在中序中找到根，左边是左子树，右边是右子树，继续递归确认

2. **后序遍历序列+中序遍历序列画出二叉树**

   用后序最后一个确认根的位置，在中序中找到根，左边是左子树，右边是右子树，继续递归确认

3. **层次遍历序列+中序遍历序列画出二叉树**

   用层次第一个确认根的位置，在中序中找到根，左边是左子树，右边是右子树，继续递归确认

## 线索二叉树

> 充分利用二叉链表的空域：
>
> - 左空则指向其前驱
> - 右空则指向其后继

## 二叉排序树

> 详细见树表查找篇章
>
> 方便搜索的一种树
>
> 左子树放小的，右子树放大的

## 平衡二叉树

> 要求左右子树的高度差最多是1

## 堆

大根堆或小根堆

![](img/13.png)

> 堆是一颗完全二叉树，采用数组顺序存储，有大小堆之分
>
> 堆又叫优先级队列
>
> 优先级队列是完全⼆叉树 + 堆的规则（⼤⼩根堆）

## 哈夫曼树

- 构造（重点）：

  1. **每次拿最小的两个结点合并成一个新结点（最多合并n-1次）**

  2. **再循环拿两个最小的结点（选过的不能再选），第一步构造的新结点也可以选中**

     > 因此需要结合n-1次

- **带权路径计算（重点）：**

  1. **找出所有叶子结点**
  2. **计算各个叶子结点的路径长度\*叶子结点的权值**
  3. **将2式相加，有几个叶子结点就有几项**

> **哈夫曼树共有2n0-1=2n2+1个结点，且没有度为1的结点**
>
> 分支结点n-1=2n0-2
>
> huffman树是带权路径**WPL（Weighed Path Length**）最⼩的树，也称最优树。当哈夫曼树的度大于2时，就运用到了外存中的排序，叫最佳归并树

- 哈夫曼编码（前缀编码）

  > huffman树的**左树编码为0，右树编码为1（左小右大）**，则每⼀个叶⼦结点将得到唯⼀的编码，即为 huffman编码，也叫做前缀编码
  >
  > 所谓前缀编码就是指，任何一个编码都不是另一个编码的前缀
  >
  > **哈夫曼树的字符个数=叶子结点个数**
  >
  > **哈夫曼树的字符长度+1=哈夫曼树的最大高度**
  >
  > **注意区分字符长度和字符个数！注意区分字符长度和字符个数！注意区分字符长度和字符个数！**

- 哈夫曼树的应用就是压缩存储空间

## 并查集

> 对两个集合的合并、查找操作
>
> 并查集采用双亲存储实现

# 图

## 图的基本概念

图（Graph）G由顶点集合V(G)和边集合E(G)构成。   

> **图不可以为空，至少要有一个顶点**，顶点集非空，**只有边是可以空的**

- 图的表示

  - 无向图：

    e={(1,2),(1,3),(1,0),(2,3),(3,0),(2,4)}

  - 有向图：

    e={<1,2>,<1,3>,<0,1>,<2,3>,<0,3>}

  > 无向图用()表示，可以颠倒顺序。无向图边成为边
  >
  > 有向图用<>表示，从左指向右，表示左边的出边是右边，不可颠倒。有向图边成为弧
  >
  > 有向图中所有顶点的入度之和等于所有顶点的出度之和。

- **边与度的关系**

  **边数e=n个顶点的度之和 / 2**

  > 即：n个顶点的度之和为边数的两倍

- **完全图（顶点n与边e的关系）**

  > 完全图指的是所有的顶点均和其他顶点有边（不仅仅是连通而已，是直接边）。有向图则要同时存在方向相反的两条弧

  - **无向完全图**中，每两个顶点之间都存在着一条边，**此时边数最多**，称为完全无向图， 最多有***e=n*(*n*-1)/2条边**。

  - **有向完全图**中，每两个顶点之间都存在着方向相反的两条边，**此时边数最多**，称为完全有向图，最多有***e=n*(*n*-1)条边。**

- 稠密图与稀疏图

  - 稠密图：接近完全图，边多
  - 稀疏图：边少

- 子图

  子图要求选取的顶点子集与边子集在父图中能连得通

- 连通

  - 无向图：顶点i到顶点j有路径，叫做**连通图**

    > 对于无向图，边的**取值范围为0到n(n-1)/2**, 如果图有n(n-1)/2条边，则⽆向称为图称⽆向完全 图，

  - 有向图：顶点i到顶点j有去和来两条路径，叫**强连通图**

    > 对于有向图，边的**取值范围为0到n(n-1)**, 如果图有n(n-1)条边，则称向图称为有向完全图，在 有向完全图中任意两个顶点之间都存在⽅向相反的两条弧
    >
    > ⼀个顶点的⼊度为0、其余顶点的⼊度均为1的有向图，称为有向树

  - 不连通：在（极大）连通分量上多＋一个顶点

- **连通图、连通分量（无向）**

  > 若无向图中任意两个顶点都连通（不一定有直接边），则称为连通图，否则称为非连通图
  >
  > > 因此连通图与无向完全图的关系是：连通图真包含于无向完全图
  >
  > 无向图G中的**极大连通子图**称为G的**连通分量**。显然，任何连通图的连通分量只有一个，即本身，而非连通图有多个连通分量。
  >
  > 如果只有一个顶点（没有边），那么此时该顶点也叫做连通分量
  >
  > **一个有n个顶点的图，最少有1个连通分量,最多又n个连通分量**

  - 实现**n个顶点的无向连通图至少n-1条边**

    > 无向连通图的最少边数，就是**生成树**
    >
    > 若再＋一条边，形成n个顶点n条边，则一定有环
    >
    > 那么显然：
    >
    > - 生成树，n-1条边
    > - 非连通图：<n-1条边

  - 只有非连通图才有可能有多个连通分量

  - **e条边的非连通图的顶点最少=连通图的顶点+1 即：边数e*=n*(n-1) /2    **

    > **求出e条边所构成的完全图n后＋1**

    > 非连通图的边数最少是n-1，并且有n+1个顶点（自推）

- **强连通图、强连通分量（有向图）**

  > 若有向图中任意两个顶点都连通（不一定有直接弧），则称为**强连通图**，否则称为非强连通图。
  >
  > > 因此强连通图与有向完全图的关系是：强连通图真包含于有向完全图
  >
  > 有向图G中的**极大强连通子图**称为G的**强连通分量**。
  >
  > 强连通图只有一个强连通分量，即本身。非强连通图有多个强连通分量。

  - 实现有**向连通图至少n条边**

  - **n个顶点的强连通图（有向图）至少有n条边**

    > 上述两都是形成了环，这样就连通了

## 图的存储结构及基本算法

### 邻接矩阵

> **顺序存储**

- 概念

> **对角线都是0**
>
> **关于对角线对称，因此顶点为n阶矩阵的n，边为主对角线以上的1的个数**
>
> 需要会根据图画出邻接矩阵
>
> 连通的话是权值（若是不带权的图，则**默认是1**）
>
> 无穷表示不连通

![](img/01.png)

> 一个图的邻接矩阵表示是唯一的。
>
> 特别适合于稠密图的存储。
>
> 邻接矩阵的存储空间为O(*n*2)

- 类型定义

  ```c
  #define  MAXV  <最大顶点个数>	
  #define INF 9999999999
  typedef char InfoType;
  typedef struct   //定义每个顶点内部存放的结构
  {  int no;			//顶点编号
     InfoType info;		//顶点其他信息
  } VertexType;
  typedef struct  		//以邻接矩阵存储的图的定义
  {  int edges[MAXV][MAXV]; 	//邻接矩阵
     int n，e;  			//顶点数，边数
     VertexType vexs[MAXV];	//存放顶点信息
  }  MatGraph;
  ```

- 矩阵的地址求法

  > 源自邻接矩阵是顺序存储形式，所以是以a[n]\[m]的方式表示的

  ​	矩阵中是**按行优先的顺序存储的**。也就是说，二维数组的第一行的所有元素会先于第二行的所有元素被存储，第二行的所有元素会先于第三行的所有元素被存储，以此类推。

  ​	给定一个 m x n 的二维数组 a，其首元素（即 a[0]\[0]）的基地址是 BASE，那么元素 a[i][j] 的地址可以通过以下公式计算：

  ```c
  Address of a[i][j] = BASE + ((i * n) + j) * size
  ```

  > - i * n : 这是前 i 行元素的总数量。
  > - j : 是第 i 行中，a[i][j] 前面的元素数量。
  > - (i * n) + j : 这是 a[i][j] 元素在二维数组中的位置（从 0 开始计数）。
  > - ((i * n) + j) * size ：由于每个元素可能会占用多于一个字节的空间（如 int 类型通常会占用4个字节），我们需要将元素在数组中的位置乘以它所占用的空间大小，来得到相对于 BASE 的偏移量。

### 邻接表

- 概念

> 采用的是**顺序存储＋链式存**储的方式实现
>
> 用一个数组作为头结点表示每个顶点，然后每个数组内部都有个指针，指向连接的结点
>
> 边界点算的是出度
>
> **需要会根据图画出邻接表，不关于主对角线对称，顶点为n阶矩阵的n，边数为邻接表中1的个数**

![](img/02.png)

> 邻接表表示不唯一。
>
> 特别适合于稀疏图存储。   
>
> 邻接表的存储空间为O(*n*+*e*)

- 类型定义

```c
typedef struct ANode    //边结点类型的定义
{  int adjvex;			//该边的终点编号
   struct ANode *nextarc;	//指向下一条边的指针
   InfoType weight;		//该边的权值等信息
}  ArcNode;

typedef struct Vnode     //表头结点类型的定义
{  Vertex data;		//顶点信息
   ArcNode *firstarc;		//指向第一条边
}  VNode;

typedef struct   //邻接表的实现
{  VNode adjlist[MAXV];	//用表头结点类型创建数组
   int n，e;			//图中顶点数n和边数e
} AdjGraph;
```

- 创建图

  ```c
  void CreateAdj(AdjGraph *&G，int A[MAXV][MAXV]，int n，int e) 
  //创建图的邻接表
  {  int i， j;
     ArcNode *p;
     G=(AdjGraph *)malloc(sizeof(AdjGraph));
     for (i=0;i<n;i++)	     //给邻接表中所有头结点的指针域置初值
        G->adjlist[i].firstarc=NULL;
     for (i=0;i<n;i++)		   		//检查邻接矩阵中每个元素
       for (j=n-1;j>=0;j--)
  		if (A[i][j]!=0 && A[i][j]!=INF)	     	//存在一条边
  		{  p=(ArcNode *)malloc(sizeof(ArcNode));	//创建一个结点p
             p->adjvex=j;			     	//存放邻接点
             p->weight=A[i][j];		 	     	//存放权
             p->nextarc=G->adjlist[i].firstarc; //采用头插法插入结点p
             G->adjlist[i].firstarc=p;
  		}
     G->n=n; G->e=e;
  }
  
  ```

- 输出图

  ```c
  void DispAdj(AdjGraph *G)	//输出邻接表G
  {  int i;
     ArcNode *p;
     for (i=0;i<G->n;i++)
     {  p=G->adjlist[i].firstarc;
        printf("%3d: "，i);
        while (p!=NULL)
        {  printf("%3d[%d]→"，p->adjvex，p->weight);
  	  p=p->nextarc;
        }
        printf("∧\n");
     }
  }
  ```

- 逆邻接表

> 将边界点算作入度即可

### 十字链表

> 对于**有向图**的另一种存储结构，它是**邻接表和逆邻接表的结合**。

![](img/03.png)

![](img/04.png)

### 邻接多重表

> 邻接多重表是无向图的另外一种存储结构，与十字链表类似。
>
> 与无向图的邻接表相比，对图的边的操作（标记或删除）更便利。

![](img/05.png)

![](img/06.png)

## 图的遍历

> 注意区分树的层次遍历、先根遍历、后根遍历
>
> 二叉树的先中后序遍历

### 深度优先遍历DFS

> **优先遍历从某个结点出发的有最深层次的结点，层次必须递增，若到底则回到第二层的其他结点继续深度遍历**
>
> 深度优先遍历相当于⼆叉树中的**前序遍历**
>
> **邻接表求遍历序列：看到一条可以走（没有走过)路径就直接走下去，没有道路时回退 **

#### 算法

```c
void DFS(AdjGraph *G，int v)  //邻接表实现，实现主要都是用邻接表
{  ArcNode *p; int w;
   visited[v]=1; 		//置已访问标记
   printf("%d  "，v); 		//输出被访问顶点的编号
   p=G->adjlist[v].firstarc; 	//p指向顶点v的第一条边的边头结点
   while (p!=NULL) 
   {  w=p->adjvex;
      if (visited[w]==0) 
         DFS(G，w);   		//若w顶点未访问，递归访问它
      p=p->nextarc; 　		//p指向顶点v的下一条边的边头结点
   }
}
```

> 深度优先遍历的过程体现出后进先出的特点：用**栈或递归**方式实现。
>
> 如何确定一个顶点是否访问过? 设置一个visited[] 全局数组， visited[*i*]=0表示顶点*i*没有访问； visited[*i*]=1表示顶点*i*已经访问过。
>
> 该算法的时间复杂度为O(*n*+*e*)。

#### 遍历次序（重要）

要点：

- **若有多条路，先选权值小的那条路**

- **掌握由一个图写出深度优先遍历序列**

  如下图，若从2出发，下一步可以选1或者6，但要先去小的，所以先去1；然后以1为出发点可以去2（去过）或者5，访问5，5没有可以访问的了；然后回到2，这次从6开始，去3，然后3又可以去4，再去7，8，遍历完成。

- **掌握由一个邻接表写出深度优先遍历序列（重点）**

  **邻接表**写出深度优先遍历序列的要点在于**要看邻接表里的**，因为邻接表里多条路，**并不一定是选权值最小的**

  如下图，若从2出发，下一步选1，然后跳到1的那一行，2被访问了，那就去5；跳5那一行，没东西了，返回2那一行；访问下一个6，6的行可以选3（没被选中过）...以此类推，**被选过的就要跳过去**

  > 秘诀：**访问一个，就到它的行去接着访问别的，若没有，则一步步向上返回**

![38](img/38.PNG)

### 广度优先遍历BFS

#### 算法

> 类似于层次遍历，距离起始结点近的先访问完，再访问离更远的
>
> **要会从邻接表的图来写出遍历序列**
>
> **邻接表求遍历序列：考虑每一条可以走（没有走过)的路径，尝试走每条道路**

```c
void BFS(AdjGraph *G，int v)
{  int w， i;
   ArcNode *p;
   SqQueue *qu;			//定义环形队列指针
   InitQueue(qu);			//初始化队列
   int visited[MAXV];        		//定义顶点访问标记数组
   for (i=0;i<G->n;i++) 
     visited[i]=0;	  		//访问标记数组初始化
   printf("%2d"，v); 			//输出被访问顶点的编号
   visited[v]=1;             		//置已访问标记
   enQueue(qu，v);
   while (!QueueEmpty(qu))       		//队不空循环
   {  deQueue(qu，w);				//出队一个顶点w
      p=G->adjlist[w].firstarc; 		//指向w的第一个邻接点
      while (p!=NULL)				//查找w的所有邻接点
      {  if (visited[p->adjvex]==0)		//若当前邻接点未被访问    
         {  printf("%2d"，p->adjvex);		//访问该邻接点
            visited[p->adjvex]=1;		//置已访问标记
            enQueue(qu，p->adjvex);		//该顶点进队
         }
         p=p->nextarc;              		//找下一个邻接点
      }
    }
    printf("\n");
}
```

> 广度优先搜索遍历体现先进先出的特点，用**队列**实现。
>
> 对于连通图，调用一次DFS或BFS，能够访问到图中的所有顶点
>
> 无向非连通图：调用一次DFS或BFS，只能访问到初始点所在连通分量中的所有顶点，不可能访问到其他连通分量中的顶点。
>
> **所以非连通图，需要调用连通分量个数次的DFS或BFS才能遍历所有结点**

#### 遍历次序（重要）

要点：

- **若有多条路，先选权值小的那条路**

- **掌握由一个图写出广度优先遍历序列**

  如下图，若从2出发，下一步可以选1或者6，但要先去小的，所以先去1，再去6；然后以1或6为出发点可以去3、5或者7，访问5（因为上一级1比较小），然后3、7；然后以5、3、7为起点访问其他的，遍历完成。

- **掌握由一个邻接表写出广度优先遍历序列（重点）**

  **邻接表**写出深度优先遍历序列的要点在于**要看邻接表里的**，因为邻接表里多条路，**并不一定是选权值最小的**

  如下图，若从2出发，下一步将该层全访问完1、6，然后跳到1的那一行，访问改行，2被访问了，那就去5，第二行的1访问完毕；之后回到2行，访问6，还是一样，跳过去，访问一行先，然后再往里深入...以此类推，**被选过的就要跳过去**

![39](img/39.PNG)

> 秘诀：先把一层的都访问遍，再挨个往里钻

## 最小生成树

> 从4-8都属于图的应用
>
> 可以先数一下有多少个顶点，因此边数为定点数-1

### 生成树概念

一个连通图的生成树是一个**极小连通子图**，它含有图中全部n个顶点和构成一棵树的**(n-1)**条边。　

**生成树是图用某种遍历方式所形成的，所以每个结点只会被访问一次，不能重复走，但必须每个结点都走完**

> 可以看出生产树的概念是针对无向图而言的，而无向图中连通的最低要求就是要有n-1条边，所以说生成树是极小连通子图
>
> 注意：连通分量是极大联通子图，一个极大一个极小，注意区分　
>
> 由广度优先遍历得到的生成树称为广度优先生成树。
>
> 由深度优先遍历得到的生成树称为深度优先生成树。
>
> **生成树是可以没有权值的，极小生成树必须要有权值**
>
> 边数=顶点数-1
>
> 树形不唯一，边和权值之和唯一

- 最小生成树（MST）：边上的权值之和最小的生成树

### 普里姆（Prim）算法

> **选择最近的点，后连接边**
>
> **要求：不能形成回路**（本质：不能重复访问结点）
>
> 找挨着最近的点连起来，并将连起来的点加入集合中，之后按照集合里周围单位1 的范围进行查找

- 步骤：

  （1）初始化U={v}。v到其他顶点的所有边为候选边；

  （2）重复以下步骤n-1次，使得其他n-1个顶点被加入到U中：

   ①从候选边中挑选权值最小的边输出，设该边在V-U中的顶点是k，将k加入U中；

   ②考察当前V-U中的所有顶点j，修改候选边：若(j，k)的权值小于原来和顶点k关联的候选边，则用(k，j)取代后者作为候选边。

![](img/07.png)

- 算法

  ```c
  #define INF 32767		//INF表示∞
  void  Prim(MatGraph g，int v)
  {  int lowcost[MAXV];
     int min;
     int closest[MAXV]，i，j，k;
     for (i=0;i<g.n;i++)	//给lowcost[]和closest[]置初值
     {	lowcost[i]=g.edges[v][i];
  	closest[i]=v;
     }
    for (i=1;i<g.n;i++)	  	//输出(n-1)条边
    {  min=INF;
       for (j=0;j<g.n;j++) 	//在(V-U)中找出离U最近的顶点k
  	if (lowcost[j]!=0 && lowcost[j]<min)
  	{  min=lowcost[j];
  	   k=j;			//k记录最近顶点编号
  	}
       printf(" 边(%d，%d)权为:%d\n"，closest[k]，k，min);
       lowcost[k]=0;		//标记k已经加入U
      for (j=0;j<g.n;j++)  //修改数组lowcost和closest
       if (lowcost[j]!=0 && g.edges[k][j]<lowcost[j])
       {  lowcost[j]=g.edges[k][j];
          closest[j]=k;
       }
     }
  }
  ```

  > Prim()算法中有两重for循环，所以时间复杂度为O(n2)。 

### 克鲁斯卡尔（Kruskal)

> **选择最小的边，后画点**
>
> **要求：不能回路**
>
> 找边最小的一条，然后将两个点连起来，如果这两点已经连通了，则不要这条边，去找另外小的一条

- 步骤：

  （1）置U的初值等于V（即包含有G中的全部顶点），TE的初值为空集（即图T中每一个顶点都构成一个连通分量）。

  （2）将图G中的边按权值从小到大的顺序依次选取：

     若选取的边未使生成树T形成回路，则加入TE；

     否则舍弃，直到TE中包含(n-1)条边为止。

  ![](img/08.png)

- 算法：

  ```c
  //用邻接矩阵来实现
  typedef struct 
  {  int u;     	//边的起始顶点
     int v;     	//边的终止顶点
     int w;   	//边的权值
  } Edge; 
  Edge E[MAXV];
  void Kruskal(MatGraph g)
  {  int i，j，u1，v1，sn1，sn2，k;
     int vset[MAXV];
     Edge E[MaxSize];		//存放所有边
     k=0;				//E数组的下标从0开始计
     for (i=0;i<g.n;i++)	//由g产生的边集E
       for (j=0;j<g.n;j++)
          if (g.edges[i][j]!=0 && g.edges[i][j]!=INF)
  	 {  E[k].u=i;  E[k].v=j;  E[k].w=g.edges[i][j];
  	    k++;
  	 }
     InsertSort(E，g.e);		//用直接插入排序对E数组按权值递增排序
     for (i=0;i<g.n;i++) 	//初始化辅助数组
  	vset[i]=i;
    k=1;				//k表示当前构造生成树的第几条边
    j=0;				//E中边的下标，初值为0
    while (k<g.n)		//生成的边数小于n时循环
    { 
       u1=E[j].u;v1=E[j].v;	//取一条边的头尾顶点
       sn1=vset[u1];
       sn2=vset[v1];		//分别得到两个顶点所属的集合编号
       if (sn1!=sn2)  		//两顶点属于不同的集合
       {  printf("  (%d，%d):%d\n"，u1，v1，E[j].w);
          k++;		   	//生成边数增1
          for (i=0;i<g.n;i++)  	//两个集合统一编号
             if (vset[i]==sn2) 	//集合编号为sn2的改为sn1
  		vset[i]=sn1
       }
       j++;			//扫描下一条边
    }
  }
  
  ```

  > Kruskal算法的时间复杂度为O(elog2e)
  >
  > **改进：堆排序、并查集**

  

## 最短路径

### 迪杰斯特拉（Dijkstra）求单源最短路径

> 类似线代里的矩阵求最短路径

![34](img/34.png)

### 弗洛伊德（Floyd）求各顶点之间最短路径问题

![35](img/35.png)

## 有向无环图描述表达式（节省空间）

![36](img/36.png)

## 拓扑排序

- 有向无环图（DAG图）
- 顶点表示活动的网络（AOV）网
- 拓扑排序（DAG图中）

![37](img/37.png)

## 关键路径

### 概念

- 开始顶点（源点）：仅有一个入度为0的顶点
- 结束顶点（汇点）：仅有一个出度为0的顶点
- 关键路径：具有最大路径长度的路径
- 关键活动：关键路径上的活动
- 最短时间：关键路径的长度

### 几个变量

- **1.事件vn的最早发生时间Ve（n）**

  **通过从源点开始，找出每条到达汇点的每条路径，最后取最大值max**

- **2.事件Vn的最迟发生事件Vl（n）**

  **通过汇点逆向回去源点，最后取出最小值min**

- **3.活动Ai的最早发生时间e（i）**

  **=Ve（n）**

- 活动Ai的最迟发生时间l（i）

  l=Vl-权值c

- c路径长

  Ai的权长

- 活动的差额d（i）

  d=l-Ve

### 关键路径计算

> - **d=0  ==  Vl-c-Ve=0  ==  逆序-权长-正序=0**

# 查找

![](img/14.PNG)

> 本节是⼀个重要的专题，也是拉开分数的地⽅，掌握好本章的内容是能够考⾼分的 
>
> - 掌握数组顺序查找：顺序查找、折半查找 
> - 掌握树形结构查找：BST、AVL、RB、B、B+ (重点) 
> - 掌握字典查找：hashTable 
> - ⼀定要会分析平均查找⻓度（这是考试的重点和难点）

## 概念

### 动态、静态、内、外查找

1. 动态查找：查找同时修改（插入、删除）
2. 静态查找：只查找不修改
3. 内查找：旨在内存进行
4. 外查找：需要访问外存

### ２-平均查找长度ASL（重点）

\- Age Search Length，这是衡量查找 算法效率的重要指标

![](img/15.PNG)

> n是表的⻓度，pi是查找第i个数据元素的概率，如果概率相等，则pi=1/n, ci是找到第i个数据 元素所需⽐较的次数。
>
> asl越小，效率越高

## 线性表查找

### 顺序查找

> 从头到尾或从尾到头

```c
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
```

> 也可以链式，只是不够顺序好

![](img/16.PNG)

### 折半（二分）查找

- 顺序表描述

> 要求是有序表，最好是顺序表，但也可以是链式

```c
//二分查找（升序）
int binSearch(rectype r[],int n ,keytype k){
	int low=0,high=n-1,mid;
	while(low<=high){
		mid=(low+high)/2;  //相当于向下取整
		if(k==r[mid].key)
			return mid+1;  //逻辑序号序号加1
		if (k<r[mid].key)
			high=mid-1;
		else
			low=mid+1;
	}
	return 0;  //如果while没有ruturn则没找到，返回0
}
```

- 二叉树描述折半查找

  此时叫**判定树或比较树**，显然，判定树是一颗平衡二叉排序树（AVL）

  > 平衡二叉树证明：当元素个数为偶数时，mid可以选择上取整和下取整。选上取整则右子树始终比左子树多1或0个；选下取整则左子树始终比右子树多1或0个，因此构成了平衡二叉树
  >
  > **失败结点个数为元素个数+1，因为n个结点相当于分成了n+1个区间，用数学的直线划分区间来理解**
  >
  > **需要会手动画出判定树、比较树**
  >
  > 如下图：
  >
  > ![41](img/41.png)

- 判定树，比较树

![](img/17.png)

> 新增的叶子结点叫做外部结点，用于计算**失败的平均查找长度**，计算方式：**（（到达外部结点经过的边数）*该层个数）累计求和/外部结点个数**
>
> 判定树里存在的结点叫做内部结点，用于计算**成功的平均查找长度，计算方式**：**（第i层*第i层的内部结点个数）累计求和/内部结点个数**
>
> **折半查找的最大查找次数=判定树的最大高度=log2n（下取整）+1 | log2（n+1）（上取整）**
>
> 折半查找的时间复杂度 为：**O(log2n)**

![](img/18.png)

### 分块（索引）查找

- 概念

  1. 分块查找又称索引顺序查找，它吸取了顺序查找和折半查找各自的优点，既有动态结构，又 适于快速查找。 

  2. 分块查找的基本思想：将查找表分为若干子块。块内的元素可以无序，但块间的元素是有序 的，即第一个块中的最大关键字小于第二个块中的所有记录的关键字，第二个块中的最大关键字 小于第三个块中的所有记录的关键字，以此类推。再建立一个索引表，索引表中的每个元素含有 各块的最大关键字和各块中的第一个元素的地址，索引表按关键字有序排列。 **即将n个数据的表分成b块，每一块再分成s列**

  3. 分块查找的过程分为两步：**第一步**是在索引表中确定待查记录所在的块，可以顺序查找或折半查找索引表；**第二步**是在块内顺序查找（只能）。

     ![](img/19.png)

     > **因此索引查找最好的情况都需要查找两次**
     >
     > 算法实现不需要掌握

- 平均查找长度

  1. 顺序查找

     ![](img/20.PNG)

     > **但s=根号n时，ASL取极小值根号n+1**
     >
     > 例题：对于10000个元素的文件，用分块查找，最佳的元素个数s是100个，总的块数b=100，ASL=101

  2. 折半查找

     ![](img/21.PNG)

     > 当s越小时，ASL值越小

  > **分块查找的缺点就是增加一个索引表的存储空间和增加建立的时间**
  >
  > 如果分块查找采用链式存储，则可以实现动态搜索表

## 树表查找

### 二叉排序树BST

- 据二叉排序树的定义，**左子树结点值 < 根结点值 < 右子树结**

> **对⼆叉树进⾏中序遍历，将得到从小到大的排序顺序**
>
> ⼆叉搜索树最⼤的功劳在于：规定了节点的位置，因此针对BST可以有效实现查找、插 ⼊、删除，**让树形结构可以进⾏动态调整**
>
> **具有n个内部结点的二叉排序树，其外部结点个数为n+1**
>
> 平均执行时间或者ASL=**O（log2（n））**
>
> 二叉排序树中的查找路径是原来二叉排序树的一部分，也一定构成一棵二叉排序树。

- n个关键字构成的不同二叉排序树有多少棵？

  答：需要用到卡特兰数，就是出栈序列个数那个：C(n，2n)/(n+1)

  如4个关键字，则有14棵树

- 算法

  1. 类型定义

     ```c
     typedef int keytype;
     typedef char infotype;
     typedef struct node{
     	keytype key;
     	infotype data;
     	struct node *lchild,*rchild;
     }bstNode;
     ```

  2. 插入

     ​	需保证插入后，仍然满足排序树需求。用到了递归，当子树为空时就会插入，如果在左边就递归左边插入，在右边就递归右边插入

     ```c
     bool insertBst(bstNode *&bt,keytype k){
     	if(!bt){
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
     ```

  3. 创建

     ```c
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
     ```

  4. 查找（非递归）

     ```c
     bstNode *searchBst(bstNode *bt,keytype k){
     	while(!bt && bt->key==k){
     		if(k<bt->key)
     			bt=bt->lchild;
     		else
     			bt=bt->rchild;
     	}
         return bt;
     }
     ```

  5. 查找（递归）

     ```c
     bstNode *searchBst2(bstNode *bt,keytype k){
     	if(!bt && bt->key==k)
     		return bt;
     	if(k<bt->key)
     		return searchBst2(bt->lchild,k);
     	else
     		return searchBst2(bt->rchild,k);
     }
     ```

  6. 删除

     算法思想

     1. 考虑p是叶子：**直接删**
     2. 考虑p只有左子树：**左子树代替**
     3. 考虑p只有右子树：**右子树代替**
     4. 考虑p同时有左右子树：**拿左子树最大或者右子树最小的**

     ```c
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
     ```

  7. 输出

     ```c
     //递归输出排序树（中序）
     void dispBst(bstNode *bt){
     	if(bt){
     		dispBst(bt->lchild);
     		printf("%d,",bt->key);
     		dispBst(bt->rchild);
     	}
     }
     ```

### 平衡二叉树AVL

定义结点**左子树与右子树的高度差为该结点的平衡因子**，则平衡 二叉树结点的**平衡因子**的值只可能是**-1、1或0**

#### 插入结点

> 插入结点可能导致平衡二叉树不平衡，因此每次调整的对象都是最小不平衡子树，即以插入路径上离插入结点最近的平衡因 子的绝对值大于1的结点作为根的子树

1. LL插入（**右旋**+移右叶到左）

   1. **将最小不平衡子树的左孩子移到根**
   2. **将原本的根移到新根的右孩子**
   3. **将新根原本的右孩子移到原根的左孩子**

   > 在最小不平衡子树的左子树的左分支插入结点，使平衡二叉树不平衡

2. RR插入（**左旋**+移左叶到右）

   1. **将最小不平衡子树的右孩子移到根**
   2. **将原本的根移到新根的左孩子**
   3. **将新根原本的的左孩子移到原根的右孩子替换**

   > 在最小不平衡子树的右子树的右分支插入结点，使平衡二叉树不平衡
   >
   > LL和RR是对称的

   ![22](img/22.PNG)

3. LR插入(**左旋**+移左叶到右+**右旋**+移右叶到左)

   1. **将最小不平衡子树的左孩子的右孩子移到根**
   2. **将原根的左孩子移到新根的左孩子**
   3. **将原根移到新根的右孩子**
   4. **将新根原本的左孩子移到新根的左孩子的右分支**
   5. **将新根原本的右孩子移到原根的左分支**

   ![23](img/23.PNG)

   > 在最小不平衡子树的左子树的右分支插入结点，使平衡二叉树不平衡

4. RL插入(**右旋**+移右叶到左+**左旋**+移左叶到右)

   1. **将最小不平衡子树的右孩子的左孩子移到根**
   2. **将原根的右孩子移到新根的右孩子**
   3. **将原根移到新根的左孩子**
   4. **将新根原本的左孩子移到新根的左孩子的右分支**
   5. **将新根原本的右孩子移到新根的右孩子的左分支**

   ![24](img/24.PNG)

   > 在最小不平衡子树的右子树的左分支插入结点，使平衡二叉树不平衡

   > **以上四种方式记忆：看第二的字母，左就右旋，右就左旋；然后看第一个字母，如果相同则结束，不相同则相反的操作**

#### 删除结点（了解）

1. 删除结点（同二叉排序树一样）
2. 一路向上找到最小不平衡子树
3. 找出最小不平衡子树下高度最高的儿子和孙子
4. 根据孙子的位置，左右旋（LL、RR、LR、RL）
5. 如果调整完，上面的出现不平衡现象，继续执行2

### 红黑树（RBT）

> 红黑树首先是二叉排序树
>
> AVL是比BST多了个平衡因子，而RBT是比BST多了红黑的颜色

| 操作 | BST    | AVL            | Red-Black Tree(RBT) |
| ---- | ------ | -------------- | ------------------- |
| 查   | O（n） | O（log2（n）） | O（log2（n））      |
| 插   | O（n） | O（log2（n）） | O（log2（n））      |
| 删   | O（n） | O（log2（n）） | O（log2（n））      |

> 平衡二叉树：适用于以查为主、很少插入、删除
>
> 红黑树：适合频繁插入、删除、实用性更强

#### 定义

​	为了保持AVL树的平衡性，插入和删除操作后，非常频繁地调整全树整体拓扑结构，代价 较大。为此在AVL树的平衡标准上进一步放宽条件，引入了红黑树的结构。

 一棵红黑树是满足如下红黑性质的二叉排序树：

- ①**每个结点或是红色，或是黑色的。** 
- **②根结点是黑色的。** 
- **③ 叶结点（虚构的外部结点、NULL结点）都是黑色的。**
- **④ 不存在两个相邻的红结点（即红结点的父结点和孩子结点均是黑色的）。**
- ⑤ **对每个结点，从该结点到任意一个叶结点的简单路径上，所含黑结点的数量相同.** 

​	与折半查找树和B树类似，为了便于对红黑树的实现和理解，引入了 n+1个外部叶结点

![](img/25.PNG)

#### 性质

​	从某结点出发（不含该结点）到达一个叶结点的任意一个简单路径上的黑结点总数称为该结 点的**黑高（记为bh）,黑高的概念是由性质⑤确定的。根结点的黑高称为红黑树的黑高**

1. 从根到叶结点的最长路径不大于最短路径的2倍
2. 有n个内部结点的红黑树的高度h<=21og2（n + l）

#### 插入

![](img/26.PNG)

### B树

​	所谓m阶B树是所有结点的平衡因子均等于（完全平衡）。

的m路平衡查找树。

 一棵成阶B树或为空树，或为满足如下特性的巾叉树: 

- 树中每个结点至多有m棵子树，即至多含有m-1个关键字。 

- 若根结点不是叶结点，则至少有两棵子树。 

- 除根结点外的所有非叶结点至少有「m/2棵子树]，即至少含有「m/2]-1个关键字。 

- 所有非叶结点的结构如下：

  ![27](img/27.png)

### B+树

​	B+树是应数据库所需而出现的一种B树的变形树。 

一棵m阶的B+树需满足下列条件: 

- 1）每个分支结点最多有所棵子树（孩子结点）。

- 2）非叶根结点至少有两棵子树，其他每个分支结点至少有「m/2】棵子树。 

- 3）结点的子树个数与关键字个数相等。

- 4）所有叶结点包含全部关键字及指向相应记录的指针，叶结点中将关键字按大小顺序排列， 并且相邻叶结点按大小顺序相互链接起来。 

- 5）所有分支结点（可视为索引的索引）中仅包含它的各个子结点（即下一级的索引块）中 关键字的最大值及指向其子结点的指针。

  ![28](img/28.png)

> B树与B+树的主要差异：
>
> |                               | m阶B树                                           | m阶B+树                            |
> | ----------------------------- | ------------------------------------------------ | ---------------------------------- |
> | n个关键字的结点含有的子树数量 | n+1                                              | n                                  |
> | 每个结点的关键字n的范围       | (m/2)上取整-1<=n<=m-1                            | (m/2)上取整<=n<=m                  |
> | 叶节点                        | 终端结点包含的关键字和其他结点的关键字是不重复的 | 非叶结点的关键字也会出现在叶结点中 |
> | 所有非叶结点                  | 每个关键字对于一个记录的存储地址                 | 起到索引的作业                     |
>
> B+树的应用：关系型数据库如mysql的索引

### B*树

![41](img/41.png)

## 散列（哈希）查找 - HashTable

### 概念

1. 哈希表

   通过哈希函数，直接对关键字进⾏**映射**访问的表就称为哈希表

   散列函数可能会把两个或两个以上的不同关键字映射到同一地址，称这种情况为**冲突**，这些 发生碰撞的不同关键字称为**同义词**。一方面，设计得好的散列函数应尽量减少这样的冲突；另一 方面，由于这样的冲突总是不可避免的，所以还要设计好处理冲突的方法。

   ![](img/29.png)

2. hashTable需要解决的两个问题

   1. 映射函数 --- **hash函数** (除留余数法)
   2. **冲突解决** --- （开放地址法、链地址法）

3. 影响哈希表查找的因素：

   1. 装填因子：已存入的元素数n与哈希地址空间大小m的比值，即**a=n/m**；越小，冲突可能性越小
   2. 所采用的哈希函数
   3. 出现哈希冲突时采取的解决办法
   4. 存入的元素特性（如连续的一串、奇数、偶数...）

### 哈希函数的构造方法

#### 直接定址法

以关键字k本身加上某个常量c作为哈希地址：**h(k)=k+c**

如：*h*(学号) = 学号-201001001

> **适用于关键字分布的连续**，否则将造成大量浪费

#### 除留余数法

用关键字k除以某个**不大于哈希表长度m的素数p**所得的余数作为哈希地址

**h(k)=k % p  (p<=m)**

> 关键在于选p
>
> p一般用的是最靠近m的素数

#### 数字分析法

![30](img/30.png)

#### 平方取中法

​	**取关键字的平方值的中间几位作为散列地址**。具体取多少位要视实际情 况而定。这种方法得到的散列地址与关键字的每位都有关系，因此使得散列地址分布比较均匀， 适用于关键字的每位取值都不够均匀或均小于散列地址所需的位数。 

​	在不同的情况下，不同的散列函数具有不同的性能，因此不能笼统地说哪种散列函数最好。 在实际选择中，采用何种构造散列函数的方法取决于关键字集合的情况，但目标是尽量降低产生 冲突的可能性。

### 哈希冲突的解决办法

#### 开放定址法（主流）

1. 线性探测法

   **di=(d0+i) mod m   （i=1,2,3...）**

   **只能往后去找，一次往后一位**，如果到末尾就从头开始

![31](img/31.png)

![32](img/32.png)

2. 平方探测法

   **di=(d0 +|- i^2) mod m    （1<=i<=m-1）**

   **往前或往后去找，迈的步子越来越大**

   ![42](img/42.png)

> **两种方法总结：就是当前位置有人了，需要每次往后一步（往前往后，步子更大）的去找空位**

#### 拉链法

拉链法就是把所有的冲突同义词用单链表连起来，哈希表的地址对应的是单链表的首结点

![33](img/33.png)

### 除留余数画出哈希表

​	假设哈希表长度*m*=13，采用除留余数法哈希函数建立如下关键字集合的哈希表： 

   (16，74，60，43，54，90，46，31，29，88，77)。 

并采用线性探查法解决冲突。

|     **下标**     | **0**  | **1** | **2**  | **3**  | **4**  | **5**  | **6**  | **7**  | **8**  | **9**  | **10** | **11** | **12** |
| :--------------: | :----: | :---: | ------ | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: |
|      **k**       | **77** |       | **54** | **16** | **43** | **31** | **29** | **46** | **60** | **74** | **88** |        | **90** |
| **成功探查次数** | **2**  |       | **1**  | **1**  | **1**  | **1**  | **4**  | **1**  | **1**  | **1**  | **1**  |        | **1**  |
|   失败探查次数   | **2**  | **1** | **10** | **9**  | **8**  | **7**  | **6**  | **5**  | **4**  | **3**  | **2**  | **1**  | **3**  |

### 拉链法画出哈希表

- 查找成功asl计算

  ![46](img/46.png)

- 查找失败asl计算

  ![47](img/47.png)

  

# 排序

> 排序可视化网站：
>
> [Comparison Sorting Visualization (usfca.edu)](https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html)

- 排序的稳定性

  - 相同关键字的元素，排序后，这些相同的关键字的元素位置没有发生改变，就称这种**排序方法是稳定**的。
  - 相同关键字的元素，排序后，这些相同的关键字的元素位置发生了改变，就称这种**排序方法是不稳定**的。

- 内排序和外排序

  外排序会相对较慢

## 插入排序

> 每次将一个待排序的元素按其关键字大小插入到前面已经排好序的有序区中的适当位置，直至全部插入完成

### 直接插入排序（增量法）

思想：左边分为有序区，右边分为无序区，初始化i=1，每次将一个新的元素插入到有序区的合适位置

```c
//直接插入排序,我的
void insertSort(rectype R[],int n){
	int i=1,temp,k;
	for(;i<n;i++){   //若是0或1个则不执行
		if(R[i-1].key>R[i].key){
			temp=R[i].key;  
			//将前面大于的往后移
			k=i-1;    //升序的前一项
            for(;k>=0;k--){
                if (temp<R[k]);
                	R[k+1]=R[k];
                else
                    break;   //不需要排序
            }
			R[k+1].key=temp;
		}
	}
}
//课本
void insertSort2(rectype R[],int n){
	int i=1,temp,k;
	for(;i<n;i++){   //若是0或1个则不执行
		if(R[i-1].key>R[i].key){
			temp=R[i].key;  
			//将前面大于的往后移
			k=i-1;    //升序的前一项
			do{
				R[k+1]=R[k];  
				k--;
			}
			while(R[k].key>temp && k>=0);
			R[k+1].key=temp;
		}
	}
}
```

> 时间：O（n^2）
>
> 空间：O（1）

### 折半插入排序

直接插入排序是用顺序比较去找插入的位置，这边是采用折半查找去找插入的位置，再移动元素插入

```c
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
			for(k=i-1;k>=high+1;k--)  								// high+1==low
				R[k+1]=R[k];
			R[high+1].key=temp;
		}
	}
}
```



> 仅减少了查找位置（比较）次数
>
> 时间：O（n^2）
>
> 空间：O（1）

### 希尔排序（Shell Sort）

​	实际上是一种分组插入方法。

​	思想：取一个小于n的整合d1作为第一个增量，把表的全部元素分成d1个组，将所有距离为d1的倍数的元素放在同一个组中，对这一个组进行插入排序；然后取第二个增量d2，继续；直到d=1之后，最所有的元素再进行一次插入排序，算法完毕。

> **思路就是：从局部的一点点有序（看起来）到最后的完全有序**

![40](img/40.png)

```c
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
```

> d1一般取n/2...然后n/4...以此类推
>
> **d表示的是两个数据之间的距离，也表示分成几组，比如说d=1就是整个表分成一组就是表示整个表**
>
> 也称为减少增量的排序方法
>
> 时间：O（n^1.3）
>
> 空间O（1）
>
> **仅用于顺序表，不能用链表**
>
> **不稳定的**
>
> > 哈希（散列）存储结构、哈希查找、希尔排序、哈希函数容易搞混，注意区分：哈希是查找的，希尔是插入排序的

## 交换排序

> 两两比较，交换次序

### 冒泡排序

```c
void swap(int &x,int &y){
	int temp=x;x=y;y=temp;
}
//冒泡排序（从后往前.每次最小放前面）
void bubbleSort(rectype R[],int n){
	int i,j,flag=1;
	for(i=0;i<n;i++){  
		for(j=n-1;j>i;j--){
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
	for(i=n-1;i>=0;i--){  //每次将最小的放前面
		for(j=0;j<i;++j){
			if(R[j].key>R[j+1].key){
				swap(R[j].key,R[j+1].key);
				flag=0;
			}
		}
		if(flag)
			break;
	}
}
```

> 可以采用链表实现
>
> **稳定的**

### 快速排序

- 基本思想：

  在待排序内的n个元素中任取一个元素（一般就是第一个元素）作为基准，把该元素放入适当位置后，数据序列被此元素划分成两部分，所有小的放前面，大的放后面，并把该元素排在这两部分的中间（称为该元素的归位），这个过程称为一趟快速排序（不完全＝一趟划分）。之后再对左右划分出来的进行快速排序，实际上就是一个递归

  > **注意快排代码：这里是low<high为的是找到low=high的点进行插入；而二分查找是low<=high是为了找到low=high+1的low点进行插入，注意区分**

  ```c
  //快速排序（王）
  int partition(rectype r[],int low,int high){
  	int pivot=r[low].key;   //pivot是基准、枢轴的意思，这里每次让第一个元素作为基准
  	while(low<high){   //找出low=high的枢轴位置
          //从high先还是low先都是一样的，这边是以high先走
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
  ```

  > 代码（递归）：重要
  >
  > **不稳定的** 
  >
  > 空间：O（nlog2n）。其中**n为递归层数**
  >
  > 时间：O（log2n)
  >
  > > 与希尔排序O（n*log2（n））的比较：当n>2.5时，快排优势，小于时，希尔优势
  >
  > 优化：每次选的枢轴尽量可以划分均匀的两部分
  >
  > 1. 选头、中、尾三个数据元素，选中间值作为枢轴元素
  > 2. 随机选一个元素作为枢轴元素
  >
  > ```c
  > //快速排序（优化）--选择mid作为基准
  > void quickSort2(rectype r[],int low,int high){
  > 	int mid,pivot;
  > 	mid=(low+high)/2;
  > 	if(low<high){
  > 		if(mid!=low)//若基准不是区间中的第一个元素，将其与第一个元素交换
  > 			swap(r[mid].key,r[low].key); //可能是懒得搞了，把基准放去low的位置，统一操作 
  > 		pivot=partition(r,low,high);
  > 		quickSort2(r,low,pivot-1);
  > 		quickSort2(r,pivot+1,high);
  > 	}
  > }
  > ```

## 选择排序

> 每一趟从待排序元素中选出关键字最小（最大）的元素，放在子表最后，直至完成

### 简单选择（直接选择）排序

> 分为有序区与无序区，有点类似冒泡

```c
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
```

> 链表也可以
>
> 不稳定

### 堆排序

堆排序是一种树形选择排序方法

> 堆是一颗完全二叉树，采用数组顺序存储，有大小根堆之分
>
> 堆又叫优先级队列
>
> 优先级队列是完全⼆叉树 + 堆的规则（⼤⼩根堆）
>
> 左孩子2i，右孩子2i+1
>
> 父节点i/2(下取整)

- 实现大根堆的算法（下标从1开始）

  ```c
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
  ```

- 实现对大根堆排序的算法

  ```c
  //堆排序的建立，每次根（最大的）和最后一个元素交换，这样每次选出最大的放末尾，就形成了升序
  void heapSort(rectype r[],int n){
  	createHeap(r,n);
  	for(int i=n;i>=2;i--){  //进行n-1躺堆排序，每一趟堆中元素个数减1
  		swap(r[1].key,r[i].key);  //将最后一个元素和根交换
  		sift(r,1,i-1);
  	}
  }
  ```

> **大根堆进行堆排序后产生的是降序序列，小根堆进行堆排序后产生的是升序序列**
>
> 时间复杂度：**O（nlog2n）**
>
> 空间复杂度：O（1）
>
> - 小根堆只需改动sift即可
>
>   ```c
>   void sift2(rectype r[],int i,int len){ 
>   	r[0]=r[i];   
>   	for(int j=2*i;j<=len;j*=2){
>   		if(j<len && r[j].key>r[j+1].key)  //如果右孩子更小
>   			j++;   //也就只需改动两个if的大于小于号即可
>   		if(r[0].key>r[j].key){  
>   			r[i]=r[j];  
>   			i=j;
>   		}
>   		else 
>   			break;
>   	}
>   	r[i]=r[0];
>   }
>   ```

- 下标从0开始的大根堆排序

  ```c
   void sift3(int* nums,int i,int len){
  	 int temp=nums[i];  //nums[0]=nums[i]
  	 for(int child=i*2+1;child<len;child=i*2+1){  //child=i*2;child<=len;chile*=2)
  	     if(child<len-1 && nums[child]<nums[child+1])  //child<len
  	        child++;
  	    if(temp>nums[child])  //nums[0]>=nums[left]
  	        break;
  	    else{
              nums[i]=nums[child];
              i=child;
          }
  	 }
  	 nums[i]=temp;  //=nums[0]
  }
  void heapsort(int* nums,int n){
       for(int i=n/2-1;i>=0;i--)  //i=n/2,i>=1
          sift3(nums,i,n);
      for(int i=n-1;i>=1;i--){  //i=n;i>=2
          int temp=nums[0];   //0都是1
          nums[0]=nums[i];
          nums[i]=temp;
          sift3(nums,0,i);  //sift3(nums,1,i-1)
      }
   }
  ```

- 堆中插入新元素：对于小根堆，新元素放到表尾，与其父节点比较，小则一路上升，直至无法上升为止

- 堆中删除元素：被删除的元素用堆底元素替代，让该元素不断下坠

  > 只有一个孩子下坠：只用对比一次关键字
  >
  > 两个孩子下坠：对比两次关键字

## 归并排序

​	归并排序是多次将两个或两个以上的有序表合成一个新的有序表。一般内排序都是用的二路归并排序，即二路归并；而外排序才是k路归并排序

- 算法思想

  将两个有序表放在同一个数组相邻的位置，并将他们放在一个暂时数组中，待合并后移回原数组去

- 递归实现（自顶向下）

  ```c
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
  ```

- 非递归式，自底向上（不重要）

  ```c
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
  ```

> 稳定
>
> 时间：同快速
>
> 空间：O（n）

## 基数排序

基数排序是一种不需要进行关键字比较的，借助于多关键字排序的思想对单关键字排序的方法

​	一般元素R【i】的关键字有**d位数字（或字符）组成**，其中每一位的值都在0-r的范围内，r要取最大的值，**其中r成为基数（index）**

​	基数排序有两种，即最低位优先（least significant digit first，**LSD**）和最高位优先（most significant digit first，MSD）

- 分配：开始时，把Q，Q·····Q各个队列置成空队列，然后依次考查线性表中的每一个元素aj（j＝0，1，···，n—1），如果元素aj的关键字k｝＝k，就把元素a，插入到Q，队列中。
- 收集：将Q，Q1，···，Q—1各个队列中的元素依次首尾相接，得到新的元素序列，从而组成新的线性表。

> 例如对整数序列递增排序，由于个位数的重要性低于十位数，十位数的重要性低于百位数，一般越重要的位越放在后面排序，个位数属于最低位，所以对整数序列递增排序时应该采用最低位优先排序方法。
>
> 算法不考
>
> **时间：O（d（n+r））**
>
> **空间：O（r）**
>
> **稳定**
>
> 擅长处理：
>
> - 关键字可以方便地拆分位d组，且d较小
> - r较小
> - 元素个数n较大

![43](img/43.png)

> 按个位收集之后，形成了个位的升序序列
>
> 按十位手机之后形成了十位的升序序列，如果十位相同，则按个位的升序序列，得到最终的排序结果

## 各排序的比较

| 排序方法     | 平均时间复杂度  | 空间       | 稳定性   |
| ------------ | --------------- | ---------- | -------- |
| **直接插入** | O（n^2）        | O（1）     | 稳定     |
| 折半插入     | O（n^2）        | O（1）     | 稳定     |
| **希尔**     | **O（n^1.3)**   | O（1）     | 不稳定   |
| 冒泡         | O（n^2）        | O（1）     | 稳定     |
| **快速**     | **O（nlog2n）** | O（log2n） | 不稳定   |
| 简单选择     | O（n^2）        | O（1）     | 不稳定   |
| **堆**       | **O（nlog2n）** | O（1）     | 不稳定   |
| **二路归并** | **O（nlog2n）** | O（n）     | 稳定     |
| 基数         | O（d（n+r））   | O（r）     | **稳定** |

> **稳定的优先选：直插、冒泡、归并**
>
> **不稳定的优先选：快速、希尔、堆**

【例10.9】设线性表中每个元素有两个数据项k1和k2，现对线性表按以下规则进行排序：先看数据项k1，k1值小的在前，大的在后；在k1值相同的情况下再看k2，k2值小的在前，大的在后。满足这种要求的排序方法是：

（1）先按k1值进行直接插入排序，再按k2值进行简单选择排序。

（2）先按k2值进行直接插入排序，再按k1值进行简单选择排序。（3）先按k1值进行简单选择排序，再按k2值进行直接插入排序。（4）先按k2值进行简单选择排序，再按k1值进行直接插入排序。

> 解这里是按两个关键字排序，**越重要的关键字越在后面排序，所以应先按k2值排序再按k1值排序**。因为他要使k1稳定，所有最后一步操作应该是稳定的排序

- 灵活采取排序
  - （1）**若n较小（如n≤50），可采用直接插入**或简单选择排序。一般地，这两种排序方法中，直接插入排序较好，但简单选择排序移动的元素数少于直接插入排序。
  - （2）若文件初始状态**基本有序（指正序），则选用直接插入或冒泡排序为宜。**
  - （3）若**n较大**，应采用时间复杂度为O（nlog2n）的排序方法，例如**快速排序、堆排序或二路归并**排序。快速排序是目前基于比较的内排序中被认为是较好的方法，当待排序的关键字是随机分布时，快速排序的平均时间最少；但堆排序所需的辅助空间少于快速排序，并且不会出现快速排序可能出现的最坏情况。这两种排序都是不稳定的，若要求排序稳定，则可选用二路归并排序。
  - （4）若需要将两个有序表合并成一个新的有序表，最好用二路归并排序方法。
  - （5）基数排序可能在O（n）时间内完成对n个元素的排序。但遗憾的是，基数排序只适用于像字符串和整数这类有明显结构特征的关键字，而当关键字的取值范围属于某个无穷集合（例如实数型关键字）时无法使用基数排序，这时只有借助于“比较”的方法来排序。由此可知，若n很大，元素的关键字位数较少且可以分解时采用基数排序较好。
