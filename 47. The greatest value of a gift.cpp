// 方法一：动态规划+常规解法
// 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗 :12.1 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (j == 0) {
                    if (i == 0) dp[i][j] = grid[i][j];
                    else dp[i][j] = dp[i - 1][j] + grid[i][j];
                }
                else {
                    if (i == 0) dp[i][j] = dp[i][j - 1] + grid[i][j];
                    else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                }
            }
        }
        return dp.back().back();
    }
};
