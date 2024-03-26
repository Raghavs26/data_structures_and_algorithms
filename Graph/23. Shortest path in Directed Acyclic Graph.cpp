#include <bits/stdc++.h>

#include <iostream>

using namespace std;

class Solution {
   private:
    bool topoSort(unordered_map<int, vector<pair<int, int>>> graph,
                  vector<bool> &visited, vector<bool> &pathVisited, int cv,
                  vector<int> res) {
        visited[cv] = true;
        pathVisited[cv] = true;
        for (auto neighbour : graph[cv]) {
            if (!visited[neighbour.first] &&
                topoSort(graph, visited, pathVisited, neighbour.first, res)) {
                return true;
            } else if (pathVisited[neighbour.first]) {
                return true;
            }
        }
        res.push_back(cv);
        pathVisited[cv] = false;
        return false;
    }

   public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
        }
        vector<bool> visited(n, false);
        vector<bool> pathVisited(n, false);
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                topoSort(graph, visited, pathVisited, i, res);
            }
        }
        vector<int> distance(n, INT_MAX);
        distance[0] = 0;
        while (!res.empty()) {
            int cur = res.back();
            res.pop_back();
            for (int i = 0; i < graph[cur].size(); i++) {
                int cv = graph[cur][i].first;
                int wt = graph[cur][i].second;
                if (distance[cur] + wt < distance[cv]) {
                    distance[cv] = distance[cur] + wt;
                }
            }
        }
        return distance;
    }
};

int main() { return 0; }