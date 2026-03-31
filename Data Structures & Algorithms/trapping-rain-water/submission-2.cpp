class Solution {
public:
    int trap(vector<int>& a) {
        if (a.empty()) {
            return 0;
        }
        int ans = 0, l = 0, r = a.size() - 1, lmax = a[0], rmax = a[r];
        while (l < r) {
            if (lmax < rmax) {
                lmax = max(lmax, a[++l]);
                ans += (lmax - a[l]);
            } else {
                rmax = max(rmax, a[--r]);
                ans += (rmax - a[r]);
            }
        }
        return ans;
    }
};
