class Solution {
public:
    int add(int a, int b) {
        int ans = 0, i = 0;
        bool carry = false;
        for (int i = 0; i < 32; ++i) {
            if ((a & 1) and (b & 1)) {
                if (carry) {
                    ans ^= (1 << i); 
                } else {
                    carry = true;
                }
            } else if (!(a & 1) and !(b & 1)) {
                if (carry) {
                    ans ^= (1 << i);
                    carry = false;
                }
            } else {
                if (!carry) {
                    ans ^= (1 << i);
                    carry = false;
                }
            }
            a >>= 1;
            b >>= 1;
        }
        return ans;
    }

    int getSum(int a, int b) {
        return add(a, b);
    }
};
