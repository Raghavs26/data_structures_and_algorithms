
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
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    return solve(arr, sum, n, dp);
  }
};

int main() { return 0; }