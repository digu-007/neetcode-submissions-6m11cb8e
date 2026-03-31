class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> cnt;
        for (auto &x: nums) {
            ++cnt[x];
        }
        vector<vector<int>> rank(10001);
        for (auto &x: cnt) {
            rank[x.second].emplace_back(x.first);
        }
        vector<int> ans;
        for (int i = 10000; i >= 0; --i) {
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
