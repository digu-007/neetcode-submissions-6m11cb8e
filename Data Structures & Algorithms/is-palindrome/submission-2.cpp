class Solution {
public:
    bool valid(char& ch) {
        return (ch >= 'A' and ch <= 'Z') or (ch >= 'a' and ch <= 'z') or (ch >= '0' and ch <= '9');
    }

    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            bool st = valid(s[l]);
            bool en = valid(s[r]);
            if (!st) {
                ++l;
            }
            if (!en) {
                --r;
            }
            if (st and en) {
                if (s[l] >= 'A' and s[l] <= 'Z') {
                    s[l] = 'a' + s[l] - 'A';
                }
                if (s[r] >= 'A' and s[r] <= 'Z') {
                    s[r] = 'a' + s[r] - 'A';
                }
                if (s[l] != s[r]) return false;
                ++l, --r;
            }
        }
        return true;
    }
};
