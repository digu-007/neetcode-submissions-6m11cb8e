class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0, cur = 0, l = 0;
        int cnt[256] = {0};
        for (int i = 0; i < s.size(); ++i) {
            ++cnt[s[i]];
            if (cnt[s[i]] > cnt[cur]) {
                cur = s[i];
            }
            int target = cnt[cur];
            while (i - l + 1 - target > k) {
                --cnt[s[l++]];
            }
            ans = max(ans, i - l + 1);
        }
        return ans;
    }
};
