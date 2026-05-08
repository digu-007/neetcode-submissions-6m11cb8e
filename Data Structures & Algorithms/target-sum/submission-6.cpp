class Solution {
public:

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(), m = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n, vector<int>(2 * m + 1, 0));
        dp[0][m + nums[0]] = 1;
        dp[0][m - nums[0]] += 1;
        for (int i = 1; i < n; ++i) {
            for (int j = -m; j <= m; ++j) {
                if (j + nums[i] <= m) dp[i][j + m] = dp[i - 1][j + nums[i] + m];
                if (j - nums[i] >= -m) dp[i][j + m] += dp[i - 1][j - nums[i] + m];
            }
        }
        return dp[n - 1][target + m];
    }
};
