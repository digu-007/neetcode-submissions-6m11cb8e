class DSU {
public:
    vector<int> p, sz;

    DSU(int n) {
        for (int i = 0; i < n; ++i) {
            p.push_back(i);
            sz.push_back(1);
        }
    }

    int find(int u) {
        if (u == p[u]) return u;
        return p[u] = find(p[u]);
    }

    bool union_sets(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        p[v] = u;
        return true;
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for (auto &x: edges) {
            if (!dsu.union_sets(x[0], x[1])) return false;
        }
        return (dsu.sz[dsu.find(0)] == n);
    }
};
