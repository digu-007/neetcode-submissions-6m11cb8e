class Solution {
public:
    int n, m;
    vector<vector<bool>> vis;
    vector<pair<int, int>> ways = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

    bool dfs(int i, int j, vector<vector<char>>& board) {
        vis[i][j] = true;
        bool ok = true;
        for (int u = 0; u < 4; ++u) {
            int x = ways[u].first + i, y = ways[u].second + j;
            if (x < 0 or y < 0 or x >= n or y >= m) {
                ok = false;
                continue;
            }
            if (!vis[x][y] and board[x][y] == 'O') ok &= dfs(x, y, board);
        }
        return ok;
    }

    void mark(int i, int j, vector<vector<char>>& board) {
        board[i][j] = 'X';
        for (int u = 0; u < 4; ++u) {
            int x = ways[u].first + i, y = ways[u].second + j;
            if (x >= 0 and y >= 0 and x < n and y < m and board[x][y] == 'O') mark(x, y, board);
        }
    }

    void solve(vector<vector<char>>& board) {
        n = board.size(), m = board[0].size();
        vis.resize(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                bool ok = false;
                if (!vis[i][j] and board[i][j] == 'O') ok = dfs(i, j, board);
                if (ok) mark(i, j, board);
            }
        }
    }
};
