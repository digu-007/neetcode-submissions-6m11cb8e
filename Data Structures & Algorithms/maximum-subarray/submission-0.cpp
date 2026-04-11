class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = 0, ans = -1000;
        for (int i = 0; i < nums.size(); ++i) {
            cur += nums[i];
            ans = max(ans, cur);
            if (cur < 0) cur = 0;
        }
        return ans;
    }
};
