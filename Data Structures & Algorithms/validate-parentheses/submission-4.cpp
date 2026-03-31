class Solution {
public:
    bool isValid(string s) {
        if (s.size() & 1) return false;
        stack<char> st;
        for (auto &x: s) {
            if (x == '(' or x == '{' or x == '[') {
                st.push(x);
            } else {
                if (st.empty()) return false;
                if (st.top() == '(' and x != ')') return false;
                if (st.top() == '[' and x != ']') return false;
                if (st.top() == '{' and x != '}') return false;
                st.pop();
            }
        }
        if (st.size()) return false;
        return true;
    }
};
