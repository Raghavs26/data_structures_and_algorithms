#include <bits/stdc++.h>
#include <iostream>

using namespace std;



class Solution {
public:
  bool checkforAsterisk(string p, int m) {
    for (int i = 0; i <= m; i++) {
      if (p[i] != '*') {
        return false;
      }
    }
    return true;
  }
  bool solve(string s, string p, int n, int m, vector<vector<int>> &dp) {
    if (dp[n][m] != -1) {
      return dp[n][m];
    }
    if (n < 0 && m < 0) {
      return true;
    }
    if (m < 0 and n >= 0) {
      return false;
    }
    if (n < 0 and m >= 0) {
      while (m >= 0) {
        if (p[m] == '*') {
          m--;
        } else {
          return dp[n][m] = false;
        }
      }
      return dp[n][m] = true;
    }
    if (s[n] == p[m] || p[m] == '?') {
      return dp[n][m] = solve(s, p, n - 1, m - 1, dp);
    }
    if (p[m] == '*') {
      bool excludeAsterisk = solve(s, p, n, m - 1, dp);
      bool includeAsterisk = solve(s, p, n - 1, m, dp);
      return dp[n][m] = includeAsterisk || excludeAsterisk;
    }
    return false;
  }
  bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return solve(s, p, n - 1, m - 1, dp);
  }
};

int main() { return 0; }