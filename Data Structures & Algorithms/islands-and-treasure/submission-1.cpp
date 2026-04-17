class Solution {
public:
    int ways[4][2] = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
    };

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), x, y;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!grid[i][j]) q.push({i, j});
            }
        }
        pair<int, int> cur;
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                x = cur.first + ways[i][0], y = cur.second + ways[i][1];
                if (x >= 0 and y >= 0 and x < n and y < m and grid[x][y] == INT_MAX) {
                    grid[x][y] = 1 + grid[cur.first][cur.second];
                    q.push({x, y});
                }
            }
        }
    }
};
