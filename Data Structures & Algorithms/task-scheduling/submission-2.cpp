class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // A * * A * * A -> 3 + 2 * (3 - 1)
        // A B * A B * A B -> 3 * 2 + 1 * (3 - 1)
        int cnt[26] = {}, mx = 0, freq = 0;
        for (auto &x: tasks) {
            ++cnt[x - 'A'];
            if (cnt[x - 'A'] > mx) {
                mx = cnt[x - 'A'];
                freq = 1;
            } else if (cnt[x - 'A'] == mx) {
                ++freq;
            }
        }
        return max((int)tasks.size(), mx * freq + (n - freq + 1) * (mx - 1));
    }
};
