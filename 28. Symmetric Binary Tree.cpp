// 方法一：递归+对称前序遍历解法
// 执行用时 :8 ms, 在所有 C++ 提交中击败了70.40%的用户
// 内存消耗 :19 MB, 在所有 C++ 提交中击败了100.00%的用户

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
    bool isSymmetric(TreeNode* root) {
        return help(root, root);
    }
    bool help(TreeNode* A, TreeNode* B) {
        if (A == nullptr && B == nullptr) return true;
        if (A == nullptr || B == nullptr) return false;
        if (A->val !=  B->val) return false;
        return help(A->left, B->right) && help(A->right, B->left);
    }
};
