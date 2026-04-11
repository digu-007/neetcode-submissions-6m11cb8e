class Solution {
public:
    vector<pair<int, int>> ways = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
    };

    bool check(int& n, int& m, int i, int j) {
        return (i >= 0 and j >= 0 and i < n and j < m);
    }

    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int& n, int& m, int i, int j) {
        if (dp[i][j]) return dp[i][j];
        dp[i][j] = 1;
        for (auto &x: ways) {
            if (!check(n, m, i + x.first, j + x.second)) continue;
            if (matrix[i][j] >= matrix[i + x.first][j + x.second]) continue;
            dp[i][j] = max(dp[i][j], 1 + dfs(matrix, dp, n, m, i + x.first, j + x.second));
        }
        // for (auto &x: ways) {
        //     if (!check(n, m, i + x.first, j + x.second)) continue;
        //     if (matrix[i][j] >= matrix[i + x.first][j + x.second]) continue;
        //     dp[i][j] = max(dp[i][j], dp[i][j] + dfs(matrix, dp, n, m, i + x.first, j + x.second));
        // }
        cout << i << " "  << j << " : " << dp[i][j] << "\n";
        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans = 1;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans = max(ans, dfs(matrix, dp, n, m, i, j));
            }
        }
        return ans;
    }
};
