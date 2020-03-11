// 方法一：滑动窗口+HashMap+常规解法
// 执行用时 :40 ms, 在所有 C++ 提交中击败了28.37%的用户
// 内存消耗 :11.1 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        int res = 0, left = -1;
        unordered_map<int, int> m;
        for (int i = 0; i < s.size(); ++i) {
            if (m.count(s[i]) and m[s[i]] > left) left = m[s[i]];
            
            m[s[i]] = i;
            res = max(res, i - left);
        }
        return res;
    }
};




// 方法二：滑动窗口+vector映射数组+常规解法
// 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗 :10.1 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(128, -1);
        int res = 0, left = -1;
        for (int i = 0; i < s.size(); ++i) {
            left = max(left, m[s[i]]);
            m[s[i]] = i;
            res = max(res, i - left);
        }
        return res;
    }
};

// 方法三：滑动窗口+HashSet+常规解法
// 执行用时 :32 ms, 在所有 C++ 提交中击败了41.72%的用户
// 内存消耗 :13.6 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, left = 0, i = 0, n = s.size();
        unordered_set<char> t;
        while (i < n) {
            if (!t.count(s[i])) {
                t.insert(s[i++]);
                res = max(res, (int)t.size());
            }  
            else {
                t.erase(s[left++]);
            }
        }
        return res;
    }
};

