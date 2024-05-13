#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
  int searchMinDiffElement(vector<int> arr, int key) {
    int start = 0, end = arr.size() - 1;
    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (arr[mid] == key) {
        return 0;
      } else if (arr[mid] > key) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    }

    return min(abs(arr[start] - key), abs(key - arr[end]));
  }
};

int main() { return 0; }