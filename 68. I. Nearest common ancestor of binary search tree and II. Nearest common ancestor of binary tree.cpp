// 方法一：递归+巧妙解法
// 执行用时 :44 ms, 在所有 C++ 提交中击败了55.33%的用户
// 内存消耗 :24.9 MB, 在所有 C++ 提交中击败了100.00%的用户

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        if (root->val > max(p->val, q->val)) 
            return lowestCommonAncestor(root->left, p, q);
        else if (root->val < min(p->val, q->val)) 
            return lowestCommonAncestor(root->right, p, q);
        else return root;
    }
};




// 方法二：迭代+巧妙解法
// 执行用时 :36 ms, 在所有 C++ 提交中击败了90.13%的用户
// 内存消耗 :25.3 MB, 在所有 C++ 提交中击败了100.00%的用户

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (true) {
            if (root->val > max(p->val, q->val)) root = root->left;
            else if (root->val < min(p->val, q->val)) root = root->right;
            else break;
        }      
        return root;
    }
};


// 方法一：递归+巧妙解法
// 执行用时 :12 ms, 在所有 C++ 提交中击败了99.60%的用户
// 内存消耗 :16.2 MB, 在所有 C++ 提交中击败了100.00%的用户

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if (!root || p == root || q == root) return root;
       TreeNode *left = lowestCommonAncestor(root->left, p, q);
       TreeNode *right = lowestCommonAncestor(root->right, p, q);
       if (left && right) return root;
       return left ? left : right;
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

