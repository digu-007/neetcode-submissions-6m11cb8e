class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        int n = a.size(), cur, idx;
        vector<int> right(n, 0), left(n, 0);
        stack<pair<int, int>> st;
        for (int i = 0; i < n; ++i) {
            left[i] = i + 1;
            cur = a[i];
            while (!st.empty() and st.top().first > cur) {
                idx = st.top().second;
                st.pop();
                right[idx] = i - idx;
            }
            st.push({a[i], i});
        }
        while (!st.empty()) st.pop();
        int ans = 0;
        for (int i = n - 1, j = 1; i >= 0; --i, ++j) {
            if (!right[i]) right[i] = j;
            cur = a[i];
            while (!st.empty() and st.top().first > cur) {
                idx = st.top().second;
                st.pop();
                left[idx] = idx - i;
            }
            st.push({a[i], i});
        }
        for (int i = 0; i < n; ++i) ans = max(ans, a[i] * (right[i] + left[i] - 1));
        return ans;
    }
};
