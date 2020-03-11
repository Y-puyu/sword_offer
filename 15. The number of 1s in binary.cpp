// 方法一：常规左移、右移位运算解法
// 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗 :8.1 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        uint32_t flag = 1;
        while (flag) {
            if (n & flag)
                count++;
            flag = flag << 1;
        }
        return count;
    }
};




// 方法二：位运算技巧
// 执行用时 :4 ms, 在所有 C++ 提交中击败了73.72%的用户
// 内存消耗 :8.2 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            n = n & (n - 1);
            ++count;
        }
        return count;
    }
};

