class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize) return false;
        map<short,short> mp;
        for (auto &x: hand) {
            ++mp[x];
        }
        for (auto &x: mp) {
            if (x.second > 0) {
                for (short i = 1; i < groupSize; ++i) {
                    if (mp[i + x.first] < x.second) {
                        return false;
                    } else {
                        mp[i + x.first] -= x.second;
                    }
                }
            }
        }
        return true;
    }
};
