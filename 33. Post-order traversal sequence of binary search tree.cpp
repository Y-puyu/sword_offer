// 方法一：递归+辅助栈，常规解法
// 执行用时 :8 ms, 在所有 C++ 提交中击败了31.96%的用户
// 内存消耗 :9.4 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        bool res = true;
        if (postorder.empty())
            return res;
        res = help(postorder, 0, postorder.size() - 1);
        return res;
    }
    bool help(vector<int>& postorder, int start, int end) {
        if (postorder.empty() || start > end)
            return true;
        //根结点
        int root = postorder[end];

        //在二叉搜索树中左子树的结点小于根结点
        int i = start;
        for(;i<end;i++)
            if (postorder[i] > root)
                break;

        //在二叉搜索书中右子树的结点大于根结点
        for(int j = i;j<end;j++)
            if (postorder[j] < root)
                return false;

        //判断左子树是不是二叉搜索树
        bool left = true;
        if (i>start) left = help(postorder,start,i-1);
        //判断右子树是不是二叉搜索树
        bool right = true;
        if (i < end - 1) right = help(postorder, i,end-1);
        return left &&  right;
    }
};




// 方法二：辅助单调栈+逆向遍历数组
// 执行用时 :4 ms, 在所有 C++ 提交中击败了77.63%的用户
// 内存消耗 :9.4 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        // 单调栈使用，单调递增的单调栈
        stack<int> stack;
        int pervElem = INT_MAX;
        // 逆向遍历，就是翻转的先序遍历
        for (int i = postorder.size() - 1; i >= 0; --i){
            // 左子树元素必须要小于递增栈顶的元素，否则就不是二叉搜索树
            if (postorder[i] > pervElem){
                return false;
            }
            while (!stack.empty() && postorder[i] < stack.top()){
                // 数组元素小于单调栈的元素了，表示往左子树走了，记录下上个根节点
                // 找到这个左子树对应的根节点，之前右子树全部弹出，不再记录，因为不可能在往根节点的右子树走了
                pervElem = stack.top();
                stack.pop();
            }
            // 这个新元素入栈
            stack.push(postorder[i]);
        }
        return true;
    }
};

