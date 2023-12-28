#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    deque<int> dq;
    vector<int> res;
    if (k > nums.size()) {
      res.push_back(*max_element(nums.begin(), nums.end()));
      return res;
    }
    int windowStart = 0, windowEnd = 0;
    while (windowEnd < nums.size()) {
      while (!dq.empty() and dq.back() < nums[windowEnd]) {
        dq.pop_back();
      }
      dq.push_back(nums[windowEnd]);
      if (windowEnd - windowStart + 1 < k) {
        windowEnd++;
      } else if (windowEnd - windowStart + 1 == k) {
        res.push_back(dq.front());
        if (dq.front() == nums[windowStart]) {
          dq.pop_front();
        }
        windowStart++;
        windowEnd++;
      }
    }
    return res;
  }
};

int main() { return 0; }