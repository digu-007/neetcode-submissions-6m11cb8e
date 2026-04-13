class Solution {
public:
    int findMin(vector<int> &a) {
        int lo = 0, hi = a.size() - 1, mid, ans = a[0];
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (a[hi] > a[lo]) {
                hi = mid - 1;
                ans = min(ans, a[lo]);
            } else {
                if (a[mid] > a[hi]) {
                    lo = mid + 1;
                    ans = min(ans, a[hi]);
                } else {
                    hi = mid - 1;
                    ans = min(ans, a[mid]);
                }
            }
        }
        return ans;
    }
};
