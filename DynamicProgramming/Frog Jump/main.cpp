#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
private:
  int robHelper(vector<int> &nums, int start, int end,
                unordered_map<string, int> &dp) {
    if (start > end) {
      return 0;
    }

    string key = to_string(start) + "_" + to_string(end);
    if (dp.find(key) != dp.end()) {
      return dp[key];
    }

    int robCurrent = nums[start] + robHelper(nums, start + 2, end, dp);
    int skipCurrent = robHelper(nums, start + 1, end, dp);
    dp[key] = max(robCurrent, skipCurrent);

    return dp[key];
  }

public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    unordered_map<string, int> memo;

    if (n == 1) {
      return nums[0];
    }

    int robFirstHouse = robHelper(nums, 0, n - 2, memo);
    int notRobFirstHouse = robHelper(nums, 1, n - 1, memo);
    return max(robFirstHouse, notRobFirstHouse);
  }
};

int main() { return 0; }