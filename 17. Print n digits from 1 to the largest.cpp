// 方法一：pow()无脑解法
// 执行用时 :8 ms, 在所有 C++ 提交中击败了81.22%的用户
// 内存消耗 :13.7 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res;
        int i = 1;
        int imax = pow(10, n);
        while(i < imax){
            res.push_back(i++);
        }
        return res;
    }
};




// 方法二：考虑大数char数组解法
// 执行用时 :12 ms, 在所有 C++ 提交中击败了51.29%的用户
// 内存消耗 :14.3 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
	vector<int> res;
	vector<int> printNumbers(int n) {
		if (n <= 0)          
            return res;
		char* number = new char[n + 1];     // 创建一个能容纳最大值的字符数组,由于有一位要存储'\0'，因此要开大一格
		memset(number, '0', n);             // 初始全部设置为0
		number[n] = '\0';                   // 第n位设为'\0'
		while (!Increment(number))
			PrintNumber(number);
		delete[]number;                     // 注意要释放内存
		return res;
	}
	bool Increment(char* number) {          // 形参传递char*指针
		bool isOverflow = false;            // 检测是否越界
		int nTakeOver = 0;                  // 存储进位
		int nLength = strlen(number);       // 长度为n,不是n+1
		for (int i = nLength - 1; i >= 0; i--) {
			int nSum = number[i] - '0' + nTakeOver;
			if (i == nLength - 1)           // 如果是第一位，进位
				nSum++;
			if (nSum >= 10) {               // 有进位
				if (i == 0)                 // 如果是最高位有进位，说明超过了给定得到最大值，越界
					isOverflow = true;
				else {                      // 非最高位有进位
					nTakeOver = 1;
					number[i] = nSum - 10 + '0';    // 对第i位进行设置
				}
			}
			else {                          // 没有进位，设置第i位数字，直接跳出循环
				number[i] = nSum + '0';
				break;
			}
		}
		return isOverflow;
	}
 
	void PrintNumber(char* number) {        // 形参传递char*指针，此处改变形参number指向的位置，不会使原始的number指针所指位置改变
		string s = "";
		bool isBegin0 = true;
		while (*number != '\0') {
			if (isBegin0 && *number != '0')     // 碰到'0'，则不输出
                isBegin0 = false;
			if (!isBegin0)
				s += *number;
			number++;
		}
		int num = stoi(s);	// 转为整数，注意在此atoi函数不能给char*使用，仅能给const char*进行转换，故使用stoi
		res.push_back(num);
	}
};

// 方法三：string解法
// 执行用时 :144 ms, 在所有 C++ 提交中击败了5.77%的用户
// 内存消耗 :28.9 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
	vector<int> res;
	vector<int> printNumbers(int n) {
		if (n <= 0) return res;
		string number(n, '0');                   // 创建一个能容纳最大值的字符数组，初始全部设置为0
		while (!Increment(number))
			saveNumber(number);
		return res;
	}
	bool Increment(string& number) {             // 注意要使用引用传递，否则无法修改number
		bool isOverflow = false;                 // 检测是否越界
		int nTakeOver = 0;                       // 存储进位
		int nLength = number.size();
		for (int i = nLength - 1; i >= 0; i--) {
		
			int nSum = number[i] - '0' + nTakeOver;
			if (i == nLength - 1)                // 如果是第一位，进位
				nSum++;
			if (nSum >= 10) {                    // 有进位
				if (i == 0)                      // 如果是最高位有进位，说明超过了给定得到最大值，越界
					isOverflow = true;
				else {
					nTakeOver = 1;
					number[i] = nSum - 10 + '0'; // 对第i位进行设置
				}
			}
			else {                               // 没有进位，设置第i位数字，并直接跳出循环
				number[i] = nSum + '0';
				break;
			}
		}
		return isOverflow;
	}
	void saveNumber(string number) {             //由于此处输出，不需要修改number，因此不需要加引用
		string s = "";
		bool isBegin0 = true;
		string::iterator it = number.begin();
		while (it != number.end()) {
			if (isBegin0 && *it != '0') 
                isBegin0 = false;
			if (!isBegin0)
				s += *it;
			it++;
		}
		int num = stoi(s);
		res.push_back(num);
	}
};

