class Solution {
public:
    vector<vector<int>> ans;

    void dfs(vector<int>& a, vector<int> cur, int idx) {
        if (idx == a.size()) {
            ans.push_back(cur);
            return;
        }
        cur.push_back(a[idx]);
        dfs(a, cur, idx + 1);
        cur.pop_back();
        while (idx + 1 < a.size() and a[idx] == a[idx + 1]) ++idx;
        dfs(a, cur, idx + 1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, {}, 0);
        return ans;
    }
};
