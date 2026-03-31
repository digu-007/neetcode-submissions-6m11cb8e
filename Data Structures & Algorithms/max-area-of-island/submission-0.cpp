class Solution {
public:
    int n, m;

    int dfs(int i, int j, vector<vector<int>>& grid) {
        int ans = 1;
        grid[i][j] = 0;
        if (i - 1 >= 0 and grid[i - 1][j]) ans += dfs(i - 1, j, grid);
        if (j - 1 >= 0 and grid[i][j - 1]) ans += dfs(i, j - 1, grid);
        if (i + 1 < n and grid[i + 1][j]) ans += dfs(i + 1, j, grid);
        if (j + 1 < m and grid[i][j + 1]) ans += dfs(i, j + 1, grid);
        return ans;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j]) ans = max(ans, dfs(i, j, grid));
            }
        }
        return ans;
    }
};
