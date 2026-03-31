class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            if (i and nums[i] == nums[i - 1]) continue;
            int l = i + 1, r = n - 1;
            while (l < r) {
                int cur = nums[i] + nums[l] + nums[r];
                if (cur > 0) {
                    --r;
                } else if (cur < 0) {
                    ++l;
                } else {
                    ans.push_back({nums[i], nums[l++], nums[r--]});
                    while (l < r and nums[l] == nums[l - 1]) ++l;
                }
            }
        }
        return ans;
    }
};
