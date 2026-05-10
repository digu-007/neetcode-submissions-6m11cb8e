class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        sort(a.begin(), a.end());
        int prev = -50001, ans = 0;
        for (auto &x: a) {
            if (x[0] < prev) {
                ++ans;
                if (x[1] < prev) prev = x[1];
            } else {
                prev = x[1];
            }
        }
        return ans;
    }
};
