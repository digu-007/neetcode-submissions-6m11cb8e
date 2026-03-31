class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        if (t.size() > n) {
            return "";
        }
        unordered_map<int,int> cnt;
        for (auto &x: t) {
            ++cnt[x];
        }
        unordered_map<int,int> next;
        int ans, min = 1111, l = 0;
        for (int i = 0; i < n; ++i) {
            ++next[s[i]];
            bool ok = true;
            for (auto &x: cnt) {
                if (x.second > next[x.first]) {
                    ok = false;
                    break;
                }
            }
            cout << ok << " " << l << " " << i << "\n";
            if (ok) {
                while (l < i) {
                    --next[s[l++]];
                    bool temp = true;
                    for (auto &x: cnt) {
                        if (x.second > next[x.first]) {
                            temp = false;
                            break;
                        }
                    }
                    if (!temp) {
                        ++next[s[--l]];
                        break;
                    }
                }
            }
            cout << ok << " " << l << " " << i << "\n";
            if (ok and i - l + 1 < min) {

                min = i - l + 1;
                ans = l;
            }
        }
        cout << min << " " << ans << "\n";
        if (min != 1111) {
            return s.substr(ans, min);
        }
        return "";
    }
};
