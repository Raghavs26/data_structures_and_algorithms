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
    int helper(TreeNode *root) {
        if (!root) return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        return left + right + 1;
    }

   public:
    int countNodes(TreeNode *root) {
        return helper(root);
    }
};

int main() {
    return 0;
}