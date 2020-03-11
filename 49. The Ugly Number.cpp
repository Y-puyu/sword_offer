// 方法一：TLE+常规解法
// TLE
// 500 / 596 个通过测试用例
// 最后执行的输入：1352

class Solution {
public:
    int nthUglyNumber(int n) {
        long long cnt = 0, tmp = 0;
        while (cnt < n) {
            ++tmp;
            if (judge(tmp)) {
                ++cnt;
            }
            
        }
        return tmp;
    }

    bool judge(int n) {
        while (n % 2 == 0) n /= 2;
        while (n % 3 == 0) n /= 3;
        while (n % 5 == 0) n /= 5;

        if (n == 1) return true;

        return false;
    }
};




// 方法二：思维+巧妙解法
// 执行用时 :16 ms, 在所有 C++ 提交中击败了33.51%的用户
// 内存消耗 :12 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(1, 1);
        int i2 = 0, i3 = 0, i5 = 0;
        while (res.size() < n) {
            int m2 = res[i2] * 2, m3 = res[i3] * 3, m5 = res[i5] * 5;
            int mn = min(m2, min(m3, m5));
            if (mn == m2) ++i2;
            if (mn == m3) ++i3;
            if (mn == m5) ++i5;
            res.push_back(mn);
        }
        return res.back();
    }
};


// 方法三：思维+堆+巧妙解法
// 执行用时 :236 ms, 在所有 C++ 提交中击败了5.11%的用户
// 内存消耗 :13.1 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> pq;
        pq.push(1);
        for (long i = 1; i < n; ++i) {
            long t = pq.top(); pq.pop();
            while (!pq.empty() && pq.top() == t) {
                t = pq.top(); pq.pop();
            }
            pq.push(t * 2);
            pq.push(t * 3);
            pq.push(t * 5);
        }
        return pq.top();
    }
};

