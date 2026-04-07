class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize) return false;
        map<int,int> mp;
        for (auto &x: hand) {
            ++mp[x];
        }
        for (auto &x: mp) {
            if (x.second > 0) {
                for (int i = 1; i < groupSize; ++i) {
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
