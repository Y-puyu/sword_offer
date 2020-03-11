// 方法一：思维+数学+巧妙解法
// 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗 :7.4 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int sumNums(int n) {
        return (int)(pow(n, 2) + n) >> 1;
    }
};




// 方法二：思维+构造函数+巧妙解法
// 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗 :7.7 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    class Sum{
    public:
        Sum() {
            sum += i;
            ++i;
        }
    };
    int sumNums(int n) {
        sum = 0;
        i = 1;
        Sum arr[n];
        return sum;
    }
private:
    static int sum;
    static int i;
};

int Solution::sum = 0;
int Solution::i = 1;


// 方法三：思维+运算符短路+顶级解法
// 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗 :7.9 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int sumNums(int n) {
        n && (n += sumNums(n - 1));
        return n;
    }
};
