class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (auto &x: nums) {
            int i = abs(x) - 1;
            if (nums[i] < 0) return abs(x);
            nums[i] *= -1;
        }
        return -1;
    }
};
