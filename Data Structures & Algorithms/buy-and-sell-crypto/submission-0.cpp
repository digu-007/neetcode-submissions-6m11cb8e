class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size(), mx = 0, ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            mx = max(mx, a[i]);
            ans = max(ans, mx - a[i]);
        }
        return ans;
    }
};
