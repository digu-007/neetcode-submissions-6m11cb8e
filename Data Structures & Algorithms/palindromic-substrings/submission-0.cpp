class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), ans = n, l, r;
        for (int i = 0; i < n; ++i) {
            l = i - 1, r = i + 1;
            while (l >= 0 and r < n) {
                if (s[l--] == s[r++]) {
                    ++ans;
                } else {
                    break;
                }
            }
            l = i, r = i + 1;
            while (l >= 0 and r < n) {
                if (s[l--] == s[r++]) {
                    ++ans;
                } else {
                    break;
                }
            }
        }
        return ans;
    }
};
