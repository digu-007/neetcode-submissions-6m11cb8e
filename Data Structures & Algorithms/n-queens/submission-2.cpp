class Solution {
public:
    int sz;
    vector<vector<string>> ans;

    void dfs(int queens, vector<int>& j, vector<string>& grid) {
        if (queens == sz) {
            ans.push_back(grid);
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
                grid[queens][i] = 'Q';
                dfs(queens + 1, j, grid);
                grid[queens][i] = '.';
                j.pop_back();
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        sz = n;
        vector<string> grid(sz, "");
        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < sz; ++j) {
                grid[i] += '.';
            }
        }
        vector<int> j;
        dfs(0, j, grid);
        return ans;
    }
};
