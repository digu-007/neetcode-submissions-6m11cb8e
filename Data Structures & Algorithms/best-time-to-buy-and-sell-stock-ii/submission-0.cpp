class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size(), ans = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i] > a[i - 1]) ans += a[i] - a[i - 1];
        }
        return ans;
    }
};