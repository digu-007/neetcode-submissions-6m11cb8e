class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for (auto &x: strs) {
            int ptr = 0;
            for (int i = 0; i < min(ans.size(), x.size()); ++i, ++ptr) {
                if (ans[i] != x[i]) break;
            }
            while (ans.size() > ptr) ans.pop_back();
        }
        return ans;
    }
};