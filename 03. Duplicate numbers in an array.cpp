// 方法一：排序法
// 执行用时 :80 ms, 在所有 C++ 提交中击败了28.37%的用户
// 内存消耗 :14.3 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] == nums[i]) {
                cnt = nums[i];
                return cnt;
            }
        }
        return -1;
    }
};

// 方法二：数组哈希
// 执行用时 :72 ms, 在所有 C++ 提交中击败了34.62%的用户
// 内存消耗 :14.4 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int arr[100000] = {0};
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            ++arr[nums[i]];
            if (arr[nums[i]] > 1) {
                cnt = nums[i];
                return nums[i]
            }
        }
        return -1;
    }
};

// map哈希映射
// 执行用时 :144 ms, 在所有 C++ 提交中击败了5.77%的用户
// 内存消耗 :28.9 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        map<int, int> m;
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            ++m[nums[i]];
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second > 1)
                cnt = it->first;
        }
        return cnt;
    }
};


// 抽屉原理、空间复杂度O(1)O(1)O(1)
// 执行用时 :52 ms, 在所有 C++ 提交中击败了65.87%的用户
// 内存消耗 :14 MB, 在所有 C++ 提交中击败了100.00%的用户

int cnt = 0;
class Solution {
public:
    int find(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == i)
                continue;
            if (nums[i] != nums[nums[i]])
                swap(nums[i], nums[nums[i]]);
            else {
                cnt = nums[i];
                return cnt;
            }
        }
        return -1;
    }

    int findRepeatNumber(vector<int>& nums) {
        return find(nums);
    }
};