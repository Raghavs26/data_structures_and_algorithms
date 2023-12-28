#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
  string minWindow(string s, string t) {
    unordered_map<char, int> mp;
    int res = INT_MAX, subStringStart = 0;
    for (char ch : t) {
      mp[ch]++;
    }
    int windowStart = 0, windowEnd = 0, distinctLetterCount = mp.size();
    while (windowEnd < s.size()) {
      char rightChar = s[windowEnd];
      if (mp.find(rightChar) != mp.end()) {
        mp[rightChar]--;
        if (mp[rightChar] == 0) {
          distinctLetterCount--;
        }
      }
      while (distinctLetterCount == 0) {
        char leftChar = s[windowStart];
        if (mp.find(leftChar) != mp.end()) {
          mp[leftChar]++;
          if (mp[leftChar] > 0) {
            distinctLetterCount++;
          }
          if (windowEnd - windowStart + 1 < res) {
            res = windowEnd - windowStart + 1;
            subStringStart = windowStart;
          }
        }
        windowStart++;
      }

      windowEnd++;
    }
    return res == INT_MAX ? "" : s.substr(subStringStart, res);
  }
};

int main() { return 0; }