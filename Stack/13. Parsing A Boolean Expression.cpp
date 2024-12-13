#include <bits/stdc++.h>
using namespace std;

#include <stack>
#include <string>
#include <vector>
using namespace std;

// time complexity : O(N)
class Solution {
   public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for (char c : expression) {
            if (c != ')' && c != ',') {
                st.push(c);
            } else if (c == ')') {
                vector<char> temp;
                while (!st.empty() && st.top() != '(') {
                    temp.push_back(st.top());
                    st.pop();
                }

                st.pop();

                if (!st.empty()) {
                    char op = st.top();
                    st.pop();
                    bool ans;
                    if (op == '&') {
                        ans = true;
                        for (char ch : temp) {
                            ans &= (ch == 't');
                        }
                    } else if (op == '|') {
                        ans = false;
                        for (char ch : temp) {
                            ans |= (ch == 't');
                        }
                    } else if (op == '!') {
                        ans = (temp[0] == 'f');
                    }

                    st.push(ans ? 't' : 'f');
                }
            }
        }
        return st.top() == 't';
    }
};

int main() {
    return 0;
}