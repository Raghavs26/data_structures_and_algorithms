#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    void dfs(vector<vector<int>>& matrix, int x, int y) {
        if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size() || matrix[x][y] != 0) {
            return;
        }
        matrix[x][y] = 1;
        dfs(matrix, x + 1, y);
        dfs(matrix, x - 1, y);
        dfs(matrix, x, y + 1);
        dfs(matrix, x, y - 1);
    }

   public:
    int regionsBySlashes(vector<string>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> matrix(rows * 3, vector<int>(cols * 3, 0));
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == '/') {
                    matrix[row * 3][col * 3 + 2] = 1;
                    matrix[row * 3 + 1][col * 3 + 1] = 1;
                    matrix[row * 3 + 2][col * 3] = 1;
                } else if (grid[row][col] == '\\') {
                    matrix[row * 3][col * 3] = 1;
                    matrix[row * 3 + 1][col * 3 + 1] = 1;
                    matrix[row * 3 + 2][col * 3 + 2] = 1;
                } else {
                    continue;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    res++;
                    dfs(matrix, i, j);
                }
            }
        }
        return res;
    }
};

int main() {
    return 0;
}