class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size(), ans = -1e9, cur = 0, l = 0;
        for (int i = 0; i < 2 * n; ++i) {
            cur += nums[i % n];
            if (l < n and i >= n) {
                while (l <= (i % n)) cur -= nums[l++];
                while (l < n and nums[l] < 0) cur -= nums[l++];
            }
            ans = max(ans, cur);
            if (cur < 0) {
                cur = 0;
                l = i + 1;
            }
        }
        return ans;
    }
};