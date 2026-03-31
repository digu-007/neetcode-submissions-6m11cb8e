class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n = nums.size();
        // for (int i = 0; i < n; ++i) {
        //     mp[nums[i]] = i; 
        // }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            int cur = target - nums[i];
            if (mp.count(cur) and i != mp[cur]) {
                int j = mp[cur];
                if (i < j) {
                    ans.emplace_back(i);
                    ans.emplace_back(j);
                } else {
                    ans.emplace_back(j);
                    ans.emplace_back(i);
                }
                return ans;
            }
            mp[nums[i]] = i;
        }
    }
};
