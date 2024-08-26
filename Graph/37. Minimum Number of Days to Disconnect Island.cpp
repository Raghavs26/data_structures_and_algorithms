#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1 || visited[i][j]) {
            return;
        }
        visited[i][j] = true;
        dfs(grid, i + 1, j, visited);
        dfs(grid, i - 1, j, visited);
        dfs(grid, i, j + 1, visited);
        dfs(grid, i, j - 1, visited);
    }

    int countIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int islands = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    islands++;
                    dfs(grid, i, j, visited);
                }
            }
        }
        return islands;
    }

   public:
    int minDays(vector<vector<int>>& grid) {
        int initialIslands = countIslands(grid);
        if (initialIslands == 0 || initialIslands > 1) return 0;

        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    int tempIslands = countIslands(grid);
                    grid[i][j] = 1;
                    if (tempIslands > 1 || tempIslands == 0) return 1;
                }
            }
        }
        return 2;
    }
};