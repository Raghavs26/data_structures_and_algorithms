#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
private:
  int solve(int i, int j, vector<vector<int>> &grid, int n, int m,
            vector<vector<int>> &dp) {
    if (i >= n or j >= m) {
      return INT16_MAX;
    }
    if (i == n - 1 and j == m - 1) {
      return grid[i][j];
    }
    if (dp[i][j] != INT_MAX) {
      return dp[i][j];
    }
    int left = grid[i][j] + solve(i + 1, j, grid, n, m, dp);
    int right = grid[i][j] + solve(i, j + 1, grid, n, m, dp);
    return dp[i][j] = min(left, right);
  }

public:
  int minPathSum(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
    return solve(0, 0, grid, n, m, dp);
  }
};

int main() { return 0; }