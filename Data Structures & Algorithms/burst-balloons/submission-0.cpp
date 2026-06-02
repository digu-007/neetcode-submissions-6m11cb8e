class Solution {
public:
    int maxCoins(vector<int>& a) {
        // 4, 3, 2, 2, 7, 2
        int n = a.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 0; len < n; ++len) {
            for (int i = 0; i < n; ++i) {
                int j = i + len;
                if (j >= n) continue;
                for (int k = i; k <= j; ++k) {
                    int u = (i == 0) ? 1 : a[i - 1];
                    int v = (j == n - 1) ? 1 : a[j + 1];
                    int dp_u = (i == k) ? 0 : dp[i][k - 1];
                    int dp_v = (j == k) ? 0 : dp[k + 1][j];
                    dp[i][j] = max(dp[i][j], dp_u + u * a[k] * v + dp_v);
                }
            }
        }
        return dp[0][n - 1];
    }
};
