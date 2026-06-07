class Solution {
public:
    string stoneGameIII(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; --i) {
            // Alice
            dp[i][0] = dp[i + 1][1] + a[i];
            if (i < n - 1) dp[i][0] = max(dp[i][0], dp[i + 2][1] + a[i + 1] + a[i]);
            if (i < n - 2) dp[i][0] = max(dp[i][0], dp[i + 3][1] + a[i + 2] + a[i + 1] + a[i]);

            // Bob
            dp[i][1] = dp[i + 1][0] - a[i];
            if (i < n - 1) dp[i][1] = min(dp[i][1], dp[i + 2][0] - a[i + 1] - a[i]);
            if (i < n - 2) dp[i][1] = min(dp[i][1], dp[i + 3][0] - a[i + 2] - a[i + 1] - a[i]);
        }
        if (!dp[0][0]) return "Tie";
        return (dp[0][0] > 0 ? "Alice" : "Bob");
    }
};