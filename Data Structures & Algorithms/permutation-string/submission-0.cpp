class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (n > m) {
            return false;
        }
        int cnt[26] = {0};
        for (int i = 0; i < n; ++i) {
            ++cnt[s1[i] - 'a'];
        }
        for (int i = 0; i < m; ++i) {
            --cnt[s2[i] - 'a'];
            if (i >= n - 1) {
                bool equal = true;
                for (int j = 0; j < 26; ++j) {
                    if (cnt[j]) {
                        equal = false;
                        break;
                    }
                }
                if (equal) return true;
                ++cnt[s2[i - n + 1] - 'a'];
            }
        }
        return false;
    }
};
