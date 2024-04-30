#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
    unordered_map<int, vector<int>> graph;
    vector<int> count;
    vector<int> res;

   private:
    void dfs(int root, int pre) {
        for (auto i : graph[root]) {
            if (i == pre) continue;
            dfs(i, root);
            count[root] += count[i];
            res[root] += res[i] + count[i];
        }
    }

    void dfs2(int root, int pre) {
        for (auto i : graph[root]) {
            if (i == pre) continue;
            res[i] = res[root] - count[i] + count.size() - count[i];
            dfs2(i, root);
        }
    }

   public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        res.resize(n, 0);
        count.resize(n, 1);

        for (auto edge : edges) {
            int v = edge[0];
            int u = edge[1];
            graph[v].push_back(u);
            graph[u].push_back(v);
        }
        dfs(0, -1);
        dfs2(0, -1);
        return res;
    }
};

int main() {
    return 0;
}
