#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        vector<vector<int>> efforts(rows, vector<int>(columns, INT_MAX));
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        efforts[0][0] = 0;

        while (!pq.empty()) {
            int effort = pq.top()[0];
            int row = pq.top()[1];
            int col = pq.top()[2];
            pq.pop();
            if (row == rows - 1 && col == columns - 1) {
                return effort;
            }
            for (auto direction : directions) {
                int nextRow = row + direction.first;
                int nextCol = col + direction.second;
                if (nextRow < 0 || nextRow >= rows || nextCol < 0 || nextCol >= columns) {
                    continue;
                }
                int newEffort = max(effort, abs(heights[row][col] - heights[nextRow][nextCol]));
                if (newEffort < efforts[nextRow][nextCol]) {
                    efforts[nextRow][nextCol] = newEffort;
                    pq.push({newEffort, nextRow, nextCol});
                }
            }
        }
        return -1;
    }
};

int main() {
    return 0;
}