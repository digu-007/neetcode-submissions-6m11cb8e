class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> last;
        int n = s.size(), r, len;
        for (int i = 0; i < n; ++i) {
            last[s[i]] = i;
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            r = last[s[i]];
            len = 1;
            while (i < r) {
                ++i, ++len;
                r = max(r, last[s[i]]);
            }
            ans.emplace_back(len);
        }
        return ans;
    }
};
