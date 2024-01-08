#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
  int solve(int W, int wt[], int val[], int n, int i, vector<vector<int>> &dp) {
    if (i >= n) {
      return 0;
    }

    if (dp[i][W] == -1) {
      return dp[i][W];
    }
    if (wt[i] > W) {
      int exclude = solve(W, wt, val, n, i + 1, dp);
      dp[i][W] = exclude;
      return exclude;
    } else {
      int include = val[i] + solve(W - wt[i], wt, val, n, i + 1, dp);
      int exclude = solve(W, wt, val, n, i + 1, dp);
      int res = max(include, exclude);
      dp[i][W] = res;
      return dp[i][W];
    }
  }

  int knapSack(int W, int wt[], int val[], int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    int res = solve(W, wt, val, n, 0, dp);
    return res;
  }
};

int main() { return 0; }