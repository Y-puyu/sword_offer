// 方法一：位运算+思维+顶级解法
// 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗 :7.9 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int add(int a, int b) {
        
        while(b!=0){
            int tmp=a^b;
            b=((unsigned int)(a&b)<<1);
            a=tmp;
        }
        return a;
    }
};

