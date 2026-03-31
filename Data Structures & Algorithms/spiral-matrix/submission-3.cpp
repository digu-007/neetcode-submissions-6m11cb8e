class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), loop = 0;
        vector<int> ans;
        for (int j = 0; j < m; ++j) {
            ans.emplace_back(matrix[0][j]);
        }
        int res = n * m;
        while (true) {
            if (ans.size() == res) return ans;
            for (int i = 1 + loop; i < n - loop; ++i) {
                ans.emplace_back(matrix[i][m - 1 - loop]);
            }
            if (ans.size() == res) return ans;
            for (int j = m - 2 - loop; j >= loop; --j) {
                ans.emplace_back(matrix[n - 1 - loop][j]);
            }
            if (ans.size() == res) return ans;
            for (int i = n - 2 - loop; i >= 1 + loop; --i) {
                ans.emplace_back(matrix[i][loop]);
            }
            if (ans.size() == res) return ans;
            for (int j = 1 + loop; j < m - 1 - loop; ++j) {
                ans.emplace_back(matrix[1 + loop][j]);
            }
            ++loop;
        }
        return ans;
    }
};
