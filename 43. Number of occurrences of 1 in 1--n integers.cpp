// 方法一：数学+思维+巧妙解法
// 执行用时 :4 ms, 在所有 C++ 提交中击败了66.26%的用户
// 内存消耗 :8.2 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int countDigitOne(int n) {
        long long res = 0, a = 1, b = 1;
        while (n > 0) {
            res += (n + 8) / 10 * a + (n % 10 == 1) * b;
            b += n % 10 * a;
            a *= 10;
            n /= 10;
        }
        return res;
    }
};




// 方法二：大数+递归+巧妙解法
// 执行用时 :4 ms, 在所有 C++ 提交中击败了66.26%的用户
// 内存消耗 :8.4 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int countDigitOne(int n) {
        if(n <= 0) return 0;
        if(n < 10) return 1;
        string s = to_string(n);
        int highNum = s[0] - '0';
        int size = s.size();
        int withoutHigh = n - highNum * pow(10,size - 1);
    // 1. 统计首位为1出现次数:
    //    - 若n首位是1(如12345), 那么有 2346个
    //    - 若n的首位U不是1(如23456), 那么有 10000个
        int first = highNum == 1 ? withoutHigh + 1 :pow(10,size - 1);
    // 统计其他位为1的出现次数
    // 2. 大于 3456
    //    - 可以划分为两个区间，例如对 23456 划分为
    //      [10000, 19999], [3457, 9999]U[20001, 23456]
    //    - 对任意一个区间，后面4个数字，选择其中一个为1，其他三个都可以在0~9中任意选择，因此一共有 2*4*10^3 个1 
    int other = highNum * (size - 1) * pow(10, size - 2);
    return first + other + countDigitOne(withoutHigh);
    }
};

