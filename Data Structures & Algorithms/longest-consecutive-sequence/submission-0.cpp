class Solution {
public:
    int dp[1001] = {0};
    unordered_map<int,int> mp;

    int solve(int cur, vector<int>& nums) {
        if (dp[cur]) return dp[cur];
        dp[cur] = 1;
        if (mp.count(nums[cur] + 1)) {
            dp[cur] += solve(mp[nums[cur] + 1], nums);
        }
        cout << cur << " " << nums[cur] << " " << dp[cur] << "\n";
        return dp[cur];
    }

    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            mp[nums[i]] = i;
        }
        for (int i = 0; i < n; ++i) {
            if (!dp[i]) {
                ans = max(ans, solve(i, nums));
            }
        }
        return ans;
    }
};
