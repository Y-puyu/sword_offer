// 方法一：前后指针常规删除法
// 执行用时 :8 ms, 在所有 C++ 提交中击败了81.22%的用户
// 内存消耗 :13.7 MB, 在所有 C++ 提交中击败了100.00%的用户

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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* node = head;
        ListNode* prev = head;
        if (head == nullptr)    
            return nullptr;
        while (node) {
            if (head->val == val)
                return head->next;
            if (node->next == nullptr && node->val == val) {
                prev->next = node->next;
            }
            if (node->val == val) {
                prev->next = node->next;
            }
            prev = node;
            node = node->next;
        }
        return head;
    }
};



// 方法二：递归删除法
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
    ListNode* deleteNode(ListNode* head, int val) {
        if (head == nullptr)    
            return nullptr;
        if (head->val == val) {
            return head->next;
        }
        head->next = deleteNode(head->next, val);
        return head;
    }
};

