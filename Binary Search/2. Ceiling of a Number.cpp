#include <bits/stdc++.h>
#include <iostream>

using namespace std;
// 1 4 5 9 10   6
int getCeil(vector<int> arr, int key) {
  int start = 0, end = arr.size() - 1;
  if (key > arr[end]) {
    return -1;
  }
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (arr[mid] == key) {
      return mid;
    } else if (arr[mid] > key) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return start;
}

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
  int f = INT_MIN, c = INT_MAX;
  for (int i = 0; i < n; i++) {
    if (arr[i] <= x)
      f = max(f, arr[i]);
    if (arr[i] >= x)
      c = min(c, arr[i]);
  }
  return {f == INT_MIN ? -1 : f, c == INT_MAX ? -1 : c};
}

int main() { return 0; }