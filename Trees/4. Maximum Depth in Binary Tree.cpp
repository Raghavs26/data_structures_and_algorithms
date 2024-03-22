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
    int solve(TreeNode *root) {
        if (!root) return 0;
        int h1 = 1 + solve(root->left);
        int h2 = 1 + solve(root->right);
        return max(h1, h2);
    }

   public:
    int maxDepth(TreeNode *root) {
        return solve(root);
    }
};

int main() {
    return 0;
}