class Solution {
public:
    int mySqrt(int x) {
        int ans = 0, lo = 0, hi = 1e5;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (1ll * mid * mid <= x) {
                lo = mid + 1;
                ans = max(ans, mid);
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};