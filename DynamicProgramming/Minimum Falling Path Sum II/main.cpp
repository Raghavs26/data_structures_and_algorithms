#include <bits/stdc++.h>

#include <iostream>
using namespace std;

// optimised bottomup
class Solution {
   public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n + 1, vector<int>(n, INT_MAX));
        int firstMinColIdx = -1;
        int secondMinColIdx = -1;

        for (int col = 0; col < n; col++) {
            dp[n - 1][col] = grid[n - 1][col];
            if (firstMinColIdx == -1 || dp[n - 1][col] <= dp[n - 1][firstMinColIdx]) {
                secondMinColIdx = firstMinColIdx;
                firstMinColIdx = col;
            } else if (secondMinColIdx == -1 || dp[n - 1][col] <= dp[n - 1][secondMinColIdx]) {
                secondMinColIdx = col;
            }
        }

        for (int row = n - 2; row >= 0; row--) {
            int curMinColIdx1 = -1, curMinColIdx2 = -1;
            for (int col = 0; col < n; col++) {
                if (col != firstMinColIdx) {
                    dp[row][col] = grid[row][col] + dp[row + 1][firstMinColIdx];
                } else {
                    dp[row][col] = grid[row][col] + dp[row + 1][secondMinColIdx];
                }
                if (curMinColIdx1 == -1 || dp[row][col] <= dp[row][curMinColIdx1]) {
                    curMinColIdx2 = curMinColIdx1;
                    curMinColIdx1 = col;
                } else if (curMinColIdx2 == -1 || dp[row][col] <= dp[row][curMinColIdx2]) {
                    curMinColIdx2 = col;
                }
            }
            firstMinColIdx = curMinColIdx1;
            secondMinColIdx = curMinColIdx2;
        }

        return *min_element(dp[0].begin(), dp[0].end());
    }
};

// memoization O(N^3)
class Solution {
    vector<vector<int>> dp;

   private:
    int solve(int i, int j, vector<vector<int>>& grid) {
        if (i == grid.size() - 1) return grid[i][j];

        if (dp[i][j] != -1) return dp[i][j];

        int minPath = 1e8;
        for (int k = 0; k < grid[0].size(); k++) {
            if (k != j) {
                minPath = min(minPath, grid[i][j] + solve(i + 1, k, grid));
            }
        }
        return dp[i][j] = minPath;
    }

   public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int res = INT_MAX;
        int n = grid.size();
        dp.resize(n + 1, vector<int>(n + 1, -1));
        for (int i = 0; i < grid.size(); i++) {
            res = min(res, solve(0, i, grid));
        }
        return res;
    }
};

int main() {
    return 0;
}