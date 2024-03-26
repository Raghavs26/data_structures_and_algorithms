#include <bits/stdc++.h>

#include <iostream>

using namespace std;

// Expected Time Complexity: O(n * m)

// Expected Space Complexity: O(n * m)

class Solution {
   private:
    void dfs(int x, int y, vector<vector<int>> &grid) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() ||
            grid[x][y] == 0) {
            return;
        }
        grid[x][y] = 0;
        dfs(x + 1, y, grid);
        dfs(x - 1, y, grid);
        dfs(x, y + 1, grid);
        dfs(x, y - 1, grid);
    }

   public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        int enclaves = 0;
        for (int row = 0; row < n; row++) {
            int col = 0;
            if (grid[row][col] == 1) {
                dfs(row, col, grid);
            }
            col = m - 1;
            if (grid[row][col] == 1) {
                dfs(row, col, grid);
            }
        }
        for (int col = 0; col < m; col++) {
            int row = 0;
            if (grid[row][col] == 1) {
                dfs(row, col, grid);
            }
            row = n - 1;
            if (grid[row][col] == 1) {
                dfs(row, col, grid);
            }
        }
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col] == 1) {
                    enclaves += 1;
                }
            }
        }
        return enclaves;
    }
};

int main() { return 0; }