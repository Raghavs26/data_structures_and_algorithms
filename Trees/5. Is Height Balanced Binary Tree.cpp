#include <bits/stdc++.h>

#include <iostream>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

int dfs(TreeNode<int> *root) {
    if (!root) return 0;
    int left = dfs(root->left);
    if (left == -1) return -1;
    int right = dfs(root->right);
    if (right == -1) return -1;
    if (abs(left - right) > 1) return -1;
    return max(left, right) + 1;
}

bool isBalancedBT(TreeNode<int> *root) {
    if (!root) return true;
    return dfs(root) != -1;
}

int main() {
    return 0;
}