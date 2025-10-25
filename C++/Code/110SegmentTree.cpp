#include <vector>
#include <climits>
#include <algorithm>
#include <iostream>
using namespace std;

// 线段树节点存储的区间信息
struct Status {
    int lSum;  // 以左端点为起点的最大子段和
    int rSum;  // 以右端点为终点的最大子段和
    int mSum;  // 区间内的最大子段和
    int iSum;  // 区间总和
};

class SegmentTree {
private:
    vector<Status> tree;  // 存储线段树节点
    int n;  // 原始数组长度

    // 合并左右子区间的信息（pushUp操作）
    Status pushUp(Status left, Status right) {
        int iSum = left.iSum + right.iSum;
        int lSum = max(left.lSum, left.iSum + right.lSum);
        int rSum = max(right.rSum, right.iSum + left.rSum);
        int mSum = max({left.mSum, right.mSum, left.rSum + right.lSum});
        return {lSum, rSum, mSum, iSum};
    }

    // 递归构造线段树
    void build(const vector<int>& nums, int node, int l, int r) {
        if (l == r) {
            // 叶子节点：四个值均为nums[l]
            tree[node] = {nums[l], nums[l], nums[l], nums[l]};
            return;
        }
        int mid = (l + r) / 2;
        int leftNode = 2 * node;    // 左子节点编号（假设根节点从1开始）
        int rightNode = 2 * node + 1;  // 右子节点编号
        // 递归构造左右子树
        build(nums, leftNode, l, mid);
        build(nums, rightNode, mid + 1, r);
        // 合并左右子树信息
        tree[node] = pushUp(tree[leftNode], tree[rightNode]);
    }

    // 递归查询区间[L, R]的信息
    Status query(int node, int l, int r, int L, int R) {
        // 当前节点区间完全在[L, R]内，直接返回
        if (L <= l && r <= R) {
            return tree[node];
        }
        int mid = (l + r) / 2;
        int leftNode = 2 * node;
        int rightNode = 2 * node + 1;

        // 情况1：查询区间只在左子树
        if (R <= mid) {
            return query(leftNode, l, mid, L, R);
        }
        // 情况2：查询区间只在右子树
        else if (L > mid) {
            return query(rightNode, mid + 1, r, L, R);
        }
        // 情况3：查询区间跨左右子树，需合并左右结果
        else {
            Status leftStatus = query(leftNode, l, mid, L, mid);
            Status rightStatus = query(rightNode, mid + 1, r, mid + 1, R);
            return pushUp(leftStatus, rightStatus);
        }
    }

    // 递归更新位置pos的值为val
    void update(int node, int l, int r, int pos, int val) {
        if (l == r) {
            // 找到叶子节点，更新值
            tree[node] = {val, val, val, val};
            return;
        }
        int mid = (l + r) / 2;
        int leftNode = 2 * node;
        int rightNode = 2 * node + 1;

        // 确定pos在左子树还是右子树
        if (pos <= mid) {
            update(leftNode, l, mid, pos, val);
        } else {
            update(rightNode, mid + 1, r, pos, val);
        }
        // 更新当前节点信息
        tree[node] = pushUp(tree[leftNode], tree[rightNode]);
    }

public:
    // 构造函数：初始化线段树
    SegmentTree(const vector<int>& nums) {
        n = nums.size();
        if (n == 0) return;
        // 线段树大小通常为4*n（确保足够存储所有节点）
        tree.resize(4 * n);
        build(nums, 1, 0, n - 1);  // 根节点编号为1，对应区间[0, n-1]
    }

    // 对外接口：查询[L, R]的最大子段和
    int queryMaxSubarray(int L, int R) {
        if (L < 0 || R >= n || L > R) return INT_MIN;
        return query(1, 0, n - 1, L, R).mSum;
    }

    // 对外接口：更新pos位置的值为val
    void updateVal(int pos, int val) {
        if (pos < 0 || pos >= n) return;
        update(1, 0, n - 1, pos, val);
    }
};

// 测试
int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    // 初始化线段树
    SegmentTree st(nums);
    
    // 查询整个数组的最大子段和（预期是4 + (-1) + 2 + 1 = 6）
    cout << "整个数组的最大子段和：" << st.queryMaxSubarray(0, 8) << endl;
    
    // 查询区间[3, 6]的最大子段和（4, -1, 2, 1 → 4-1+2+1=6）
    cout << "[3,6]的最大子段和：" << st.queryMaxSubarray(3, 6) << endl;
    
    // 更新位置2的值（原-3改为5），数组变为[-2,1,5,4,-1,2,1,-5,4]
    st.updateVal(2, 5);
    
    // 再次查询整个数组的最大子段和（1+5+4-1+2+1=12）
    cout << "更新后整个数组的最大子段和：" << st.queryMaxSubarray(0, 8) << endl;
    
    return 0;
}