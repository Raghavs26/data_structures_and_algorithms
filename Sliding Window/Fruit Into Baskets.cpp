#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
  int totalFruit(vector<int> &fruits) {
    unordered_map<int, int> mp;
    int k = 2, res = 0, n = fruits.size();
    int window_end = 0, window_start = 0;
    while (window_end < n) {
      int right = fruits[window_end];
      mp[right] += 1;
      while (mp.size() > k) {
        int left = fruits[window_start];
        mp[left] -= 1;
        if (mp[left] == 0) {
          mp.erase(left);
        }
        window_start += 1;
      }
      res = max(res, window_end - window_start + 1);
      window_end += 1;
    }
    return res;
  }
};

int main() { return 0; }