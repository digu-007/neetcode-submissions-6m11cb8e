class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
        int n = s.size(), l = 0, ans = 0;
        int cnt[256] = {0};
        for (int i = 0; i < n; ++i) {
            if (cnt[s[i]]++) {
                while (cnt[s[i]] > 1) {
                    --cnt[s[l++]];
                }
            }
            ans = max(ans, i - l + 1);
        }
        return ans;
    }
};
