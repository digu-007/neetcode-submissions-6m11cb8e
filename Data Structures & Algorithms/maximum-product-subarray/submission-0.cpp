class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0], mx = 1, mn = 1, cur;
        for (auto &x: nums) {
            cur = mx * x;
            mx = max({mx * x, mn * x, x});
            mn = min({cur, mn * x, x});
            ans = max(mx, ans);
        }
        return ans;
    }
};
