#include <bits/stdc++.h>
using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
   public:
    // Constructor initializes an empty nested list.
    NestedInteger();
    // Constructor initializes a single integer.
    NestedInteger(int value);
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);
    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class Solution {
   public:
    NestedInteger deserialize(string s) {
        if (s[0] != '[') return NestedInteger(stoi(s));
        stack<NestedInteger> st;
        int start = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '[') {
                st.push(NestedInteger());
                start = i + 1;
            } else if (c == ',') {
                if (i > start) {
                    int num = stoi(s.substr(start, i - start));
                    st.top().add(NestedInteger(num));
                }
                start = i + 1;
            } else if (c == ']') {
                if (i > start) {
                    int num = stoi(s.substr(start, i - start));
                    st.top().add(NestedInteger(num));
                }
                NestedInteger cur = st.top();
                st.pop();
                if (!st.empty()) {
                    st.top().add(cur);
                } else {
                    return cur;
                }
                start = i + 1;
            }
        }
        return NestedInteger();
    }
};

int main() {
    return 0;
}