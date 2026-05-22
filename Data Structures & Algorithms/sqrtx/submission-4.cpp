class Solution {
public:
    int mySqrt(int x) {
        int ans = 0, lo = 0, hi = 46340;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2, val = mid * mid;
            if (val < x) {
                lo = mid + 1;
                if (mid > ans) ans = mid;
            } else if (val == x) {
                return mid;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};