class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        int n = a.size(), m = b.size();
        vector<int> dp(m + 1, 0);
        for (int i = 1; i <= n; ++i) {
            vector<int> cur(m + 1, 0);
            for (int j = 1; j <= m; ++j) {
                if (a[i - 1] == b[j - 1]) {
                    cur[j] = dp[j - 1] + 1;
                } else {
                    cur[j] = max(dp[j], cur[j - 1]);
                }
            }
            dp = cur;
        }
        return dp[m];
    }
};
