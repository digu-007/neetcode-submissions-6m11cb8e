class DSU {
vector<int> p, sz;
int n;

public:
    DSU(int n) {
        for (int i = 0; i < n; ++i) {
            p.push_back(i);
            sz.push_back(1);
        }
    }

    int find(int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        if (sz[v] > sz[u]) swap(u, v);
        p[v] = u;
        sz[u] += sz[v];
        return true;
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& a) {
        int max = *max_element(a.begin(), a.end());
        vector<bool> is_prime(max + 1, true);
        for (int i = 2; i * i <= max; ++i) {
            if (is_prime[i]) {
                for (int j = i * i; j <= max; j += i) {
                    is_prime[j] = false;
                }
            }
        }
        int n = a.size();
        DSU dsu(n);
        int cnt = 1;
        for (int j = 2; j <= max; ++j) {
            if (!is_prime[j]) continue;
            int f = -1;
            for (int i = 0; i < n; ++i) {
                if (a[i] % j) continue;
                if (f == -1) {
                    f = i;
                } else {
                    if (dsu.unite(f, i)) ++cnt;
                }
            }
        }
        return (cnt == n);
    }
};