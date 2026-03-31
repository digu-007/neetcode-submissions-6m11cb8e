class MinStack {
public:
    long min;
    stack<long> stk;
    
    MinStack() {
        
    }
    
    void push(int val) {
        if (stk.empty()) {
            min = val;
            stk.push(0);
        } else {
            stk.push(val - min);
            if (val < min) min = val;
        }
    }
    
    void pop() {
        long top = stk.top();
        stk.pop();
        if (top < 0) min = min - top;
    }
    
    int top() {
        long top = stk.top();
        if (top < 0) {
            return min;
        }
        return min + top;
    }
    
    int getMin() {
        return min;
    }
};
