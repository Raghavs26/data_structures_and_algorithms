#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
  int findMaxSubarraySum(long long arr[], int n, long long sum) {
    int currentSum = 0, res = INT_MIN;
    int windowStart = 0, windowEnd = 0;
    while (windowEnd < n) {
      currentSum += arr[windowEnd];
      while (currentSum > sum) {
        currentSum -= arr[windowStart];
        windowStart++;
      }
      windowEnd++;
      res = max(res, currentSum);
    }
    return res;
  }
};

int main() { return 0; }