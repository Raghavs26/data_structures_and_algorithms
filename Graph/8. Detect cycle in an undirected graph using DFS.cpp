#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
private:
  bool detectUsingDFS(int cv, vector<int> adj[], vector<bool> &visited,
                      int parent) {
    visited[cv] = true;
    for (int neighbour : adj[cv]) {
      if (!visited[neighbour]) {
        if (detectUsingDFS(neighbour, adj, visited, cv)) {
          return true;
        }
      } else if (neighbour != parent) {
        return true;
      }
    }
    return false;
  }

public:
  bool isCycle(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
      if (!visited[i]) {
        if (detectUsingDFS(i, adj, visited, -1)) {
          return true;
        }
      }
    }
    return false;
  }
};

int main() { return 0; }