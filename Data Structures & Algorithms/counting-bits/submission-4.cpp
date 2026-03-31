class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        int cur = 0;
        cout << (1 << 2) << "\n";
        for (int i = 1; i <= n; ++i) {
            if (i == (1 << (cur + 1))) ++cur;
            cout << i << " " << (1 << cur) << "\n";
            ans[i] = 1 + ans[i - (1 << cur)];
        }
        return ans;
    }
};
