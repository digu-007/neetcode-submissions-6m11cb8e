class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        set<int> st = {a[0]};
        for (int i = 1; i < a.size(); ++i) {
            if (*st.rbegin() < a[i]) {
                st.emplace(a[i]);
                continue;
            }
            auto itr = st.lower_bound(a[i]);
            st.erase(itr);
            st.emplace(a[i]);
        }
        return int(st.size());
    }
};
