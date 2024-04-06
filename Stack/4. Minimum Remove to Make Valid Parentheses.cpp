#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        string res;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop();
                } else {
                    s[i] = '!';
                }
            }
        }
        while (!st.empty()) {
            int ci = st.top();
            s[ci] = '!';
            st.pop();
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '!') {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};

int main() {
    return 0;
}