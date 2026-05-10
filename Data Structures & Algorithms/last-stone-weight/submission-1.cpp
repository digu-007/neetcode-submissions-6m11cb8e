class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<short> pq;
        for (auto &x: stones) {
            pq.push(x);
        }
        while (pq.size() > 1) {
            short f = pq.top();
            pq.pop();
            short s = pq.top();
            pq.pop();
            if (f != s) {
                pq.push(f - s);
            }
        }
        return (pq.empty() ? 0 : pq.top());
    }
};
