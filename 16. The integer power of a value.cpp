// 方法一：快速幂
// 执行用时 :8 ms, 在所有 C++ 提交中击败了9.43%的用户
// 内存消耗 :8.3 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    double myPow(double x, int n) {
        long q = n;
        if (n < 0) {
            x = 1.0 / x;
            q = -q;
        }
        double res = 1;
        while(q) {
            if (q & 1)  // 位运算只能用于整形
                res *= x;
            x *= x;
            q >>= 1;
        }
        return res;
    }
};




// 方法二：5行高效递归
// 执行用时 :4 ms, 在所有 C++ 提交中击败了69.36%的用户
// 内存消耗 :8.3 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        double half = myPow(x, n / 2);
        if (n % 2 == 0) return half * half;
        if (n > 0) return half * half * x;
        return half * half / x;
    }
};


// 方法三：迭代法
// 执行用时 :8 ms, 在所有 C++ 提交中击败了9.43%的用户
// 内存消耗 :8.3 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        for (int i = n; i != 0; i /= 2) {
            if (i % 2 != 0) res *= x;
            x *= x;
        }
        return n < 0 ? 1 / res : res;
    }
};

