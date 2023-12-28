#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
  int findSubString(string str) {
    unordered_map<char, int> mp1;
    unordered_map<char, int> mp2;
    int res = INT_MAX;
    int windowStart = 0, windowEnd = 0, n = str.size();
    for (int i = 0; i < str.size(); i++) {
      mp2[str[i]]++;
    }
    while (windowEnd < n) {
      char rightChar = str[windowEnd];
      mp2[rightChar]++;
      if (mp2[rightChar] > 1) {
      }
    }
  }
};

int main() { return 0; }