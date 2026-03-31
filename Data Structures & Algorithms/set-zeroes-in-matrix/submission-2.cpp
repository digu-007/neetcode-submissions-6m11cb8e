class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        bool r = false, c = false;
        for (int i = 0; i < n; ++i) {
            if (!a[i][0]) r = true;
        }
        for (int j = 0; j < m; ++j) {
            if (!a[0][j]) c = true;
        }
        for (int i = 1; i < n; ++i) {
            bool zero = false;
            for (int j = 1; j < m; ++j) {
                if (!a[i][j]) {
                    zero = true;
                    break;
                }
            }
            if (zero) a[i][0] = 0;
        }
        for (int j = 1; j < m; ++j) {
            bool zero = false;
            for (int i = 0; i < n; ++i) {
                if (!a[i][j]) {
                    zero = true;
                    break;
                }
            }
            if (zero) {
                for (int i = 0; i < n; ++i) {
                    a[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < n; ++i) {
            if (!a[i][0]) {
                for (int j = 1; j < m; ++j) {
                    a[i][j] = 0;
                }
            }
        }
        if (r) {
            for (int i = 0; i < n; ++i) {
                a[i][0] = 0;
            }
        }
        if (c) {
            for (int j = 0; j < m; ++j) {
                a[0][j] = 0;
            }
        }
    }
};
