#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
  char nextGreatestLetter(vector<char> &letters, char target) {
    int start = 0, end = letters.size() - 1;
    if (letters[start] > target or letters[end] <= target)
      return letters[0];
    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (letters[mid] > target) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    }
    return letters[start];
  }
};

int main() { return 0; }