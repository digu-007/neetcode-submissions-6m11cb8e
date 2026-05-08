class Solution {
public:
    bool canPartition(vector<int>& a) {
        int n = a.size(), m = accumulate(a.begin(), a.end(), 0);
        if (m & 1) return false;
        m >>= 1;
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (dp[i - 1][j]) dp[i][j] = 1;
                if (j >= a[i - 1] and dp[i - 1][j - a[i - 1]]) dp[i][j] = 1;
            }
        }
        return dp[n][m];
    }
};
