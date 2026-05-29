class Solution {
public:
    vector<vector<int>> g;
    vector<bool> vis;

    void dfs(int i) {
        vis[i] = true;
        for (auto &x: g[i]) {
            if (!vis[x]) dfs(x);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        g.resize(n, vector<int>());
        vis.resize(n, false);
        for (auto &x: edges) {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                dfs(i);
                ++ans;
            }
        }
        return ans;
    }
};
