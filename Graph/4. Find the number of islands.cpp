#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
  void bfs(int x, int y, vector<vector<bool>> &visited,
           vector<vector<char>> &grid) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    vector<pair<int, int>> directions{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                      {0, 1},   {1, -1}, {1, 0},  {1, 1}};
    while (!q.empty()) {
      int row = q.front().first;
      int col = q.front().second;
      q.pop();
      visited[row][col] = true;
      for (pair<int, int> direction : directions) {
        int newRow = row + direction.first;
        int newCol = col + direction.second;
        if (newRow >= 0 && newRow < grid.size() && newCol >= 0 &&
            newCol < grid[0].size() && grid[newRow][newCol] == '1' &&
            !visited[newRow][newCol]) {
          q.push({newRow, newCol});
        }
      }
    };

    int numIslands(vector<vector<char>> & grid) {
      int res = 0;
      int n = grid.size(), m = grid[0].size();
      vector<vector<bool>> visited(n, vector<bool>(m, false));
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (grid[i][j] == '1' and !visited[i][j]) {
            res++;
            bfs(i, j, visited, grid);
          }
        }
      }
      return res;
    }
  }
};

int main() { return 0; }