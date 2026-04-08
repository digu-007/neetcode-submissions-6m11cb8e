class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int n = coins.size(), dp[amount + 1][n + 1] = {};
        dp[0][0] = 1;
        // for (int j = 0; j < n; ++j) dp[0][j] = 1;
        for (int j = 1; j <= n; ++j) {
            for (int i = 0; i <= amount; ++i) {
                dp[i][j] = dp[i][j - 1];
                if (coins[j - 1] > i) continue;
                dp[i][j] += dp[i - coins[j - 1]][j];
            }
        }
        return dp[amount][n];
    }
};
