class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(), a.end());
        vector<vector<int>> ans({a[0]});
        for (auto &x: a) {
            int prev = ans.back()[1];
            if (x[0] <= prev) {
                ans.back()[1] = max(prev, x[1]);
            } else {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
