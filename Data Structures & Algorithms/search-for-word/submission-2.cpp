class Solution {
public:
    int n, m, len;
    vector<vector<int>> ways = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };

    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& vis, string word, int i, int j, int cur) {
        if (len == cur) return true;
        if (i >= n or j >= m or i < 0 or j < 0 or board[i][j] != word[cur] or board[i][j] == '!') return false;
        char temp = board[i][j];
        board[i][j] = '!';
        bool ans = false;
        for (int k = 0; k < 4; ++k) {
            int x = ways[k][0] + i, y = ways[k][1] + j;
            ans |= dfs(board, vis, word, x, y, cur + 1);
        }
        board[i][j] = temp;
        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size(), len = word.size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (dfs(board, vis, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};
