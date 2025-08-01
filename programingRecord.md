

> 本文档用来记录我根据[代码随想录](https://www.programmercarl.com/)来学习c++算法的过程
>
> 为了节省空间和篇幅，不会将每个题的代码粘贴出来，就简单写一下方法思路，其中某些好用的模板会写出来，如滑动窗口、双指针等

# 洛谷说明

各个评测状态

**AC**：Accept，程序通过。

**WA**：Wrong Answer，答案错误。

**CE**：Compile Error，**编译错误。**

**PC**：Partially Correct，部分正确。

**RE**：Runtime Error，运行时错误。

**TLE**：Time Limit Exceeded，超出时间限制。

**MLE**：Memory Limit Exceeded，超出内存限制。

**OLE**：Output Limit Exceeded，输出超过限制。

**UKE**：Unknown Error，出现未知错误。

# 2025

## 5月

> 本月主要学习数组，一开始是没打算记录的，后面才想到去做，所以这个月很少记录（主要懒得去翻以前的记录了）

[76\. 最小覆盖子串](https://leetcode.cn/problems/minimum-window-substring/)

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

[567. 字符串的排列](https://leetcode.cn/problems/permutation-in-string/)

滑动窗口还可以固定大小的方式，就适用于这种子串、子排列相同长度的情况下

[46. Permutations](https://leetcode.cn/problems/permutations/)

基本抄了官方的解了，第一次做仅能想到每一次要不断通过递归，确定一个元素，才能实现所有的情况可能，但是没想出具体如何实现递归，直接看了题解了

回溯算法的框架：

```cpp
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



## 6月

> 记录本人6月份力扣的刷题记录，前面的序号表示是几号，如1就是6月1号
>
> 本月学完了数组、链表、哈希表和字符串

1. [167. Two Sum II - Input Array Is Sorted](https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/)

   滑动窗口：直接左右指针的方式，当和大于target时，让右指针左移，也就是和会减小；而当和小于target时，让左指针右移，这样和就会增大

   ```cpp
   class Solution {
   public:
       vector<int> twoSum(vector<int>& numbers, int target) {
           int n = numbers.size(), left = 0, right = n - 1;
           while (left < right) {
               if (numbers[left] + numbers[right] > target)
                   right--;
               else if (numbers[left] + numbers[right] < target)
                   left++;
               else
                   break;
           }
           return vector<int> {left + 1, right + 1};
       }
   };
   ```

   ### 链表

2. [203. Remove Linked List Elements](https://leetcode.cn/problems/remove-linked-list-elements/)

   - 方法一：正常的前后指针解法

     ```cpp
     /**
      * Definition for singly-linked list.
      * struct ListNode {
      *     int val;
      *     ListNode *next;
      *     ListNode() : val(0), next(nullptr) {}
      *     ListNode(int x) : val(x), next(nullptr) {}
      *     ListNode(int x, ListNode *next) : val(x), next(next) {}
      * };
      */
     class Solution {
     public:
         ListNode* removeElements(ListNode* head, int val) {
             while (head && head->val == val) {
                 ListNode *temp = head;
                 head = head->next;
                 delete(temp);
             }
             ListNode *pre = head, *now;
             while (pre && pre->next) {
                 now = pre->next;
                 if (now->val == val) {
                     pre->next = now->next;
                     delete(now);
                 }
                 else
                     pre = pre->next;
             }
             return head;
         }
     };
     ```

   - 方法二：设置一个虚拟头结点在进行移除节点操作

     ```cpp
     /**
      * Definition for singly-linked list.
      * struct ListNode {
      *     int val;
      *     ListNode *next;
      *     ListNode() : val(0), next(nullptr) {}
      *     ListNode(int x) : val(x), next(nullptr) {}
      *     ListNode(int x, ListNode *next) : val(x), next(next) {}
      * };
      */
     class Solution {
     public:
         ListNode* removeElements(ListNode* head, int val) {
             ListNode *vitual = new ListNode(0), *cur, *pro;  // 注意对节点初始化时，就需要用new
             vitual->next = head;
             cur = vitual;
             while (cur->next) {
                 pro = cur->next;
                 if (pro->val == val) {
                     cur->next = pro->next;
                     delete(pro);
                 }
                 else
                     cur = pro;
             }
             head = vitual->next;
             delete(vitual);  // 该虚拟节点也应该释放掉
             return head;
         }
     };

   - 方法三：通过递归的思路解决本题:

     基础情况：对于空链表，不需要移除元素。

     递归情况：首先检查头节点的值是否为 val，如果是则移除头节点，答案即为在头节点的后续节点上递归的结果；如果头节点的值不为 val，则答案为头节点与在头节点的后续节点上递归得到的新链表拼接的结果。

     ```cpp
     /**
      * Definition for singly-linked list.
      * struct ListNode {
      *     int val;
      *     ListNode *next;
      *     ListNode() : val(0), next(nullptr) {}
      *     ListNode(int x) : val(x), next(nullptr) {}
      *     ListNode(int x, ListNode *next) : val(x), next(next) {}
      * };
      */
     class Solution {
     public:
         ListNode* removeElements(ListNode* head, int val) {
             // 也可以通过递归的思路解决本题:
             // 基础情况：对于空链表，不需要移除元素。
             // 递归情况：首先检查头节点的值是否为 val，如果是则移除头节点，答案即为在头节点的后续节点上递归的结果；如果头节点的值不为 val，则答案为头节点与在头节点的后续节点上递归得到的新链表拼接的结果。
             if (!head)  // 空链表
                 return nullptr;
             if (head->val == val) {
                 ListNode *newHead = removeElements(head->next, val);
                 delete head;
                 return newHead;
             }
             else {
                 head->next = removeElements(head->next, val);
                 return head;
             }
         }
     };

3. 无

4. [707. Design Linked List](https://leetcode.cn/problems/design-linked-list/)

   - 方法一：用虚拟节点（头指针）的方式来实现
   - 方法二：C语言实现双链表的版本

   [206. Reverse Linked List](https://leetcode.cn/problems/reverse-linked-list/)

   - 方法一：双指针的方式，通过以第一个节点为尾节点，最后一个节点为头结点的方式。
   - 方法二：递归解法，会有点难以理解
   - 方法三：使用虚拟头结点，通过头插法实现链表的反转

5. [92. Reverse Linked List II](https://leetcode.cn/problems/reverse-linked-list-ii/)

   - 方法一：将left的前一个元素作为虚拟头结点，只不过要保存left的节点，之后对区域内去逆序，最后将保存的left节点指向right后的节点即可

     ```cpp
     class MyLinkedList {
     public:
         struct ListNode {
             int val;
             ListNode *next;
             ListNode(int val):val(val), next(nullptr) {};
         };
     
     private:
         ListNode *_dummyHead;
         int _size = 0;    
     
     public:
         MyLinkedList() {
             _dummyHead = new ListNode(0);
             _size = 0;
         }
         
         int get(int index) {
             // 先判断索引是否越界
             if (index < 0 || index >= _size)
                 return -1;
             ListNode *cur = _dummyHead->next;  // 定位到第一个元素
             while (index-- > 0) {
                 cur = cur->next;
             }
             return cur->val;
         }
         
         void addAtHead(int val) {
             ListNode *newNode = new ListNode(val);
             newNode->next = _dummyHead->next;
             _dummyHead->next = newNode;
             _size++;
         }
         
         void addAtTail(int val) {
             ListNode *newNode = new ListNode(val), *cur = _dummyHead;  // 定位到第一个元素
             while (cur->next) {
                 cur = cur->next;
             }
             cur->next = newNode;
             _size++;
         }
         
         void addAtIndex(int index, int val) {
             // 判断越界情况，这里只有当index超出链表长度时，才不插入，否则即使小于0也会插入（根据题目规定的）
             if (index > _size)
                 return;
             if (index < 0)
                 index = 0; // 表示小于0时，插入到第一个位置
             ListNode *newNode = new ListNode(val), *cur = _dummyHead->next, *pre = _dummyHead;  // 定位到第一个元素
             while (index--) {
                 pre = cur;   // 这里我写复杂了，一般情况下，cur = _dummyHead即可，也不需要pre，因为本身有虚拟节点就是省去前后指针操作的
                 cur = cur->next;
             }
             newNode->next = cur;
             pre->next = newNode;
             _size++;
         }
         
         void deleteAtIndex(int index) {
             // 判断越界情况
             if (index < 0 || index >= _size || _size == 0)
                 return;
             ListNode *cur = _dummyHead->next, *pre = _dummyHead;  // 定位到第一个元素
             while (index--) {
                 pre = cur;
                 cur = cur->next;
             }
             if (cur->next == nullptr)
                 pre->next = nullptr;
             else
                 pre->next = cur->next;
             delete(cur);
             //如果不再加上一句cur=nullptr,cur会成为乱指的野指针
             //如果之后的程序不小心使用了cur，会指向难以预想的内存空间
             cur = nullptr;
             _size--;
         }
     
         // 打印链表
         void printLinkedList() {
             ListNode *cur = _dummyHead->next;
             while (cur) {
                 cout << cur->val << ',';
                 cur = cur->next;
             }
         }
     };
     
     /**
      * Your MyLinkedList object will be instantiated and called as such:
      * MyLinkedList* obj = new MyLinkedList();
      * int param_1 = obj->get(index);
      * obj->addAtHead(val);
      * obj->addAtTail(val);
      * obj->addAtIndex(index,val);
      * obj->deleteAtIndex(index);
      */

   - **方法二：完全抄的递归版本（有点挑战性，自己暂时想不出）**

     ```cpp
     // 双链表节点的定义
     typedef struct DoubleListNode {
         int val;
         struct DoubleListNode *next;
         struct DoubleListNode *prev;
     }DoubleListNode;
     
     // 双链表的定义：有size大小
     typedef struct {
         int size;
         // 双链表由多个双链表节点所组成
         DoubleListNode *data;
     } MyLinkedList;
     
     MyLinkedList* myLinkedListCreate() {
         MyLinkedList *obj = (MyLinkedList *)malloc(sizeof(MyLinkedList));
         DoubleListNode *head = (DoubleListNode *)malloc(sizeof(DoubleListNode));
         head->val = 0;
         head->next = NULL; head->prev = NULL;
         obj->data = head;
         obj->size = 0;
         return obj;
     }
     
     int myLinkedListGet(MyLinkedList* obj, int index) {
         if (index >= obj->size || index < 0)
             return -1;
         DoubleListNode *cur = obj->data->next;
         while (index--) {
             cur = cur->next;
         }
         return cur->val;
     }
     
     void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
         DoubleListNode *newNode = (DoubleListNode *)malloc(sizeof(DoubleListNode));
         newNode->val = val;
     
         // 开始插入
         newNode->next = obj->data->next;
         if (obj->data->next)
             obj->data->next->prev = newNode;
         obj->data->next = newNode;
         newNode->prev = obj->data;
     
         obj->size++;
     }
     
     void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
         DoubleListNode *newNode = (DoubleListNode *)malloc(sizeof(DoubleListNode));
         newNode->val = val;
         DoubleListNode *pre = obj->data, *cur = obj->data->next;
         while (cur) {
             pre = cur;
             cur = cur->next;
         }
         newNode->next = cur; // NULL
         newNode->prev = pre;
         pre->next = newNode;
     
         obj->size++;
     }
     
     void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
         if (index > obj->size)
             return;
         if (index < 0)
             index = 0;
         DoubleListNode *newNode = (DoubleListNode *)malloc(sizeof(DoubleListNode)), *pre = obj->data, *cur = obj->data->next;
         newNode->val = val;
     
         while (index--) {
             pre = cur;
             cur = cur->next;
         }
     
         newNode->next = cur;
         if (cur)
             cur->prev = newNode;
         newNode->prev = pre;
         pre->next = newNode;
     
         obj->size++;
     }
     
     void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
         if (index >= obj->size || index < 0)
             return;
         DoubleListNode *pre = obj->data, *cur = obj->data->next;
         while (index--) {
             pre = cur;
             cur = cur->next;
         }
         pre->next = cur->next;
         if (cur->next)
             cur->next->prev = pre;
         free(cur);
     
         obj->size--;
     }
     
     // 清除链表
     void myLinkedListFree(MyLinkedList* obj) {
         DoubleListNode *pre, *cur = obj->data->next;
         // 先逐渐释放每个节点，最后再释放链表
         while (cur) {
             pre = cur;
             cur = cur->next;
             free(pre);
             obj->size--;
         }
         free(obj);
     }
     
     /**
      * Your MyLinkedList struct will be instantiated and called as such:
      * MyLinkedList* obj = myLinkedListCreate();
      * int param_1 = myLinkedListGet(obj, index);
      
      * myLinkedListAddAtHead(obj, val);
      
      * myLinkedListAddAtTail(obj, val);
      
      * myLinkedListAddAtIndex(obj, index, val);
      
      * myLinkedListDeleteAtIndex(obj, index);
      
      * myLinkedListFree(obj);
     */

6. 无

7. 无

8. 无

9. [25. Reverse Nodes in k-Group](https://leetcode.cn/problems/reverse-nodes-in-k-group/)

   - 方法一：借助gpt实现了头插法的版本

     ```cpp
     /**
      * Definition for singly-linked list.
      * struct ListNode {
      *     int val;
      *     ListNode *next;
      *     ListNode() : val(0), next(nullptr) {}
      *     ListNode(int x) : val(x), next(nullptr) {}
      *     ListNode(int x, ListNode *next) : val(x), next(next) {}
      * };
      */
     class Solution {
     public:
         ListNode* reverseKGroup(ListNode* head, int k) {
             ListNode* dummyHead = new ListNode(0);
             dummyHead->next = head;
             ListNode* pre = dummyHead;
             
             while (true) {
                 // 检查剩余节点是否有k个
                 ListNode* node = pre;
                 for (int i = 0; i < k && node != nullptr; i++) {
                     node = node->next;
                 }
                 if (node == nullptr) break; // 不足k个，退出循环
                 
                 ListNode* cur = pre->next;
                 ListNode* start = cur; // 记录当前组的第一个节点，反转后变为最后一个
                 
                 // 反转当前组的k个节点
                 for (int i = 0; i < k; i++) {
                     ListNode* t = cur->next;
                     cur->next = pre->next;
                     pre->next = cur;
                     cur = t;
                 }
                 
                 // 更新pre指针到下一组的前面
                 start->next = cur;
                 pre = start;
             }
             
             return dummyHead->next;
         }
     };

   - 方法二：自己尝试着用递归解出来了！

     ```cpp
     /**
      * Definition for singly-linked list.
      * struct ListNode {
      *     int val;
      *     ListNode *next;
      *     ListNode() : val(0), next(nullptr) {}
      *     ListNode(int x) : val(x), next(nullptr) {}
      *     ListNode(int x, ListNode *next) : val(x), next(next) {}
      * };
      */
     class Solution {
     public:
         ListNode* reverseKGroup(ListNode* head, int k) {
             // 尝试用递归思考去解决：本任务是要以按照k个节点为一组来为每一组进行逆序，而对于达不到k个元素的就不需要逆序，那么算法可以优化成：先对一组去逆序，接着在对后续的元素按照k个节点为一组的方式去调用递归。我觉得难点在于递归前后传递这些，以及应该从哪里开始之类的
             // 先判断边界情况
             if (!head || k == 1)    return head;
             
             ListNode *dummyHead = new ListNode(0, head);
             for (int i = 0; i < k && dummyHead; i++) dummyHead = dummyHead->next;
             if (!dummyHead) return head;  // 如果达不到k个，则原顺序返回
     
             ListNode *cur, *pre, *start, *t;
             pre = nullptr;
             start = head;
             cur = start;
     
             for (int i = 0; i < k && cur; i++) {
                 t = cur->next;
                 cur->next = pre;
                 pre = cur;
                 cur = t;
             }
     
             // pre = start;
             start->next = reverseKGroup(cur, k);
     
             return pre;
         }
     };

   - 方法三：递归和封装函数来解决此问题

     ```cpp
     /**
      * Definition for singly-linked list.
      * struct ListNode {
      *     int val;
      *     ListNode *next;
      *     ListNode() : val(0), next(nullptr) {}
      *     ListNode(int x) : val(x), next(nullptr) {}
      *     ListNode(int x, ListNode *next) : val(x), next(next) {}
      * };
      */
     class Solution {
     public:
         ListNode* reverseKGroup(ListNode* head, int k) {
             // 尝试用递归思考去解决：本任务是要以按照k个节点为一组来为每一组进行逆序，而对于达不到k个元素的就不需要逆序，那么算法可以优化成：先对一组去逆序，接着在对后续的元素按照k个节点为一组的方式去调用递归。我觉得难点在于递归前后传递这些，以及应该从哪里开始之类的
             // 先判断边界情况
             if (!head || k == 1)    return head;
             
             ListNode *end = head;
             for (int i = 0; i < k; i++) {
                 if (!end) return head;  // 如果达不到k个，则原顺序返回
                 end = end->next;
             }
     
             ListNode *pre = reverse(head, k);
             head->next = reverseKGroup(end, k);
     
             return pre;  // 表示的是每一组的最后一个节点，逆序后就成为了首节点
         }
         ListNode* reverse(ListNode *head, int k) {
             ListNode *cur, *pre, *t;
             pre = nullptr;
             cur = head;
     
             for (int i = 0; i < k; i++) {
                 t = cur->next;
                 cur->next = pre;
                 pre = cur;
                 cur = t;
             }
             return pre;
         }
     };

   [141. Linked List Cycle](https://leetcode.cn/problems/linked-list-cycle/)

   - 方法一：快慢指针秒杀
   - 方法二：用哈希表来判断，如果哈希表中节点出现一次，则直接true。代价是会消耗额外的空间复杂度

10. [142. Linked List Cycle II](https://leetcode.cn/problems/linked-list-cycle-ii/)

    1. 方法一：参考了题解实现的双指针
    2. 方法二：简简单单哈希表

11. [160. Intersection of Two Linked Lists](https://leetcode.cn/problems/intersection-of-two-linked-lists/)

    1. 方法一：双层循环的方式
    2. 方法二：两个链表右端对齐的方式（参考了官解，但我已经理解了）
    3. 方法三：运用哈希表或者集合的方式，最坏的时间复杂度是O(n + m)

    [19. Remove Nth Node From End of List](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/)

    1. 方法一：最简单的方法，两次循环
    2. 方法二：利用 vector 来存储节点的方式，可以只遍历一次链表就完成
    3. 方法三：用vector来模拟栈的使用
    4. 方法四：双指针解决（最推荐的）

    [83. Remove Duplicates from Sorted List](https://leetcode.cn/problems/remove-duplicates-from-sorted-list/)

    1. 简简单单的双指针

12. [21. Merge Two Sorted Lists](https://leetcode.cn/problems/merge-two-sorted-lists/)

    1. 方法一：直接遍历完两次链表
    2. 方法二：递归。可以发现问题是根据传递进来的两个链表，合并成一个新的链表，那么我就可以使这个问题规模缩小，然后不断地重复执行，这样由小到大，最后出来的就是我想要的。就是速度和消耗比较差了

    **-x == ~(x - 1)**

13. 复习递归解法：[92. Reverse Linked List II](https://leetcode.cn/problems/reverse-linked-list-ii/)

    [23. Merge k Sorted Lists](https://leetcode.cn/problems/merge-k-sorted-lists/)

    1. 方法一，将全部元素加入到一个数组中，后对数组排序，再遍历数组，生成一个链表的方式，最容易想到的做法
    2. 方法二：定义一个函数，该函数的功能是对两个链表进行合并并以小到大排序，首先需要计算共有多少个链表，则需要调用该函数 n - 1 次，即可完成全部链表的合并和排序的功能
    3. 方法三：分治法解决，将一个大问题分解为很多个小问题。例如本体要按顺序合并k个链表，那么我只需要先合并好左边的链表和右边的链表，再用一次合并两个链表即可实现；而左右两边链表合并的过程和这一个大问题是一样的

14. [24. Swap Nodes in Pairs](https://leetcode.cn/problems/swap-nodes-in-pairs/)

    1. 方法一：简单的双指针的方式（迭代或者叫模拟）

    2. 方法二：这题一看就可以用递归解，比如将交换链表中的每两个元素变为只交换一个，但是交换完之后，将pre指针指向调用递归后的结果

15. 无

    ### 哈希表

16. 常见的三种哈希结构

    当我们想使用哈希法来解决问题的时候，我们一般会选择如下三种数据结构。

    - 数组
    - set （集合）
    - map(映射)

    在C++中，set 和 map 分别提供以下三种数据结构，其底层实现以及优劣如下表所示：

    | 集合               | 底层实现 | 是否有序 | 数值是否可以重复 | 能否更改数值 | 查询效率 | 增删效率 |
    | ------------------ | -------- | -------- | ---------------- | ------------ | -------- | -------- |
    | std::set           | 红黑树   | 有序     | **否**           | 否           | O(log n) | O(log n) |
    | std::multiset      | 红黑树   | 有序     | **是**           | 否           | O(logn)  | O(logn)  |
    | std::unordered_set | 哈希表   | **无序** | **否**           | 否           | **O(1)** | **O(1)** |

    std::**unordered_set底层实现为哈希表**，std::**set 和std::multiset 的底层实现是红黑树**，红黑树是一种平衡二叉搜索树，所以key值是有序的，但key不可以修改，改动key值会导致整棵树的错乱，所以**只能删除和增加**。

    | 映射               | 底层实现 | 是否有序    | 数值是否可以重复 | 能否更改数值 | 查询效率 | 增删效率 |
    | ------------------ | -------- | ----------- | ---------------- | ------------ | -------- | -------- |
    | std::map           | 红黑树   | key有序     | key**不可重复**  | key不可修改  | O(logn)  | O(logn)  |
    | std::multimap      | 红黑树   | key有序     | key**可重复**    | key不可修改  | O(log n) | O(log n) |
    | std::unordered_map | 哈希表   | key**无序** | key不可重复      | key不可修改  | **O(1)** | **O(1)** |

    std::unordered_map 底层实现为哈希表，std::map 和std::multimap 的底层实现是红黑树。同理，std::map 和std::multimap 的key也是有序的（这个问题也经常作为面试题，考察对语言容器底层的理解）。

    当我们要使用集合来解决哈希问题的时候，优先使用unordered_set，因为它的查询和增删效率是最优的，**如果需要集合是有序的，那么就用set，如果要求不仅有序还要有重复数据的话，那么就用multiset。**

    [242. Valid Anagram](https://leetcode.cn/problems/valid-anagram/)

    1. 方法一：最简单的就是用两个哈希表的方式
    2. 方法二，排序后看想不想同
    3. 方法三：用数组的方式，但不适用于unicode编码的字符

    [349. Intersection of Two Arrays](https://leetcode.cn/problems/intersection-of-two-arrays/)

    1. 方法一：直接哈希数组搞定
    2. 方法二：用数组的方式（只能适用于题目给了你数组范围的条件下）

    直接使用set 不仅占用空间比数组大，而且速度要比数组慢，set把数值映射到key上都要做hash计算的。

    不要小瞧 这个耗时，在数据量大的情况，差距是很明显的

    [202. Happy Number](https://leetcode.cn/problems/happy-number/)

    1. 方法一：用自定义的死循环界限，但面试肯定不适合
    2. **方法二：快慢指针其实是判断有无环的标准操作**
    3. **方法三：哈希集合的方式来判断是否有重复的元素**

17. [1. Two Sum](https://leetcode.cn/problems/two-sum/)

    1. 方法一：最笨的三重循环方式
    2. 方法二：用分治法来解决，题目是求四个数组和为0，那我直接先求好两组两个数组的和，再将这两组（排列）组合起来
    3. **方法三：方法二的优化版本，减少了遍历次数**

    [454. 4Sum II](https://leetcode.cn/problems/4sum-ii/)

    1. 方法一：最笨的三重循环方式
    2. 方法二：用分治法来解决，题目是求四个数组和为0，那我直接先求好两组两个数组的和，再将这两组（排列）组合起来
    3. 方法三：方法二的优化版本，减少了遍历次数

18. [383. Ransom Note](https://leetcode.cn/problems/ransom-note/)

    1. 方法一：直接magazine存到哈希表里，再用ransomNote去-1
    2. 方法二：用数组形式的哈希表，会更加的快

    **[15. 3Sum](https://leetcode.cn/problems/3sum/)**

    1. 方法一：双层循环，确认两个数这样可以唯一确认第三个数。但是我自己写的超时了，借助到gpt才能通过

19. 无

20. 无

21. 无

22. 方法二：自己想的双指针办法，先对整个数组进行排序，然后双指针一个从前一个从后出发，这样得到的是两数之和，将该和与另一数相加就是结果了。自己写的版本超时了，gpt帮我优化好了，性能不如方法一

    方法二改进版：从前往后去固定一个数，接着在这个数的后面定义高低指针，去不断寻找符合条件的情况

23. \54. 替换数字（第八期模拟笔试）

    1. 方法一：用辅助空间的方式
    2. 方法二：不使用辅助空间的方法

    ### 字符串

    [541. Reverse String II](https://leetcode.cn/problems/reverse-string-ii/)

    1. 一层循环搞定

    [151. Reverse Words in a String](https://leetcode.cn/problems/reverse-words-in-a-string/)

    1. 方法一：使用辅助空间的方式，从后往前遍历
    2. 方法二：不使用辅助空间的方式来实现：将整个字符串逆序，这样单词位置逆序就实现了，再对每个单词实现逆序，这样就是最终结果了

24. 方法三：先逆序后去除收尾空格和中间多余空格，最后对每个单词进行交换即可

25. \55. 右旋字符串（第八期模拟笔试）

    通过整个字符串逆序，在对左右两侧分别逆序即可

26. [28. Find the Index of the First Occurrence in a String](https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/)

    1. 方法一：先判断needle子串的首位元素是否在haystack中符合，如果符合，再逐个判断，符合才返回
    2. 方法二：优化暴力匹配
    3. 方法三：kmp1，统一减一的实现方法，next表从 -1 开始

27. [459. Repeated Substring Pattern](https://leetcode.cn/problems/repeated-substring-pattern/)

    1. 方法一：暴力解

    2. 方法二：由数学归纳法可以发现，将两个s放在一起，去掉头尾一个字符，如果能在剩余中找到任意一个s，则说明是存在重复的

    3. 方法三：kmp

       ```cpp
           bool repeatedSubstringPattern(string s) {
               // 可以发现，如果一个字符串s是由重复子串组成，那么 最长相等前后缀不包含的子串一定是字符串s的最小重复子串况）
               // 由此可以得到此题解的步骤：
               // 1.建立next数组
               int n = s.size();
               vector<int> next(n);
               getNext(&next[0], s);
       
               // 2.找到最长相等前后缀不包含的子串的长度，如果不能被s字符串长度整除或者长度大于s字符串长度的一半，则不符合；否则一定成立
               int t = n - next.back(); // next[n - 1]
               if (n % t != 0 || t > ceil(n / 2))
                   return false;
               return true;
           }
       ```

## 7月

> 暑假回到家里就开摆了，在家管不住自己学习，一直在玩呀玩，就压根没怎么学了，月底31号时学了栈和队列开头

7.31

[232. Implement Queue using Stacks](https://leetcode.cn/problems/implement-queue-using-stacks/)

通过双栈的方式可以很容易实现队列的功能：一个是入栈的，另一个是根据入栈来调整的出栈

[225. Implement Stack using Queues](https://leetcode.cn/problems/implement-stack-using-queues/)

同样通过双队列的方式可以实现栈的功能：用第二个队列来进行备份（每次移动n-1个元素过去），这样剩下一个元素就是top元素

单队列的方式同样可以实现栈的功能：将前n-1个元素再一次插入到尾部，这样头元素就是栈top的元素了

## 8月



















