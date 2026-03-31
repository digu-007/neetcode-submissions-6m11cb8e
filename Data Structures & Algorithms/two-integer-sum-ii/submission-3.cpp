class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        int r = a.size() - 1, l = 0;
        vector<int> ans = {0, 0};
        while (l < r) {
            if (a[l] + a[r] > target) {
                --r;
            } else if (a[l] + a[r] < target) {
                ++l;
            } else {
                return {l + 1, r + 1};
            }
        }
        return ans;
    }
};
