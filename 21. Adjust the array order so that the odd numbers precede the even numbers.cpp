// 方法一：双指针+位运算解法
// 执行用时 :24 ms, 在所有 C++ 提交中击败了76.91%的用户
// 内存消耗 :20.6 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            while (((nums[left] & 1) != 0) and left < right) ++left;
            while (((nums[right] & 1) == 0) and left < right) --right;
            swap(nums[left], nums[right]); 
        }
        return nums;
    }
};