class DSU {
public:
    vector<int> p, sz;

    DSU(int n) {
        for (int i = 0; i < n; ++i) {
            p.push_back(i);
            sz.push_back(1);
        }
    }

    int find_set(int u) {
        if (u == p[u]) return u;
        return p[u] = find_set(p[u]);
    }

    bool union_sets(int u, int v) {
        u = find_set(u), v = find_set(v);
        if (u == v) return true;
        if (sz[v] > sz[u]) swap(u, v);
        sz[u] += sz[v];
        p[v] = p[u];
        return false;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& p) {
        int n = p.size();
        vector<vector<int>> e;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dist = abs(p[i][0] - p[j][0]) + abs(p[i][1] - p[j][1]);
                e.push_back({dist, i, j});
            }
        }
        sort(e.begin(), e.end());
        int ans = 0;
        DSU dsu(n);
        for (int i = 0; i < e.size(); ++i) {
            if (!dsu.union_sets(e[i][1], e[i][2])) ans += e[i][0];
        }
        return ans;
    }
};
