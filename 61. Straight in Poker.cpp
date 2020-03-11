// 方法一：模拟+常规解法
// 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗 :11.7 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 0; 
        for (int i = 0; i < nums.size(); ++i) 
            if (nums[i] == 0) ++cnt;
        int left = cnt, right = left + 1, tmp = 0;
        while (right < nums.size()) {
            if (nums[left] == nums[right]) return false;
            tmp += nums[right] - nums[left] - 1;
            left++;
            right++;
        }
        return (tmp > cnt) ? false : true;

    }
};

