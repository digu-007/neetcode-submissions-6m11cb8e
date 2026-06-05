class Solution {
public:
    int n, side;
    vector<int> dp;
    int solve(int mask, vector<int>& a) {
        if (!mask) return 0;
        if (dp[mask] != -2) return dp[mask];
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                int next = solve(mask ^ (1 << i), a);
                if (next >= 0 and next + a[i] <= side) return dp[mask] = (next + a[i]) % side;
            }
        }
        return dp[mask] = -1;
    }

    bool makesquare(vector<int>& a) {
        int total = accumulate(a.begin(), a.end(), 0);
        if (total % 4) return false;
        side = total / 4;
        sort(a.rbegin(), a.rend());
        if (a[0] > side) return false;
        n = a.size();
        dp.resize(1 << n, -2);
        return (solve((1 << n) - 1, a) == 0);
    }
};