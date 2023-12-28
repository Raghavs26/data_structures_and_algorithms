#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
  int lenOfLongSubarr(int A[], int N, int K) {
    long long sum = 0;
    int res = 0;
    int windowStart = 0, windowEnd = 0;
    while (windowEnd < N) {
      sum += A[windowEnd];
      while (sum > K and windowStart < windowEnd) {
        sum -= A[windowStart];
        windowStart++;
      }
      if (sum == K) {
        res = max(res, windowEnd - windowStart + 1);
      }
      windowEnd++;
    }
    return res;
  }
};

int main() {
  int a[] = {1, 2, 3, 0, 0, 0, -15, 2, 3, 4, 5, 1, 1, 1, 1, 1, 1, 5, 6};
  int n = sizeof(a) / sizeof(a[0]);
  int k = 0;
  Solution s;
  cout << s.lenOfLongSubarr(a, n, k);
  return 0;
}