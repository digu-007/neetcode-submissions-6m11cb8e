class MedianFinder {
public:
    int n;
    priority_queue<int> lo;
    priority_queue<int, vector<int>, greater<int>> hi;

    MedianFinder() {
        n = 0;
    }
    
    void addNum(int num) {
        if (lo.empty()) {
            lo.push(num);
        } else if (num > lo.top()) {
            hi.push(num);
        } else {
            lo.push(num);
        }
        ++n;
        if (hi.size() > lo.size()) {
            int cur = hi.top();
            hi.pop();
            lo.push(cur);
        } else if (lo.size() > hi.size() + 1) {
            int cur = lo.top();
            lo.pop();
            hi.push(cur);
        }
    }
    
    double findMedian() {
        if (n & 1) {
            return (double)lo.top();
        }
        return ((double)lo.top() + hi.top()) / 2.0;
    }
};
