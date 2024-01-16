#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
private:
  void dfs(int x, int y, vector<vector<char>> &mat, int n, int m) {
    if (x < 0 || y < 0 || x >= n || y >= m || mat[x][y] != 'O') {
      return;
    }
    mat[x][y] = '#';
    dfs(x + 1, y, mat, n, m);
    dfs(x - 1, y, mat, n, m);
    dfs(x, y + 1, mat, n, m);
    dfs(x, y - 1, mat, n, m);
  }

public:
  vector<vector<char>> fill(int n, int m, vector<vector<char>> mat) {
    for (int row = 0; row < n; row++) {
      int col = 0;
      if (mat[row][col] == 'O') {
        dfs(row, col, mat, n, m);
      }
      col = m - 1;
      if (mat[row][col] == 'O') {
        dfs(row, col, mat, n, m);
      }
    }
    for (int col = 0; col < m; col++) {
      int row = 0;
      if (mat[row][col] == 'O') {
        dfs(row, col, mat, n, m);
      }
      row = n - 1;
      if (mat[row][col] == 'O') {
        dfs(row, col, mat, n, m);
      }
    }
    for (int row = 0; row < n; row++) {
      for (int col = 0; col < m; col++) {
        if (mat[row][col] == '#') {
          mat[row][col] = 'O';
        } else if (mat[row][col] == 'O') {
          mat[row][col] = 'X';
        }
      }
    }
    return mat;
  }
};

int main() { return 0; }