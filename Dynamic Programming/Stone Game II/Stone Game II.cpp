#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<vector<int>>> dp;

   private:
    int solve(int player, vector<int>& piles, int i, int M) {
        if (i >= piles.size()) return 0;
        if (dp[player][i][M] != -1) return dp[player][i][M];
        int res = player == 0 ? INT_MIN : INT_MAX;
        int stones = 0;
        for (int j = 1; j <= min(2 * M, (int)piles.size() - i); j++) {
            stones += piles[i + j - 1];
            if (player == 0) {
                res = max(res, stones + solve(1, piles, i + j, max(M, j)));
            } else {
                res = min(res, solve(0, piles, i + j, max(M, j)));
            }
        }
        return dp[player][i][M] = res;
    }

   public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        dp.resize(2, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
        return solve(0, piles, 0, 1);
    }
};
int main() {
    return 0;
}