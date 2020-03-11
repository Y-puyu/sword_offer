// 方法一：辅助HashMap+迭代解法
// 执行用时 :8 ms, 在所有 C++ 提交中击败了94.82%的用户
// 内存消耗 :13.6 MB, 在所有 C++ 提交中击败了100.00%的用户

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node *res = new Node(head->val);
        Node *node = res, *cur = head->next;
        unordered_map<Node*, Node*> m;
        m[head] = res;
        while (cur) {
            Node *t = new Node(cur->val, nullptr, nullptr);
            node->next = t;
            m[cur] = t;
            node = node->next;
            cur = cur->next;
        }
        node = res; cur = head;
        while (cur) {
            node->random = m[cur->random];
            node = node->next;
            cur = cur->next;
        }
        return res;
    }
};



// 方法二：辅助HashMap+递归解法
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;
        return helper(head, m);
    }
    Node* helper(Node* node, unordered_map<Node*, Node*>& m) {
        if (!node) return nullptr;
        if (m.count(node)) return m[node];
        Node *res = new Node(node->val, nullptr, nullptr);
        m[node] = res;
        res->next = helper(node->next, m);
        res->random = helper(node->random, m);
        return res;
    }
};

// 方法三：非辅助空间+O(n)O(n)O(n)时间效率+巧妙解法
// 执行用时 :8 ms, 在所有 C++ 提交中击败了94.82%的用户
// 内存消耗 :13.4 MB, 在所有 C++ 提交中击败了100.00%的用户

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        Node* cur = head;
        while (cur != nullptr) {
            Node* node = new Node(cur->val);
            node->next = cur->next;
            cur->next = node;
            cur = cur->next->next;
        }
        cur = head;
        while (cur != nullptr) {
            if (cur->random != nullptr) cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        Node* copyHead = head->next;
        cur = head;
        Node * copy = head->next;
        while (cur != nullptr) {
            cur->next = cur->next->next;
            cur = cur->next;
            if (copy->next != nullptr) {
                copy->next = copy->next->next;
                copy = copy->next;
            }
        }
        return copyHead;
    }
};


