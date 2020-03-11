// 方法一：中序遍历+递归解法
// 执行用时 :8 ms, 在所有 C++ 提交中击败了84.14%的用户
// 内存消耗 :10 MB, 在所有 C++ 提交中击败了100.00%的用户

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) return nullptr;
        Node *head = nullptr, *pre = nullptr;
        inorder(root, pre, head);
        pre->right = head;
        head->left = pre;
        return head;
    }
    void inorder(Node* node, Node*& pre, Node*& head) {
        if (node == nullptr) return;
        inorder(node->left, pre, head);
        if (head == nullptr) {
            head = node;
            pre = node;
        } else {
            pre->right = node;
            node->left = pre;
            pre = node;
        }
        inorder(node->right, pre, head);
    }
};