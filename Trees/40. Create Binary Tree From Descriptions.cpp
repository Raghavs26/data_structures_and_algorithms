#include <bits/stdc++.h>

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> tree;
        unordered_set<int> childrenSet;

        for (const auto& description : descriptions) {
            int parent = description[0], child = description[1];
            bool isLeft = description[2] == 1;

            if (tree.find(parent) == tree.end()) {
                tree[parent] = new TreeNode(parent);
            }
            if (tree.find(child) == tree.end()) {
                tree[child] = new TreeNode(child);
            }

            if (isLeft) {
                tree[parent]->left = tree[child];
            } else {
                tree[parent]->right = tree[child];
            }

            childrenSet.insert(child);
        }

        TreeNode* res = nullptr;
        for (auto [key, node] : tree) {
            if (childrenSet.find(key) == childrenSet.end()) {
                res = node;
                break;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}