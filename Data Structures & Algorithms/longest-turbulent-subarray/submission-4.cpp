class Solution {
public:
    bool check(int l, int i, vector<int>& a) {
        if ((i - l) & 1) {
            if (a[i + 1] >= a[i]) return false;
        } else {
            if (a[i + 1] <= a[i]) return false;
        }
        return true;
    }

    int maxTurbulenceSize(vector<int>& a) {
        int n = a.size(), ans = 1;
        for (int i = 0; i < n - 1; ++i) {
            int l = i;
            while (i + 1 < n and check(l, i, a)) {
                ++i;
            }
            ans = max(ans, i - l + 1);
            if (i > l) --i;
        }
        for (int i = 0; i < n - 1; ++i) {
            int l = i;
            while (i + 1 < n and check(l - 1, i, a)) {
                ++i;
            }
            ans = max(ans, i - l + 1);
            if (i > l) --i;
        }
        return ans;
    }
};