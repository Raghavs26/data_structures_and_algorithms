#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
    vector<vector<int>> dp;

   private:
    bool solve(int i, string& s, int n, int open) {
        if (i == n) {
            if (open == 0) return true;
            return false;
        }
        if (dp[i][open] != -1) {
            return dp[i][open];
        }

        bool res = false;
        if (s[i] == '*') {
            res |= solve(i + 1, s, n, open + 1);
            if (open > 0) {
                res |= solve(i + 1, s, n, open - 1);
            }
            res |= solve(i + 1, s, n, open);
        } else {
            if (s[i] == '(') {
                res |= solve(i + 1, s, n, open + 1);
            } else if (s[i] == ')' && open > 0) {
                res |= solve(i + 1, s, n, open - 1);
            }
        }
        return dp[i][open] = res;
    }

   public:
    bool checkValidString(string s) {
        int n = s.size();
        dp.resize(n + 1, vector<int>(n + 1, -1));
        return solve(0, s, n, 0);
    }
};

int main() {
    return 0;
}