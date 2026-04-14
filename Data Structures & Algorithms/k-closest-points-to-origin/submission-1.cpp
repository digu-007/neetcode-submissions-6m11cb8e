class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int cur, mx;
        priority_queue<vector<int>> pq;
        for (auto &x: points) {
            cur = x[0] * x[0] + x[1] * x[1];
            pq.push({cur, x[0], x[1]});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        vector<int> f;
        while (pq.size()) {
            f = pq.top();
            ans.push_back({f[1], f[2]});
            pq.pop();
        }
        return ans;
    }
};
