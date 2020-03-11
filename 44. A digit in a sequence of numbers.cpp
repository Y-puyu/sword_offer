// 方法一：数学+思维+巧妙解法
// 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗 :8.3 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int findNthDigit(int n) {
        long long len = 1, cnt = 9, start = 1;
        while (n > len * cnt) {
            n -= len * cnt;
            ++len;
            cnt *= 10;
            start *= 10;
        }
        start += (n - 1) / len;
        string t = to_string(start);
        return t[(n - 1) % len] - '0';
    }
};
