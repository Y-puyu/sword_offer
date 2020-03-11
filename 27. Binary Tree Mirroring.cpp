// 方法一：递归+交换左右子树解法
// 执行用时 :4 ms, 在所有 C++ 提交中击败了71.97%的用户
// 内存消耗 :11 MB, 在所有 C++ 提交中击败了100.00%的用户

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
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNode* head = root;
        if (root->left == nullptr && root->right == nullptr) return root;
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        if (root->left) mirrorTree(root->left);
        if (root->right) mirrorTree(root->right);
        return head;
    }
};