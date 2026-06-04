class Solution {
public:
    long long minEnd(int n, int x) {
        // 10110: 10110 10111
        // 10011: 10 11
        // 10: 11
        // 11: 10011
        --n;
        bitset<35> bits(n);
        long long ans = x, i = 0, ctr = 0;
        while (ctr < 35) {
            if (!(x & 1)) {
                bool bit = bits[ctr++];
                if (bit) ans += ((long long)1 << i);

            }
            x >>= 1;
            ++i;
        }
        return ans;
    }
};