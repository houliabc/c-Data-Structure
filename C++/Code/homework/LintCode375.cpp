#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* cloneTree(TreeNode* r) {
    if (r == nullptr) return nullptr;
    TreeNode* newNode = new TreeNode(r->val);
    newNode->left = cloneTree(r->left);
    newNode->right = cloneTree(r->right);
    return newNode;
}

void preorder(TreeNode* node) {
    if (node == nullptr) return;
    cout << node->val << " ";
    preorder(node->left);
    preorder(node->right);
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(2);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(4);

    TreeNode* clonedRoot = cloneTree(root);

    cout << "原树前序遍历: ";
    preorder(root);
    cout << endl;

    cout << "克隆树前序遍历: ";
    preorder(clonedRoot);
    cout << endl;

    return 0;
}