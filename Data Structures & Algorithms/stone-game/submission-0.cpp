class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(int l, int r, vector<int>& a) {
        if (l > r) return 0;
        if (dp[l][r] != -1e6) return dp[l][r];
        int cnt = l + n - 1 - r;
        if (cnt & 1) {
            dp[l][r] = min(solve(l + 1, r, a) - a[l], solve(l, r - 1, a) - a[r]);
        } else {
            dp[l][r] = max(solve(l + 1, r, a) + a[l], solve(l, r - 1, a) + a[r]);
        }
        return dp[l][r];
    }

    bool stoneGame(vector<int>& piles) {
        n = piles.size();
        dp.resize(n, vector<int>(n, -1e6));
        return (solve(0, n - 1, piles) > 0);
    }
};