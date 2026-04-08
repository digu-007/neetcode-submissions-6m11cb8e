class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), ans, cur = -1, pref = 0;
        for (int i = n - 1; i >= 0; --i) {
            pref += (gas[i] - cost[i]);
            if (pref > cur) cur = pref, ans = i;
        }
        if (pref < 0) return -1;
        return ans;
    }
};
