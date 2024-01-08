#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size();
    int n = nums2.size();

    if (m > n) {
      return findMedianSortedArrays(nums2, nums1);
    }

    int total = m + n;

    int low = 0;
    int high = m;

    double result = 0.0;

    while (low <= high) {

      int mid1 = low + (high - low) / 2;
      int mid2 = (total + 1) / 2 - mid1;

      int left1 = (mid1 > 0) ? nums1[mid1 - 1] : INT_MIN;
      int right1 = (mid1 < m) ? nums1[mid1] : INT_MAX;
      int left2 = (mid2 > 0) ? nums2[mid2 - 1] : INT_MIN;
      int right2 = (mid2 < n) ? nums2[mid2] : INT_MAX;

      if (left1 <= right2 && left2 <= right1) {
        int left = max(left1, left2);
        int right = min(right1, right2);
        if (total % 2 == 0) {
          result = (left + right) / 2.0;
        } else {
          result = left;
        }
        break;
      } else if (left1 > right2) {
        high = mid1 - 1;
      } else {
        low = mid1 + 1;
      }
    }
    return result;
  }
};

int main() { return 0; }