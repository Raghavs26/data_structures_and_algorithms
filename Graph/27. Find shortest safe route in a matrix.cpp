#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    int print2largest(int arr[], int n) {
        int firstLargest = INT_MIN;
        int secondLargest = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (arr[i] > firstLargest) {
                secondLargest = firstLargest;
                firstLargest = arr[i];
            } else if (firstLargest > arr[i] && arr[i] > secondLargest) {
                secondLargest = arr[i];
            }
        }
        return secondLargest == INT_MIN ? -1 : secondLargest;
    }
};

class Solution {
   public:
    int findShortestPath(vector<vector<int>> &mat) {
        int n = mat.size(), m = mat[0].size();
        queue<pair<int, int>> q;
        vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (mat[row][col] == 0) {
                    mat[row][col] = -1;
                    if (row - 1 >= 0) mat[row - 1][col] = -1;
                    if (row + 1 < n) mat[row + 1][col] = -1;
                    if (col - 1 >= 0) mat[row][col - 1] = -1;
                    if (col + 1 < m) mat[row][col + 1] = -1;
                }
            }
        }

        for (int row = 0; row < n; row++) {
            if (mat[row][0] == 1) {
                q.push({row, 0});
                mat[row][0] = -1;
            }
        }
        int res = 0;
        while (!q.empty()) {
            int size = q.size();
            res += 1;
            for (int i = 0; i < size; i++) {
                int currentRow = q.front().first;
                int currentCol = q.front().second;
                q.pop();
                if (currentCol == m - 1) return res;
                for (auto direction : directions) {
                    int nextRow = currentRow + direction.first;
                    int nextCol = currentCol + direction.second;
                    if (nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= m || mat[nextRow][nextCol] != 1) {
                        continue;
                    }
                    q.push({nextRow, nextCol});
                    mat[nextRow][nextCol] = -1;
                }
            }
        }
        return -1;
    }
};

int main() {
    return 0;
}