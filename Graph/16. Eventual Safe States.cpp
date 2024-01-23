#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
private:
  bool checkCycle(int cv, vector<int> adj[], vector<bool> &visited,
                  vector<bool> &pathVisited) {
    visited[cv] = true;
    pathVisited[cv] = true;
    for (auto neighbours : adj[cv]) {
      if (!visited[neighbours]) {
        if (checkCycle(neighbours, adj, visited, pathVisited)) {
          return true;
        }
      } else if (pathVisited[neighbours] == true) {
        return true;
      }
    }
    pathVisited[cv] = false;
    return false;
  }

public:
  vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    vector<bool> pathVisited(V, false);
    for (int i = 0; i < V; i++) {
      if (!visited[i]) {
        checkCycle(i, adj, visited, pathVisited);
      }
    }
    vector<int> res;
    for (int i = 0; i < V; i++) {
      if (!pathVisited[i]) {
        res.push_back(i);
      }
    }
    return res;
  }
};

int main() { return 0; }