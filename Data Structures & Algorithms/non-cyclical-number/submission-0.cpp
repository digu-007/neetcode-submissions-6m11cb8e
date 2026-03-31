class Solution {
public:
    unordered_set<int> vis;
    
    void check(int n) {
        if (vis.count(n)) {
            return;
        }
        vis.insert(n);
        int next = 0;
        while (n) {
            next += (n % 10) * (n % 10);
            n /= 10;
        }
        check(next);
    }

    bool isHappy(int n) {
        check(n);
        return vis.count(1);
    }
};
