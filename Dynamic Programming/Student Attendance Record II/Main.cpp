#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
    vector<vector<vector<int>>> dp;
    const int MOD = 1e9 + 7;

   private:
    int solve(int n, int s, int a, int l) {
        if (a >= 2) {
            return 0;
        }
        if (l >= 3) {
            return 0;
        }
        if (s == n) {
            return 1;
        }
        if (dp[s][a][l] != -1) {
            return dp[s][a][l] % MOD;
        }
        int count = 0;
        count = (count + solve(n, s + 1, a, 0)) % MOD;
        count = (count + solve(n, s + 1, a + 1, 0)) % MOD;
        count = (count + solve(n, s + 1, a, l + 1)) % MOD;

        dp[s][a][l] = count % MOD;
        return count % MOD;
    }

   public:
    int checkRecord(int n) {
        dp.resize(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(n, 0, 0, 0);
    }
};

int main() {
    return 0;
}
