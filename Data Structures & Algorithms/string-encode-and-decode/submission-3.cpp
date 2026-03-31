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
            cout << ans << "\n";
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int ctr = 0;
        cout << s.size() << "\n";
        while (ctr < s.size()) {
            string res = "";
            string temp = "";
            temp += s[ctr];
            temp += s[ctr + 1];
            temp += s[ctr + 2];
            long len = stoi(temp);
            ctr += 3;
            for (int i = 0; i < len; ++i) {
                res += s[ctr + i];
            }
            cout << len << " " << ctr << " " << res << "\n\n";
            ctr += len;
            ans.emplace_back(res);
        }
        return ans;
    }
};
