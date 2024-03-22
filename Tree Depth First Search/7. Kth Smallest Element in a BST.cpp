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
    void inOrder(TreeNode *root, vector<int> &inorder) {
        if (!root) return;
        inOrder(root->left, inorder);
        inorder.push_back(root->val);
        inOrder(root->right, inorder);
    }

   public:
    int kthSmallest(TreeNode *root, int k) {
        vector<int> inorder;
        inOrder(root, inorder);
        return inorder[k - 1];
    }
};
int main() {
    return 0;
}