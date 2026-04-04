class Solution {
public:
    bool check(vector<int>& a, int& cur, int h) {
        for (auto &x: a) {
            h -= (x + cur - 1) / cur;
        }
        return (h >= 0);
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = 1e9, mid, ans;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (check(piles, mid, h)) {
                ans = mid, hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
