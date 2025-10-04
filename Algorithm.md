在本文章中，记录了本人觉得值得关注的关于C++的数据结构定义、使用方法和一些值得关注的C++高级知识点，没啥题目，除非一些非常经典的题

章节顺序根据[代码随想录](https://www.programmercarl.com/)的C++算法来的，最底部还添加了C++的一些基本用法或规则

<!--more-->

# 编程语言

## 代码规范

### 变量命名

我就采用小驼峰大驼峰命名法即可了

| 命名法 | 举例               | 一般适用语言    |
| ------ | ------------------ | --------------- |
| 小驼峰 | int myAge          | Java、Go、C++   |
| 大驼峰 | public class MyAge | C++函数和结构体 |

### 代码留白

![image-20250430095018624](assets/image-20250430095018624.png)

# 程序性能

## 时间复杂度

时间复杂度就是**对一个算法所用的时间的一个函数的表示，用于预估程序的运行时间**。

时间复杂度一般只保留最高位，如同泰勒公式展开一样。如O(n^2^ + n) == O(n^2^)



时间复杂度并不一定就是越低越好，如O(n^2^)在数据规模大的情况下，低于O(n)，但是在数据规模小的情况下，能够反超后者

**O（l）常数阶＜O（log n）对数阶＜O（n）线性阶＜O（n^2^）平万阶＜O（n^3^）立万阶＜O（2^n^）指数阶**  

> **log n == log~10~ n ==  log~2~ n** 
>
> 所以统一就用 log n



- 计算递归算法的时间复杂度：

  **递归算法的时间复杂度 == 递归次数 x 每次递归所需要的时间**

## C++内存管理

**C／C＋＋的内存堆空间**的申请和释放完全靠**自己管理**

![image-20250430095856923](assets/image-20250430095856923.png)

![image-20250430095913315](assets/image-20250430095913315.png)

## 64位的编译器指针占8个字节

![image-20250430100424783](assets/image-20250430100424783.png)

也就是说 CPU 可以访问 2^64^ 个内存地址

## 内存对齐

CPU 读取内存是按照块来读取的，而一个块可以包含2、4、8、16字节。现在64位的操作系统对应的一块也就是8个字节，也就是cpu一次性能处理64位的数据

![image-20250430115917711](assets/image-20250430115917711.png)

就浪费了资源，所以一定需要内存对齐，好处是：

![image-20250430115955699](assets/image-20250430115955699.png)



## 空间复杂度

主要是指算法在运行的过程中需要用到的内存空间的大小，一般是创建各种存储结构时开辟的空间。

**递归算法的空间复杂度 == 递归的层数（深度） x  每次递归的空间复杂度**

> 也就是说递归次数多不仅会导致过大的时间复杂度，还会导致更多的空间复杂度，其中对时间复杂度的影响最大（因为是按递归次数算的），对空间复杂度影响最小（因为是按递归深度算的）。

# 数组

## 双指针

## 子数组（滑动窗口）

一般的思路就是【滑动窗口】，有时需要配合哈希表来实现。

滑动窗口有两种，分别是最小滑动窗口和最大滑动窗口，具体实现细节如下：

1. 最小滑动窗口

   ```cpp
   while (high < nums.size()) {
       判断[low, high]是否满足条件
   	while 满足条件的话 {
           更新最小数量结果min_num
           low++;
       }
   }
   ```

   

2. 最大滑动窗口

```
while (high < nums.size()) {
    判断[low, high]是否不满足条件
	while 不满足条件的话 {
        low++;
    }
    更新最大数量结果max_num
}
```

> 注意这里更新结果是在while的外面的

- **子排列数组的题目：固定滑动窗口的大小，使其窗口大小和子排列数组一致长**

- 通用模板

  ```cpp
  // 滑动窗口算法伪码框架
  void slidingWindow(string s) {
      // 用合适的数据结构记录窗口中的数据，根据具体场景变通
      // 比如说，我想记录窗口中元素出现的次数，就用 map
      // 如果我想记录窗口中的元素和，就可以只用一个 int
      auto window = ...
  
      int left = 0, right = 0;
      while (right < s.size()) {
          // c 是将移入窗口的字符
          char c = s[right];
          window.add(c);
          // 增大窗口
          right++;
  
          // 进行窗口内数据的一系列更新
          ...
  
          // *** debug 输出的位置 ***
          printf("window: [%d, %d)\n", left, right);
          // 注意在最终的解法代码中不要 print
          // 因为 IO 操作很耗时，可能导致超时
  
          // 判断左侧窗口是否要收缩
          while (window needs shrink) {
              // d 是将移出窗口的字符
              char d = s[left];
              window.remove(d);
              // 缩小窗口
              left++;
  
              // 进行窗口内数据的一系列更新
              ...
          }
      }
  }
  ```

- 滑动窗口的变体

  

## 模拟



# 链表

## 定义

```cpp
// 单链表
struct ListNode {
    int val;  // 节点上存储的元素
    ListNode *next;  // 指向下一个节点的指针
    ListNode(int x) : val(x), next(NULL) {}  // 节点的构造函数
};

// 通过自己定义构造函数初始化节点：

ListNode* head = new ListNode(5);
// 使用默认构造函数初始化节点：

ListNode* head = new ListNode();
head->val = 5;
// 所以如果不定义构造函数使用默认构造函数的话，在初始化的时候就不能直接给变量赋值！
```

# 哈希表

1. 常见的三种哈希结构

   当我们想使用哈希法来解决问题的时候，我们一般会选择如下三种数据结构。

   - 数组
   - set （集合）
   - map(映射)


## set

**`set<类型, 比较器> st`**

- 类型：要储存的数据类型
- 比较器：比较大小使用的比较器，默认为 `less<类型>`，可自定义

```cpp
set<int> st1;               // 储存int的集合（从小到大）
set<int, greater<int>> st2; // 储存int的集合（从大到小）
```



在C++中，set 和 map 分别提供以下三种数据结构，其底层实现以及优劣如下表所示：

| 集合               | 底层实现 | 是否有序 | 数值是否可以重复 | 查询效率 | 增删效率 |
| ------------------ | -------- | -------- | ---------------- | -------- | -------- |
| std::set           | 红黑树   | 有序     | **否**           | O(log n) | O(log n) |
| std::multiset      | 红黑树   | 有序     | **是**           | O(logn)  | O(logn)  |
| std::unordered_set | 哈希表   | **无序** | **否**           | **O(1)** | **O(1)** |

std::**unordered_set底层实现为哈希表**，std::**set 和std::multiset 的底层实现是红黑树**，红黑树是一种平衡二叉搜索树，所以key值是有序的，但key不可以修改，改动key值会导致整棵树的错乱，所以**只能删除和增加**。

## map

**`map<键类型, 值类型, 比较器> mp`**

- 键类型：要储存键的数据类型
- 值类型：要储存值的数据类型
- 比较器：键比较大小使用的比较器，默认为 `less<类型>`，可自定义

```cpp
map<int, int> mp1;               // int->int 的映射（键从小到大）
map<int, int, greater<int>> st2; // int->int 的映射（键从大到小）
```



| 映射               | 底层实现 | 是否有序    | 数值是否可以重复 | 查询效率 | 增删效率 |
| ------------------ | -------- | ----------- | ---------------- | -------- | -------- |
| std::map           | 红黑树   | key有序     | key**不可重复**  | O(logn)  | O(logn)  |
| std::multimap      | 红黑树   | key有序     | key**可重复**    | O(log n) | O(log n) |
| std::unordered_map | 哈希表   | key**无序** | key不可重复      | **O(1)** | **O(1)** |

std::unordered_map 底层实现为哈希表，std::map 和std::multimap 的底层实现是红黑树。同理，std::map 和std::multimap 的key也是有序的（这个问题也经常作为面试题，考察对语言容器底层的理解）。

当我们要使用集合来解决哈希问题的时候，优先使用unordered_set，因为它的查询和增删效率是最优的，**如果需要集合是有序的，那么就用set，如果要求不仅有序还要有重复数据的话，那么就用multiset。**



**C++中map、set、multimap，multiset的底层实现都是平衡二叉搜索树**，所以map、set的增删操作时间时间复杂度是logn

> 而unordered_map、unordered_set，unordered_map、unordered_set底层实现是**哈希表**。

# 字符串

[String](##String)

# 栈和队列

## c++的情况

栈和队列使用的是SGI STL 的标准库

> 三个最为普遍的STL版本：
>
> 1. HP STL 其他版本的C++ STL，一般是以HP STL为蓝本实现出来的，HP STL是C++ STL的第一个实现版本，而且开放源代码。
> 2. P.J.Plauger STL 由P.J.Plauger参照HP STL实现出来的，被Visual C++编译器所采用，不是开源的。
> 3. SGI STL 由Silicon Graphics Computer Systems公司参照HP STL实现，被Linux的C++编译器GCC所采用，SGI STL是开源软件，源码可读性甚高。

STL中栈和队列往往不被归类为容器，而被归类为**container adapter（容器适配器）**。

![栈与队列理论3](https://houlir2.dpdns.org/2025/07/679492fcf69aae0ac8c937adf8fcaf31.png)

**栈和队列**内部存储数据的方式都**默认是deque的方式**，对外提供的借口才是栈和队列常规的操作

> **deque是一个双向队列**，只要封住一端，只开通另一端就可以实现栈的逻辑了。

## 序列容器和容器适配器区别

| 容器 / 适配器 | 类型       | 底层实现                                | 核心特性                                                     | 适用场景                                                     |
| ------------- | ---------- | --------------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| `vector`      | 序列容器   | 动态数组（连续内存空间）                | **随机访问快**（`O(1)`），**尾部插入 / 删除快**（`O(1)`），中间插入 / 删除慢（`O(n)`） | 需要频繁随机访问、尾部操作，且**插入删除集中在尾部**的场景（如存储列表、缓存） |
| `list`        | 序列容器   | **双向链表**（非连续内存，节点链接）    | 随机访问慢（`O(n)`），**任意位置插入 / 删除快**（`O(1)`，只需修改指针） | 需要频繁在中间插入 / 删除元素，且很少随机访问的场景（如链表、队列模拟） |
| `deque`       | 序列容器   | 分段连续内存（中控器管理多段数组）      | **两端插入 / 删除快（`O(1)`），随机访问较快**（`O(1)`），中间插入 / 删除慢（`O(n)`） | 需要高效两端操作，且有一定随机访问需求的场景（如双端队列、滑动窗口） |
| `stack`       | 容器适配器 | 默认**基于 `deque` 实现**（可指定其他） | 后进先出（LIFO），**仅允许访问栈顶元素**                     | 实现递归、表达式解析、撤销操作等需要 “后进先出” 的场景       |
| `queue`       | 容器适配器 | 默认**基于 `deque` 实现**（可指定其他） | 先进先出（FIFO），**仅允许访问队首元素**                     | 实现任务调度、消息队列等需要 “先进先出” 的场景               |

以下是 `vector`、`list`、`deque`、`stack`、`queue` 的相同方法与不同方法对比（基于 C++ 标准库）：

| 方法类型     | 相同方法（所有容器 / 适配器均支持）                | `vector` 独有方法                       | `list` 独有方法                                     | `deque` 独有方法                        | `stack` 独有方法          | `queue` 独有方法          |
| ------------ | -------------------------------------------------- | --------------------------------------- | --------------------------------------------------- | --------------------------------------- | ------------------------- | ------------------------- |
| **基础属性** | `size()` `empty()` `clear()`（`stack`/`queue` 无） | -                                       | `unique()`（去重，需先排序） `splice()`（合并链表） | -                                       | -                         | -                         |
| **元素访问** | -                                                  | `operator[]` `at(int)`                  | -                                                   | `operator[]` `at(int)`                  | `top()`                   | `front()` `back()`        |
| **尾部操作** | `push_back(x)` `pop_back()`（`stack`/`queue` 无）  | -                                       | -                                                   | -                                       | `push(x)`（等价尾部插入） | `push(x)`（等价尾部插入） |
| **头部操作** | -                                                  | 无（需用 `insert` 模拟，效率低）        | `push_front(x)` `pop_front()`                       | `push_front(x)` `pop_front()`           | 无                        | `pop()`（等价头部删除）   |
| **中间操作** | -                                                  | `insert(iterator, x)` `erase(iterator)` | `insert(iterator, x)` `erase(iterator)`             | `insert(iterator, x)` `erase(iterator)` | 无（不支持中间操作）      | 无（不支持中间操作）      |
| **迭代器**   | -                                                  | `begin()`/`end()`（随机访问迭代器）     | `begin()`/`end()`（双向迭代器）                     | `begin()`/`end()`（随机访问迭代器）     | 无（不**支持迭代器**）    | 无（**不支持迭代器**）    |
| **其他特性** | -                                                  | `reserve(n)`（预留空间） `capacity()`   | `merge()`（合并有序链表） `reverse()`（反转）       | -                                       |                           |                           |

> 所有容器都具有：`size()` `empty()` `clear()` `push_back(x)` `pop_back()`且具有迭代器begin()、end()，可以调用内置算法
>
> 所有容器适配器（数据结构模式）最多有：`push` `pop` `top` `front` `back`

## 初始化

```cpp
std::stack<int, std::vector<int>> third;  // 使用vector为底层容器的栈
std::queue<int, std::list<int>> third;  // 使用list为底层容器的队列

// 默认的情况下使用deque作为底层
stack<int> st;
queue<int> de;
```

## 优先级队列

**就是一个披着队列外衣的堆**

**堆是一棵完全二叉树，树中每个结点的值都不小于（或不大于）其左右孩子的值。** 如果父亲结点是大于等于左右孩子就是大顶堆，小于等于左右孩子就是小顶堆。

**`priority_queue<类型, 容器, 比较器> pque`**

- 类型：要储存的数据类型（可以指定pair）
- 容器：储存数据的底层容器，默认为 `vector<类型>`，竞赛中保持默认即可
- 比较器：比较大小使用的比较器，默认为 `less<类型>`，可自定义

```cpp
priority_queue<int> pque1;                            // 储存int的大顶堆
priority_queue<int, vector<int>, greater<int>> pque2; // 储存int的小顶堆
```

# 二叉树

## 定义

```cpp
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
```

## 遍历

### 深度优先遍历

这是图里的叫法，分为前序中序后序

1. 递归

   ```cpp
   class Solution {
   public:
       void traversal(TreeNode* cur, vector<int>& vec) {
           if (cur == NULL) return;
           vec.push_back(cur->val);    // 中
           traversal(cur->left, vec);  // 左
           traversal(cur->right, vec); // 右
       }
       vector<int> preorderTraversal(TreeNode* root) {
           vector<int> result;
           traversal(root, result);
           return result;
       }
   };
   ```

2. 迭代（栈➕循环）

   ```cpp
   // 前序
   class Solution {
   public:
       vector<int> preorderTraversal(TreeNode* root) {
           stack<TreeNode*> st;
           vector<int> result;
           if (root == NULL) return result;
           st.push(root);
           while (!st.empty()) {
               TreeNode* node = st.top();                       // 中
               st.pop();
               result.push_back(node->val);
               if (node->right) st.push(node->right);           // 右（空节点不入栈）
               if (node->left) st.push(node->left);             // 左（空节点不入栈）
           }
           return result;
       }
   };
   
   
   
   // 中序
   class Solution {
   public:
       vector<int> inorderTraversal(TreeNode* root) {
           vector<int> result;
           stack<TreeNode*> st;
           TreeNode* cur = root;
           while (cur != NULL || !st.empty()) {
               if (cur != NULL) { // 指针来访问节点，访问到最底层
                   st.push(cur); // 将访问的节点放进栈
                   cur = cur->left;                // 左
               } else {
                   cur = st.top(); // 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
                   st.pop();
                   result.push_back(cur->val);     // 中
                   cur = cur->right;               // 右
               }
           }
           return result;
       }
   };
   ```

3. 统一的迭代法

   1. 空指针标记法

      ```cpp
      class Solution {
      public:
          vector<int> inorderTraversal(TreeNode* root) {
              // 统一迭代法实现中序遍历（通过boolean 标记法）
              vector<int> res;
              stack<TreeNode*> st;
              if (root)
                  st.push(root);
              while (!st.empty()) {
                  TreeNode* cur = st.top();
                  // 如果当前不是空节点，则调整一下顺序（先取出中节点），顺序为：右中左（中序遍历）
                  if (cur) {
                      st.pop();
                      if (cur->right) st.push(cur->right);
                      st.push(cur);
                      // 添加一个空节点，要求只有遇到空节点时，才输出到res中，否则是算作可能出现重复的情况
                      st.push(nullptr);
                      if (cur->left) st.push(cur->left);
                  }
                  else {
                      st.pop();
                      cur = st.top();
                      st.pop();
                      res.push_back(cur->val);
                  }
              }
              return res;
          }
      };
      ```

      

   2. boolean 标记法

      ```cpp
      class Solution {
      public:
          vector<int> inorderTraversal(TreeNode* root) {
              // 统一迭代法实现中序遍历（通过boolean 标记法）
              vector<int> res;
              stack<pair<TreeNode*, bool>> st;
              if (root)
                  st.push(make_pair(root, false));
              while (!st.empty()) {
                  TreeNode* cur = st.top().first;
                  // 用来表示当前节点是否已经访问过（处理好顺序了），如果访问过就直接输出该节点了，否则调整顺序
                  bool visited = st.top().second;
                  st.pop();
                  if (visited) {
                      res.push_back(cur->val);
                      continue;
                  }
      
                  if (cur->right) st.push(make_pair(cur->right, false));
                  // 只有中节点是调整好的，此时将访问设置为true
                  st.push(make_pair(cur, true));
                  if (cur->left) st.push(make_pair(cur->left, false));
              }
              return res;
          }
      };
      ```

      

      

   

### 广度优先遍历

也就是层序遍历

1. 递归

   ```cpp
   class Solution {
   public:
       void levelTraversal(TreeNode* cur, vector<vector<int>>& res, int depth) {
           // 先设置好递归结束的条件
           if (!cur) return;
           // 如果是新的一层，则加入空的一维数组
           if (res.size() == depth)
               res.push_back(vector<int> ());
           
           // 接下来就是递归的操作，先插入当前节点
           res[depth].push_back(cur->val);
           // 开始左子树右子树递归了
           levelTraversal(cur->left, res, depth + 1);
           levelTraversal(cur->right, res, depth + 1);
       }
       vector<vector<int>> levelOrder(TreeNode* root) {
           // 递归方式实现层序遍历
           // 树的递归方式的使用方式一般是：主函数中直接调用一个递归函数（和主函数不同），传入的数组要求是能够修改的
           vector<vector<int>> res;
           levelTraversal(root, res, 0);
           return res;
       }
   };
   ```

   

2. 利用队列

   ```cpp
   class Solution {
   public:
       vector<vector<int>> levelOrder(TreeNode* root) {
           // 迭代实现层序遍历：利用了队列
           vector<vector<int>> res;
           queue<TreeNode*> que;
           if (root)
               que.push(root);
           // 用一个size来确定某节点是属于哪一层（哪一个vector里的）
           while (!que.empty()) {
               // 用来总结每一层的节点
               vector<int> t;
               // 每一轮大循环的que里的元素，都表示的是本层中有的节点数量
               int s = que.size();
               for (int i = 0; i < s; i++) {
                   TreeNode* cur = que.front();
                   que.pop();
                   t.push_back(cur->val);
   
                   if (cur->left) {
                       que.push(cur->left);
                   }
                   if (cur->right) {
                       que.push(cur->right);
                   }
               }
               res.push_back(t);
           }
           return res;
       }
   };
   ```

   



































# 回溯算法

回溯算法的框架：

```
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    
    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择
```

# C++ 标准库

## STL 容器

C++ 标准库容器可分为 **序列容器**、**关联容器**、**无序关联容器** 和 **容器适配器** 四大类，它们在功能、底层实现和适用场景上有显著差异，但也存在一些通用操作。以下是汇总对比：

### 容器分类总览

> 算法竞赛必学：array、vector、deque、list、所有有序和无序的关联容器、stack、queue、priority_queue、string、pair、tuple

| 类别             | 包含容器                                                     | 底层实现 / 核心特性                                          | 有序性       | 允许重复元素                                               | 随机访问支持                                                |
| ---------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------ | ---------------------------------------------------------- | ----------------------------------------------------------- |
| **序列容器**     | `vector`、`list`、`deque`、`array`(数组）、`forward_list`(单向链表：只能沿一个方向遍历的链表) | 按插入顺序存储，元素位置由插入顺序决定                       | 按插入顺序   | 允许                                                       | `vector`/`deque`/`array` 支持；`list`/`forward_list` 不支持 |
| **关联容器**     | `set`、`multiset`、`map`、`multimap`                         | 基于**红黑树**（平衡二叉搜索树），元素按 **键（key）** 自动排序 | 按键**有序** | `multiset`/`multimap` 允许；`set`/`map` 不允许             | 不支持（迭代器仅双向）                                      |
| **无序关联容器** | `unordered_set`、`unordered_multiset`、`unordered_map`、`unordered_multimap` | 基于**哈希表，元素无序存储**，**通过哈希函数快速访问**       | **无序**     | `unordered_multiset`/`unordered_multimap` 允许；其余不允许 | 不支持（迭代器仅前向）                                      |
| **容器适配器**   | `stack`、`queue`、`priority_queue`                           | stack、queue默认是用deque容器；**priority_queue默认是用vector容器** | -            | 由底层容器决定                                             | 不支持（仅允许访问特定位置元素）                            |

> 其中，set、map和priority_queue可以有第三个参数来设置谓词（**谓词就是返回值为真或者假的函数**。STL 容器中经常会使用到谓词，用于模板参数）

### 容器的****共同方法****

以下方法是绝大多数容器（除部分适配器外）都支持的基础操作：



| 方法              | 功能描述                                      | 例外容器                                                    |
| ----------------- | --------------------------------------------- | ----------------------------------------------------------- |
| `size()`          | 返回容器中元素的数量                          | 无（所有容器均支持）                                        |
| `empty()`         | 判断容器是否为空（`size() == 0`）             | 无（所有容器均支持）                                        |
| `begin()`/`end()` | 返回指向首元素 / 尾后位置的迭代器（用于遍历） | `stack`、`queue`、`priority_queue`（不支持迭代器）          |
| `clear()`         | 清空容器中所有元素                            | `stack`、`queue`、`priority_queue`（需通过 `pop` 逐个删除） |
| `swap(container)` | 交换两个同类型容器的内容                      | 无（所有容器均支持）                                        |

### 容器的独有方法

#### 序列容器（按插入顺序存储）

| 容器             | 核心方法（独有或特色）                                       | 适用场景                                                 |
| ---------------- | ------------------------------------------------------------ | -------------------------------------------------------- |
| `vector`         | `operator[]`、`at(i)`（随机访问）、`push_back(x)`、`pop_back(x)`、`reserve(n)`（预留空间）、`capacity()`（当前容量） | 频繁随机访问、尾部插入 / 删除（如存储列表、动态数组）    |
| `list（双链表）` | `push_front(x)`、`pop_front(x)`、`splice(pos, other)`（合并链表）、`unique()`（去重）、`reverse()`（反转） | 频繁在任意位置插入 / 删除（如链表、双向队列）            |
| `deque`          | `operator[]`、`at(i)`（随机访问）、**`push_front(x)`、`pop_front(x)`、**`push_back(x)`、`pop_back(x)` | 高效两端操作 + 随机访问（如**双端队列**、滑动窗口）      |
| `array`          | `operator[]`、`at(i)`（随机访问）、`data()`（返回底层数组指针） | 固定大小数组（编译期确定大小，如存储坐标、固定长度数据） |
| `forward_list`   | `push_front(x)`、`pop_front(x)`、`insert_after(pos, x)`（在指定位置后插入） | **单向链表**，内存占用小，仅需前向遍历（如实现单向队列） |

#### 关联容器（按键有序，红黑树实现）

| 容器       | 核心方法（独有或特色）                                       | 适用场景                                               |
| ---------- | ------------------------------------------------------------ | ------------------------------------------------------ |
| `set`      | `insert(x)`（插入键）、`erase(x)`（删除键）、`find(x)`（查找键，返回迭代器）、`count(x)`（键出现次数，仅 0 或 1） | 存储不重复元素，需按键有序访问（如去重 + 排序）        |
| `multiset` | 同 `set`，但 `count(x)` 可返回 > 1 的值（允许重复键）        | 存储可重复元素，需按键有序访问（如统计频率 + 排序）    |
| `map`      | `operator[key]`（访问 / 插入键值对）、`insert({key, val})`、`erase(key)`、`find(key)`、`at(key)`（访问值） | 存储键值对（键唯一），需按键有序访问（如字典、映射表） |
| `multimap` | 同 `map`，但允许重复键（无 `operator[]`，需用 `find`/`equal_range` 访问） | 存储键值对（键可重复），需按键有序访问（如一对多映射） |

#### 无序关联容器（哈希表实现，无序）

| 容器                 | 核心方法（独有或特色）                                    | 适用场景                                   |
| -------------------- | --------------------------------------------------------- | ------------------------------------------ |
| `unordered_set`      | 同 `set`，但无序，查找效率更高（平均 `O(1)`）             | 快速查找、去重，无需有序（如查重集合）     |
| `unordered_multiset` | 同 `multiset`，但无序                                     | 快速查找、允许重复，无需有序（如频率统计） |
| `unordered_map`      | 同 `map`，但无序，`operator[key]` 效率更高（平均 `O(1)`） | 快速键值对查找，无需有序（如哈希表、缓存） |
| `unordered_multimap` | 同 `multimap`，但无序                                     | 快速一对多映射，无需有序                   |

#### 容器适配器（封装底层容器，接口受限）

`容器适配器<类型，容器，构造器>`

构造器仅针对priority_queue有，如果指定了构造器，则必须指定容器，否则容器可以不写

| 容器             | 核心方法（独有或特色）                                       | 底层默认容器 | 适用场景                                       | 特殊说明                               |
| ---------------- | ------------------------------------------------------------ | ------------ | ---------------------------------------------- | -------------------------------------- |
| `stack`          | **`push(x)`（栈顶插入）、`pop()`（栈顶删除，无返回）、`top()`（访问栈顶）** | `deque`      | 后进先出（LIFO）场景（如递归模拟、表达式解析） | top()                                  |
| `queue`          | `push(x)`（队尾插入）、`pop()`（队首删除，无返回）、**`front()`（访问队首）、`back()`（访问队尾）** | `deque`      | 先进先出（FIFO）场景（如任务调度、消息队列）   | front()                                |
| `priority_queue` | `push(x)`（插入并维持优先级）、`pop()`（删除最高优先级元素）、**`top()`（访问最高优先级元素）** | `vector`     | 需按优先级处理元素（如最大堆、任务优先级调度） | top()，less表示大顶堆，greater是小顶堆 |

### 核心差异总结

1. **有序性**：
   - 关联容器（`set`/`map` 等）按键**自动排序**；
   - 无序关联容器（`unordered_*`）**无序**；
   - 序列容器按**插入顺序**排序；
   - 适配器的有序性由底层容器决定（`priority_queue` 是堆结构，始终按优先级有序）。
2. **访问效率**：
   - 随机访问：`vector`/`deque`/`array` 支持 `O(1)` 随机访问；
   - 查找效率：无序关联容器（哈希表）平均 `O(1)`，关联容器（红黑树）`O(log n)`，序列容器 `O(n)`。
3. **插入 / 删除效率**：
   - 尾部操作：`vector`/`deque` 的 `push_back`/`pop_back` 是 `O(1)`；
   - 头部操作：`deque`/`list`/`forward_list` 的 `push_front`/`pop_front` 是 `O(1)`；
   - 中间操作：`list`/`forward_list`（链表）`O(1)`，`vector`/`deque`（数组）`O(n)`（需移动元素）。
4. **适用场景优先级**：
   - 快速随机访问 + 尾部操作 → `vector`；
   - 频繁中间插入 / 删除 → `list`；
   - 两端操作 + 随机访问 → `deque`；
   - 键值对映射 + 有序 → `map`；
   - 键值对映射 + 快速查找 → `unordered_map`；
   - 栈 / 队列逻辑 → 对应适配器。

## STL 算法

C++STL中的内置算法主要在[头文件](https://so.csdn.net/so/search?q=头文件&spm=1001.2101.3001.7020)`<algorithm>`、`<functional>`、`<numeric>`中

- `<algorithm>`是所有STL头文件中最大的一个，也是包含算法最多，最常用的一个头文件，其中包含比较、交换、查找、遍历、复制、修改等算法
- `<numeric>`体积很小，只包括几个在序列上面进行简单数学运算的模板函数
- `<functional>`定义了一些模板类，用以声明函数对象(仿函数)

### 算法库 Algorithm

1. [ ] `count()`

2. [ ] `find()`

3. [ ] `fill()`

4. **[x] [`swap()`](https://zh.cppreference.com/w/cpp/algorithm/swap)**

   ```cpp 
   swap(a, b);

5. **[x] [`reverse()`](https://zh.cppreference.com/w/cpp/algorithm/reverse)**

   反转一个可**迭代对象**的元素顺序(要用迭代器)

   ```cpp
   reverse(s.begin(), s.end());

6. [ ] `shuffle()` C++11

7. **[x] [`unique()`](https://zh.cppreference.com/w/cpp/algorithm/unique)**

   消除数组的**重复相邻**元素（**如果有序，就能去重**），数组长度不变，但是有效数据缩短，**返回**的是有效数据位置的**结尾迭代器。**

   例如：[1, 1, 4, 5] -> [1, 4, 5, ?]，下划线位置为返回的迭代器指向。

   ```cpp
   vector<int> arr{1, 2, 1, 4, 5, 4, 4};
   sort(arr.begin(), arr.end());
   arr.erase(unique(arr.begin(), arr.end()), arr.end());

8. **[x] [`sort()`](https://zh.cppreference.com/w/cpp/algorithm/sort)**

   要用迭代器

   ```cpp
   void sort( RandomIt first, RandomIt last, Compare comp );  // 可以选用比较器

9. **[x] [`lower_bound()`](https://zh.cppreference.com/w/cpp/algorithm/lower_bound) / [`upper_bound()`](https://zh.cppreference.com/w/cpp/algorithm/upper_bound)**

   在**已升序排序**的元素中，应用二分查找检索指定元素，返回对应元素迭代器位置。**找不到则返回尾迭代器。**

   - **`lower_bound()`: 寻找 ≥x 的第一个元素的位置**
   - **`upper_bound()`: 寻找 >x 的第一个元素的位置**

   怎么找 / 的第一个元素呢？

   -  \>x 的第一个元素的前一个元素（如果有）便是 ≤x 的第一个元素
   -  ≥x  的第一个元素的前一个元素（如果有）便是 <x 的第一个元素

   **返回的是迭代器，如何转成下标索引呢？减去头迭代器即可。**

   ```cpp
   //原型一
   ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last,  const T& val);
   //原型二
   ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val, Compare comp);  // 可以指定一个 cmp 比较器
   
   // 示例
   vector<int> arr{0, 1, 1, 1, 8, 9, 9};
   idx = lower_bound(arr.begin(), arr.end(), 7) - arr.begin(); // 4
   idx = lower_bound(arr.begin(), arr.end(), 8) - arr.begin(); // 4
   idx = upper_bound(arr.begin(), arr.end(), 7) - arr.begin(); // 4
   idx = upper_bound(arr.begin(), arr.end(), 8) - arr.begin(); // 5

10. **[x] [`max()`](https://zh.cppreference.com/w/cpp/algorithm/max) / [`min()`](https://zh.cppreference.com/w/cpp/algorithm/min)**

11. [ ] `max_element()` / `min_element()`

12. [ ] `prev_permutation()` / `next_permutation()`

1. 数学函数 cmath
   1. **[x] [`abs()`](https://zh.cppreference.com/w/cpp/numeric/math/fabs)**
   2. **[x] [`exp()`](https://zh.cppreference.com/w/cpp/numeric/math/exp)**
   3. **[x] [`log()`](https://zh.cppreference.com/w/cpp/numeric/math/log) / `log10()` / `log2()`**
   4. **[x] [`pow()`](https://zh.cppreference.com/w/cpp/numeric/math/pow)**
   5. **[x] [`sqrt()`](https://zh.cppreference.com/w/cpp/numeric/math/sqrt)**
   6. [ ] `sin()` / `cos()` / `tan()`
   7. [ ] `asin()` / `acos()` / `atan()`
   8. [ ] `sinh()` / `cosh()` / `tanh()`
   9. [ ] `asinh()` / `acosh()` / `atanh()` C++11
   10. **[x] [`ceil()`](https://zh.cppreference.com/w/cpp/numeric/math/ceil) / [`floor()`](https://zh.cppreference.com/w/cpp/numeric/math/floor)**
   11. **[x] [`round()`](https://zh.cppreference.com/w/cpp/numeric/math/round) C++11**
2. 数值算法 numeric
   1. [ ] `iota()` C++11
   2. [ ] `accumulate()`
   3. **[x] [`gcd()`](https://zh.cppreference.com/w/cpp/numeric/gcd) C++17**
   4. **[x] [`lcm()`](https://zh.cppreference.com/w/cpp/numeric/lcm) C++17**
3. 伪随机数生成 random
   1. [ ] `mt19937`
   2. [ ] `random_device()`

## String

C 语言中是在`<string.h>` 库中；而 CPP 中是`<string>`即可

`string`好就好在他**重载了加法运算符（支持字符串加法）和比较运算符**

### 转 char 数组

String 转换为 char 是变成 C 语言中类似 字符数组的情况：

```cpp
printf("%s", s);          // 编译错误
printf("%s", s.data());   // 编译通过，但是是 undefined behavior
printf("%s", s.c_str());  // 一定能够正确输出
```

### 各种 string 方法

| 功能                     | 原型                                                    | 补充                                                         |
| ------------------------ | ------------------------------------------------------- | ------------------------------------------------------------ |
| 长度                     | strlen(s)、s.size()` 和 `s.length()                     | 推荐用后两种                                                 |
| 查第一次出现位置（下标） | s.find(str, pos)                                        | pos默认是0；如果没有出现，则返回 `string::npos`（被定义为 `-1`，但类型仍为 `size_t`/`unsigned long`） |
| 截取子串                 | s.substr(pos, len)                                      | 从 `pos` 位置开始截取最多 `len` 个字符组成的字符串（如果从 `pos` 开始的后缀长度不足 `len` 则截取这个后缀）。 |
| 插入字符（串）           | s.insert(index, str)或s.insert(index, count, ch)        | 第一个是在下标插入字符串；第二个是插入count个ch字符          |
| 删除字符串               | s.erase(index, count)                                   | 若不传参给 `count` 则表示删去 `index` 位置及以后的所有字符） |
| 替换字符（串）           | replace(pos, count, str)` 和 `replace(first, last, str) | 将从 `pos` 位置开始 `count` 个字符的子串替换为 `str` <br>将以 `first` 开始（含）、`last` 结束（不含）的子串替换为 `str`，其中 `first` 和 `last` 均为迭代器。 |

### 数值与字符串互转

| 源                                             | 目的        | 函数        |
| ---------------------------------------------- | ----------- | ----------- |
| int / long long / float / double / long double | string      | to_string() |
| string                                         | int         | stoi()      |
| string                                         | long long   | stoll()     |
| string                                         | float       | stof()      |
| string                                         | double      | stod()      |
| string                                         | long double | stold()     |

## Pair

`std::pair` 是标准库中定义的一个类模板。**用于将两个变量关联在一起，组成一个「对」，而且两个变量的数据类型可以是不同的。**

> 类模板（class template）本身不是一个类，而是可以根据 **不同数据类型** 产生 **不同类** 的「模板」。
>
> 在使用时，编译器会根据传入的数据类型产生对应的类，再创建对应实例。
>
> 与自定义的 `struct` 相比，`pair` 不需要额外定义结构与重载运算符，因此使用起来更加**简便**。**效率和自己定义结构体差不多**
>
> 然而，自定义 `struct` 的变量命名往往更加清晰（`pair` **只能使用** `first` 与 `second` 访问包含的两个变量）。同时，**如果需要将两个以上的变量进行关联，自定义 `struct` 会更加合适。**

### 定义

```cpp
int main() {
    // 初始化方法一
    pair<int, float> it;
    it.first = 1;
    it.second = 2.0;
    cout << it.first + it.second;

    // 初始化方法二
    pair<int, double> it2 = std::make_pair(3, 4.1);

    // 初始化方法三
    pair<int, float> it3 = {1, 'a'};
    return 0;
}
```

### 比较

`pair` 已经预先定义了所有的比较运算符，包括 `<`、`>`、`<=`、`>=`、`==`、`!=`。

其中，`<`、`>`、`<=`、`>=` 四个运算符会**先比较两个 `pair` 中的第一个变量，在第一个变量相等的情况下再比较第二个变量。**

```cpp
// 比较（直接对pair类型比较，而不是里面的成员）
if (it < it2) cout << "it2 win";
```

由于 `pair` 定义了 STL 中常用的 `<` 与 `==`，使得其能够很好的与其他 STL 函数或数据结构配合。比如，**`pair` 可以作为 `priority_queue` 的数据类型。**

```cpp
priority_queue<pair<int, double>> q;  // 优先级队列
```

### 离散化

`pair` 可以轻松实现离散化。

我们可以创建一个 `pair` 数组，将原始数据的**值作为每个 `pair` 第一个变量**，将原始数据的**位置作为第二个变量**。在排序后，将原始数据值的排名（该值排序后所在的位置）赋给该值原本所在的位置即可。

```cpp
// `pair` 可以轻松实现离散化。
// a为原始数据
pair<int, int> a[MAXN];
// ai为离散化后的数据
int ai[MAXN];
for (int i = 0; i < n; i++) {
  // first为原始数据的值，second为原始数据的位置（下标，从0开始）
  scanf("%d", &a[i].first);
  a[i].second = i;
}

// 排序
sort(a, a + n);  // 这里用到了数组地址的特性，如果是容器，使用的方式是 xx.begin()

for (int i = 0; i < n; i++) {
  // 将该值的排名（从0开始）赋给该值原本所在的位置
  ai[a[i].second] = i;
}
```

### Dijkstra

如前所述，`pair` 可以作为 `priority_queue` 的数据类型。

那么，在 Dijkstra 算法的堆优化中，可以使用 `pair` 与 `priority_queue` 维护节点，将节点当前到起点的距离作为第一个变量，将节点编号作为第二个变量。

```cpp
priority_queue<pair<int, int>, std::vector<pair<int, int>>,
               std::greater<pair<int, int>>>
    q;
... while (!q.empty()) {
  // dis为入堆时节点到起点的距离，i为节点编号
  int dis = q.top().first, i = q.top().second;
  q.pop();
  ...
}
```

### pair 与 map

`map` 的是 C++ 中存储键值对的数据结构。很多情况下，**`map` 中存储的键值对通过 `pair` 向外暴露。**

```cpp
map<int, double> m; 
m.insert(make_pair(1, 2.0));
```

# C++基础

## Linux中编译

### g++

使用 `g++ -v` 来检查是否安装过 `g++`。

使用如下命令可以安装：

**sudo apt install g++**

- 编译代码

`g++ test.cpp -o test -lm `

还可以编译多个文件：`g++ 文件1 文件2 -o test -lm `

指定c++标准版本：`g++ -std=c++11 文件1 -o 文件名`

`g++` 是 C++ 语言的编译器（C 语言的编译器为 `gcc`），**`-o` 用于指定可执行文件的文件名**，编译选项 `-lm` 用于链接数学库 `libm`，从而使得使用 `math.h` 的代码可以正常编译运行。

> 注：C++ 程序不需要 `-lm` 即可正常编译运行。历年 NOI/NOIP 试题的 C++ 编译选项中都带着 `-lm`，故这里也一并加上。

### gcc编译选项

**gcc test.cpp -o test -lm**

| gcc选项       | 作用描述                                                     |
| ------------- | ------------------------------------------------------------ |
| `-o <文件名>` | output——**指定输出文件名**（**可执行文件(linux中无需exe后缀)**、库文件等） |
| -O[0/1/2/3/g] | 用于开启代码优化，可跟随数字指定优化级别（`-O0` 到 `-O3`，**默认 `-O0` 不优化**），g介于O0和O1之间，，平衡了「可调试性」和「基础优化」 |
| `-c`          | 只编译不链接，生成目标文件（.o）                             |
| `-g`          | 生成调试信息（用于 gdb 调试），用于在编译时保留调试信息（如变量名、行号等） |
| `-l<库名>`    | 链接动态库（如 `-lstdc++` 链接 C++ 标准库、**-lm链接数学库**） |
| `-std=<标准>` | 指定语言标准（如 `-std=c11`、`-std=c++20`）                  |
| -E            | 展开头文件、替换宏，生成纯 C 代码                            |
| -S            | 只执行预处理和编译，生成汇编代码后停止                       |

### 编译的5个阶段

**源文件（.c）→预处理（.i）→编译（.s）→汇编（.o）→链接（.exe）**

| 阶段                    | 参数 | 例子                                                         | 含义                                                         |
| ----------------------- | ---- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 预处理（Preprocessing） | -E   | gcc -E sum.c -o sum.i                                        | 展开头文件、替换宏，生成纯 C 代码（`.i`文件）                |
| 编译（Compilation）     | -S   | gcc -S sum.i -o sum.s                                        | 将预处理后的`.i`文件转换为**汇编代码**（`.s`文件），即汇编指令（**CPU能理解不能执行**） |
| 汇编（Assembly）        | -c   | gcc -c sum -o sum.o \| as sum.s -o sum.o                     | 将汇编代码（`.s`）转换为**机器码**（**二进制目标文件**，`.o`，**CPU可以直接执行**）；可以直接用gcc，也可以用as（gcc本质也用了as） |
| 链接（Linking）         | -o   | gcc sum.o -o sum.exe \| ld sum.o -o sum -lc -dynamic-linker /lib64/ld-linux-x86-64.so.2 | 将目标文件（`.o`）与系统库组合，解决外部符号引用，最终生成可执行文件 |

```shell
# 1. 编写源程序.c
gcc -E sum.c -o sum.i
# 2. 预处理
gcc -S sum.i sum.s
# 3. 编译
gcc -S sum.i sum.s
# 4. 汇编
gcc -c sum.s -o sum.o
# 5. 链接
gcc sum.o -o sum.exe
```



> **其中**
>
> 1. `as`是 GNU 的纯汇编器，专门将汇编代码转为目标文件
>
> 2. `ld`是 GNU 链接器。
>
>    `-dynamic-linker /lib64/ld-linux-x86-64.so.2`：指定动态链接器（加载程序时负责加载依赖的动态库，路径可能因系统而异，32 位系统通常是`/lib/ld-linux.so.2`）

## 基本语法

### C++「代码框架」

```cpp
#include <cstdio>
#include <iostream>

int main() {
  // do something...
  return 0;
}
```

> **什么是 include？**
>
> `#include` 其实是一个预处理命令，意思为将一个文件「放」在这条语句处，被「放」的文件被称为头文件。也就是说，在编译时，编译器会「复制」头文件 `iostream` 中的内容，「粘贴」到 `#include <iostream>` 这条语句处。这样，你就可以使用 `iostream` 中提供的 `std::cin`、`std::cout`、`std::endl` 等对象了。

如果你学过 C 语言，你会发现目前我们接触的 C++ 中的头文件一般都不带 `.h` 后缀，而那些 C 语言中的头文件 `xx.h` 都变成了 `cxx`，如 `stdio.h` 变成了 `cstdio`。因为 C++ 为了和 C 保持兼容，都直接使用了 C 语言中的头文件，为了区分 C++ 的头文件和 C 的头文件，使用了 `c` 前缀。

一般来说，应当根据你需要编写的 C++ 程序的需要来确定你要 `#include` 哪些头文件。但如果你 `#include` 了多余的头文件，只会增加编译时间，几乎不会对运行时间造成影响。如果你只需要 `scanf` 和 `printf`，就可以不用 `#include <iostream>`。



可以 `#include` 自己写的头文件吗？答案是，可以。

你可以自己写一个头文件，如：`myheader.h`。然后，将其放到和你的代码相同的目录里，再 `#include "myheader.h"` 即可。需要注意的是，**自定义的头文件需要使用引号而非尖括号**。当然，你也可以使用编译命令 `-I <header_file_path>` 来告诉编译器在哪找头文件，就不需要将头文件放到和代码相同的目录里了。

### 输入与输出

1. `cin`与`cout`
2. `scanf` 与 `printf` 

其实是 C 语言提供的函数。大多数情况下，它们的速度比 `cin` 和 `cout` 更快，并且能够方便地控制输入输出格式。

### main函数

`int main(int argc, char* argv[])`

- `argc`：是 **argument count** 的缩写，意为「参数计数」，表示命令行参数的总个数（包含程序名本身）。
  例如执行 `./sum 2 3` 时，`argc` 的值为 `3`（分别是 `./sum`、`2`、`3`）。
- `argv`：是 **argument vector** 的缩写，意为「参数向量」（这里的「vector」指数组），是一个存储命令行参数的字符串数组。
  例如 `./sum 2 3` 中：
  - `argv[0]` 存储程序名 `./sum`
  - `argv[1]` 存储第一个参数 `2`
  - `argv[2]` 存储第二个参数 `3`

### 算法模板

```cpp
#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    // 解题
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t; // 单测则注释
    while (t--)
        solve();
    return 0;
}”
```

> 1. `#include <bits/stdc++.h>`
>
>    - 这是一个包含指令，**引入了 C++ 标准库中的所有头文件**。省去了逐个包含所需头文件的麻烦，但会增加编译时间（比赛中可忽略）
>
> 2. `#define endl '\n'`
>
>    比标准`endl`效率更高，因为`endl`会强制刷新输出缓冲区
>
> 3. `#define int long long`
>
>    **避免整数溢出**问题，在算法竞赛中很常用
>
> 4. `signed main()`
>
>    - 程序入口函数，`signed`是**为了与前面`#define int long long`兼容**
>    - 因为`long long`类型的主函数需要用`signed`修饰
>
> 5. `ios::sync_with_stdio(false);`
>
>    - 关闭 C++ 标准输入输出流与 C 语言输入输出流的同步
>    - 可以提高输入输出效率
>
> 6. `cin.tie(0); cout.tie(0);`
>
>    - 解除`cin`与`cout`的绑定
>    - 进一步提高输入输出效率
>
> 7. `int t = 1; cin >> t; while (t--)`
>
>    - 处理多组测试数据的常见写法
>    - 先读取测试数据的数量`t`，然后循环`t`次调用`solve()`函数
>    - 如果是单组测试数据，可以注释掉`cin >> t;`

## 变量

### 布尔类型

用bool

只有true和false

### 字符类型

窄字符型位数一般为 $8$

- `signed char`：有符号字符表示的类型，表示范围在 -128 - 127 之间。
- `unsigned char`：无符号字符表示的类型，表示范围在 0 - 255 之间。
- `char` 拥有与 `signed char` 或 `unsigned char` 之一相同的表示和对齐，但始终是独立的类型。

> `char` 的符号性取决于编译器和目标平台：ARM 和 PowerPC 的默认设置通常没有符号，而 x86 与 x64 的默认设置通常有符号。
>
> 与其他整型不同，`char`、`signed char`、`unsigned char` 是 **三种不同的类型**。
>
> 一般来说 `signed char`,`unsigned char` 不应用来存储字符，绝大多数情况下，这两种类型均被视作整数类型。

### 浮点类型

用于存储「实数」（注意并不是严格意义上的实数，而是**实数在一定规则下的近似**），包括以下三种：

- `float`：单精度浮点类型。如果支持就会匹配 IEEE-754 binary32 格式。
- `double`：双精度浮点类型。如果支持就会匹配 IEEE-754 binary64 格式。
- `long double`：扩展精度浮点类型。如果支持就会匹配 IEEE-754 binary128 格式，否则如果支持就会匹配 IEEE-754 binary64 扩展格式，否则匹配某种精度优于 binary64 而值域至少和 binary64 一样好的非 IEEE-754 扩展浮点格式，否则匹配 IEEE-754 binary64 格式。

| 浮点格式                   | 位宽      | 最大正数                   | 精度位数         |
| :------------------------- | :-------- | :------------------------- | :--------------- |
| IEEE-754 binary32 格式     | $32$      | $3.4\times 10^{38}$        | $6\sim 9$        |
| IEEE-754 binary64 格式     | $64$      | $1.8\times 10^{308}$       | $15\sim 17$      |
| IEEE-754 binary64 扩展格式 | $\geq 80$ | $\geq 1.2\times 10^{4932}$ | $\geq 18\sim 21$ |
| IEEE-754 binary128 格式    | $128$     | $1.2\times 10^{4932}$      | $33\sim 36$      |

> IEEE-754 **浮点格式的最小负数是最大正数的相反数**。

因为 `float` 类型表示范围较小，且精度不高，**实际应用中常使用 `double` 类型表示浮点数**。

另外，浮点类型可以支持一些特殊值：

- **无穷（正或负）：`INFINITY`.**——需要导入`<cmath>`
- **负零：`-0.0`，例如 `1.0 / 0.0 == INFINITY`,`1.0 / -0.0 == -INFINITY`.**
- **非数（NaN）：`std::nan`,`NAN`，一般可以由 `0.0 / 0.0` 之类的运算产生。它与任何值（包括自身）比较都不相等，C++11 后可以 使用 `std::isnan` 判断一个浮点数是不是 NaN**.

### 空指针类型

**std::nullptr_t**

注意这是一个类型，意味着可以定义属于该类型的变量

```cpp
#include <iostream>
#include <cmath>
using namespace std;

int main() {
        nullptr_t p = nullptr;  // C++11引入的nullptr
        cout << p << endl;  // 输出nullptr的地址，通常为0
}
```

# C++高级

## 迭代器

### 定义

很多数据结构并不是线性的（例如红黑树），对于非线性数据结构，下标是无意义的。无法使用下标来遍历整个数据结构。

迭代器的作用就是定义某个数据结构的遍历方式，通过迭代器的增减，代表遍历到的位置，通过迭代器便能成功遍历非线性结构了。（**行为类似指针**）

```cpp
for (vector<int>::iterator it = a.begin(); it != a.end(); ++it)
    cout << *it << endl;
```

- `a.begin()` 是一个迭代器，指向的是第一个元素
- `a.end()` 是一个迭代器，指向的是最后一个元素**再后面一位**
- 上述迭代器具有自增运算符，自增则迭代器向下一个元素移动
- 迭代器与指针相似，如果对它使用解引用运算符，即 `*it`，就能取到对应值了

### 用法

对于 vector 容器，它的迭代器功能比较完整，以它举例：

- `.begin()`：头迭代器
- `.end()`：尾迭代器
- `.rbegin()`：反向头迭代器
- `.rend()`：反向尾迭代器
- 迭代器 `+` 整型：将迭代器向后移动
- 迭代器 `-` 整型：将迭代器向前移动
- 迭代器 `++`：将迭代器向后移动 1 位
- 迭代器 `--`：将迭代器向前移动 1 位
- 迭代器 `-` 迭代器：两个迭代器的距离
- `prev(it)`：返回 it 的前一个迭代器
- `next(it)`：返回 it 的后一个迭代器

对于其他容器，由于其结构特性，上面的功能不一定都有（例如 set 的迭代器是不能相减求距离的）

> **`.end()` 和 `.rend()` 指向的位置是无意义的值**
>
> 注意插入和删除的情况元素变动会对迭代效果产生影响

## lambda

lambda 的一种语法：

```
[capture] (parameters) mutable -> return-type {statement}
```

> 1. lambda 以 capture 子句开头，它指定哪些变量被捕获（有点类似于参数，但**这里如果指定了mutable的话，这些捕获的内容就能够修改影响到外面**），捕获列表可为空，或指定捕获方式：有 `&` 符号前缀的变量通过 [引用](https://oi-wiki.org/lang/reference/) 访问，没有该前缀的变量通过值访问
> 2. 传参
> 3. 可加可不加，用于说明要不要修改capture的内容
> 4. 返回类型，可以不加
> 5. 函数体

















