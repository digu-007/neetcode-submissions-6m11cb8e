class Twitter {
public:
    int ctr;
    unordered_map<int, deque<pair<int, int>>> user;
    unordered_map<int, unordered_set<int>> followers;

    Twitter() {
        ctr = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        user[userId].push_back({ctr++, tweetId});
        if (user[userId].size() > 10) user[userId].pop_front();
    }
    
    vector<int> getNewsFeed(int userId) {
        followers[userId].insert(userId);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto &x: followers[userId]) {
            for (int i = user[x].size() - 1; i >= 0; --i) {
                if (pq.size() < 10) {
                    pq.push(user[x][i]);
                } else {
                    if (pq.top().first < user[x][i].first) {
                        pq.pop();
                        pq.push(user[x][i]);
                    } else {
                        break;
                    }
                }
            }
        }
        vector<int> ans;
        while (pq.size()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};
