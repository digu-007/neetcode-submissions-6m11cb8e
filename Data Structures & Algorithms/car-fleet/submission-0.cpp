class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> v;
        int n = speed.size();
        for (int i = 0; i < n; ++i) {
            v.push_back({position[i], speed[i]});
        }
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        int ans = 0;
        pair<int, int> lead;
        for (int i = 0; i < n; ++i) {
            ++ans;
            lead = v[i];
            while (i + 1 < n) {
                if ((target - lead.first) * v[i + 1].second >= (target - v[i + 1].first) * lead.second) {
                    ++i;
                } else {
                    break;
                }
            }
        }
        return ans;
    }
};
