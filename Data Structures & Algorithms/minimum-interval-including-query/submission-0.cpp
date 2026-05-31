class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& a, vector<int>& queries) {
        vector<vector<int>> points;
        for (int i = 0; i < a.size(); ++i) {
            points.push_back({a[i][0], 0, i});
            points.push_back({a[i][1], 2, i});
        }
        int n = queries.size();
        for (int i = 0; i < n; ++i) {
            points.push_back({queries[i], 1, i});
        }
        sort(points.begin(), points.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans(n, -1);
        vector<bool> done(n, false);
        for (auto &x: points) {
            if (!x[1]) {
                pq.push({a[x[2]][1] - a[x[2]][0], x[2]});
            } else if (x[1] == 2) {
                done[x[2]] = true;
            } else {
                while (pq.size() and done[pq.top().second]) {
                    pq.pop();
                }
                if (pq.size()) {
                    ans[x[2]] = pq.top().first + 1;
                }
            }

        }
        return ans;
    }
};
