// 方法一：DFS、回溯、bool矩阵
// 执行用时 :464 ms, 在所有 C++ 提交中击败了7.01%的用户
// 内存消耗 :158.5 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int movingCount(int m, int n, int k) {
        int tmp = m * n;
        vector<bool> visited(tmp, false);
        int count = movingCountCore(m, n, k, 0, 0, visited);
        return count;
    }

    int movingCountCore(int m, int n, int k, int row, int col, vector<bool>& visited) {
        int count = 0;
        if (check(m, n, k, row, col, visited)) {
            visited[row * n + col] = true;
            count = 1 + movingCountCore(m, n, k, row - 1, col, visited) 
                      + movingCountCore(m, n, k, row, col - 1, visited) 
                      + movingCountCore(m, n, k, row + 1, col, visited)
                      + movingCountCore(m, n, k, row, col + 1, visited);
        }
        return count;
    }

    bool check(int m, int n, int k, int row, int col, vector<bool>& visited) {
        if (row >= 0 && row < m && col >= 0 && col < n 
            && getDigitSum(row) + getDigitSum(col) <= k 
            && !visited[row * n + col])
            return true;
        return false;
    }

    int getDigitSum(int number) {
        int sum = 0;
        while (number > 0) {
            sum += number % 10;
            number /= 10;
        }
        return sum;
    }
};



// 方法二：DFS、回溯、代码优化
// 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗 :9.6 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int nums = 0;
    int movingCount(int m, int n, int k) {
        vector<vector <int> > arr(m, vector<int>(n, 0));
        if(k == 0)
            return 1;
        dfs(m, n, k, arr, 0, 0);
        return nums;
    }
    void dfs(int m, int n, int k, vector<vector <int> >& arr, int i, int j){
        if(i >= m || j >= n || i < 0 || j < 0)
            return;
        if(arr[i][j] == 1)
            return;
        if((i % 10 + i / 10 + j % 10 + j / 10) > k)
            return;
        arr[i][j] = 1;
        nums++;
        dfs(m, n, k, arr, i - 1, j);
        dfs(m, n, k, arr, i + 1, j);
        dfs(m, n, k, arr, i, j - 1);
        dfs(m, n, k, arr, i, j + 1);
    }
};

// 方法三：DFS性质、回溯、递归、代码优化
// 执行用时 :4 ms, 在所有 C++ 提交中击败了91.38%的用户
// 内存消耗 :9.3 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int nums = 0;
    int movingCount(int m, int n, int k) {
        vector<vector <int> > arr(m, vector<int>(n, 0));
        if(k == 0)
            return 1;
        dfs(m, n, k, arr, 0, 0);
        return nums;
    }
    void dfs(int m, int n, int k, vector<vector <int> >& arr, int i, int j){
        if(i >= m || j >= n || i < 0 || j < 0)
            return;
        if(arr[i][j] == 1)
            return;
        if((i % 10 + i / 10 + j % 10 + j / 10) > k)
            return;
        arr[i][j] = 1;
        nums++;
        dfs(m, n, k, arr, i + 1, j);
        dfs(m, n, k, arr, i, j + 1);
    }
};


