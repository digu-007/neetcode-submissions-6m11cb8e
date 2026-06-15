class Solution {
public:
    unordered_map<char, int> val = {
        {'I', 1}, 
        {'V', 5}, 
        {'X', 10}, 
        {'L', 50}, 
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int romanToInt(string s) {
        int n = s.size(), ans = val[s[n - 1]];
        for (int i = 0; i < n - 1; ++i) {
            ans += (val[s[i + 1]] > val[s[i]] ? -val[s[i]] : val[s[i]]);
        }
        return ans;
    }
};