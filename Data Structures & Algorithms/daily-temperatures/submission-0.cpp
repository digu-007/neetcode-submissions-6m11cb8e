class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        int n = a.size(), cur;
        pair<int, int> rec;
        vector<int> ans(n, 0);
        stack<pair<int, int>> st;
        for (int i = 0; i < n; ++i) {
            cur = a[i];
            while (!st.empty() and cur > st.top().first) {
                rec = st.top();
                st.pop();
                ans[rec.second] = i - rec.second;
            }
            st.push({a[i], i});
        }
        return ans;
    }
};
