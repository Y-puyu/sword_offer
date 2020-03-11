// 方法一：模拟+辅助栈，常规解法
// 执行用时 :4 ms, 在所有 C++ 提交中击败了98.55%的用户
// 内存消耗 :17.6 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() != popped.size()) return false;
        if (pushed.size() == 0 && popped.size() == 0) return true;
        stack<int> s1, s2;
        for (int i = popped.size() - 1; i >= 0; --i) 
            s2.push(popped[i]);
        for (int i = 0; i < pushed.size(); ++i) {
            s1.push(pushed[i]);
            while (s2.top() == s1.top()) { 
                s1.pop();
                s2.pop();
                if (s1.empty()) break;
            }
        }
        return s1.empty();
    }
};


