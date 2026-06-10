class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& a) {
        sort(a.begin(), a.end());
        vector<int> res(n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        set<int> choose;
        for (int i = 0; i < n; ++i) {
            choose.insert(i);
        }
        for (int i = 0; i < a.size(); ++i) {
            if (!pq.size()) {
                pq.push(make_pair(a[i][1], 0));
                choose.erase(0);
                ++res[0];
            } else {
                if (pq.top().first <= a[i][0]) {
                    while (pq.size() and pq.top().first <= a[i][0]) {
                        choose.insert(pq.top().second);
                        pq.pop();
                    }
                    auto itr = choose.begin();
                    pq.push(make_pair(a[i][1], *itr));
                    ++res[*itr];
                    choose.erase(itr);
                } else {
                    if (pq.size() < n) {
                        auto itr = choose.begin();
                        pq.push(make_pair(a[i][1], *itr));
                        ++res[*itr];
                        choose.erase(itr);
                    } else {
                        auto top = pq.top();
                        pq.pop();
                        pq.push(make_pair(a[i][1] + max(top.first - a[i][0], 0), top.second));
                        ++res[top.second];
                    }
                }    
            }
        }
        int ans = 0, cur = -1;
        for (int i = 0; i < n; ++i) {
            if (res[i] > cur) {
                cur = res[i];
                ans = i;
            }
        }
        return ans;
    }
};