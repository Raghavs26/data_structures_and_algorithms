#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
  int search(string pat, string txt) {
    unordered_map<char, int> mp;
    for (char c : pat) {
      mp[c]++;
    }
    int k = pat.size(), distinctLetter = mp.size();
    int windowStart = 0, windowEnd = 0, n = txt.size();
    int res = 0;
    while (windowEnd < n) {
      char rightChar = txt[windowEnd];
      if (mp.find(rightChar) != mp.end()) {
        mp[rightChar]--;
        if (mp[rightChar] == 0) {
          distinctLetter--;
        }
      }
      if (windowEnd - windowStart + 1 == k) {
        if (distinctLetter == 0) {
          res++;
        }
        char leftChar = txt[windowStart];
        if (mp.find(leftChar) != mp.end()) {
          mp[leftChar]++;
          if (mp[leftChar] > 0) {
            distinctLetter++;
          }
        }
        windowStart++;
      }
      windowEnd++;
    }
    return res;
  }
};

int main() { return 0; }