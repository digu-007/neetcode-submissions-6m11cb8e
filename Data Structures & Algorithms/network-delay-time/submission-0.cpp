class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> d(n + 1, 1e6);
        d[k] = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (auto &x: times) {
                if (d[x[1]] > d[x[0]] + x[2]) d[x[1]] = d[x[0]] + x[2];
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, d[i]);
        }
        return (ans == 1e6 ? -1 : ans);
    }
};
