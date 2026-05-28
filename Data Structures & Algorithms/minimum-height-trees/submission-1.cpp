class Solution {
public:
    vector<vector<int>> g;
    vector<int> p;

    pair<int, int> dfs(int node) {
        int cur = node, max = 0;
        for (auto &x: g[node]) {
            if (p[x] == -1) {
                p[x] = node;
                pair<int, int> res = dfs(x);
                if (res.second + 1 > max) {
                    max = res.second + 1;
                    cur = res.first;
                }
            }
        }
        return {cur, max};
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        g.resize(n);
        p.resize(n, -1);
        for (auto &x: edges) {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        p[0] = 0;
        int farthest = dfs(0).first;
        fill(p.begin(), p.end(), -1);
        p[farthest] = 0;
        int other = dfs(farthest).first;
        vector<int> res = {other};
        while (other != farthest) {
            other = p[other];
            res.push_back(other);
        }
        int sz = res.size();
        if (sz & 1) {
            return {res[sz / 2]};
        }
        return {res[sz / 2], res[sz / 2 - 1]};
    }
};