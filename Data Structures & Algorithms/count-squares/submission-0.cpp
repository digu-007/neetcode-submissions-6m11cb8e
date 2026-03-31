class CountSquares {
public:
    vector<int> y_points[1001];
    map<pair<int,int>,int> cnt;
    CountSquares() {}
    
    void add(vector<int> point) {
        ++cnt[{point[0], point[1]}];
        y_points[point[1]].emplace_back(point[0]);
    }
    
    int count(vector<int> point) {
        int ans = 0;
        for (auto &x: y_points[point[1]]) {
            if (x == point[0]) continue;
            int len = abs(x - point[0]);
            int y1 = point[1] - len, y2 = point[1] + len;
            ans += cnt[{point[0], y1}] * cnt[{x, y1}];
            ans += cnt[{point[0], y2}] * cnt[{x, y2}];
        }
        return ans;
    }
};
