#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string clearDigits(string s) {
        string res;
        stack<char> st;
        for (char c : s) {
            if (isdigit(c) && !st.empty()) {
                st.pop();
            } else {
                st.push(c);
            }
        }
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    return 0;
}