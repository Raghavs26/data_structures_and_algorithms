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
    void buildGraph(unordered_map<int, vector<int>> &graph, TreeNode *parent, TreeNode *root) {
        if (!root) return;
        if (parent) {
            graph[root->val].push_back(parent->val);
            graph[parent->val].push_back(root->val);
        }
        buildGraph(graph, root, root->left);
        buildGraph(graph, root, root->right);
    }

    vector<int> findLeafNodes(TreeNode *root) {
        vector<int> leaves;
        if (!root) return leaves;
        if (!root->left && !root->right) {
            leaves.push_back(root->val);
        } else {
            vector<int> leftLeaves = findLeafNodes(root->left);
            vector<int> rightLeaves = findLeafNodes(root->right);
            leaves.insert(leaves.end(), leftLeaves.begin(), leftLeaves.end());
            leaves.insert(leaves.end(), rightLeaves.begin(), rightLeaves.end());
        }
        return leaves;
    }

    int bfs(unordered_map<int, vector<int>> &graph, int start, int end, int maxDist) {
        queue<pair<int, int>> q;
        unordered_set<int> visited;
        q.push({start, 0});
        visited.insert(start);

        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();
            if (node == end) return dist;
            for (int neighbor : graph[node]) {
                if (visited.find(neighbor) == visited.end()) {
                    if (dist + 1 <= maxDist) {
                        q.push({neighbor, dist + 1});
                        visited.insert(neighbor);
                    }
                }
            }
        }
        return maxDist + 1;
    }

   public:
    int countPairs(TreeNode *root, int distance) {
        unordered_map<int, vector<int>> graph;
        buildGraph(graph, nullptr, root);

        vector<int> leaves = findLeafNodes(root);
        int res = 0;

        for (int i = 0; i < leaves.size(); ++i) {
            for (int j = i + 1; j < leaves.size(); ++j) {
                if (bfs(graph, leaves[i], leaves[j], distance) <= distance) {
                    res++;
                }
            }
        }
        return res;
    }
};

int main() {
    return 0;
}