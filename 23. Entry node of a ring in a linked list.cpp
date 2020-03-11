// 方法一：带环判断及拓展
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        ListNode* node = pHead;
        ListNode* head = pHead;
        ListNode* slow = pHead;
        ListNode* quick = pHead;
        int n = 0;
        if (pHead == nullptr)return nullptr;
        while (quick) {
            if (quick->next == nullptr) return nullptr;
            if (quick->next->next == nullptr) return nullptr;
            quick = quick->next->next;
            slow = slow->next;
            if (slow == quick) break;
        }
        while (1) {
            slow = slow->next;
            ++n;
            if (slow == quick) break;
        }
        while (n) {
            node = node->next;
            --n;
        }
        while (1) {
            if (node == head) break;
            node = node->next;
            head = head->next;
        }
        return node;
    }
};

