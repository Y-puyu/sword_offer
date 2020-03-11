// 方法一：字符串处理+常规解法
// 执行用时 :12 ms, 在所有 C++ 提交中击败了59.33%的用户
// 内存消耗 :9.7 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    string reverseWords(string s) {
        int k = 0, e = s.size() - 1;
        while (s[k] == ' ') ++k; 
        while (s[e] == ' ') --e; 
        string tmps = "", ans = "";
        for (int i = k; i <= e; ++i) {
            if (s[i] != ' ') tmps+=s[i];
            else {
                while (s[i] == ' ') ++i; 
                --i;
                ans += swapstr(tmps);
                ans+=" "; 
                tmps="";
            }
        }
        ans += swapstr(tmps);
        return swapstr(ans);
    }

    string swapstr(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) swap(s[++i], s[--j]);
        return s;
    }
};




// 方法一：思维+字符串处理+巧妙解法
// 执行用时 :4 ms, 在所有 C++ 提交中击败了96.30%的用户
// 内存消耗 :8.5 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};

