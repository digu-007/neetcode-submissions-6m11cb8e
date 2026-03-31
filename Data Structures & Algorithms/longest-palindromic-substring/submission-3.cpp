class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), st = 0, ans = 1, l, r;
        for (int i = 0; i < n; ++i) {
            l = i - 1, r = i + 1;
            int odd_len = 1;
            while (l >= 0 and r < n) {
                if (s[l] == s[r]) {
                    odd_len += 2;
                    if (odd_len > ans) {
                        ans = odd_len;
                        st = l;
                    }
                    --l, ++r;
                } else {
                    break;
                }
            }
            l = i, r = i + 1;
            int even_len = 0;
            while (l >= 0 and r < n) {
                if (s[l] == s[r]) {
                    even_len += 2;
                    if (even_len > ans) {
                        ans = even_len;
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
