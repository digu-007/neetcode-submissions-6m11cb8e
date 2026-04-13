class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size(), m;
        bool match, dp[n + 1];
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            dp[i] = false;
            for (auto &word: wordDict) {
                m = word.size();
                if (m > i or !dp[i - m]) continue;
                cout << m << "\n";
                match = true;
                for (int j = 0; j < m; ++j) {
                    cout << s[i - m + j] << " " << word[j] << "\n";
                    if (s[i - m + j] != word[j]) {
                        match = false;
                        break;
                    }
                }
                dp[i] |= match;
            }
        }
        return dp[n];
    }
};
