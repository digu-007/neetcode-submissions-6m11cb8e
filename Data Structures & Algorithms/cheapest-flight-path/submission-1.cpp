class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> d(n, INT_MAX / 2);
        d[src] = 0;
        for (int i = 0; i <= k; ++i) {
            vector<int> temp = d;
            for (auto &x: flights) {
                if (d[x[0]] + x[2] < temp[x[1]]) temp[x[1]] = x[2] + d[x[0]];
            }
            d = temp;
        }
        return d[dst] != INT_MAX / 2 ? d[dst] : -1;
    }
};
