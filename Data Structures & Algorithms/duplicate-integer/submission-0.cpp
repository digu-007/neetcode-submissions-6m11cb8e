class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,bool> mp;
        for (auto &x: nums) {
            if (mp.count(x)) {
                return true;
            } else {
                mp[x] = true;
            }
        }
        return false;
    }
};