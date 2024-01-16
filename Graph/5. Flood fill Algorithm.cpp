#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
  void dfs(vector<vector<int>> &image, int currentRow, int currentColumn,
           int newColor, int originalColor) {
    if (currentRow < 0 || currentColumn < 0 || currentRow >= image.size() ||
        currentColumn >= image[0].size() ||
        image[currentRow][currentColumn] != originalColor) {
      return;
    }

    image[currentRow][currentColumn] = newColor;
    dfs(image, currentRow - 1, currentColumn, newColor, originalColor);
    dfs(image, currentRow + 1, currentColumn, newColor, originalColor);
    dfs(image, currentRow, currentColumn - 1, newColor, originalColor);
    dfs(image, currentRow, currentColumn + 1, newColor, originalColor);
  }

  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int newColor) {
    int originalColor = image[sr][sc];
    if (newColor == originalColor) {
      return image;
    }
    dfs(image, sr, sc, newColor, originalColor);
    return image;
  }
};

int main() { return 0; }