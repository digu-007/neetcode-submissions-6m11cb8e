class FreqStack {
public:
    unordered_map<int, int> place;
    vector<stack<int>> stks;

    FreqStack() {}
    
    void push(int val) {
        if (++place[val] > stks.size()) {
            stack<int> stk;
            stk.push(val);
            stks.push_back(stk);
        } else {
            stks[place[val] - 1].push(val);
        }
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