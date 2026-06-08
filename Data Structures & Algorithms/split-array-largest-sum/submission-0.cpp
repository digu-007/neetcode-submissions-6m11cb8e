class Solution {
public:
    bool check(int sum, vector<int>& nums, int k) {
        int cur = 0, cnt = 1;
        for (auto &x: nums) {
            if (cur + x > sum) {
                cur = 0;
                ++cnt;
            }
            cur += x;
        }
        return (cnt <= k);
    }

    int splitArray(vector<int>& nums, int k) {
        int lo = *max_element(nums.begin(), nums.end()), hi = 1e9, ans = hi;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(mid, nums, k)) {
                hi = mid - 1;
                ans = mid;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};