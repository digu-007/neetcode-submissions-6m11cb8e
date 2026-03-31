class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> st;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            st.emplace(nums[i]);
            if (i >= k - 1) {
                ans.push_back(*st.rbegin());
                st.erase(st.find(nums[i - k + 1]));
            }
        }
        return ans;
    }
};
