// 方法一：模拟+常规解法
// 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗 :7.7 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int strToInt(string str) {
        int i = 0, flag = 1;
        int flag2 = 0;
        string st;
        while (str[i] == ' ') ++i;
        if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '-' && str[i] != '+') return 0;
        if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9')) {
            flag = -1;
            ++i;
        }
        if (str[i] == '+' && (str[i + 1] >= '0' && str[i + 1] <= '9')) {
            flag = 1;
            ++i;
        }
        while (str[i] >= '0' && str[i] <= '9') {
            st.push_back(str[i]);
            ++i;
        }
        long double num = 0;
        long double cnt = 1;
        for (int i = st.length() - 1; i >= 0; --i) {
            num += ((st[i] - '0') * cnt);
            cnt *= 10;
            if (num > INT_MAX) {
                flag2 = 11;
                break;
            }
        }
		if (flag2 == 11 && flag == 1) return INT_MAX;
		if (flag2 == 11 && flag == -1) return INT_MIN;
        
        return num * flag;
    }
};

// 方法二：istringstream函数+巧妙解法
// 执行用时 :8 ms, 在所有 C++ 提交中击败了54.38%的用户
// 内存消耗 :7.9 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int strToInt(string str) {
        int digit=0;
        istringstream is(str);
        is >> digit;
        return digit;
    }
};
