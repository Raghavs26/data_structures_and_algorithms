#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
  bool solve(vector<int> arr, int sum, int n, vector<vector<int>> dp) {
    if (n == 0 || sum < 0) {
      return false;
    }
    if (sum == 0) {
      return true;
    }
    if (dp[n][sum] != -1) {
      return dp[n][sum];
    }
    if (arr[n - 1] <= sum) {
      bool include = solve(arr, sum - arr[n - 1], n - 1, dp);
      bool exclude = solve(arr, sum, n - 1, dp);
      return dp[n][sum] = include || exclude;
    } else {
      return dp[n][sum] = solve(arr, sum, n - 1, dp);
    }
  }
  bool isSubsetSum(vector<int> arr, int sum) {
    int n = arr.size();
    vector<vector<int>> dp1(n + 1, vector<int>(sum + 1, -1));
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    for (int i = 0; i < sum + 1; i++) {
      dp[0][i] = true;
    }
    for (int i = 1; i < n + 1; i++) {
      for (int j = 1; j < sum + 1; i++) {
        if (arr[i - 1] <= j) {
          dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    return solve(arr, sum, n, dp1);
  }
};

int main() { return 0; }
