class Solution {
public:
    bool match(string& s, string& t, int l, int r) {
        for (int i = l; i <= r; ++i) {
            if (s[i] != t[i - l]) return false;
        }
        return true;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size(), m = dictionary.size();
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + 1;
            for (int j = 1; j <= m; ++j) {
                int len = dictionary[j - 1].size();
                if (len <= i and match(s, dictionary[j - 1], i - len, i - 1)) dp[i] = min(dp[i], dp[i - len]);
            }
        }
        return dp[n];
    }
};