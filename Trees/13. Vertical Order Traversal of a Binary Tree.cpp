#include <bits/stdc++.h>

#include <iostream>
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
    bool compare(const pair<int, int> &a, const pair<int, int> &b) {
        return a.first < b.first;
    }

   public:
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        vector<vector<int>> res;
        map<int, vector<pair<int, int>>> mp;
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while (!q.empty()) {
            int size = q.size();
            map<int, vector<pair<int, int>>> temp;
            for (int i = 0; i < size; i++) {
                TreeNode *current = q.front().first;
                int row = q.front().second.first;
                int col = q.front().second.second;
                temp[col].push_back({current->val, row});
                if (current->left) q.push({current->left, {row + 1, col - 1}});
                if (current->right) q.push({current->right, {row + 1, col + 1}});
            }
            for (auto [col, nodes] : temp) {
                sort(nodes.begin(), nodes.end(), compare);
                mp[col].insert(mp[col].end(), nodes.begin(), nodes.end());
            }
        }
        for (auto [col, nodes] : mp) {
            vector<int> colNodes;
            for (auto [val, row] : nodes) {
                colNodes.push_back(val);
            }
            res.push_back(colNodes);
        }
        return res;
    }
};

int main() {
    return 0;
}