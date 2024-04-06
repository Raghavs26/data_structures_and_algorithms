#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    string makeGood(string s) {
        stack<char> st;
        for (char ch : s) {
            if (!st.empty() && abs(st.top() - ch) == 32) {
                st.pop();
            } else {
                st.push(ch);
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

int main() {
    return 0;
}