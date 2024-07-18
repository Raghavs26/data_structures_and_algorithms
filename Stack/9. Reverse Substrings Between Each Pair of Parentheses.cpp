#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string reverseParentheses(string s) {
        stack<char> st;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == ')') {
                string temp;
                while (!st.empty() && st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }
                if (!st.empty() && st.top() == '(') st.pop();
                for (char c : temp) st.push(c);
            } else {
                st.push(s[i]);
            }
        }
        string res;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};