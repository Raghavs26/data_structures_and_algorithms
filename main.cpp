#include <climits>
#include <unordered_map>
#include <vector>


class Solution {
private:
  // Helper function with memoization
  int solve(int i, int j, vector<vector<int>> &triangle,
            unordered_map<string, int> &memo) {
    // Base case: if we are at the bottom row
    if (i == triangle.size() - 1) {
      return triangle[i][j];
    }

    // Check if the result is already memoized
    string key = to_string(i) + "_" + to_string(j);
    if (memo.find(key) != memo.end()) {
      return memo[key];
    }

    // Recursive cases
    int left = solve(i + 1, j, triangle, memo);
    int right = solve(i + 1, j + 1, triangle, memo);

    // Update the minimum path sum for the current position and memoize the
    // result
    int result = triangle[i][j] + min(left, right);
    memo[key] = result;

    return result;
  }

public:
  int minimumTotal(vector<vector<int>> &triangle) {
    unordered_map<string, int> memo; // Memoization table
    return solve(0, 0, triangle, memo);
  }
};
