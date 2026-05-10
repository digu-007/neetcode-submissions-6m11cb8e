class Solution {
public:
    bool overlap(vector<int> a, vector<int> b) {
        if (a[0] > b[0]) swap(a, b);
        return (b[0] <= a[1]);
    }

    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) {
        vector<vector<int>> ans;
        int n = a.size();
        bool fill = false;
        for (int i = 0; i < n; ++i) {
            if (overlap(a[i], b)) {
                int lo = min(a[i][0], b[0]), hi = max(a[i][1], b[1]);
                while (i + 1 < n and overlap(a[i + 1], b)) {
                    ++i;
                    hi = max(hi, a[i][1]);
                }
                ans.push_back({lo, hi});
                fill ^= 1;
            } else {
                if (!fill and b[1] < a[i][0]) {
                    if (!i or (a[i - 1][1] < b[0])) {
                        ans.push_back(b);
                        fill ^= 1;
                    }
                }
                ans.push_back(a[i]);
            }
        }
        if (!fill) ans.push_back(b);
        return ans;
    }
};
