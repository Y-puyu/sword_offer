// 方法一：递归+常规解法
// 执行用时 :40 ms, 在所有 C++ 提交中击败了6.23%的用户
// 内存消耗 :37.2 MB, 在所有 C++ 提交中击败了100.00%的用户

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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == nullptr) return res;
        vector<int> vt;
        int amt = 0;
        help(root, sum, vt, amt);
        return res;
    }
    void help(TreeNode* root, int sum, vector<int> vt, int amt) {
        amt += root->val;
        vt.push_back(root->val);
        // 如果为叶节点，并且路径上结点的和等于输入的值，打印这条路径
        bool isLeaf = root->left == nullptr and root->right == nullptr;
        if (amt == sum and isLeaf) res.push_back(vt);
        // 如果不为叶节点，则遍历它的子节点
        if (root->left != nullptr) help(root->left, sum, vt, amt);
        if (root->right != nullptr) help(root->right, sum, vt, amt);
        // 在返回到父节点之前，在路径中删除当前节点
        amt -= root->val;
        vt.pop_back();
    }
};

