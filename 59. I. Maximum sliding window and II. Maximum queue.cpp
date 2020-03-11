// 方法一：模拟+单调队列+常规解法
// 执行用时 :12 ms, 在所有 C++ 提交中击败了99.62%的用户
// 内存消耗 :17.6 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() < k or k <= 0) return {};
        vector<int> vt;
        deque<int> dq;
        for (int i = 0; i < k; ++i) {
            while (!dq.empty() and nums[i] >= nums[dq.back()]) dq.pop_back();
            dq.push_back(i);
        }
        for (int i = k; i < nums.size(); ++i) {
            vt.push_back(nums[dq.front()]);
            while (!dq.empty() and nums[i] >= nums[dq.back()]) dq.pop_back();
            if (!dq.empty() and dq.front() <= i - k) dq.pop_front();
            dq.push_back(i);
        }
        vt.push_back(nums[dq.front()]);
        return vt;
    }
};




// 方法一：模拟+单调队列+常规解法
// 执行用时 :180 ms, 在所有 C++ 提交中击败了36.69%的用户
// 内存消耗 :50.3 MB, 在所有 C++ 提交中击败了100.00%的用户

class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        return que.empty() ? -1 : dq.front();
    }
    
    void push_back(int value) {
        que.push(value);
        while (!dq.empty() and dq.back() < value) dq.pop_back();
        dq.push_back(value);
    }
    
    int pop_front() {
        if(que.empty()) return -1;
        int t = que.front();
        que.pop();
        if(t == dq.front()) dq.pop_front();
        return t;
    }
private:
    queue<int> que;
    deque<int> dq;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

