class Solution {
public:
    int n, m;
    vector<pair<int, int>> ways = {
        {1, 0},
        {0, -1},
        {0, 1},
        {-1, 0}
    };

    void dfs(int x, int y, vector<vector<char>>& grid) {
        grid[x][y] = '0';
        for (int i = 0; i < 4; ++i) {
            int next_x = ways[i].first + x, next_y = ways[i].second + y;
            if (next_x < n and next_x >= 0 and next_y < m and next_y >= 0 and grid[next_x][next_y] == '1') dfs(next_x, next_y, grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    dfs(i, j, grid);
                    ++ans;
                }
            }
        }
        return ans;
    }
};
