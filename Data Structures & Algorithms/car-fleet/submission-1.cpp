class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<short, short>> v;
        short n = speed.size();
        for (short i = 0; i < n; ++i) {
            v.push_back({position[i], speed[i]});
        }
        sort(v.begin(), v.end(), greater<pair<short, short>>());
        short ans = 0;
        pair<short, short> lead;
        for (short i = 0; i < n; ++i) {
            ++ans;
            lead = v[i];
            while (i + 1 < n) {
                if ((int)(target - lead.first) * v[i + 1].second >= (int)(target - v[i + 1].first) * lead.second) {
                    ++i;
                } else {
                    break;
                }
            }
        }
        return ans;
    }
};
