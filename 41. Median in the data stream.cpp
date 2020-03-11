// 方法一：最大/小堆+泛型算法+过程化思考+顶级解法
// 执行用时 :124 ms, 在所有 C++ 提交中击败了96.61%的用户
// 内存消耗 :45 MB, 在所有 C++ 提交中击败了100.00%的用户

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (((min.size() + max.size()) & 1) == 0) {
            if (max.size() > 0 and num < max[0]) {
                max.push_back(num);
                push_heap(max.begin(), max.end(), less<double>());
                num = max[0];
                pop_heap(max.begin(), max.end(), less<double>());
                max.pop_back();
            }
            min.push_back(num);
            push_heap(min.begin(), min.end(), greater<double>());
        }
        else {
            if (min.size() > 0 and min[0] < num) {
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<double>());
                num = min[0];
                pop_heap(min.begin(), min.end(), greater<double>());
                min.pop_back();
            }
            max.push_back(num);
            push_heap(max.begin(), max.end(), less<double>());
        }
    }
    
    double findMedian() {
        int size = min.size() + max.size();
        if (size == 0) return 0;
        double mid = 0;
        if ((size & 1) == 1) mid = min[0];
        else mid = (min[0] + max[0]) / 2;
        return mid;
    }
private:
    vector<double> min;
    vector<double> max;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */