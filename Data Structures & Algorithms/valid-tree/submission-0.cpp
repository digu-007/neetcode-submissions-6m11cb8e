class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& graph, vector<int>& color) {
        color[node] = 1;
        for (auto &x: graph[node]) {
            if (!color[x]) {
                if (dfs(x, node, graph, color)) {
                    return true;
                }
            } else if (x != parent and color[x] == 1) {
                return true;
            }
        }
        color[node] = 2;
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> color(n, 0), ans;
        for (auto &x: edges) {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        if (dfs(0, -1, graph, color)) {
            return false;
        }
        for (int i = 1; i < n; ++i) {
            if (!color[i]) return false;
        }
        return true;
    }
};
