#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
  long maximumSumSubarray(int k, vector<int> &arr, int n) {
    long res = 0, current_sum = 0;
    int window_end = 0, window_start = 0;
    while (window_end < n) {
      current_sum += arr[window_end];
      if (window_end - window_start + 1 >= k) {
        res = max(res, current_sum);
        current_sum -= arr[window_start];
        window_start += 1;
      }
      window_end += 1;
    }
    return res;
  }
};

int main() { return 0; }