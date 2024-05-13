#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
private:
  int solve(int i, int j, vector<vector<int>> &triangle, int n) {
    if (i == n - 1) {
      return triangle[i][j];
    }

    int left =
        (j < triangle[i + 1].size()) ? solve(i + 1, j, triangle, n) : INT_MAX;
    int right = (j < triangle[i + 1].size()) ? solve(i + 1, j + 1, triangle, n)
                                             : INT_MAX;
    return triangle[i][j] + min(left, right);
  }

public:
  int minimumTotal(vector<vector<int>> &triangle) {
    int n = triangle.size(), m = triangle[0].size();
    return solve(0, 0, triangle, n);
  }
};

int main() { return 0; }