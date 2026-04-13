class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int n = a.size(), m = a[0].size(), lo = 0, hi = m * n - 1, mid, r, c;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            r = mid / m, c = mid % m;
            if (a[r][c] == target) {
                return true;
            } else if (a[r][c] > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return false;
    }
};
