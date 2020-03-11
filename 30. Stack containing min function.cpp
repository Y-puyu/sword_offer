// 方法一：模拟+辅助栈，常规解法
// 执行用时 :28 ms, 在所有 C++ 提交中击败了75.09%的用户
// 内存消耗 :17.7 MB, 在所有 C++ 提交中击败了100.00%的用户

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if (s1.empty()) {
            s1.push(x);
            s2.push(x);
        }
        else 
            s1.push(x);
        if (s1.top() >= s2.top()) 
            s2.push(s2.top());
        else    
            s2.push(s1.top());
    }
    
    void pop() {
        s1.pop();
        s2.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int min() {
        return s2.top();
    }
private:
    stack<int> s1;
    stack<int> s2;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */



// 方法二：一个栈+整形变量，巧妙解法
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        min_val = INT_MAX;
    }  
    void push(int x) {
        if (x <= min_val) {
            st.push(min_val);
            min_val = x;
        }
        st.push(x);
    }   
    void pop() {
        int t = st.top(); st.pop();
        if (t == min_val) {
            min_val = st.top(); st.pop();
        }
    }  
    int top() {
        return st.top();
    }    
    int min() {
        return min_val;
    }
private:
    int min_val;
    stack<int> st;
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */

