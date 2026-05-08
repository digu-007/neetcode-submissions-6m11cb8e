class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size(), ans = 1;
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
