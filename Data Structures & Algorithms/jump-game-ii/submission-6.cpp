class Solution {
public:
    int jump(vector<int>& a) {
        int n = a.size(), ans = 0, cur = 0, jump, mx, next, i = 0;
        while (i < n) {
            if (i == n - 1) return ans;
            ++ans;
            jump = a[cur];
            mx = 0;
            while (i + 1 < n and jump > 0) {
                ++i, --jump;
                if (a[i] + cur - i >= mx) {
                    mx = a[i] + cur - i;
                    next = i;
                }
            }
            cur = next;
        }
        return ans;
    }
};
