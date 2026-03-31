class Solution {
public:
    int rob(vector<int>& a) {
        int n = a.size();
        if (n == 1) return a[0];
        int dp[n + 1][2] = {0};
        dp[1][1] = a[0];
        for (int i = 2; i <= n; ++i) {
            if (i == n) {
                dp[i][0] = max(dp[i - 2][0] + a[i - 1], dp[i - 1][0]);
                dp[i][1] = dp[i - 1][1];
            } else {
                dp[i][0] = max(dp[i - 2][0] + a[i - 1], dp[i - 1][0]);
                dp[i][1] = max(dp[i - 2][1] + a[i - 1], dp[i - 1][1]);
            }
        }
        return max(dp[n][0], dp[n][1]);
    }
};
