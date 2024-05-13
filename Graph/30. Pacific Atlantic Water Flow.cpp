#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   private:
    bool isValid(int r, int c, vector<vector<int>>& heights) {
        return r >= 0 && c >= 0 && r < heights.size() && c < heights[0].size();
    }

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int prevHeight, int r, int c) {
        if (!isValid(r, c, heights) || visited[r][c] || heights[r][c] < prevHeight)
            return;
        visited[r][c] = true;
        dfs(heights, visited, heights[r][c], r + 1, c);
        dfs(heights, visited, heights[r][c], r - 1, c);
        dfs(heights, visited, heights[r][c], r, c + 1);
        dfs(heights, visited, heights[r][c], r, c - 1);
    }

   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;

        int rows = heights.size(), cols = heights[0].size();
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++) {
            dfs(heights, pacific, INT_MIN, i, 0);
            dfs(heights, atlantic, INT_MIN, i, cols - 1);
        }

        for (int i = 0; i < cols; i++) {
            dfs(heights, pacific, INT_MIN, 0, i);
            dfs(heights, atlantic, INT_MIN, rows - 1, i);
        }
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
