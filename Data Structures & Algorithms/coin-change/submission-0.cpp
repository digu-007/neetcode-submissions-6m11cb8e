class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount + 1] = {0};
        for (int i = 1; i <= amount; ++i) {
            dp[i] = INT_MAX;
            for (auto &x: coins) {
                if (x <= i and dp[i - x] != -1) {
                    dp[i] = min(dp[i - x] + 1, dp[i]);
                }
            }
            if (dp[i] == INT_MAX) dp[i] = -1;
        }
        return dp[amount];
    }
};
