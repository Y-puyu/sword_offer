// 方法一：TLE+暴力+常规解法
// TLE
// 35 / 139 个通过测试用例

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int cnt = 0, tmp = 0;;
        for (int i = 0; i < nums.size(); ++i) {
            tmp = nums[i];
            for (int j = i; j < nums.size(); ++j) {
                if (tmp > nums[j]) ++cnt;
            }
        }
        return cnt;    
    }
};




// 方法二：思维+归并排序+巧妙解法
// 执行用时 :144 ms, 在所有 C++ 提交中击败了94.34%的用户
// 内存消耗 :47.3 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> vt(nums);
        int cnt = help(nums, vt, 0, nums.size() - 1);
        return cnt;
    }

    int help(vector<int>& nums, vector<int>& vt, int left, int right) {
        if (left == right) {
            vt[left] = nums[left];
            return 0;
        }
        int len = (right - left) / 2;
        int start = help(vt, nums, left, left + len);
        int end = help(vt, nums, left + len + 1, right);
        int i = left + len;
        int j = right;
        int index_vt = right;
        int cnt = 0;
        while (i >= left and j >= left + len + 1) {
            if (nums[i] > nums[j]) {
                vt[index_vt--] = nums[i--];
                cnt += j - left - len;
            } 
            else {
                vt[index_vt--] = nums[j--];
            }
        }
        for (; i >= left; --i) vt[index_vt--] = nums[i];
        for (; j >= left + len + 1; --j) vt[index_vt--] = nums[j];

        return start + end + cnt;
    }
};

