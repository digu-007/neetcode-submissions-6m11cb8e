class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> cnt;
        for (auto &x: s) {
            ++cnt[x];
        }
        priority_queue<pair<int, char>> pq;
        for (auto &x: cnt) {
            pq.push({x.second, x.first});
        }
        int n = s.size(), max = pq.top().first;
        if (max > (n + 1) / 2) return "";
        string ans = "";
        while (pq.size()) {
            auto cur = pq.top();
            pq.pop();
            if (ans.size() and ans.back() == cur.second) {
                auto sec = pq.top();
                pq.pop();
                ans += sec.second;
                if (--sec.first) pq.push(sec);
                pq.push(cur);
            } else {
                ans += cur.second;
                if (--cur.first) pq.push(cur);
            }
        }
        return ans;
    }
};