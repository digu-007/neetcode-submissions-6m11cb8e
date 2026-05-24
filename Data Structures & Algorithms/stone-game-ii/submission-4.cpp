class Solution {
public:
    int n;

    int solve(int idx, int m, bool turn, vector<int>& piles, vector<vector<vector<int>>>& dp) {
        if (idx >= n) return 0;
        if (dp[idx][m][turn]) return dp[idx][m][turn];
        if (!turn) dp[idx][m][turn] = INT_MAX;
        int pref = 0;
        for (int i = idx; i < min(n, idx + 2 * m); ++i) {
            pref += piles[i];
            if (turn) {
                dp[idx][m][turn] = max(dp[idx][m][turn], pref + solve(i + 1, max(i - idx + 1, m), turn ^ 1, piles, dp));
            } else {
                dp[idx][m][turn] = min(dp[idx][m][turn], solve(i + 1, max(i - idx + 1, m), turn ^ 1, piles, dp));
            }
        }
        return dp[idx][m][turn];
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        if (n == 1) return piles[0];
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));
        return solve(0, 1, 1, piles, dp);
    }
};