// 方法一：逆置链表、顺序遍历输出
// 执行用时 :8 ms, 在所有 C++ 提交中击败了67.78%的用户
// 内存消耗 :9.7 MB, 在所有 C++ 提交中击败了100.00%的用户

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> vt;
        if (head == nullptr)
            return vt;
        head = ReverseList(head);
        for (ListNode* p = head; p != nullptr; p = p->next)
            vt.push_back(p->val);
        return vt;
    }

    ListNode* ReverseList(ListNode* pHead) {
        if (pHead->next == nullptr || pHead==nullptr)
            return pHead;
        ListNode* pre = NULL;
        ListNode* cur = pHead;
        ListNode* next = NULL;
        while (cur != NULL) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};




// 方法二：辅助栈空间
// 执行用时 :8 ms, 在所有 C++ 提交中击败了67.78%的用户
// 内存消耗 :9.9 MB, 在所有 C++ 提交中击败了100.00%的用户

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> vt;
        stack<int> st;
        if (head == nullptr)
            return vt;
        for (ListNode* p = head; p != nullptr; p = p->next)
            st.push(p->val);
        while (!st.empty()) {
            vt.push_back(st.top());
            st.pop();
        }
        return vt;
    }
};

// 方法三：递归法
// 执行用时 :112 ms, 在所有 C++ 提交中击败了5.06%的用户
// 内存消耗 :265.9 MB, 在所有 C++ 提交中击败了100.00%的用户
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> vt;
    vector<int> reversePrint(ListNode* head) {
        if (head == nullptr)
            return vt;
        reversePrint(head->next);
        vt.push_back(head->val);
        return vt;
    }
};