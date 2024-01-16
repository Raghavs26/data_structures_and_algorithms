#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
  int recur(vector<int> coin, int amount, int index, vector<vector<int>> &dp) {
    if (index < 0 or amount < 0) {
      return INT_MAX;
    }
    if (amount == 0) {
      return 0;
    }
    if (dp[index][amount] != -1) {
      return dp[index][amount];
    }
    if (coin[index] < amount) {
      int exclude = recur(coin, amount, index - 1, dp);
      int include = recur(coin, amount - coin[index], index, dp);
      dp[index][amount] = min(include, exclude);
    } else {
      dp[index][amount] = recur(coin, amount, index - 1, dp);
    }
    return dp[index][amount];
  }
  int coinChange(vector<int> &coins, int amount) {
    vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
    int res = recur(coins, amount, coins.size() - 1, dp);
    return res == INT_MAX ? -1 : res;
  }
};

int main() { return 0; }