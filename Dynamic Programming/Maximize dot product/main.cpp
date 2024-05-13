#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
    vector<vector<int>> dp;

   private:
    int solve(int n, int m, int a[], int b[]) {
        if (m == 0) {
            return 0;
        }

        if (m > n) {
            return INT_MIN;
        }
        if (dp[n][m] != -1) return dp[n][m];

        int include = a[n - 1] * b[m - 1] + solve(n - 1, m - 1, a, b);
        int exclude = solve(n - 1, m, a, b);

        return dp[n][m] = max(include, exclude);
    }

   public:
    int maxDotProduct(int n, int m, int a[], int b[]) {
        dp.resize(n + 1, vector<int>(m + 1, -1));
        return solve(n, m, a, b);
    }
};

int main() {
    return 0;
}