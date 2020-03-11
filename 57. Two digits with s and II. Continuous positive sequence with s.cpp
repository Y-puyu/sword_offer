// 方法一：二分法+常规解法
// 执行用时 :244 ms, 在所有 C++ 提交中击败了71.63%的用户
// 内存消耗 :102.4 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    bool dichotomy(vector<int>& nums, int left, int right, int tmp) {
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] == tmp) return true;
            else if (nums[mid] < tmp) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            int tmp = target - nums[i];
            if (dichotomy(nums, i + 1, nums.size() - 1, tmp)) return {nums[i], tmp};
        }
        return {};
    }
};




// 方法二：双指针+巧妙解法
// 执行用时 :240 ms, 在所有 C++ 提交中击败了77.14%的用户
// 内存消耗 :102.5 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if (nums[left] + nums[right] > target) --right;
            else if (nums[left] + nums[right] < target) ++left;
            else return {nums[left], nums[right]};
        }
        return {};
    }
};

// 方法一：滑动窗口+巧妙解法
// 执行用时 :4 ms, 在所有 C++ 提交中击败了87.69%的用户
// 内存消耗 :8.2 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        int left = 1, right = 2;
        int mid = (1 + target) / 2, cnt = left + right;
        while (left < mid) {
            if (cnt == target) res.push_back(help(left, right));
            while (cnt > target and left < mid) {
                cnt -= left;
                ++left;
                if (cnt == target) res.push_back(help(left, right));
            }
            ++right;
            cnt += right;
        }
        return res;
    }

    vector<int> help(int left, int right) {
        vector<int> tmp;
        for (int i = left; i <= right; ++i) tmp.push_back(i);
        return tmp; 
    }
};

