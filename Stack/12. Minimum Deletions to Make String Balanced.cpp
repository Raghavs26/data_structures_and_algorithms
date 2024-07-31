#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minimumDeletions(string s) {
        int res = 0;
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' && !st.empty() && st.top() == 'b') {
                st.pop();
                res++;
            } else {
                st.push(s[i]);
            }
        }
        return res;
    }
};

int main() {
    return 0;
}