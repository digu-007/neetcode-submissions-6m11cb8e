class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for (auto &x: operations) {
            if (x == "+") {
                int f = st.top();
                st.pop();
                int s = st.top();
                st.push(f);
                st.push(f + s);
            } else if (x == "C") {
                st.pop();
            } else if (x == "D") {
                st.push(st.top() * 2);
            } else {
                st.push(stoi(x));
            }
        }
        int ans = 0;
        while (st.size()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};