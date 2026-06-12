class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // 11000011011111100100110011
        // 11000011001010010010000000
        // 11000011001010111110000000
        int ans = 0;
        for (int i = 31; i >= 0; --i) {
            int cur = (1 << i);
            if ((left & cur) != (right & cur)) break;
            if (left & cur) ans += cur;
        }
        return ans;
    }
};