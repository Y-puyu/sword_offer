// 方法一：STL next_permutation()+巧妙解法
// 执行用时 :24 ms, 在所有 C++ 提交中击败了93.02%的用户
// 内存消耗 :20.1 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> vt;
        sort(s.begin(), s.end());
        vt.emplace_back(s);
        while (next_permutation(s.begin(), s.end())) 
            vt.emplace_back(s);
        return vt;
    }
};




// 方法二：递归+回溯+通用解法
// 执行用时 :212 ms, 在所有 C++ 提交中击败了22.38%的用户
// 内存消耗 :30.9 MB, 在所有 C++ 提交中击败了100.00%的用户炫耀一下:

class Solution {
public:
	vector<string> res;
	set<string> tempRes;
	vector<string> permutation(string s) {
		if (s.size() == 0) return res;  
		help(s, &s[0]);
		for (set<string>::iterator it=tempRes.begin();it!=tempRes.end();it++) 
			res.push_back(*it);
		return res;
	}
	void help(string& s, char* sBegin)
	{
		if (*sBegin == '\0') tempRes.insert(s);     // sBegin所指字符为空'\0'，将当前字符串s存储起来
		else {
			for (char* sCh = sBegin; *sCh != '\0'; sCh++) { // sBegin所指字符为空'\0'，将当前字符串s存储起来
				char temp = *sBegin;    // 交换位置
				*sBegin = *sCh;
				*sCh = temp;
                
				help(s, sBegin + 1); // 交换完后继续全排列
				
				temp = *sBegin; // 回溯
				*sBegin = *sCh;
				*sCh = temp;
			}
		}
	}
};

