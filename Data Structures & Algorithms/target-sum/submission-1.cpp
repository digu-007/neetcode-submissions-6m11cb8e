class Solution {
public:
    int limit;

    int solve(vector<int>& a, vector<vector<int>>& dp, int idx, int cur, int target) {
        if (idx < 0) return cur == target;
        if (dp[idx][cur + limit] != -1) return dp[idx][cur + limit];
        return dp[idx][cur + limit] = solve(a, dp, idx - 1, cur + a[idx], target) + solve(a, dp, idx - 1, cur - a[idx], target);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        limit = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n, vector<int>(2 * limit + 1, -1));
        return solve(nums, dp, n - 1, 0, target);
    }
};
