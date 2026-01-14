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

![image-20250430095018624](https://houlir2.dpdns.org/2025/10/04f1efc180db055642d18e09d7b185cf.png)

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

![image-20250430095856923](https://houlir2.dpdns.org/2025/10/1edab95aa08736d4b6797243dc48c3c0.png)

![image-20250430095913315](https://houlir2.dpdns.org/2025/10/3894c79a62b0a3f86c094e5d78eccb9c.png)

## 64位的编译器指针占8个字节

![image-20250430100424783](https://houlir2.dpdns.org/2025/10/c452dc9e160c309c600b3ade4abb0b5f.png)

也就是说 CPU 可以访问 2^64^ 个内存地址

## 内存对齐

CPU 读取内存是按照块来读取的，而一个块可以包含2、4、8、16字节。现在64位的操作系统对应的一块也就是8个字节，也就是cpu一次性能处理64位的数据

![image-20250430115917711](https://houlir2.dpdns.org/2025/10/411b5d93275923f9d5e7e0bacb6549ca.png)

就浪费了资源，所以一定需要内存对齐，好处是：

![image-20250430115955699](https://houlir2.dpdns.org/2025/10/4dc167e31036997be41b043cd1c7d122.png)



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

### 递归

**每次写递归，都按照这三要素来写，可以保证大家写出正确的递归算法！**

1. **确定递归函数的参数和返回值：** 确定哪些参数是递归的过程中需要处理的，那么就在递归函数里加上这个参数， 并且还要明确每次递归的返回值是什么进而确定递归函数的返回类型。
2. **确定终止条件：** 写完了递归算法, 运行的时候，经常会遇到栈溢出的错误，就是没写终止条件或者终止条件写的不对，操作系统也是用一个栈的结构来保存每一层递归的信息，如果递归没有终止，操作系统的内存栈必然就会溢出。
3. **确定单层递归的逻辑：** 确定每一层递归需要处理的信息。在这里也就会重复调用自己来实现递归的过程。

### 递归返回值

递归函数什么时候需要返回值？什么时候不需要返回值？这里总结如下三点：

- 如果需要**搜索整棵二叉树且不用处理递归返回值，递归函数就不要返回值**。（这种情况就是本文下半部分介绍的[113.路径总和ii](https://leetcode.cn/problems/path-sum-ii/description/)）
- 如果需要**搜索整棵二叉树且需要处理递归返回值，递归函数就需要返回值**。 （这种情况我们在[236. 二叉树的最近公共祖先 (opens new window)](https://programmercarl.com/0236.二叉树的最近公共祖先.html)中介绍）
- 如果要**搜索其中一条符合条件的路径，那么递归一定需要返回值，因为遇到符合条件的路径了就要及时返回**。（本题的情况：[112. Path Sum](https://leetcode.cn/problems/path-sum/)）

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

## 线段树

主要用来**解决最大区间和，最大子段和，最长连续上升子序列的问题**。可以将$\Omicron(n)$的复杂度降为O(logn)。

线段树可以算作一种数据结构，不算具体的算法。是一种二叉树，对于一个线段（区间）而言，用二叉树来表示，如：

![在这里插入图片描述](https://houlir2.dpdns.org/2025/10/e4ec587583428283dc6210d4d2a0d8eb.png)

### 建树

我们设一个结构体 `tree`，`tree[i].l` 与 `tree[i].r` 分别表示这个点代表的线段的左右下标，`tree[i].sum` 表示这个节点表示的线段和，`tree[i].lazy`表示这个节点的懒标记。

```cpp
// 线段树节点存储的区间信息
struct node {
    long l,r,sum,lz;
} tree[N];
long nums[N];

// 递归建树
void build(int i, int l, int r) {
    tree[i].lazy = 0;
    tree[i].l = l;
    tree[i].r = r;
    // 如果当前是叶子节点，l == r == nullptr
    if (l == r) {
        // l 和 r 才是原始数据 nums 的索引范围。
        tree[i].sum = nums;
        return;
    }
    int mid = (l + r) >> 1;
    // 递归构造左右子树
    build(i << 1, l, mid);
    build((i << 1) + 1, mid + 1, r);
    // 当前区间和为左右子区间的总和
    tree[i].sum = tree[i << 1].sum + tree[(i << 1) + 1].sum;
}
```

### 无pushdown的线段树

#### 区间查询

线段树的查询方法：

1. 如果这个区间**被完全包括在目标区间里面**，直接返回这个区间的值
2. 如果没有交集，返回0
3. 如果这个区间的**左儿子和目标区间有交集**，那么搜索左儿子
4. 如果这个区间的**右儿子和目标区间有交集**，那么搜索右儿子

```cpp
// 区间查询
int search(int i, int l, int r) {
    // 情况1：
    if (tree[i].l >= l && tree[i].r <= r)
        return tree[i].sum;
    // 情况2：
    if （tree[i].l < l || tree[i].r > r）
    int s = 0;
    
    // 情况3：
    if (tree[i << 1].r >= l)
        s += search(i << 1, l, r);
    // 情况4：
   	if (tree[(i << 1) + 1].l <= r)
        s += search((i << 1) + 1, r);
    return s;
}
```

#### 单点修改

然后,我们怎么修改这个区间的单点，其实这个相对简单很多，你要把区间的第index位加上k。

那么你从根节点开始，看这个index是在左儿子还是在右儿子，在哪往哪跑，

然后返回的时候，还是按照`tree[i].sum=tree[i*2].sum+tree[i*2+1].sum`的原则，更新所有路过的点

![在这里插入图片描述](https://houlir2.dpdns.org/2025/10/94bd65a50184567517b1c1445b8b30b9.png)

```cpp
// 单点修改
void add(int i, int index, int k) {
    // 如果是叶子节点说明找到了，对齐进行修改：
    if (tree[i].l == tree[i].r) {
        tree[i].sum += k;
        return;
    }
    // 如果没找到，那就去找左右子树，看他在哪里
    // 左
    if (index < tree[i << 1].r)
        add(i << 1, index, k);
    // 右
    else
        add((i << 1) + 1, index, k);
    // 返回更新上面的值
    tree[i].sum = tree[i << 1].sum + tree[(i << 1) + 1].sum;
    return;
}
```

#### 区间修改

区间修改和单点查询，我们的思路就变为：**如果把这个区间加上 k  ，相当于把这个区间涂上一个 k  的标记，然后单点查询的时候，就从上跑到下，把沿路的标记加起来就好**。

这里面给区间贴标记的方式与上面的区间查找类似，原则还是那三条，只不过**第一条：如果这个区间被完全包括在目标区间里面，直接返回这个区间的值变为了如果这个区间如果这个区间被完全包括在目标区间里面，则加上这个区间标记 k **

```cpp
// 区间修改
void modify(int i, int l, int r, int k) {
    // 表示完全包含于[l, r]区间
    if (tree[i] >= r && tree[i] <= l) {
        tree[i].sum += k;
        return;
    }
    int mid = (tree[i].l + tree[i].r) >> 1;
    // 左区间包含，就相应修改左区间
    if (l <= mid)
        modify(i << 1, l, r, k);
    if (mid + 1 <= r)  // 等价于 mid < r
        // 等价于 x * 2 + 1
        modify(p << 1 | 1, l, r, k);
}

// 方法二：不用mid
void modify(int i, int l, int r, int k) {
    if (tree[i] >= r && tree[i] <= l) {
        tree[i].sum += k;
        return;
    }
    if (l <= tree[i << 1])
        modify(i << 1, l, r, k);
    if (tree[i << 1 | 1] <= r) 
        modify(p << 1 | 1, l, r, k);
}
```

#### 代码及题

[P3374 【模板】树状数组 1](https://www.luogu.com.cn/problem/P3374)

```cpp
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
#define MAXN 100010
#define INF 10000009
#define MOD 10000007
#define LL long long
#define in(a) a=read()
#define REP(i,k,n) for(long long i=k;i<=n;i++)
#define DREP(i,k,n) for(long long i=k;i>=n;i--)
#define cl(a) memset(a,0,sizeof(a))
inline long long read(){
    long long x=0,f=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
    for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
    return x*f;
}
inline void out(long long x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) out(x/10);
    putchar(x%10+'0');
}
long long n,m,p;
long long input[MAXN];
struct node{
    long long l,r;
    long long sum,mlz,plz;
}tree[4*MAXN];
inline void build(long long i,long long l,long long r){
    tree[i].l=l;
    tree[i].r=r;
    tree[i].mlz=1;
    if(l==r){
        tree[i].sum=input[l]%p;
        return ;
    }
    long long mid=(l+r)>>1;
    build(i<<1,l,mid);
    build(i<<1|1,mid+1,r);
    tree[i].sum=(tree[i<<1].sum+tree[i<<1|1].sum)%p;
    return ;
}
inline void pushdown(long long i){
    long long k1=tree[i].mlz,k2=tree[i].plz;
    tree[i<<1].sum=(tree[i<<1].sum*k1+k2*(tree[i<<1].r-tree[i<<1].l+1))%p;
    tree[i<<1|1].sum=(tree[i<<1|1].sum*k1+k2*(tree[i<<1|1].r-tree[i<<1|1].l+1))%p;
    tree[i<<1].mlz=(tree[i<<1].mlz*k1)%p;
    tree[i<<1|1].mlz=(tree[i<<1|1].mlz*k1)%p;
    tree[i<<1].plz=(tree[i<<1].plz*k1+k2)%p;
    tree[i<<1|1].plz=(tree[i<<1|1].plz*k1+k2)%p;
    tree[i].plz=0;
    tree[i].mlz=1;
    return ;
}
inline void mul(long long i,long long l,long long r,long long k){
    if(tree[i].r<l || tree[i].l>r)  return ;
    if(tree[i].l>=l && tree[i].r<=r){
        tree[i].sum=(tree[i].sum*k)%p;
        tree[i].mlz=(tree[i].mlz*k)%p;
        tree[i].plz=(tree[i].plz*k)%p;
        return ;
    }
    pushdown(i);
    if(tree[i<<1].r>=l)  mul(i<<1,l,r,k);
    if(tree[i<<1|1].l<=r)  mul(i<<1|1,l,r,k);
    tree[i].sum=(tree[i<<1].sum+tree[i<<1|1].sum)%p;
    return ;
}
inline void add(long long i,long long l,long long r,long long k){
    if(tree[i].r<l || tree[i].l>r)  return ;
    if(tree[i].l>=l && tree[i].r<=r){
        tree[i].sum+=((tree[i].r-tree[i].l+1)*k)%p;
        tree[i].plz=(tree[i].plz+k)%p;
        return ;
    }
    pushdown(i);
    if(tree[i<<1].r>=l)  add(i<<1,l,r,k);
    if(tree[i<<1|1].l<=r)  add(i<<1|1,l,r,k);
    tree[i].sum=(tree[i<<1].sum+tree[i<<1|1].sum)%p;
    return ;
}
inline long long search(long long i,long long l,long long r){
    if(tree[i].r<l || tree[i].l>r)  return 0;
    if(tree[i].l>=l && tree[i].r<=r)
        return tree[i].sum;
    pushdown(i);
    long long sum=0;
    if(tree[i<<1].r>=l)  sum+=search(i<<1,l,r)%p;
    if(tree[i<<1|1].l<=r)  sum+=search(i<<1|1,l,r)%p;
    return sum%p;
}
int main(){
    in(n);    in(m);in(p);
    REP(i,1,n)  in(input[i]);
    build(1,1,n); 

    REP(i,1,m){
        long long fl,a,b,c;
        in(fl);
        if(fl==1){
            in(a);in(b);in(c);
            c%=p;
            mul(1,a,b,c);
        }
        if(fl==2){
            in(a);in(b);in(c);
            c%=p;
            add(1,a,b,c);
        }
        if(fl==3){
            in(a);in(b);
            printf("%lld\n",search(1,a,b));
        }
    }
    return 0;
}
/*
5 4 1000
1 2 3 4 5
3 1 5
2 1 5 1
1 1 5 2

3 1 5
*/ 
```



#### 单点查询

然后就是单点查询了，这个更好理解了，就是index在哪往哪跑，**把路径上所有的标价加上**就好了，是对于区间修改后的，需要向上去回溯修改的情况

```cpp
// 单点查询
void query(int i, int index) {
    // 将一路上区间修改后的未进行回溯修改的元素，在这里进行统一的处理
    res += tree[i].sum;
    // 如果是叶子就结束
    if (tree[i].l == tree[i].r)
        return;
   int mid = (tree[i].l + tree[i].r) >> 1;
    if (index <= mid)
        query(i << 1, index);
    else 
        query(i << 1 | 1, index);
}
```

> **为什么需要把路上的 sum  加起来：**
>
> 因为我们在进行区间修改的时候，若当前区间已经被完全包含在目标区间 [ l , r ] [l,r][*l*,*r*] 里，直接将该区间 `tree[i].num += k`，不需要再继续往下走了，类似 lazy 标记，所以单点查询的时候要再加上路径上的值（即原本的权值再加上经过的若干次修改的值才是这个单点的值）。

#### 代码及题

洛谷 [P3368 【模板】树状数组 2](https://www.luogu.com.cn/problem/P3368)：

```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 7;

int n, m, s, t;
int ans;
int a[maxn];
struct segment_tree
{	
	struct node
	{
		int l, r;
		int num;
	}tr[maxn * 4];
	
	void build(int p, int l, int r)
	{
		tr[p] = {l, r, 0};
		if(l == r) {
			tr[p].num = a[l];
			return ;
		}
		int mid = l + r >> 1;
		build(p << 1, l, mid);
		build(p << 1 | 1, mid + 1, r);
	}		
	
	void modify(int p, int l, int r, int k) 
	{
		if(tr[p].l >= l && tr[p].r <= r) {
			tr[p].num += k;
			return ;
		}
		int mid = tr[p].l + tr[p].r >> 1;
		if(l <= mid) modify(p << 1, l, r, k);
		if(r > mid) modify(p << 1 | 1, l, r, k);
	}
	
	void query(int p, int x)
	{
		ans += tr[p].num;
		if(tr[p].l == tr[p].r) return;
		int mid = tr[p].l + tr[p].r >> 1;
		if(x <= mid) query(p << 1, x);
		else query(p << 1 | 1, x); 
	}
}ST;

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) {
	    scanf("%d", &a[i]);
	}
	ST.build(1, 1, n);
    for (int i = 1; i <= m; ++ i) {
        int c;
        scanf("%d", &c);
        if(c == 1) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            ST.modify(1, x, y, z);
        }
        else {
            ans = 0;
            int x;
            scanf("%d", &x);
            ST.query(1, x);
            printf("%d\n", ans);
        }
    }
	return 0;
}
/*
int main()
{
	n = 100;
	for (int i = 1; i <= n; ++ i) {
		a[i] = i;
	}
	ST.build(1, 1, n);
	m = 10;
	for (int i = 1; i <= m; ++ i) {
		int l = 1, r = 100;
		ST.modify(1, l, r, 10000);
		ans = 0;
		// query(p, x), p = 1, x 为想要查询的点的下标
		ST.query(1, 50); // 单点查询 下标为 50 的点的值，ans = 50 + 10000 * i
		cout << i << " " << ans << '\n';
		ans = 0;
		ST.query(1, 100); // 单点查询 ans = 100 + 10000 * i
		cout << i << " " << ans << '\n'; 
	}
	return 0;
}
*/

```

### pushdown的线段树（lazy标记）

#### 区间修改

是不能直接将区间修改和区间查询组合在一起的，这时候就需要添加`懒标记lazytag`来记录区间的标记

> **懒标记（Lazy Tag）** 是一种**延迟更新**技术，核心作用是**减少不必要的递归操作，优化区间更新的效率**。
>
> 懒标记的思路是：**当更新一个区间时，如果当前节点的区间完全被目标区间包含，就不继续递归更新其子节点，而是在当前节点记录一个 “待更新标记”（即懒标记），表示 “该节点的所有子节点需要执行这个更新，但暂时先不执行”**。等到后续需要查询或更新该节点的子节点时，再把这个标记 “下放”（`pushDown`）到子节点，完成实际的更新。
>
> 这样可以**把多次对同一区间的更新合并，减少递归次数**，确保区间更新和查询的时间复杂度始终保持 `O(log n)`。

**区间修改的时候，我们按照如下原则：**

1. 如果当前**区间被完全覆盖在目标区间**里，将这个区间的 `sum + k * (tree[i].r - tree[i].l + 1)`

   也就是**加上这个子区间里要修改的个数乘修改的值即可**

2. 如果**没有完全覆盖，则先下传懒标记**

3. 如果这个区间的左儿子和目标区间有交集，那么搜索左儿子

4. 如果这个区间的右儿子和目标区间有交集，那么搜索右儿子

然后查询的时候，将这个懒标记下传就好了，下面图解一下：

如图，区间 1 ∼ 4 分别是 1 、 2 、 3 、 4 ，我们要把 1 ∼ 3 区间 + 1 。因为 1 ∼ 2 区间被完全覆盖，所以将其 + 2 （1~2区间的父节点），并将**紫色的 lazytag** + 1，3 区间同理

![在这里插入图片描述](https://houlir2.dpdns.org/2025/10/7e046fce3b2d27a12423d892d67be214.png)

> 这里在线段【1,2】的紫色lazytag + 1 是因为之后查询的时候要将它所有孩子节点都 + 1，所以叫做pushdown。线段【3,3】同理，因为【3,3】 仅仅是【3,4】的一部分，所以这个懒标记只能标记到3那（因为懒标记是标记对所有孩子的处理，而【4,4】不需要处理）

```cpp
// 区间修改
void add(int i, int l, int r, int k) {
    // 完全覆盖
    if (tree[i].l >= l && tree[i].r <= r) {
        tree[i].sum += k * (tree[i].r - tree[i].l + 1);
        // 记录懒标记，其值为需要将所有孩子节点加的值
        tree[i].lazy += k;
        return;
    }
    // 向下传递
    push_down(i);
    if (tree[i << 1].r >= l)
        add(i << 1, l, r, k);
    if (tree[i * 2 + 1].l <= r)
        add(i * 2 + 1, l, r, k);
    tree[i].sum = tree[i << 1].sum + tree[i * 2 + 1].sum;
}



// push_down就是将lazy标志归零，同时自己加上 k * ( r - l + 1)，而每个孩子加上k
void push_down(int i) {
    if (tree[i].lazy != 0) {
        // 先让左右儿子先加
        tree[i << 1].sum += tree[i].lazy;
        tree[i * 2 + 1].sum += tree[i].lazy;
        // 使左右分别求和加起来
        int mid = (tree[i].l + tree[i].r) >> 1;
        // 左孩子的范围是【左孩子.l，左右孩子的中间值】
        tree[i << 1].sum += tree[i].lazy * (mid - tree[i * 2].l + 1);
        // 同理，右孩子：【左右孩子中间值 + 1，右孩子.r】
        tree[i * 2 + 1].sum += tree[i].lazy * (tree[i * 2 + 1].r - mid);  // 这里之所以不用 +1 是因为 mid 的 +1 与 -1 低效了
        // 懒标记已使用，归零
        tree[i].lazy = 0;
    }
}
```

#### 区间查询

区间查询的情况也要像修改一样进行pushdown，这里用图模拟一下。我们要查询 2 ∼ 4区间的和，这是**查询前**的情况（**此时非叶子节点的懒标记的值已经修改过了（区间修改后的值），但是它的子节点都还没修改，这时就是在查询的时候进行的修改**），所有**紫色的代表 lazytag，红色表示值，蓝色表示区间序号**

![在这里插入图片描述](https://houlir2.dpdns.org/2025/10/59b77800c67efd4898c40b8e25273781.png)

然后，我们查到区间 **1 ∼ 2时，发现这个区间并没有被完全包括在目标区间里，于是我们就pushdown，lazytag下传**，并让每个区间 sum 加上 ( r − l ) × lazytag 。

![在这里插入图片描述](https://houlir2.dpdns.org/2025/10/8bce838aa79434169f7e9682e03fbece.png)

然后查到 2 ∼ 2区间，发现被完全包含，所以就返 3 ，再搜索到 3 ∼ 4  区间，发现被完全包含，那么直接返回 8，最后 3 + 8 = 11 就是答案

```cpp
int search(int i, int l, int r) {
    if (tree[i].l >= l && tree[i].r <= r)
        return tree[i].sum;
    if (tree[i].r < l || tree[i].l > r)
        return 0;
    push_down(i);
    int s = 0;
    if (tree[i << 1].r >= l)
        s += search(i << 1, l, r);
    if (tree[i * 2 + 1].l <= r)
        s += search(i * 2 + 1, l, r);
    return s;
}
```

#### 代码和题

[P3372 【模板】线段树 1](https://www.luogu.com.cn/problem/P3372)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+7;
const ll mod=2147483647;
ll n,m;
struct node
{
    ll l,r,sum,lz;
}tree[N];
ll arr[N];
void build(ll i,ll l,ll r,ll arr[])
{
    tree[i].lz=0;//初始化的时候肯定都是0
    tree[i].l=l;
    tree[i].r=r;
    if(l==r)
    {
        tree[i].sum=arr[l];//到达底部单节点才把输入的值赋给你
        return ;
    }
    ll mid=(l+r)/2;
    build(i*2,l,mid,arr);
    build(i*2+1,mid+1,r,arr);
    tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;//树已经全部建完了，再从下往上+++，使得上层的树都有了值
    return ;
}
inline void push_down(ll i)
{
    if(tree[i].lz!=0)
    {
        tree[i*2].lz+=tree[i].lz;
        tree[i*2+1].lz+=tree[i].lz;
        ll mid=(tree[i].l+tree[i].r)/2;
        tree[i*2].sum+=tree[i].lz*(mid-tree[i*2].l+1);
        tree[i*2+1].sum+=tree[i].lz*(tree[i*2+1].r-mid);
        tree[i].lz=0;
    }
    return ;
}
inline void add(ll i,ll l,ll r,ll k)
{
    if(tree[i].l>=l&&tree[i].r<=r)
    {
        tree[i].sum+=k*(tree[i].r-tree[i].l+1);
        tree[i].lz+=k;
        return ;
    }
    push_down(i);
    if(tree[i*2].r>=l)
        add(i*2,l,r,k);
    if(tree[i*2+1].l<=r)
        add(i*2+1,l,r,k);
    tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
    return ;
}
inline ll searchs(ll i,ll l, ll r)
{
    if(tree[i].l>=l&&tree[i].r<=r)
        return tree[i].sum;
    push_down(i);
    ll num=0;
    if(tree[i*2].r>=l)
        num+=searchs(i*2,l,r);
    if(tree[i*2+1].l<=r)
        num+=searchs(i*2+1,l,r);
    return num;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>arr[i];
    build(1,1,n,arr);//从根节点开始建树
    for(int i=1;i<=m;++i)
    {
        ll tmp;
        cin>>tmp;
        if(tmp==1)
        {
            ll a,b,c;
            cin>>a>>b>>c;
            add(1,a,b,c);//每次修改都是从编号为1开始的，因为编号1是树的顶端，往下分叉
        }
        if(tmp==2)
        {
            ll a,b;
            cin>>a>>b;
            printf("%lld\n",searchs(1,a,b));//编号i的话，每次都是从1开始
        }
    }
    return 0;
}
```



### 乘法线段树

[P3373 【模板】线段树 2](https://www.luogu.com.cn/problem/P3373)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+7;
template<typename T>void read(T &x)
{
    x=0;char ch=getchar();ll f=1;
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}x*=f;
}
ll n,m,arr[N],mod,flag,cn,cm,cw;
struct node
{
    ll l,r,sum,mul,add;//有乘有加，先乘后加
}tree[N];

inline void build(ll i,ll l,ll r)
{
    tree[i].l=l;
    tree[i].r=r;
    tree[i].mul=1;
    if(l==r)
    {
        tree[i].sum=arr[l]%mod;
        return ;
    }
    ll mid=(l+r)>>1;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    tree[i].sum=(tree[i*2].sum+tree[i*2+1].sum)%mod;
}
inline void push_down(ll i)
{
    tree[i*2].sum=(ll)(tree[i].mul*tree[i*2].sum+((tree[i*2].r-tree[i*2].l+1)*tree[i].add)%mod)%mod;
    tree[i*2+1].sum=(ll)(tree[i].mul*tree[i*2+1].sum+((tree[i*2+1].r-tree[i*2+1].l+1)*tree[i].add)%mod)%mod;
    tree[i*2].mul=(ll)(tree[i*2].mul*tree[i].mul)%mod;
    tree[i*2+1].mul=(ll)(tree[i*2+1].mul*tree[i].mul)%mod;
    tree[i*2].add=(ll)(tree[i*2].add*tree[i].mul+tree[i].add)%mod;
    tree[i*2+1].add=(ll)(tree[i*2+1].add*tree[i].mul+tree[i].add)%mod;
    tree[i].mul=1;tree[i].add=0;
}
inline void add(ll i,ll l,ll r,ll k)
{
    if(tree[i].l>=l&&tree[i].r<=r)
    {
        tree[i].add=(ll)(tree[i].add+k)%mod;
        tree[i].sum=(ll)(tree[i].sum+k*(tree[i].r-tree[i].l+1))%mod;
        return ;
    }
    push_down(i);
  
    if(tree[i*2].r>=l)
        add(i*2,l,r,k);
    if(tree[i*2+1].l<=r)
        add(i*2+1,l,r,k);
    //ll mid=(tree[i].l+tree[i].r)>>1;
    //if(l<=mid)add(i*2,l,r,k);
    //if(mid<r)add(i*2+1,l,r,k);
    tree[i].sum=(tree[i*2].sum+tree[i*2+1].sum)%mod;
}
inline void mult(ll i,ll l,ll r,ll k)
{
    if(tree[i].l>=l&&tree[i].r<=r)
    {
        tree[i].mul=(tree[i].mul*k)%mod;
        tree[i].add=(tree[i].add*k)%mod;
        tree[i].sum=(tree[i].sum*k)%mod;
        return ;
    }
    push_down(i);
  
    if(tree[i*2].r>=l)
        mult(i*2,l,r,k);
    if(tree[i*2+1].l<=r)
        mult(i*2+1,l,r,k);
    //ll mid=(tree[i].l+tree[i].r)>>1;
    //if(l<=mid)mult(i*2,l,r,k);
    //if(mid<r)mult(i*2+1,l,r,k);
    tree[i].sum=(tree[i*2].sum+tree[i*2+1].sum)%mod;
}
inline ll query(ll i,ll l,ll r)
{
    if(tree[i].l>=l&&tree[i].r<=r)
        return tree[i].sum;
    push_down(i);
    ll num=0;
    if(tree[i*2].r>=l)
        num=(num+query(i*2,l,r))%mod;
    if(tree[i*2+1].l<=r)
        num=(num+query(i*2+1,l,r))%mod;
    return num;
    //ll val=0;
    //ll mid=(tree[i].l+tree[i].r)>>1;
    //if(l<=mid)val=(val+query(i*2,l,r))%mod;
    //if(mid<r)val=(val+query(i*2+1,l,r))%mod;
    //return val;
}
int main()
{
    read(n),read(m),read(mod);
    for(int i=1;i<=n;++i)
        read(arr[i]);
    build(1,1,n);
    for(int i=1;i<=m;++i)
    {
        read(flag);
        if(flag==1)
        {
            read(cn),read(cm),read(cw);
            mult(1,cn,cm,cw);
        }
        else if(flag==2){
            read(cn),read(cm),read(cw);
            add(1,cn,cm,cw);
        }
        else {
            read(cn),read(cm);
            cout<<query(1,cn,cm)<<endl;
        }
    }
}
/*
5 4 1000
1 2 3 4 5
3 1 5
2 1 5 1
1 1 5 2

3 1 5
*/ 
```

### 根号线段树

## 树总结

![img](https://houlir2.dpdns.org/2025/10/205934d55294ca715995e46c00705ca6.png)

# 回溯算法

**回溯就是递归，也是穷举**。虽然效率低，但是对一些只能穷举的问题来说，是最优解，如：

- 组合问题：N个数里面按一定规则找出k个数的集合
- 切割问题：一个字符串按一定规则有几种切割方式
- 子集问题：一个N个数的集合里有多少符合条件的子集
- 排列问题：N个数按一定规则全排列，有几种排列方式
- 棋盘问题：N皇后，解数独等等





## 回溯算法的框架

一般可以**以backtracking命名**

**模板：**

```cpp
void backtracking(参数) {
    if (终止条件) {
        存放结果;
        return;
    }

    for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
        处理节点;	// 如插入子vector
        backtracking(路径，选择列表); // 递归
        回溯，撤销处理结果	// 如vec.pop_back()也是回溯
    }
}
```

**例如：**

```cpp
private:
	vector<vector<int>> res;
	vector<int> t;
	
	void backTracking(vector<int> nums, int start) {
        if () {
            res.push_back(t);
            return
        }
        
        for (int i = start; i < nums.size(); i++) {
            t.push_back(nums[i]);
            backTracking(nums, i + 1);
            t.pop_back();
        }
    }
```

其中，for表示横向遍历（也就是树中孩子个数），回溯递归就是竖向遍历（树的深度）

![回溯算法理论基础](https://houlir2.dpdns.org/2025/10/180ebfb7736ebf037db9ce9359feba7a.png)

## 回溯算法的返回值

递归函数什么时候需要返回值？什么时候不需要返回值？这里总结如下三点：

- 如果需要**搜索整棵二叉树且不用处理递归返回值，递归函数就不要返回值**。（这种情况就是本文下半部分介绍的[113.路径总和ii](https://leetcode.cn/problems/path-sum-ii/description/)）——**排列个数、组合个数**
- 如果需要**搜索整棵二叉树且需要处理递归返回值，递归函数就需要返回值**。 （这种情况我们在[236. 二叉树的最近公共祖先 (opens new window)](https://programmercarl.com/0236.二叉树的最近公共祖先.html)中介绍）
- 如果要**搜索其中一条符合条件的路径，那么递归一定需要返回值，因为遇到符合条件的路径了就要及时返回**。（本题的情况：[112. Path Sum](https://leetcode.cn/problems/path-sum/)）

## 回溯总结

![img](https://houlir2.dpdns.org/2025/10/6f1906ca0132a935ea8da094390658d5.png)

# 贪心算法

贪心算法没有固定的套路，主要是需要自己尝试一下，能不能在某些地方去进行贪心，一个问题能用贪心解决，必须满足三个核心条件：

- **最优子结构**：全局最优解**包含子问题的最优解**（这一点和动态规划一致）。
- **贪心选择性质**：**全局最优解可以通过一系列 “局部最优选择” 得到**（即不考虑未来决策，只选当前最优，最终能拼出全局最优）。
- 找不到任何的反例是不符合上述条件的

> 贪心的使用中，大多数是要用到max和min的，所以重点可能就在于如何合理恰当的运用max和min，当然不是每道题都是

如一些`最`的问题上，比如最短路径，最大字数组合等

严格的数据证明一般有如下两种：

- 数学归纳法
- 反证法

总结：

![img](https://houlir2.dpdns.org/2025/12/0ddc4da350311fd343dbc21f8bc82f31.png)

# 动态规划DP

## 模板

> 二者区别：**动规是由前一个状态推导出来的（如果原本应为1，但前者是0，可能就推出之后的都是0了），而贪心是局部直接选最优的**

**这五步都搞清楚了，才能说把动态规划真的掌握了！**

1. 确定dp数组（dp table）以及下标的含义
2. 确定递推公式
3. dp数组如何初始化（需要根据地推公式来决定如何初始化）
4. 确定遍历顺序（从前往后/从后往前）
5. 举例推导dp数组（草稿纸验证）

**动态规划的思路是根据子问题的求解推导出整体的最优解。也就是类似贪心的思想，但是需要加上递推式**

## 背包问题

主要是01背包和完全背包

![416.分割等和子集1](https://houlir2.dpdns.org/2025/12/79a530037716def50178945a56d1cbb8.png)

除此以外其他类型的背包，面试几乎不会问，都是竞赛级别的了，leetcode上连多重背包的题目都没有，所以题库也告诉我们，01背包和完全背包就够用了。

而完全背包又是也是01背包稍作变化而来，即：完全背包的物品数量是无限的。

### 背包问题的具体化求解过程

总结得出，对**求最大个数时，dp[0]初始化为1，用max，且递推式里用+1；求总和时用+=；求价值时用+value[i]。求最小个数时，初始化为INT_MAX，用min，且递推式里用+1**

### 01背包

https://kamacoder.com/problempage.php?pid=1046

1. 二维dp数组

   01背包中二维dp数组的**两个for遍历的先后循序是可以颠倒的**

   ```cpp
   #include <algorithm>
   #include <iostream>
   #include <vector>
   using namespace std;
    
   int main() {
     int n, bagWeight;
     cin >> n >> bagWeight;
     vector<int> weight(n), value(n);
     for (int i = 0; i < n; i++) {
       cin >> weight[i];
     }
     for (int i = 0; i < n; i++) {
       cin >> value[i];
     }
     // dp[i][j] 表示背包重量为j时，必须选取物品i时所能达到的最大价值
     vector<vector<int>> dp(n, vector<int>(bagWeight + 1));
     // 6 1
     // 2 2 3 1 5 2
     // 2 3 1 5 4 3
     //     0   1
     // w1  0   0
     // w2  0   0
     // w3  0   0
     // w4  0   0
     // w5  0   5
     // w6  0   0
     // 初始化dp表，其中第0列都应该设为0（重量0）
     for (int i = 0; i < n; i++) {
       dp[i][0] = 0;
     }
     // 第一行应该是第一个物品的按照背包容量能否拿到价值
     for (int j = 1; j <= bagWeight; j++) {
       if (weight[0] <= j)
         dp[0][j] = value[0];
     }
    
     // 先选取合适的空间
     // i 为第i个物品
     for (int i = 1; i < n; i++) {
       // 从前往后遍历
       // j为背包空间
       for (int j = 0; j <= bagWeight; j++) {
         // 如果当前背包容纳不下第i个物品，则价值用上一个i-1物品的最大价值
         if (weight[i] > j)
           dp[i][j] = dp[i - 1][j];
         // 如果容纳的了，就看是否能容纳两个
         else
           dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
       }
     }
     cout << dp[n - 1][bagWeight];
     return 0;
   }
   ```

2. 一维滚动数组

   **01背包下的一维dp数组**的两个for循环先后循序**一定是先遍历物品，再遍历背包容量**。

   **01 背包要求 “每个物品只能选 1 次”，所以必须用逆序遍历**

   ```cpp
   #include <algorithm>
   #include <iostream>
   #include <vector>
   using namespace std;
    
   int main() {
     int n, bagWeight;
     cin >> n >> bagWeight;
     vector<int> weight(n), value(n);
     for (int i = 0; i < n; i++) {
       cin >> weight[i];
     }
     for (int i = 0; i < n; i++) {
       cin >> value[i];
     }
     // 用一维滚动数组来代替二维的dp表。dp[j] 表示容量为j的背包，价值总和最大是多少。
     vector<int> dp(bagWeight + 1, 0);
    
     // 先选取合适的空间
     // i 为第i个物品
     for (int i = 0; i < n; i++) {
       // j为背包空间
       // 用一维dp表只能后续遍历背包打造
       for (int j = bagWeight; j >= weight[i]; j--) {
           // 只需去掉[i]这一维度即可
           dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
       }
     }
     cout << dp[bagWeight];
     return 0;
   }
   ```


### 完全背包

https://kamacoder.com/problempage.php?pid=1052

**相比于01背包，只改动了初始化和dp递推式**

1. 二维dp表

   ```cpp
   #include <algorithm>
   #include <iostream>
   #include <vector>
   using namespace std;
    
   int main() {
     int n, bagWeight;
     cin >> n >> bagWeight;
     vector<int> weight(n), value(n);
     for (int i = 0; i < n; i++) {
       cin >> weight[i];
       cin >> value[i];
     }
     // dp[i][j] 表示背包重量为j时，必须选取物品i时所能达到的最大价值
     vector<vector<int>> dp(n, vector<int>(bagWeight + 1, 0));
     // 4 5
     // weight: 1 2 3 4
     // value:  2 4 4 5 
     //     0   1  2   3   4   5
     // w1  0   2  4   6   8   10
     // w2  0   2  4   6   8   10
     // w3  0   2
     // w4  0   2
     // 初始化dp表，其中第一行应该是第一个物品的按照背包容量能否拿到价值
     // 相比于01背包，只改动了初始化和dp递推式
     for (int j = weight[0]; j <= bagWeight; j++) {
       dp[0][j] = dp[0][j - weight[0]] + value[0];
     }
    
     // 先选取合适的空间
     // i 为第i个物品
     for (int i = 1; i < n; i++) {
       // 从前往后遍历
       // j为背包空间
       for (int j = 0; j <= bagWeight; j++) {
         // 如果当前背包容纳不下第i个物品，则价值用上一个i-1物品的最大价值
         if (weight[i] > j)
           dp[i][j] = dp[i - 1][j];
         // 如果容纳的了，就看是否能容纳两个
         else
           // 相比于01背包，只改动了初始化和dp递推式
           dp[i][j] = max(dp[i - 1][j], dp[i][j - weight[i]] + value[i]);
       }
     }
     cout << dp[n - 1][bagWeight];
     return 0;
   }
   ```

2. 一维dp数组

   **在完全背包中，对于一维dp数组来说，两个循环都是正序遍历（每个物品可以选无限次，所以可以正序），而且本题中的两层for循环顺序是无所谓的**！

   但在求排列和组合的情况下，就不能颠倒顺序了：

   **如果求组合数就是外层for循环遍历物品，内层for遍历背包**。

   **如果求排列数就是外层for遍历背包，内层for循环遍历物品**。

   1. 先遍历物品（组合）：
   
      ```cpp
      #include <algorithm>
      #include <iostream>
      #include <vector>
      using namespace std;
       
      int main() {
        int n, bagWeight;
        cin >> n >> bagWeight;
        vector<int> weight(n), value(n);
        for (int i = 0; i < n; i++) {
          cin >> weight[i];
          cin >> value[i];
        }
        // 一维滚动dp数组实现——初始化为0即可
        vector<int> dp(bagWeight + 1, 0);
      
        // 先遍历物品
        for (int i = 0; i < n; i++) {
          // 再遍历背包
          for (int j = 0; j <= bagWeight; j++) {
            if (j - weight[i] >= 0)
              dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
          }
        }
        cout << dp[bagWeight];
        return 0;
      }
      ```
   
   2. 先遍历背包（排列）：
   
      ```cpp
      for (int j = 0; j <= bagWeight; j++) {
          for (int i = 0; i < weight.size(); i++) {
              if (j - weight[i] >= 0)
                  dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
          }
      }
      ```
   

### 多重背包

该背包面试基本不考，但也需练习。本质是将m件物品摊开，化为m行的01背包中的一个物品，接着按照01背包思路即可——选与不选

![image-20251211155037836](https://houlir2.dpdns.org/2025/12/5fe814c4ff95067911e3a082800a4c8e.png)

https://kamacoder.com/problempage.php?pid=1066

- 自己写+gpt更正——三重遍历的01背包 + 一个遍历个数：

```cpp
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int main() {
    int bagSize = 0, n;
    cin >> bagSize >> n;
    vector<int> weight(n), value(n), count(n);
    // n个矿石的重量
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    // n个矿石的价值
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }
    // n个矿石的可用数量上限
    for (int i = 0; i < n; i++) {
        cin >> count[i];
    }

    vector<vector<int>> dp(n, vector<int>(bagSize + 1, 0));

    // 初始化第一行
    for (int j = 1; j <= bagSize; j++) { // 从j=1开始，而非weight[0]，避免漏算
        // 核心：计算当前容量j下，物品0最多能装多少个（重量+数量双重限制）
        int max_num = min(count[0], j / weight[0]);
        dp[0][j] = max_num * value[0]; // 按实际可装数量计算价值
    }

    // 开始递推dp数组
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= bagSize; j++) {
            // 初始值为“不选当前物品i”的最优解 
            dp[i][j] = dp[i - 1][j];

            // 遍历当前物品i的可选数量k（1~count[i]），限制数量
            for (int k = 1; k <= count[i]; k++) {
                // 重量足够装k个物品i时，才计算价值
                if (j >= k * weight[i]) {
                    // 选k个物品i的价值 = 剩余容量的最优解 + k*价值
                    dp[i][j] = max(dp[i][j], dp[i-1][j - k*weight[i]] + k*value[i]);
                } else {
                    break; // 重量不够，无需尝试更多数量
                }
            }
        }
    }

    cout << dp[n - 1][bagSize];
    return 0;
}
```

### 背包递推公式

问能否能装满背包（或者最多装多少）：dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]); ，对应题目如下：

- [动态规划：416.分割等和子集(opens new window)](https://programmercarl.com/0416.分割等和子集.html)
- [动态规划：1049.最后一块石头的重量 II(opens new window)](https://programmercarl.com/1049.最后一块石头的重量II.html)

问装满背包有几种方法：dp[j] += dp[j - nums[i]] ，对应题目如下：

- [动态规划：494.目标和(opens new window)](https://programmercarl.com/0494.目标和.html)
- [动态规划：518. 零钱兑换 II(opens new window)](https://programmercarl.com/0518.零钱兑换II.html)
- [动态规划：377.组合总和Ⅳ(opens new window)](https://programmercarl.com/0377.组合总和Ⅳ.html)
- [动态规划：70. 爬楼梯进阶版（完全背包）(opens new window)](https://programmercarl.com/0070.爬楼梯完全背包版本.html)

问背包装满最大价值：dp[j] = max(dp[j], dp[j - weight[i]] + value[i]); ，对应题目如下：

- [动态规划：474.一和零(opens new window)](https://programmercarl.com/0474.一和零.html)

问装满背包所有物品的最小个数：dp[j] = min(dp[j - coins[i]] + 1, dp[j]); ，对应题目如下：

- [动态规划：322.零钱兑换(opens new window)](https://programmercarl.com/0322.零钱兑换.html)
- [动态规划：279.完全平方数(opens new window)](https://programmercarl.com/0279.完全平方数.html)

### [遍历顺序](https://programmercarl.com/背包总结篇.html#遍历顺序)

#### 01背包

在[动态规划：关于01背包问题，你该了解这些！ (opens new window)](https://programmercarl.com/背包理论基础01背包-1.html)中我们讲解二维dp数组01背包先遍历物品还是先遍历背包都是可以的，且第二层for循环是从小到大遍历。

和[动态规划：关于01背包问题，你该了解这些！（滚动数组） (opens new window)](https://programmercarl.com/背包理论基础01背包-2.html)中，我们讲解一维dp数组01背包只能先遍历物品再遍历背包容量，且第二层for循环是从大到小遍历。

**一维dp数组的背包在遍历顺序上和二维dp数组实现的01背包其实是有很大差异的，大家需要注意！**

#### [完全背包](https://programmercarl.com/背包总结篇.html#完全背包)

说完01背包，再看看完全背包。

在[动态规划：关于完全背包，你该了解这些！ (opens new window)](https://programmercarl.com/背包问题理论基础完全背包.html)中，讲解了纯完全背包的一维dp数组实现，先遍历物品还是先遍历背包都是可以的，且第二层for循环是从小到大遍历。

但是仅仅是纯完全背包的遍历顺序是这样的，题目稍有变化，两个for循环的先后顺序就不一样了。

**如果求组合数就是外层for循环遍历物品，内层for遍历背包**。

**如果求排列数就是外层for遍历背包，内层for循环遍历物品**。

相关题目如下：

- 求组合数：[动态规划：518.零钱兑换II(opens new window)](https://programmercarl.com/0518.零钱兑换II.html)
- 求排列数：[动态规划：377. 组合总和 Ⅳ (opens new window)](https://mp.weixin.qq.com/s/Iixw0nahJWQgbqVNk8k6gA)、[动态规划：70. 爬楼梯进阶版（完全背包）(opens new window)](https://programmercarl.com/0070.爬楼梯完全背包版本.html)

如果求最小数，那么两层for循环的先后顺序就无所谓了，相关题目如下：

- 求最小数：[动态规划：322. 零钱兑换 (opens new window)](https://programmercarl.com/0322.零钱兑换.html)、[动态规划：279.完全平方数(opens new window)](https://programmercarl.com/0279.完全平方数.html)

**对于背包问题，其实递推公式算是容易的，难是难在遍历顺序上，如果把遍历顺序搞透，才算是真正理解了**。

### 背包问题总结

![img](https://houlir2.dpdns.org/2025/12/f031cff7929672e8e978231430bbc0f0.jpeg)

# 单调栈

利用单调栈来做可以达到线性的复杂度，本质是用栈的开销了优化时间上的性能

比如求右边大于当前（左边）的，那就用递增的栈即可，分为两种情况处理：1.小于等于栈顶时入栈，大于栈顶时，出栈顶元素，直到小于等于当前，同时更新res表，再入栈。

# 图论

## dfs

### 框架

```cpp
vector<vector<int>> res; // 保存符合条件的所有路径
vector<int> path; // 起点到终点的路径
void dfs(参数) {
    if (终止条件) {
        存放结果;
        return;
    }

    for (选择：本节点所连接的其他节点) {
        处理节点;
        dfs(图，选择的节点); // 递归
        回溯，撤销处理结果
    }
}
```

### dfs判断节点能到达所有节点

```cpp
#include <iostream>
#include <vector>
#include <list>
using namespace std;
 
// 深度遍历完cur的可以到达的节点，并标记好visited
void dfs(vector<list<int>>& graph, vector<int>& visited, int cur) {
    if (visited[cur])
        return;
    visited[cur] = 1;
    for (auto& i : graph[cur]) {
        dfs(graph, visited, i);
    }
}
 
int main() {
    int vertex, edge, s, t;
    cin >> vertex >> edge;
    // 领接矩阵不方面判断顶点1到其他顶点是否有路径，但是邻接表方便
    vector<list<int>> graph(vertex + 1);
    // 表示各个顶点能否访问到
    vector<int> visited(vertex + 1, false);
    for (int i = 0; i < edge; i++) {
        cin >> s >> t;
        // s -> t
        graph[s].push_back(t); 
    }
 
    dfs(graph, visited, 1);
    for (int i = 1; i <= vertex; i++) {
        // 若有节点为0，说明该节点无法到达
        if (!visited[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << 1 << endl;
    return 0;
}
```



### 最大岛屿面积

```cpp
#include <iostream>
#include <vector>
using namespace std;
 
vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int count;
 
void dfs(vector<vector<int>>& graph, vector<vector<bool>>& visited, int row, int col) {
    // 遍历4个方向
    for (auto& dir : direction) {
        int nextRow = row + dir[0];
        int nextCol = col + dir[1];
        if (nextRow < 0 || nextCol < 0 || nextRow >= graph.size() || nextCol >= graph[0].size())
            continue;
        // 递归遍历相邻陆地
        if (!visited[nextRow][nextCol] && graph[nextRow][nextCol] == 1) {
            visited[nextRow][nextCol] = true;
            count++;
            dfs(graph, visited, nextRow, nextCol);
        }
    }
}
 
int main() {
    int rNum, cNum, res;
    cin >> rNum >> cNum;
    vector<vector<int>> graph(rNum, vector<int>(cNum, 0));
    // 版本二：用额外的标记数组
    vector<vector<bool>> visited(rNum, vector<bool>(cNum, false));
    for (int i = 0; i < rNum; i++) {
        for (int j = 0; j < cNum; j++) {
            cin >> graph[i][j]; 
        }
    }
 
    // 遍历整个矩阵，寻找未被访问的陆地（1）
    for (int i = 0; i < rNum; i++) {
        for (int j = 0; j < cNum; j++) {
            // 遇到陆地（且未被访问），计数+1，然后通过DFS标记该岛屿所有陆地为0
            if (!visited[i][j] && graph[i][j] == 1) {
                count = 1;
                // 立刻标记为访问，且dfs遍历每个连通分量的节点时，也标记上
                visited[i][j] = true;
                dfs(graph, visited, i, j);
                res = max(res, count);
            }
        }
    }
 
    cout << res;
    return 0;
}
```

### 求孤岛总面积

```cpp
#include <iostream>
#include <vector>
using namespace std;
int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1}; // 保存四个方向
void dfs(vector<vector<int>>& grid, int x, int y) {
    grid[x][y] = 0;
    for (int i = 0; i < 4; i++) { // 向四个方向遍历
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        // 超过边界
        if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;
        // 不符合条件，不继续遍历
        if (grid[nextx][nexty] == 0) continue;

        dfs (grid, nextx, nexty);
    }
    return;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // 从左侧边，和右侧边 向中间遍历
    for (int i = 0; i < n; i++) {
        if (grid[i][0] == 1) dfs(grid, i, 0);
        if (grid[i][m - 1] == 1) dfs(grid, i, m - 1);
    }
    // 从上边和下边 向中间遍历
    for (int j = 0; j < m; j++) {
        if (grid[0][j] == 1) dfs(grid, 0, j);
        if (grid[n - 1][j] == 1) dfs(grid, n - 1, j);
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) count++;
        }
    }
    cout << count << endl;
}
```



### 邻接矩阵dfs求连通分量个数

https://kamacoder.com/problempage.php?pid=1171

```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(vector<vector<int>>& graph, vector<vector<bool>>& visited, int row, int col) {
    // 遍历4个方向
    for (auto& dir : direction) {
        int nextRow = row + dir[0];
        int nextCol = col + dir[1];
        if (nextRow < 0 || nextCol < 0 || nextRow >= graph.size() || nextCol >= graph[0].size())
            continue;
        // 递归遍历相邻陆地
        if (!visited[nextRow][nextCol] && graph[nextRow][nextCol] == 1) {
            visited[nextRow][nextCol] = true;
            dfs(graph, visited, nextRow, nextCol);
        }
    }
}

int main() {
    int rNum, cNum, res = 0;
    cin >> rNum >> cNum;
    vector<vector<int>> graph(rNum, vector<int>(cNum, 0));
    // 版本二：用额外的标记数组
    vector<vector<bool>> visited(rNum, vector<bool>(cNum, false));
    for (int i = 0; i < rNum; i++) {
        for (int j = 0; j < cNum; j++) {
            cin >> graph[i][j]; 
        }
    }

    // 遍历整个矩阵，寻找未被访问的陆地（1）
    for (int i = 0; i < rNum; i++) {
        for (int j = 0; j < cNum; j++) {
            // 遇到陆地（且未被访问），计数+1，然后通过DFS标记该岛屿所有陆地为0
            if (!visited[i][j] && graph[i][j] == 1) {
                // 立刻标记为访问，且dfs遍历每个连通分量的节点时，也标记上
                visited[i][j] = true;
                res++;
                dfs(graph, visited, i, j);
            }
        }
    }

    cout << res;
    return 0;
}
```



### 邻接矩阵dfs求路径

```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> res;
vector<int> path;

void dfs(vector<vector<int>>& graph, int now, int n) {
    if (now == n) {
        res.push_back(path);
        return;
    }
    for (int i = 1; i <= n; i++) {
        // 表示当前有指向，那么dfs此路径
        if(graph[now][i] == 1) {
            path.push_back(i);
            dfs(graph, i, n);
            path.pop_back();
        }
    }
}

int main() {
    int vNum, eNum, row, col;
    cin >> vNum >> eNum;
    // 对齐位序
    vector<vector<int>> graph(vNum + 1, vector<int>(vNum + 1, 0));
    for (int i = 0; i < eNum; i++) {
        cin >> row >> col;
        graph[row][col] = 1;
    }
    path.push_back(1); // 无论什么路径已经是从1节点出发
    dfs(graph, 1, vNum);

    // 打印路径
    if (res.size() == 0) {
        cout << -1;
        return 0;
    }
    for (auto& i: res) {
        for (int j = 0; j < i.size() - 1; j++) {
            cout << i[j] << ' ';
        }
        cout << i[i.size() - 1] << endl;
    }
    return 0;
}
```

### 领接表dfs

```cpp
#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<vector<int>> res;
vector<int> path;

void dfs(vector<list<int>>& graph, int now, int n) {
    if (now == n) {
        res.push_back(path);
        return;
    }
    for (int i : graph[now]) {
        path.push_back(i);
        dfs(graph, i, n);
        path.pop_back();
    }
}

int main() {
    int vNum, eNum, vec, linkList;
    cin >> vNum >> eNum;
    // 对齐位序：用邻接表
    vector<list<int>> graph(vNum + 1);
    for (int i = 0; i < eNum; i++) {
        cin >> vec >> linkList;
        // 表示将依附于vec的节点加入链表中
        graph[vec].push_back(linkList);
    }

    path.push_back(1); // 无论什么路径已经是从1节点出发
    dfs(graph, 1, vNum);

    // 打印路径
    if (res.size() == 0) {
        cout << -1;
    }
    for (auto& i: res) {
        for (int j = 0; j < i.size() - 1; j++) {
            cout << i[j] << ' ';
        }
        cout << i[i.size() - 1] << endl;
    }
    return 0;
}
```

## bfs

也叫做Kahn卡恩算法

### 邻接矩阵岛屿问题模板

```cpp
int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1}; // 表示四个方向
// grid 是地图，也就是一个二维数组
// visited标记访问过的节点，不要重复访问
// x,y 表示开始搜索节点的下标
void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
    queue<pair<int, int>> que; // 定义队列
    que.push({x, y}); // 起始节点加入队列
    visited[x][y] = true; // 只要加入队列，立刻标记为访问过的节点
    while(!que.empty()) { // 开始遍历队列里的元素
        pair<int ,int> cur = que.front(); 
        que.pop(); // 从队列取元素
        int curx = cur.first;
        int cury = cur.second; // 当前节点坐标
        for (int i = 0; i < 4; i++) { // 开始向当前节点的四个方向左右上下去遍历
            int nextx = curx + dir[i][0];
            int nexty = cury + dir[i][1]; // 获取周边四个方向的坐标
            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;  // 坐标越界了，直接跳过
            if (!visited[nextx][nexty]) { // 如果节点没被访问过
                que.push({nextx, nexty});  // 队列添加该节点为下一轮要遍历的节点
                visited[nextx][nexty] = true; // 只要加入队列立刻标记，避免重复访问
            }
        }
    }
}
```

### bfs求连通分量个数

https://kamacoder.com/problempage.php?pid=1171

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
 
void bfs(vector<vector<int>>& graph, vector<vector<bool>>& visited, int x, int y) {
    // bfs的队列迭代主要是在bfs算法里写的，而非主函数那
    queue<pair<int, int>> que;
    que.push({x, y});
    visited[x][y] = true;   // 只要加入队列，立刻标记
    while (!que.empty()) {
        pair<int, int> cur = que.front();
        que.pop();
        int curX = cur.first, curY = cur.second;
        for (auto& dir : direction) {
            int nextX = curX + dir[0];
            int nextY = curY + dir[1];
            if (nextX < 0 || nextY < 0 || nextX >= graph.size() || nextY >= graph[0].size())
                continue;
            // 递归遍历相邻陆地
            if (!visited[nextX][nextY] && graph[nextX][nextY] == 1) {
                que.push({nextX, nextY});
                visited[nextX][nextY] = true;
            }
        }
    }
}
 
int main() {
    int rNum, cNum, res = 0;
    cin >> rNum >> cNum;
    vector<vector<int>> graph(rNum, vector<int>(cNum, 0));
    // 版本三：用额外的标记数组的bfs
    vector<vector<bool>> visited(rNum, vector<bool>(cNum, false));
    for (int i = 0; i < rNum; i++) {
        for (int j = 0; j < cNum; j++) {
            cin >> graph[i][j]; 
        }
    }
 
    // 遍历整个矩阵，寻找未被访问的陆地（1）
    for (int i = 0; i < rNum; i++) {
        for (int j = 0; j < cNum; j++) {
            // 遇到陆地（且未被访问），计数+1，然后通过bfs标记该岛屿所有陆地为0
            if (!visited[i][j] && graph[i][j] == 1) {
                // 立刻标记为访问，且bfs遍历每个连通分量的节点时，也标记上
                visited[i][j] = true;
                res++;
                bfs(graph, visited, i, j);
            }
        }
    }
 
    cout << res;
    return 0;
}
```

## 并查集

并查集主要有三个功能。

1. 寻找根节点，函数：find(int u)，也就是判断这个节点的祖先节点是哪个
2. 将两个节点接入到同一个集合，函数：join(int u, int v)，将两个节点连在同一个根节点上
3. 判断两个节点是否在同一个集合，函数：isSame(int u, int v)，就是判断两个节点是不是同一个根节点

### 路径压缩的并查集

```cpp
int n = 1005; // n根据题目中节点数量而定，一般比节点数量大一点就好
// 并查集标记节点关系的数组
vector<int> father = vector<int> (n, 0); 

// 并查集初始化
void init() {
    for (int i = 0; i < n; ++i) {
        // 初始值，每个节点的根为其自己
        father[i] = i;
    }
}
// 并查集里寻根的过程
int find(int u) {
    // 如果当前是根就返回，否则递归的去找其真正的根（深度访问到底）
    return u == father[u] ? u : father[u] = find(father[u]); // 使用了father[u] = 就是用路径压缩
}

// 判断 u 和 v是否找到同一个根
bool isSame(int u, int v) {
    u = find(u);
    v = find(v);
    return u == v;
}

// 将v->u 这条边加入并查集：将v所指向的根指向u所指向的根，也就是后者的根指向前者的根
void join(int u, int v) {
    u = find(u); // 寻找u的根
    v = find(v); // 寻找v的根
    if (u == v) return ; // 如果发现根相同，则说明在一个集合，不用两个节点相连直接返回
    father[v] = u;
}
```

**实战：**

https://kamacoder.com/problempage.php?pid=1179

```cpp
#include <iostream>
#include <vector>
using namespace std;
 
int n;  // 节点数量
// 并查集的集合表
vector<int> father(101, 0);

// 初始化
void init() {
    for (int i = 0; i < n; i++)
        father[i] = i;  // 初始化：让其根为自己
}

// 寻根
int find(int u) {
    return u == father[u] ? u : father[u] = find(father[u]);  // 使用了路径压缩
}

// 判断两个u和v是否是同根
bool isSame(int u, int v) {
    u = find(u);
    v = find(v);
    return u == v;
}

// 将 v->u 这条边加入并查集
void join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) 
        return;
    father[v] = u;
}
 
int main() {
    // 这题显然是关于并查集的应用，只需判断两个节点是否属于同一个集合即可
    int edge, s, t, source, destination;
    cin >> n >> edge;

    // 初始化并查集
    init();

    // 将所有变加入并查集中
    for (int i = 0; i < edge; i++) {
        cin >> s >> t;
        join(s, t); 
    }

    cin >> source >> destination;
    // 判断两节点是否同根
    if (isSame(source, destination))
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}
```



### 按秩合并的并查集

```cpp
int n = 1005; // n根据题目中节点数量而定，一般比节点数量大一点就好
vector<int> father = vector<int> (n, 0); // C++里的一种数组结构
vector<int> rank = vector<int> (n, 1); // 初始每棵树的高度都为1

// 并查集初始化
void init() {
    for (int i = 0; i < n; ++i) {
        father[i] = i;
        rank[i] = 1; // 也可以不写
    }
}
// 并查集里寻根的过程
int find(int u) {
    return u == father[u] ? u : find(father[u]);// 注意这里不做路径压缩
}

// 判断 u 和 v是否找到同一个根
bool isSame(int u, int v) {
    u = find(u);
    v = find(v);
    return u == v;
}

// 将v->u 这条边加入并查集
void join(int u, int v) {
    u = find(u); // 寻找u的根
    v = find(v); // 寻找v的根

    if (rank[u] <= rank[v]) father[u] = v; // rank小的树合入到rank大的树
    else father[v] = u;

    if (rank[u] == rank[v] && u != v) rank[v]++; // 如果两棵树高度相同，则v的高度+1，因为上面 if (rank[u] <= rank[v]) father[u] = v; 注意是 <=
}
```



## 最小生成树

MST——minimum-spanning-tre

**最小生成树的定义本身只针对「无向连通带权图（可负值）」**

### 普里姆prim

**权值可以为负的，适合稠密图**

**prim三部曲**：

1. 第一步，选距离生成树最近节点（贪心选最小）——由初始化或每轮的第三步更新的minDist数组（**记录了所有非生成树节点距离生成树的最小距离**）得到
2. 第二步，最近节点加入生成树——若有相同，可以选择序号小的
3. 第三步，更新非生成树节点到生成树的距离（即更新minDist数组）

https://kamacoder.com/problempage.php?pid=1053

```cpp
#include<iostream>
#include<vector>
#include <climits>

using namespace std;
int main() {
    int v, e;
    int x, y, k;
    cin >> v >> e;
    // 填一个默认最大值，题目描述val最大为10000
    vector<vector<int>> grid(v + 1, vector<int>(v + 1, 10001));
    while (e--) {
        cin >> x >> y >> k;
        // 因为是双向图（无向图），所以两个方向都要填上
        grid[x][y] = k;
        grid[y][x] = k;

    }

    // 用于保存最小生成树的边
    vector<int> minDist(v + 1, 10001);
    // 用于判断某定点是否在生成树中
    vector<bool> isInTree(v + 1, false);

    // 生成n个节点的最小生成树，只需要n-1条边，也就是n-1轮循环
    for (int i = 1; i < v; i++) {
        // 用于标记最小边的位置（位序）
        int cur = -1;
        int minVal = INT_MAX;
        // 第一步：选择最近的一条边的顶点作为起点
        for (int j = 1; j <= v; j++) { // 从1开始，对其位序：1~v
            //  选取最小生成树节点的条件：
            //  （1）不在最小生成树里
            //  （2）距离最小生成树最近的节点
            if (!isInTree[j] && minDist[j] < minVal) {  // 由于mindist默认值是10001，比INTMAX小，故总会选择第一位序的作为起点顶点
                cur = j;
                minVal = minDist[j];
            }
        }
        // 第二步：将这个最近节点加入生成树中
        isInTree[cur] = true;

        // 第三步：更新非生成树节点到生成树的距离
        for (int j = 1; j <= v; j++) { 
            //  更新非生成树节点到生成树的距离的条件：
            //  （1）不在最小生成树里
            //  （2）与cur相连的某节点的权值 比 该某节点距离最小生成树的距离小
            if (!isInTree[j] && grid[cur][j] < minDist[j]) {  // 由于mindist默认值是10001，比INTMAX小，故总会选择第一位序的作为起点顶点
                minDist[j] = grid[cur][j];
            }
        }
    }

    int res = 0;
    // 只有n-1条边，且第一条边为10001，所以不能记
    for (int i = 2; i <= v; i++) {
        res += minDist[i];
    }

    cout << res << endl;

    return 0;
}
```

### 克鲁斯卡尔Kruscal

**适合稀疏图，权值可以为负**

> 总结下来：MST和最短路径的第一个算法都是不能带负值，但第二个算法可以。MST是无向图，最短路径一般是有向图，但无向图也可以

kruscal的思路：

- **边的权值排序**，因为要**优先选最小的边**加入到生成树里
- **遍历排序后的边**
  - 如果边首尾的两个节点在同一个集合，说明如果连上这条边图中会出现环
  - 如果边**首尾的两个节点不在同一个集合，加入到最小生成树，并把两个节点加入同一个集合**

https://kamacoder.com/problempage.php?pid=1053

```cpp
#include<iostream>
#include<vector>
#include <climits>
#include <algorithm>
using namespace std;

// 用克鲁斯卡尔来求最小生成树：运用到了并查集
// 定义边集合，包括起始、终点和边权值
struct Edge {
    int l, r, val;
};

// 节点数量
int n = 10001;
// 并查集标记节点关系的数组
vector<int> father(n, -1);

void init() {
    for (int i = 0; i < n; i++)
        father[i] = i;
}

int find(int u) {
    // 如果当前是根就返回，否则递归的去找其真正的根（深度访问到底）
    return u == father[u] ? u : father[u] = find(father[u]);
}

void join(int u, int v) {
    u = find(u);
    v = find(v);
    // 表示此时已经是同一个集合了
    if (u == v)
        return;
    father[v] = u;
}

bool isSame(int u, int v) {
    u = find(u);
    v = find(v);
    return u == v;
}

int main() {
    int v, e;
    int v1, v2, val;
    cin >> v >> e;
    vector<Edge> edges;
    int res = 0;
    while (e--) {
        cin >> v1 >> v2 >> val;
        edges.push_back({v1, v2, val});
    }

    // 按权值对边从小到大排序
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.val < b.val;
    });

    init();

    // 从头开始遍历边
    for (Edge edge: edges) {
        int x = find(edge.l), y = find(edge.r);
        // 不在同一个集合，则加入最小生成树，同时加入集合里
        if (x != y) {
            // 生成树的边的和
            res += edge.val;
            // 将两个节点加入同一个集合
            join(x, y);
        }
    }
    cout << res << endl;

    return 0;
}
```

## 最短路径

都是针对带权有向图而言的

### 迪杰斯特拉Dijkstra

用于**非负权值有向图**求起点到某节点的最短路径

**dijkstra三部曲**：

1. 第一步，选源点到哪个节点近且该节点未被访问过
2. 第二步，该最近节点被标记访问过
3. 第三步，更新非访问节点到源点的距离（即更新minDist数组）

https://kamacoder.com/problempage.php?pid=1047

```cpp
#include<iostream>
#include<vector>
#include <climits>

using namespace std;
int main() {
    int v, e;
    int x, y, k;
    cin >> v >> e;
    // 初始化邻接矩阵，INT_MAX表示不可达
    vector<vector<int>> grid(v + 1, vector<int>(v + 1, INT_MAX));
    while (e--) {
        cin >> x >> y >> k;
        // 单向图（有向图），仅赋值x→y的距离，无需双向
        grid[x][y] = k;
    }

    // 用于保存从起点到该节点的最短距离
    vector<int> minDist(v + 1, INT_MAX);
    // 初始化起始顶点，自己到自己的距离为0，从1开始进行对其
    minDist[1] = 0;
    // 用于判断某顶点是否访问过
    vector<bool> visited(v + 1, false);

    // 迪杰斯特拉算法：v轮循环，确定v个节点的最短路径
    for (int i = 1; i <= v; i++) {
        // 用于标记最小边的位置（位序）
        int cur = -1;
        int minVal = INT_MAX;
        // 第一步：选择最近的一条边的顶点作为起点
        for (int j = 1; j <= v; j++) { // 从1开始，对其位序：1~v
            //  选取最短边的顶点条件：
            //  （1）该顶点未被访问过
            //  （2）距离起点是最近的节点
            if (!visited[j] && minDist[j] < minVal) {  // 由于mindist默认值是INT_MAX，比INTMAX小，故总会选择第一位序的作为起点顶点
                cur = j;
                minVal = minDist[j];
            }
        }
        // 若所有未访问节点都不可达，直接跳出循环（优化）
        if (cur == -1) break;
        // 第二步：将这个最近节点标记为访问过
        visited[cur] = true;

        // 第三步：通过cur更新其他未访问节点的最短距离（松弛操作）
        for (int j = 1; j <= v; j++) { 
            //  最短路径的条件：
            //  （1）该顶点未被访问过
            //  （2）与cur相连的某节点的权值 比 该某节点距离最小生成树的距离小
            if (!visited[j] && grid[cur][j] != INT_MAX && grid[cur][j] + minDist[cur] < minDist[j]) {  // 由于mindist默认值是INT_MAX，比INTMAX小，故总会选择第一位序的作为起点顶点
                minDist[j] = grid[cur][j] + minDist[cur];
            }
        }
    }

    if (minDist[v] == INT_MAX)
        cout << -1 << endl;
    else
        cout << minDist[v] << endl;

    return 0;
}
```

### dijkstra与prim算法的区别

其实代码大体不差，唯一区别在 三部曲中的 第三步： 更新minDist数组

因为**prim是求 非访问节点到最小生成树的最小距离，而 dijkstra是求 非访问节点到源点的最小距离**。

prim 更新 minDist数组的写法：

```cpp
for (int j = 1; j <= v; j++) {
    if (!isInTree[j] && grid[cur][j] < minDist[j]) {
        minDist[j] = grid[cur][j];
    }
}
```

因为 minDist表示 节点到最小生成树的最小距离，所以 新节点cur的加入，只需要 使用 grid[cur][j] ，grid[cur][j] 就表示 cur 加入生成树后，生成树到 节点j 的距离。

dijkstra 更新 minDist数组的写法：

```cpp
for (int v = 1; v <= n; v++) {
    if (!visited[v] && grid[cur][v] != INT_MAX && minDist[cur] + grid[cur][v] < minDist[v]) {
        minDist[v] = minDist[cur] + grid[cur][v];
    }
}
```

因为 minDist表示 节点到源点的最小距离，所以 新节点 cur 的加入，需要使用 源点到cur的距离 （minDist[cur]） + cur 到 节点 v 的距离 （grid[cur][v]），才是 源点到节点v的距离。

此时大家可能不禁要想 **prim算法 可以有负权值**吗？

当然可以！

### 弗洛伊德Floyd

一种基于 **动态规划** 的方法，用于求解任意两个顶点之间的最短路径，它适用于**带权非负有向图**。

https://kamacoder.com/problempage.php?pid=1155

```cpp
#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {
    int n, m, p1, p2, val;
    cin >> n >> m;

    // 1.dp数组定义
    vector<vector<vector<int>>> grid(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 10005)));  // 因为边的最大距离是10^4

    // 2.dp数组初始化
    for (int i = 0; i < m; i++) {
        cin >> p1 >> p2 >> val;
        // 双向图（无环图），只能把 k 赋值为 0，本题节点 0 是无意义的，节点是从1 到 n。
        grid[p1][p2][0] = val;
        grid[p2][p1][0] = val;
    }

    // 开始floyd：实际上就是在遍历所有可能的情况上用上了动态规划
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                // 3.dp递推公式：分两种情况：前者是节点i 到 节点j 的最短路径不经过节点k；后者是节点i 到 节点j 的最短路径经过节点k
                // 表示从起点i到终点j的对于走k或不走k的最短路径。后者的表示[i][k]+[k][j]就表示先从i到k再从k到j，相当于中转站一般的
                grid[i][j][k] = min(grid[i][j][k - 1], grid[i][k][k - 1] + grid[k][j][k - 1]);
            }
        }
    }

    // 输出结果
    int z, start, end;
    cin >> z;
    while(z--) {
        cin >> start >> end;
        if (grid[start][end][n] == 10005)
            cout << -1 << endl;
        else
            cout << grid[start][end][n] << endl;
    }
    return 0;
}
```

空间优化版本（二维数组）：

```cpp
#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {
    int n, m, p1, p2, val;
    cin >> n >> m;

    // 1.dp数组定义
    vector<vector<int>> grid(n + 1, vector<int>(n + 1, 10005));  // 因为边的最大距离是10^4

    // 2.dp数组初始化
    for (int i = 0; i < m; i++) {
        cin >> p1 >> p2 >> val;
        // 双向图，只能把 k 赋值为 0，本题节点 0 是无意义的，节点是从1 到 n。
        grid[p1][p2] = val;
        grid[p2][p1] = val;
    }

    // 开始floyd：实际上就是在遍历所有可能的情况上用上了动态规划
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                // 3.dp递推公式：分两种情况：前者是节点i 到 节点j 的最短路径不经过节点k；后者是节点i 到 节点j 的最短路径经过节点k
                // 表示从起点i到终点j的对于走k或不走k的最短路径。后者的表示[i][k]+[k][j]就表示先从i到k再从k到j，相当于中转站一般的
                grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
            }
        }
    }

    // 输出结果
    int z, start, end;
    cin >> z;
    while(z--) {
        cin >> start >> end;
        if (grid[start][end] == 10005)
            cout << -1 << endl;
        else
            cout << grid[start][end] << endl;
    }
    return 0;
}
```

### 最短路径总结

四大最短路算法，分别是Dijkstra、Bellman_ford、SPFA 和 Floyd。

针对这四大最短路算法，我用了七篇长文才彻底讲清楚，分别是：

- dijkstra朴素版
- dijkstra堆优化版
- Bellman_ford
- Bellman_ford 队列优化算法（又名SPFA）
- bellman_ford 算法判断负权回路
- bellman_ford之单源有限最短路
- Floyd 算法精讲
- 启发式搜索：A * 算法

最短路算法比较复杂，而且各自有各自的应用场景，我来用一张表把讲过的最短路算法的使用场景都展现出来：

![img](https://houlir2.dpdns.org/2026/01/6a48a99d558b102035f1747b9bea86e4.png)

（因为A * 属于启发式搜索，和上面最短路算法并不是一类，不适合一起对比，所以没有放在一起）

## 有向无环图DAG

**用来描述表达式，可以使相同子式（不止是子式，字母也可以）只出现一次，从而节省空间**

### 拓扑排序AOV

DAG的扩展，以**顶点表示活动，是个无权图，边表示活动之间关系**

应用：表示软件开发项目的**依赖关系**，或者如makefile、maven



拓扑排序 是在图上的一种排序。

概括来说，**给出一个 有向图，把这个有向图转成线性的排序 就叫拓扑排序**。

同样，拓扑排序也可以**检测这个有向图 是否有环，即存在循环依赖的情况**。

只要记住如下两步拓扑排序的过程，代码就容易写了：

1. 找到入度为0 的节点，加入结果集
2. 将该节点从图中移除

https://kamacoder.com/problempage.php?pid=1191

BFS版本：

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

int main() {
    int n, m, s, t;  // s->t
    cin >> n >> m;
    unordered_map<int, vector<int>> umap;
    vector<int> res;
    vector<int> inDegree(n, 0);
    queue<int> que;

    while (m--) {
        cin >> s >> t;
        inDegree[t]++;
        umap[s].push_back(t);
    }

    // 初始化：将入度为0的顶点加入队列中
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0)
            que.push(i);
    }

    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        // 加入结果集后删除该节点
        res.push_back(cur);
        // 获取该节点的出度顶点表
        vector<int> t = umap[cur];
        if (!t.empty()) {
            for (int i = 0; i < t.size(); i++) {
                // 减少入度
                inDegree[t[i]]--;
                // 如果经过减少入度后达到入度为0后，就又成为下一个将加入结果集的顶点
                if (inDegree[t[i]] == 0)
                    que.push(t[i]);
            }
        }
    }

    // 输出结果集
    if (res.size() != n)
        cout << -1;
    else {
        for (int i = 0; i < n - 1; i++)
            cout << res[i] << " ";
        cout << res[n - 1];
    }
}
```

DFS版本：

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

int main() {
    int n, m, s, t;  // s->t
    cin >> n >> m;
    unordered_map<int, vector<int>> umap;
    vector<int> res;
    vector<int> inDegree(n, 0);
    stack<int> stk;

    while (m--) {
        cin >> s >> t;
        inDegree[t]++;
        umap[s].push_back(t);
    }

    // 初始化：将入度为0的顶点加入队列中
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0)
            stk.push(i);
    }

    while (!stk.empty()) {
        int cur = stk.top();
        stk.pop();
        // 加入结果集后删除该节点
        res.push_back(cur);
        // 获取该节点的出度顶点表
        vector<int> t = umap[cur];
        if (!t.empty()) {
            for (int i = 0; i < t.size(); i++) {
                // 减少入度
                inDegree[t[i]]--;
                // 如果经过减少入度后达到入度为0后，就又成为下一个将加入结果集的顶点
                if (inDegree[t[i]] == 0)
                    stk.push(t[i]);
            }
        }
    }

    // 输出结果集
    if (res.size() != n)
        cout << -1;
    else {
        for (int i = 0; i < n - 1; i++)
            cout << res[i] << " ";
        cout << res[n - 1];
    }
}
```



### 关键路径AOE

DAG的扩展，以**顶点表示事件，边表示活动，有权图**。

关键路径也可以检测一个图是否有环

只有说最长的路径完成（关键路径）了，整个工程才能结束

应用：解决「项目的时间规划与优化」问题，如软件开发管理、生产流水线、工程施工进度管理等

![image-20260109175319254](https://houlir2.dpdns.org/2026/01/dba79540992700cf12268665ca792be9.png)

![image-20260109175445046](https://houlir2.dpdns.org/2026/01/db37e02a23719746e672bc54dcf28ec2.png)

![image-20260109174303344](https://houlir2.dpdns.org/2026/01/3f22de2170bb926a1899f305bd1da816.png)

![image-20260109174311100](https://houlir2.dpdns.org/2026/01/095456cd2b4e0f14839fbf5effc33244.png)

# 查找

## 顺序、折半查找

### asl计算

分为查找成功与查找失败的asl，其中**顺序查找和有序表顺序查找的成功asl都=(n+1)/2**，而**顺序查找查找的失败asl=n+1，有序顺序查找的失败asl=n/2 + n/(n+1)**；**折半查找的asl要画出判定树来计算；分块查找的最小平均查找长度asl在s=b=√n时成立，此时asl=√n + 1**

> 有序顺序查找和折半查找都可以画成判定树，只不过后者是平衡的，前者不一定

![image-20260114172357155](https://houlir2.dpdns.org/2026/01/f1b04d8c8e3f332c33c2eeed2b58a562.png)

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
| `deque`          | `operator[]`、`at(i)`（随机访问）、**`push_front(x)`、`pop_front(x)`、**`push_back(x)`、`pop_back(x)`、`.front()`、`.back()` | 高效两端操作 + 随机访问（如**双端队列**、滑动窗口）      |
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
  // index为入堆时节点到起点的距离，i为节点编号
  int index = q.top().first, i = q.top().second;
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

## 左值和右值

> [参考](https://www.cnblogs.com/david-china/p/17080072.html)

### 左值 [*可以取地址的对象就是左值*]

左值是一个表示数据的表达式，比如：*变量名、解引用的指针变量*。一般地，我们**可以获取它的地址和对它赋值**，但被 const 修饰后的左值，不能给它赋值，但是仍然可以取它的地址。*总体而言，可以取地址的对象就是左值。*

```cpp
// 以下的a、p、*p、b都是左值
int a = 3;
int* p = &a;
*p;
const int b = 2;
```

### 右值[*不可以取地址的对象就是右值*]

右值也是一个表示数据的表达式，**比如：*字面常量、表达式返回值，传值返回函数的返回值（是传值返回，而非传引用返回）*，右值不能出现在赋值符号的左边且不能取地址**。*总体而言，不可以取地址的对象就是右值。*

```cpp
double x = 1.3, y = 3.8;
// 以下几个都是常见的右值
10;                 // 字面常量
x + y;             // 表达式返回值
fmin(x, y);        // 传值返回函数的返回值

以下写法均不能通过编译：

10 = 4;
x + y = 4;
fmin(x, y) = 4;
VS2015 编译报错：error C2106: “=”: 左操作数必须为左值。原因：右值不能出现在赋值符号的左边。
&10;、&(x + y);、&fmin(x, y);，VS2015 编译报错：error C2102: “&” 要求左值。原因：右值不能取地址。
```



### 总结

区分左值和右值，终究还是要看能否取地址。

## 左值引用和右值引用

*无论左值引用还是右值引用，都是给对象取别名。*

### 左值引用【*避免对象拷贝】*

左值引用就是对左值的引用，给左值**取别名**。**主要作用是避免对象拷贝。**

```cpp
// 以下几个是对上面左值的左值引用
int& ra = a;
int*& rp = p;
int& r = *p;
const int& rb = b;
```

> 通常函数调用时采用**值传递**的方式，系统会在内存中开辟空间用来存储形参变量，并将实参变量的值拷贝给形参变量，所以**形参变量只是实参变量的副本而已**，并且如果函数传递的是类的对象，系统还会调用类中的拷贝构造函数来构造形参对象
> 
> **指针作为函数的形参**，虽然达到的效果跟使用引用一样，但**当调用函数时仍然需要为形参指针分配空间，引用则不需要**【引用在底层也会分配指针大小的空间，在汇编底层角度，引用和指针是一样的，不过引用类似于常量指针】。推荐使用引用而非指针作为函数的传递函数

###  右值引用【*延长对象生命周期*】

右值引用就是对右值的引用，给右值取别名。**主要作用是把延长对象的生命周期，一般是延长到作用域的scope之外**。

**右值引用的表示**是在具体的变量类型名称后加**两个 &**，比如：int&& rr = 4;。

```cpp
// 以下几个是对上面右值的右值引用
int&& rr1 = 10;
double&& rr2 = x + y;
double&& rr3 = fmin(x, y);
```

> **注意：**
>
> **右值引用 引用 右值，会使右值被存储到特定的位置**。也就是说，右值引用变量其实是左值，可以对它取地址和赋值（const右值引用变量可以取地址但不可以赋值，因为 const 在起作用）。
> 当然，取地址是指取变量空间的地址（右值是不能取地址的）。
> 比如：
>
> 1. 
>
> `double&& rr2 = x + y;`　　
>
> `&rr2;`　　
>
> `rr2 = 9.4;`　　
>
> 右值引用 rr2 引用右值 x + y 后，该表达式的返回值被存储到特定的位置，不能取表达式返回值 x + y 的地址，但是可以取 rr2 的地址，也可以修改 rr2 。 const double&& rr4 = x + y; &rr4; 可以对 rr4 取地址，但不能修改 rr4，即写成rr4 = 5.3;会编译报错。
>
> 2.  
>
>    `const double&& rr4 = x + y;　　`
>
>    `&rr4;　　`
>
>    可以对 rr4 取地址，但不能修改 rr4，即写成rr4 = 5.3;     会编译报错

现在我们知道左值引用可以引用左值，右值引用可以引用右值。
那么*左值引用是否可以引用右值？右值引用是否可以引用左值呢？*

- **左值引用可以指向右值，但需要const（const左值既可以引用左值，也可以引用右值）来修饰，不能修改这个值**
- **右值引用可以指向左值，需要std::move(v)即可**
- 声明出来的左值引用或右值引用都是左值

下面的对比与总结给出详细探讨解释。

```txt
问：为什么const左值引用也可以引用右值？
答：在 C++11标准产生之前，是没有右值引用这个概念的，当时如果想要一个类型既能接收左值也能接收右值的话，需要用const左值引用，比如标准容器的 push_back 接口：void push_back (const T& val)。
也就是说，如果const左值引用不能引用右值的话，有些接口就不好支持了。另外，const左值引用，本意上是指向一个不被（该引用本身）它修改的内存区域，本质上这个引用变量本身也就是一个常量，至于这个内存区域对应一个全局变量、局部变量、xvalue，无所谓啊
```

下面就是 C++98标准中相关接口const左值引用引用右值的例子：

```cpp
vector<int> v;
v.push_back(1);
v.push_back(2);
v.push_back(3);
```

### 2.3.2 右值引用总结：

**右值引用只能引用右值，不能直接引用左值**。
但是**右值引用可以引用被move的左值**。

```txt
move，本文指std::move（C++11），作用是将一个左值强制转化为右值，以实现移动语义。左值被 move 后变为右值，于是右值引用可以引用。
```

```cpp
// 1.右值引用只能引用右值
int&& rr1 = 10;
double&& rr2 = x + y;
const double&& rr3 = x + y;

int t = 10;
//int&& rrt = t; // 编译报错，不能直接引用左值


// 2.但是右值引用可以引用被move的左值
int&& rrt = std::move(t);
int*&& rr4 = std::move(p);
int&& rr5 = std::move(*p);
const int&& rr6 = std::move(b);
```











