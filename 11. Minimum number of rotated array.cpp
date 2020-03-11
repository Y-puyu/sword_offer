// 方法一：二分法
// 执行用时 :4 ms, 在所有 C++ 提交中击败了96.03%的用户
// 内存消耗 :14.5 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (numbers[mid] > numbers[right]) 
                left = mid + 1;
            else if (numbers[mid] < numbers[right]) 
                right = mid;
            else 
                --right;
        }
        return numbers[right];
    }
};




// 方法二：分治法、递归
// 执行用时 :4 ms, 在所有 C++ 提交中击败了96.03%的用户
// 内存消耗 :14.6 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int minArray(vector<int>& numbers) {
        return helper(numbers, 0, numbers.size() - 1);
    }
    int helper(vector<int>& nums, int start, int end) {
        if (start == end) 
            return nums[start];
        if (nums[start] < nums[end]) 
            return nums[start];
        int mid = (start + end) / 2;
        return min(helper(nums, start, mid), helper(nums, mid + 1, end));
    }
};

