class Solution {
public:
    int minCostClimbingStairs(vector<int>& a) {
        int n = a.size();
        int dp[n + 2] = {0};
        for (int i = 2; i <= n; ++i) {
            dp[i] = min(dp[i - 1] + a[i - 1], dp[i - 2] + a[i - 2]);
        }
        return dp[n];
    }
};
