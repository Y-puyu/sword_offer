// 方法一：动规解法
// 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗 :8.6 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int cuttingRope(int n) {
        vector<int> vt(n + 1, 0);
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        vt[0] = 0;
        vt[1] = 1;
        vt[2] = 2;
        vt[3] = 3;
        int max = 0;
        for (int i = 4; i <= n; ++i) {
            for (int j = 1; j <= i / 2; ++j) {
                int tmp = vt[j] * vt[i - j]; 
                if (max < tmp)
                    max = tmp;
            }
            vt[i] = max;
        }

        max = vt.back();
        return max;
    }
};




// 方法二：数学、贪心、代码优化
// 执行用时 :4 ms, 在所有 C++ 提交中击败了62.46%的用户
// 内存消耗 :8.2 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int cuttingRope(int n) {
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        int tmp3 = n / 3;
        if (n - tmp3 * 3 == 1)
            tmp3 -= 1;
        int tmp2 = n - tmp3 * 3;
        long long count2 = 1, count3 = 1;
        while (tmp3) {
            count3 *= 3;
            count3 %= 1000000007;
            --tmp3;
        }
        if (tmp2 == 0)
            return count3;
        count2 = tmp2 * count3;
        if (count2 > 1000000007)
            count2 %= 1000000007;
        
        return count2;
    }
};

