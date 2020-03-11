// 方法一：思维+模拟+顶级解法
// 执行用时 :20 ms, 在所有 C++ 提交中击败了93.40%的用户
// 内存消耗 :26.1 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int>  vt(n);
        int tmp = 1;
        for(int i = 0; i < a.size(); ++i) {
            vt[i] = tmp;
            tmp *= a[i];
        }
        tmp = 1;
        for(int i = n-1; i >= 0; --i) {
            vt[i] *= tmp;
            tmp *= a[i];
        }
        return vt;
    }
};

