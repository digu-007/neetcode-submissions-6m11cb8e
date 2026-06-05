class Solution {
public:
    int sz, ans;

    void dfs(int queens, vector<int>& j) {
        if (queens == sz) {
            ++ans;
            return;
        }
        vector<bool> possible(sz, true);
        for (int i = 0; i < j.size(); ++i) {
            possible[j[i]] = false;
            int diff = queens - i;
            if (j[i] + diff < sz) possible[j[i] + diff] = false;
            if (j[i] - diff >= 0) possible[j[i] - diff] = false;
        }
        for (int i = 0; i < sz; ++i) {
            if (possible[i]) {
                j.push_back(i);
                dfs(queens + 1, j);
                j.pop_back();
            }
        }
    }

    int totalNQueens(int n) {
        sz = n, ans = 0;
        vector<int> j;
        dfs(0, j);
        return ans;
    }
};