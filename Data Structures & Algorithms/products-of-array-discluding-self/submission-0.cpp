class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int suf[n + 1];
        suf[n] = 1;
        for (int i = n - 1; i > 0; --i) {
            suf[i] = nums[i] * suf[i + 1];
        }
        vector<int> ans;
        int cur = 1;
        for (int i = 0; i < n; ++i) {
            ans.emplace_back(cur * suf[i + 1]);
            cur *= nums[i];
        }
        return ans;
    }
};
