class Solution {
public:
    vector<vector<int>> g;
    vector<int> vis;

    bool dfs(int u) {
        vis[u] = 1;
        for (auto &x: g[u]) {
            if (!vis[x]) {
                if (!dfs(x)) {
                    return false;
                }
            } else if (vis[x] == 1) {
                return false;
            }
        }
        vis[u] = 2;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        g.resize(numCourses, vector<int>());
        for (auto &x: prerequisites) {
            g[x[0]].push_back(x[1]);
        }
        vis.resize(numCourses, 0);
        for (int i = 0; i < numCourses; ++i) {
            if (!vis[i] and !dfs(i)) return false;
        }
        return true;
    }
};
