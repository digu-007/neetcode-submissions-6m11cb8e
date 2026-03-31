class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& a) {
        int cnt_r[9] = {0};
        int cnt_c[9] = {0};
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (a[i][j] != '.' and cnt_r[a[i][j] - '1']++) return false;
                if (a[j][i] != '.' and cnt_c[a[j][i] - '1']++) return false;
            }
            fill(cnt_r, cnt_r + 9, 0);
            fill(cnt_c, cnt_c + 9, 0);
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                for (int x = 0; x < 3; ++x) {
                    for (int y = 0; y < 3; ++y) {
                        if (a[i + x][j + y] != '.' and cnt_r[a[i + x][j + y] - '1']++) return false;
                    }
                }
                fill(cnt_r, cnt_r + 9, 0);
            }
        }
        return true;
    }
};
