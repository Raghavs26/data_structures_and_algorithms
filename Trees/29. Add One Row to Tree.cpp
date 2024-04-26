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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        queue<TreeNode*> q;
        q.push(root);
        int currentDepth = 1;

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* current = q.front();
                q.pop();

                if (currentDepth == depth - 1) {
                    TreeNode* newLeft = new TreeNode(val);
                    TreeNode* newRight = new TreeNode(val);
                    newLeft->left = current->left;
                    newRight->right = current->right;
                    current->left = newLeft;
                    current->right = newRight;
                } else {
                    if (current->left) q.push(current->left);
                    if (current->right) q.push(current->right);
                }
            }
            currentDepth++;
        }

        return root;
    }
};

int main() {
    return 0;
}
