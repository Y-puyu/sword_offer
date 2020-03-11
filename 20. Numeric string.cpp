// 方法一：各种情况分类分析+优化
// 执行用时 :8 ms, 在所有 C++ 提交中击败了50.94%的用户
// 内存消耗 :8.4 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    bool isNumber(string s) {
        bool num = false, numAfterE = true, dot = false, exp = false, sign = false;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') {
                if (i < n - 1 && s[i + 1] != ' ' && (num || dot || exp || sign)) return false;
            } else if (s[i] == '+' || s[i] == '-') {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != ' ') return false;
                sign = true;
            } else if (s[i] >= '0' && s[i] <= '9') {
                num = true;
                numAfterE = true;
            } else if (s[i] == '.') {
                if (dot || exp) return false;
                dot = true;
            } else if (s[i] == 'e') {
                if (exp || !num) return false;
                exp = true;
                numAfterE = false;
            } else return false;
        }
        return num && numAfterE;
    }
};




// 方法二：普通思考方式
// 执行用时 :12 ms, 在所有 C++ 提交中击败了15.09%的用户
// 内存消耗 :8.5 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
	bool isNumber(string s) {
		// 移除首尾空格
		int start = 0, end = s.size() - 1;
		while (start < s.size() && s[start] == ' ')    start++;
		while (end >= 0 && s[end] == ' ')   end--;
		s = s.substr(start, end - start + 1);

		int e = 0, dot = 0;                         // 统计e 和 . 的出现次数
		for (char c : s) {
			if (c == 'e')   e++;
			else if (c == '.')  dot++;
			else if (c == '+' || c == '-');
			else if (c >= '0' && c <= '9');
			else return false;                      // 除了+-e.0123456789以外都非法 包括空白
		}
		if (e > 1 || dot > 1)   return false;       // e 和 . 只能最多出現一次

		e = s.find("e");
		if (e != -1) {
			string exp = s.substr(e + 1);           // 分离出指数部分
			if (exp.find(".") != -1)    return false;      // 指数有個不同規則是只能是整數
			if (!commonCheck(exp))  return false;
			s = s.substr(0, e);
		}
		if (!commonCheck(s))    return false;

		return true;
	}
	bool commonCheck(string s) {
		if (!s.empty() && (s[0] == '+' || s[0] == '-'))   s.erase(s.begin());  // 如果首字串是+- 合法, 先移除掉
		if (s.empty())    return false;
		if (s.find("+") != -1)    return false;
		if (s.find("-") != -1)    return false;
		if (s == ".")       return false;           // .可以出現在任何位位置, 但唯独不可以只有自己
		return true;
	}
};

// 方法三：题解大佬极其清晰的解法（查看必有收获）
// 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗 :8.5 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    bool isNumber(string s) {
        //1、从首尾寻找s中不为空格首尾位置，也就是去除首尾空格
        int i=s.find_first_not_of(' ');
        if(i==string::npos)return false;
        int j=s.find_last_not_of(' ');
        s=s.substr(i,j-i+1);
        if(s.empty())return false;

        //2、根据e来划分底数和指数
        int e=s.find('e');

        //3、指数为空，判断底数
        if(e==string::npos)return judgeP(s);

        //4、指数不为空，判断底数和指数
        else return judgeP(s.substr(0,e))&&judgeS(s.substr(e+1));
    }

    bool judgeP(string s)//判断底数是否合法
    {
        bool result=false,point=false;
        int n=s.size();
        for(int i=0;i<n;++i)
        {
            if(s[i]=='+'||s[i]=='-'){//符号位不在第一位，返回false
                if(i!=0)return false;
            }
            else if(s[i]=='.'){
                if(point)return false;//有多个小数点，返回false
                point=true;
            }
            else if(s[i]<'0'||s[i]>'9'){//非纯数字，返回false
                return false;
            }
            else{
                result=true;
            }
        }
        return result;
    }

    bool judgeS(string s)//判断指数是否合法
    {   
        bool result=false;
        //注意指数不能出现小数点，所以出现除符号位的非纯数字表示指数不合法
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='+'||s[i]=='-'){//符号位不在第一位，返回false
                if(i!=0)return false;
            }
            else if(s[i]<'0'||s[i]>'9'){//非纯数字，返回false
                return false;
            }
            else{
                result=true;
            }
        }
        return result;
    }
};

