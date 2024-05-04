#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int countSubsetSumWaysHelper(vector<int> &arr, int n, int k,
                             unordered_map<string, int> &memo) {
  if (k < 0)
    return 0;
  if (n == 0) {
    return (k == 0) ? 1 : 0;
  }

  string key = to_string(n) + "_" + to_string(k);
  if (memo.find(key) != memo.end()) {
    return memo[key];
  }

  if (arr[n - 1] <= k) {
    int exclude = countSubsetSumWaysHelper(arr, n - 1, k, memo);
    int include = countSubsetSumWaysHelper(arr, n - 1, k - arr[n - 1], memo);
    memo[key] = include + exclude;
  } else {
    memo[key] = countSubsetSumWaysHelper(arr, n - 1, k, memo);
  }

  return memo[key];
}

int findWays(vector<int> &arr, int k) {
  int n = arr.size();
  unordered_map<string, int> memo;
  return countSubsetSumWaysHelper(arr, n, k, memo);
}

int main() { return 0; }