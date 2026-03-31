class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (n > m) {
            return false;
        }
        int cnt1[26] = {0}, cnt2[26] = {0};
        for (int i = 0; i < n; ++i) {
            ++cnt1[s1[i] - 'a'];
            ++cnt2[s2[i] - 'a'];
        }
        int same = 0;
        for (int i = 0; i < 26; ++i) {
            if (cnt1[i] == cnt2[i]) ++same;
        }
        if (same == 26) return true;
        for (int i = n; i < m; ++i) {
            ++cnt2[s2[i] - 'a'];
            --cnt2[s2[i - n] - 'a'];
            if (s2[i] != s2[i - n]) {
                if (cnt2[s2[i] - 'a'] - 1 == cnt1[s2[i] - 'a']) {
                    --same;
                } else if (cnt2[s2[i] - 'a'] == cnt1[s2[i] - 'a']) {
                    ++same;
                }
                if (cnt2[s2[i - n] - 'a'] + 1 == cnt1[s2[i - n] - 'a']) {
                    --same;
                } else if (cnt2[s2[i - n] - 'a'] == cnt1[s2[i - n] - 'a']) {
                    ++same;
                }
            }
            if (same == 26) return true;
        }
        return false;
    }
};
