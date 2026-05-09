class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, bool> mp;
        for (auto &x: wordList) {
            mp[x] = true;
        }
        queue<string> q({beginWord});
        int ans = 0;
        while (q.size()) {
            ++ans;
            int sz = q.size();
            while (sz--) {
                string cur = q.front();
                cout << cur << "\n";
                if (cur == endWord) return ans;
                q.pop();
                for (auto &x: cur) {
                    char ch = x;
                    for (int i = 0; i < 26; ++i) {
                        if (i == (ch - 'a')) continue;
                        x = char('a' + i);
                        if (mp.count(cur) and mp[cur]) {
                            q.push(cur);
                            mp[cur] = false;
                        }
                    }
                    x = ch;
                }
            }
        }
        return 0;
    }
};
