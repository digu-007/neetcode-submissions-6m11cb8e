class Solution {
public:
    vector<vector<int>> ways = {
        {0, 1},
        {-1, 0},
        {1, 0},
        {0, -1}
    };

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> d(n, vector<int>(m, 1e9));
        d[0][0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        while (pq.size()) {
            auto top = pq.top();
            pq.pop();
            int x = top[1], y = top[2];
            if (x == n - 1 and y == m - 1) return d[x][y];
            // if (top.first > d[x][y]) continue;
            for (int i = 0; i < 4; ++i) {
                int dx = x + ways[i][0], dy = y + ways[i][1];
                if (dx >= 0 and dy >= 0 and dx < n and dy < m) {
                    int cur = max(top[0], abs(heights[x][y] - heights[dx][dy]));
                    if (cur < d[dx][dy]) {
                        d[dx][dy] = cur;
                        pq.push({cur, dx, dy});
                    }
                }
            }
        }
        return -1;
    }
};