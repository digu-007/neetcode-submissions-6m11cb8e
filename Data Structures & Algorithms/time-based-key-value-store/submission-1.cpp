class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!mp.count(key)) {
            return "";
        }
        auto &cur = mp[key];
        pair<int, string> p = {timestamp + 1, ""};
        auto itr = lower_bound(cur.begin(), cur.end(), p);
        if (itr == cur.begin()) {
            return "";
        }
        --itr;
        return itr -> second;
    }
};
