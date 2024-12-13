#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        int res = 0;

        function<void(int)> dfs = [&](int i) {
            if (i == s.size()) {
                res = max(res, (int)st.size());
                return;
            }

            for (int j = i; j < s.size(); j++) {
                string word = s.substr(i, j - i + 1);
                if (st.find(word) == st.end()) {
                    st.insert(word);
                    dfs(j + 1);
                    st.erase(word);
                }
            }
        };

        dfs(0);
        return res;
    }
};

int main() {
    return 0;
}