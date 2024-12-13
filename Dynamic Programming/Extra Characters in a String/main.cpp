#include <bits/stdc++.h>
using namespace std;

// time complexity: O(2^N)
class Solution {
    vector<int> dp;

   private:
    int solve(string &s, unordered_set<string> &st, int i) {
        if (i >= s.size()) return 0;
        if (dp[i] != -1) return dp[i];
        int res = 1 + solve(s, st, i + 1);
        for (int j = i + 1; j < s.size(); j++) {
            string current = s.substr(i, j - i + 1);
            if (st.find(current) != st.end()) {
                res = min(res, solve(s, st, j + 1));
            }
        }
        return dp[i] = res;
    }

   public:
    int minExtraChar(string s, vector<string> &dictionary) {
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        dp.resize(s.size() + 1, -1);
        return solve(s, st, 0);
    }
};

int main() {
    return 0;
}