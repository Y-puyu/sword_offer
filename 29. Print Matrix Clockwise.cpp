// 方法一：边界情况+循环结束判断+常规解法
// 执行用时 :12 ms, 在所有 C++ 提交中击败了82.41%的用户
// 内存消耗 :12.5 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> vt;
        if (matrix.size() == 0 || matrix[0].size() == 0) return vt;
        int row = matrix.size(), col = matrix[0].size(), start = 0; 

        while (col > start * 2 && row > start * 2) {
            int endX = col - 1 - start;
            int endY = row - 1 - start;

            // 从左到右打印一行
            for (int i = start; i <= endX; ++i) 
                vt.push_back(matrix[start][i]);
            // 从上到下打印一列
            if (start < endY) {
                for (int i = start + 1; i <= endY; ++i)
                    vt.push_back(matrix[i][endX]);
            }
            // 从右到左打印一行
            if (start < endX && start < endY) {
                for (int i = endX - 1; i >= start; --i)
                    vt.push_back(matrix[endY][i]);
            }
            // 从下到上打印一行
            if (start < endX && start < endY - 1)
                for (int i = endY - 1; i >= start + 1; --i)
                    vt.push_back(matrix[i][start]);
            ++start;
        }
        return vt;
    }
};




// 方法二：下标转化法
// 执行用时 :8 ms, 在所有 C++ 提交中击败了97.04%的用户
// 内存消耗 :12.5 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        int c = m > n ? (n + 1) / 2 : (m + 1) / 2;
        int p = m, q = n;
        for (int i = 0; i < c; ++i, p -= 2, q -= 2) {
            for (int col = i; col < i + q; ++col) 
                res.push_back(matrix[i][col]);
            for (int row = i + 1; row < i + p; ++row)
                res.push_back(matrix[row][i + q - 1]);
            if (p == 1 || q == 1) break;
            for (int col = i + q - 2; col >= i; --col)
                res.push_back(matrix[i + p - 1][col]);
            for (int row = i + p - 2; row > i; --row) 
                res.push_back(matrix[row][i]);
        }
        return res;
    }
};

// 方法三：迷宫遍历法
// 执行用时 :16 ms, 在所有 C++ 提交中击败了47.43%的用户
// 内存消耗 :12.5 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size(), n = matrix[0].size(), idx = 0, i = 0, j = 0;
        vector<int> res;
        vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int k = 0; k < m * n; ++k) {
            res.push_back(matrix[i][j]);
            matrix[i][j] = -10000;
            int x = i + dirs[idx][0], y = j + dirs[idx][1];
            if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] == -10000) {
                idx = (idx + 1) % 4;
                x = i + dirs[idx][0];
                y = j + dirs[idx][1];
            }
            i = x;
            j = y;
        }
        return res;
    }
};

