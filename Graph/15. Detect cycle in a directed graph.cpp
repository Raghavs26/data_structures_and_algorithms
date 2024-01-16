#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
private:
  bool check(int cv, vector<int> adj[], vector<bool> &visited,
             vector<bool> &pathVisited) {
    visited[cv] = true;
    pathVisited[cv] = true;
    for (auto neighbours : adj[cv]) {
      if (!visited[neighbours] and
          check(neighbours, adj, visited, pathVisited)) {
        return true;
      } else if (pathVisited[neighbours]) {
        return true;
      }
    }
    pathVisited[cv] = false;
    return false;
  }

public:
  bool isCyclic(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    vector<bool> pathVisited(V, false);
    for (int i = 0; i < V; i++) {
      if (!visited[i]) {
        if (check(i, adj, visited, pathVisited)) {
          return true;
        }
      }
    }
    return false;
  }
};
/*

class Solution {
private:
    // Function to detect cycle in a directed graph using DFS
    bool dfs(int src, vector<int>& visited, vector<vector<int>>& adj) {
        // Mark the node as visited
        visited[src] = 2;

        for (int nbr : adj[src]) {
            // If unvisited
            if (visited[nbr] == 0) {
                // Mark it as the same path
                visited[nbr] = 2;
                if (dfs(nbr, visited, adj)) {
                    return true;
                }
            } else if (visited[nbr] == 2) {
                return true;
            }
        }

        // Backtrack to visited
        visited[src] = 1;
        return false;
    }

public:
    // Function to check if a directed graph contains a cycle
    bool isCyclic(int V, vector<vector<int>>& adj) {
        // Space optimization using only the visited array
        vector<int> visited(V, 0);

        // 0 - Unvisited
        // 1 - Visited
        // 2 - Same Path

        for (int i = 0; i < V; i++) {
            if (visited[i] == 0) {
                if (dfs(i, visited, adj)) {
                    return true;
                }
            }
        }
        return false;
    }
};
*/

int main() { return 0; }