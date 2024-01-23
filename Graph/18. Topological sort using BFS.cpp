#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {

public:
  vector<int> topoSort(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++) {
      for (auto nh : adj[i]) {
        indegree[nh]++;
      }
    }
    queue<int> q;
    for (int i = 0; i < V; i++) {
      if (indegree[i] == 0) {
        q.push(i);
      }
    }
    vector<int> res;
    while (!q.empty()) {
      int current = q.front();
      q.pop();
      res.push_back(current);
      for (auto nh : adj[current]) {
        indegree[nh]--;
        if (indegree[nh] == 0) {
          q.push(nh);
        }
      }
    }
    return res;
  }
};

int main() { return 0; }