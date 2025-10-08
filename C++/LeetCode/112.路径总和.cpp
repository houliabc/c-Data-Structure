/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 */

// @lc code=start
// Definition for a binary tree node.
// #include <iostream>
// #include <climits>
// #include <vector>

// using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
class Solution {
    bool res = false;
    void getPath(TreeNode* node, vector<int>& path, int targetSum) {
        // 开头就插入，防止根节点未插入
        path.push_back(node->val);
        // 指定结束条件：子节点
        if (!node->left && !node->right) {
            int sum = 0;
            for (auto i: path)
                sum += i;
            if (sum == targetSum)
                res = true;
            return;
        }
        
        // 递归配合回溯
        if (node->left) {
            getPath(node->left, path, targetSum);
            path.pop_back();
        }
        if (node->right) {
            getPath(node->right, path, targetSum);
            path.pop_back();
        }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        // 思路就是像昨天写的那一道所有路径类似（用到了回溯），只是将路径输出变为了求和即可
        if (!root)     return false;
        vector<int> path;
        getPath(root, path, targetSum);
        return res;
    }
};
// @lc code=end

