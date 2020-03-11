// 方法一：暴搜
// 执行用时 :28 ms, 在所有 C++ 提交中击败了96.72%的用户
// 内存消耗 :12.2 MB, 在所有 C++ 提交中击败了100.00%的用户
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) 
            return false;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == target)
                    return true;
            }
        }
        return false;
    }
};



// 数学规律法
// 执行用时 :52 ms, 在所有 C++ 提交中击败了18.44%的用户
// 内存消耗 :12.2 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) 
            return false;
        if (target < matrix[0][0] || target > matrix.back().back()) 
            return false;
        int x = matrix.size() - 1, y = 0;
        while (true) {
            if (matrix[x][y] > target) 
                --x;
            else if (matrix[x][y] < target) 
                ++y;
            else 
                return true;
            if (x < 0 || y >= matrix[0].size()) 
                break;
        }
        return false;
    }
};	
