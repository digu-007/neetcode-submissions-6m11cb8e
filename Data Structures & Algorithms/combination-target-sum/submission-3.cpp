class Solution {
public:
    vector<vector<int>> ans;

    void dfs(vector<int>& a, int& target, vector<int> cur, int sum, int idx) {
        if (sum == target) {
            ans.push_back(cur);
            return;
        }
        for (int i = idx; i < a.size(); ++i) {
            if (sum + a[i] > target) return;
            cur.push_back(a[i]);
            dfs(a, target, cur, sum + a[i], i);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& a, int target) {
        sort(a.begin(), a.end());
        dfs(a, target, {}, 0, 0);
        return ans;
    }
};
