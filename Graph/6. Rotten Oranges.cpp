#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
  int orangesRotting(vector<vector<int>> &grid) {
    int fresh = 0;
    int n = grid.size(), m = grid[0].size();
    vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    queue<vector<int>> q;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1) {
          fresh++;
        } else if (grid[i][j] == 2) {
          q.push({i, j, 0});
        }
      }
    }
    int time = 0;
    int rottenOranges = 0;
    while (!q.empty()) {

      int row = q.front()[0];
      int col = q.front()[1];
      int currentTime = q.front()[2];
      q.pop();
      time = max(time, currentTime);
      for (auto direction : directions) {
        int newRow = row + direction.first;
        int newCol = col + direction.second;
        int newTime = currentTime + 1;
        if (newRow < 0 or newRow >= n or newCol < 0 or newCol >= m or
            grid[newRow][newCol] == 0 or grid[newRow][newCol] == 2) {
          continue;
        }
        q.push({newRow, newCol, newTime});
        grid[newRow][newCol] = 2;
        fresh--;
      }
    }
    return fresh == 0 ? time : -1;
  }
};

int main() { return 0; }