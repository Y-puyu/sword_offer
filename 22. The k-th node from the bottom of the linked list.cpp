// 方法一：先走k - 1步解法
// 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗 :12.9 MB, 在所有 C++ 提交中击败了100.00%的用户

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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (head == nullptr) return nullptr;
        int count = 0;
        ListNode* node = head;
        ListNode* tmp = head;
        while (head) {
            head = head->next;
            ++count;
        }
        if (k > count) return nullptr;
        
        while (k) {
            tmp = tmp->next;    
            --k;
        }
        while (tmp) {
            tmp = tmp->next;
            node = node->next;
        }
        return node;
    }
};

