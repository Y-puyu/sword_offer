// 方法一：快排思想+O(n)O(n)O(n)时间复杂度算法+巧妙解法
// 执行用时 :32 ms, 在所有 C++ 提交中击败了86.92%的用户
// 内存消耗 :21.2 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
	int getMidIndex(vector<int> &array, int start, int end) {
		int mid = start + ((end - start) >> 1);
		int a = array[start];
		int b = array[mid];
		int c = array[end];
		if ((a >= b && a <= c) || (a <= b && a >= c)) return start;
		if ((b >= a && b <= c) || (b <= a && b >= c)) return mid;
		if ((c >= a && c <= b) || (c <= a && c >= b)) return end;
		return -1;
	}

	int partition(vector<int> &array, int start, int end) {
		int midIndex = getMidIndex(array, start, end);
		int temp = array[midIndex];
		array[midIndex] = array[end];
		array[end] = temp;
		temp = array[end];
		while (start < end) {
			while (start < end && array[start] < temp) start++;
			if (start < end) {
				array[end] = array[start];
				end--;
			}
			while (start < end && array[end] >= temp) end--;
			if (start < end) {
				array[start] = array[end];
				start++;
			}
		}
		array[start] = temp;
		return start;
	}

	vector<int> getLeastNumbers(vector<int>& nums, int k) {
		if (k == 0) return {};
		int start = 0;
		int end = (int)nums.size() - 1;
		int position = partition(nums, start, end);
		int index = k - 1;
		while (index != position) {
			if (index > position) start = position + 1;
			else end = position - 1;

			position = partition(nums, start, end);
	    }
		vector<int>rs(position + 1);
		for (int i = 0; i <= position; i++) rs[i] = nums[i];
		return rs;
	}
};




// 方法二：O(logn)O(logn)O(logn)时间复杂度+海量数据+巧妙解法
// 执行用时 :56 ms, 在所有 C++ 提交中击败了40.30%的用户
// 内存消耗 :26.9 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> vt;
        multiset<int, greater<int>> s;
        multiset<int, greater<int>>::iterator sit;
        vector<int>::iterator vit = arr.begin();
        for (; vit != arr.end(); ++vit) {
            if (s.size() < k) s.insert(*vit);
            else {
                sit = s.begin();
                if (*vit < *(s.begin())) {
                    s.erase(sit);
                    s.insert(*vit);
                }
            }   
        }
        for (auto it = s.begin(); it != s.end(); ++it) vt.emplace_back(*it);
        return vt;
    }
};

