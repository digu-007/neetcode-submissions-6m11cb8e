class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool first = false, second = false, third = false;
        for (auto &x: triplets) {
            if (x[0] > target[0] or x[1] > target[1] or x[2] > target[2]) continue;
            first |= (x[0] == target[0]);
            second |= (x[1] == target[1]);
            third |= (x[2] == target[2]);
        }
        return (first & second & third);
    }
};
