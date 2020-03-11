// 方法一：多数投票算法+O(n)O(n)O(n)时间复杂度+最优解法
// 执行用时 :20 ms, 在所有 C++ 提交中击败了82.68%的用户
// 内存消耗 :21.7 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int majorityElement(vector<int> numbers) {
        int num = 0, count = 0;
        for (int i = 0; i < numbers.size(); i++) {
            if (count == 0) num = numbers[i];
            if (numbers[i] == num) count++;
            else count--;
        }
        return num;
    }
};


// 执行用时 :20 ms, 在所有 C++ 提交中击败了82.68%的用户
// 内存消耗 :21.8 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int majorityElement(vector<int> numbers) {
        int n = numbers.size();
        if (n == 0) 
            return 0;
        int num = numbers[0], count = 1;
        for (int i = 1; i < n; i++) {
            if (numbers[i] == num) 
                count++;
            else 
                count--;
            if (count == 0) {
                num = numbers[i];
                count = 1;
            }
        }
        // 经过上面的操作, 已经找到该数 num 了. 
        // 下面的操作是为了确认 num 确实是出现次数超过一半. 
        count = 0;
        for (int i = 0; i < n; i++) {
            if (numbers[i] == num) 
                count++;
        }
        if (count * 2 > n) 
            return num;
        return 0;
    }
};





// 方法二：sort()排序+O(logn)O(logn)O(logn)时间复杂度+投机解法
// 执行用时 :24 ms, 在所有 C++ 提交中击败了62.85%的用户
// 内存消耗 :21.3 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() >> 1];
    }
};
