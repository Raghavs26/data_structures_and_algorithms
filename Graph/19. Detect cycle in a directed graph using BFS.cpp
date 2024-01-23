#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
public:
  bool isCyclic(int V, vector<int> adj[]) {
    vector<int> inDegree(V, 0);
    for (int i = 0; i < V; i++) {
      for (auto it : adj[i]) {
        inDegree[it]++;
      }
    }
    queue<int> q;
    for (int i = 0; i < V; i++) {
      if (inDegree[i] == 0) {
        q.push(i);
      }
    }
    int count = 0;
    while (!q.empty()) {
      int current = q.front();
      q.pop();
      count++;
      for (auto it : adj[current]) {
        inDegree[it]--;
        if (inDegree[it] == 0) {
          q.push(it);
        }
      }
    }
    return count == V;
  }
};

int main() { return 0; }