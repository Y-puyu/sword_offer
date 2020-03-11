// 方法一：递归+剪枝+常规解法
// 控制台单过11都过不了

class Solution {
public:
    vector<double> twoSum(int n) {
        int size = 6 * n;
        vector<double> v;
        vector<int> vt(size - n + 1, 0);
        help(n, vt);
        int total = pow(6, n);
        for (int i = n; i <= size; ++i) {
            double res = (double)vt[i - n] / total;
            v.push_back(res);
        }
        return v;
    }

    void help(int n, vector<int>& vt) {
        for (int i = 1; i <= 6; ++i) help(n, n, i, vt);
    }

    void help(int num, int tmp, int sum, vector<int>& vt) {
        if (tmp == 1) vt[sum - num]++;
        else {
            for (int i = 1; i <= 6; ++i)
                help(num, tmp - 1, i + sum, vt);
        }
    }
};

// 控制台能过11，总时间超TLE
class Solution {
public:
    vector<double> twoSum(int n) {
        if (n == 1) return {0.16667,0.16667,0.16667,0.16667,0.16667,0.16667};
        int size = 6 * n;
        vector<double> v;
        vector<int> vt(size - n + 1, 0);
        help(n, vt);
        int total = pow(6, n);
        for (int i = n; i < size / 2 + 6; ++i) {
            double res = (double)vt[i - n] / total;
            v.push_back(res);
        }
        for (int i = size / 2 - 6; i >= 0; --i) v.push_back(v[i]);
        return v;
    }

    void help(int n, vector<int>& vt) {
        for (int i = 1; i <= 6; ++i) help(n, n, i, vt);
    }

    void help(int num, int tmp, int sum, vector<int>& vt) {
        if (tmp == 1) vt[sum - num]++;
        else {
            for (int i = 1; i <= 6; ++i)
                help(num, tmp - 1, i + sum, vt);
        }
    }
};




// 方法二：动态规划+迭代+巧妙解法
// 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗 :8 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
	vector<double> twoSum(int n) {
		vector<vector<int>> dp(n + 1, vector<int>(6 * n + 1, 0));
		double num = pow(6, n);
		vector<double> res(5 * n + 1, 1 / (double)6);
		//初始状态
		for (int i = 1; i <= 6; i++) dp[1][i] = 1;
         //从2到n计算dp
		for (int i = 2; i <= n; i++) {     
            //表示当n=i时候的点数和取值从i到6i
			for (int j = i; j <= i * 6; j++) {  
                //dp[i][j]=dp[i-1][j-1]+dp[i-1][j-2]+dp[i-1][j-3]+dp[i-1][j-4]+dp[i-1][j-5]+dp[i-1][j-6];
				for (int k = 1; k <= 6; k++) {  
                    //第i个骰子点数一定比i-1个骰子点数大
					if (j - k > 0) dp[i][j] += dp[i - 1][j - k]; 
					if (i == n) res[j - i] = dp[i][j] / num;
				}
			}
		}
		return res;
	}
};

