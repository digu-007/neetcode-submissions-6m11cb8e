class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> p;
        for (int i = 0; i < n; ++i) {
            p.push_back({capital[i], profits[i]});
        }
        sort(p.begin(), p.end());
        priority_queue<int> pq;
        int idx = 0;
        while (k > 0) {
            while (idx < n) {
                if (p[idx].first <= w) {
                    pq.push(p[idx++].second);
                } else {
                    break;
                }
            }
            if (!pq.size()) return w;
            w += pq.top();
            pq.pop();
            --k;
        }
        return w;
    }
};