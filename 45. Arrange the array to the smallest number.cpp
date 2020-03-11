// 方法一：数学+思维+lambada表达式+巧妙解法
// 执行用时 :16 ms, 在所有 C++ 提交中击败了62.48%的用户
// 内存消耗 :13.6 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    string minNumber(vector<int>& nums) {
       string res;
        sort(nums.begin(), nums.end(), [](int a, int b) {
           return to_string(a) + to_string(b) < to_string(b) + to_string(a); 
        });
        for (int i = 0; i < nums.size(); ++i) {
            res += to_string(nums[i]);
        }
        return res;
    }       
};