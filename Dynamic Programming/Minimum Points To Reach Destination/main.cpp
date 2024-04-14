#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
    vector<vector<int>> dp;

    int solve(int x, int y, int m, int n, vector<vector<int>>& points) {
        if (x == m - 1 && y == n - 1) {
            return max(1, 1 - points[x][y]);
        }

        if (x >= m || y >= n) {
            return INT_MAX;
        }

        if (dp[x][y] != -1) {
            return dp[x][y];
        }

        int left = solve(x + 1, y, m, n, points);
        int down = solve(x, y + 1, m, n, points);

        int pointsNeeded = min(left, down) - points[x][y];

        dp[x][y] = max(1, pointsNeeded);

        return dp[x][y];
    }

   public:
    int minPoints(int m, int n, vector<vector<int>>& points) {
        dp.resize(m + 1, vector<int>(n + 1, -1));

        return solve(0, 0, m, n, points);
    }
};

int main() {
    return 0;
}