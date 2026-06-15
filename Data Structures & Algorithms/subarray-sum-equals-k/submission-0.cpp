class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int pre = 0;
        unordered_map<int, int> cnt;
        for (auto &x: nums) {
            pre += x;
            ++cnt[pre];
        }
        int ans = 0;
        pre = 0;
        for (auto &x: nums) {
            if (cnt.count(pre + k)) ans += cnt[pre + k];
            pre += x;
            --cnt[pre];
        }
        return ans;
    }
};