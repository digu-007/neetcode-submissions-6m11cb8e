class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int cnt[2001] = {0};
        for (auto &x: nums) {
            ++cnt[x + 1000];
        }
        vector<vector<int>> rank(nums.size() + 1);
        for (int i = -1000; i <= 1000; ++i) {
            rank[cnt[i + 1000]].emplace_back(i);
        }
        vector<int> ans;
        for (int i = nums.size(); i > 0; --i) {
            while (rank[i].size()) {
                if (k) {
                    --k;
                    ans.emplace_back(rank[i].back());
                    rank[i].pop_back();
                } else {
                    return ans;
                }
            }
        }
        return ans;
    }
};
