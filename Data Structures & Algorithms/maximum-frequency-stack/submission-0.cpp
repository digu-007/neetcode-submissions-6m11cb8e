class FreqStack {
public:
    int mx;
    unordered_map<int, int> place;
    unordered_map<int, stack<int>> mp;

    FreqStack() {
        mx = 0;
    }
    
    void push(int val) {
        mp[++place[val]].push(val);
        if (mp[place[val]].size() == 1) ++mx;
    }
    
    int pop() {
        int ans = mp[mx].top();
        mp[mx].pop();
        if (mp[mx].empty()) --mx;
        --place[ans];
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */