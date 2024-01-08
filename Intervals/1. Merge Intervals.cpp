#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct cmp {
  bool operator()(const vector<int> &a, const vector<int> &b) {
    return a[0] < b[0];
  }
};

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end(), cmp());
    int start = intervals[0][0], end = intervals[0][1], n = intervals.size();
    for (int i = 1; i < n; i++) {
      vector<int> current = intervals[i];
      if (current[0] <= end) {
        end = current[1];
      } else {
        res.push_back({start, end});
        start = current[0];
        end = current[1];
      }
    }
    res.push_back({start, end});
    return res;
  };
};
int main() {
  vector<vector<int>> v{{1, 3}, {2, 4}, {6, 8}, {9, 10}};

  Solution *s = new Solution();
  auto res = s->merge(v);
  for (auto i : res) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}