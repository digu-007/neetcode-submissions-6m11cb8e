class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<short>,short> mp;
        vector<vector<string>> ans;
        short cnt = 0;
        vector<short> cur(26, 0);
        for (auto &s: strs) {
            for (auto &ch: s) {
                ++cur[ch - 'a'];
            }
            if (mp.count(cur)) {
                ans[mp[cur]].emplace_back(s);
            } else {
                mp[cur] = cnt++;
                vector<string> temp = {s};
                ans.emplace_back(temp);
            }
            for (auto &ch: s) {
                --cur[ch - 'a'];
            }
        }
        return ans;
    }
};
