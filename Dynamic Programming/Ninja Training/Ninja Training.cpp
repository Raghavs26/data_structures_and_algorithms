#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int solve(int n, vector<vector<int>> &points, int lastTask,
          unordered_map<string, int> &dp) {
  if (n < 0) {
    return 0;
  }
  string key = to_string(n) + "_" + to_string(lastTask);
  if (dp.find(key) != dp.end()) {
    return dp[key];
  }
  int res = INT_MIN;

  for (int i = 0; i < 3; i++) {
    int point = 0;
    if (lastTask != i) {
      point = points[n][i] + solve(n - 1, points, i, dp);
    }
    res = max(res, point);
    dp[key] = res;
  }
  return dp[key];
}

int ninjaTraining(int n, vector<vector<int>> &points) {
  unordered_map<string, int> dp;
  return solve(n - 1, points, -1, dp);
}

int main() { return 0; }