class Solution {
public:
    int tribonacci(int n) {
        if (n <= 1) return n;
        int f = 0, s = 1, t = 1;
        for (int i = 3; i <= n; ++i) {
            int next = f + s + t;
            swap(next, t);
            swap(next, s);
            swap(next, f);
        }
        return t;
    }
};