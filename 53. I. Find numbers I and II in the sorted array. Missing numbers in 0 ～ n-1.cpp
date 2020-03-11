// 方法一：遍历+常规解法
// 执行用时 :4 ms, 在所有 C++ 提交中击败了98.65%的用户
// 内存消耗 :15.8 MB,在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return 0;
        int tmp = 0;
        for (int i = 0; i <nums.size(); ++i) {
            while (i < nums.size() and nums[i] == target) {
                ++tmp;
                ++i;
            }
        }
        return tmp;;
    }
};



// 方法二：二分法+递归+巧妙解法
// 执行用时 :16 ms, 在所有 C++ 提交中击败了22.43%的用户
// 内存消耗 :23.7 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = getLeft(nums, target, 0, nums.size() - 1);
        int right = getRight(nums, target, 0, nums.size() - 1);
        if (left > -1 and right > -1) return right - left + 1;
        return 0; 
    }

    int getLeft(vector<int> nums, int target, int left, int right) {
        if (left > right) return -1;
        int mid = (left + right) >> 1;
        if (nums[mid] == target) {
            if ((mid > 0 and nums[mid - 1] != target) or mid == 0) return mid;
            else right = mid - 1;
        }
        else if (nums[mid] > target) right = mid - 1;
        else left = mid + 1;

        return getLeft(nums, target, left, right);
    }

    int getRight(vector<int> nums, int target, int left, int right) {
        if (left > right) return -1;
        int mid = (left + right) >> 1;
        if (nums[mid] == target) {
            if ((mid < nums.size() - 1 and nums[mid + 1] != target) or mid == nums.size() - 1) return mid;
            else left = mid + 1;
        }
        else if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;

        return getRight(nums, target, left, right);
    }
};

// 方法一：遍历+常规解法
// 执行用时 :24 ms, 在所有 C++ 提交中击败了58.30%的用户
// 内存消耗 :19.5 MB, 在所有 C++ 提交中击败了100.00%的用户
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (i != nums[i]) 
                return i;
        }
        return nums.back() + 1;
    }

};

// 方法二：二分法+巧妙解法
// 执行用时 :20 ms, 在所有 C++ 提交中击败了82.48%的用户
// 内存消耗 :19.5 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = (left + right) >> 1;
            if (mid == nums[mid]) left = mid + 1; 
            else right = mid;
        }
        return left;
    }
};

