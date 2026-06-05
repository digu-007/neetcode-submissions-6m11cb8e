class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        vector<int> d(n + 1, 0);
        q.push(0);
        while (q.size()) {
            int cur = q.front();
            q.pop();
            for (int i = 1; i * i <= n - cur; ++i) {
                int num = i * i + cur;
                if (!d[num]) {
                    q.push(num);
                    d[num] = 1 + d[cur];
                    cout << num << " " << d[num] << "\n";
                }
            }
        }
        return d[n];
    }
};