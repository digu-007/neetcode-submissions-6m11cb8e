class FreqStack {
public:
    unordered_map<int, int> place;
    vector<stack<int>> stks;

    FreqStack() {}
    
    void push(int val) {
        int cur = ++place[val];
        if (cur > stks.size()) {
            stack<int> stk;
            stks.push_back(stk);
        }
        stks[cur - 1].push(val);
    }
    
    int pop() {
        int ans = stks.back().top();
        stks.back().pop();
        if (stks.back().empty()) stks.pop_back();
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