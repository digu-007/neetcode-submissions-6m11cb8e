class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int cur = nums[i] + nums[l] + nums[r];
                if (cur > 0) {
                    --r;
                } else if (cur < 0) {
                    ++l;
                } else {
                    cout << i << " " << l << " " << r << "\n";
                    res.insert({nums[i], nums[l++], nums[r]});
                }
            }
        }
        vector<vector<int>> ans;
        for (auto &x: res) {
            ans.push_back(x);
        }
        return ans;
    }
};
