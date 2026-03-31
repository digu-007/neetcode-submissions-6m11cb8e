class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        int pre[n + 1], mx[n + 1];
        pre[0] = 0, mx[n] = 0;
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + a[i];
        }
        for (int i = n - 1; i >= 0; --i) {
            mx[i] = max(mx[i + 1], a[i]);
        }
        int ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (a[i]) {
                int idx = i, target = mx[i + 1];
                while (i + 1 < n) {
                    if (a[idx] > target) {
                        if (a[i + 1] == target) {
                            ans += (target * (i - idx) - (pre[i + 1] - pre[idx + 1]));
                            break;
                        } else {
                            ++i;
                        }
                    } else {
                        if (a[i + 1] >= a[idx]) {
                            ans += (a[idx] * (i - idx) - (pre[i + 1] - pre[idx + 1]));
                            break;
                        } else {
                            ++i;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
