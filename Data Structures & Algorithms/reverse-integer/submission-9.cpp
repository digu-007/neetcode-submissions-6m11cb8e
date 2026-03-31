class Solution {
public:
    int reverse(int x) {
        if (!x) return 0;
        string cur = to_string(x);
        std::reverse(cur.begin(), cur.end());
        if (*cur.rbegin() == '-') cur.pop_back();
        if (x > 0) {
            string mx = to_string(INT_MAX);
            if (cur.length() == 10 and cur > mx) return 0;
        } else {
            string mn = to_string(INT_MIN);
            cur = '-' + cur;
            if (cur.length() == 11 and cur > mn) return 0;
        }
        return stoi(cur);
    }
};
