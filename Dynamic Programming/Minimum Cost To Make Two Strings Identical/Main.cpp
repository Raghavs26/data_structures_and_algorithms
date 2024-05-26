#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
    vector<vector<int>> dp;

   private:
    int lcs(string &x, string &y, int i, int j) {
        if (i >= x.size() || j >= y.size()) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (x[i] == y[j]) {
            return dp[i][j] = 1 + lcs(x, y, i + 1, j + 1);
        }
        return dp[i][j] = max(lcs(x, y, i + 1, j), lcs(x, y, i, j + 1));
    }

   public:
    int findMinCost(string x, string y, int costX, int costY) {
        dp.resize(x.size() + 1, vector<int>(y.size() + 1, -1));
        int len = lcs(x, y, 0, 0);
        int c1 = (x.size() - len) * costX;
        int c2 = (y.size() - len) * costY;
        return c1 + c2;
    }
};

int main() {
    return 0;
}
