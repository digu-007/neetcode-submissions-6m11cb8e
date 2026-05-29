class Solution {
public:
    unordered_map<string, vector<string>> g;
    vector<string> ans;

    void dfs(string u) {
        while (g[u].size()) {
            string v = g[u].back();
            g[u].pop_back();
            dfs(v);
        }
        ans.push_back(u);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        for (auto &x: tickets) {
            g[x[0]].push_back(x[1]);
        }
        for (auto &x: g) {
            sort(x.second.rbegin(), x.second.rend());
        }
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
