class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), loop = 0;
        vector<int> ans;
        for (int j = 0; j < m; ++j) {
            ans.emplace_back(matrix[0][j]);
            matrix[0][j] = -111;
        }
        int res = n * m;
        while (true) {
            if (ans.size() == res) return ans;
            for (int i = 1 + loop; i < n - loop; ++i) {
                ans.emplace_back(matrix[i][m - 1 - loop]);
                matrix[i][m - 1 - loop] = -111;
                cout << i << " " << m - 1 - loop << "\n";
            }
            if (ans.size() == res) return ans;
            for (int j = m - 2 - loop; j >= loop; --j) {
                ans.emplace_back(matrix[n - 1 - loop][j]);
                matrix[n - 1 - loop][j] = -111;
                cout << n - 1 - loop << " " << j << "\n";
            }
            if (ans.size() == res) return ans;
            for (int i = n - 2 - loop; i >= 1 + loop; --i) {
                ans.emplace_back(matrix[i][loop]);
                matrix[i][loop] = -111;
                cout << i << " " << loop << "\n";
            }
            if (ans.size() == res) return ans;
            for (int j = 1 + loop; j < m - 1 - loop; ++j) {
                ans.emplace_back(matrix[1 + loop][j]);
                matrix[1 + loop][j] = -111;
                cout << loop + 1 << " " << j << "\n";
            }
            for (auto &x: ans) {
                cout << x << " ";
            }
            ++loop;
        }
        return ans;
    }
};
