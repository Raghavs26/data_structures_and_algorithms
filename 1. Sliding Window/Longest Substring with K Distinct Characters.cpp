#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
  int longestKSubstr(string s, int k) {
    unordered_map<char, int> mp;
    int res = INT_MIN, window_start = 0, window_end = 0, n = s.size();
    while (window_end < n) {
      char right_char = s[window_end];
      mp[right_char] += 1;
      while (mp.size() > k) {
        char left_char = s[window_start];
        mp[left_char] -= 1;
        if (mp[left_char] == 0) {
          mp.erase(left_char);
        }
        window_start += 1;
      }
      res = max(res, window_end - window_start + 1);
      window_end += 1;
    }
    return res == INT_MIN ? -1 : res;
  }
};

int main() { return 0; }