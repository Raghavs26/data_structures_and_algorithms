#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
  int solve(int W, int wt[], int val[], int n, int i) {
    if (i >= n) {
      return 0;
    }

    if (wt[i] > W) {
      int exclude = solve(W, wt, val, n, i + 1);
      return exclude;
    } else {
      int include = val[i] + solve(W - wt[i], wt, val, n, i + 1);
      int exclude = solve(W, wt, val, n, i + 1);
      return max(include, exclude);
    }
  }

  int knapSack(int W, int wt[], int val[], int n) {
    int res = solve(W, wt, val, n, 0);
    return res;
  }
};

int main() { return 0; }