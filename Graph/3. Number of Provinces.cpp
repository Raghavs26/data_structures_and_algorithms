#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
  void dfs(int cv, vector<int> adjacencyList[], vector<bool> visited) {
    visited[cv] = 1;
    for (auto neighbour : adjacencyList[cv]) {
      if (!visited[neighbour]) {
        dfs(neighbour, adjacencyList, visited);
      }
    }
  }

  int numProvinces(vector<vector<int>> adj, int V) {
    vector<int> adjacencyList[V];
    vector<bool> visited(V, false);
    int res = 0;

    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        if (adj[i][j] == 1 && i != j) {
          adjacencyList[i].push_back(j);
          adjacencyList[j].push_back(i);
        }
      }
    }
    for (int i = 0; i < V; i++) {
      if (!visited[i]) {
        res++;
        dfs(i, adjacencyList, visited);
      }
    }
    return res;
  }
};

int main() { return 0; }