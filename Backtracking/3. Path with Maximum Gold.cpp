#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   private:
    int solve(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) {
            return 0;
        }
        int temp = grid[i][j];
        grid[i][j] = 0;
        int a = temp + solve(grid, i + 1, j);
        int b = temp + solve(grid, i - 1, j);
        int c = temp + solve(grid, i, j + 1);
        int d = temp + solve(grid, i, j - 1);
        grid[i][j] = temp;
        return max({a, b, c, d});
    }

   public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) continue;
                res = max(res, solve(grid, i, j));
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
