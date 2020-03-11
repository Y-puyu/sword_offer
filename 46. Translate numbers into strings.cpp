// 方法一：思维+递归+巧妙解法
// 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗 :8.3 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int translateNum(int num) {
        string tmp = to_string(num);
        vector<int> counts(tmp.size(), 0);
        int count = 0;
        for (int i = tmp.size() - 1; i >= 0; --i) {
            count = 0;
            if (i < tmp.size() - 1) count = counts[i + 1];
            else count = 1;

            if (i < tmp.size() - 1) {
                int cnt = (tmp[i] - '0') * 10 + tmp[i + 1] - '0';
                if (cnt >= 10 and cnt <= 25) {
                    if (i < tmp.size() - 2) count += counts[i + 2];
                    else count += 1;
                }
            }
            counts[i] = count;
        }
        return counts[0];

    }
};
