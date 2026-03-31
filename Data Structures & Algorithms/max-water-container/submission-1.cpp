class Solution {
public:
    int maxArea(vector<int>& a) {
        int l = 0, r = a.size() - 1, ans = 0;
        while (l < r) {
            int cur = min(a[l], a[r]) * (r - l);
            if (cur > ans) {
                ans = cur;
            }
            if (a[l] > a[r]) {
                --r;
            } else {
                ++l;
            }
        }
        return ans;
    }
};
