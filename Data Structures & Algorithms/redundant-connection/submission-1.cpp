class DSU {
public:
    vector<int> p, sz;
    
    DSU(int n) {
        p.resize(n + 1);
        sz.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            p[i] = i, sz[i] = 1;
        }
    }

    int find_set(int u) {
        if (p[u] == u) return u;
        return p[u] = find_set(p[u]);
    }

    bool union_set(int u, int v) {
        u = find_set(u);
        v = find_set(v);
        if (u == v) return true;
        if (sz[u] < sz[v]) swap(u, v);
        p[v] = u;
        sz[u] += sz[v];
        return false;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size());
        for (auto &x: edges) {
            if (dsu.union_set(x[0], x[1])) return {x[0], x[1]};
        }
        return {};
    }
};
