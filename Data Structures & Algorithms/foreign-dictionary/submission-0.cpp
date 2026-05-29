class Solution {
public:
    vector<int> g[26];
    vector<int> vis;
    string ans;

    bool dfs(int u) {
        vis[u] = 1;
        for (auto &x: g[u]) {
            if (!vis[x]) {
                bool ok = dfs(x);
                if (!ok) return false;
            } else if (vis[x] == 1) {
                return false;
            }
        }
        vis[u] = 2;
        ans += char(u + 'a');
        return true;
    }

    string foreignDictionary(vector<string>& words) {
        vector<bool> present(26, false);
        for (auto &x: words) {
            for (auto &ch: x) {
                present[ch - 'a'] = true;
            }
        }
        int n = words.size();
        for (int i = 1; i < n; ++i) {
            int f = words[i - 1].size(), s = words[i].size();
            bool ok = false;
            for (int j = 0; j < min(f, s); ++j) {
                if (words[i - 1][j] != words[i][j]) {
                    g[words[i][j] - 'a'].push_back(words[i - 1][j] - 'a');
                    ok = true;
                    break;
                }
            }
            if (!ok and f > s) return "";
        }
        vis.resize(26, 0);
        for (int i = 0; i < 26; ++i) {
            if (present[i] and !vis[i]) {
                if (!dfs(i)) return "";
            }
        }
        return ans;
    }
};
