class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> mp;
        for (auto &x: wordList) {
            for (int i = 0; i < x.size(); ++i) {
                string pattern = x.substr(0, i) + "*" + x.substr(i + 1);
                mp[pattern].push_back(x);
            }
        }
        unordered_set<string> vis{beginWord};
        queue<string> q({beginWord});
        int ans = 0;
        while (q.size()) {
            ++ans;
            int sz = q.size();
            while (sz--) {
                string cur = q.front();
                if (cur == endWord) return ans;
                q.pop();
                for (int i = 0; i < cur.size(); ++i) {
                    string pattern = cur.substr(0, i) + "*" + cur.substr(i + 1);
                    for (auto &x: mp[pattern]) {
                        if (!vis.count(x)) {
                            q.push(x);
                            vis.insert(x);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
