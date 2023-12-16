#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int longestSubstrDistinctChars(string s) {
  int res = 0, n = s.size();
  if (n <= 1)
    return n;
  unordered_map<char, int> mp;
  int window_start = 0, window_end = 0;
  while (window_end < n) {
    char right_char = s[window_end];
    mp[right_char] = window_end;
    if (mp.find(right_char) != mp.end()) {
      window_start = max(window_start, mp[right_char] + 1);
    }
    res = max(res, window_end - window_start + 1);
    window_end += 1;
  }
  return res;
}

int main() { return 0; }