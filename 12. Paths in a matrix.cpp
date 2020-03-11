// 方法一：DFS、回溯、bool矩阵、经典仿照原书
// 执行用时 :12 ms, 在所有 C++ 提交中击败了18.23%的用户
// 内存消耗 :10.6 MB, 在所有 C++ 提交中击败了100.00%的用户

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



// 方法二：DFS、回溯、修改原数组
// 执行用时 :12 ms, 在所有 C++ 提交中击败了18.23%的用户
// 内存消耗 :10.6 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) 
            return false;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (search(board, word, 0, i, j)) 
                    return true;
            }
        }
        return false;
    }
    bool search(vector<vector<char>>& board, string word, int idx, int i, int j) {
        if (idx == word.size()) 
            return true;
        int m = board.size(), n = board[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[idx]) 
            return false;    
        char c = board[i][j];
        board[i][j] = '#';
        bool res = search(board, word, idx + 1, i - 1, j) 
                 || search(board, word, idx + 1, i + 1, j)
                 || search(board, word, idx + 1, i, j - 1)
                 || search(board, word, idx + 1, i, j + 1);
        board[i][j] = c;
        return res;
    }
};

