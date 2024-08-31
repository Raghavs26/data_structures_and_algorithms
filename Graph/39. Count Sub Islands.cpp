#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    bool checkSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        if (i < 0 || i >= grid1.size() || j < 0 || j >= grid1[0].size()) return true;
        if (grid2[i][j] != 1) return true;
        grid2[i][j] = -1;

        bool res = grid1[i][j] == 1;
        res &= checkSubIslands(grid1, grid2, i + 1, j);
        res &= checkSubIslands(grid1, grid2, i - 1, j);
        res &= checkSubIslands(grid1, grid2, i, j + 1);
        res &= checkSubIslands(grid1, grid2, i, j - 1);
        return res;
    }

   public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();
        int islands = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == 1 && checkSubIslands(grid1, grid2, i, j)) {
                    islands++;
                }
            }
        }
        return islands;
    }
};

int main() {
    return 0;
}