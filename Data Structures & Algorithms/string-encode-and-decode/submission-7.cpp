class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for (auto &x: strs) {
            int cur = x.length();
            string pref = "";
            if (cur > 99) {
                pref += to_string(cur);
            } else if (cur > 9) {
                pref += ("0" + to_string(cur));
            } else if (cur) {
               pref += ("00" + to_string(cur)); 
            } else {
                pref += "000";
            }
            ans += (pref + x);
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int n = s.size(), ctr = 0;
        while (ctr < n) {
            int len = (s[ctr] - '0') * 100 + (s[ctr + 1] - '0') * 10 + s[ctr + 2] - '0';
            ctr += 3;
            ans.emplace_back(s.substr(ctr, len));
            ctr += len;
        }
        return ans;
    }
};
