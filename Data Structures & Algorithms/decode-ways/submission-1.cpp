class Solution {
public:
    int numDecodings(string s) {
        int n = s.size(), dp[n + 1];
        if (s[0] == '0') return 0;
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            cout << s[i - 2] << " " << s[i - 1] << "\n";
            if (s[i - 1] == '0') {
                if (s[i - 2] != '1' and s[i - 2] != '2') {
                    return 0;
                } else {
                    dp[i] = dp[i - 2];
                    continue;
                }
            }
            dp[i] = dp[i - 1];
            if (s[i - 2] == '1') {
                if (s[i - 1] != '0') dp[i] += dp[i - 2];
            }
            if (s[i - 2] == '2') {
                if (s[i - 1] > '0' and s[i - 1] < '7') dp[i] += dp[i - 2];
            }
            cout << dp[i] << "\n";
        }
        return dp[n];
    }
};
