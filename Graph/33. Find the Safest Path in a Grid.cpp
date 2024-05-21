#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
    vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

   private:
    bool isPossible(vector<vector<int>>& distance, int safeDistance) {
        queue<pair<int, int>> q;
        int n = distance.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        q.push({0, 0});
        visited[0][0] = true;

        if (distance[0][0] < safeDistance)
            return false;

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            if (x == n - 1 && y == n - 1) {
                return true;
            }

            for (auto direction : directions) {
                int nx = x + direction.first;
                int ny = y + direction.second;

                if (nx >= 0 && nx < n && ny >= 0 && ny < n && visited[nx][ny] != true) {
                    if (distance[nx][ny] < safeDistance) {
                        continue;
                    }
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
        return false;
    }

   public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    distance[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (auto direction : directions) {
                    int nx = x + direction.first;
                    int ny = y + direction.second;
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m || distance[nx][ny] <= distance[x][y] + 1) {
                        continue;
                    }
                    distance[nx][ny] = distance[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        int left = 0, right = n + m;
        int res = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(distance, mid)) {
                res = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}