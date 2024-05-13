#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> efforts(n, vector<int>(m, INT_MAX));
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        efforts[0][0] = 0;

        while (!pq.empty()) {
            int effort = pq.top()[0];
            int row = pq.top()[1];
            int col = pq.top()[2];
            pq.pop();
            if (row == n - 1 && col == m - 1) {
                return effort;
            }
            for (auto direction : directions) {
                int nextRow = row + direction.first;
                int nextCol = col + direction.second;
                if (nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= m) {
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