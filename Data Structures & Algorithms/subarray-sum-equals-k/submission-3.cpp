class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int pre = 0, ans = 0;
        for (auto &x: nums) {
            ++cnt[pre];
            pre += x;
            if (cnt.count(pre - k)) ans += cnt[pre - k];
        }
        return ans;
    }
};