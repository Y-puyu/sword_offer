// 方法一：递归解法
// 执行用时 :24 ms, 在所有 C++ 提交中击败了47.33%的用户
// 内存消耗 :20.3 MB, 在所有 C++ 提交中击败了100.00%的用户

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        
        ListNode* tmp = nullptr;
        if (l1->val < l2->val) {
            tmp = l1;
            tmp->next = mergeTwoLists(l1->next, l2);
        }
        else {
            tmp = l2;
            tmp->next = mergeTwoLists(l1, l2->next);
        }
        return tmp;
    }
};




// 方法二：迭代解法
// 执行用时 :40 ms, 在所有 C++ 提交中击败了6.05%的用户
// 内存消耗 :19.9 MB, 在所有 C++ 提交中击败了100.00%的用户

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        ListNode* head = new ListNode(0);
        ListNode* ret = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                head->next = l1;
                l1 = l1->next;
                head = head->next;
            }
            else {
                head->next = l2;
                l2 = l2->next;
                head = head->next;
            } 
        }
        head->next = l1 == nullptr ? l2 : l1;
        return ret->next;
    }
};



