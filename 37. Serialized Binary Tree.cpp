// 方法一：层序遍历+迭代解法
// 执行用时 :8 ms, 在所有 C++ 提交中击败了84.14%的用户
// 内存消耗 :10 MB, 在所有 C++ 提交中击败了100.00%的用户

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    string encode(TreeNode* root) {
        if (!root) return "#,";
        string res = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *t = q.front(); q.pop();
            if (t) {
                res += to_string(t->val) + ",";
                q.push(t->left);
                q.push(t->right);
            } else {
                res += "#,";
            }
        }
        return res;
    }

    TreeNode* takeNum(const string& data, int& p) {
        if (data[p] == '#') {
            p += 2;
            return NULL;
        }
        bool isN = false;
        if (data[p] == '-') {
            isN = true;
            p++;
        }
        int val = 0;
        while (data[p] != ',') {
            val = val * 10 + (data[p] - '0');
            p++;
        }
        p++;
        if (isN) {
            val = -val;
        }
        return new TreeNode(val);
    }

    TreeNode* decode(const string& data) {
        if (data[0] == '#') return NULL;
        int p = 0;

        TreeNode *root = takeNum(data, p);
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *t = q.front(); q.pop();
            TreeNode *l = takeNum(data, p);
            TreeNode *r = takeNum(data, p);
            if (l) q.push(l);
            if (r) q.push(r);
            t->left = l;
            t->right = r;
        }
        return root;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = encode(root);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode *root = decode(data);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));




// 方法二：先序遍历+递归解法
// 执行用时 :40 ms, 在所有 C++ 提交中击败了63.53%的用户
// 内存消耗 :26.5 MB, 在所有 C++ 提交中击败了100.00%的用户

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }
private:
    void serialize(TreeNode *root, ostringstream &out) {
        if (root) {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        } else {
            out << "# ";
        }
    }
    TreeNode* deserialize(istringstream &in) {
        string val;
        in >> val;
        if (val == "#") return nullptr;
        TreeNode *root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

