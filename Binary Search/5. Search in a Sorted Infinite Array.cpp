#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class ArrayReader {
public:
  vector<int> arr;
  ArrayReader(const vector<int> &arr) { this->arr = arr; }

  virtual int get(int index) {
    if (index >= (int)arr.size()) {
      return numeric_limits<int>::max();
    }
    return arr[index];
  }
};

class Solution {
public:
  int search(ArrayReader *reader, int key) {
    int start = 0, end = 1;
    while (reader->get(end) < key) {
      start = end;
      end = 2 * end;
    }
    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (reader->get(mid) == key) {
        return mid;
      } else if (reader->get(mid) > key) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    }
    return -1;
  }
};

int main() {
  Solution *s = new Solution();
  vector<int> arr{4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30};
  int key = 16;
  ArrayReader *ar = new ArrayReader(arr);
  cout << s->search(ar, key);
  return 0;
}