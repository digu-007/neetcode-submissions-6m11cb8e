class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, ans;
        for (auto &x: nums) {
            if (!cnt) ans = x;
            (x == ans) ? ++cnt : --cnt;
        }
        return ans;
    }
};