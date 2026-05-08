class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        if (s3.size() != n + m) return false;
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (i and s1[i - 1] == s3[i + j - 1] and dp[i - 1][j]) dp[i][j] = true;
                if (j and s2[j - 1] == s3[i + j - 1] and dp[i][j - 1]) dp[i][j] = true;
            }
        }
        return dp[n][m];
    }
};
