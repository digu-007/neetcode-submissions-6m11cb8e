class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last[26] = {};
        int n = s.size(), r, len;
        for (int i = 0; i < n; ++i) {
            last[s[i] - 'a'] = i;
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            r = last[s[i] - 'a'];
            len = 1;
            while (i < r) {
                ++i, ++len;
                r = max(r, last[s[i] - 'a']);
            }
            ans.emplace_back(len);
        }
        return ans;
    }
};
