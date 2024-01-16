#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> res(n, vector<int>(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1) {
          q.push({i, j});
          grid[i][j] = 0;
          visited[i][j] = true;
        }
      }
    }
    while (!q.empty()) {
      int row = q.front().first;
      int col = q.front().second;
      q.pop();
      for (auto direction : directions) {
        int newRow = row + direction.first;
        int newCol = col + direction.second;
        if (newRow < 0 || newCol < 0 || newRow >= n || newCol >= m ||
            visited[newRow][newCol]) {
          continue;
        }
        q.push({newRow, newCol});
        visited[newRow][newCol] = true;
        grid[newRow][newCol] = grid[row][col] + 1;
      }
    }
    return grid;
  }
} vector<vector<int>> nearest(vector<vector<int>> grid) {
  int n = grid.size(), m = grid[0].size();
  vector<vector<int>> res(n, vector<int>(m, 0));
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
  queue<pair<int, int>> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 1) {
        q.push({i, j});
        grid[i][j] = 0;
        visited[i][j] = true;
      }
    }
  }
  while (!q.empty()) {
    int row = q.front().first;
    int col = q.front().second;
    q.pop();
    for (auto direction : directions) {
      int newRow = row + direction.first;
      int newCol = col + direction.second;
      if (newRow < 0 || newCol < 0 || newRow >= n || newCol >= m ||
          visited[newRow][newCol]) {
        continue;
      }
      q.push({newRow, newCol});
      visited[newRow][newCol] = true;
      grid[newRow][newCol] = grid[row][col] + 1;
    }
  }
  return grid;
}
;

int main() {
  vector<vector<int>> grid = {{0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 1, 1}};
  Solution s;
  auto res = s.nearest(grid);
  for (auto i : res) {
    for (int j : i) {
      cout << j << " ";
    }
    cout << "\n";
  }
  return 0;
}