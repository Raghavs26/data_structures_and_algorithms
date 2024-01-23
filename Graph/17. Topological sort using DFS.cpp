#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
private:
  bool check(int cv, vector<int> adj[], vector<bool> &visited,
             vector<bool> &pathVisited, vector<int> &res) {
    visited[cv] = true;
    pathVisited[cv] = true;
    for (auto neighbours : adj[cv]) {
      if (!visited[neighbours]) {
        if (check(neighbours, adj, visited, pathVisited, res)) {
          return true;
        };
      } else if (pathVisited[neighbours] == true) {
        return true;
      }
    }
    pathVisited[cv] = false;
    res.push_back(cv);
    return false;
  }

public:
  vector<int> topoSort(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    vector<bool> pathVisited(V, false);
    vector<int> res;
    for (int i = 0; i < V; i++) {
      if (!visited[i]) {
        if (check(i, adj, visited, pathVisited, res)) {
          return {};
        }
      }
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

int main() { return 0; }