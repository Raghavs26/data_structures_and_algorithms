#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int maximumGain(string s, int x, int y) {
        if (x < y) {
            swap(x, y);
            for (char &c : s) {
                if (c == 'a') {
                    c = 'b';
                } else if (c == 'b') {
                    c = 'a';
                }
            }
        }

        auto removePairs = [](string s, char first, char second, int gain) {
            stack<char> st;
            int totalGain = 0;
            for (char c : s) {
                if (!st.empty() && st.top() == first && c == second) {
                    st.pop();
                    totalGain += gain;
                } else {
                    st.push(c);
                }
            }

            string remaining;
            while (!st.empty()) {
                remaining += st.top();
                st.pop();
            }
            reverse(remaining.begin(), remaining.end());
            return make_pair(totalGain, remaining);
        };

        auto res1 = removePairs(s, 'a', 'b', x);
        int totalGain = res1.first;

        auto result2 = removePairs(res1.second, 'b', 'a', y);
        totalGain += result2.first;

        return totalGain;
    }
};