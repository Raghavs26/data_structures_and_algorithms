#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    bool dfs(int cv, unordered_map<int, vector<int>>& graph, vector<bool>& visited, vector<bool>& pathVisited, vector<int>& res) {
        visited[cv] = true;
        pathVisited[cv] = true;
        for (auto neighbor : graph[cv]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, graph, visited, pathVisited, res)) {
                    return true;
                }
            } else if (pathVisited[neighbor]) {
                return true;
            }
        }
        pathVisited[cv] = false;
        res.push_back(cv);
        return false;
    }

    vector<int> topoSort(vector<vector<int>>& conditions, int n) {
        unordered_map<int, vector<int>> graph;
        vector<int> topo;
        for (auto& edge : conditions) {
            graph[edge[0]].push_back(edge[1]);
        }
        vector<bool> visited(n + 1, false);
        vector<bool> pathVisited(n + 1, false);
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                if (dfs(i, graph, visited, pathVisited, topo)) {
                    return {};
                }
            }
        }
        reverse(topo.begin(), topo.end());
        return topo;
    }

   public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rows = topoSort(rowConditions, k);
        vector<int> cols = topoSort(colConditions, k);
        if (rows.size() == 0 || cols.size() == 0) return {};
        vector<vector<int>> res(k, vector<int>(k, 0));

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (rows[i] == cols[j]) res[i][j] = rows[i];
            }
        }
        return res;
    }
};

int main() {
    return 0;
}