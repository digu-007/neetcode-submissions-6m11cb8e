class Solution {
public:
    vector<string> ans;

    void dfs(int open, int close, int delta, string cur) {
        if (!open and !close) {
            ans.push_back(cur);
            return;
        }
        if (open > 0) {
            cur += "(";
            dfs(open - 1, close, delta + 1, cur);
            cur.pop_back();
        }
        if (close > 0 and delta > 0) {
            cur += ")";
            dfs(open, close - 1, delta - 1, cur);
        }
    }

    vector<string> generateParenthesis(int n) {
        dfs(n, n, 0, "");
        return ans;
    }
};
