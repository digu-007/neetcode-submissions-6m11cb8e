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
            string res = "";
            string temp = s.substr(ctr, 3);
            int len = stoi(temp);
            ctr += 3;
            for (int i = 0; i < len; ++i) {
                res += s[ctr + i];
            }
            ctr += len;
            ans.emplace_back(res);
        }
        return ans;
    }
};
