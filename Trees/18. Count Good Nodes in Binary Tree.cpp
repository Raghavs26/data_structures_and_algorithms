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
    int dfs(TreeNode *root, int prev) {
        if (!root) return 0;
        int res = root->val >= prev ? 1 : 0;
        res += dfs(root->left, max(root->val, prev));
        res += dfs(root->right, max(root->val, prev));
        return res;
    }

   public:
    int goodNodes(TreeNode *root) {
        if (!root) return 0;
        return dfs(root, INT_MIN);
    }
};

int main() {
    return 0;
}