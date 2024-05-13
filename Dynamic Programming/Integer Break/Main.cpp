#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   private:
    int helper(int n, int dp[]) {
        if (n == 2)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        int res = INT_MIN;
        for (int i = 1; i < n; i++) {
            res = max(res, i * (n - i));
            res = max(res, i * helper(n - i, dp));
        }
        dp[n] = res;
        return res;
    }

   public:
    int integerBreak(int n) {
        int* dp = new int[n + 1];
        for (int i = 0; i < n + 1; i++) {
            dp[i] = -1;
        }
        return helper(n, dp);
    }
};
int main() {
    return 0;
}
