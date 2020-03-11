// 方法一：哈希映射+常规解法
// 执行用时 :20 ms, 在所有 C++ 提交中击败了99.43%的用户
// 内存消耗 :13.2 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    char firstUniqChar(string s) {
        if (s.size() == 0) return ' ';
        vector<int> vt(256, 0);
        for (int i = 0; i < s.size(); ++i) ++vt[s[i]];
        for (int i = 0; i < s.size(); ++i) {
            if (vt[s[i]] == 1) return s[i];
        }
        return ' ';
    }
};
