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
    int solve(TreeNode *root, int num) {
        if (!root) return 0;
        if (!root->left && !root->right) {
            return num * 10 + root->val;
        }
        return solve(root->left, num * 10 + root->val) + solve(root->right, num * 10 + root->val);
    }

   public:
    int sumNumbers(TreeNode *root) {
        return solve(root, 0);
    }
};

int main() {
    return 0;
}
