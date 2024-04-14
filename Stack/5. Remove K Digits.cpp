
#include <bits/stdc++.h>

#include <iostream>
using namespace std;



class Solution {
   public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        string res;
        int n = num.size();
        for (char ch : num) {
            while (!st.empty() && st.top() > ch && k > 0) {
                st.pop();
                k--;
            }
            st.push(ch);
        }
        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }

        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        int i = 0;
        while (i < res.size() && res[i] == '0') {
            i++;
        }
        if (i == res.size()) return "0";
        return res.substr(i);
    }
};

int main() {
    return 0;
}