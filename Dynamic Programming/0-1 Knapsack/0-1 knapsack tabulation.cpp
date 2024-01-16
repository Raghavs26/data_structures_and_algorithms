#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
  int knapSack(int W, int wt[], int val[], int n) {
    int dp[n + 1][W + 1];
    for (int i = 0; i < n + 1; i++) {
      dp[i][0] = 0;
    }
    for (int i = 0; i < W + 1; i++) {
      dp[0][i] = 0;
    }
    // we can also 2d vector directly initialise it to 0
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= W; j++) {
        if (wt[i - 1] <= j) {
          dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    return dp[n][W];
  }
};

int main() { return 0; }