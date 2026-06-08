class Solution {
public:
    int firstMissingPositive(vector<int>& a) {
        int n = a.size(), i = 0;
        while (i < n) {
            if (a[i] <= 0 or a[i] > n) {
                ++i;
                continue;
            }
            int next = a[i] - 1;
            if (a[i] != a[next]) {
                swap(a[i], a[next]);
            } else {
                ++i;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};