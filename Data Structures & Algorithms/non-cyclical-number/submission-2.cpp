class Solution {
public:
    unordered_set<int> vis;
    
    int calc(int n) {
        int next = 0;
        while (n) {
            next += (n % 10) * (n % 10);
            n /= 10;
        }
        return next;
    }

    bool isHappy(int n) {
        int slow = n, fast = calc(n);
        while (slow != fast) {
            slow = calc(slow);
            fast = calc(calc(fast));
        }
        return (fast == 1);
    }
};
