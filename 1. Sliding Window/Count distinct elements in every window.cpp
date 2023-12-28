#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<int> countDistinct(int A[], int n, int k) {
    unordered_map<int, int> mp;
    vector<int> res;
    int windowStart = 0, windowEnd = 0;
    while (windowEnd < n) {
      if (windowEnd - windowStart + 1 < k) {
        mp[A[windowEnd]]++;
        windowEnd++;
      } else if (windowEnd - windowStart + 1 == k) {
        res.push_back(mp.size());
        mp[A[windowStart]]--;
        if (mp[A[windowStart]] == 0) {
          mp.erase(A[windowStart]);
        }
        mp[A[windowEnd]]++;
        windowStart++;
        windowEnd++;
      }
    }
    return res;
  }
};

int main() {
  int a[] = {1, 2, 1, 3, 4, 2, 3};
  int n = 7, k = 4;
  Solution *s = new Solution();
  auto v = s->countDistinct(a, n, k);
  for (auto i : v) {
    cout << i << " ";
  }
  return 0;
}