class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), st = 0, ans = 1, l, r, len;
        for (int i = 0; i < n; ++i) {
            l = i - 1, r = i + 1;
            len = 1;
            while (l >= 0 and r < n) {
                if (s[l] == s[r]) {
                    len += 2;
                    if (len > ans) {
                        ans = len;
                        st = l;
                    }
                    --l, ++r;
                } else {
                    break;
                }
            }
            l = i, r = i + 1;
            len = 0;
            while (l >= 0 and r < n) {
                if (s[l] == s[r]) {
                    len += 2;
                    if (len > ans) {
                        ans = len;
                        st = l;
                    }
                    --l, ++r;
                } else {
                    break;
                }
            }
        }
        return s.substr(st, ans);
    }
};
