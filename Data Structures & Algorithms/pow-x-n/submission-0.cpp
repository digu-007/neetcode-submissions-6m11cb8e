class Solution {
public:
    double myPow(double x, int n) {
        if (!x) return 0;
        if (!n) return 1;
        double ans = 1;
        int pow = abs(n);
        while (pow) {
            if (pow & 1) {
                ans *= x;
            }
            pow >>= 1;
            x *= x;
        }
        return n > 0 ? ans : 1 / ans;
    }
};
