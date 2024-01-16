#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
private:
  bool detectUsingBFS(int cv, vector<int> adj[], vector<bool> &visited) {
    queue<pair<int, int>> q;
    q.push({cv, -1});
    visited[cv] = true;
    while (!q.empty()) {
      int currentNode = q.front().first;
      int parent = q.front().second;
      q.pop();
      for (int neighbour : adj[currentNode]) {
        if (!visited[neighbour]) {
          visited[neighbour] = true;
          q.push({neighbour, currentNode});
        } else if (parent != neighbour) {
          return true;
        }
      }
    }
    return false;
  }

public:
  bool isCycle(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
      if (!visited[i]) {
        if (detectUsingBFS(i, adj, visited)) {
          return true;
        }
      }
    }
    return false;
  }
};

int main() { return 0; }