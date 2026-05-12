class Solution {
public:
    int n;
    vector<vector<int>> ans;

    void dfs(vector<int>& a, vector<bool>& vis, vector<int> cur) {
        if (cur.size() == n) {
            ans.push_back(cur);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                cur.push_back(a[i]);
                vis[i] = true;
                dfs(a, vis, cur);
                vis[i] = false;
                cur.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<bool> vis(n, false);
        dfs(nums, vis, {});
        return ans;
    }
};
