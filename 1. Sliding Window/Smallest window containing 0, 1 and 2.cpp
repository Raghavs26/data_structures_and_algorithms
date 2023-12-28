#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
  int smallestSubstring(string S) {
    if (S.size() < 3) {
      return -1;
    }
    int res = INT_MAX;
    int zero = -1, one = -1, two = -1;
    for (int i = 0; i < S.size(); i++) {
      if (S[i] == '0') {
        zero = i;
      } else if (S[i] == '1') {
        one = i;
      } else if (S[i] == '2') {
        two = i;
      }
      if (zero != -1 && one != -1 && two != -1) {
        res = min(res, (max(zero, one, two) - min(zero, one, two) + 1));
      }
    }
    return res != INT_MAX ? res : -1;
  }
};

int main() { return 0; }