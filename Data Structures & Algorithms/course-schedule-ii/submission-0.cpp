class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& color, vector<int>& ans) {
        color[node] = 1;
        for (auto &x: graph[node]) {
            if (!color[x]) {
                if (dfs(x, graph, color, ans)) {
                    return true;
                }
            } else if (color[x] == 1) {
                return true;
            }
        }
        color[node] = 2;
        ans.push_back(node);
        return false;
    }

    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> graph(n);
        vector<int> color(n, 0), ans;
        for (auto &x: pre) {
            graph[x[0]].push_back(x[1]);
        }
        for (int i = 0; i < n; ++i) {
            if (!color[i]) {
                bool cycle = dfs(i, graph, color, ans);
                if (cycle) return {};
            }
        }
        return ans;
    }
};
