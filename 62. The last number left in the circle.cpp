// 方法一：模拟+环形链表+常规解法
// TLE
// 26 / 36 个通过测试用例

class Solution {
public:
    int lastRemaining(int n, int m) {
        list<int> ls;
        for (int i = 0; i < n; ++i) ls.push_back(i);
        list<int>::iterator it = ls.begin();
        while (ls.size() > 1) {
            for (int i = 1; i < m; ++i) {
                ++it;
                if (it == ls.end()) it = ls.begin();
            }
            list<int>::iterator next = ++it;
            if (next == ls.end()) next = ls.begin();
            --it;
            ls.erase(it);
            it = next;
        }
        return *it;
    }
};



// 方法二：数学+递归+约瑟夫环+巧妙解法
int func(int n, int m) {
    if (n == 1) return 0;
    return (func(n - 1, m) + m) % n;
}
//n个人 每次淘汰报m 的人
//返回最终剩下的人的编号(0开始)

// 执行用时 :12 ms, 在所有 C++ 提交中击败了56.21%的用户
// 内存消耗 :12 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    int lastRemaining(int n, int m) {
        return (n == 1) ? 0 : (lastRemaining(n - 1, m) + m) % n;
    }   
};


