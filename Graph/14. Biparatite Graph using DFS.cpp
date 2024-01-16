#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
private:
  bool check(int cv, vector<int> adj[], vector<int> colors, int color) {
    colors[cv] = color;
    for (auto neighbours : adj[cv]) {
      if (colors[neighbours] == -1) {
        int newColor = (color == 0) ? 1 : 0;
        if (!check(neighbours, adj, colors, newColor)) {
          return false;
        }
      } else if (colors[neighbours] == colors[cv]) {
        return false;
      }
    }
    return true;
  }

public:
  bool isBipartite(int V, vector<int> adj[]) {
    vector<int> colors(V, -1);
    for (int i = 0; i < V; i++) {
      if (colors[i] == -1 and !check(i, adj, colors, 0)) {
        return false;
      }
    }
    return true;
  }
};


int main() { return 0; }