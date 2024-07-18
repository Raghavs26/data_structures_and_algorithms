#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   private:
    void buildGraph(TreeNode *root, TreeNode *parent, unordered_map<int, vector<pair<int, char>>> &graph) {
        if (!root) return;
        if (parent) {
            graph[root->val].push_back({parent->val, 'U'});
            if (parent->left == root) {
                graph[parent->val].push_back({root->val, 'L'});
            } else if (parent->right == root) {
                graph[parent->val].push_back({root->val, 'R'});
            }
        }
        buildGraph(root->left, root, graph);
        buildGraph(root->right, root, graph);
    }

    string bfs(unordered_map<int, vector<pair<int, char>>> &graph, int start, int dest) {
        unordered_map<int, bool> visited;
        unordered_map<int, pair<int, char>> parent;
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (node == dest) break;
            for (auto [neighbor, direction] : graph[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    parent[neighbor] = {node, direction};
                    q.push(neighbor);
                }
            }
        }

        string path;
        int current = dest;
        while (current != start) {
            path += parent[current].second;
            current = parent[current].first;
        }

        reverse(path.begin(), path.end());
        return path;
    }

   public:
    string getDirections(TreeNode *root, int startValue, int destValue) {
        if (!root) return "";
        unordered_map<int, vector<pair<int, char>>> graph;
        buildGraph(root, nullptr, graph);
        string res = bfs(graph, startValue, destValue);
        return res;
    }
};

int main() {
    return 0;
}