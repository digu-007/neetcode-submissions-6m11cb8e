class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<pair<int, int>> p;
        for (int i = 0; i < n; ++i) {
            p.push_back(make_pair(ratings[i], i));
        }
        sort(p.begin(), p.end());
        vector<int> ans(n, 1);
        for (auto &x: p) {
            int i = x.second;
            if (i > 0 and x.first > ratings[i - 1]) ans[i] = ans[i - 1] + 1; 
            if (i < n - 1 and x.first > ratings[i + 1]) ans[i] = max(ans[i], ans[i + 1] + 1); 
        }
        return accumulate(ans.begin(), ans.end(), 0);
    }
};