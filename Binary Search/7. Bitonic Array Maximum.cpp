#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
  int searchBitonicArray(vector<int> arr) {
    int start = 0, end = arr.size() - 1;
    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (arr[mid] > arr[mid + 1]) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    }
    return arr[start];
  }
};

int main() { return 0; }