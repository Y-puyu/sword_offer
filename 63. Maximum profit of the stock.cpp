// 方法一：数学+思维+动态规划+顶级解法
// 执行用时 :20 ms, 在所有 C++ 提交中击败了20.77%的用户
// 内存消耗 :15.6 MB, 在所有 C++ 提交中击败了5.09%的用户

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        vector<int> vt(prices.size() - 1);
        for (int i = 0; i < prices.size() - 1; ++i) 
            vt[i] = prices[i + 1] - prices[i];
        
        vector<int> dp(vt.size());
        dp[0] = max(0, vt[0]);
        int max= dp[0];
        for (int i = 1; i < vt.size(); ++i) {
            dp[i] = max(0, dp[i - 1] + vt[i]);
            max= max(max, dp[i]);
        }
        return max;
    }
};




// 方法二：动态规划+巧妙解法
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0; // 边界条件
        int minprice = prices[0];
        vector<int> dp (n, 0);

        for (int i = 1; i < n; ++i){
            minprice = min(minprice, prices[i]);
            dp[i] = max(dp[i - 1], prices[i] - minprice);
        }
        return dp[n - 1];
    }
};

// 方法三：暴力+常规解法
// 执行用时 :1820 ms, 在所有 C++ 提交中击败了20.77%的用户
// 内存消耗 :14.1 MB, 在所有 C++ 提交中击败了5.09%的用户
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int)prices.size(), ans = 0;
        for (int i = 0; i < n; ++i){
            for (int j = i + 1; j < n; ++j){
                ans = max(ans, prices[j] - prices[i]);
            }
        }
        return ans;
    }
};
