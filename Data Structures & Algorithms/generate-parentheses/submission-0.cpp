class Solution {
public:
    vector<string> ans;

    void dfs(int open, int close, string cur) {
        if (!open and !close) {
            ans.push_back(cur);
            return;
        }
        if (open > 0) {
            cur += "(";
            dfs(open - 1, close, cur);
            cur.pop_back();
        }
        if (close > open) {
            cur += ")";
            dfs(open, close - 1, cur);
        }
    }

    vector<string> generateParenthesis(int n) {
        dfs(n, n, "");
        return ans;
    }
};
