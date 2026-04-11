class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 5 6 7 8 9 1 2 3 4
        int lo = 0, hi = nums.size() - 1, mid;
        while (lo <= hi) {
            mid = (hi + lo) / 2;
            if (target == nums[mid]) return mid;
            if (nums[mid] >= nums[lo]) {
                if (target > nums[mid] || target < nums[lo]) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            } else {
                if (target < nums[mid] || target > nums[hi]) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
        }
        return -1;
    }
};
