// 方法一：中序遍历+常规解法
// 执行用时 :20 ms, 在所有 C++ 提交中击败了89.38%的用户
// 内存消耗 :26.7 MB, 在所有 C++ 提交中击败了100.00%的用户

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int res = 0, cnt = 0;
    int kthLargest(TreeNode* root, int k) {
        help(root, k);
        return res;
    }
    void help(TreeNode* root, int k) {
        if (root == nullptr) return;
        if (root->right != nullptr) help(root->right, k);
        ++cnt;
        if (cnt == k) res = root->val;
        if (root->left != nullptr) help(root->left, k);
        return;
    }
};
