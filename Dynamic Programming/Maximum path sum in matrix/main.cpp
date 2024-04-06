#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
    vector<vector<int>> dp;

   private:
    int solve(int i, int j, vector<vector<int>> &grid, int n) {
        if (i >= n or j >= n) {
            return -1e8;
        }
        if (i == n - 1 and j == n - 1) {
            return grid[i][j];
        }
        if (dp[i][j] != INT_MIN) {
            return dp[i][j];
        }
        int left = grid[i][j] + solve(i + 1, j, grid, n);
        int right = (j > 0) ? grid[i][j] + solve(i + 1, j - 1, grid, n) : INT_MIN;
        int down = (j < n - 1) ? grid[i][j] + solve(i + 1, j + 1, grid, n) : INT_MIN;
        return dp[i][j] = max({left, right, down});
    }

   public:
    int maximumPath(int n, vector<vector<int>> matrix) {
        dp.resize(n + 1, vector<int>(n + 1, INT_MIN));
        int res = INT_MIN;
        for (int i = 0; i < n; i++) {
            int tempAns = solve(i, 0, matrix, n);
            res = max(res, tempAns);
        }
        return res;
    }
};

int main() {
    return 0;
}