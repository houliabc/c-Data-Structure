

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

1. [20. Valid Parentheses](https://leetcode.cn/problems/valid-parentheses/)

   方法一：将全部元素进栈，当遇到右括号就出栈

   方法二：当遇到左括号时，将对应的有括号入栈；而当遇到右括号时，出栈看匹不匹配，如果不匹配直接返回0了

   [1047. Remove All Adjacent Duplicates In String](https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/)

   方法一：就正常每个元素压入栈中解

   方法二：运用在官解中的string容器自带的入栈出栈功能来实现

2. [150. Evaluate Reverse Polish Notation](https://leetcode.cn/problems/evaluate-reverse-polish-notation/)

   只是求结果而不是实现运算器的功能就容易很多，因为实现运算器需要考虑很多特殊情况，输入有问题的情况，这题直接求值保证输入没问题的情况下是很简单做出来的

   [239. Sliding Window Maximum](https://leetcode.cn/problems/sliding-window-maximum/)

   方法一：本题运用了一个**新知识点单调队列**的方法：递增或递减的队列

   方法二：尝试将队列封装起来的方法来实现本题目

3. 无

4. 无

5. 无

6. 无

7. 无

8. 无

9. 无

10. 无

11. [347. Top K Frequent Elements](https://leetcode.cn/problems/top-k-frequent-elements/)

    方法一：运用到了哈希表统计个数，之后调换键值，以此来选出 k 个出现频率最多的
    时间复杂度O(n + n + n) = O(n)
    空间复杂度O(n + n * logn + n) = O(nlogn)

    方法二：用优先级队列（就是一个堆，完全二叉树）实现，本题中用小顶堆处理，如果使用大顶堆就需要维护n个元素的大顶堆；而小顶堆我们只需要维护k个元素即可，一旦插入了k个元素以上，就弹出这一个超出的，并不在插入，此时小顶堆里，就全是最高频的元素

12. 无

13. 无

14. 347的方法二

    方法二用lambda实现

15. 



## 9月

1. 无

2. 无

3. 无

4. 无

5. 无

6. 无

7. 无

8. 无

9. 无

10. 无

11. 无

12. 无

13. 无

14. 无

15. 无

16. 无

17. 无

18. 无

19. ### 二叉树

    [102. Binary Tree Level Order Traversal](https://leetcode.cn/problems/binary-tree-level-order-traversal/)

    方法一：用队列来实现层序遍历

    方法二：递归版本

20. 

## 10月

1. 无

2. 无

3. [144. Binary Tree Preorder Traversal](https://leetcode.cn/problems/binary-tree-preorder-traversal/)

   [94. Binary Tree Inorder Traversal](https://leetcode.cn/problems/binary-tree-inorder-traversal/)

   [145. Binary Tree Postorder Traversal](https://leetcode.cn/problems/binary-tree-postorder-traversal/)

   都分别有递归和迭代（栈）两种方法

4. [102. Binary Tree Level Order Traversal](https://leetcode.cn/problems/binary-tree-level-order-traversal/)

   也是有递归和迭代（队列）两种方法

   ```cpp
           vector<vector<int>> res;
           queue<TreeNode*> que;
           if (root)
               que.push(root);
           while (!que.empty()) {
               vector<int> t;
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
   ```

   

   [199. Binary Tree Right Side View](https://leetcode.cn/problems/binary-tree-right-side-view/)

   这题是只需要取层序遍历的最右边的节点，n 层就有 n 个节点

   [637. Average of Levels in Binary Tree](https://leetcode.cn/problems/average-of-levels-in-binary-tree/)

   简单题

   [429. N-ary Tree Level Order Traversal](https://leetcode.cn/problems/n-ary-tree-level-order-traversal/)

   多一层循环

   [515. Find Largest Value in Each Tree Row](https://leetcode.cn/problems/find-largest-value-in-each-tree-row/)

   只需筛选一下即可

   [104. Maximum Depth of Binary Tree](https://leetcode.cn/problems/maximum-depth-of-binary-tree/)

   套模板即可

   [111. Minimum Depth of Binary Tree](https://leetcode.cn/problems/minimum-depth-of-binary-tree/)

   只需找到左右子树都不存在的那一层即可

   [226. Invert Binary Tree](https://leetcode.cn/problems/invert-binary-tree/)

   只需swap交换左右子树即可

5. [101. Symmetric Tree](https://leetcode.cn/problems/symmetric-tree/)

6. [101. Symmetric Tree](https://leetcode.cn/problems/symmetric-tree/)

   1. 方法一（自己写的优化版）：用到**广度遍历，针对每一层，要求最左边和最右边往中间走，值要相同**
   2. 方法二：使用递归的后序遍历的方式来判断，**左边实行左右中的顺序，右边实现右左中的顺序，需要注意当节点为空时需要插入一个作为标记，防止什么也不插入，会出现问题**
   3. 方法三：判断二叉树是否对称，只需**递归判断内层（左子树的右儿子和右子树的左儿子）与外层是否相等**即可

   [222. Count Complete Tree Nodes](https://leetcode.cn/problems/count-complete-tree-nodes/)

   迭代法层序遍历搞定

   [110. Balanced Binary Tree](https://leetcode.cn/problems/balanced-binary-tree/)

   递归解

7. [257. Binary Tree Paths](https://leetcode.cn/problems/binary-tree-paths/)

   用到了递归和回溯，参考了，自己有一点思路但想不出完整的

   [100. Same Tree](https://leetcode.cn/problems/same-tree/)

   只需将对称的树算法的内层比较和外层比较设置为相同的左子树和右子树即可

   [572. Subtree of Another Tree](https://leetcode.cn/problems/subtree-of-another-tree/)

   利用到了第100做递归，参考了别的人

   思路就是先找到节点值相同的节点，之后利用100做判断，如果没找到就继续dfs找

8. [112. Path Sum](https://leetcode.cn/problems/path-sum/)

   1. void的递归版本（略麻烦）：思路就是像昨天写的那一道所有路径类似（用到了回溯），只是将路径输出变为了求和即可
   2. 带返回值的递归版本，还了一种思路，不再是求和了而是用目标值做减法：判断左右子树是否符合题目要求，只有符合要求才返回true

   递归函数什么时候需要返回值？什么时候不需要返回值？这里总结如下三点：

   - 如果需要搜索整棵二叉树且不用处理递归返回值，递归函数就不要返回值。（这种情况就是本文下半部分介绍的113.路径总和ii）
   - 如果需要搜索整棵二叉树且需要处理递归返回值，递归函数就需要返回值。 （这种情况我们在[236. 二叉树的最近公共祖先 (opens new window)](https://programmercarl.com/0236.二叉树的最近公共祖先.html)中介绍）
   - 如果要搜索其中一条符合条件的路径，那么递归一定需要返回值，因为遇到符合条件的路径了就要及时返回。（本题的情况）

   [113. Path Sum II](https://leetcode.cn/problems/path-sum-ii/)

   这题就是112的小修改版本，只需多增加一个二维数组，同时还要将路上取到的值得保存下来

   [106. Construct Binary Tree from Inorder and Postorder Traversal](https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)

   1. 先构造根节点（指向后序序列的最后一个），在递归的调用左指针和右指针指向递归出来的新树（将左右序列作为vector——耗时耗空间）
   2. 去掉vector，采用指针的方式来实现

9. [105. Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

   用java写的根据下标来实现

   [617. Merge Two Binary Trees](https://leetcode.cn/problems/merge-two-binary-trees/)

   java版：思路是递归遍历两个树，当相同就和加起来构建一个新节点，否则用非空的那一个节点作为新树对应位置上的节点

   [700. Search in a Binary Search Tree](https://leetcode.cn/problems/search-in-a-binary-search-tree/)

   秒了：根据二叉搜索树先找到那一个节点

   [98. Validate Binary Search Tree](https://leetcode.cn/problems/validate-binary-search-tree/)

   递归实现，通过标记左子树和右子树的最小和最大范围来确定是否符合二叉搜索树

   中序遍历递归法解决

10. [530. Minimum Absolute Difference in BST](https://leetcode.cn/problems/minimum-absolute-difference-in-bst/)

    方法一：中序遍历BST（得到递增有序序列）构建对应的vector，后选出最小的两个即可

    方法二：直接递归保存前节点的方式（无需构造vector）

    [236. Lowest Common Ancestor of a Binary Tree](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/)

    本题应该使用深度遍历，对于需要回溯的问题，后序遍历是最合适的，因为是先访问完两个子树才访问根节点的，正好符合本题回溯需求

    [235. Lowest Common Ancestor of a Binary Search Tree](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/)

    二叉搜索树是排序的，可以利用这一点，实现普通树的公共祖先

    [701. Insert into a Binary Search Tree](https://leetcode.cn/problems/insert-into-a-binary-search-tree/)

    先实现最简单的在叶子节点的左右子树中插入，就这一种情况

11. [450. Delete Node in a BST](https://leetcode.cn/problems/delete-node-in-a-bst/)

    1. 方法一：当左右子树都有时，将左子树上位，且此左子树右指针应指向原右子树，且若左子树有右节点时，应该BST插入到原右子树的左子树里。使用了递归，并且还运用到了昨天写的BST中插入节点的方式，我的大题思路是正确的，但是一些细节问题没有写对，在gpt的帮助下，成功实现了
    2. 方法二，更高效的方法：当删除节点左右子树都有时，将左子树插入到右子树的最左下角（根据BST性质，一定能插入且是符合要求的），而右子树作为新的子树节点上位替换那个被删除的节点，同时要递归的将从根开始的左右指针指向这个被删除节点后调整好的节点
    3. 方法三：假设不是BST，不运用它的特性来实现删除操作（遍历所有节点）

    [669. Trim a Binary Search Tree](https://leetcode.cn/problems/trim-a-binary-search-tree/)

    还以为是运用到上一题的知识，不断的删除，但其实不用那么复杂，直接重新规划指针即可

    [108. Convert Sorted Array to Binary Search Tree](https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/)

    递归的去取数组中的中间左边元素来插入进二叉树中

    致辞二叉树完结

12. ### 回溯

    [77. Combinations](https://leetcode.cn/problems/combinations/)

    实现想不出，因为明明是叫回溯算法，但我却忘记了pop_back的回溯方式，参考了就明白了

    剪枝优化了循环次数

    [40. Combination Sum II](https://leetcode.cn/problems/combination-sum-ii/)

    这一题不需要考虑元素个数问题，而是考虑求的和要符合条件，但是因为存在重复值的问题，故一定会出现重复的结果，这就需要在插入前进行适当的筛选。我的实现参考了gpt的，对于重复元素进行了剪枝

13. [216. Combination Sum III](https://leetcode.cn/problems/combination-sum-iii/)

    和前面解法类似

    [17. Letter Combinations of a Phone Number](https://leetcode.cn/problems/letter-combinations-of-a-phone-number/)

    自己写的，会稍有点区别，大题框架还是一致的

14. 

15. 

16. 

17. 

18. 

19. 

20. 

21. 

22. 

23. 

24. 

25. 

26. 

27. 

28. 

29. 

30. 

31. 

32. 









