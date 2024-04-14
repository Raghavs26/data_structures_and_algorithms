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
    int solve(TreeNode *root, bool isLeft) {
        if (!root) return 0;
        if (!root->left && !root->right && isLeft) {
            return root->val;
        }
        return solve(root->left, true) + solve(root->right, false);
    }

   public:
    int sumOfLeftLeaves(TreeNode *root) {
        return solve(root, false);
    }
};

int main() {
    return 0;
}