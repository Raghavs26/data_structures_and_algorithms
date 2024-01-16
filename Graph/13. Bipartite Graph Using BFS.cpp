#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
private:
  bool check(int cv, vector<int> adj[], vector<int> &colors) {
    queue<int> q;
    q.push(cv);
    colors[cv] = 0;
    while (!q.empty()) {
      int current = q.front();
      q.pop();
      for (auto neighbours : adj[current]) {
        if (colors[neighbours] == -1) {
          q.push(neighbours);
          colors[neighbours] = colors[current] == 0 ? 1 : 0;
        } else if (colors[neighbours] == colors[current]) {
          return false;
        }
      }
    }
    return true;
  }

public:
  bool isBipartite(int V, vector<int> adj[]) {
    vector<int> colors(V, -1);
    for (int i = 0; i < V; i++) {
      if (colors[i] == -1 and !check(i, adj, colors)) {
        return false;
      }
    }
    return true;
  }
};

int main() { return 0; }
