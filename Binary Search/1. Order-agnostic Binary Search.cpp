#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int binarySearchAsc(vector<int> arr, int key) {
  int left = 0, right = arr.size() - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == key) {
      return mid;
    } else if (arr[mid] > key) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return -1;
}
int binarySearchDesc(vector<int> arr, int key) {
  int left = 0, right = arr.size() - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == key) {
      return mid;
    } else if (arr[mid] < key) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return -1;
}

int orderAgnosticBinarySearch(vector<int> arr, int key) {
  if (arr[0] < arr[1]) {
    return binarySearchAsc(arr, key);
  } else {
    return binarySearchDesc(arr, key);
  }
}

int main() { return 0; }