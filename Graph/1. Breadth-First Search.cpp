#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<bool> visited(V , false);
    vector<int> res;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
      int cur = q.front();
      res.push_back(cur);
      q.pop();
      visited[cur] = true;
      for (int i = 0; i < adj[cur].size(); i++) {
        int el = adj[cur][i];
        if (!visited[el]) {
          q.push(el);
          visited[el] = true;
        }
      }
    }
  }
};

int main() { return 0; }