// 方法一：分析遍历法
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if (pNode == nullptr)
            return nullptr;
        TreeLinkNode* Next = nullptr;
        if (pNode->right != nullptr) {
            Next = pNode->right;
            while (Next->left != nullptr) {
                    Next = Next->left;
            }
        }
        else if (pNode->next != nullptr) {
            TreeLinkNode* cur = pNode;
            TreeLinkNode* parent = pNode->next;
            while (parent != nullptr && cur == parent->right) {
                cur = parent;
                parent = parent->next;
            }
            Next = parent;
        }
        return Next;
    }
};
