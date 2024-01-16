#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
  void dfs(int V, vector<int> adj[], int currentVertex, vector<bool> &visited,
           vector<int> &res) {
    visited[currentVertex] = true;
    res.push_back(currentVertex);
    for (int neighbour : adj[currentVertex]) {
      if (!visited[neighbour]) {
        dfs(V, adj, neighbour, visited, res);
      }
    }
  }
  vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    vector<int> res;
    for (int i = 0; i < V; i++) {
      if (!visited[i]) {
        dfs(V, adj, i, visited, res);
      }
    }
  }
};

int main() { return 0; }