#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
    vector<vector<int>> dp;

   private:
    int solve(int i, int count, int w, vector<int> &cost) {
        if (i == cost.size()) {
            if (w == 0) {
                return 0;
            }
            return 1e9;
        }
        if (count > i + 1) {
            return 1e9;
        }
        if (w == 0) {
            return 0;
        }
        if (dp[i][w] != -1) {
            return dp[i][w];
        }
        int include = 1e9;
        if (cost[i] != -1 && i + 1 <= w) {
            include = cost[i] + solve(i, count + 1, w - (i + 1), cost);
        }
        int exclude = solve(i + 1, 0, w, cost);
        return dp[i][w] = min(include, exclude);
    }

   public:
    int minimumCost(int n, int w, vector<int> &cost) {
        dp.resize(n + 1, vector<int>(w + 1, -1));
        return solve(0, 0, w, cost);
    }
};

int main() {
    return 0;
}
