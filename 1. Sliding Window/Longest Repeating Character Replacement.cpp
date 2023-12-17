#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
  int characterReplacement(string s, int k) {
    int res = 0, n = s.size();
    int window_start = 0, window_end = 0, max_repeated_char = 0;
    unordered_map<char, int> mp;
    while (window_end < n) {
      char right_char = s[window_end];
      mp[right_char]++;
      max_repeated_char = max(max_repeated_char, mp[right_char]);
      if (window_end - window_start + 1 - max_repeated_char > k) {
        char left_char = s[left_char];
        mp[left_char] -= 1;
        window_start += 1;
      }
      res = max(res, window_end - window_start + 1);
      window_end += 1;
    }
    return res;
  }
};

int main() { return 0; }