class Solution {
public:
    string mul(string& s, int u, int zero) {
        if (!u) return "0";
        int carry = 0;
        string ans = "";
        while (zero) {
            ans.push_back('0');
            --zero;
        }
        for (int i = s.size() - 1; i >= 0; --i) {
            int val = (s[i] - '0') * u + carry;
            ans += to_string(val % 10);
            carry = val / 10;
        }
        if (carry) ans += to_string(carry);
        cout << ans << "\n";
        return ans;
    }

    string multiply(string num1, string num2) {
        if (num2.size() > num1.size()) swap(num1, num2);
        int n = num1.size(), m = num2.size(), mx = 1;
        vector<string> res;
        for (int i = m - 1; i >= 0; --i) {
            res.push_back(mul(num1, (num2[i] - '0'), m - 1 - i));
            mx = max(mx, (int)res.back().size());
        }
        string ans = "";
        cout << mx << "\n";
        int carry = 0, idx = 0;
        while (mx) {
            int val = carry;
            for (int i = 0; i < m; ++i) {
                if (idx < res[i].size()) val += res[i][idx] - '0';
            }
            ans += to_string(val % 10);
            carry = val / 10;
            --mx, ++idx;
        }
        if (carry) ans += to_string(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
