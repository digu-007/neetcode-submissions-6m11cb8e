class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        sort(a.begin(), a.end());
        int prev = -50001, ans = 0;
        for (auto &x: a) {
            if (x[0] < prev) {
                ++ans;
                prev = min(x[1], prev);
            } else {
                prev = x[1];
            }
        }
        return ans;
    }
};
