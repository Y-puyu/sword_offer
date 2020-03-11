// 方法一：递归+常规解法
// 执行用时 :16 ms, 在所有 C++ 提交中击败了46.43%的用户
// 内存消耗 :21.4 MB, 在所有 C++ 提交中击败了100.00%的用户

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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return (left > right) ? (left + 1) : (right + 1);
    }
};




// 方法一：递归+常规解法
// 执行用时 :16 ms, 在所有 C++ 提交中击败了79.85%的用户
// 内存消耗 :22.7 MB, 在所有 C++ 提交中击败了100.00%的用户

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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        int diff = left - right;
        if (diff > 1 || diff < -1) return false;

        return isBalanced(root->left) and isBalanced(root->right);
    }

    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return (left > right) ? (left + 1) : (right + 1);
    }
};

// 方法二：递归优化+巧妙解法
// 执行用时 :12 ms, 在所有 C++ 提交中击败了93.83%的用户
// 内存消耗 :23.7 MB, 在所有 C++ 提交中击败了100.00%的用户

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
    bool isBalanced(TreeNode* root) {
        int depth = 0;
        return help(root, &depth);
    }

    bool help(TreeNode* root, int* pDepth) {
        if (root == nullptr) {
            *pDepth = 0;
            return true;
        }
        int left;
        int right;
        if (help(root->left, &left) and help(root->right, &right)) {
            int diff = left - right;
            if (diff <= 1 and diff >= -1) {
                *pDepth = 1 + (left > right ? left : right);
                return true;
            }
        }
        return false;
    }
};


