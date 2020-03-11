// 方法一：位运算+异或+顶级解法
// 执行用时 :32 ms, 在所有 C++ 提交中击败了42.14%的用户
// 内存消耗 :17.7 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int tmp = 0;
        for (int i = 0; i < nums.size(); ++i) {
            tmp ^= nums[i];
        }
        int index = 0;
        while (((tmp & 1) == 0) and (index < 8 * sizeof(int))) {
            tmp = tmp >> 1;
            ++index;
        }
        int a = 0, b = 0;
        for (int j = 0; j < nums.size(); ++j) {
            if ((nums[j] >> index) & 1) a ^= nums[j];
            else b ^= nums[j];
        }
        return {a, b};
    }
};



// 方法一：位运算+顶级解法
// 执行用时 :60 ms, 在所有 C++ 提交中击败了52.03%的用户
// 内存消耗 :17.9 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> vt(32, 0);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < 32; ++j){
                vt[j] += nums[i] & 1;
                nums[i] >>= 1;
            }
        }
        int res = 0;
        for (int i = 0; i < 32; ++i){
            if (vt[i] % 3 == 1) res += 1 << i;
        }
        return res;
    }
};

