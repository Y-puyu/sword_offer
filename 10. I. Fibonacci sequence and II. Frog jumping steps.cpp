// 方法一：自下而上、循环求解
// 执行用时 :8 ms, 在所有 C++ 提交中击败了61.41%的用户
// 内存消耗 :8 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int fib(int n) {
        long long  a = 0, b = 1, c = 0;
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        while (--n) {
            c = a % 1000000007 + b % 1000000007;
            a = b;
            b = c;
        } 
        return c % 1000000007;
    }
};




// 青蛙跳台阶、经典递归
// 执行用时 :4 ms, 在所有 C++ 提交中击败了61.72%的用户
// 内存消耗 :8.2 MB, 在所有 C++ 提交中击败了100.00%的用户
class Solution {
public:
    int numWays(int n) {
        long long arr[2] = {1, 1};
        if (n < 2)
            return arr[n];
        long long  a = 1, b = 1, c = 0;
        while (--n) {
            c = a % 1000000007 + b % 1000000007;
            a = b;
            b = c;
        } 
        return c % 1000000007;
    }
};


