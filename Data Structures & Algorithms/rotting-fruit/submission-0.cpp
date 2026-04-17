class Solution {
public:
    int ways[4][2] = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
    };

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), fresh = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) q.push({i, j});
                fresh += (grid[i][j] == 1);
            }
        }
        int ans = 0;
        while (!q.empty()) {
            if (fresh) ++ans;
            int ctr = q.size();
            while (ctr--) {
                pair<int, int> cur = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    int x = cur.first + ways[i][0], y = cur.second + ways[i][1];
                    if (x >= 0 and y >= 0 and x < n and y < m and grid[x][y] == 1) {
                        grid[x][y] = 2;
                        --fresh;
                        q.push({x, y});
                    }
                }
            }
        }
        return (fresh ? -1 : ans);
    }
};
