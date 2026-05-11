class Solution {
public:
    vector<vector<string>> ans;
    int n;

    bool is_palindrome(string& s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }

    void dfs(vector<string> cur, string& s, int i) {
        if (i == n) {
            ans.push_back(cur);
            return;
        }
        for (int idx = i; idx < n; ++idx) {
            if (is_palindrome(s, i, idx)) {
                cur.push_back(s.substr(i, idx - i + 1));
                dfs(cur, s, idx + 1);
                cur.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.size();
        dfs({}, s, 0);
        return ans;
    }
};
