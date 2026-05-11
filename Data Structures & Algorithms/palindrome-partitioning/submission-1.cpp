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

    void dfs(vector<string> cur, string& s, int i, int j) {
        if (j == n) {
            if (i == n) ans.push_back(cur);
            return;
        }
        if (is_palindrome(s, i, j)) {
            cur.push_back(s.substr(i, j - i + 1));
            dfs(cur, s, j + 1, j + 1);
            cur.pop_back();
        }
        dfs(cur, s, i, j + 1);
    }

    vector<vector<string>> partition(string s) {
        n = s.size();
        dfs({}, s, 0, 0);
        return ans;
    }
};
