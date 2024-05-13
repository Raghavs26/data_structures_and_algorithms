#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
  int first(vector<int> nums, int target) {
    int start = 0, end = nums.size() - 1;
    int res = -1;
    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (nums[mid] == target) {
        res = mid;
        end = mid - 1;
      } else if (nums[mid] > target) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    }
    return res;
  }
  int last(vector<int> nums, int target) {
    int start = 0, end = nums.size() - 1;
    int res = -1;
    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (nums[mid] == target) {
        res = mid;
        start = mid + 1;
      } else if (nums[mid] > target) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    }
    return res;
  }
  vector<int> searchRange(vector<int> &nums, int target) {
    vector<int> res;
    int f = first(nums, target);
    int l = last(nums, target);
    res.push_back(f);
    res.push_back(l);
    return res;
  }
};

int main() { return 0; }