#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
private:
  void dfs(int x, int y, vector<vector<int>> &grid, int n, int m,
           vector<pair<int, int>> &temp, int fr, int fc) {
    if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == 0) {
      return;
    }
    temp.push_back(
        {x - fr, y - fc}); // store coordinates relative to the starting point
    grid[x][y] = 0;

    dfs(x + 1, y, grid, n, m, temp, fr, fc);
    dfs(x - 1, y, grid, n, m, temp, fr, fc);
    dfs(x, y + 1, grid, n, m, temp, fr, fc);
    dfs(x, y - 1, grid, n, m, temp, fr, fc);
  }

public:
  int countDistinctIslands(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    int res = 0;
    set<vector<pair<int, int>>> st;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1) {
          vector<pair<int, int>> temp;
          dfs(i, j, grid, n, m, temp, i, j);
          st.insert(temp);
        }
      }
    }

    return st.size();
  }
};

int main() { return 0; }