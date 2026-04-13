class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int f, s;
        for (auto &x: tokens) {
            if (x == "+" or x == "-" or x == "*" or x == "/") {
                s = st.top();
                st.pop();
                f = st.top();
                st.pop();
                if (x == "+") {
                    st.push(f + s);
                } else if (x == "-") {
                    st.push(f - s);
                } else if (x == "*") {
                    st.push(f * s);
                } else {
                    st.push(f / s);
                }
            } else {
                st.push(stoi(x));
            }
        }
        return st.top();
    }
};
