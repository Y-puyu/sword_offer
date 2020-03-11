// 方法一：双栈模拟法
// 执行用时 :564 ms, 在所有 C++ 提交中击败了23.52%的用户
// 内存消耗 :106.1 MB, 在所有 C++ 提交中击败了100.00%的用户

class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        int tmp = 0;
        if (s2.empty() && s1.empty())
            return -1;
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        tmp = s2.top();
        s2.pop();
        return tmp;
    }
private:
    stack<int> s1;
    stack<int> s2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

