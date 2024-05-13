#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
    vector<vector<int>> dp;

   private:
    int solve(string& str, int i, int prev) {
        if (i == str.size()) return 0;

        if (dp[i][prev] != -1) return dp[i][prev];

        int flip = 1e8, notFlip = 1e8;
        if (str[i] == '0') {
            if (prev == 0) {
                flip = 1 + solve(str, i + 1, 1);
                notFlip = solve(str, i + 1, 0);
            } else {
                flip = 1 + solve(str, i + 1, 1);
            }
        } else {
            if (prev == 0) {
                flip = 1 + solve(str, i + 1, 0);
                notFlip = solve(str, i + 1, 1);
            } else {
                notFlip = solve(str, i + 1, 1);
            }
        }
        return dp[i][prev] = min(flip, notFlip);
    }

   public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        dp.resize(n + 1, vector<int>(2, -1));
        return solve(s, 0, 0);
    }
};

int main() {
 return 0;
}
