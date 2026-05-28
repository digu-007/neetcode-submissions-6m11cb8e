class Solution {
public:
    int lastStoneWeightII(vector<int>& a) {
        int sum = accumulate(a.begin(), a.end(), 0), val = sum / 2;
        int n = a.size();
        vector<vector<int>> dp(n + 1, vector<int>(val + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= val; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (a[i - 1] <= j) dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i - 1]] + a[i - 1]);
            }
        }
        return (sum - 2 * dp[n][val]);
    }
};