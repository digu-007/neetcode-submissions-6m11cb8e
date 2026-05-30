class Solution {
public:
    int n, m;
    vector<pair<int, int>> ways = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

    void dfs(int i, int j, vector<vector<bool>>& oc, vector<vector<int>>& a) {
        oc[i][j] = true;
        for (int u = 0; u < 4; ++u) {
            int x = ways[u].first + i, y = ways[u].second + j;
            if (x >= 0 and y >= 0 and x < n and y < m and !oc[x][y] and a[i][j] <= a[x][y]) dfs(x, y, oc, a);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& a) {
        n = a.size(), m = a[0].size();
        vector<vector<bool>> pc, at;
        pc.resize(n, vector<bool>(m, false));
        at.resize(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i) {
            dfs(i, 0, pc, a);
            dfs(i, m - 1, at, a);
        }
        for (int j = 0; j < m; ++j) {
            dfs(0, j, pc, a);
            dfs(n - 1, j, at, a);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (pc[i][j] and at[i][j]) ans.push_back({i, j});
            }
        }
        return ans;
    }
};
