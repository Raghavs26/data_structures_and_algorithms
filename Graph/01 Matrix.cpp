#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct Cell {
  int row, col, steps;
};

class Solution {
public:
  vector<vector<int>> nearest(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> res(n, vector<int>(m, 0));
    vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1) {
          q.push({{i, j}, 0});
          grid[i][j] = -1;
        }
      }
    }

    while (!q.empty()) {
      auto current = q.front();
      q.pop();

      int row = current.first.first;
      int col = current.first.second;
      int steps = current.second;

      res[row][col] = steps;

      for (auto direction : directions) {
        int newRow = row + direction.first;
        int newCol = col + direction.second;

        if (newRow >= 0 && newCol >= 0 && newRow < n && newCol < m &&
            grid[newRow][newCol] == 0) {
          grid[newRow][newCol] = -1;
          q.push({{newRow, newCol}, steps + 1});
        }
      }
    }

    return res;
  }
};

int main() { return 0; }