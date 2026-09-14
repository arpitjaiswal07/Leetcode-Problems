class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for (string c : operations) {
            if (c == "C") {
                st.pop();
            }
            else if (c == "D") {
                st.push(st.top() * 2);
            }
            else if (c == "+") {
                int last = st.top();
                st.pop();

                int secondLast = st.top();

                st.push(last);
                st.push(last + secondLast);
            }
            else {
                st.push(stoi(c));
            }
        }

        int total = 0;

        while (!st.empty()) {
            total += st.top();
            st.pop();
        }

        return total;
    }
};
