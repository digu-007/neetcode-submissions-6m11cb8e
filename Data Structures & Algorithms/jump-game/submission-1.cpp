class Solution {
public:
    bool canJump(vector<int>& a) {
        int n = a.size(), i = 0, jump, cur = 0, next, mx;
        while (i < n) {
            jump = a[cur];
            cout << cur << " " << i << " : ";
            if (jump + cur >= n - 1) return true;
            if (!jump) return false;
            mx = 0;
            while (i + 1 < n and jump > 0) {
                ++i, --jump;
                cout << mx << " ";
                if (a[i] + i - cur >= mx) {
                    mx = a[i] + i - cur;
                    next = i;
                }
            }
            cout << "\n";
            cur = next;
        }
        return false;
    }
};
