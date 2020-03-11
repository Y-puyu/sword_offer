// 方法一：前缀和+双指针+巧妙解法
// 执行用时 :36 ms, 在所有 C++ 提交中击败了27.23%的用户
// 内存消耗 :25.9 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> vt(nums.size() + 1, 0);
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            cnt += nums[i];
            vt[i + 1] += cnt;
        }
        int left = 1, right = 1;
        int sum = -10000000;
        while (right <= nums.size()) {
            int tmp = vt[right] - vt[left - 1];
            if (tmp < nums[right - 1]) {
                sum = max(sum, nums[right - 1]);
                left = right;
            }
            else {
                sum = max(sum, tmp);
                right += 1;
            }
        }
        return sum;
    }
};




// 方法二：原地动规+常规解法
// 执行用时 :24 ms, 在所有 C++ 提交中击败了79.79%的用户
// 内存消耗 :25.4 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int tmp = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] > 0) nums[i] += nums[i - 1];

            tmp = max(tmp, nums[i]);
        }
        return tmp;
    }
};
