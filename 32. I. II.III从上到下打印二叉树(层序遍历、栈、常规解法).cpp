// 方法一：辅助队列+层序遍历+常规解法
// 执行用时 :4 ms, 在所有 C++ 提交中击败了87.08%的用户
// 内存消耗 :14.5 MB, 在所有 C++ 提交中击败了100.00%的用户

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
    vector<int> levelOrder(TreeNode* root) {
        vector<int> vt;
        if (root == nullptr) return vt;
        queue<TreeNode*> q;
        TreeNode* cur;
        q.push(root);
        while (!q.empty()) {
            for (int i = 0; i < q.size(); ++i) {
                cur = q.front();
                vt.push_back(cur->val);
                q.pop();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        return vt;
    }
};




// 方法一：辅助队列+层序遍历+常规解法
// 执行用时 :4 ms, 在所有 C++ 提交中击败了90.01%的用户
// 内存消耗 :15.1 MB, 在所有 C++ 提交中击败了100.00%的用户

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        vector<int> vt;
        queue<TreeNode*> q;   
        TreeNode* cur;
        int len = 1;
        q.push(root);
        while (!q.empty()) {
            for (int i = 0; i < len; ++i) { 
                cur = q.front();
                vt.push_back(cur -> val);
                q.pop();
                if (cur->left) q.push(cur -> left);
                if (cur->right) q.push(cur->right);
            }
            res.push_back(vt);			// 改动点
            vt.clear();					// 改动点
            len = q.size();
        }
        return res;
    }
};

// 方法一：辅助队列+层序遍历+标志奇偶层+常规解法
// 执行用时 :4 ms, 在所有 C++ 提交中击败了86.05%的用户
// 内存消耗 :15.1 MB, 在所有 C++ 提交中击败了100.00%的用户

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        vector<int> vt;
        queue<TreeNode*> q;   
        TreeNode* cur;
        int len = 1, cnt = 1;
        q.push(root);
        while (!q.empty()) {
            for (int i = 0; i < len; ++i) { 
                cur = q.front();
                vt.push_back(cur -> val);
                q.pop();
                if (cur->left) q.push(cur -> left);
                if (cur->right) q.push(cur->right);
            }
            if (cnt % 2 == 0) reverse(vt.begin(), vt.end());	// 注意点
            res.push_back(vt);
            vt.clear();
            len = q.size();
            ++cnt;
        }
        
        return res;
    }
};

// 方法二：辅助双栈+层序遍历+常规解法
// 执行用时 :16 ms, 在所有 C++ 提交中击败了6.88%的用户
// 内存消耗 :15.1 MB, 在所有 C++ 提交中击败了100.00%的用户

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> vt;
        if (root == nullptr) return res;
        int len = 1;
        stack<TreeNode*> s1, s2;
        s2.push(root);
        while (!s1.empty() or !s2.empty()) {
            while (!s2.empty()) {
                TreeNode* tmp = s2.top();
                vt.push_back(tmp->val);
                s2.pop();
                if (tmp->left) s1.push(tmp->left);
                if (tmp->right) s1.push(tmp->right);
            }
            if (vt.size()) res.push_back(vt);
            vt.clear();
            while (!s1.empty()) {
                TreeNode* tmp = s1.top();
                vt.push_back(tmp->val);
                s1.pop();
                if (tmp->right) s2.push(tmp->right);
                if (tmp->left) s2.push(tmp->left);
            }
            if (vt.size()) res.push_back(vt);
            vt.clear();
        }
        return res;
    }
};

