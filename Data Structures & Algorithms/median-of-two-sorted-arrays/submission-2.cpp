class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 1, 2), (5, 9    3), (4, 8
        // 1, 2, 3, 4, 5, 8, 9
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        int n = nums1.size(), m = nums2.size(), lo = 0, hi = n, total = n + m, half = total / 2;
        double ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int rem = half - mid;
            int l1 = mid > 0 ? nums1[mid - 1] : INT_MIN;
            int r1 = mid < n ? nums1[mid] : INT_MAX;
            int l2 = rem > 0 ? nums2[rem - 1] : INT_MIN;
            int r2 = rem < m ? nums2[rem] : INT_MAX;

            if (l1 <= r2 and l2 <= r1) {
                if (total & 1) return min(r1, r2);
                return (min(r1, r2) + max(l1, l2)) / 2.0;
            } else if (l1 > r2) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return -1;
    }
};
