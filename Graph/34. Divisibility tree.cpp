#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   private:
    int dfs(unordered_map<int, vector<int>>& tree, int currentNode, int parent, int& res) {
        int count = 0;
        for (auto neighbour : tree[currentNode]) {
            if (neighbour != parent) {
                int x = dfs(tree, neighbour, currentNode, res);
                if (x % 2 == 0) {
                    res++;
                } else {
                    count += x;
                }
            }
        }
        return count + 1;
    }

   public:
    int minimumEdgeRemove(int n, vector<vector<int>> edges) {
        unordered_map<int, vector<int>> tree;
        for (auto edge : edges) {
            int u = edge[0], v = edge[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        int res = 0;
        dfs(tree, 1, -1, res);

        return res;
    }
};

int main() {
    return 0;
}