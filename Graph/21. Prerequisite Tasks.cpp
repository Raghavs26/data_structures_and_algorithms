#include <bits/stdc++.h>
#include <iostream>

using namespace std;
class Solution {
public:
  bool isPossible(int n, int p, vector<pair<int, int>> &prerequisites) {
    vector<int> inDegree(n + 1, 0);
    unordered_map<int, vector<int>> graph;
    for (auto it : prerequisites) {
      graph[it.first].push_back(it.second);
    }

    for (int i = 0; i < n; i++) {
      for (auto it : graph[i]) {
        inDegree[it]++;
      }
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
      if (inDegree[i] == 0)
        q.push(i);
    }

    vector<int> topo;
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      topo.push_back(node);

      for (auto it : graph[node]) {
        inDegree[it]--;
        if (inDegree[it] == 0)
          q.push(it);
      }
    }

    return topo.size() == n;
  }
};
int main() { return 0; }