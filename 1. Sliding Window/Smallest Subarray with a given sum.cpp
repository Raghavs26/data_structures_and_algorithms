#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int res = INT_MAX, n = nums.size(), current_sum = 0;
    int window_start = 0, window_end = 0;
    while (window_end < n) {
      current_sum += nums[window_end];
      while (current_sum >= target) {
        res = min(res, window_end - window_start + 1);
        current_sum -= nums[window_start];
        window_start += 1;
      }
      window_end += 1;
    }
    return res == INT_MAX ? 0 : res;
  }
};

int main() { return 0; }