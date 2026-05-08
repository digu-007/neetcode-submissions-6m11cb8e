class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        int ans = 0;
        dp[1][1] = -5000001;
        dp[1][0] = -a[0];
        for (int i = 2; i <= n; ++i) {
            dp[i][0] = max(dp[i - 2][1] - a[i - 1], dp[i - 1][0]); // buy
            dp[i][1] = max(dp[i - 1][0] + a[i - 1], dp[i - 1][1]); // sell
            cout << dp[i][0] << " " << dp[i][1] << "\n";
            ans = max(ans, dp[i][1]);
        }
        return ans;
    }
};
