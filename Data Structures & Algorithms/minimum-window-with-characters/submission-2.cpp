class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if (t.size() > n) {
            return "";
        }
        unordered_map<int,int> cnt;
        for (auto &x: t) {
            ++cnt[x];
        }
        int ans, min = 1111, l = 0;
        for (int i = 0; i < n; ++i) {
            if (cnt.count(s[i])) {
                if (cnt[s[i]] > 0) --m;
                --cnt[s[i]];
            }
            while (!m and l < i) {
                if (cnt.count(s[l])) {
                    if (cnt[s[l]] < 0) {
                        ++cnt[s[l++]];
                    } else {
                        break;
                    }
                } else {
                    ++l;
                }
            }
            if (!m and i - l + 1 < min) {
                min = i - l + 1;
                ans = l;
            }
        }
        if (min != 1111) {
            return s.substr(ans, min);
        }
        return "";
    }
};
