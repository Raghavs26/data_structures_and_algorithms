#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
  int longestOnes(vector<int> &nums, int k) {
    int res = 0, n = nums.size();
    int window_start = 0, window_end = 0, max_ones = 0;
    while (window_end < n) {
      int right = nums[window_end];
      if (right == 1) {
        max_ones += 1;
      }
      if (window_end - window_start + 1 - max_ones > k) {
        int left = nums[window_start];
        if (left == 1) {
          max_ones -= 1;
        }
        window_start += 1;
      }
      res = max(res, window_end - window_start + 1);
      window_end += 1;
    }
    return res;
  }
};

int main() {
  vector<int> v{0, 0, 0, 0};
  Solution *s = new Solution();
  cout << s->longestOnes(v, 0);
  return 0;
}