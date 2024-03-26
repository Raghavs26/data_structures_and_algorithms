#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
private:
  vector<char> topoSort(int k, unordered_map<char, vector<char>> &graph) {
    vector<int> indegree(k, 0);
    for (int i = 0; i < k; i++) {
      char node = i + 'a';
      for (char neighbor : graph[node]) {
        indegree[neighbor - 'a']++;
      }
    }

    queue<char> q;
    for (int i = 0; i < k; i++) {
      if (indegree[i] == 0) {
        char node = i + 'a';
        q.push(node);
      }
    }

    vector<char> topo;
    while (!q.empty()) {
      char node = q.front();
      q.pop();
      topo.push_back(node);

      for (char neighbor : graph[node]) {
        indegree[neighbor - 'a']--;
        if (indegree[neighbor - 'a'] == 0) {
          q.push(neighbor);
        }
      }
    }

    return topo;
  }

public:
  string findOrder(string dict[], int n, int k) {
    unordered_map<char, vector<char>> graph;
    for (int i = 0; i < n - 1; i++) {
      string s1 = dict[i];
      string s2 = dict[i + 1];
      int len = min(s1.size(), s2.size());
      for (int ptr = 0; ptr < len; ptr++) {
        if (s1[ptr] != s2[ptr]) {
          graph[s1[ptr]].push_back(s2[ptr]);
          break;
        }
      }
    }

    vector<char> topo = topoSort(k, graph);
    string res = "";
    if (topo.size() != k) {
      return res;
    }
    for (auto it : topo) {
      res += it;
    }
    return res;
  }
};
