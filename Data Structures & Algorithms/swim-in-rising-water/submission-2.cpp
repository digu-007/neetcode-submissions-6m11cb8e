class Solution {
public:
    int n;
    vector<vector<bool>> vis;
    vector<pair<int, int>> ways = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };

    void dfs(int i, int j, vector<vector<int>>& grid, int& level) {
        vis[i][j] = true;
        for (auto &u: ways) {
            int x = u.first + i, y = u.second + j;
            if (x < n and x >= 0 and y < n and y >= 0 and !vis[x][y] and grid[x][y] <= level) dfs(x, y, grid, level);
        }
    }

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        vis.resize(n, vector<bool>(n, false));
        int lo = 0, hi = n * n - 1, ans = hi;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (grid[0][0] <= mid) dfs(0, 0, grid, mid);
            if (vis[n - 1][n - 1]) {
                hi = mid - 1;
                ans = mid;
            } else {
                lo = mid + 1;
            }
            for (int i = 0; i < n; ++i) {
                fill(vis[i].begin(), vis[i].end(), false);
            }
        }
        return ans;
    }
};
